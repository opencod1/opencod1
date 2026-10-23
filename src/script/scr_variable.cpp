/*
 * script/scr_variable.cpp
 *
 * Original translation unit:
 *   /Volumes/BigCheese/ Source/AspyrP4/CoD/Source/script/scr_variable.cpp
 *
 * Retail range 0x00470530-0x00475810, 141 functions.
 *
 * @fidelity: likely
 */

#ifdef __cplusplus
/* retail built this unit as C++ with exceptions (/TP /GX); every name keeps C linkage */
extern "C" {
#endif

#include "scr_local.h"

/* the save-state cursors and id maps */
unsigned short  *scrSave_idToSaveId;    /* 0x0097645C */
unsigned short  *scrSave_saveIdToId;    /* 0x0097646C */
char            *scrSave_readPos;       /* 0x00976470 */
void Hunk_FreeTempMemory( void *buf );   /* universal/com_memory.c */
unsigned short  scrSave_numSaveObjects; /* 0x00976458 */

extern void  Com_Meminfo_f( void );
extern char **FS_ListFilteredFiles( const char *path, const char *extension,
									const char *filter, int *numfiles );
extern void *Hunk_AllocLowAlignInternal( int size, int align );
extern void *Hunk_AllocateTempMemoryHighInternal( int size );
extern int   Hunk_ClearTempMemoryHigh( void );
extern int   Hunk_CommitTempMemory( void );
extern void  Scr_PrintPrevCodePos( const char *codePos, int offset );
extern void  qsort_m( void *base, unsigned int count, unsigned int width,
					  int ( __cdecl *compare )( const void *, const void * ) );

extern int Hunk_ReallocateTempMemory();

extern ScriptArrayRootStorage scrVarPub_gameId;

extern unsigned short scrVarPub_pauseArrayId;

extern unsigned short scrVarPub_levelId;
extern unsigned short scrVarPub_animId;

extern unsigned int   scrVarPub_time;

typedef struct VariableStackBuffer_s {
	const char     *pos;            /* +0x00 */
	const char     *codePos;        /* +0x04 */
	unsigned short  size;           /* +0x08  entry count */
	unsigned short  objectId;       /* +0x0A */
	/* +0x0C  `size` entries, stride 5: unsigned char type; VariableUnion u; */
} VariableStackBuffer;

#define SCR_STACKENTRY_SIZE     5
#define SCR_STACKBUFFER_HEADER  12

void             WriteString( unsigned short id );
unsigned short   ReadId( void );
void             AddSaveObject( unsigned short id );
void             DoLoadEntryInternal( VariableValue *value );
void             DoSaveEntryInternal( unsigned char type, VariableUnion u );
void             AddSaveEntry( unsigned char type, VariableUnion u );

void            AddSaveStack( const struct VariableStackBuffer_s *buf );
float           Scr_GetObjectUsage( unsigned short id );
float           Scr_GetEndonUsage( unsigned short id );
float           Scr_GetThreadUsage( const struct VariableStackBuffer_s *buf, float *endonUsage );

Variable                scrVarIndirections[VARIABLELIST_SIZE];

/* retail 0x009B6478 -- 65536 * 12 bytes */
VariableValueInternal   scrVarNodes[VARIABLELIST_SIZE];

unsigned short          scrVarPub_tempVariable;

/* retail 0x0140735C / 0x01407360: halfwords inside one struct, so VC7 may read them as dwords */
struct {
	unsigned short      classId;
	unsigned short      pad0;
	unsigned short      entId;
	unsigned short      pad1;
} scrVarPub_ids;
#define scrVarPub_classId   scrVarPub_ids.classId
#define scrVarPub_entId     scrVarPub_ids.entId

scrClassMapEntry_t     *scrVarPub_classMap;
unsigned int            scrVarPub_classNum;

int                     scrVarPub_error_index;

char                   *scrVarPub_fieldBuffer;  /* 0x00976468 */
int scrVarPub_programBuffer;   /* 0x01407380 */
int scrVarPub_endScriptBuffer;   /* 0x01407384 */
int scrVarPub_developer;   /* 0x008E60D0 */
int scrVarPub_developerScript;   /* 0x008E60C4 */
int scrVarPub_canonicalStrCountAndLoadFlags;   /* 0x008E60BC */

/* retail 0x005757C8 */
const char * const var_typename[VAR_TYPE_COUNT] = {
	"undefined",
	"string",
	"localized string",
	"vector",
	"float",
	"int",
	"codepos",
	"object",
	"key/value",
	"function",
	"stack",
	"animation",
	"thread",
	"entity",
	"struct",
	"array",
	"dead thread",
	"dead entity",
	"dead object"
};

#define VAR_REFCOUNT( n )   ( (n)->u.halfword.lo )
#define VAR_OBJECTID( n )   ( (n)->u.halfword.lo )
#define VAR_PREVFREE( n )   ( (n)->u.halfword.lo )
#define VAR_KVENTNUM( n )   ( (n)->u.halfword.lo )
#define VAR_SELF( n )       ( (n)->u.halfword.hi )
#define VAR_ENTNUM( n )     ( (n)->u.halfword.hi )
#define VAR_ARRAYSIZE( n )  ( (n)->u.halfword.hi )
#define VAR_KVOFFSET( n )   ( (n)->u.halfword.hi )

#define VAR_NODEINDEX( n )  ( (unsigned short)( (n) - scrVarNodes ) )
#define VAR_HANDLEINDEX( s )( (unsigned short)( (s) - scrVarIndirections ) )

#define VAR_TYPE( n )       ( (int)( (n)->status & VAR_STATUS_TYPE_MASK ) )
#define VAR_STAT( n )       ( (n)->status & VAR_STATUS_STAT_MASK )
#define VAR_NAME( n )       ( (n)->status >> VAR_STATUS_NAME_SHIFT )

#define VAR_PACKED_THREAD   ( VAR_STAT_EXTERNAL | VAR_THREAD )
#define VAR_PACKED_ENTITY   ( VAR_STAT_EXTERNAL | VAR_ENTITY )
#define VAR_PACKED_STRUCT   ( VAR_STAT_EXTERNAL | VAR_STRUCT )
#define VAR_PACKED_ARRAY    ( VAR_STAT_EXTERNAL | VAR_ARRAY )

#define SCR_VECTOR_ALLOC_SIZE   ( 2 + 3 * 4 )

#define SCR_STRING_MT_TYPE_TEMP     14
#define SCR_STRING_MT_TYPE_FIELD    15      /* Scr_AddClassField, 0x00472781 */

typedef struct scrThreadInfo_s {
	const char *callStack[32];  /* +0x00  innermost first */
	int         callStackCount; /* +0x80 */
	float       varUsage;       /* +0x84 */
	float       endonUsage;     /* +0x88 */
} scrThreadInfo_t;

/* ---- ThreadInfoCompare  0x00470530 ---- VERIFIED */
int __cdecl ThreadInfoCompare( const void *a, const void *b ) {
	const scrThreadInfo_t *ta = (const scrThreadInfo_t *)a;
	const scrThreadInfo_t *tb = (const scrThreadInfo_t *)b;
	int i;

	for ( i = 0; i < ta->callStackCount; i++ ) {
		const char *left;
		const char *right;
		if ( i >= tb->callStackCount ) {
			break;
		}
		left = ta->callStack[i];
		right = tb->callStack[i];
		if ( left != right ) {
			return (int)( left - right );
		}
	}
	return ta->callStackCount - tb->callStackCount;
}

/* ---- Scr_DumpScriptThreads  0x00470580 ---- VERIFIED */
void Scr_DumpScriptThreads( void ) {
	scrThreadInfo_t            *threadInfo;
	scrThreadInfo_t            *nextInfo;
	scrThreadInfo_t            *pInfo;
	scrThreadInfo_t             info;
	VariableValueInternal      *node;
	const VariableStackBuffer  *stackBuf;
	const unsigned char        *buf;
	const char                 *pos;
	unsigned char               type;
	const char                 *codePos;
	int                         size;
	int                         numThreads;
	int                         count;
	int                         t;
	int                         j;
	unsigned int                i;
	unsigned short              child;
	float                       threadVarUsage;
	float                       endonUsage;

	threadInfo = (scrThreadInfo_t *)malloc( sizeof( scrThreadInfo_t ) * VARIABLELIST_SIZE );
	if ( !threadInfo ) {
		Sys_OutOfMemoryError();
	}
	Com_Memset( threadInfo, 0, sizeof( scrThreadInfo_t ) * VARIABLELIST_SIZE );

	numThreads = 0;
	nextInfo = threadInfo;
	for ( i = 1; i < VARIABLELIST_SIZE; i++ ) {
		node = &scrVarNodes[i];
		if ( VAR_STAT( node ) == VAR_STAT_FREE || VAR_TYPE( node ) != VAR_STACK ) {
			continue;
		}
		stackBuf = (const VariableStackBuffer *)node->u.pointerValue;
		pos = stackBuf->codePos;
		numThreads++;
		size = stackBuf->size;
		pInfo = nextInfo++;

		info.callStackCount = 0;
		buf = (const unsigned char *)stackBuf + SCR_STACKBUFFER_HEADER;
		while ( size ) {
			size--;
			type = *buf++;
			codePos = *(const char * const *)buf;
			buf += sizeof( VariableUnion );
			if ( type == VAR_CODEPOS ) {
				info.callStack[info.callStackCount++] = codePos;
			}
		}
		info.callStack[info.callStackCount++] = pos;

		pInfo->varUsage       = Scr_GetThreadUsage( stackBuf, &pInfo->endonUsage );
		pInfo->callStackCount = info.callStackCount--;
		for ( j = 0; j < pInfo->callStackCount; j++ ) {
			pInfo->callStack[j] = info.callStack[info.callStackCount - j];
		}
	}

	qsort_m( threadInfo, numThreads, sizeof( scrThreadInfo_t ), ThreadInfoCompare );

	Com_Printf( "********************************\n" );
	t = 0;
	while ( t < numThreads ) {
		/* 0x004706F4..0x00470740: both group sums live in st0/st1 for the
		   whole do-while (fadd dword, no fstp, kept across ThreadInfoCompare)
		   and go straight to __ftol2, retaining extended precision while live. */
		pInfo          = &threadInfo[t];
		threadVarUsage = 0;
		endonUsage     = 0;
		count          = 0;
		do {
			count++;
			threadVarUsage += threadInfo[t].varUsage;
			endonUsage     += threadInfo[t].endonUsage;
			t++;
		} while ( t < numThreads && !ThreadInfoCompare( pInfo, &threadInfo[t] ) );

		Com_Printf( "count: %d, var usage: %d, endon usage: %d\n",
					count, (int)threadVarUsage, (int)endonUsage );
		Scr_PrintPrevCodePos( pInfo->callStack[0], 0 );
		for ( j = 1; j < pInfo->callStackCount; j++ ) {
			Com_Printf( "called from:\n" );
			Scr_PrintPrevCodePos( pInfo->callStack[j], 0 );
		}
	}
	free( threadInfo );

	Com_Printf( "********************************\n" );
	for ( i = 0; i < scrVarPub_classNum; i++ ) {
		if ( !FindVariable( scrVarPub_entId, i ) ) {
			continue;
		}
		info.varUsage = 0;
		count    = 0;
		for ( child = FindNextSibling( FindObject( FindVariable( scrVarPub_entId, i ) ) ); child;
		      child = FindNextSibling( child ) ) {
			count++;
			info.varUsage += Scr_GetObjectUsage( FindObject( child ) );
		}
		Com_Printf( "ent type '%s'... count: %d, var usage: %d\n",
					scrVarPub_classMap[i].name, count, (int)info.varUsage );
	}
	Com_Printf( "********************************\n" );
}

/* ---- Scr_DumpScriptVariables  0x004708F0 ---- VERIFIED */
void Scr_DumpScriptVariables( void ) {
}

/* ---- InitVariables  0x00470900 ---- VERIFIED */
void InitVariables( void ) {
	unsigned int    i;
	unsigned short  prev = 0;

	for ( i = 1; i < VARIABLELIST_SIZE; i++ ) {
		scrVarNodes[i].status = VAR_UNDEFINED;
		scrVarNodes[prev].hashNext = (unsigned short)i;
		VAR_PREVFREE( &scrVarNodes[i] ) = prev;
		scrVarIndirections[i].id = (unsigned short)i;
		prev = (unsigned short)i;
	}

	scrVarNodes[0].status = VAR_UNDEFINED;
	scrVarNodes[prev].hashNext = 0;
	scrVarIndirections[0].id = 0;
	VAR_PREVFREE( &scrVarNodes[0] ) = prev;
}

/* ---- Var_Init  0x00470970 ---- VERIFIED */
void Var_Init( void ) {
	SL_Init();
	InitVariables();
	scrVarPub_classId = AllocObject();
	scrVarPub_entId   = AllocObject();
}

/* ---- Scr_GetNumScriptVars  0x004709E0 ---- VERIFIED */
int Scr_GetNumScriptVars( void ) {
	return 0;
}

/* ---- AllocVariable  0x004713F0 ---- VERIFIED */
VariableValueInternal *AllocVariable( void ) {
	unsigned short          freeHandle;
	Variable               *entry;
	VariableValueInternal  *node;

	freeHandle = scrVarNodes[0].hashNext;
	if ( !freeHandle ) {
		Scr_TerminalError( "exceeded maximum number of script variables" );
	}

	entry = &scrVarIndirections[freeHandle];
	node = &scrVarNodes[ entry->id ];

	scrVarNodes[0].hashNext = node->hashNext;
	VAR_PREVFREE( &scrVarNodes[ scrVarIndirections[ scrVarNodes[0].hashNext ].id ] ) = 0;

	node->hashNext    = freeHandle;
	node->nextSibling = freeHandle;
	entry->prevSibling = freeHandle;

	return node;
}

/* ---- FreeVariable  0x00471460 ---- VERIFIED */
void FreeVariable( unsigned short id ) {
	VariableValueInternal  *node = &scrVarNodes[id];
	unsigned short          handle = node->hashNext;
	unsigned short          prev   = scrVarIndirections[handle].prevSibling;
	unsigned short          next   = node->nextSibling;

	scrVarIndirections[next].prevSibling = prev;
	scrVarNodes[ scrVarIndirections[prev].id ].nextSibling = next;

	node->status &= ~VAR_STATUS_STAT_MASK;
	node->hashNext = scrVarNodes[0].hashNext;
	VAR_PREVFREE( node ) = 0;
	VAR_PREVFREE( &scrVarNodes[ scrVarIndirections[ scrVarNodes[0].hashNext ].id ] ) = handle;
	scrVarNodes[0].hashNext = handle;
}

/* ---- AllocValue  0x004714E0 ---- VERIFIED */
unsigned short AllocValue( void ) {
	VariableValueInternal *node = AllocVariable();

	node->status = VAR_STAT_EXTERNAL;
	return VAR_NODEINDEX( node );
}

/* ---- AllocObject  0x00471510 ---- VERIFIED */
unsigned short AllocObject( void ) {
	VariableValueInternal *node = AllocVariable();

	node->status = VAR_PACKED_STRUCT;
	VAR_REFCOUNT( node ) = 0;
	return VAR_NODEINDEX( node );
}

/* ---- Scr_AllocArray  0x00471580 ---- VERIFIED */
unsigned short Scr_AllocArray( void ) {
	VariableValueInternal *node = AllocVariable();

	node->status = VAR_PACKED_ARRAY;
	VAR_REFCOUNT( node )  = 0;
	VAR_ARRAYSIZE( node ) = 0;
	return VAR_NODEINDEX( node );
}

/* ---- AllocEntity  0x00471540 ---- VERIFIED */
unsigned short AllocEntity( int classnum, unsigned short entnum ) {
	VariableValueInternal *node = AllocVariable();

	node->status = ( (unsigned int)classnum << VAR_STATUS_NAME_SHIFT ) | VAR_PACKED_ENTITY;
	VAR_REFCOUNT( node ) = 0;
	VAR_ENTNUM( node )   = entnum;
	return VAR_NODEINDEX( node );
}

/* ---- AllocThread  0x004715C0 ---- VERIFIED
   Retail inlines this into VM_Execute (self read before AllocVariable); VC7 only
   does so here with __forceinline. The out-of-line copy is unchanged. */
unsigned short AllocThread( unsigned short self ) {
	VariableValueInternal *node = AllocVariable();

	node->status = VAR_PACKED_THREAD;
	VAR_REFCOUNT( node ) = 0;
	VAR_SELF( node )     = self;
	return VAR_NODEINDEX( node );
}

/* ---- AddRefToObject  0x004716A0 ---- VERIFIED */
void AddRefToObject( unsigned short id ) {
	VAR_REFCOUNT( &scrVarNodes[id] )++;
}

/* ---- RemoveRefToObject  0x004716B0 ---- VERIFIED */
void RemoveRefToObject( unsigned short id ) {
	/* through a pointer: ClearObject's inlined AddRef stays an inc word, as in retail */
	VariableValueInternal *entry = &scrVarNodes[id];

	if ( VAR_REFCOUNT( entry ) ) {
		VAR_REFCOUNT( entry )--;
		return;
	}
	ClearObject( id );
	FreeVariable( id );
}

/* ---- AllocVector  0x00471700 ---- VERIFIED */
float *AllocVector( void ) {
	float *v = (float *)( (unsigned short *)MT_Alloc( SCR_VECTOR_ALLOC_SIZE, 2 ) + 1 );

	( (unsigned short *)v )[-1] = 0;
	return v;
}

/* ---- AllocVector  0x00471720 ---- VERIFIED */
VariableUnion AllocVectorValue( const float *v ) {
	VariableUnion   u;
	float          *copy = AllocVector();

	copy[0] = v[0];
	copy[1] = v[1];
	copy[2] = v[2];
	u.vectorValue = copy;
	return u;
}

/* ---- AddRefToVector  0x00471750 ---- VERIFIED */
extern const char *scrMemTree_constBase;
extern int scrMemTree_constLen;
void AddRefToVector( const float *v ) {
	if ( (unsigned int)((const char *)v - scrMemTree_constBase) < (unsigned int)scrMemTree_constLen ) return;
	( (unsigned short *)v )[-1]++;
}

/* ---- RemoveRefToVector  0x00471770 ---- VERIFIED */
void RemoveRefToVector( const float *v ) {
	unsigned short refCount;
	if ( (unsigned int)((const char *)v - scrMemTree_constBase) < (unsigned int)scrMemTree_constLen ) return;
	refCount = ((unsigned short *)v)[-1];
	if ( refCount ) {
		((unsigned short *)v)[-1] = refCount - 1;
		return;
	}
	MT_Free( (unsigned short *)v - 1, SCR_VECTOR_ALLOC_SIZE );
}

/* ---- AddRefToValue  0x004717B0 ---- VERIFIED */
void AddRefToValue( int type, VariableUnion u ) {
	switch ( type ) {
	case VAR_OBJECT: AddRefToObject( u.halfword.lo ); break;
	case VAR_STRING:
	case VAR_ISTRING: SL_AddRefToString( u.stringValue ); break;
	case VAR_VECTOR: AddRefToVector( u.vectorValue ); break;
	default: break;
	}
}

/* ---- RemoveRefToValue  0x00471820 ---- VERIFIED */
void RemoveRefToValue( int type, VariableUnion u ) {
	switch ( type ) {
	case VAR_OBJECT: RemoveRefToObject( u.halfword.lo ); break;
	case VAR_STRING:
	case VAR_ISTRING: SL_RemoveRefToString( u.stringValue ); break;
	case VAR_VECTOR: RemoveRefToVector( u.vectorValue ); break;
	default: break;
	}
}

/* ---- FreeValue  0x00471610 ---- VERIFIED */
void FreeValueInternal( VariableValueInternal *node ) {
	RemoveRefToValue( VAR_TYPE( node ), node->u );
	FreeVariable( VAR_NODEINDEX( node ) );
}

/* ---- FreeValue  0x00471680 ---- VERIFIED */
void FreeValue( unsigned short id ) {
	FreeValueInternal( &scrVarNodes[id] );
}

/* ---- IsValidArrayIndex  0x00471870 ---- VERIFIED */
qboolean IsValidArrayIndex( unsigned int index ) {
	return 0xFDFFFFu >= ( index + 0x7E0000u ) ? qtrue : qfalse;
}

/* ---- GetInternalVariableIndex  0x00471880 ---- VERIFIED */
unsigned int GetInternalVariableIndex( unsigned int index ) {
	return ( index - VAR_NAME_INDEX_BIAS ) & VAR_NAME_INDEX_MASK;
}

static unsigned short Var_HashBucket( unsigned short parentId, unsigned int name ) {
	return (unsigned short)( ( name + 31u * (unsigned int)parentId ) % 0xFFFFu + 1u );
}

/* ---- FindVariableIndexInternal  0x00470A30 ---- VERIFIED */
unsigned short FindVariableIndexInternal( unsigned short parentId, unsigned int name ) {
	unsigned short          bucket = Var_HashBucket( parentId, name );
	Variable               *bucketSlot = &scrVarIndirections[bucket];
	VariableValueInternal  *node = &scrVarNodes[ bucketSlot->id ];
	unsigned short          link;
	Variable               *slot;

	if ( VAR_STAT( node ) != VAR_STAT_HEAD ) {
		return 0;
	}
	if ( VAR_NAME( node ) == name ) {
		return bucket;
	}

	link = node->hashNext;
	slot = &scrVarIndirections[link];
	node = &scrVarNodes[ slot->id ];
	while ( slot != bucketSlot ) {
		if ( VAR_NAME( node ) == name ) {
			return link;
		}
		link = node->hashNext;
		slot = &scrVarIndirections[link];
		node = &scrVarNodes[ slot->id ];
	}
	return 0;
}

/* ---- GetVariableIndexInternal  0x00470AE0 ---- VERIFIED */
unsigned short GetVariableIndexInternal( unsigned short parentId, unsigned int name ) {
	unsigned short          index;
	unsigned short          newIndex;
	unsigned short          link;
	unsigned short          id;
	Variable               *entry;
	Variable               *newEntry;
	Variable               *walkEntry;
	VariableValueInternal  *entryValue;
	VariableValueInternal  *newEntryValue;
	VariableValueInternal  *walkValue;
	VariableValueInternal  *parentValue;
	unsigned short          prevFree;
	unsigned short          nextFree;
	unsigned short          nextSibling;

	/* Mac 1.3 shape: the free-list pop is written out here (no AllocVariable call) */
	index      = Var_HashBucket( parentId, name );
	entry      = &scrVarIndirections[index];
	entryValue = &scrVarNodes[entry->id];

	if ( VAR_STAT( entryValue ) == VAR_STAT_HEAD ) {
		if ( VAR_NAME( entryValue ) == name ) {
			return index;
		}

		link      = entryValue->hashNext;
		walkEntry = &scrVarIndirections[link];
		walkValue = &scrVarNodes[walkEntry->id];
		while ( walkEntry != entry ) {
			if ( VAR_NAME( walkValue ) == name ) {
				return link;
			}
			link      = walkValue->hashNext;
			walkEntry = &scrVarIndirections[link];
			walkValue = &scrVarNodes[walkEntry->id];
		}

		newIndex = scrVarNodes[0].hashNext;
		if ( !newIndex ) {
			Scr_TerminalError( "exceeded maximum number of script variables" );
		}
		newEntry      = &scrVarIndirections[newIndex];
		newEntryValue = &scrVarNodes[newEntry->id];
		scrVarNodes[0].hashNext = newEntryValue->hashNext;
		VAR_PREVFREE( &scrVarNodes[ scrVarIndirections[ scrVarNodes[0].hashNext ].id ] ) = 0;
		newEntryValue->status   = VAR_STAT_CHAINED;
		newEntryValue->hashNext = entryValue->hashNext;
		entryValue->hashNext    = newIndex;
	} else {
		if ( VAR_STAT( entryValue ) == VAR_STAT_FREE ) {
			prevFree = VAR_PREVFREE( entryValue );
			nextFree = entryValue->hashNext;
			scrVarNodes[ scrVarIndirections[prevFree].id ].hashNext = nextFree;
			VAR_PREVFREE( &scrVarNodes[ scrVarIndirections[nextFree].id ] ) = prevFree;
			/* Mac 1.3 recomputes the node from the bucket slot here */
			newEntryValue = &scrVarNodes[entry->id];
		} else {
			newIndex = scrVarNodes[0].hashNext;
			if ( !newIndex ) {
				Scr_TerminalError( "exceeded maximum number of script variables" );
			}
			newEntry      = &scrVarIndirections[newIndex];
			newEntryValue = &scrVarNodes[newEntry->id];
			scrVarNodes[0].hashNext = newEntryValue->hashNext;
			VAR_PREVFREE( &scrVarNodes[ scrVarIndirections[ scrVarNodes[0].hashNext ].id ] ) = 0;

			nextSibling = entryValue->nextSibling;
			scrVarNodes[ scrVarIndirections[entry->prevSibling].id ].nextSibling = newIndex;
			scrVarIndirections[nextSibling].prevSibling = newIndex;

			if ( VAR_STAT( entryValue ) == VAR_STAT_CHAINED ) {
				for ( id = scrVarIndirections[entryValue->hashNext].id;
					  scrVarNodes[id].hashNext != index;
					  id = scrVarIndirections[ scrVarNodes[id].hashNext ].id ) {
				}
				scrVarNodes[id].hashNext = newIndex;
			} else {
				entryValue->hashNext = newIndex;
			}

			newEntry->prevSibling = entry->prevSibling;
			id           = newEntry->id;
			newEntry->id = entry->id;
			entry->id    = id;
		}
		newIndex = index;
		newEntryValue->status   = VAR_STAT_HEAD;
		newEntry = entry;
		newEntryValue->hashNext = index;
	}

	parentValue = &scrVarNodes[parentId];
	nextSibling = parentValue->nextSibling;
	newEntryValue->nextSibling = nextSibling;
	scrVarIndirections[nextSibling].prevSibling = newIndex;
	parentValue->nextSibling = newIndex;
	newEntry->prevSibling = parentValue->hashNext;
	newEntryValue->status = ( newEntryValue->status & 0xFF ) | ( name << VAR_STATUS_NAME_SHIFT );

	if ( VAR_TYPE( parentValue ) == VAR_ARRAY ) {
		VAR_ARRAYSIZE( parentValue )++;
		if ( name < VAR_NAME_OBJECT_BASE ) {
			SL_AddRefToString( (unsigned short)name );
		} else if ( name < VAR_NAME_OBJECT_LIMIT ) {
			AddRefToObject( (unsigned short)name );
		}
	}

	return newIndex;
}

/* ---- MakeVariableExternal  0x00470E00 ---- VERIFIED */
void MakeVariableExternal( Variable *slot, VariableValueInternal *parentNode ) {
	unsigned short          index = VAR_HANDLEINDEX( slot );
	VariableValueInternal  *entryValue = &scrVarNodes[ slot->id ];
	unsigned int            name;
	unsigned short          newIndex;
	Variable               *newEntry;
	VariableValueInternal  *newEntryValue;
	Variable               *prev;
	Variable               *walkEntry;
	VariableValueInternal  *walkValue;
	Variable                tmp;
	unsigned short          removedPrev;
	unsigned short          removedNext;
	unsigned short          promotedPrev;

	if ( VAR_TYPE( parentNode ) == VAR_ARRAY ) {
		VAR_ARRAYSIZE( parentNode )--;
		name = VAR_NAME( entryValue );
		if ( name < VAR_NAME_OBJECT_BASE ) {
			SL_RemoveRefToString( (unsigned short)name );
		} else if ( name < VAR_NAME_OBJECT_LIMIT ) {
			RemoveRefToObject( (unsigned short)name );
		}
	}

	/* Mac 1.3 shape: both paths end in the one EXTERNAL store */
	if ( VAR_STAT( entryValue ) == VAR_STAT_HEAD ) {
		newIndex      = entryValue->hashNext;
		newEntry      = &scrVarIndirections[newIndex];
		newEntryValue = &scrVarNodes[newEntry->id];
		if ( newEntry != slot ) {
			newEntryValue->status = ( newEntryValue->status & ~VAR_STATUS_STAT_MASK ) | VAR_STAT_HEAD;
			removedPrev  = slot->prevSibling;
			removedNext  = entryValue->nextSibling;
			promotedPrev = newEntry->prevSibling;
			scrVarIndirections[newEntryValue->nextSibling].prevSibling = index;
			scrVarNodes[ scrVarIndirections[promotedPrev].id ].nextSibling = index;
			scrVarIndirections[removedNext].prevSibling = newIndex;
			scrVarNodes[ scrVarIndirections[removedPrev].id ].nextSibling = newIndex;

			tmp       = *slot;
			*slot     = *newEntry;
			*newEntry = tmp;
			index = newIndex;
		}
	} else {
		walkEntry = slot;
		walkValue = entryValue;
		do {
			prev      = walkEntry;
			walkEntry = &scrVarIndirections[walkValue->hashNext];
			walkValue = &scrVarNodes[walkEntry->id];
		} while ( walkEntry != slot );

		scrVarNodes[prev->id].hashNext = entryValue->hashNext;
	}

	entryValue->status = ( entryValue->status & ~VAR_STATUS_STAT_MASK ) | VAR_STAT_EXTERNAL;
	entryValue->hashNext = index;
}

/* ---- FindArrayVariableIndex  0x00471890 ---- VERIFIED */
unsigned short FindArrayVariableIndex( unsigned short parentId, unsigned int index ) {
	return FindVariableIndexInternal( parentId, GetInternalVariableIndex( index ) );
}

/* ---- FindArrayVariable  0x004718B0 ---- VERIFIED */
unsigned short FindArrayVariable( unsigned short parentId, int index ) {
	return scrVarIndirections[ FindArrayVariableIndex( parentId, (unsigned int)index ) ].id;
}

/* ---- FindVariable  0x004718E0 ---- VERIFIED */
unsigned short FindVariable( unsigned short parentId, unsigned int name ) {
	return scrVarIndirections[ FindVariableIndexInternal( parentId, name ) ].id;
}

/* ---- FindObjectVariable  0x00471900 ---- VERIFIED */
unsigned short FindObjectVariable( unsigned short parentId, unsigned short childId ) {
	return scrVarIndirections[
		FindVariableIndexInternal( parentId, (unsigned int)childId + VAR_NAME_OBJECT_BASE ) ].id;
}

/* ---- GetArrayVariableIndex  0x00471930 ---- VERIFIED */
unsigned short GetArrayVariableIndex( unsigned short parentId, unsigned int index ) {
	return GetVariableIndexInternal( parentId, GetInternalVariableIndex( index ) );
}

/* ---- GetArrayVariable  0x00471B00 ---- VERIFIED */
unsigned short GetArrayVariable( unsigned short parentId, int index ) {
	return scrVarIndirections[ GetArrayVariableIndex( parentId, (unsigned int)index ) ].id;
}

/* ---- GetVariable  0x00471B40 ---- VERIFIED */
unsigned short GetVariable( unsigned short parentId, unsigned int name ) {
	return scrVarIndirections[ GetVariableIndexInternal( parentId, name ) ].id;
}

/* ---- GetObjectVariable  0x00471B60 ---- VERIFIED */
unsigned short GetObjectVariable( unsigned short parentId, unsigned short childId ) {
	return scrVarIndirections[
		GetVariableIndexInternal( parentId, (unsigned int)childId + VAR_NAME_OBJECT_BASE ) ].id;
}

/* ---- GetVariableField  0x00471950 ---- VERIFIED */
unsigned short GetVariableField( unsigned short parentId, unsigned short name ) {
	unsigned short          handle;
	VariableValueInternal  *parentNode;
	VariableValueInternal  *tempNode;
	unsigned short          fieldId;
	unsigned int            parentType;
	unsigned short entnum;

	handle = FindVariableIndexInternal( parentId, name );
	if ( handle ) {
		return scrVarIndirections[handle].id;
	}

	parentNode = &scrVarNodes[parentId];
	parentType = VAR_TYPE( parentNode );

	if ( parentType < VAR_DEADTHREAD ) {

	if ( parentType != VAR_ENTITY ) {
		return scrVarIndirections[ GetVariableIndexInternal( parentId, name ) ].id;
	}

	fieldId = FindArrayVariable( scrVarPub_classMap[ VAR_NAME( parentNode ) ].id, name );
	if ( !fieldId ) {
		return scrVarIndirections[ GetVariableIndexInternal( parentId, name ) ].id;
	}

	entnum = VAR_ENTNUM(parentNode);
	ClearVariableValue( scrVarPub_tempVariable );
	tempNode = &scrVarNodes[ scrVarPub_tempVariable ];
	tempNode->status = ( parentNode->status & ~0xFFu ) | tempNode->status | VAR_KEYVALUE;
	VAR_KVENTNUM( tempNode ) = entnum;
	VAR_KVOFFSET( tempNode ) = VAR_ARRAYSIZE( &scrVarNodes[fieldId] );

	return scrVarPub_tempVariable;
	}
	ClearVariableValue( scrVarPub_tempVariable );
	return scrVarPub_tempVariable;
}

/* ---- ClearVariableField  0x00471A70 ---- VERIFIED */
void ClearVariableField( unsigned short parentId, unsigned short name ) {
	VariableValueInternal *parentNode;

	if ( FindVariableIndexInternal( parentId, name ) ) {
		RemoveVariable( parentId, name );
		return;
	}

	parentNode = &scrVarNodes[parentId];
	if ( (parentNode->status & VAR_STATUS_TYPE_MASK) >= VAR_DEADTHREAD ) return;
	if ( VAR_TYPE( parentNode ) == VAR_ENTITY ) {
		if ( FindArrayVariable( scrVarPub_classMap[ VAR_NAME( parentNode ) ].id, name ) ) {
			Scr_Error( "cannot set entity builtin key/value to undefined" );
		}
	}
}

/* ---- RemoveVariable  0x00471B80 ---- VERIFIED */
void RemoveVariable( unsigned short parentId, unsigned int name ) {
	unsigned short          handle = FindVariableIndexInternal( parentId, name );
	/* slot->id through the pointer: VC7 then folds both into [handle*4+X] like retail */
	Variable               *slot = &scrVarIndirections[handle];
	VariableValueInternal  *entry = &scrVarNodes[slot->id];

	MakeVariableExternal( slot, &scrVarNodes[parentId] );
	FreeValueInternal( entry );
}

/* ---- RemoveObjectVariable  0x00471BD0 ---- VERIFIED */
void RemoveObjectVariable( unsigned short parentId, unsigned short childId ) {
	RemoveVariable( parentId, (unsigned int)childId + VAR_NAME_OBJECT_BASE );
}

/* ---- SafeRemoveArrayVariable  0x00471C20 ---- VERIFIED */
void SafeRemoveArrayVariable( unsigned short parentId, unsigned int index ) {
	SafeRemoveVariable( parentId, GetInternalVariableIndex( index ) );
}

/* ---- RemoveArrayVariable  0x00471C80 ---- VERIFIED */
void RemoveArrayVariable( unsigned short parentId, unsigned int index ) {
	RemoveVariable( parentId, GetInternalVariableIndex( index ) );
}

/* ---- SafeRemoveVariable  0x00471CD0 ---- VERIFIED */
void SafeRemoveVariable( unsigned short parentId, unsigned int name ) {
	unsigned short          handle = FindVariableIndexInternal( parentId, name );
	Variable               *slot;
	VariableValueInternal  *entry;

	if ( !handle ) {
		return;
	}
	slot = &scrVarIndirections[handle];
	entry = &scrVarNodes[slot->id];
	MakeVariableExternal( slot, &scrVarNodes[parentId] );
	FreeValueInternal( entry );
}

/* ---- ClearObjectInternal  0x00470F70 ---- VERIFIED */
void ClearObjectInternal( unsigned short id ) {
	Variable       *slot;
	unsigned short  childId;
	VariableValueInternal *parent = &scrVarNodes[id];

	slot = &scrVarIndirections[ parent->nextSibling ];
	childId = slot->id;
	while ( childId != id ) {
		MakeVariableExternal( slot, parent );
		slot = &scrVarIndirections[ scrVarNodes[childId].nextSibling ];
		childId = slot->id;
	}

	childId = scrVarIndirections[ parent->nextSibling ].id;
	while ( childId != id ) {
		VariableValueInternal *child = &scrVarNodes[childId];
		childId = scrVarIndirections[child->nextSibling].id;
		FreeValueInternal( child );
	}
}

/* ---- ClearObject  0x00471010 ---- VERIFIED */
void ClearObject( unsigned short id ) {
	AddRefToObject( id );
	ClearObjectInternal( id );
	RemoveRefToObject( id );
}

/* ---- GetThreadNotifyName  0x00471040 ---- VERIFIED */
unsigned short GetThreadNotifyName( unsigned short id ) {
	return (unsigned short)VAR_NAME( &scrVarNodes[id] );
}

/* ---- SetThreadNotifyName  0x00471060 ---- VERIFIED */
void SetThreadNotifyName( unsigned short id, unsigned short name ) {
	SL_AddRefToString( name );
	scrVarNodes[id].status |= (unsigned int)name << VAR_STATUS_NAME_SHIFT;
}

/* ---- ClearThreadNotifyName  0x00471090 ---- VERIFIED */
void ClearThreadNotifyName( unsigned short id ) {
	SL_RemoveRefToString( GetThreadNotifyName( id ) );
	scrVarNodes[id].status &= 0xFF;
}

/* ---- KillThread  0x00471100 ---- VERIFIED */
void KillThread( unsigned short id ) {
	unsigned short endonId;
	unsigned short self;
	unsigned short pauseSlot;
	unsigned short bucket;

	AddRefToObject( id );
	ClearObjectInternal( id );

	endonId = VAR_SELF( &scrVarNodes[id] );
	RemoveRefToObject( endonId );

	self = VAR_SELF( &scrVarNodes[id] );

	pauseSlot = FindObjectVariable( scrVarPub_pauseArrayId, id );
	if ( pauseSlot ) {
		bucket = VAR_OBJECTID( &scrVarNodes[pauseSlot] );

		for ( ;; ) {
			unsigned short          entry;
			unsigned short          waiter;
			unsigned short          handle;

			entry = FindNextSibling( bucket );
			if ( !entry ) {
				break;
			}
			waiter = (unsigned short)VAR_NAME( &scrVarNodes[entry] );

			handle = FindVariableIndexInternal( bucket,
					(unsigned int)waiter + VAR_NAME_OBJECT_BASE );
			VM_CancelNotify__FUsUs( waiter,
					VAR_OBJECTID( &scrVarNodes[ scrVarIndirections[handle].id ] ) );

			scrVarNodes[waiter].status =
				( scrVarNodes[waiter].status & ~VAR_STATUS_TYPE_MASK ) | VAR_DEADTHREAD;

			RemoveVariable( bucket, (unsigned int)waiter + VAR_NAME_OBJECT_BASE );

			RemoveRefToObject( id );
		}

		RemoveObjectVariable( scrVarPub_pauseArrayId, id );
	}

	if ( GetThreadNotifyName( id ) ) {
		pauseSlot = FindObjectVariable( scrVarPub_pauseArrayId, self );
		bucket    = VAR_OBJECTID( &scrVarNodes[pauseSlot] );

		VM_CancelNotify__FUsUs( id,
			VAR_OBJECTID( &scrVarNodes[ FindObjectVariable( bucket, id ) ] ) );

		bucket = VAR_OBJECTID( &scrVarNodes[
			FindObjectVariable( scrVarPub_pauseArrayId, self ) ] );
		RemoveObjectVariable( bucket, id );

		if ( VAR_ARRAYSIZE( &scrVarNodes[bucket] ) == 0 ) {
			RemoveObjectVariable( scrVarPub_pauseArrayId, self );
		}
	}

	scrVarNodes[id].status = ( scrVarNodes[id].status & ~VAR_STATUS_TYPE_MASK ) | VAR_DEADTHREAD;
	RemoveRefToObject( id );
}

/* ---- SetVariableValue  0x00471E50 ---- VERIFIED */
void SetVariableValue( unsigned short id, VariableValue *value ) {
	VariableValueInternal *node = &scrVarNodes[id];

	RemoveRefToValue( VAR_TYPE( node ), node->u );
	node->status &= ~VAR_STATUS_TYPE_MASK;
	node->status |= (unsigned int)value->type;
	node->u = value->u;
}

/* ---- SetNewVariableValue  0x00471ED0 ---- VERIFIED */
void SetNewVariableValue( unsigned short id, VariableValue *value ) {
	VariableValueInternal *node = &scrVarNodes[id];

	node->status |= (unsigned int)value->type;
	node->u = value->u;
}

/* ---- GetVariableValueAddress  0x00471EF0 ---- VERIFIED */
VariableValue *GetVariableValueAddress( unsigned short id ) {
	return (VariableValue *)&scrVarNodes[id];
}

/* ---- ClearVariableValue  0x00471F00 ---- VERIFIED */
void ClearVariableValue( unsigned short id ) {
	VariableValueInternal *node = &scrVarNodes[id];

	RemoveRefToValue( VAR_TYPE( node ), node->u );
	node->status &= VAR_STATUS_STAT_MASK;
}

/* ---- SetVariableFieldValue  0x00471F80 ---- VERIFIED */
void SetVariableFieldValue( unsigned short id, VariableValue *value ) {
	VariableValueInternal *node = &scrVarNodes[id];
	switch (node->status & VAR_STATUS_TYPE_MASK) {
	case VAR_KEYVALUE:
		SetEntityFieldValue__FUiiiP13VariableValue(node->status >> 8, VAR_KVENTNUM(node), VAR_KVOFFSET(node), value);
		return;
	case VAR_OBJECT:
		RemoveRefToObject(VAR_OBJECTID(node));
		break;
	case VAR_STRING:
	case VAR_ISTRING:
		SL_RemoveRefToString(node->u.stringValue);
		break;
	case VAR_VECTOR:
		RemoveRefToVector(node->u.vectorValue);
		break;
	}
	node->status &= ~VAR_STATUS_TYPE_MASK;
	node->status |= (unsigned int)value->type;
	node->u = value->u;
}

/* ---- GetVariableValue  0x00472020 ---- VERIFIED */
void GetVariableValue( unsigned short id, VariableValue *value ) {
	VariableValueInternal *entry = &scrVarNodes[id];

	value->type = VAR_TYPE( entry );
	value->u = entry->u;
}

/* ---- GetVariableFieldValue  0x00472040 ---- VERIFIED */
/* id is volatile: LTCG then leaves it on the stack (callers push it, the body reads
   [esp+4]) and passes only value in a register (edi), as retail does */
void GetVariableFieldValue( volatile unsigned short id, VariableValue *value ) {
	VariableValueInternal *node = &scrVarNodes[id];
	unsigned int type = node->status & VAR_STATUS_TYPE_MASK;
	switch(type) {
	case VAR_KEYVALUE:
		GetEntityFieldValue__FUiiiP13VariableValue(VAR_NAME(node), VAR_KVENTNUM(node), VAR_KVOFFSET(node), value);
		if (value->type == VAR_OBJECT && GetVarType(value->u.halfword.lo) == VAR_ARRAY) {
			unsigned short source = value->u.halfword.lo;
			RemoveRefToObject(source);
			value->u.halfword.lo = Scr_AllocArray();
			CopyArray(source, value->u.halfword.lo);
		}
		return;
	case VAR_OBJECT:
		AddRefToObject(VAR_OBJECTID(node));
		break;
	case VAR_STRING:
	case VAR_ISTRING:
		SL_AddRefToString(node->u.stringValue);
		break;
	case VAR_VECTOR:
		AddRefToVector(node->u.vectorValue);
		break;
	}
	value->type = type;
	value->u = node->u;
}

/* ---- GetSizeValue  0x00472140 ---- VERIFIED */
void GetSizeValue( VariableValue *value ) {
	if ( value->type == VAR_OBJECT ) {
		unsigned short object = value->u.halfword.lo;
		VariableValueInternal *objectNode = &scrVarNodes[object];
		int size;

		value->type = VAR_INTEGER;
		if ( VAR_TYPE(objectNode) == VAR_ARRAY ) {
			size = VAR_ARRAYSIZE(objectNode);
		} else {
			size = 1;
		}
		value->u.intValue = size;
		RemoveRefToObject( object );
		return;
	}

	if ( value->type == VAR_STRING ) {
		unsigned short  handle = value->u.stringValue;
		const char     *text;

		value->type = VAR_INTEGER;
		text = SL_ConvertToString( handle );
		value->u.intValue = (int)strlen( text );
		SL_RemoveRefToString( handle );
		return;
	}

	Scr_Error( va( "size cannot be applied to %s", var_typename[value->type] ) );
}

/* ---- GetArraySize  0x004721F0 ---- VERIFIED */
unsigned int GetArraySize( unsigned short id ) {
	return VAR_ARRAYSIZE( &scrVarNodes[id] );
}

/* ---- FindNextSibling  0x00472200 ---- VERIFIED */
unsigned short FindNextSibling( unsigned short id ) {
	unsigned short nextSibling = scrVarNodes[id].nextSibling;

	/* Only the sibling slot is a local; the handle is read through the
	   indirection twice. That is what lets the inlined copies (KillThread,
	   CopyEntity, VM_TerminateNotifyList, ...) allocate it like retail. */
	if ( ( scrVarNodes[ scrVarIndirections[nextSibling].id ].status
			& VAR_STATUS_TYPE_MASK ) < VAR_THREAD ) {
		return scrVarIndirections[nextSibling].id;
	}
	return 0;

}

/* ---- GetVariableName  0x00472230 ---- VERIFIED */
unsigned int GetVariableName( unsigned short id ) {
	return VAR_NAME( &scrVarNodes[id] );
}

/* ---- GetVariableKeyObject  0x004709F0 ---- VERIFIED */
unsigned short GetVariableKeyObject( unsigned short id ) {
	return (unsigned short)( VAR_NAME( &scrVarNodes[id] ) - VAR_NAME_OBJECT_BASE );
}

/* ---- GetEntityType  0x00470A10 ---- VERIFIED */
unsigned int GetEntityType( unsigned short id ) {
	/* the named node pointer keeps Scr_GetEntityNum's second status load (retail 0x0047D95B) */
	VariableValueInternal *entityValue = &scrVarNodes[id];

	return VAR_NAME( entityValue );
}

/* ---- GetSelf  0x00471600 ---- VERIFIED */
unsigned short GetSelf( unsigned short id ) {
	return VAR_SELF( &scrVarNodes[id] );
}

/* ---- GetEntnum  0x00473580 ---- VERIFIED */
unsigned int GetEntnum( unsigned short id ) {
	return VAR_ENTNUM( &scrVarNodes[id] );
}

/* ---- GetObject  0x00472250 ---- VERIFIED */
unsigned short GetObject( unsigned short id ) {
	VariableValueInternal *node = &scrVarNodes[id];

	if ( VAR_TYPE( node ) == VAR_UNDEFINED ) {
		node->status |= VAR_OBJECT;
		VAR_OBJECTID( node ) = AllocObject();
	}
	return VAR_OBJECTID( node );
}

/* ---- GetArray  0x004722A0 ---- VERIFIED */
unsigned short GetArray( unsigned short id ) {
	VariableValueInternal *node = &scrVarNodes[id];

	if ( VAR_TYPE( node ) == VAR_UNDEFINED ) {
		node->status |= VAR_OBJECT;
		VAR_OBJECTID( node ) = Scr_AllocArray();
	}
	return VAR_OBJECTID( node );
}

/* ---- FindObject  0x00472300 ---- VERIFIED */
unsigned short FindObject( unsigned short id ) {
	return VAR_OBJECTID( &scrVarNodes[id] );
}

/* ---- IsFieldObject  0x00472310 ---- VERIFIED */
qboolean IsFieldObject( unsigned short id ) {
	/* unsigned compare (sbb/neg), not VAR_TYPE's int */
	return (qboolean)( ( scrVarNodes[id].status & VAR_STATUS_TYPE_MASK ) < VAR_ARRAY );
}

/* ---- Scr_IsThreadAlive  0x00472330 ---- VERIFIED */
qboolean Scr_IsThreadAlive( unsigned short id ) {
	return VAR_TYPE( &scrVarNodes[id] ) == VAR_THREAD ? qtrue : qfalse;
}

/* ---- GetVarType  0x00472420 ---- VERIFIED */
int GetVarType( unsigned short id ) {
	return VAR_TYPE( &scrVarNodes[id] );
}

/* ---- CastFieldObject  0x00472350 ---- VERIFIED */
unsigned short CastFieldObject( VariableValue *value ) {
	VariableValue   objectValue;
	int             type;

	/* Mac 1.3 shape: the type is read once and the id is returned from objectValue */
	if ( value->type == VAR_OBJECT ) {
		type = GetVarType( value->u.halfword.lo );
		if ( type < VAR_ARRAY ) {
			objectValue.type = VAR_OBJECT;
			objectValue.u.halfword.lo = value->u.halfword.lo;
			SetVariableValue( scrVarPub_tempVariable, &objectValue );
			return objectValue.u.halfword.lo;
		}
		Scr_Error( va( "%s is not an object", var_typename[type] ) );
	}
	Scr_Error( va( "%s is not an object", var_typename[value->type] ) );
	return 0;
}

/* ---- CopyArray  0x00471D20 ---- VERIFIED */
void CopyArray( unsigned short sourceId, unsigned short destId ) {
	Variable *childSlot = &scrVarIndirections[scrVarNodes[sourceId].nextSibling];
	unsigned short childId = childSlot->id;

	while ( childId != sourceId ) {
		VariableValueInternal  *childNode = &scrVarNodes[childId];
		int                     childType = GetVarType( childId );
		Variable *destSlot = &scrVarIndirections[GetVariableIndexInternal(destId, GetVariableName(childId))];
		unsigned short          destChild = destSlot->id;
		VariableValueInternal  *destNode = &scrVarNodes[destChild];

		destNode->status |= (unsigned int)childType;

		if ( childType != VAR_OBJECT ) {
			destNode->u = childNode->u;
			AddRefToValue( childType, childNode->u );
		} else {
			if ( GetVarType( VAR_OBJECTID(childNode) ) == VAR_ARRAY ) {
				VAR_OBJECTID(destNode) = Scr_AllocArray();
				CopyArray( VAR_OBJECTID(childNode), VAR_OBJECTID(destNode) );
			} else {
				VAR_OBJECTID(destNode) = VAR_OBJECTID(childNode);
				AddRefToObject( VAR_OBJECTID(childNode) );
			}
		}

		childSlot = &scrVarIndirections[childNode->nextSibling];
		childId = childSlot->id;
	}
}

/* ---- EvalArray  0x00472970 ---- VERIFIED */
void EvalArray( VariableValue *index, VariableValue *container ) {
	unsigned short  childId;
	unsigned short  stringValue;
	const char     *s;
	const float    *vectorValue;
	VariableValueInternal *arrayValue;
	char            c[2];

	/* Mac 1.3 shape: each failed index check raises and falls into the next case */
	switch ( container->type ) {
	case VAR_STRING:
		if ( index->type == VAR_INTEGER ) {
			if ( index->u.intValue >= 0 ) {
				stringValue = container->u.stringValue;
				s = SL_ConvertToString( stringValue );
				if ( (unsigned int)index->u.intValue < strlen( s ) ) {
					index->type = VAR_STRING;
					c[0] = s[index->u.intValue];
					c[1] = 0;
					index->u.stringValue = SL_GetStringOfLen( c, 0, 2, 14 );
					SL_RemoveRefToString( stringValue );
					return;
				}
			}
			Scr_Error( va( "string index %d out of range", index->u.intValue ) );
		}
		Scr_Error( va( "%s is not a string index", var_typename[index->type] ) );
	case VAR_VECTOR:
		if ( index->type == VAR_INTEGER ) {
			if ( index->u.uintValue < 3 ) {
				vectorValue = container->u.vectorValue;
				index->type = VAR_FLOAT;
				index->u.floatValue = vectorValue[index->u.intValue];
				RemoveRefToVector( vectorValue );
				return;
			}
			Scr_Error( va( "vector index %d out of range", index->u.intValue ) );
		}
		Scr_Error( va( "%s is not a vector index", var_typename[index->type] ) );
	case VAR_OBJECT:
		arrayValue = &scrVarNodes[container->u.halfword.lo];
		if ( VAR_TYPE( arrayValue ) != VAR_ARRAY ) {
			scrVarPub_error_index = 1;
			Scr_Error( va( "%s is not an array", var_typename[ VAR_TYPE( arrayValue ) ] ) );
		}

		switch ( index->type ) {
		case VAR_INTEGER:
			if ( IsValidArrayIndex( index->u.uintValue ) ) {
				childId = FindArrayVariable( container->u.halfword.lo, index->u.intValue );
				break;
			}
			Scr_Error( va( "array index %d out of range", index->u.intValue ) );
		case VAR_STRING:
			childId = FindVariable( container->u.halfword.lo, index->u.stringValue );
			SL_RemoveRefToString( index->u.stringValue );
			break;
		default:
			Scr_Error( va( "%s is not an array index", var_typename[index->type] ) );
			return;
		}
		if ( childId ) {
			GetVariableValue( childId, index );
			AddRefToValue( index->type, index->u );
			RemoveRefToObject( container->u.halfword.lo );
		} else {
			RemoveRefToObject( container->u.halfword.lo );
			index->type = VAR_UNDEFINED;
		}
		return;
	default:
		scrVarPub_error_index = 1;
		Scr_Error( va( "%s is not an array, string, or vector", var_typename[container->type] ) );
		return;
	}
}

/* Var_ResolveArrayObject -- the KEYVALUE unwrapping the three array functions
   share.  Retail (0x00472C2D, 0x00472F1C, 0x0047329D) hands GetEntityFieldValue
   the VM stack slot ABOVE the index, index + 1, as the scratch value: it sets
   scrVmPub_top = index and reads the result from index[1].  A C local here is
   wrong, not merely different: IncInParam refuses any top above scrVmPub_maxstack
   (0x0047C58D), and a C-stack local sits above the .bss stack whenever the loader
   puts the thread stack above the image -- "Internal script stack overflow" on
   the first self.field[i] a script evaluates.
   The whole union is handed back, as retail keeps it (a full dword local,
   0x00472EE1 / 0x00472F40): EvalArrayRef writes it back into node->u with
   only halfword.lo replaced. */
extern VariableValue *scrVmPub_top;
extern int scrVmPub_inparamcount;
static __forceinline int Var_ResolveArrayObject( VariableValueInternal *node, VariableUnion *arrayU,
								   VariableValue *index ) {
	int type = VAR_TYPE( node );

	*arrayU = node->u;

	while ( type != VAR_OBJECT ) {
		if (type != VAR_KEYVALUE) break;
		scrVmPub_top = index;
		index[1].type = VAR_UNDEFINED;
		( (int (*)( unsigned int, int, int ))scrImport_GetObjectField )( VAR_NAME(node), VAR_KVENTNUM(node), VAR_KVOFFSET(node) );
		scrVmPub_inparamcount = 0;
		*arrayU = index[1].u;
		type = index[1].type;
		RemoveRefToValue( type, index[1].u );
	}
	return type;
}

/* ---- Scr_EvalArrayIndex_m  0x00472BE0 ---- VERIFIED */
unsigned short Scr_EvalArrayIndex_m( unsigned short id, VariableValue *index ) {
	VariableValueInternal  *entryValue;
	VariableValueInternal  *arrayValue;
	VariableUnion           arrayU;
	unsigned short          handle;
	unsigned short          name;
	int                     type;

	entryValue = &scrVarNodes[id];
	arrayU = entryValue->u;
	type = VAR_TYPE( entryValue );
	while ( type != VAR_OBJECT ) {
		if ( type != VAR_KEYVALUE ) {
			scrVarPub_error_index = 1;
			Scr_Error( va( "%s is not an array", var_typename[type] ) );
			break;
		}
		GetEntityFieldValue__FUiiiP13VariableValue( VAR_NAME( entryValue ), VAR_KVENTNUM( entryValue ),
													 VAR_KVOFFSET( entryValue ), index + 1 );
		arrayU = index[1].u;
		type = index[1].type;
		RemoveRefToValue( type, arrayU );
	}

	arrayValue = &scrVarNodes[arrayU.halfword.lo];
	if ( VAR_TYPE( arrayValue ) != VAR_ARRAY ) {
		scrVarPub_error_index = 1;
		Scr_Error( va( "%s is not an array", var_typename[ VAR_TYPE( arrayValue ) ] ) );
	}

	if ( index->type == VAR_INTEGER ) {
		if ( IsValidArrayIndex( index->u.uintValue ) ) {
			handle = FindArrayVariableIndex( arrayU.halfword.lo, index->u.uintValue );
			if ( handle ) {
				return scrVarIndirections[handle].id;
			}
		} else {
			Scr_Error( va( "array index %d out of range", index->u.intValue ) );
		}
	} else if ( index->type == VAR_STRING ) {
		name = index->u.stringValue;
		handle = FindVariableIndexInternal( arrayU.halfword.lo, name );
		if ( handle ) {
			SL_RemoveRefToString( name );
			return scrVarIndirections[handle].id;
		}
	} else {
		Scr_Error( va( "%s is not an array index", var_typename[index->type] ) );
	}
	Scr_Error( "array index does not exist" );
	return 0;
}

/* ---- EvalArrayRef  0x00472EC0 ---- VERIFIED */
unsigned short EvalArrayRef( unsigned short id, VariableValue *index ) {
	VariableValueInternal  *entryValue;
	VariableValueInternal  *arrayValue;
	VariableValue           resolvedArray;
	unsigned short          source;
	unsigned short          handle;

	entryValue = &scrVarNodes[id];
	resolvedArray.u = entryValue->u;
	resolvedArray.type = VAR_TYPE( entryValue );
	for ( ;; ) {
		if ( resolvedArray.type == VAR_UNDEFINED ) {
			resolvedArray.u.halfword.lo = Scr_AllocArray();
			entryValue->status |= VAR_OBJECT;
			entryValue->u = resolvedArray.u;
			goto add_index;
		}
		if ( resolvedArray.type == VAR_OBJECT ) {
			break;
		}
		if ( resolvedArray.type != VAR_KEYVALUE ) {
			scrVarPub_error_index = 1;
			switch ( resolvedArray.type ) {
			case VAR_STRING:
				Scr_Error( "string characters cannot be individually changed" );
			case VAR_VECTOR:
				Scr_Error( "vector components cannot be individually changed" );
			default:
				Scr_Error( va( "%s is not an array", var_typename[resolvedArray.type] ) );
			}
			break;
		}
		GetEntityFieldValue__FUiiiP13VariableValue( VAR_NAME( entryValue ), VAR_KVENTNUM( entryValue ),
													 VAR_KVOFFSET( entryValue ), index + 1 );
		resolvedArray = index[1];
		RemoveRefToValue( resolvedArray.type, resolvedArray.u );
	}

	arrayValue = &scrVarNodes[resolvedArray.u.halfword.lo];
	if ( VAR_TYPE( arrayValue ) != VAR_ARRAY ) {
		scrVarPub_error_index = 1;
		Scr_Error( va( "%s is not an array", var_typename[ VAR_TYPE( arrayValue ) ] ) );
	}

	if ( VAR_REFCOUNT( arrayValue ) ) {
		source = resolvedArray.u.halfword.lo;
		RemoveRefToObject( source );
		resolvedArray.u.halfword.lo = Scr_AllocArray();
		CopyArray( source, resolvedArray.u.halfword.lo );
		entryValue->u = resolvedArray.u;
	}

add_index:
	if ( index->type == VAR_INTEGER ) {
		if ( IsValidArrayIndex( index->u.uintValue ) ) {
			return scrVarIndirections[ GetArrayVariableIndex( resolvedArray.u.halfword.lo, index->u.uintValue ) ].id;
		}
		Scr_Error( va( "array index %d out of range", index->u.intValue ) );
	}

	if ( index->type == VAR_STRING ) {
		handle = scrVarIndirections[ GetVariableIndexInternal( resolvedArray.u.halfword.lo, index->u.stringValue ) ].id;
		SL_RemoveRefToString( index->u.stringValue );
		return handle;
	}
	Scr_Error( va( "%s is not an array index", var_typename[index->type] ) );
	return 0;
}

/* ---- ClearArray  0x00473250 ---- VERIFIED */
void ClearArray( unsigned short id, VariableValue *index ) {
	VariableValueInternal  *entryValue;
	VariableValueInternal  *arrayValue;
	VariableUnion           arrayU;
	int                     type;

	entryValue = &scrVarNodes[id];
	arrayU = entryValue->u;
	type = VAR_TYPE( entryValue );
	while ( type != VAR_OBJECT ) {
		if ( type != VAR_KEYVALUE ) {
			scrVarPub_error_index = 1;
			Scr_Error( va( "%s is not an array", var_typename[type] ) );
			break;
		}
		GetEntityFieldValue__FUiiiP13VariableValue( VAR_NAME( entryValue ), VAR_KVENTNUM( entryValue ),
													 VAR_KVOFFSET( entryValue ), index + 1 );
		arrayU = index[1].u;
		type = index[1].type;
		RemoveRefToValue( type, arrayU );
	}

	arrayValue = &scrVarNodes[arrayU.halfword.lo];
	if ( VAR_TYPE( arrayValue ) != VAR_ARRAY ) {
		scrVarPub_error_index = 1;
		Scr_Error( va( "%s is not an array", var_typename[ VAR_TYPE( arrayValue ) ] ) );
	}

	if ( index->type == VAR_INTEGER ) {
		if ( IsValidArrayIndex( index->u.uintValue ) ) {
			SafeRemoveArrayVariable( arrayU.halfword.lo, index->u.uintValue );
			return;
		}
		Scr_Error( va( "array index %d out of range", index->u.intValue ) );
	}

	if ( index->type == VAR_STRING ) {
		SafeRemoveVariable( arrayU.halfword.lo, index->u.stringValue );
		SL_RemoveRefToString( index->u.stringValue );
	} else {
		Scr_Error( va( "%s is not an array index", var_typename[index->type] ) );
	}
}

/* ---- GetEmptyArray  0x004734F0 ---- VERIFIED */
void GetEmptyArray( VariableValue *value ) {
	value->type = VAR_OBJECT;
	value->u.halfword.lo = Scr_AllocArray();
}

/* ---- SetEmptyArray  0x00473530 ---- VERIFIED */
void SetEmptyArray( unsigned short id ) {
	VariableValueInternal *node = &scrVarNodes[id];

	node->status |= VAR_OBJECT;
	VAR_OBJECTID( node ) = Scr_AllocArray();
}

/* ---- Scr_SetClassMap  0x00472500 ---- VERIFIED */
void Scr_SetClassMap( scrClassMapEntry_t *classMap, unsigned int classCount ) {
	unsigned int i;

	scrVarPub_classMap = classMap;
	scrVarPub_classNum = classCount;

	for ( i = 0; i < classCount; i++ ) {
		VariableValueInternal  *node;
		unsigned short          child;

		child = scrVarIndirections[ GetVariableIndexInternal( scrVarPub_entId, i ) ].id;
		node  = &scrVarNodes[child];
		if ( VAR_TYPE( node ) == VAR_UNDEFINED ) {
			node->status |= VAR_OBJECT;
			VAR_OBJECTID( node ) = Scr_AllocArray();
		}

		child = scrVarIndirections[ GetVariableIndexInternal( scrVarPub_classId, i ) ].id;
		node  = &scrVarNodes[child];
		if ( VAR_TYPE( node ) == VAR_UNDEFINED ) {
			node->status |= VAR_OBJECT;
			VAR_OBJECTID( node ) = Scr_AllocArray();
		}

		classMap[i].id = VAR_OBJECTID( node );
	}
}

/* ---- Scr_RemoveClassMap  0x00472620 ---- VERIFIED */
void Scr_RemoveClassMap( void ) {
	unsigned int i;

	if ( !scr_inited ) {
		return;
	}

	for ( i = 0; i < scrVarPub_classNum; i++ ) {
		unsigned short handle;

		handle = FindVariableIndexInternal( scrVarPub_classId, i );
		if ( handle ) {
			Variable *slot = &scrVarIndirections[handle];
			VariableValueInternal *child = &scrVarNodes[slot->id];

			MakeVariableExternal( slot,
				&scrVarNodes[ scrVarPub_classId ] );
			FreeValueInternal( child );
		}

		handle = FindVariableIndexInternal( scrVarPub_entId, i );
		if ( handle ) {
			Variable *slot = &scrVarIndirections[handle];
			VariableValueInternal *child = &scrVarNodes[slot->id];

			MakeVariableExternal( slot,
				&scrVarNodes[ scrVarPub_entId ] );
			FreeValueInternal( child );
		}
	}
}

/* ---- Scr_AddClassField  0x004726F0 ---- VERIFIED */
void Scr_AddClassField( unsigned short classId, const char *name, unsigned short offset ) {
	unsigned short          canonical;
	unsigned short          handle;
	unsigned short          childId;
	VariableValueInternal  *node;

	canonical = scrString_canonicalMap[ SL_FindStringOfLen( name, strlen( name ) + 1 ) ];
	if ( canonical ) {
		childId = scrVarIndirections[
			GetVariableIndexInternal( classId, GetInternalVariableIndex( canonical ) ) ].id;
		node = &scrVarNodes[childId];
		node->status = ( node->status & ~VAR_STATUS_TYPE_MASK ) | VAR_INTEGER;
		VAR_KVOFFSET( node ) = offset;
	}

	handle = SL_GetStringOfLen( name, 0, strlen( name ) + 1, SCR_STRING_MT_TYPE_FIELD );
	childId = scrVarIndirections[ GetVariableIndexInternal( classId, handle ) ].id;
	SL_RemoveRefToString( handle );

	node = &scrVarNodes[childId];
	VAR_KVOFFSET( node ) = offset;
	node->status = ( node->status & ~VAR_STATUS_TYPE_MASK ) | VAR_INTEGER;
}

/* ---- Scr_GetOffset  0x00472800 ---- VERIFIED */
int Scr_GetOffset( unsigned short classId, const char *name ) {
	unsigned short handle = SL_ConvertFromString( name );
	unsigned short childId = FindVariable( classId, handle );

	if ( childId ) {
		return VAR_KVOFFSET( &scrVarNodes[childId] );
	}
	return -1;
}

/* ---- FindEntityId  0x00472850 ---- VERIFIED */
unsigned short FindEntityId( int entnum, int classnum ) {
	unsigned short classRoot;
	unsigned short childId;

	classRoot = VAR_OBJECTID( &scrVarNodes[
		scrVarIndirections[ FindVariableIndexInternal( scrVarPub_entId, classnum ) ].id ] );

	childId = FindArrayVariable( classRoot, entnum );
	if ( !childId ) {
		return 0;
	}
	return VAR_OBJECTID( &scrVarNodes[childId] );
}

/* ---- Scr_GetEntityId  0x004728B0 ---- VERIFIED */
unsigned short Scr_GetEntityId( int entnum, int classnum ) {
	unsigned short          classRoot;
	unsigned short          childId;
	VariableValueInternal  *node;
	unsigned short object;

	classRoot = VAR_OBJECTID( &scrVarNodes[
		scrVarIndirections[ FindVariableIndexInternal( scrVarPub_entId, classnum ) ].id ] );


	childId = GetArrayVariable( classRoot, entnum );
	node = &scrVarNodes[childId];

	if ( VAR_TYPE( node ) != VAR_UNDEFINED ) {
		return VAR_OBJECTID( node );
	}

	object = AllocEntity( classnum, (unsigned short)entnum );
	/* re-derived after the call: retail keeps childId*3 live across it, not the pointer */
	node = &scrVarNodes[childId];
	node->status |= VAR_OBJECT;
	VAR_OBJECTID(node) = object;
	return object;

}

/* ---- Scr_FreeEntityNum  0x00472440 ---- VERIFIED */
void Scr_FreeEntityNum( int entnum, int classnum ) {
	unsigned short          classRoot;
	unsigned short          childId;
	unsigned short          entityId;
	VariableValueInternal  *entry;

	if ( !scr_inited ) {
		return;
	}

	classRoot = VAR_OBJECTID( &scrVarNodes[
		scrVarIndirections[ FindVariableIndexInternal( scrVarPub_entId, classnum ) ].id ] );

	childId = FindArrayVariable( classRoot, entnum );
	if ( !childId ) {
		return;
	}

	entityId = VAR_OBJECTID( &scrVarNodes[childId] );
	entry = &scrVarNodes[entityId];
	entry->status = ( entry->status & ~VAR_STATUS_TYPE_MASK ) | VAR_DEADENTITY;

	AddRefToObject( entityId );
	VM_TerminateNotifyList__FUs( entityId );
	ClearObjectInternal( entityId );
	RemoveRefToObject( entityId );

	RemoveArrayVariable( classRoot, entnum );
}

/* ---- CopyEntity  0x00473590 ---- VERIFIED */
void CopyEntity( unsigned short sourceId, unsigned short destId ) {
	unsigned short childId;

	for ( childId = FindNextSibling( sourceId ); childId; childId = FindNextSibling( childId ) ) {
		VariableValueInternal *childNode = &scrVarNodes[childId];

		if ( VAR_NAME( childNode ) != VAR_NAME_OBJECT_LIMIT ) {
			unsigned short          destChild;
			VariableValueInternal  *destNode;
			unsigned int            status;

			destChild = scrVarIndirections[
				GetVariableIndexInternal( destId, VAR_NAME( childNode ) ) ].id;
			destNode = &scrVarNodes[destChild];

			status = childNode->status & ~VAR_STATUS_STAT_MASK;
			destNode->status |= status;
			{ VariableUnion value = childNode->u;
			  destNode->u = value;
			  AddRefToValue((int)(status & VAR_STATUS_TYPE_MASK), value); }
		}
	}
}

/* ---- Scr_CopyEntityNum  0x00473660 ---- VERIFIED */
void Scr_CopyEntityNum( int fromEntnum, int toEntnum, int classnum ) {
	unsigned short sourceId = FindEntityId( fromEntnum, classnum );

	if ( !sourceId ) {
		return;
	}
	if ( !FindNextSibling( sourceId ) ) {
		return;
	}
	CopyEntity( sourceId, Scr_GetEntityId( toEntnum, classnum ) );
}

void Var_Init__Fv( void ) { Var_Init(); }
void InitVariables__Fv( void ) { InitVariables(); }

unsigned short FindVariableIndexInternal__FUsUi( unsigned short p, unsigned int n ) {
	return FindVariableIndexInternal( p, n );
}
unsigned short GetVariableIndexInternal__FUsUi( unsigned short p, unsigned int n ) {
	return GetVariableIndexInternal( p, n );
}
void MakeVariableExternal__FP8VariableP21VariableValueInternal(
		Variable *slot, VariableValueInternal *parent ) {
	MakeVariableExternal( slot, parent );
}
void ClearObjectInternal__FUs( unsigned short id ) { ClearObjectInternal( id ); }
void ClearObject__FUs( unsigned short id ) { ClearObject( id ); }
void ClearThreadNotifyName__FUs( unsigned short id ) { ClearThreadNotifyName( id ); }
void SetThreadNotifyName__FUsUs( unsigned short id, unsigned short name ) {
	SetThreadNotifyName( id, name );
}
void KillThread__FUs( unsigned short id ) { KillThread( id ); }
VariableValueInternal *AllocVariable__Fv( void ) { return AllocVariable(); }
unsigned short AllocValue__Fv( void ) { return AllocValue(); }
unsigned short AllocObject__Fv( void ) { return AllocObject(); }
unsigned short AllocThread__FUs( unsigned short self ) { return AllocThread( self ); }
unsigned short AllocEntity__FiUs( int c, unsigned short e ) { return AllocEntity( c, e ); }
void FreeVariable__FUs( unsigned short id ) { FreeVariable( id ); }
void FreeValue__FP21VariableValueInternal( VariableValueInternal *n ) { FreeValueInternal( n ); }
void FreeValue__FUs( unsigned short id ) { FreeValue( id ); }
void AddRefToObject__FUs( unsigned short id ) { AddRefToObject( id ); }
void RemoveRefToObject__FUs( unsigned short id ) { RemoveRefToObject( id ); }
void AddRefToVector__FPCf( const float *v ) { AddRefToVector( v ); }
void RemoveRefToVector__FPCf( const float *v ) { RemoveRefToVector( v ); }
void AddRefToValue__Fi13VariableUnion( int t, VariableUnion u ) { AddRefToValue( t, u ); }
void RemoveRefToValue__Fi13VariableUnion( int t, VariableUnion u ) { RemoveRefToValue( t, u ); }
unsigned short FindVariable__FUsUi( unsigned short p, unsigned int n ) {
	return FindVariable( p, n );
}
unsigned short GetVariable__FUsUi( unsigned short p, unsigned int n ) {
	return GetVariable( p, n );
}
unsigned short FindObjectVariable__FUsUs( unsigned short p, unsigned short c ) {
	return FindObjectVariable( p, c );
}
unsigned short GetObjectVariable__FUsUs( unsigned short p, unsigned short c ) {
	return GetObjectVariable( p, c );
}
unsigned short FindArrayVariable__FUsi( unsigned short p, int i ) {
	return FindArrayVariable( p, i );
}
unsigned short GetArrayVariable__FUsi( unsigned short p, int i ) {
	return GetArrayVariable( p, i );
}
unsigned short GetArrayVariable__FUsUi( unsigned short p, unsigned int i ) {
	return GetArrayVariable( p, (int)i );
}
unsigned short GetVariableField__FUsUs( unsigned short p, unsigned short n ) {
	return GetVariableField( p, n );
}
void ClearVariableField__FUsUs( unsigned short p, unsigned short n ) {
	ClearVariableField( p, n );
}
void RemoveVariable__FUsUi( unsigned short p, unsigned int n ) { RemoveVariable( p, n ); }
void SafeRemoveVariable__FUsUi( unsigned short p, unsigned int n ) { SafeRemoveVariable( p, n ); }
void RemoveArrayVariable__FUsUi( unsigned short p, unsigned int n ) {
	RemoveArrayVariable( p, n );
}
void SafeRemoveArrayVariable__FUsUi( unsigned short p, unsigned int n ) {
	SafeRemoveArrayVariable( p, n );
}
void RemoveObjectVariable__FUsUs( unsigned short p, unsigned short c ) {
	RemoveObjectVariable( p, c );
}
void SetVariableValue__FUsP13VariableValue( unsigned short id, VariableValue *v ) {
	SetVariableValue( id, v );
}
void SetNewVariableValue__FUsP13VariableValue( unsigned short id, VariableValue *v ) {
	SetNewVariableValue( id, v );
}
void SetVariableFieldValue__FUsP13VariableValue( unsigned short id, VariableValue *v ) {
	SetVariableFieldValue( id, v );
}
void GetVariableValue__FUsP13VariableValue( unsigned short id, VariableValue *v ) {
	GetVariableValue( id, v );
}
void GetVariableFieldValue__FUsP13VariableValue( unsigned short id, VariableValue *v ) {
	GetVariableFieldValue( id, v );
}
void ClearVariableValue__FUs( unsigned short id ) { ClearVariableValue( id ); }
VariableValue *GetVariableValueAddress__FUs( unsigned short id ) {
	return GetVariableValueAddress( id );
}
void GetSizeValue__FP13VariableValue( VariableValue *v ) { GetSizeValue( v ); }
unsigned int GetArraySize__FUs( unsigned short id ) { return GetArraySize( id ); }
unsigned short FindNextSibling__FUs( unsigned short id ) { return FindNextSibling( id ); }
unsigned int GetVariableName__FUs( unsigned short id ) { return GetVariableName( id ); }
unsigned short GetVariableKeyObject__FUs( unsigned short id ) {
	return GetVariableKeyObject( id );
}
unsigned int GetEntityType__FUs( unsigned short id ) { return GetEntityType( id ); }
unsigned short GetThreadNotifyName__FUs( unsigned short id ) {
	return GetThreadNotifyName( id );
}
unsigned short GetSelf__FUs( unsigned short id ) { return GetSelf( id ); }
unsigned int GetEntnum__FUs( unsigned short id ) { return GetEntnum( id ); }
unsigned short GetObject__FUs( unsigned short id ) { return GetObject( id ); }
unsigned short GetArray__FUs( unsigned short id ) { return GetArray( id ); }
unsigned short FindObject__FUs( unsigned short id ) { return FindObject( id ); }
qboolean IsFieldObject__FUs( unsigned short id ) { return IsFieldObject( id ); }
int GetVarType__FUs( unsigned short id ) { return GetVarType( id ); }
qboolean IsValidArrayIndex__FUi( unsigned int i ) { return IsValidArrayIndex( i ); }
unsigned int GetInternalVariableIndex__FUi( unsigned int i ) {
	return GetInternalVariableIndex( i );
}
unsigned short FindArrayVariableIndex__FUsUi( unsigned short p, unsigned int i ) {
	return FindArrayVariableIndex( p, i );
}
unsigned short GetArrayVariableIndex__FUsUi( unsigned short p, unsigned int i ) {
	return GetArrayVariableIndex( p, i );
}
unsigned short CastFieldObject__FP13VariableValue( VariableValue *v ) {
	return CastFieldObject( v );
}
void CopyArray__FUsUs( unsigned short s, unsigned short d ) { CopyArray( s, d ); }
void CopyEntity__FUsUs( unsigned short s, unsigned short d ) { CopyEntity( s, d ); }
void EvalArray__FP13VariableValueP13VariableValue( VariableValue *i, VariableValue *c ) {
	EvalArray( i, c );
}
unsigned short EvalArrayRef__FUsP13VariableValue( unsigned short id, VariableValue *i ) {
	return EvalArrayRef( id, i );
}
void ClearArray__FUsP13VariableValue( unsigned short id, VariableValue *i ) {
	ClearArray( id, i );
}
void GetEmptyArray__FP13VariableValue( VariableValue *v ) { GetEmptyArray( v ); }
void SetEmptyArray__FUs( unsigned short id ) { SetEmptyArray( id ); }
float *AllocVector__Fv( void ) { return AllocVector(); }
VariableUnion AllocVector__FPCf( const float *v ) { return AllocVectorValue( v ); }
unsigned short FindEntityId__Fii( int e, int c ) { return FindEntityId( e, c ); }

#define SCR_SAVE_IDMAP_SIZE     ( VARIABLELIST_SIZE * (int)sizeof( unsigned short ) )

/* the import table declares these unprototyped; spell the call types out for C++ */
#define SCR_LOAD_READ           ( (char *(*)( int ))scrImport_LoadRead )

/* ---- WriteByte__FUc  0x004736D0 ---- VERIFIED */
void WriteByte( unsigned char value ) {
	*(unsigned char *)TempMalloc( 1 ) = value;
}

/* ---- ReadByte__Fv  0x00473700 ---- VERIFIED */
char ReadByte( void ) {
	return *(unsigned char *)scrSave_readPos++;
}

/* ---- WriteShort__FUs  0x00473710 ---- VERIFIED */
void WriteShort( unsigned short value ) {
	*(unsigned short *)TempMalloc( 2 ) = value;
}

/* ---- ReadShort__Fv  0x00473740 ---- VERIFIED */
__int16 ReadShort( void ) {
	__int16 value = *(unsigned short *)scrSave_readPos;

	scrSave_readPos += 2;
	return value;
}

/* ---- WriteString  0x00473760 ---- VERIFIED */
void WriteString( unsigned short id ) {
	const char *text = SL_ConvertToString(id);
	strcpy((char *)TempMalloc((int)strlen(text)+1),text);
}

void WriteString__FUs( unsigned short id ) { WriteString( id ); }

/* ---- SafeWriteString__FUs  0x004737C0 ---- VERIFIED */
void SafeWriteString( unsigned short id ) {
	if ( !id ) {
		WriteByte( 0 );
		return;
	}
	WriteByte( 1 );
	WriteString( id );
}

/* ---- ReadString__Fv  0x004737F0 ---- VERIFIED */
__int16 ReadString( void ) {
	unsigned int  len = strlen( (const char *)scrSave_readPos ) + 1;
	__int16       handle;

	handle = SL_GetStringOfLen( (char *)scrSave_readPos, 0, len, SCR_STRING_MT_TYPE_TEMP );
	scrSave_readPos += len;
	return handle;
}

/* ---- SafeReadString__Fv  0x00473830 ---- VERIFIED */
__int16 SafeReadString( void ) {
	/* a named local: retail zeroes it with xor eax,eax (`return 0` gives xor ax,ax) */
	__int16 string;

	if ( ReadByte() ) {
		string = ReadString();
	} else {
		string = 0;
	}
	return string;
}

/* ---- WriteFloat__Ff  0x00473880 ---- VERIFIED */
void WriteFloat( float value ) {
	*(float *)TempMalloc( 4 ) = value;
}

/* ---- ReadFloat__Fv  0x004738B0 ---- VERIFIED */
float ReadFloat( void ) {
	float value = *(float *)scrSave_readPos;

	scrSave_readPos += 4;
	return value;
}

/* ---- WriteVector__FPCf  0x004738C0 ---- VERIFIED */
void WriteVector( const float *v ) {
	WriteFloat(v[0]);
	WriteFloat(v[1]);
	WriteFloat(v[2]);
}

/* ---- ReadVector__Fv  0x00473930 ---- VERIFIED */
float *ReadVector( void ) {
	float value[3];
	value[0] = (float)ReadFloat();
	value[1] = (float)ReadFloat();
	value[2] = (float)ReadFloat();
	return (float *)AllocVectorValue(value).vectorValue;
}

/* ---- WriteInt__Fi  0x00473990 ---- VERIFIED */
void WriteInt( int value ) {
	*(int *)TempMalloc( 4 ) = value;
}

/* ---- ReadInt__Fv  0x004739C0 ---- VERIFIED */
int ReadInt( void ) {
	int value = *(unsigned int *)scrSave_readPos;

	scrSave_readPos += 4;
	return value;
}

/* ---- WriteCodepos__FPCc  0x004739E0 ---- VERIFIED */
int *__cdecl WriteCodepos( int codePos ) {
	int  offset;
	int *dest;

	offset = codePos ? codePos - scrVarPub_programBuffer : -1;
	dest = (int *)TempMalloc( 4 );
	*dest = offset;
	return dest;
}

/* ---- ReadCodepos__Fv  0x00473A20 ---- VERIFIED */
int ReadCodepos( void ) {
	int offset = *(int *)scrSave_readPos;

	scrSave_readPos += 4;
	if ( offset >= 0 ) {
		return scrVarPub_programBuffer + offset;
	}
	return 0;
}

/* ---- WriteId__FUs  0x00473A50 ---- VERIFIED */
void WriteId( unsigned short id ) {
	WriteShort( scrSave_idToSaveId[id] );
}

/* ---- ReadId  0x00473A80 ---- VERIFIED */
unsigned short ReadId( void ) {
	unsigned short saveId = *(unsigned short *)scrSave_readPos;
	unsigned short id;

	scrSave_readPos += 2;
	id = scrSave_saveIdToId[saveId];
	AddRefToObject( id );
	return id;
}

unsigned short ReadId__Fv( void ) { return ReadId(); }

/* ---- WriteBuffer__FPci  0x00473AB0 ---- VERIFIED */
void WriteBuffer( int len, const void *buf ) {
	char *dest;

	dest = (char *)TempMalloc( len );
	Com_Memcpy( dest, buf, len );
}

/* ---- ReadBuffer  0x00473AE0 ---- VERIFIED */
void ReadBuffer( char *buf, int len ) {
	Com_Memcpy( buf, scrSave_readPos, len );
	scrSave_readPos += len;
}

void ReadBuffer__FPci( char *buf, int len ) { ReadBuffer( buf, len ); }

/* ---- Scr_ConvertThreadToSave  0x00473B00 ---- VERIFIED */
__int16 __cdecl Scr_ConvertThreadToSave( unsigned __int16 id ) {
	if ( !id ) {
		return 0;
	}
	AddSaveObject( id );
	return scrSave_idToSaveId[id];
}

/* ---- Scr_ConvertThreadFromLoad  0x00473B30 ---- VERIFIED
 * retail reads the argument slot as a dword and tests only its low half. */
unsigned short Scr_ConvertThreadFromLoad( unsigned int handle ) {
	unsigned short saveId = (unsigned short)handle;
	unsigned short id;

	if ( !saveId ) {
		return 0;
	}
	id = scrSave_saveIdToId[saveId];
	AddRefToObject( id );
	return id;
}

/* ---- WriteStack__FPC19VariableStackBuffer  0x00473B60 ---- VERIFIED */
void WriteStack( const VariableStackBuffer *buf ) {
	unsigned short count = buf->size;
	const char *entry;
	int remaining;
	WriteShort(count);
	WriteInt((int)buf->pos);
	WriteCodepos((int)buf->codePos);
	WriteId(buf->objectId);
	entry = (const char *)buf + SCR_STACKBUFFER_HEADER;
	if (!count) return;
	remaining = count;
	do {
		unsigned char type = (unsigned char)*entry++;
		VariableUnion value = *(const VariableUnion *)entry;
		entry += sizeof(VariableUnion);
		DoSaveEntryInternal(type,value);
	} while (--remaining);
}

/* ---- ReadStack  0x00473C30 ---- VERIFIED */
VariableStackBuffer *ReadStack( void ) {
	VariableStackBuffer *buf;
	unsigned short       count;
	int                  codePos;
	char                *entry;
	int                  i;

	count = *(unsigned short *)scrSave_readPos;
	scrSave_readPos += 2;

	i = count;
	buf = (VariableStackBuffer *)MT_Alloc(
			SCR_STACKENTRY_SIZE * i + SCR_STACKBUFFER_HEADER, 1 );
	buf->size = count;

	buf->pos = *(const char **)scrSave_readPos;
	scrSave_readPos += 4;

	codePos = *(const int *)scrSave_readPos;
	scrSave_readPos += 4;
	buf->codePos = codePos >= 0 ? (const char *)(scrVarPub_programBuffer + codePos) : NULL;

	buf->objectId = ReadId();

	entry = (char *)buf + SCR_STACKBUFFER_HEADER;
	if (count) do {
		VariableValue value;

		DoLoadEntryInternal( &value );
		*entry++ = (char)value.type;
		*(VariableUnion *)entry = value.u;
		entry += sizeof(VariableUnion);
	} while (--i);
	return buf;
}

/* ---- AddSaveStack__FPC19VariableStackBuffer  0x00473CF0 ---- VERIFIED */
void AddSaveStack( const VariableStackBuffer *buf ) {
	const char *entry = (const char *)buf;
	unsigned short count;
	int remaining;
	AddSaveObject(((const VariableStackBuffer *)entry)->objectId);
	count = ((const VariableStackBuffer *)entry)->size;
	entry += SCR_STACKBUFFER_HEADER;
	if (!count) return;
	remaining = count;
	do {
		unsigned char type = (unsigned char)*entry++;
		VariableUnion value = *(const VariableUnion *)entry;
		entry += sizeof(VariableUnion);
		AddSaveEntry(type,value);
	} while (--remaining);
}

/* ---- AddSaveEntry__FUc13VariableUnion  0x00473D40 ---- VERIFIED */
void AddSaveEntry( unsigned char type, VariableUnion u ) {
	switch ( type ) {
	case VAR_OBJECT:
		AddSaveObject( u.halfword.lo );
		break;
	case VAR_STACK:
		AddSaveStack( (const VariableStackBuffer *)u.pointerValue );
		break;
	}
}

/* ---- AddSaveEntry  0x00473D60 ---- VERIFIED */
void AddSaveEntry__FP21VariableValueInternal( VariableValueInternal *node ) {
	AddSaveEntry( (unsigned char)VAR_TYPE( node ), node->u );
}

/* ---- Scr_GetEntryUsage  0x00473D90 ---- VERIFIED
   Retail returns the quotient unrounded in st0 (fild / fadd 1.0f / fdivp, no
   fstp; FPU at _PC_53). The original float API preserves that x87 return
   precision in VC7; single-precision literals select the retail DWORD operands. */
float Scr_GetEntryUsage( unsigned char type, VariableUnion u ) {
	if (type == VAR_OBJECT) {
		VariableValueInternal *node = &scrVarNodes[u.halfword.lo];
		if (VAR_TYPE(node) == VAR_ARRAY) {
			float usage = Scr_GetObjectUsage(u.halfword.lo);
			return usage / ((float)VAR_REFCOUNT(node) + 1.0f);
		}
	}
	return 0.0f;
}

float Scr_GetEntryUsage__FUc13VariableUnion( unsigned char type, VariableUnion u ) {
	return Scr_GetEntryUsage( type, u );
}

/* ---- Scr_GetEntryUsage  0x00473DE0 ---- VERIFIED
   Result stays in st0 (fadd 1.0f, no fstp).  Retail has no callers:
   Scr_GetObjectUsage inlines it with its own association; kept for address
   fidelity only. */
float Scr_GetEntryUsage__FP21VariableValueInternal( VariableValueInternal *node ) {
	return Scr_GetEntryUsage( (unsigned char)VAR_TYPE( node ), node->u ) + 1.0f;
}

/* ---- DoSaveEntryInternal  0x00473E00 ---- VERIFIED */
void DoSaveEntryInternal( unsigned char type, VariableUnion u ) {
	WriteByte( (char)type );

	switch ( type & VAR_STATUS_TYPE_MASK ) {
	case VAR_STRING:
	case VAR_ISTRING:
		WriteString( u.stringValue );
		break;
	case VAR_VECTOR:
		WriteVector(u.vectorValue);
		break;
	case VAR_FLOAT:
		WriteFloat( u.floatValue );
		break;
	case VAR_INTEGER:
		WriteInt( u.intValue );
		break;
	case VAR_ANIMATION:
		/* own case body: retail keeps a second, unmerged WriteInt call */
		WriteInt( (int)u.uintValue );
		break;
	case VAR_CODEPOS:
	case VAR_FUNCTION:
		WriteCodepos( (int)u.codePosValue );
		break;
	case VAR_OBJECT:
		WriteId( u.halfword.lo );
		break;
	case VAR_STACK:
		WriteStack( (const VariableStackBuffer *)u.pointerValue );
		break;
	default:
		break;
	}
}

/* ---- DoSaveEntry__FP13VariableValueUib  0x00473ED0 ---- VERIFIED */
void DoSaveEntry( VariableValue *value, unsigned int name, char bIntern ) {
	DoSaveEntryInternal( (unsigned char)value->type, value->u );

	if ( bIntern && name < VAR_NAME_OBJECT_LIMIT ) {
		if ( name < VAR_NAME_OBJECT_BASE ) {
			WriteByte( 2 );
			WriteString( (unsigned short)name );
		} else {
			WriteByte( 3 );
			WriteId( (unsigned short)name );
		}
		return;
	}

	if ( name < VAR_NAME_OBJECT_BASE ) {
		WriteByte( 0 );
		WriteShort( (unsigned short)name );
	} else {
		WriteByte( 1 );
		WriteInt( (int)name );
	}
}

/* ---- DoLoadEntryInternal  0x00473F80 ---- VERIFIED */
void DoLoadEntryInternal( VariableValue *value ) {
	unsigned char type = (unsigned char)ReadByte();

	value->type = type;

	switch ( type & VAR_STATUS_TYPE_MASK ) {
	case VAR_STRING:
	case VAR_ISTRING:
		value->u.stringValue = (unsigned short)ReadString();
		break;
	case VAR_VECTOR:
		value->u.vectorValue = (const float *)ReadVector();
		break;
	case VAR_FLOAT:
		value->u.floatValue = ReadFloat();
		break;
	case VAR_INTEGER:
		value->u.intValue = ReadInt();
		break;
	case VAR_ANIMATION:
		value->u.intValue = ReadInt();
		break;
	case VAR_CODEPOS:
	case VAR_FUNCTION:
		value->u.codePosValue = (const char *)ReadCodepos();
		break;
	case VAR_OBJECT:
		value->u.halfword.lo = ReadId();
		break;
	case VAR_STACK:
		value->u.pointerValue = ReadStack();
		break;
	default:
		break;
	}
}

void DoLoadEntryInternal__FP13VariableValue( VariableValue *value ) {
	DoLoadEntryInternal( value );
}

/* ---- DoLoadEntry__FP13VariableValue  0x00474020 ---- VERIFIED */
unsigned int DoLoadEntry( VariableValue *value ) {
	unsigned char   tag;
	unsigned int    name;

	DoLoadEntryInternal( value );

	tag = (unsigned char)*scrSave_readPos;
	scrSave_readPos += 1;

	switch ( tag ) {
	case 0:
		name = (unsigned short)ReadShort();
		break;
	case 1:
		name = *(unsigned int *)scrSave_readPos;
		scrSave_readPos += 4;
		break;
	case 2:
		name = (unsigned short)ReadString();
		break;
	case 3:
		name = (unsigned short)ReadId() + VAR_NAME_OBJECT_BASE;   /* movzx, 0x00474071 */
		break;
	default:
		name = 0;
		break;
	}
	return name;
}

unsigned int DoLoadEntry__FP13VariableValue( VariableValue *value ) {
	return DoLoadEntry( value );
}

/* ---- AddSaveObject  0x00474090 ---- VERIFIED */
void AddSaveObject( unsigned short id ) {
	unsigned short *saveMap = scrSave_idToSaveId;
	while (!saveMap[id]) {
		VariableValueInternal *node;
		int parentType;
		unsigned char isArray;
		unsigned short child;
		++scrSave_numSaveObjects;
		saveMap[id] = scrSave_numSaveObjects;
		scrSave_saveIdToId[scrSave_numSaveObjects] = id;
		node = &scrVarNodes[id];
		parentType = VAR_TYPE(node);
		isArray = parentType == VAR_ARRAY;
		for ( child = FindNextSibling( id ); child; child = FindNextSibling( child ) ) {
			VariableValueInternal *entry = &scrVarNodes[child];
			if (isArray) {
				unsigned int name = VAR_NAME(entry);
				if (name >= VAR_NAME_OBJECT_BASE && name < VAR_NAME_OBJECT_LIMIT) AddSaveObject((unsigned short)name);
			}
			AddSaveEntry((unsigned char)VAR_TYPE(entry),entry->u);
		}
		saveMap = scrSave_idToSaveId;
		if (parentType != VAR_THREAD) return;
		id = VAR_SELF(node);
	}
}

void AddSaveObject__FUs( unsigned short id ) { AddSaveObject( id ); }

/* ---- Scr_GetEndonUsage  0x004741D0 ---- VERIFIED */
float Scr_GetEndonUsage( unsigned short id ) {
	unsigned short handle;
	unsigned short node;

	handle = FindVariableIndexInternal( scrVarPub_pauseArrayId,
										id + VAR_NAME_OBJECT_BASE );
	node = scrVarIndirections[handle].id;
	if ( node ) {
		return Scr_GetObjectUsage( VAR_OBJECTID( &scrVarNodes[node] ) );
	}
	return 0.0f;
}

float Scr_GetEndonUsage__FUs( unsigned short id ) { return Scr_GetEndonUsage( id ); }

float Scr_GetEntryUsage__FP21VariableValueInternal( VariableValueInternal *node );

/* ---- Scr_GetObjectUsage  0x00474220 ---- VERIFIED */
float Scr_GetObjectUsage( unsigned short id ) {
	float           usage;
	unsigned short  child;

	usage = 1.0f;
	for ( child = FindNextSibling( id ); child; child = FindNextSibling( child ) ) {
		usage += Scr_GetEntryUsage__FP21VariableValueInternal( &scrVarNodes[child] );
	}
	return usage;
}

float Scr_GetObjectUsage__FUs( unsigned short id ) { return Scr_GetObjectUsage( id ); }

/* ---- Scr_GetThreadUsage  0x00474310 ---- VERIFIED */
float Scr_GetThreadUsage( const VariableStackBuffer *buf, float *endonUsage ) {
	int             size;
	const char     *pos;
	float           usage;

	size  = buf->size;
	pos   = (const char *)buf + SCR_STACKBUFFER_HEADER + SCR_STACKENTRY_SIZE * size;
	usage = Scr_GetObjectUsage( buf->objectId );
	*endonUsage = Scr_GetEndonUsage( buf->objectId );

	while ( size ) {
		unsigned char   type;
		VariableUnion   u;

		pos -= 4;
		u = *(const VariableUnion *)pos;
		pos--;
		type = (unsigned char)*pos;
		size--;
		if ( type != VAR_CODEPOS ) {
			usage += Scr_GetEntryUsage( type, u );
		} else {
			pos -= 4;
			u = *(const VariableUnion *)pos;
			pos--;
			size--;
			usage += Scr_GetObjectUsage( u.halfword.lo );
			*endonUsage += Scr_GetEndonUsage( u.halfword.lo );
		}
	}
	return usage;
}

float Scr_GetThreadUsage__FPC19VariableStackBufferPf( const VariableStackBuffer *buf,
													  float *endonUsage ) {
	return Scr_GetThreadUsage( buf, endonUsage );
}

/* ---- DoSaveObjectInfo  0x00474470 ---- VERIFIED */
void DoSaveObjectInfo( unsigned short id ) {
	VariableValueInternal  *node = &scrVarNodes[id];
	unsigned char           status;
	unsigned char           type;
	unsigned char           bArray;
	unsigned short          count;
	unsigned short          child;

	status = (unsigned char)( node->status & 0x9F );
	WriteByte( (char)status );

	type = status & VAR_STATUS_TYPE_MASK;
	if ( type == VAR_THREAD ) {
		WriteId( VAR_SELF( node ) );
		SafeWriteString( (unsigned short)VAR_NAME( node ) );
	} else if ( type == VAR_ENTITY || type == VAR_DEADENTITY ) {
		WriteShort( (short)VAR_ENTNUM( node ) );
		WriteShort( (short)VAR_NAME( node ) );
	}

	bArray = (char)( VAR_TYPE( node ) == VAR_ARRAY );

	count = 0;
	for (child = FindNextSibling(id); child; child = FindNextSibling(child)) {
		count++;
	}
	WriteShort( (short)count );

	for (child = FindNextSibling(id); child; child = FindNextSibling(child)) {
		VariableValueInternal  *entry = &scrVarNodes[child];
		VariableValue           value;

		value.type = (unsigned char)( entry->status & 0x9F );
		value.u    = entry->u;
		DoSaveEntry( &value, VAR_NAME( entry ), bArray );
	}
}

void DoSaveObjectInfo__FUs( unsigned short id ) { DoSaveObjectInfo( id ); }

/* ---- DoLoadObjectInfo  0x004746C0 ---- VERIFIED */
void DoLoadObjectInfo( unsigned short id ) {
	VariableValueInternal  *node = &scrVarNodes[id];
	int                     status;
	unsigned char           type;
	unsigned char           bArray;
	unsigned short          count;
	int                     i;

	type = *(unsigned char *)scrSave_readPos;
	scrSave_readPos += 1;

	status = ( node->status & ~VAR_STATUS_TYPE_MASK ) | type;
	node->status = status;
	type &= VAR_STATUS_TYPE_MASK;
	if ( type == VAR_THREAD ) {
		unsigned short saveId;
		unsigned short self;

		saveId = *(unsigned short *)scrSave_readPos;
		scrSave_readPos += 2;
		self = scrSave_saveIdToId[saveId];
		AddRefToObject( self );
		VAR_SELF( node ) = self;

		node->status |= (unsigned int)(unsigned short)SafeReadString()
						<< VAR_STATUS_NAME_SHIFT;
	} else if ( type == VAR_ENTITY || type == VAR_DEADENTITY ) {
		VAR_ENTNUM( node ) = ReadShort();
		node->status = status | (unsigned int)(unsigned short)ReadShort() << VAR_STATUS_NAME_SHIFT;
	} else if ( type == VAR_ARRAY ) {
		VAR_ARRAYSIZE( node ) = 0;
	}

	bArray = type == VAR_ARRAY ? qtrue : qfalse;

	count = (unsigned short)ReadShort();

	for ( i = count; i > 0; i-- ) {
		VariableValue   value;
		unsigned int    name;
		VariableValueInternal *entry;

		name  = DoLoadEntry( &value );
		entry = &scrVarNodes[ scrVarIndirections[ GetVariableIndexInternal( id, name ) ].id ];

		if ( bArray ) {
			if ( name < VAR_NAME_OBJECT_BASE ) {
				SL_RemoveRefToString( (unsigned short)name );
			} else if ( name < VAR_NAME_OBJECT_LIMIT ) {
				RemoveRefToObject( (unsigned short)name );
			}
		}

		entry->status |= (unsigned int)value.type;
		entry->u = value.u;
	}
}

void DoLoadObjectInfo__FUs( unsigned short id ) { DoLoadObjectInfo( id ); }

/* ---- Scr_SavePre  0x00474880 ---- VERIFIED */
void Scr_SavePre( int sys ) {
	unsigned int i;

	scrSave_idToSaveId = (unsigned short *)Hunk_AllocateTempMemoryHighInternal( SCR_SAVE_IDMAP_SIZE );
	scrSave_saveIdToId = (unsigned short *)Hunk_AllocateTempMemoryHighInternal( SCR_SAVE_IDMAP_SIZE );
	Com_Memset( scrSave_idToSaveId, 0, SCR_SAVE_IDMAP_SIZE );

	scrSave_numSaveObjects = 0;

	AddSaveObject( scrVarPub_levelId );
	AddSaveObject( scrVarPub_animId );
	AddSaveObject( scr_timeArrayId );
	AddSaveObject( scrVarPub_pauseArrayId );

	for ( i = 0; i < scrVarPub_classNum; i++ ) {
		AddSaveObject( VAR_OBJECTID( &scrVarNodes[
			scrVarIndirections[ FindVariableIndexInternal( scrVarPub_entId, i ) ].id ] ) );
		AddSaveObject( VAR_OBJECTID( &scrVarNodes[
			scrVarIndirections[ FindVariableIndexInternal( scrVarPub_classId, i ) ].id ] ) );
	}

	AddSaveEntry__FP21VariableValueInternal( &scrVarNodes[scrVarPub_gameId.handle] );
}

/* ---- WriteGameEntry  0x00474A30 ---- VERIFIED */
void WriteGameEntry__Fv( void ) {
	DoSaveEntryInternal( (unsigned char)( scrVarNodes[scrVarPub_gameId.handle].status & 0x9F ),
						 scrVarNodes[scrVarPub_gameId.handle].u );
}

/* ---- ReadGameEntry  0x00474A60 ---- VERIFIED */
void ReadGameEntry__Fv( void ) {
	VariableValue value;

	scrVarPub_gameId.handle = AllocValue();
	DoLoadEntryInternal( &value );
	/* indexed twice, not SetNewVariableValue: retail addresses [id*12+base] */
	scrVarNodes[scrVarPub_gameId.handle].status |= (unsigned int)value.type;
	scrVarNodes[scrVarPub_gameId.handle].u = value.u;
}

/* ---- Scr_SavePost  0x00474AC0 ---- VERIFIED */
void Scr_SavePost( void ) {
	unsigned int i;

	WriteInt( (int)scrVarPub_time );
	WriteShort( (short)scrSave_numSaveObjects );

	for ( i = 1; i <= scrSave_numSaveObjects; i++ ) {
		DoSaveObjectInfo( scrSave_saveIdToId[i] );
	}

	WriteGameEntry__Fv();

	WriteId( scrVarPub_levelId );
	WriteId( scrVarPub_animId );
	WriteId( scr_timeArrayId );
	WriteId( scrVarPub_pauseArrayId );

	for ( i = 0; i < scrVarPub_classNum; i++ ) {
		WriteId( VAR_OBJECTID( &scrVarNodes[
			scrVarIndirections[ FindVariableIndexInternal( scrVarPub_entId, i ) ].id ] ) );
	}
}

/* ---- Scr_SaveShutdown  0x00474DA0 ---- VERIFIED */
int Scr_SaveShutdown( void ) {
	return Hunk_ClearTempMemoryHigh();
}

/* ---- Scr_LoadPre  0x00474DB0 ---- VERIFIED */
void Scr_LoadPre( void ) {
	unsigned int    i;
	VariableValue   value;

	scrSave_readPos = SCR_LOAD_READ( 4 );
	scrSave_readPos = SCR_LOAD_READ( *(int *)scrSave_readPos );

	scrVarPub_time = (unsigned int)ReadInt();
	scrSave_numSaveObjects = (unsigned short)ReadShort();

	scrSave_idToSaveId = (unsigned short *)Hunk_AllocateTempMemoryInternal( SCR_SAVE_IDMAP_SIZE );
	scrSave_saveIdToId = (unsigned short *)Hunk_AllocateTempMemoryInternal(
						2 * (int)scrSave_numSaveObjects + 2 );

	for ( i = 1; i <= scrSave_numSaveObjects; i++ ) {
		unsigned short id = AllocObject();

		scrSave_saveIdToId[i]  = id;
		scrSave_idToSaveId[id] = (unsigned short)i;
	}

	for ( i = 1; i <= scrSave_numSaveObjects; i++ ) {
		DoLoadObjectInfo( scrSave_saveIdToId[i] );
	}

	ReadGameEntry__Fv();

	scrVarPub_levelId      = ReadId();
	scrVarPub_animId       = ReadId();
	scr_timeArrayId        = ReadId();
	scrVarPub_pauseArrayId = ReadId();

	value.type = VAR_OBJECT;
	for ( i = 0; i < scrVarPub_classNum; i++ ) {
		value.u.halfword.lo = ReadId();
		SetVariableValue(
			scrVarIndirections[ FindVariableIndexInternal( scrVarPub_entId, i ) ].id,
			&value );
	}
}

/* ---- Scr_LoadShutdown  0x004750B0 ---- VERIFIED */
void Scr_LoadShutdown( void ) {
	unsigned int i;

	for ( i = 1; i <= scrSave_numSaveObjects; i++ ) {
		RemoveRefToObject( scrSave_saveIdToId[i] );
	}

	Hunk_FreeTempMemory( scrSave_saveIdToId );
	Hunk_FreeTempMemory( scrSave_idToSaveId );
}

/* ---- Scr_FindField  0x004751B0 ---- VERIFIED */
short __cdecl Scr_FindField( const char *name, int *typeOut ) {
	const char *cursor = scrVarPub_fieldBuffer;

	while ( *cursor ) {
		unsigned int nameSize = strlen( cursor ) + 1;

		/* retail 0x004751D5: CRT _stricmp (0x0053549F), not Q_stricmp */
		if ( !_stricmp( name, cursor ) ) {
			unsigned short offset;
			int            type;

			cursor += nameSize;
			type = (int)(signed char)cursor[2];
			memcpy( &offset, cursor, sizeof( offset ) );
			*typeOut = type;
			return (short)offset;
		}
		cursor += nameSize + 3;
	}
	return 0;
}

/* ---- Scr_AddFieldsForFile  0x00475210 ---- VERIFIED */
static void Scr_AddFieldsForFile( const char *filename ) {
	fileHandle_t    f;
	int             length;
	char           *fileText;
	char           *parse;

	length = FS_FOpenFileByMode( filename, &f, FS_READ );
	if ( length < 0 ) {
		Com_Error( ERR_DROP, va( "\x15" "cannot find '%s'", filename ) );
	}

	fileText = (char *)Hunk_AllocateTempMemoryHighInternal( length + 1 );
	FS_Read( fileText, length, f );
	fileText[length] = '\0';
	FS_FCloseFile( f );

	parse = fileText;
	Com_BeginParseSession( "Scr_AddFields" );

	for ( ;; ) {
		char           *token;
		int             fieldType;
		unsigned int    nameSize;
		unsigned short  canonical;
		int             existingType;
		char           *record;
		int             i;

		token = Com_Parse( &parse );
		if ( parse == NULL ) {
			break;
		}

		if ( !strcmp( token, "float" ) ) {
			fieldType = VAR_FLOAT;
		} else if ( !strcmp( token, "int" ) ) {
			fieldType = VAR_INTEGER;
		} else if ( !strcmp( token, "string" ) ) {
			fieldType = VAR_STRING;
		} else {
			Com_Error( ERR_DROP, va( "\x15" "unknown type '%s' in '%s'", token, filename ) );
			return;
		}

		token = Com_Parse( &parse );
		if ( parse == NULL ) {
			Com_Error( ERR_DROP, va( "\x15" "missing field name in '%s'", filename ) );
		}

		nameSize = strlen( token ) + 1;
		for ( i = nameSize - 1; i >= 0; i-- ) {
			token[i] = (char)tolower( token[i] );
		}

		canonical = SL_FindCanonicalString( token );
		if ( !canonical ) {
			continue;
		}

		if ( Scr_FindField( token, &existingType ) ) {
			Com_Error( ERR_DROP, "\x15" "duplicate key '%s' in '%s'", token, filename );
		}

		record = (char *)TempMalloc( (int)nameSize + 3 );
		strcpy( record, token );
		record += nameSize;
		*(unsigned short *)record = canonical;
		record += 2;
		record[0] = (char)fieldType;
		record[1] = '\0';
	}

	Com_EndParseSession();
	Hunk_ClearTempMemoryHigh();
}

int Scr_AddFieldsForFile__FPCc( const char *filename ) {
	Scr_AddFieldsForFile( filename );
	return 0;
}

/* ---- Scr_AddFields  0x004754F0 ---- VERIFIED */
void __cdecl Scr_AddFields( const char *path, const char *extension ) {
	char  **files;
	int     numfiles;
	int     i;
	char   *terminator;

	files = FS_ListFilteredFiles( path, extension, 0, &numfiles );

	TempMemoryReset();
	scrVarPub_fieldBuffer = (char *)Hunk_AllocLowAlignInternal( 0, 32 );
	scrVarPub_fieldBuffer[0] = '\0';

	for ( i = 0; i < numfiles; i++ ) {
		char qpath[64];

		/* retail 0x00475551: unbounded CRT sprintf (0x00525208) into char[64] */
		sprintf( qpath, "%s/%s", path, files[i] );
		Scr_AddFieldsForFile( qpath );
	}

	if ( files ) {
		FS_FreeFileList( files );
	}

	terminator  = (char *)TempMalloc( 1 );
	*terminator = '\0';
	Hunk_CommitTempMemory();
}

/* ---- Scr_FreeValue  0x00475610 ---- VERIFIED */
void __cdecl Scr_FreeValue( unsigned short id ) {
	RemoveRefToObject( id );
}

/* ---- Scr_MakeValuePrimitive  0x00475660 ---- VERIFIED */
int __cdecl Scr_MakeValuePrimitive( unsigned short parentId ) {
	unsigned short          id;
	VariableValueInternal  *entryValue;
	unsigned int            status;
	unsigned int            name;

	if ( VAR_TYPE( &scrVarNodes[parentId] ) != VAR_ARRAY ) {
		return 0;
	}

	/* Mac 1.3 shape: removing a child restarts the walk */
restart:
	for ( id = FindNextSibling( parentId ); id; id = FindNextSibling( id ) ) {
		entryValue = &scrVarNodes[id];
		status = entryValue->status;
		name = status >> VAR_STATUS_NAME_SHIFT;
		switch ( status & VAR_STATUS_TYPE_MASK ) {
		case VAR_CODEPOS:
		case VAR_FUNCTION:
		case VAR_STACK:
		case VAR_ANIMATION:
			RemoveVariable( parentId, name );
			goto restart;
		case VAR_OBJECT:
			if ( !Scr_MakeValuePrimitive( entryValue->u.halfword.lo ) ) {
				RemoveVariable( parentId, name );
				goto restart;
			}
			break;
		}
	}
	return 1;
}

int Scr_MakeValuePrimitive__FUs( unsigned short arrayId ) {
	return Scr_MakeValuePrimitive( arrayId );
}

/* ---- Scr_AllocGameVariable  0x00475790 ---- VERIFIED */
void __cdecl Scr_AllocGameVariable( void ) {
	if ( !scrVarPub_gameId.handle ) {
		scrVarPub_gameId.handle = AllocValue();
		SetEmptyArray( scrVarPub_gameId.word );
	}
}

/* ---- Scr_FreeGameVariable  0x004757D0 ---- VERIFIED */
void __cdecl Scr_FreeGameVariable( int bComplete ) {
	if ( bComplete ) {
		FreeValueInternal( &scrVarNodes[ scrVarPub_gameId.handle ] );
		scrVarPub_gameId.handle = 0;
		return;
	}
	Scr_MakeValuePrimitive( VAR_OBJECTID( &scrVarNodes[ scrVarPub_gameId.handle ] ) );
}

/* ---- Scr_GetChecksum  0x00475810 ---- VERIFIED */
unsigned int *__cdecl Scr_GetChecksum( unsigned int *out ) {
	out[0] = scrCompilePub_checksum;
	out[1] = scrCompilePub_programLen;
	out[2] = scrVarPub_endScriptBuffer - scrVarPub_programBuffer;
	return out;
}

#ifdef __cplusplus
}
#endif
