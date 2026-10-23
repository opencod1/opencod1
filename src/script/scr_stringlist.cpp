/*
 * script/scr_stringlist.cpp
 *
 * Original translation unit:
 *   /Volumes/BigCheese/ Source/AspyrP4/CoD/Source/script/scr_stringlist.cpp
 *
 * Retail range 0x0046F7C0-0x004704B0, 28 functions.
 *
 * @fidelity: verified
 */

#ifdef __cplusplus
/* This unit is C; the build compiles it as C++ for the shared project
 * settings, so force C linkage for every definition. */
extern "C" {
#endif

#include "scr_local.h"
#include <malloc.h>

scrStringHashSlot_t     scrStringHashSlots[SCR_STRING_HASH_SLOT_COUNT];

scrStringHashSlot_t    *scrString_freedHashSlot;

unsigned short         *scrString_canonicalMap;
/* initialised, so a real definition rather than a C common: VC7 then reloads it as a
   dword after the canonical-map store (retail Scr_InsertDeveloperOpcodes 0x0046C878) */
unsigned short          scrString_canonicalCount = 0;

/* ---- GetRefString  0x0046F7C0 ---- VERIFIED */
scrStringEntry_t *GetRefString( unsigned short handle ) {
	return (scrStringEntry_t *)( (scrMemBlock_t *)GetRefString_var + handle );
}

/* ---- GetRefString  0x0046F7D0 ---- VERIFIED */
static scrStringEntry_t *GetRefStringByText( const char *text ) {
	return (scrStringEntry_t *)( text - SCR_STRING_ENTRY_HEADER_SIZE );
}

/* ---- SL_ConvertToString  0x0046F7E0 ---- VERIFIED */
const char *SL_ConvertToString( unsigned short handle ) {
	if ( handle ) {
		return GetRefString( handle )->text;
	}
	return NULL;
}

/* ---- SL_ConvertFromString  0x0046F800 ---- VERIFIED */
unsigned short SL_ConvertFromString( const char *text ) {
	scrStringEntry_t *entry = GetRefStringByText( text );

	return (unsigned short)( ( (const char *)entry - (const char *)GetRefString_var )
							 / SCR_MT_BLOCK_SIZE );
}

/* ---- GetHashCode  0x0046F820 ---- VERIFIED */
static unsigned short GetHashCode( const char *text, unsigned int size ) {
	unsigned int hash;

	if ( size < SCR_STRING_HASH_SHORT_LIMIT ) {
		for ( hash = 0; size; size-- ) {
			hash = hash * SCR_STRING_HASH_MULTIPLIER + (unsigned int)(int)(signed char)*text++;
		}
		return (unsigned short)( hash % SCR_STRING_HASH_LINK_MASK + SCR_STRING_HASH_FIRST_SLOT );
	}

	return (unsigned short)( ( size >> 2 ) % SCR_STRING_HASH_LINK_MASK + SCR_STRING_HASH_FIRST_SLOT );
}

/* ---- SL_Init  0x0046F860 ---- VERIFIED */
void SL_Init( void ) {
	unsigned short          previous;
	unsigned int            slot;
	scrStringHashSlot_t    *entry;

	MT_Init();

	scrStringHashSlots[0].linkAndFlags = 0;
	previous = 0;
	for ( slot = SCR_STRING_HASH_FIRST_SLOT;
		  slot < SCR_STRING_HASH_SLOT_COUNT;
		  slot++ ) {
		entry = &scrStringHashSlots[slot];
		entry->linkAndFlags = SCR_STRING_HASH_EMPTY;
		scrStringHashSlots[previous].linkAndFlags =
			(unsigned short)( scrStringHashSlots[previous].linkAndFlags | slot );
		entry->stringHandle = previous;
		previous = (unsigned short)slot;
	}
	scrStringHashSlots[0].stringHandle = previous;
}

/* ---- SL_FindStringOfLen  0x0046F8E0 ---- VERIFIED */
unsigned short SL_FindStringOfLen( const char *text, unsigned int size ) {
	unsigned short          hash;
	scrStringHashSlot_t    *head;
	scrStringHashSlot_t    *current;
	scrStringEntry_t       *entry;
	unsigned short          previousSlot;
	unsigned short          currentSlot;
	unsigned short          movedHandle;

	hash = GetHashCode( text, size );
	head = &scrStringHashSlots[hash];

	if ( ( head->linkAndFlags & SCR_STRING_HASH_FLAGS_MASK )
		 == SCR_STRING_HASH_OCCUPIED ) {
		entry = GetRefString( head->stringHandle );
		if ( entry->sizeByte == (unsigned char)size
			 && memcmp( entry->text, text, size ) == 0 ) {
			return head->stringHandle;
		}

		previousSlot = hash;
		currentSlot = (unsigned short)( head->linkAndFlags & SCR_STRING_HASH_LINK_MASK );
		current = &scrStringHashSlots[currentSlot];
		while ( current != head ) {
			entry = GetRefString( current->stringHandle );
			if ( entry->sizeByte == (unsigned char)size
				 && memcmp( entry->text, text, size ) == 0 ) {
				scrStringHashSlots[previousSlot].linkAndFlags =
					(unsigned short)( ( current->linkAndFlags & SCR_STRING_HASH_LINK_MASK )
									  | ( scrStringHashSlots[previousSlot].linkAndFlags
										  & SCR_STRING_HASH_FLAGS_MASK ) );
				current->linkAndFlags =
					(unsigned short)( ( head->linkAndFlags & SCR_STRING_HASH_LINK_MASK )
									  | ( current->linkAndFlags & SCR_STRING_HASH_FLAGS_MASK ) );
				head->linkAndFlags =
					(unsigned short)( currentSlot
									  | ( head->linkAndFlags & SCR_STRING_HASH_FLAGS_MASK ) );

				movedHandle = current->stringHandle;
				current->stringHandle = head->stringHandle;
				head->stringHandle = movedHandle;
				return movedHandle;
			}
			previousSlot = currentSlot;
			currentSlot = (unsigned short)( current->linkAndFlags & SCR_STRING_HASH_LINK_MASK );
			current = &scrStringHashSlots[currentSlot];
		}
	}

	return 0;
}

/* ---- SL_FindString  0x0046FA30 ---- VERIFIED */
unsigned short SL_FindString( const char *text ) {
	return SL_FindStringOfLen( text, (unsigned int)strlen( text ) + 1 );
}

/* ---- SL_FindLowercaseString  0x0046FA50 ---- VERIFIED */
unsigned short SL_FindLowercaseString( const char *text ) {
	unsigned int    size;
	char           *lowercase;
	int             i;

	size = (unsigned int)strlen( text ) + 1;
	lowercase = (char *)_alloca( size );

	for ( i = (int)size - 1; i >= 0; i-- ) {
		lowercase[i] = (char)tolower( text[i] );
	}

	return SL_FindStringOfLen( lowercase, size );
}

/* ---- SL_GetStringOfLen  0x0046FAC0 ---- VERIFIED */
unsigned short SL_GetStringOfLen( const char *text, unsigned char user,
								  unsigned int size, int type ) {
	unsigned short          hash;
	scrStringHashSlot_t    *head;
	scrStringHashSlot_t    *current;
	scrStringHashSlot_t    *freeEntry;
	scrStringEntry_t       *entry;
	unsigned short          previousSlot;
	unsigned short          currentSlot;
	unsigned short          freeSlot;
	unsigned short          nextFree;
	unsigned short          movedHandle;

	hash = GetHashCode( text, size );
	head = &scrStringHashSlots[hash];

	if ( ( head->linkAndFlags & SCR_STRING_HASH_FLAGS_MASK )
		 == SCR_STRING_HASH_OCCUPIED ) {
		entry = GetRefString( head->stringHandle );
		if ( entry->sizeByte == (unsigned char)size
			 && memcmp( entry->text, text, size ) == 0 ) {
			if ( ( entry->flags & user ) == 0 ) {
				entry->flags = (unsigned char)( entry->flags | user );
				entry->refCount++;
			}
			return head->stringHandle;
		}

		currentSlot = (unsigned short)( head->linkAndFlags & SCR_STRING_HASH_LINK_MASK );
		current = &scrStringHashSlots[currentSlot];
		previousSlot = hash;
		while ( current != head ) {
			entry = GetRefString( current->stringHandle );
			if ( entry->sizeByte == (unsigned char)size
				 && memcmp( entry->text, text, size ) == 0 ) {
				scrStringHashSlots[previousSlot].linkAndFlags =
					(unsigned short)( ( current->linkAndFlags & SCR_STRING_HASH_LINK_MASK )
									  | ( scrStringHashSlots[previousSlot].linkAndFlags
										  & SCR_STRING_HASH_FLAGS_MASK ) );
				current->linkAndFlags =
					(unsigned short)( ( head->linkAndFlags & SCR_STRING_HASH_LINK_MASK )
									  | ( current->linkAndFlags & SCR_STRING_HASH_FLAGS_MASK ) );
				head->linkAndFlags =
					(unsigned short)( currentSlot
									  | ( head->linkAndFlags & SCR_STRING_HASH_FLAGS_MASK ) );

				movedHandle = current->stringHandle;
				current->stringHandle = head->stringHandle;
				head->stringHandle = movedHandle;

				if ( ( entry->flags & user ) == 0 ) {
					entry->flags = (unsigned char)( entry->flags | user );
					entry->refCount++;
				}
				return head->stringHandle;
			}
			previousSlot = currentSlot;
			currentSlot = (unsigned short)( current->linkAndFlags & SCR_STRING_HASH_LINK_MASK );
			current = &scrStringHashSlots[currentSlot];
		}

		freeSlot = scrStringHashSlots[0].linkAndFlags;
		if ( freeSlot == 0 ) {
			Scr_DumpScriptThreads();
			Com_Error( ERR_DROP, "\x15" "exceeded maximum number of script strings\n" );
		}
		/* pop the free list (retail inlines this at both allocation sites) */
		freeEntry = &scrStringHashSlots[freeSlot];
		nextFree = (unsigned short)( freeEntry->linkAndFlags & SCR_STRING_HASH_LINK_MASK );
		scrStringHashSlots[0].linkAndFlags = nextFree;
		scrStringHashSlots[nextFree].stringHandle = 0;

		freeEntry->linkAndFlags =
			(unsigned short)( ( head->linkAndFlags & SCR_STRING_HASH_LINK_MASK )
							  | SCR_STRING_HASH_CHAINED );
		head->linkAndFlags =
			(unsigned short)( ( freeSlot & SCR_STRING_HASH_LINK_MASK )   /* no-op mask: retail's xor merge */
							  | ( head->linkAndFlags & SCR_STRING_HASH_FLAGS_MASK ) );
		freeEntry->stringHandle = head->stringHandle;
	} else {
		if ( ( head->linkAndFlags & SCR_STRING_HASH_FLAGS_MASK ) == SCR_STRING_HASH_EMPTY ) {
			previousSlot = head->stringHandle;
			currentSlot = (unsigned short)( head->linkAndFlags & SCR_STRING_HASH_LINK_MASK );
			scrStringHashSlots[previousSlot].linkAndFlags =
				(unsigned short)( currentSlot
								  | ( scrStringHashSlots[previousSlot].linkAndFlags
									  & SCR_STRING_HASH_FLAGS_MASK ) );
			scrStringHashSlots[currentSlot].stringHandle = previousSlot;
		} else {
			currentSlot = (unsigned short)( head->linkAndFlags & SCR_STRING_HASH_LINK_MASK );
			previousSlot = currentSlot;
			while ( ( scrStringHashSlots[previousSlot].linkAndFlags
					  & SCR_STRING_HASH_LINK_MASK ) != hash ) {
				previousSlot = (unsigned short)( scrStringHashSlots[previousSlot].linkAndFlags
												 & SCR_STRING_HASH_LINK_MASK );
			}

			freeSlot = scrStringHashSlots[0].linkAndFlags;
			if ( freeSlot == 0 ) {
				Scr_DumpScriptThreads();
				Com_Error( ERR_DROP, "\x15" "exceeded maximum number of script strings\n" );
			}
			freeEntry = &scrStringHashSlots[freeSlot];
			nextFree = (unsigned short)( freeEntry->linkAndFlags & SCR_STRING_HASH_LINK_MASK );
			scrStringHashSlots[0].linkAndFlags = nextFree;
			scrStringHashSlots[nextFree].stringHandle = 0;

			scrStringHashSlots[previousSlot].linkAndFlags =
				(unsigned short)( freeSlot
								  | ( scrStringHashSlots[previousSlot].linkAndFlags
									  & SCR_STRING_HASH_FLAGS_MASK ) );
			freeEntry->linkAndFlags = (unsigned short)( currentSlot | SCR_STRING_HASH_CHAINED );
			freeEntry->stringHandle = head->stringHandle;
		}
		head->linkAndFlags = (unsigned short)( hash | SCR_STRING_HASH_OCCUPIED );
	}

	head->stringHandle =
		MT_AllocIndex( (int)( size + SCR_STRING_ENTRY_HEADER_SIZE ), type );
	entry = GetRefString( head->stringHandle );
	Com_Memcpy( entry->text, text, size );
	entry->flags = user;
	entry->refCount = 0;
	entry->sizeByte = (unsigned char)size;

	return head->stringHandle;
}

/* ---- SL_GetString_  0x0046FE00 ---- VERIFIED */
unsigned short SL_GetString_( const char *text, unsigned char user, int type ) {
	return SL_GetStringOfLen( text, user, (unsigned int)strlen( text ) + 1, type );
}

/* ---- SL_GetString  0x0046FE30 ---- VERIFIED */
unsigned short SL_GetString( const char *text, unsigned char user ) {
	return SL_GetString_( text, user, 6 );
}

/* ---- SL_GetLowercaseStringOfLen  0x0046FE60 ---- VERIFIED */
unsigned short SL_GetLowercaseStringOfLen( const char *text, unsigned char user,
										   unsigned int size, int type ) {
	char   *lowercase;
	int     i;

	lowercase = (char *)_alloca( size );
	for ( i = (int)size - 1; i >= 0; i-- ) {
		lowercase[i] = (char)tolower( text[i] );
	}

	return SL_GetStringOfLen( lowercase, user, size, type );
}

/* ---- SL_GetLowercaseString_  0x0046FED0 ---- VERIFIED */
unsigned short SL_GetLowercaseString_( const char *text, unsigned char user, int type ) {
	return SL_GetLowercaseStringOfLen( text, user,
									   (unsigned int)strlen( text ) + 1, type );
}

/* ---- SL_GetLowercaseString  0x0046FF00 ---- VERIFIED */
unsigned short SL_GetLowercaseString( const char *text, unsigned char user ) {
	return SL_GetLowercaseString_( text, user, 6 );
}

/* ---- SL_TransferRefToString  0x0046FF30 ---- VERIFIED */
void SL_TransferRefToString( unsigned short handle, unsigned char usage ) {
	scrStringEntry_t *entry = GetRefString( handle );

	if ( entry->flags & usage ) {
		entry->refCount--;
		return;
	}
	entry->flags = (unsigned char)( entry->flags | usage );
}

/* ---- SL_AddRefToString  0x0046FF50 ---- VERIFIED */
void SL_AddRefToString( unsigned short handle ) {
	GetRefString( handle )->refCount++;
}

/* ---- SL_FreeString  0x0046FF70 ---- VERIFIED */
void SL_FreeString( unsigned short handle, const char *text, unsigned int size ) {
	unsigned short          hash;
	scrStringHashSlot_t    *head;
	scrStringHashSlot_t    *replacement;
	unsigned short          replacementSlot;
	unsigned short          previousSlot;
	unsigned short          oldFreeHead;

	hash = GetHashCode( text, size );
	head = &scrStringHashSlots[hash];

	MT_FreeIndex( handle, size + SCR_STRING_ENTRY_HEADER_SIZE );

	replacementSlot = (unsigned short)( head->linkAndFlags & SCR_STRING_HASH_LINK_MASK );
	replacement = &scrStringHashSlots[replacementSlot];

	if ( head->stringHandle == handle ) {
		if ( replacement != head ) {
			head->linkAndFlags =
				(unsigned short)( ( replacement->linkAndFlags
									& SCR_STRING_HASH_LINK_MASK )
								  | SCR_STRING_HASH_OCCUPIED );
			head->stringHandle = replacement->stringHandle;
			scrString_freedHashSlot = head;
		} else {
			/* already equal; retail still copies both (mov ecx,esi / mov eax,ebx) */
			replacement = head;
			replacementSlot = hash;
		}
	} else {
		previousSlot = hash;
		while ( replacement->stringHandle != handle ) {
			previousSlot = replacementSlot;
			replacementSlot = (unsigned short)( replacement->linkAndFlags
												& SCR_STRING_HASH_LINK_MASK );
			replacement = &scrStringHashSlots[replacementSlot];
		}
		scrStringHashSlots[previousSlot].linkAndFlags =
			(unsigned short)( ( replacement->linkAndFlags & SCR_STRING_HASH_LINK_MASK )
							  | ( scrStringHashSlots[previousSlot].linkAndFlags
								  & SCR_STRING_HASH_FLAGS_MASK ) );
	}

	oldFreeHead = scrStringHashSlots[0].linkAndFlags;
	replacement->linkAndFlags = scrStringHashSlots[0].linkAndFlags;   /* re-read: retail's mov si,dx */
	replacement->stringHandle = 0;
	scrStringHashSlots[oldFreeHead].stringHandle = replacementSlot;
	scrStringHashSlots[0].linkAndFlags = replacementSlot;
}

/* ---- SL_RemoveRefToString  0x00470050 ---- VERIFIED */
void SL_RemoveRefToString( unsigned short handle ) {
	scrStringEntry_t *entry = GetRefString( handle );

	if ( entry->refCount ) {
		entry->refCount--;
		return;
	}
	SL_FreeString( handle, entry->text, (unsigned int)strlen( entry->text ) + 1 );
}

/* ---- SL_RemoveRefToStringOfLen  0x00470090 ---- VERIFIED */
void SL_RemoveRefToStringOfLen( unsigned short handle, unsigned int size ) {
	scrStringEntry_t *entry = GetRefString( handle );

	if ( entry->refCount ) {
		entry->refCount--;
		return;
	}
	SL_FreeString( handle, entry->text, size );
}

/* ---- Scr_SetString  0x004700C0 ---- VERIFIED */
void Scr_SetString( unsigned short *slot, unsigned short value ) {
	if ( *slot ) {
		SL_RemoveRefToString( *slot );
	}
	if ( value ) {
		SL_AddRefToString( value );
	}
	*slot = value;
}

/* ---- Scr_AllocString  0x00470130 ---- VERIFIED */
unsigned short Scr_AllocString( const char *text ) {
	return SL_GetString( text, SCR_STRING_USER_SCRIPT );
}

/* ---- SL_GetStringForFloat  0x00470160 ---- VERIFIED */
unsigned short SL_GetStringForFloat( float value ) {
	char text[SCR_STRING_FORMAT_BUFFER_SIZE];

	sprintf( text, "%g", (double)value );
	return SL_GetString_( text, 0, 14 );
}

/* ---- SL_GetStringForInt  0x004701E0 ---- */
unsigned short SL_GetStringForInt( int value ) {
	char text[SCR_STRING_FORMAT_BUFFER_SIZE];

	sprintf( text, "%i", value );
	return SL_GetString_( text, 0, 14 );
}

/* ---- SL_GetStringForVector  0x00470260 ---- */
unsigned short SL_GetStringForVector( const float *v ) {
	char text[SCR_STRING_FORMAT_BUFFER_SIZE];

	sprintf( text, "(%.2f, %.2f, %.2f)", (double)v[0], (double)v[1], (double)v[2] );
	return SL_GetString_( text, 0, 14 );
}

/* ---- SL_ShutdownSystem  0x004702F0 ---- VERIFIED */
void SL_ShutdownSystem( unsigned char usage ) {
	unsigned int            slot;
	scrStringHashSlot_t    *hashSlot;
	scrStringEntry_t       *entry;

	for ( slot = SCR_STRING_HASH_FIRST_SLOT;
		  slot < SCR_STRING_HASH_SLOT_COUNT;
		  slot++ ) {
		do {
			hashSlot = &scrStringHashSlots[slot];
			if ( ( hashSlot->linkAndFlags & SCR_STRING_HASH_FLAGS_MASK )
				 == SCR_STRING_HASH_EMPTY ) {
				break;
			}

			entry = GetRefString( hashSlot->stringHandle );
			if ( ( entry->flags & usage ) == 0 ) {
				break;
			}
			entry->flags = (unsigned char)( entry->flags & ~usage );

			scrString_freedHashSlot = NULL;
			SL_RemoveRefToString( hashSlot->stringHandle );
		} while ( scrString_freedHashSlot );
	}
}

/* ---- CreateCanonicalFilename  0x00470390 ---- VERIFIED */
void CreateCanonicalFilename( char *dest, const char *source, int maxLength ) {
	char ch;

	for ( ;; ) {
		do {
			do {
				ch = *source++;
			} while ( ch == '\\' );
		} while ( ch == '/' );

		while ( (unsigned char)ch >= ' ' ) {
			*dest++ = (char)tolower( ch );
			maxLength--;
			if ( maxLength == 0 ) {
				Com_Error( ERR_DROP,
						   "\x15" "Filename '%s' exceeds maximum length of %d",
						   source, maxLength );
			}
			if ( ch == '\\' ) {
				break;
			}

			ch = *source++;
			if ( ch == '/' ) {
				ch = '\\';
			}
		}

		if ( ch == '\0' ) {
			*dest = '\0';
			return;
		}
	}
}

/* ---- Scr_CreateCanonicalFilename  0x00470400 ---- VERIFIED */
unsigned short Scr_CreateCanonicalFilename( const char *filename ) {
	char canonical[SCR_STRING_CANONICAL_LIMIT];

	CreateCanonicalFilename( canonical, filename, SCR_STRING_CANONICAL_LIMIT );
	return SL_GetString_( canonical, 0, 7 );
}

void SL_FreeString__FUsPCcUi( unsigned short handle, const char *text,
							  unsigned int size ) {
	SL_FreeString( handle, text, size );
}

scrStringEntry_t *GetRefString__FUs( unsigned short handle ) {
	return GetRefString( handle );
}

scrStringEntry_t *GetRefString__FPCc( const char *text ) {
	return GetRefStringByText( text );
}

void CreateCanonicalFilename__FPcPCci( char *dest, const char *source, int maxLength ) {
	CreateCanonicalFilename( dest, source, maxLength );
}

#ifdef __cplusplus
}
#endif
