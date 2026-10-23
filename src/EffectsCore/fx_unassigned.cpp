/*
 * Machine-translated from Call of Duty 1.1 (Windows, CoDMP.exe).
 * Original translation unit:
 * /Volumes/BigCheese/ Source/AspyrP4/CoD/Source/EffectsCore/fx_unassigned.cpp
 * Retail range 0x0048C070-0x004A0FA0, 685 functions: all translated, 0 stubbed
 * (the last AUTO-STUBBED helpers -- the std::logic_error family, allocator
 * and string-compare shims, the scheduler's per-effect archiver -- were
 * reconstructed from retail).
 * @fidelity: likely
 * @fidelity-default: unreviewed
 */

#ifdef __cplusplus
#include <exception>   /* std::exception: LIBCMT stdexcpt.obj */
void __cdecl operator delete( void * ) throw();   /* <new>: allocator::deallocate never throws */
namespace std {
/* <xstring>: basic_string's base; _Xlen/_Xran throw length_error/out_of_range (LIBCPMT string.obj). */
class _String_base
{
public:
  void _Xlen() const;
  void _Xran() const;
};
}
/* retail built this unit as C++ with exceptions (/TP /EHs); every name keeps C linkage */
extern "C" {
#endif

/* Native allocator value objects are copied on the stack. */
typedef struct {int *pointer;} FxListResultArgument;
typedef struct {unsigned int *node;} FxListIteratorArgument;
static __inline FxListResultArgument FxListResult(int*pointer){FxListResultArgument a;a.pointer=pointer;return a;}
static __inline FxListIteratorArgument FxListIterator(unsigned int*node){FxListIteratorArgument a;a.node=node;return a;}
typedef struct {int value;} FxPostIncrementArgument;
typedef struct {unsigned char value;} FxTidyBooleanArgument;
typedef struct {const void *pointer;} FxTypeInfoSourceArgument;
typedef struct {unsigned int *pointer;} FxVectorWordArgument;
typedef struct {unsigned int count;} FxVectorCountArgument;
static __inline FxVectorWordArgument FxVectorWord(unsigned int *pointer){FxVectorWordArgument a;a.pointer=pointer;return a;}
static __inline FxVectorCountArgument FxVectorCount(unsigned int count){FxVectorCountArgument a;a.count=count;return a;}
typedef struct {const void *pointer;} FxTreeAllocatorReference;
typedef struct {void **pointer;} FxMapRootValue;
static __inline FxMapRootValue FxMapRootArgument(void **node){FxMapRootValue arg;arg.pointer=node;return arg;}
typedef struct {void *pointer;} FxMapIteratorValue;
static __inline FxMapIteratorValue FxMapIteratorArgument(void *p){FxMapIteratorValue a;a.pointer=p;return a;}
typedef struct {void ****pointer;} FxPairStringReference;
typedef struct {unsigned int *pointer;} FxPairValueReference;
typedef struct {const void *pointer;} FxNodeAllocatorReference;
typedef struct {unsigned int count;} FxNodeAllocationCount;
typedef struct {void *pointer;} FxDeallocatePointer;
typedef struct {void ***pointer;} FxRebalanceResult;
typedef struct {unsigned char value;} FxRebalanceBool;
typedef struct {int value;} FxRebalanceValue;
static __inline FxRebalanceResult FxRebalanceOutput(void ***p){FxRebalanceResult a;a.pointer=p;return a;}
static __inline FxRebalanceBool FxRebalanceDirection(unsigned char b){FxRebalanceBool a;a.value=b;return a;}
static __inline FxRebalanceValue FxRebalanceInput(int v){FxRebalanceValue a;a.value=v;return a;}
typedef struct {const unsigned char *pointer;} FxInsidePointer;
typedef struct {unsigned char :8;} FxNonscalarPointerTag;
typedef struct { unsigned char value; } FxStlAllocatorTag;

typedef struct { const char *pointer; } FxConstCharPointerArgument;
typedef struct { unsigned int count; } FxSizeArgument;
static __inline FxConstCharPointerArgument FxConstCharArgument(const char *pointer) { FxConstCharPointerArgument arg; arg.pointer=pointer; return arg; }
static __inline FxSizeArgument FxCountArgument(unsigned int count) { FxSizeArgument arg; arg.count=count; return arg; }
int __fastcall stl_fxString_assignPtrCount_m(int self, FxConstCharPointerArgument pointerArg, FxSizeArgument countArg);
/* Native C bridge: one ECX object plus the actual four-byte deleting-flags stack value. */
typedef struct { unsigned int bits; } FxDeletingFlags;

/* Native C ABI bridge: each value record carries exactly one real four-byte stack argument. */
typedef struct { char *pointer; } FxCharPointerArgument;

typedef struct { void *pointer; } FxPointerArgument;
typedef struct { const void *pointer; } FxConstPointerArgument;

typedef char FxPointerArgumentIsFourBytes[(sizeof(FxPointerArgument)==4)?1:-1];
typedef char FxSizeArgumentIsFourBytes[(sizeof(FxSizeArgument)==4)?1:-1];




#include "../qcommon/crt_cpp_runtime.h"
#include "../qcommon/qcommon.h"
#include "../client_mp/cl_refapi.h"   /* re */
#include "fx_types.h"

/* the fx cvars (registered by CL_Init, client_mp/cl_main_mp.c) */
extern cvar_t *fx_count;
extern cvar_t *fx_cull;
extern cvar_t *fx_debug;
extern cvar_t *fx_debugBolt;
extern cvar_t *fx_draw;
extern cvar_t *fx_enable;
extern cvar_t *fx_freeze;
/* renderer/tr_debug.c */
extern unsigned int colorDebugRed[9];
extern unsigned int colorDebugGreen[5];
extern unsigned int colorDebugBlue[92];
extern unsigned int colorDebugYellow[88];
/* fx_rdata.c: the scheduler, and the SFxHelper (unsigned char[132]) seen through its first int */
extern unsigned int theFxScheduler[5409];
extern int theFxHelper;
/* The C++ originals of some members below kept the standard thiscall
 * convention (ECX this, stack arguments, callee pops): a no-code reference to
 * the function's own address marks it address-taken, so LTCG keeps the
 * declared convention instead of assigning custom argument registers. */
#define FX_STANDARD_CALL(fn) ((void)&(fn))
/* Some retail members keep a parameter in its stack home and reload it after
 * every store through a pointer, as if its address escaped; a dead store of
 * the address marks it so without emitting any code. */
#define FX_ADDRESS_ESCAPES(v) if ( 0 ) *(void **)0 = (void *)&(v)

/* An effect's scalar deleting destructor (vftable slot 0) takes ECX this plus
 * one stack dword of flags.  __fastcall would pass an integer second argument
 * in EDX, and VC7 materializes a by-value struct through a register first, so
 * the flags travel as a float carrying the same bits (0x00000001): VC7 pushes
 * that as an immediate, like retail's `push 1`. */
typedef void (__fastcall *FxEffectDeleteFn)( void *self, float deleteFlagBits );
#define FX_DELETE_FLAG_BITS_1  1.4012984643e-45f   /* bit pattern 0x00000001 */
#define FX_DELETE_EFFECT( effect ) \
  ( (**(FxEffectDeleteFn **)(effect))( (void *)(effect), FX_DELETE_FLAG_BITS_1 ) )

void __cdecl stl_fxScheduledList_dtor_m( int list );
int  __cdecl stl_fxEffectIdMap_tidy_m( int tree );

/* Forward declarations for reconstructed helpers that are defined later in
 * this translation unit.  C++ has no implicit function declarations, so the
 * calls below need these prototypes; VC7's permissive mode masked the issue. */
void __cdecl stl_fxEffectIdMap_clear_m( int tree );
int  __stdcall stl_fxScheduledList_pushFront_m( int list, unsigned int *value );
void __stdcall stl_fxIntVector_nop3_m( int unused1, int unused2 );
char *__cdecl stl_fxChar_swap_m( char *a, char *b );
char __cdecl stl_fxIntVector_buy_m( unsigned int count, unsigned int *vec );

#include "../renderer/qgl.h"
#include "../universal/com_sndalias.h"
/* The refexport_t slots the decompiled callers use unprototyped (int (*)()
 * in C): under C++ an ellipsis keeps C's any-arguments call. */
#ifdef __cplusplus
#define FX_ANYARGS ...
#undef  re_RegisterModel
#define re_RegisterModel           ( *(int (**)(...))&re.RegisterModel )
#undef  re_RegisterShader
#define re_RegisterShader          ( *(int (**)(...))&re.RegisterShader )
#undef  re_GetShaderName
#define re_GetShaderName           ( *(int (**)(...))&re.GetShaderName )
#undef  re_SetIgnorePrecacheErrors
#define re_SetIgnorePrecacheErrors ( *(int (**)(...))&re.SetIgnorePrecacheErrors )
#undef  re_AddRefEntityToScene
#define re_AddRefEntityToScene     ( *(int (**)(...))&re.AddRefEntityToScene )
#undef  re_AddPolyToScene
#define re_AddPolyToScene          ( *(int (**)(...))&re.AddPolyToScene )
#else
#define FX_ANYARGS
#endif
/* Dinkumware's comparison operators return bool (a char in the C build). */
#ifdef __cplusplus
#define FX_BOOL bool
#else
#define FX_BOOL char
#endif
/* VC7 scalar fill carries the actual allocator reference and an empty dispatch tag. */
typedef struct {void *pointer;} FxIntAllocatorReference;
/* The real tag is a one-byte empty C++ object: C storage is unnamed padding only. */
typedef struct {unsigned char :8;} FxScalarPointerTag;
typedef char FxScalarPointerTagSizeProof[sizeof(FxScalarPointerTag)==1?1:-1];
static __inline FxIntAllocatorReference FxIntAllocator(void *pointer){FxIntAllocatorReference arg;arg.pointer=pointer;return arg;}
static __inline FxScalarPointerTag FxScalarPointerCategory(void){FxScalarPointerTag tag;return tag;}
typedef struct {int value;} FxMediaHandleArgument;

/* ---- module-owned globals ---- */
char *fxModelRegistrations;   /* 0x01407324 */
int fxActiveCount;
int fxDrawnCount;
int fxActiveEffectsInitialized;   /* 0x01407314 */
int fxPrimitiveTemplatePlayCount;   /* 0x01407318 */
int fxPrimitiveSpawnCount;   /* 0x0140731C */
int fxBoltFrames;   /* 0x01407320 */
int fxMemHighWaterBytes;   /* 0x01407328 */
/* fxSchedulerEffectIdsHead (0x0140C9A4), fxSchedulerScheduledEffectsHead
 * (0x0140C9B0) and fxScheduledCount (0x0140C9B4) are fields of
 * theFxScheduler; fx_types.h aliases them. */
int fxFreeListHead;
/* retail .rdata error strings; extern keeps C++ const data externally linked */
extern const char fx_errSaveEffectNameTooLong[] = "\x15" "Found effect name > 255 characters while saving effects state\n";   /* 0x00559C88 */
extern const char fx_errSaveOutOfMemory[] = "\x15Saving FX system state: out of memory (%i bytes exceeded on writing %i byte(s))\n";   /* 0x00559FE0 */
extern const char fx_errLoadStateReadPastEnd[] = "\x15Loading FX system state: read past the end of the buffer\n";   /* 0x0055A034 */


#define FXS_BX(s)       ( (unsigned char *)(s) + 4 )
#define FXS_SIZE(s)     ( *(unsigned int *)( (unsigned char *)(s) + 20 ) )
#define FXS_RES(s)      ( *(unsigned int *)( (unsigned char *)(s) + 24 ) )
#define FXS_PTR(s)      ( 16 <= FXS_RES(s) ? *(unsigned char **)FXS_BX(s) : FXS_BX(s) )
/* _Tidy() in Dinkumware form: _Myres = 15; _Eos(0) = _Myptr()[_Mysize = 0] = char().
 * The _Myptr() test on the just-stored capacity folds away but sets VC7's store schedule. */
#define FXS_TIDYINIT(s) { FXS_RES(s) = 15; FXS_PTR(s)[FXS_SIZE(s) = 0] = 0; }

#define FXN_LEFT(n)     ( *(unsigned char **)( (unsigned char *)(n) +  0 ) )
#define FXN_PARENT(n)   ( *(unsigned char **)( (unsigned char *)(n) +  4 ) )
#define FXN_RIGHT(n)    ( *(unsigned char **)( (unsigned char *)(n) +  8 ) )
#define FXN_KEY(n)      ( (unsigned char *)(n) + 12 )
#define FXN_MAPPED(n)   ( *(int *)( (unsigned char *)(n) + 40 ) )
#define FXN_COLOR(n)    ( *( (unsigned char *)(n) + 44 ) )
#define FXN_ISNIL(n)    ( *( (unsigned char *)(n) + 45 ) )

#define FX_RED          0
#define FX_BLACK        1

#define FXT_HEAD(t)     ( *(unsigned char **)( (unsigned char *)(t) + 4 ) )
#define FXT_SIZE(t)     ( *(unsigned int  *)( (unsigned char *)(t) + 8 ) )

#define FX_MAP_PAIR_SIZE   32
#define FXP_MAPPED(p)      ( *(int *)( (unsigned char *)(p) + 28 ) )

typedef struct DObj_s {
    void          *tree;                      /* +0x00  XAnimTree *          */
    void          *evalStorage;               /* +0x04                       */
    int            skelCacheKey;              /* +0x08  vs com_skelTimeStamp */
    unsigned char *partRemapTable;            /* +0x0C                       */
    unsigned short unknownState10;            /* +0x10                       */
    unsigned short scrNotifyId;               /* +0x12                       */
    unsigned short tracePartRemapHandle;      /* +0x14                       */
    unsigned char  childCount;                /* +0x16                       */
    unsigned char  partCount;                 /* +0x17  total bones, < 128   */
    unsigned int   childRefs[8];              /* +0x18  XModel * per child   */
    short          childModelIndices[8];      /* +0x38                       */
    unsigned char  childParentPartIndices[8]; /* +0x48  0xFF == unparented   */
    unsigned char  childPartBaseIndices[8];   /* +0x50                       */
} DObj;

char __cdecl FX_GetBoneOrientation( unsigned int *bolt, float *out );

void AxisCopy( float in[3][3], float out[3][3] );
void CM_Trace( void *results, const float *start, const float *end,
               const float *mins, const float *maxs, int model,
               const float *origin, int brushmask, int capsule,
               const void *sphere );
extern qboolean CM_TraceBox( const float *start, const float *end,
                             const float *mins, const float *maxs,
                             float fraction );
extern void *Com_PickSoundAlias( const char *name, int source );
int Com_SoundAliasIndex( const void *alias, int source );   /* universal/com_sndalias.c */
float __cdecl Com_RandFloatRange_m( float lo, float hi );   /* Raven flrand: returns float (universal/com_memory.c still says double) */
void __cdecl DObjCalcAnim( void *dobj, unsigned int *requestBits );
void __cdecl DObjCalcSkel( const unsigned int *partBits, void *dobj );
void __cdecl DObjCreate( const void *models, unsigned short modelCount, void *tree,
                         void *dobj, unsigned short scrNotifyId );
int __cdecl DObjFree( unsigned int releaseTree, void *dobj );
void *Hunk_AllocAlignInternal( int size, int align );
int __cdecl MSS_PlaySoundAlias_Internal( void *alias, float *alias2, float blend,
                                         int entnum, float *origin, int *outChan,
                                         int startMs );
void __cdecl MakeNormalVectors( const float *forward, float *right, float *up );
extern int R_CreateBufferARB();
void RotatePointAroundVector( float *dst, const float *dir, const float *point,
                              float degrees );
float VectorNormalize2( const float *v, float *out );
/* std::exception is LIBCMT's class (see the <stdexcept> block ahead of
 * std::logic_error). */
extern int j__atol( const char *s );
/* Marks the end of a fatal error path (Com_Error does not return): retail threw there. */
#ifdef _MSC_VER
#define FX_NORETURN_POINT __assume( 0 )
#else
#define FX_NORETURN_POINT ( (void)0 )
#endif
void j__free( void *block );
int *__stdcall FxPool_AllocPrimType14( int *pool, int size );
unsigned int *__fastcall FxPool_FreePrimType14( int *pool, char *element );
int *__stdcall FxPool_AllocLight( int *pool, int size );
int *__stdcall FxPool_AllocParticle( int *pool, int size );
int *__stdcall FxPool_AllocLine( int *pool, int size );
int *__stdcall FxPool_AllocElectricity( int *pool, int size );
int *__stdcall FxPool_AllocOrientedParticle( int *pool, int size );
int *__stdcall FxPool_AllocTail( int *pool, int size );
int *__stdcall FxPool_AllocCylinder( int *pool, int size );
int *__stdcall FxPool_AllocEmitter( int *pool, int size );
int *__stdcall FxPool_AllocFlash( int *pool, int size );
typedef struct { void *value; } GpPointerArgument;
/* memorytree.cpp's CGenericParser2 (0x38 bytes: CGPGroup mTopLevel, mTextPool
 * +0x30, mWriteable +0x34); the constructor is retail 0x004A2930, which
 * RegisterEffect inlines, the destructor 0x004A2960. */
struct CGenericParser2
{
  int gp[14];
  CGenericParser2()
  {
    gp[0] = (int)"Top Level";
    gp[1] = 0;
    gp[2] = 0;
    gp[3] = 0;
    gp[4] = 0;
    gp[5] = 0;
    gp[6] = 0;
    gp[7] = 0;
    gp[8] = 0;
    gp[9] = 0;
    gp[10] = 0;
    *( (char *)&gp[11] ) = 0;
    gp[12] = 0;
    *( (char *)&gp[13] ) = 0;
  }
  ~CGenericParser2();
};
char __stdcall CGenericParser2__Parse( int this_, char **dataPtr, char cleanFirst,
                                     char writeable );
void vectoangles( const float *value1, float *angles );

#define FX_BLOCK_SIZE       0x8000
#define FX_ARENA_SIZE       0x200000
#define FX_BLOCK_HDR        0x7FF0
#define FX_HDR_FREECOUNT    32752
#define FX_HDR_FREELIST     32756
#define FX_HDR_PREV         32760
#define FX_HDR_NEXT         32764

int     __cdecl   FxMem_Init( void );
int     __stdcall FxMem_Init_ctor_m( int self );
unsigned int *__cdecl   FxMem_ClaimBlock_m( int count, int elemSize, int prev );
int    *__stdcall   FxPool_AllocBoltFrame( int *pool, int elemSize );
int    *__stdcall   FxPool_AllocModel( int *pool, int elemSize );

unsigned int *__fastcall FxPool_FreeBoltFrame( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeModel( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeEffect( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeLight( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeParticle( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeLine( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeElectricity( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeOrientedParticle( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeTail( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeCylinder( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeEmitter( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeDecal( int *pool, char *p );
unsigned int *__fastcall FxPool_FreePrimitiveTemplate( int *pool, char *p );
unsigned int *__fastcall FxPool_FreeScheduledEffect( int *pool, char *p );

/* stl_fxEffectIdMap_insert_m's stub is __stdcall; declared here so stl_fxEffectIdMap_index_m's call does not
 * implicitly declare a cdecl one that collides with the definition below. */
int     __stdcall  stl_fxEffectIdMap_insert_m( int a1, int a2, void ***a3 );
int     __stdcall  stl_fxEffectIdMap_index_m( int tree, const FxStdString &key );
void __fastcall stl_fxEffectIdMap_eraseSubtree_m(void *receiver,FxMapRootValue root);
__inline void __fastcall stl_fxEffectIdMap_iterInc_m(int **pptr);
unsigned int *__stdcall  stl_fxScheduledList_buynodeHead_m( int list );
unsigned int *__stdcall  stl_fxScheduledList_buynodeVal_m( int list, int next, int prev, unsigned int *val );
#ifdef __cplusplus
/* list::_Incsize keeps its C++ member form (this = the list), which LTCG
 * gives retail's count@ecx, this@edx convention. */
struct FxScheduledList { int Incsize( unsigned int n ); };
#define stl_fxScheduledList_incsize_m( n, list ) ( ( (struct FxScheduledList *)(list) )->Incsize( (n) ) )
#else
int     __fastcall stl_fxScheduledList_incsize_m( unsigned int n, int list );
#endif
unsigned int *__stdcall  stl_fxEffectIdMap_buynodeHead_m( int tree );
__inline void __fastcall stl_fxEffectIdMap_iterDec_m(int **pptr);
int **__fastcall stl_fxEffectIdMap_eraseRange_m(int tree,FxMapIteratorValue resultArg,FxMapIteratorValue firstArg,FxMapIteratorValue lastArg);
int   **__stdcall  stl_fxEffectIdMap_eraseNode_m( int tree, int **result, int *where );
struct FxListIter { unsigned int *node; FxListIter( unsigned int *n ) : node( n ) {} };   /* list::iterator: has a constructor, so returned through a hidden pointer */
FxListIter __fastcall stl_fxScheduledList_eraseRange_m(int list,FxListIteratorArgument firstArg,FxListIteratorArgument lastArg);
__declspec(noinline) void    __stdcall  stl_fxIntVector_xlen_m( int vec );
int     __stdcall  stl_fxEffectIdMap_lrotate_m( int node_, int tree );
int     __stdcall  stl_fxEffectIdMap_rrotate_m( int node_, int tree );
int     __cdecl    stl_fxEffectIdMap_max_m( int node );

struct FxVecIter
{
  unsigned int *ptr;
  FxVecIter( unsigned int *p ) : ptr( p ) {}
  FxVecIter( const FxVecIter &right ) : ptr( right.ptr ) {}
};   /* vector::iterator (_Ptrit): has a constructor, so returned through a hidden pointer */
/* std::vector<int> (VC7 Dinkumware) as the scheduler's media lists use it:
 * _Insert_n(where, count, val) and _Ucopy(first, last, ptr) are __thiscall
 * (retn 0Ch); iterators are constructed straight into their argument slots. */
struct FxIntVector
{
  unsigned char alval[4];   /* +0x00  _Alval: allocator<int> (empty) */
  unsigned int       *myfirst;    /* +0x04 */
  unsigned int       *mylast;     /* +0x08 */
  unsigned int       *myend;      /* +0x0C */

  void    InsertN( FxVecIter where, unsigned int count, const unsigned int &val );
  unsigned int *Ucopy( FxVecIter first, FxVecIter last, unsigned int *ptr );        /* _Ucopy<iterator> */
};
inline unsigned int *__cdecl UcopyConst( FxIntVector *self, FxVecIter first, FxVecIter last, unsigned int *ptr );   /* _Ucopy, inlined copy */
#define stl_fxIntVector_insertN_m( vec, whereArg, countArg, valueArg ) \
  ( ( (struct FxIntVector *)(vec) )->InsertN( FxVecIter( (unsigned int *)(whereArg).pointer ), (countArg).count, \
                                              *(const unsigned int *)(valueArg).pointer ) )
/* vector<int>::push_back( *valPtr ) as LTCG inlines it. */
#define FX_INT_PUSH_BACK( vecPtr, valPtr ) \
  { \
    unsigned int      *vec_      = (unsigned int *)(vecPtr); \
    unsigned int size_     = !vec_[1] ? 0 : (unsigned int)( (int)( vec_[2] - vec_[1] ) >> 2 ); \
    unsigned int capacity_ = !vec_[1] ? 0 : (unsigned int)( (int)( vec_[3] - vec_[1] ) >> 2 ); \
    if ( size_ < capacity_ ) \
    { \
      unsigned int *end_ = (unsigned int *)vec_[2]; \
      stl_fxIntVector_uninitFillN_m( end_, 1u, (const unsigned int *)(valPtr), FxIntAllocator( (void *)vec_ ), \
                                     FxScalarPointerCategory() ); \
      vec_[2] = (unsigned int)( end_ + 1 ); \
    } \
    else \
    { \
      FxVecIter where_( (unsigned int *)vec_[2] );   /* end() */ \
      ( (struct FxIntVector *)vec_ )->InsertN( where_, 1, *(const unsigned int *)(valPtr) ); \
    } \
  }
/* CMediaHandles::AddHandle( int item ): mMediaList.push_back( item ), as LTCG
 * inlines it into the parsers' list loops. */
#define FX_MEDIA_ADD_HANDLE( vecPtr, val ) \
  { \
    int item_ = (int)(val); \
    FX_INT_PUSH_BACK( vecPtr, &item_ ) \
  }
/* fill(first, last, val) and copy_backward(first, last, dest) over vector<int> iterators. */
void      __cdecl stl_fxIntVector_fill_m( const unsigned int *pval, FxVecIter first, FxVecIter last );
FxVecIter __cdecl stl_fxIntVector_copyBackward_m( FxVecIter first, FxVecIter last, FxVecIter dest );
void __cdecl stl_fxIntVector_uninitFillN_m(unsigned int *dest,unsigned int count,const unsigned int *pval,FxIntAllocatorReference allocatorArg,FxScalarPointerTag scalarTag);
/* VC7.0 vector<int>::iterator (_Ptrit): a one-pointer class passed by value. */
typedef struct { unsigned int *ptr; } fxIntVecIter;
unsigned int *__cdecl   stl_fxIntVector_uninitCopy_m( FxVecIter first, FxVecIter last, unsigned int *dest,
                                                FxIntAllocatorReference al, FxNonscalarPointerTag tag );
char    __cdecl   stl_fxIntVector_buyAllocTail_m( unsigned int count, unsigned int *vec );

/* CFxScheduler__SaveState_m's per-effect archiver (called ahead of its body). */
void __cdecl CFxArchive__ArchiveScheduledEffect_m( int archive, unsigned __int16 *effect );

/* CFxArchive data members: void in retail, callee-pops its stack arguments. */
void __stdcall CFxArchive__ReadData( int count, unsigned int *archive, byte *dst );
void __stdcall CFxArchive__WriteData( int *archive, byte *data, int count );

/* Dinkumware string-compare and allocator shims with no callers in this
 * build (retail register conventions made explicit; see each body). */
FX_BOOL  __stdcall stl_fxStringLess_opCall_m( int left, int right, int unused );
char *__fastcall stl_fxString_myptr_m(unsigned int *self);
void    *__stdcall stl_fxScheduledList_nodeAllocate_m( unsigned int count, int unused1, int unused2 );
void    *__stdcall stl_fxIntVector_allocate_m( unsigned int count, int unused1, int unused2 );
void    *__stdcall stl_fxString_allocate_m( size_t Size, int hint );
void    *__stdcall stl_fxEffectIdMap_alnodAllocate_m( unsigned int count, int unused1, int unused2 );
FX_BOOL  __cdecl   stl_fxString_operatorLess_m( int left, int right );
void    *__cdecl   stl_fxScheduledList_allocate2_m( unsigned int count, void *hint );
void    *__cdecl   stl_fxIntVector_allocate2_m( unsigned int count, void *hint );
void    *__cdecl   stl_fxString_allocate2_m( size_t count, void *hint );
void    *__cdecl   stl_fxEffectIdMap_allocate2_m( unsigned int count, void *hint );
int      __cdecl   stl_fxString_compareStr_m( int self, int right );
/* std::string::compare(off, n0, ptr, count): retail callee-pops its stack arguments. */
int      __stdcall stl_fxString_compare_m( int self, unsigned int n0, unsigned int off,
                                           const char *ptr, unsigned int count );
/* Callers evaluate right.size() before right.c_str() (C++ right-to-left
 * argument order over two inline member calls); the C callers hoist the size
 * into a local to keep that order. */

void __stdcall   CFxScheduler__PlayEffect_id_axis( unsigned int *self, int id, float *org, int *axis, int *bolt );
void __stdcall   CFxScheduler__PlayEffect_id_fwd_m( unsigned int *self, int effectId, float *origin, int *forward );

char *__stdcall CFxScheduler__GetNewEffectTemplate( int *outId, char *name, int scheduler );
char *__stdcall CFxScheduler__CopyEffect_m( int effectId, int scheduler, int *outId );
char __stdcall CPrimitiveTemplate__ParsePrimitive( int self, int group );

char   __cdecl CParticle__UpdateOrigin( int self );
float *__cdecl CParticle__UpdateVelocity( float *self );
void   __cdecl CParticle__UpdateSize( int self );
void   __cdecl CParticle__UpdateSize2( int self );
void   __cdecl CParticle__UpdateAlpha( int self );
void   __cdecl CTail__UpdateLength_m( int self );
void   __cdecl CTail__CalcNewEndpoint_m( int self );
void __cdecl CEmitter__UpdateAngles_m( float *self );
void   __cdecl CLight__UpdateSize_m( int self );
void   __cdecl CLight__UpdateRGB_m( int self );

/* theFxHelper's cull planes (normal, dist), 16 bytes each from fxHelperCullPlane0NormalX. */
typedef struct { float normal[3]; float dist; } fxCullPlane_t;

char __stdcall SFxHelper__CullSphere( int unusedThis, float *origin, float radius );
char __stdcall SFxHelper__CullCylinder( int unusedThis, float *p1, float *p2,
                                        float radius1, float radius2 );
void __cdecl CFxBoltFrame__Release( char *self );

void __fastcall CEffect__dtor( void *self );
void __fastcall CParticle__dtor( void *self );
void __fastcall COrientedParticle__dtor( void *self );
void __fastcall CLine__dtor( void *self );
void __fastcall CElectricity__dtor( void *self );
void __fastcall CTail__dtor( void *self );
void __fastcall CCylinder__dtor( void *self );
void __fastcall CEmitter__dtor( void *self );
void __fastcall CLight__dtor( void *self );
void __fastcall CFlash__dtor( void *self );

#ifdef __cplusplus
/* std::map<std::string, int> (48-byte nodes), CFxScheduler::mEffectIDs.  Its
 * destructor (retail 0x004929F0, this@<eax>) is the COMDAT the constructor's
 * unwind funclet reaches; stringed's map<string, int> shares it. */
struct SeStrIntMap
{
  char           proxy;   /* +0x00  comparator (an empty object: one uninitialized byte) */
  unsigned char *head;    /* +0x04  _Myhead */
  unsigned int   size;    /* +0x08  _Mysize */
  SeStrIntMap()
  {
    FxStlAllocatorTag allocator;

    proxy = allocator.value;
    head = (unsigned char *)stl_fxEffectIdMap_buynodeHead_m( (int)this );
    FXN_ISNIL ( head ) = 1;
    FXN_PARENT( head ) = head;
    FXN_LEFT  ( head ) = head;
    FXN_RIGHT ( head ) = head;
    size = 0;
  }
  ~SeStrIntMap()
  {
    void          *erased;
    unsigned char *h;

    stl_fxEffectIdMap_eraseRange_m( (int)this, FxMapIteratorArgument( (void *)&erased ), FxMapIteratorArgument( FXN_LEFT( head ) ), FxMapIteratorArgument( head ) );
    h = head;
    operator delete( h );
    head = 0;
    size = 0;
  }
};
/* std::list<SScheduledEffect *>, CFxScheduler::mFxSchedule: the last member, so
 * nothing after it needs its destructor. */
struct FxScheduledListObj
{
  char           alloc;   /* +0x00 */
  unsigned int        *head;    /* +0x04  _Myhead */
  unsigned int   size;    /* +0x08  _Mysize */
  FxScheduledListObj()
  {
    head = stl_fxScheduledList_buynodeHead_m( (int)this );
    size = 0;
  }
};
/* CFxScheduler::CreateEffect keeps its C++ member form: __thiscall (this@ecx,
 * five stack arguments, retn 14h). */
struct CFxScheduler
{
  unsigned char      mEffectTemplates[FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET];   /* SEffectTemplate[128] */
  SeStrIntMap        mEffectIDs;    /* +0x5400 */
  FxScheduledListObj mFxSchedule;   /* +0x540C */
  CFxScheduler();
  void CreateEffect( int tmpl, int *bolt, float *origin, float *axisIn, int timeOffset );
  int  RegisterEffect( const char *file, bool isPath );   /* __thiscall, retn 8 */
};
#define CFxScheduler__CreateEffect( self, tmpl, bolt, origin, axisIn, timeOffset ) \
  ( ( (struct CFxScheduler *)(self) )->CreateEffect( (tmpl), (bolt), (origin), (axisIn), (timeOffset) ) )
#define CFxScheduler__RegisterEffect( self, file, isPath ) \
  ( ( (struct CFxScheduler *)(self) )->RegisterEffect( (file), (isPath) != 0 ) )
#else
int __cdecl CFxScheduler__RegisterEffect( unsigned int *thisObj, char *Source, char isPath );
void __cdecl CFxScheduler__CreateEffect( unsigned int *self, int tmpl, int *bolt,
                                         float *origin, float *axisIn, int timeOffset );
#endif
void SFxHelper__Print( int unusedThis, char *Format, ... );

int __cdecl FX_AddParticle( char **bolt, int org, float *vel, float *accel, char useSize2, int sizeStart, int sizeEnd, float sizeParm, int size2Start, int size2End, float size2Parm, int alphaStart, int alphaEnd, float alphaParm, unsigned int *rgbStart, unsigned int *rgbEnd, float rgbParm, int rotation, int rotationDelta, unsigned int *mins, unsigned int *maxs, int elasticity, int deathFxId, int impactFxId, int killTime, int shader, unsigned int inFlags );
typedef struct {float *value;} FxTailLineVectorPointer;
static FxTailLineVectorPointer FxTailLineVectorArgument(float *p){FxTailLineVectorPointer a;a.value=p;return a;}
int __cdecl FX_AddLine(
        char **bolt,
        int start,
        FxTailLineVectorPointer endArg,
        int sizeStart,
        int sizeEnd,
        float sizeParm,
        int alphaStart,
        int alphaEnd,
        float alphaParm,
        unsigned int *rgbStart,
        unsigned int *rgbEnd,
        float rgbParm,
        int killTime,
        int shader,
        int flags);
int __cdecl FX_AddElectricity( char **bolt, int start, float *end, int sizeStart, int sizeEnd, float sizeParm, int alphaStart, int alphaEnd, float alphaParm, unsigned int *rgbStart, unsigned int *rgbEnd, float rgbParm, int chaos, int killTime, int shader, int flags );
typedef struct {float *value;} FxTailMotionVectorPointer;
static FxTailMotionVectorPointer FxTailMotionVectorArgument(float *p){FxTailMotionVectorPointer a;a.value=p;return a;}
int __cdecl FX_AddTail(
        char **bolt,
        int org,
        FxTailMotionVectorPointer velArg,
        FxTailMotionVectorPointer accelArg,
        int sizeStart,
        int sizeEnd,
        float sizeParm,
        int lengthStart,
        int lengthEnd,
        float lengthParm,
        int alphaStart,
        int alphaEnd,
        float alphaParm,
        unsigned int *rgbStart,
        unsigned int *rgbEnd,
        float rgbParm,
        unsigned int *mins,
        unsigned int *maxs,
        int elasticity,
        int deathFxId,
        int impactFxId,
        int killTime,
        int shader,
        int flags);
int __cdecl FX_AddCylinder( char **bolt, int start, float *normal, int sizeStart, int sizeEnd, float sizeParm, int size2Start, int size2End, float size2Parm, int lengthStart, int lengthEnd, float lengthParm, int alphaStart, int alphaEnd, float alphaParm, unsigned int *rgbStart, unsigned int *rgbEnd, float rgbParm, int killTime, int shader, int flags );
int __cdecl FX_AddEmitter( int org, char **bolt, float *vel, float *accel, int sizeStart, int sizeEnd, float sizeParm, int alphaStart, int alphaEnd, float alphaParm, unsigned int *rgbStart, unsigned int *rgbEnd, float rgbParm, unsigned int *angles, unsigned int *angleDelta, unsigned int *mins, unsigned int *maxs, int elasticity, int deathFxId, int impactFxId, int emitterFxId, int density, int variance, int killTime, int model, unsigned int inFlags );
int __cdecl FX_AddLight( char **bolt, float *org, float sizeStart, float sizeEnd, float sizeParm, unsigned int *rgbStart, unsigned int *rgbEnd, float rgbParm, int killTime, int flags );
int __cdecl FX_AddOrientedParticle( char **bolt, int normal, int org, float *vel, float *accel, char useSize2, int sizeStart, int sizeEnd, float sizeParm, int size2Start, int size2End, float size2Parm, int alphaStart, int alphaEnd, float alphaParm, unsigned int *rgbStart, unsigned int *rgbEnd, float rgbParm, int rotation, int rotationDelta, unsigned int *mins, unsigned int *maxs, int elasticity, int deathFxId, int impactFxId, int killTime, int shader, unsigned int inFlags );
int __cdecl FX_AddFlash( unsigned int *org, unsigned int *rgbStart, unsigned int *rgbEnd, float rgbParm, int killTime, int shader, int flags );

int *__stdcall FxMem_AllocScheduledEffect( int *pool, int elemSize );

int *__stdcall FxPool_AllocPrimitiveTemplate( int *pool, int elemSize );

typedef void *( *XModelAllocFn )( int size );
void *XModelPrecache( const char *name, int loadSurfaces, XModelAllocFn alloc,
                      XModelAllocFn allocMesh );
void *__cdecl FxModelAlloc_m( unsigned int size );

char *__cdecl CFxModel__Register( char *name );

/* Prototypes for members defined further down that earlier code calls (the
 * C front end took them from the later definitions; C++ needs them first). */
/* basic_string::assign(right, roff, count) keeps its C++ member form: __thiscall
 * (this@ecx, three stack arguments, retn 0Ch; callers push 0 / -1 as immediates). */
struct FxString
{
  void        *unused0;                       /* +0x00  allocator slot */
  union { int bufw[4]; char *ptr; } bx;     /* +0x04  small-string buffer or heap pointer */
  unsigned int size;                          /* +0x14 */
  unsigned int capacity;                      /* +0x18 */
  int Assign( const void *right, unsigned int roff, unsigned int count );
  int Erase( unsigned int off, unsigned int count );   /* erase(off, count): __thiscall, retn 8 */
  bool Grow( unsigned int n, bool trim );           /* _Grow(n, trim): __thiscall, retn 8 */
  void Copy( unsigned int n, unsigned int oldlen );  /* _Copy(n, oldlen): __thiscall, retn 8 */
  /* <xstring>'s inline helpers; defined where retail kept their out-of-line copies */
  inline const char *Myptr() const;              /* _Myptr() const */
  inline void Eos( unsigned int newsize );       /* _Eos(newsize) */
  inline void Tidy( bool built = false );        /* _Tidy(built) */
};
#define stl_fxString_erase_m( self, off, count ) ( ( (struct FxString *)(self) )->Erase( (off), (count) ) )
#define stl_fxString_grow_m( self, n, trim ) ( ( (struct FxString *)(self) )->Grow( (n), (trim) ) )
#define stl_fxString_copy_m( self, n, oldlen ) ( ( (struct FxString *)(self) )->Copy( (n), (oldlen) ) )
}   /* extern "C" */
/* map<string, int>::value_type */
namespace std
{
template<class _Ty1, class _Ty2> struct pair;
template<> struct pair<const FxStdString, int>
{
  const FxStdString first;
  int               second;
  pair( const FxStdString &val1, const int &val2 );
  ~pair();
};
}
typedef std::pair<const FxStdString, int> FxEffectIdValue;
extern "C" {
/* map<string,int> value_type: pair<const string, int>; Construct is its copy
 * constructor as inlined into the node constructor. */
struct FxMapPair
{
  FxString first;
  int      second;
  void Construct( const FxMapPair *right )
  {
    FXS_TIDYINIT( &first );
    first.Assign( &right->first, 0, 0xFFFFFFFF );
    second = right->second;
  }
};
/* map<string,int>::_Node(left, parent, right, val, color), placement-constructed by _Buynode. */
struct FxMapNode
{
  FxMapNode( int left, int parent, int right, int val, char color )
  {
    FXN_LEFT( this )   = (unsigned char *)left;
    FXN_PARENT( this ) = (unsigned char *)parent;
    FXN_RIGHT( this )  = (unsigned char *)right;
    ( (FxMapPair *)FXN_KEY( this ) )->Construct( (const FxMapPair *)val );   /* _Myval(val) */
    FXN_COLOR( this )  = color;
    FXN_ISNIL( this )  = 0;
  }
  void *operator new( size_t, void *where ) { return where; }
};
#define stl_fxString_assignSubstr_m( self, src, off, count ) \
  ( ( (struct FxString *)(self) )->Assign( (const void *)(src), (off), (count) ) )
int   __cdecl    stl_fxScheduledList_pushBack_m( unsigned int *value, int list );
int   __cdecl    stl_fxEffectIdMap_nodeDtor_m( int node );
int **__cdecl    stl_fxEffectIdMap_lowerBound_m( int **result, int tree, int key );
int   __fastcall stl_fxEffectIdMap_lbound_m( int tree, const void *keyObject );
int   __fastcall stl_fxEffectIdMap_insertRebalance_m( int tree, int wherenode, FxRebalanceResult resultArg,
                                                      unsigned char directionArg, FxRebalanceValue valueArg );
struct FxMapIter { unsigned char *node; FxMapIter( unsigned char *n ) : node( n ) {} };   /* map::iterator: returned through a hidden pointer */
FxMapIter __cdecl stl_fxEffectIdMap_find_m( int tree, int key );
int   __stdcall  stl_fxEffectIdMap_buynode_m( int tree, int left, int parent, int right, int val, char colour );
void  __stdcall  SFxHelper__PlaySound( int aliasIndex, const void *helper, float *origin, int entnum );
void  __stdcall  SFxHelper__AddLightToScene( int unusedThis, const float *origin, float intensity,
                                             float red, float green, float blue );
int __cdecl FxPool_MakeBlockCurrentBoltFrame( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentModel( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentLight( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentParticle( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentLine( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentElectricity( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentOrientedParticle( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentTail( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentCylinder( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentEmitter( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentDecal( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentPrimitiveTemplate( int pool, int block );
int __cdecl FxPool_MakeBlockCurrentScheduledEffect( int pool, int block );
void  __cdecl    CPrimitiveTemplate__copy_m( char *dst, char *src );
int   __cdecl    CParticle__UpdateRotation( int self );
int   __cdecl    CParticle__UpdateRGB( int self );
int   __stdcall  CFxScheduler__ParseEffect( char *effectName, int scheduler, int *parseTree );

/*
 * FxArchive -- the FX system's RLE-compressed save/load buffer.  Read and
 * write archives share this layout; `reading` / `writing` select the mode and
 * `table` is the per-archive shader / effect-id remap.  The RLE codec state
 * lives in the last three ints (see CFxArchive__ReadData / CFxArchive__WriteData).
 * File-local reconstruction; offsets pinned with COD1_STATIC_ASSERT below.
 */
typedef struct FxArchive_s
{
    unsigned char *buffer;          /* +0x0000  backing byte buffer             */
    int            size;            /* +0x0004  buffer capacity in bytes        */
    int            pos;             /* +0x0008  current byte offset in buffer    */
    unsigned char  reading;         /* +0x000C  nonzero: read (decode) mode      */
    unsigned char  writing;         /* +0x000D  nonzero: write (encode) mode     */
    unsigned short _pad0E;          /* +0x000E                                   */
    int            bytesProcessed;  /* +0x0010  running logical byte count       */
    int            table[1800];     /* +0x0014  shader / effect-id remap         */
    int            rleState;        /* +0x1C34  decode: current run kind         */
    int            rleCount;        /* +0x1C38  decode: bytes left in run         */
    int            rleMarker;       /* +0x1C3C  encode: offset of open run byte   */
} FxArchive;

COD1_STATIC_ASSERT( offsetof( FxArchive, size )           ==    4, "FxArchive.size @ 4" );
COD1_STATIC_ASSERT( offsetof( FxArchive, pos )            ==    8, "FxArchive.pos @ 8" );
COD1_STATIC_ASSERT( offsetof( FxArchive, reading )        ==   12, "FxArchive.reading @ 12" );
COD1_STATIC_ASSERT( offsetof( FxArchive, writing )        ==   13, "FxArchive.writing @ 13" );
COD1_STATIC_ASSERT( offsetof( FxArchive, bytesProcessed ) ==   16, "FxArchive.bytesProcessed @ 16" );
COD1_STATIC_ASSERT( offsetof( FxArchive, table )          ==   20, "FxArchive.table @ 20" );
COD1_STATIC_ASSERT( offsetof( FxArchive, rleState )       == 7220, "FxArchive.rleState @ 7220" );
COD1_STATIC_ASSERT( offsetof( FxArchive, rleCount )       == 7224, "FxArchive.rleCount @ 7224" );
COD1_STATIC_ASSERT( offsetof( FxArchive, rleMarker )      == 7228, "FxArchive.rleMarker @ 7228" );
COD1_ASSERT_SIZE( FxArchive, 7232 );

/* The primitives' virtual Archive( CFxArchive & ), vftable slot 6 (+24): only
 * declared, so no vftable is emitted for this view. */
struct FxArchivable
{
  virtual void Slot0();
  virtual void Slot1();
  virtual void Slot2();
  virtual void Slot3();
  virtual void Slot4();
  virtual void Slot5();
  virtual void Archive( FxArchive *ar );
};

/* ---- CFxArchive__ReadByte_m  0x0048CB30 ----  VERIFIED */
char __cdecl CFxArchive__ReadByte_m(int unusedReg, unsigned int *archive)
{
  char value; // BYREF (filled by ReadData; unusedReg is an unused register artifact)

  CFxArchive__ReadData(1, archive, (byte *)&value);
  return value;
}

/* ---- CFxArchive__ReadShort_m  0x0048CB50 ----  [HIGH] */
__int16 __cdecl CFxArchive__ReadShort_m(int unusedReg, unsigned int *archive)
{
  int value; // BYREF (low 2 bytes filled by ReadData)

  CFxArchive__ReadData(2, archive, (byte *)&value);
  return value;
}

/* ---- CFxArchive__WriteByte_m  0x0048CB70 ----  [HIGH] */
void __stdcall CFxArchive__WriteByte_m(int *archive, char value)
{
  CFxArchive__WriteData(archive, (byte *)&value, 1);
}

/* ---- CFxArchive__WriteShort_m  0x0048CB80 ----  [HIGH] */
void __stdcall CFxArchive__WriteShort_m(int *archive, char value)
{
  CFxArchive__WriteData(archive, (byte *)&value, 2);
}

/* ---- CFxArchive__ctor  0x0048CB90 ----  [HIGH] */
int __cdecl CFxArchive__ctor(int self)
{
  FxArchive *ar = (FxArchive *)self;

  ar->buffer         = NULL;
  ar->size           = 0;
  ar->pos            = 0;
  ar->reading        = 0;
  ar->writing        = 0;
  ar->bytesProcessed = 0;
  ar->rleMarker      = 0;
  ar->rleState       = 0;
  ar->rleCount       = 0;
  return self;
}

/* ---- CFxArchive__BeginReading  0x0048CBC0 ----  VERIFIED */
int __cdecl CFxArchive__BeginReading(int buffer, int self, int size)
{
  FxArchive *ar = (FxArchive *)self;

  ar->buffer         = (unsigned char *)buffer;
  ar->size           = size;
  ar->pos            = 0;
  ar->reading        = 1;
  ar->writing        = 0;
  ar->bytesProcessed = 0;
  ar->rleMarker      = 0;
  ar->rleState       = 0;
  ar->rleCount       = 0;
  memset(ar->table, 0, sizeof(ar->table));
  return 0;
}

/* ---- CFxArchive__BeginWriting  0x0048CC00 ----  VERIFIED */
int __cdecl CFxArchive__BeginWriting(int self, int size, int buffer)
{
  FxArchive *ar = (FxArchive *)self;

  ar->buffer         = (unsigned char *)buffer;
  ar->size           = size;
  ar->pos            = 0;
  ar->reading        = 0;
  ar->writing        = 1;
  ar->bytesProcessed = 0;
  ar->rleMarker      = 0;
  ar->rleState       = 0;
  ar->rleCount       = 0;
  return self;
}

/* ---- CFxArchive__MapEffectID  0x0048CC30 ----  [HIGH] */
int __cdecl CFxArchive__MapEffectID(int self, int index, int value)
{
  FxArchive *ar = (FxArchive *)self;

  ar->table[index] = value;
  return self;
}

/* ---- CFxArchive__ReadEffectID  0x0048CC40 ----  VERIFIED */
int __cdecl CFxArchive__ReadEffectID(unsigned int *archive)
{
  FxArchive *ar = (FxArchive *)archive;
  __int16    index; // BYREF

  CFxArchive__ReadData(2, archive, (byte *)&index);
  return ar->table[index];
}

/* ---- CFxArchive__ReadShader_m  0x0048CC60 ----  VERIFIED */
int __cdecl CFxArchive__ReadShader_m(unsigned int *thisObj)
{
  int             len;
  unsigned __int8 nameLen;   // BYREF
  byte           name[64];  // BYREF

  CFxArchive__ReadData(1, thisObj, &nameLen);
  if ( !nameLen || nameLen >= 0x40u )
    return 0;
  len = nameLen;
  CFxArchive__ReadData(nameLen, thisObj, name);
  *(name + len) = 0;   /* retail 0x0048CCA5: no bound check; pointer store avoids the /GS range check */
  return re_RegisterShader(name, 9);
}

/* ---- CFxArchive__ReadEffectID_m  0x0048CCE0 ----  VERIFIED */
char *__cdecl CFxArchive__ReadEffectID_m(unsigned int *thisObj)
{
  int             len;
  unsigned __int8 nameLen;   // BYREF
  char            name[64];  // BYREF

  CFxArchive__ReadData(1, thisObj, &nameLen);
  if ( !nameLen || nameLen >= 0x40u )
    return 0;
  len = nameLen;
  CFxArchive__ReadData(nameLen, thisObj, (byte *)name);
  *(name + len) = 0;   /* retail 0x0048CD23: no bound check; pointer store avoids the /GS range check */
  return CFxModel__Register(name);
}

/* ---- CFxArchive__ReadData  0x0048CD60 ----  [HIGH] */
/* RLE decoder for CFxArchive__WriteData's stream: rleState literals, then
 * rleCount zeros, then the next tag. */
void __stdcall CFxArchive__ReadData(int count, unsigned int *archive, byte *dst)
{
  FxArchive     *ar = (FxArchive *)archive;
  unsigned char  tag;

  ar->bytesProcessed += count;
  while ( 1 )
  {
    while ( ar->rleState )
    {
      ar->rleState--;
      count--;
      if ( ar->pos >= ar->size )
        Com_Error(ERR_DROP, fx_errLoadStateReadPastEnd);
      *dst++ = ar->buffer[ar->pos];
      ar->pos++;
      if ( !count )
        return;
    }
    while ( ar->rleCount && count )
    {
      ar->rleCount--;
      count--;
      *dst++ = 0;
      if ( !count )
        return;
    }
    if ( ar->pos >= ar->size )
      Com_Error(ERR_DROP, fx_errLoadStateReadPastEnd);
    tag = ar->buffer[ar->pos];
    ar->pos++;
    switch ( tag & 0xC0 )
    {
    case 0x00:
      ar->rleState = 1;
      ar->rleCount = (tag & 0x3F) + 1;
      break;
    case 0x40:
      ar->rleState = 2;
      ar->rleCount = (tag & 0x3F) + 1;
      break;
    case 0x80:
      ar->rleState = 4;
      ar->rleCount = (tag & 0x3F) + 1;
      break;
    default:
      ar->rleState = (tag & 0x3F) + 1;
      ar->rleCount = 0;
      break;
    }
  }
}

/* ---- CFxArchive__WriteEffectID  0x0048CEA0 ----  VERIFIED */
void __cdecl CFxArchive__WriteEffectID(int effectIndex, int *archive)
{
  int value; // BYREF

  value = effectIndex;
  CFxArchive__WriteData(archive, (byte *)&value, 2);
}

/* ---- CFxArchive__WriteShader_m  0x0048CEC0 ----  VERIFIED */
void __cdecl CFxArchive__WriteShader_m(int shader, int *archive)
{
  char *name;
  int   len;
  byte lenByte[4]; // BYREF

  name = (char *)re_GetShaderName(shader);
  if ( !name )
    name = "";
  len = strlen(name);
  lenByte[0] = len;
  CFxArchive__WriteData(archive, lenByte, 1);
  if ( len )
    CFxArchive__WriteData(archive, (byte *)name, len);
}

/* ---- CFxArchive__WriteEffectID_m  0x0048CF10 ----  VERIFIED */
void __cdecl CFxArchive__WriteEffectID_m(int effectId, int *archive)
{
  char *name;
  int   len;
  byte lenByte[4]; // BYREF

  if ( !effectId || !(name = (char *)(effectId - 64)) )
    name = "";
  len = strlen(name);
  lenByte[0] = len;
  CFxArchive__WriteData(archive, lenByte, 1);
  if ( len )
    CFxArchive__WriteData(archive, (byte *)name, len);
}

/* ---- CFxArchive__WriteData  0x0048CF60 ----  [CONFIRMED] */
/* RLE encoder: a 0xC0|n tag opens n+1 literals; a 0x00/0x40/0x80|n tag
 * holds 1/2/4 literals followed by n+1 zeros.  The guarded do-while loops
 * give retail's rotated inner loops. */
void __stdcall CFxArchive__WriteData(int *archive, byte *data, int count)
{
  FxArchive     *ar = (FxArchive *)archive;
  int            i;
  unsigned char  tag;
  unsigned char  run;

  ar->bytesProcessed += count;
  if ( ar->rleMarker == ar->pos )
  {
    ar->buffer[ar->rleMarker] = 0xC0;
    ar->buffer[ar->pos + 1] = *data++;
    ar->pos += 2;
    count--;
  }
  if ( ar->pos + count > ar->size )
    Com_Error(ERR_DROP, fx_errSaveOutOfMemory, ar->size, count);
  for ( i = 0; i < count; i++ )
  {
    switch ( ar->buffer[ar->rleMarker] & 0xC0 )
    {
    case 0x00:
    case 0x40:
    case 0x80:
      /* zero run: absorb zeros until a literal or a full run */
      if ( i >= count )
        return;
      do
      {
        if ( data[i] )
          goto newLiteral;
        if ( (ar->buffer[ar->rleMarker] & 0x3F) == 0x3F )
          goto newLiteral;
        ar->buffer[ar->rleMarker]++;
      }
      while ( ++i < count );
      return;
    default:
      /* literal run */
      if ( i >= count )
        return;
      do
      {
        tag = ar->buffer[ar->rleMarker];
        run = tag & 0x3F;
        if ( run == 0 )
        {
          if ( !data[i] )
          {
            ar->buffer[ar->rleMarker] = 0x00;
            goto next;
          }
        }
        else if ( run == 1 )
        {
          if ( !data[i] )
          {
            ar->buffer[ar->rleMarker] = 0x40;
            goto next;
          }
        }
        else if ( run == 3 )
        {
          if ( !data[i] )
          {
            ar->buffer[ar->rleMarker] = 0x80;
            goto next;
          }
        }
        else if ( run == 0x3F )
        {
          ar->rleMarker = ar->pos;
          ar->buffer[ar->pos] = 0xC0;
          ar->buffer[ar->pos + 1] = data[i];
          ar->pos += 2;
          continue;
        }
        else if ( run > 5 && !data[i] && !ar->buffer[ar->pos - 2] && !ar->buffer[ar->pos - 1] )
        {
          /* the last two literals were zeros too: move them into a 0x00 run */
          ar->buffer[ar->rleMarker] -= 3;
          ar->buffer[ar->pos - 2] = ar->buffer[ar->pos - 3];
          ar->buffer[ar->pos - 3] = 2;
          ar->rleMarker = ar->pos - 3;
          ar->pos--;
          goto next;
        }
        ar->buffer[ar->rleMarker] = tag + 1;
        ar->buffer[ar->pos] = data[i];
        ar->pos++;
      }
      while ( ++i < count );
      return;
    }
newLiteral:
    ar->rleMarker = ar->pos;
    ar->buffer[ar->pos] = 0xC0;
    ar->buffer[ar->pos + 1] = data[i];
    ar->pos += 2;
next:
    ;
  }
}

/* ---- CFxArchive__Value_bytes_m  0x0048D190 ----  [HIGH] */
void __cdecl CFxArchive__Value_bytes_m(int count, int archive, byte *data)
{
  FxArchive *ar = (FxArchive *)archive;

  if ( ar->reading )
    CFxArchive__ReadData(count, (unsigned int *)archive, data);
  else
    CFxArchive__WriteData((int *)archive, data, count);
}

/* ---- CFxArchive__ArchiveEffectID  0x0048D1B0 ----  VERIFIED */
void __cdecl CFxArchive__ArchiveEffectID(int archive, unsigned int *value)
{
  FxArchive *ar = (FxArchive *)archive;
  __int16    idx; // BYREF

  if ( ar->reading )
  {
    CFxArchive__ReadData(2, (unsigned int *)archive, (byte *)&idx);
    *value = ar->table[idx];
  }
  else
  {
    idx = *(__int16 *)value;
    CFxArchive__WriteData((int *)archive, (byte *)&idx, 2);
  }
}

/* ---- CFxArchive__Value_shader_m  0x0048D1F0 ----  VERIFIED */
void __cdecl CFxArchive__Value_shader_m(int archive, int *value)
{
  FxArchive *ar = (FxArchive *)archive;

  if ( ar->reading )
    *value = CFxArchive__ReadShader_m((unsigned int *)archive);
  else
    CFxArchive__WriteShader_m(*value, (int *)archive);
}

/* ---- CFxArchive__Value_effectID_m  0x0048D210 ----  VERIFIED */
void __cdecl CFxArchive__Value_effectID_m(int archive, int *value)
{
  FxArchive *ar = (FxArchive *)archive;

  if ( ar->reading )
    *value = (int)CFxArchive__ReadEffectID_m((unsigned int *)archive);
  else
    CFxArchive__WriteEffectID_m(*value, (int *)archive);
}

/* ---- FxMem_Init  0x0048D230 ----  VERIFIED */
int __cdecl FxMem_Init( void )
{
  unsigned int off;

  for ( off = 0; off < FX_ARENA_SIZE; off += FX_BLOCK_SIZE )
    *(int *)( (char *)&fxMemBlocks + off + FX_HDR_FREECOUNT ) = -1;
  return (int)off;
}

/* ---- FxMem_Init_ctor_m  0x0048D260 ----  VERIFIED */
int __stdcall FxMem_Init_ctor_m( int self )
{
  unsigned int off;

  for ( off = 0; off < FX_ARENA_SIZE; off += FX_BLOCK_SIZE )
    *(int *)( (char *)&fxMemBlocks + off + FX_HDR_FREECOUNT ) = -1;
  return self;
}

/* ---- FxMem_ClaimBlock_m  0x0048D290 ----  [CONFIRMED] */
unsigned int *__cdecl FxMem_ClaimBlock_m( int count, int elemSize, int prev )
{
  char        *block;
  unsigned int off;
  int          i;

  block = (char *)&fxMemBlocks;
  for ( off = 0; off < FX_ARENA_SIZE; off += FX_BLOCK_SIZE, block += FX_BLOCK_SIZE )
  {
    if ( *(int *)( (char *)&fxMemBlocks + off + FX_HDR_FREECOUNT ) < 0 )
      goto found;
  }
  Com_DPrintf( "^1Out of effects memory!\n" );
  return 0;

found:
  if ( fxMemHighWaterBytes < (int)( off + FX_BLOCK_SIZE ) )
    fxMemHighWaterBytes = off + FX_BLOCK_SIZE;

  /* thread the free list through the slab: element i points at element i + 1 */
  *(int *)( block + FX_HDR_FREECOUNT ) = count;
  for ( i = 0; i < count - 1; i++ )
    *(char **)( block + i * elemSize ) = block + ( i + 1 ) * elemSize;
  *(unsigned int *)( block + i * elemSize ) = 0;
  *(char **)( block + FX_HDR_FREELIST ) = block;
  if ( prev )
    *(char **)( prev + FX_HDR_NEXT ) = block;
  *(int *)( block + FX_HDR_PREV ) = prev;
  *(int *)( block + FX_HDR_NEXT ) = 0;
  return (unsigned int *)block;
}

/* ---- FxMem_UnlinkBlock  0x0048D330 ----  VERIFIED */
int __cdecl FxMem_UnlinkBlock(int block)
{
  int next;
  int prev;

  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  return block;
}

/* ---- FxMem_FreeElem  0x0048D3C0 ----  VERIFIED */
char *__cdecl FxMem_FreeElem(char *thisObj)
{
  char *block;

  /* Round the element down to its 0x8000-aligned block, then push it onto
   * that block's free list and bump the block's free count. */
  block = (char *)&fxMemBlocks + ((thisObj - (char *)&fxMemBlocks) & 0xFFFF8000);
  *(unsigned int *)thisObj = *(unsigned int *)(block + FX_HDR_FREELIST);
  *(unsigned int *)(block + FX_HDR_FREELIST) = (int)thisObj;
  ++*(unsigned int *)(block + FX_HDR_FREECOUNT);
  return block;
}

/* ---- SFxBoltInfo__copy_m  0x0048D3F0 ----  [HIGH] */
unsigned int *__cdecl SFxBoltInfo__copy_m(unsigned int *self, unsigned int *src)
{
  self[0] = src[0];
  self[1] = src[1];
  return self;
}

/* ---- CFxBoltFrame__AddRef_m  0x0048D400 ----  [HIGH] */
unsigned int *__cdecl CFxBoltFrame__AddRef_m(unsigned int *self)
{
  ++*self;
  return self;
}

/* ---- CFxBoltFrame__operator_new  0x0048D410 ----  VERIFIED */
int *__cdecl CFxBoltFrame__operator_new(int elemSize)
{
  return FxPool_AllocBoltFrame(&fxPool_BoltFrame, elemSize);
}

/* ---- CFxBoltFrame__operator_delete  0x0048D420 ----  VERIFIED */
/* Retail: mov edx,&fxPool_BoltFrame / jmp FxPool_FreeBoltFrame (ecx = p).
 * No retail code references this out-of-line copy; CFxBoltFrame__Release
 * tail-jumps to FxPool_FreeBoltFrame directly. */
unsigned int *__cdecl CFxBoltFrame__operator_delete(char *thisObj)
{
  return FxPool_FreeBoltFrame(&fxPool_BoltFrame, thisObj);
}

/* ---- CFxBoltFramePtr__ctor_m  0x0048D430 ----  [HIGH] */
unsigned int *__cdecl CFxBoltFramePtr__ctor_m(unsigned int *result)
{
  *result = 0;
  return result;
}

/* ---- CFxBoltFramePtr__ctor_frame_m  0x0048D440 ----  [HIGH] */
unsigned int *__cdecl CFxBoltFramePtr__ctor_frame_m(unsigned int *result, unsigned int *frame)
{
  ++*frame;
  *result = (unsigned int)frame;
  return result;
}

/* ---- CFxBoltFramePtr__assign_m  0x0048D460 ----  VERIFIED */
void __cdecl CFxBoltFramePtr__assign_m(char **src, char **dst)
{
  char *old;
  char *newRef;

  old = *dst;
  if ( *dst != *src )
  {
    if ( old )
    {
      CFxBoltFrame__Release(old);
      *dst = 0;
    }
    newRef = *src;
    if ( *src )
    {
      ++*(unsigned int *)newRef;
      *dst = newRef;
    }
  }
}

/* ---- CFxBoltFramePtr__assign_frame_m  0x0048D480 ----  VERIFIED */
void __cdecl CFxBoltFramePtr__assign_frame_m(char **dst, char *ref)
{
  char *old;

  old = *dst;
  if ( *dst != ref )
  {
    if ( old )
      CFxBoltFrame__Release(old);
    ++*(unsigned int *)ref;
    *dst = ref;
  }
}

/* ---- CFxBoltFramePtr__Get_m  0x0048D4A0 ----  [HIGH] */
int __cdecl CFxBoltFramePtr__Get_m(int self)
{
  return *(unsigned int *)self;
}

/* ---- CFxBoltFramePtr__IsValid_m  0x0048D4B0 ----  [HIGH] */
int __cdecl CFxBoltFramePtr__IsValid_m(unsigned int *thisObj)
{
  return *thisObj != 0;
}

/* ---- CFxModel__operator_new_m  0x0048D4C0 ----  VERIFIED */
int *__cdecl CFxModel__operator_new_m(int elemSize)
{
  return FxPool_AllocModel(&fxPool_Model, elemSize);
}

/* ---- CFxModel__operator_delete_m  0x0048D4D0 ----  VERIFIED */
unsigned int *__cdecl CFxModel__operator_delete_m(char *thisObj)
{
  return FxPool_FreeModel(&fxPool_Model, thisObj);
}

/* ---- CEffect__operator_delete  0x0048D4E0 ----  VERIFIED */
unsigned int *__cdecl CEffect__operator_delete(char *thisObj)
{
  return FxPool_FreeEffect(&fxPool_Effect, thisObj);
}

/* ---- CLight__operator_delete  0x0048D4F0 ----  VERIFIED */
unsigned int *__cdecl CLight__operator_delete(char *thisObj)
{
  return FxPool_FreeLight(&fxPool_Light, thisObj);
}

/* ---- CParticle__operator_delete  0x0048D500 ----  VERIFIED */
unsigned int *__cdecl CParticle__operator_delete(char *thisObj)
{
  return FxPool_FreeParticle(&fxPool_Particle, thisObj);
}

/* ---- CLine__operator_delete  0x0048D510 ----  VERIFIED */
unsigned int *__cdecl CLine__operator_delete(char *thisObj)
{
  return FxPool_FreeLine(&fxPool_Line, thisObj);
}

/* ---- CElectricity__operator_delete  0x0048D520 ----  VERIFIED */
unsigned int *__cdecl CElectricity__operator_delete(char *thisObj)
{
  return FxPool_FreeElectricity(&fxPool_Electricity, thisObj);
}

/* ---- COrientedParticle__operator_delete  0x0048D530 ----  VERIFIED */
unsigned int *__cdecl COrientedParticle__operator_delete(char *thisObj)
{
  return FxPool_FreeOrientedParticle(&fxPool_OrientedParticle, thisObj);
}

/* ---- CTail__operator_delete  0x0048D540 ----  VERIFIED */
unsigned int *__cdecl CTail__operator_delete(char *thisObj)
{
  return FxPool_FreeTail(&fxPool_Tail, thisObj);
}

/* ---- CCylinder__operator_delete  0x0048D550 ----  VERIFIED */
unsigned int *__cdecl CCylinder__operator_delete(char *thisObj)
{
  return FxPool_FreeCylinder(&fxPool_Cylinder, thisObj);
}

/* ---- CEmitter__RandomizeDensity_m  0x0048D560 ----  VERIFIED */
int __cdecl CEmitter__RandomizeDensity_m(float *self)
{
  int result;
  float randomFraction;

  result = rand();
  
  randomFraction = result * 0.000030517578125f;
  self[89] = (randomFraction + randomFraction - 1.0f) * self[98] + self[97];
  return result;
}

/* ---- CEmitter__operator_delete  0x0048D590 ----  VERIFIED */
unsigned int *__cdecl CEmitter__operator_delete(char *thisObj)
{
  return FxPool_FreeEmitter(&fxPool_Emitter, thisObj);
}

/* ---- CPoly__operator_delete  0x0048D5A0 ----  VERIFIED */
unsigned int *__cdecl CPoly__operator_delete(char *thisObj)
{
  return FxPool_FreeDecal(&fxPool_Decal, thisObj);
}

/* ---- CFxArchive__IsReading_m  0x0048D5B0 ----  [HIGH] */
char __cdecl CFxArchive__IsReading_m(int archive)
{
  return ((FxArchive *)archive)->reading;
}

/* ---- CFxArchive__ReadInt_m  0x0048D5C0 ----  VERIFIED */
int __cdecl CFxArchive__ReadInt_m(int unusedReg, unsigned int *archive)
{
  int value; // BYREF (filled by ReadData)

  CFxArchive__ReadData(4, archive, (byte *)&value);
  return value;
}

/* ---- CFxArchive__WriteInt_m  0x0048D5E0 ----  VERIFIED */
void __stdcall CFxArchive__WriteInt_m(int *archive, int value)
{
  /* retail: lea eax,[esp+8] -- writes all 4 bytes of the int stack argument */
  CFxArchive__WriteData(archive, (byte *)&value, 4);
}

/* ---- CFxArchive__Value_int_m  0x0048D5F0 ----  [HIGH] */
void __cdecl CFxArchive__Value_int_m(byte *value, int archive)
{
  if ( ((FxArchive *)archive)->reading )
    CFxArchive__ReadData(4, (unsigned int *)archive, value);
  else
    CFxArchive__WriteData((int *)archive, value, 4);
}

/* ---- CFxArchive__Value_float_m  0x0048D620 ----  [HIGH] */
void __cdecl CFxArchive__Value_float_m(byte *value, int archive)
{
  if ( ((FxArchive *)archive)->reading )
    CFxArchive__ReadData(4, (unsigned int *)archive, value);
  else
    CFxArchive__WriteData((int *)archive, value, 4);
}

/* ---- CFxArchive__Value_vec3_m  0x0048D650 ----  [HIGH] */
void __cdecl CFxArchive__Value_vec3_m(byte *value, int archive)
{
  if ( ((FxArchive *)archive)->reading )
    CFxArchive__ReadData(12, (unsigned int *)archive, value);
  else
    CFxArchive__WriteData((int *)archive, value, 12);
}

/* ---- ClampVec  0x0048D680 ----  [CONFIRMED] */
/* Scale a vec3 of floats by 255 and store as clamped [0,255] bytes. */
int __cdecl ClampVec(int srcVec, int dstBytes)
{
  int i;
  int n = 0;

  for ( i = 0; i < 3; ++i )
  {
    n = (int)( *(float *)( srcVec + 4 * i ) * 255.0f );
    if ( n < 0 )
      n = 0;
    else if ( n > 255 )
      n = 255;
    *(byte *)( dstBytes + i ) = (unsigned char)n;
  }
  return n;   /* dead EAX: last component value */
}

/* ---- CFxBoltFrame__Acquire  0x0048D6C0 ----  [HIGH] */
/* Find the cached bolt-frame whose key matches key[0..1], or allocate and link
 * a fresh one; bump its refcount and return it through out.  The cache is the
 * fxBoltFrames singly-linked list (next @ [14], key @ [15..16], refcount @ [0]). */
/* Retail returns a CFxBoltFramePtr by value: the caller passes the hidden
 * result pointer (EBX) and gets it back in EAX.  The function also has an
 * unused CFxBoltFramePtr local whose NULL-constructing store survives
 * ([esp] = 0); the volatile store reproduces it. */
int **__cdecl CFxBoltFrame__Acquire( int **out, int *key )
{
  int *volatile unusedPtr;
  int *node;
  int *fresh;

  unusedPtr = 0;

  for ( node = (int *)fxBoltFrames; node; node = (int *)node[14] )
  {
    if ( node[15] == key[0] && node[16] == key[1] )
      break;
  }

  if ( !node )
  {
    fresh = FxPool_AllocBoltFrame( &fxPool_BoltFrame, 68 );
    if ( fresh )
    {
      fresh[0]  = 0;
      fresh[1]  = 0;
      fresh[15] = key[0];
      fresh[16] = key[1];
      fresh[14] = fxBoltFrames;
      fxBoltFrames = (int)fresh;
      node = fresh;
    }
    else
    {
      node = 0;
    }
  }

  ++*node;
  *out = node;
  return out;
}

/* ---- CFxBoltFrame__Release  0x0048D730 ----  VERIFIED */
void __cdecl CFxBoltFrame__Release( char *thisObj )
{
  int     *link;
  char    *node;

  if ( --*(int *)thisObj != 0 )
    return;

  link = &fxBoltFrames;
  if (*link)
  {
    do
    {
      node = (char *)*link;
      if (node == thisObj)
        goto found;
      link = (int *)(node + 56);
    } while (*link);
  }
  goto release;
found:
  *link = *(unsigned int *)&FX_BOLTFRAME(thisObj)->mNext;
release:
  FxPool_FreeBoltFrame( &fxPool_BoltFrame, thisObj );
}

/* ---- CFxBoltFrame__GetOrientation  0x0048D770 ----  VERIFIED */
/* Return the bolt-frame's cached orientation (@ +8), refreshing it from the
 * skeleton if stale; 0 if the bone is invalid. */
int __cdecl CFxBoltFrame__GetOrientation( int boltFrame )
{
  if ( FX_BOLTFRAME(boltFrame)->mBolt.dobjHandle < 0 )
    return 0;
  if ( *(unsigned int *)&FX_BOLTFRAME(boltFrame)->mSkelTimeStamp != com_skelTimeStamp )
  {
    *(unsigned int *)&FX_BOLTFRAME(boltFrame)->mSkelTimeStamp = com_skelTimeStamp;
    if ( !FX_GetBoneOrientation( (unsigned int *)&FX_BOLTFRAME(boltFrame)->mBolt, (float *)FX_BOLTFRAME(boltFrame)->mOrientation ) )
    {
      *(unsigned int *)&FX_BOLTFRAME(boltFrame)->mBolt.dobjHandle = -1;
      *(unsigned int *)&FX_BOLTFRAME(boltFrame)->mBolt.boneIndex = -1;
      return 0;
    }
  }
  return boltFrame + 8;
}

/* ---- CFxBoltFrame__ctor  0x0048D7B0 ----  VERIFIED */
/* Initialise a bolt-frame node for key[0..1] and push it onto the cache list. */
unsigned int *__cdecl CFxBoltFrame__ctor( unsigned int *self, unsigned int *key )
{
  *(unsigned int *)&FX_BOLTFRAME(self)->mRefCount  = 0;
  *(unsigned int *)&FX_BOLTFRAME(self)->mSkelTimeStamp  = 0;
  *(unsigned int *)&FX_BOLTFRAME(self)->mBolt.dobjHandle = key[0];
  *(unsigned int *)&FX_BOLTFRAME(self)->mBolt.boneIndex = key[1];
  *(unsigned int *)&FX_BOLTFRAME(self)->mNext = fxBoltFrames;
  fxBoltFrames = (int)self;
  return self;
}

/* ---- CFxBoltFramePtr__Archive  0x0048D7E0 ----  VERIFIED */
/* Save/load the bolt-frame smart pointer *framePtr as its key pair (frame +60,
 * +64), or a single -1 for a null pointer.  Retail: eax = archive, edi =
 * framePtr; the smart-ptr assignments and the temp's destructor are inlined
 * there, and are expressed here through the out-of-line copies they match.
 * Only caller: CEffect__Archive (whose FX_Save / FX_Add roots are unreferenced
 * in MP, so this path is dead in CoDMP). */
void __cdecl CFxBoltFramePtr__Archive( int archive, char **framePtr )
{
  FxArchive *ar = (FxArchive *)archive;
  int        tmp;
  int        key[2];

  if ( ar->reading )
  {
    CFxArchive__ReadData( 4, (unsigned int *)ar, (byte *)&tmp );
    key[0] = tmp;
    if ( tmp >= 0 )
    {
      int       *acquired;   /* the CFxBoltFramePtr temporary */
      int      **ref;

      CFxArchive__ReadData( 4, (unsigned int *)ar, (byte *)&tmp );
      key[1] = tmp;
      ref = CFxBoltFrame__Acquire( &acquired, key );             /* 0x48D82C: temp holds a ref */
      CFxBoltFramePtr__assign_m( (char **)ref, framePtr );       /* 0x48D831..0x48D851 inlined */
      if ( acquired )
        CFxBoltFrame__Release( (char *)acquired );          /* temp smart-ptr dtor */
    }
    else
    {
      /* 0x48D865: inlined assign of a null frame, same code as
       * CFxBoltFramePtr__assign_frame_m (0x48D480).  With a non-null *framePtr
       * it releases it and then does 'inc dword ptr [esi]' with esi = 0, a
       * retail null write (fault), kept as retail. */
      CFxBoltFramePtr__assign_frame_m( framePtr, 0 );
    }
  }
  else if ( *framePtr )
  {
    CFxArchive__WriteInt_m( (int *)ar, *(int *)( *framePtr + 60 ) );
    CFxArchive__WriteInt_m( (int *)ar, *(int *)( *framePtr + 64 ) );
  }
  else
  {
    CFxArchive__WriteInt_m( (int *)ar, -1 );
  }
}

/* ---- FxModelAlloc_m  0x0048D8D0 ----  VERIFIED */
void *__cdecl FxModelAlloc_m(unsigned int size)
{
  return Hunk_AllocAlignInternal(size, 32);  /* retail 0x0048D8D9: tail-jmp, returns the block */
}

/* ---- CFxModel__Register  0x0048D8E0 ----  VERIFIED */
char *__cdecl CFxModel__Register( char *String1 )
{
  char          *rec;
  int           *node;
  void          *model;
  unsigned char *storage;
  unsigned short handle;
  int            i;
  char          *dobj;
  int            dobjModel[3];
  int            partBits[4];

  if ( _strnicmp( String1, "xmodel/", 7u ) )
    return 0;

  for ( rec = fxModelRegistrations; rec; rec = *(char **)( rec + 0x98 ) )
  {
    if ( !_stricmp( String1, rec ) )
      return rec + 0x40;
  }

  node = FxPool_AllocModel( &fxPool_Model, 0x9C );
  if ( !node )
    return 0;

  model = XModelPrecache( String1 + 7, 2, (XModelAllocFn)FxModelAlloc_m, (XModelAllocFn)FxModelAlloc_m );
  if ( !model )
  {
    FxPool_FreeModel( &fxPool_Model, (char *)node );
    return 0;
  }
  dobjModel[0] = (int)model;
  dobjModel[1] = 0;
  handle = (unsigned short)re_RegisterModel( String1, 9 );
  *(unsigned short *)&dobjModel[2] = handle;
  if ( !handle )
  {
    FxPool_FreeModel( &fxPool_Model, (char *)node );
    return 0;
  }
  dobj = (char *)node + 0x40;
  DObjCreate( dobjModel, 1, 0, dobj, 0 );

  storage = (unsigned char *)Hunk_AllocAlignInternal( 96 * *( (unsigned char *)dobj + 0x17 ) + 48, 32 );
  *(unsigned int *)( dobj + 4 ) = (unsigned int)storage;
  for ( i = 0; i < 4; ++i )
  {
    *(unsigned int *)( storage + 4 * i +  0 ) = 0;
    *(unsigned int *)( storage + 4 * i + 16 ) = 0;
    *(unsigned int *)( storage + 4 * i + 32 ) = 0;
  }

  memset( partBits, 0xFF, sizeof( partBits ) );
  DObjCalcAnim( dobj, (unsigned int *)partBits );
  DObjCalcSkel( (const unsigned int *)partBits, dobj );

  strcpy( (char *)node, String1 );
  *(unsigned int *)( (char *)node + 0x98 ) = (unsigned int)fxModelRegistrations;
  fxModelRegistrations = (char *)node;
  return dobj;
}

/* ---- CFxModel__DObjForHandle  0x0048DA40 ----  [HIGH] */
void CFxModel__DObjForHandle()
{
  ;
}

/* ---- CFxModel__NameForDObj  0x0048DA50 ----  [CONFIRMED] */
char *__cdecl CFxModel__NameForDObj(int model)
{
  if ( !model )
    return "";
  return (char *)(model - 64);
}

/* ---- CFxModel__Clean  0x0048DA60 ----  [HIGH] */
/* Free every registered CFxModel: destroy its DObj (@ +64) and return the node
 * to the pool.  Records are chained through the "next" link @ +0x98. */
void CFxModel__Clean( void )
{
  char *rec;

  while ( ( rec = fxModelRegistrations ) != 0 )
  {
    fxModelRegistrations = *(char **)( rec + 0x98 );
    DObjFree( 1u, (void *)( rec + 64 ) );
    FxPool_FreeModel( &fxPool_Model, rec );
  }
}

/* ---- CEffect__ctor  0x0048DAB0 ----  [CONFIRMED] */
unsigned int *__cdecl CEffect__ctor(unsigned int *self)
{
  *self = (unsigned int)&vtbl_CEffect;
  self[54] = 0;
  return self;
}

/* ---- CEffect__scalar_dtor  0x0048DAD0 ----  [CONFIRMED] */
char *__fastcall CEffect__scalar_dtor(char *thisObj, int edxUnused, char deleteFlags)
{
  CEffect__dtor(thisObj);
  if ( (deleteFlags & 1) != 0 )
    CEffect__operator_delete(thisObj);
  return thisObj;
}

/* ---- CEffect__dtor  0x0048DB00 ----  VERIFIED */
__declspec(noinline) void __fastcall CEffect__dtor( void *self )
{
  unsigned int *thisObj = (unsigned int *)self;
  char   *bolt;

  FX_STANDARD_CALL(CEffect__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  bolt  = (char *)thisObj[54];
  if ( bolt )
    CFxBoltFrame__Release( bolt );
}

/* ---- CEffect__Die  0x0048DB20 ----  [CONFIRMED] */
void CEffect__Die()
{
  ;
}

/* ---- CEffect__Cull  0x0048DB30 ----  [CONFIRMED] */
char CEffect__Cull()
{
  return 0;
}

/* ---- CEffect__Draw  0x0048DB40 ----  [CONFIRMED] */
void CEffect__Draw()
{
  ;
}

/* ---- CEffect__Update  0x0048DB50 ----  [HIGH] */
char __fastcall CEffect__Update(unsigned int *thisObj)
{
  /* signed compare, as retail: 0x48DB59 setle */
  int expiration = (int)thisObj[4];
  if (expiration > fxMTime)
    return 0;
  return 1;
}

/* ---- CEffect__TypeID  0x0048DB60 ----  [CONFIRMED] */
char CEffect__TypeID()
{
  return 0;
}

/*
 * Archive one fixed-size field: in read mode decode `len` bytes from the
 * archive into base+off, in write mode encode them.  Retail's CFx*::Archive
 * methods call the CFxArchive::Value helpers once per field (inlined).
 */
#define FX_AR_FIELD( ar, base, off, len )                                            \
    CFxArchive__Value_bytes_m( (len), (int)(ar), (byte *)( (base) + (off) ) )

/* ---- CEffect__Archive  0x0048DB70 ----  [CONFIRMED] */
void __fastcall CEffect__Archive( int thisObj, int edxUnused, int archive )
{
  FxArchive *ar = (FxArchive *)archive;

  FX_AR_FIELD( ar, thisObj,  FX_EFFECT_OFS( mOrigin1 ), 12 );
  FX_AR_FIELD( ar, thisObj, FX_EFFECT_OFS( mTimeStart ),  4 );
  FX_AR_FIELD( ar, thisObj, FX_EFFECT_OFS( mTimeEnd ),  4 );
  FX_AR_FIELD( ar, thisObj, FX_EFFECT_OFS( mFlags ),  4 );
  FX_AR_FIELD( ar, thisObj, FX_EFFECT_OFS( mMin ), 12 );
  FX_AR_FIELD( ar, thisObj, FX_EFFECT_OFS( mMax ), 12 );

  /* shader/effect handles @ +52 / +56 archive as int16 indices into the
   * per-archive remap table (FxArchive.table @ +20). */
  CFxArchive__ArchiveEffectID( archive, (unsigned int *)&FX_EFFECT(thisObj)->mImpactFxID );
  CFxArchive__ArchiveEffectID( archive, (unsigned int *)&FX_EFFECT(thisObj)->mDeathFxID );

  FX_AR_FIELD( ar, thisObj, FX_EFFECT_OFS( mRefEnt ), 156 );

  CFxArchive__Value_shader_m( archive, (int *)&FX_EFFECT(thisObj)->mRefEnt.customShader );
  CFxArchive__Value_effectID_m( archive, (int *)&FX_EFFECT(thisObj)->mRefEnt.dobj );

  CFxBoltFramePtr__Archive( archive, (char **)( thisObj + FX_EFFECT_OFS( mBoltFrame ) ) );
}

/* ---- CParticle__ctor  0x0048DD30 ----  [CONFIRMED] */
__declspec(noinline) unsigned int *__cdecl CParticle__ctor(unsigned int *self)
{
  self[54] = 0;
  *self = (unsigned int)&vtbl_CParticle;
  self[15] = 4;
  return self;
}

/* ---- CParticle__scalar_dtor  0x0048DD50 ----  [CONFIRMED] */
char *__fastcall CParticle__scalar_dtor(char *thisObj, int edxUnused, char deleteFlags)
{
  CParticle__dtor(thisObj);
  if ( (deleteFlags & 1) != 0 )
    CParticle__operator_delete(thisObj);
  return thisObj;
}

/* ---- CParticle__dtor  0x0048DD80 ----  VERIFIED */
__declspec(noinline) void __fastcall CParticle__dtor( void *self )
{
  unsigned int *thisObj = (unsigned int *)self;
  char   *bolt;

  FX_STANDARD_CALL(CParticle__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  bolt  = (char *)thisObj[54];
  if ( bolt )
    CFxBoltFrame__Release( bolt );
}

/* ---- CParticle__Die  0x0048DDA0 ----  [CONFIRMED] */
/* On death, if the "spawn death fx" flag is set (and not suppressed), spawn the
 * death effect (@ +56) at the particle origin along a random unit direction. */
void __fastcall CParticle__Die( int thisObj )
{
  int   flags;
  float dir[3];   /* BYREF */

  flags = *(unsigned int *)&FX_PARTICLE(thisObj)->mFlags;
  if ( ( flags & 0x20000000 ) != 0 && ( flags & 0x40000000 ) == 0 )
  {
    /* JK2 FxPrimitives: VectorSet( norm, crandom(), crandom(), crandom() ) -- the comma
     * expression keeps fstp st(0) before the id load. fmul 0x568E98 = 2^-15; the parens
     * stop VC7 folding the 2.0f into it (retail: fadd st(0),st). */
    VectorSet( dir, 2.0f * ( rand() * 0.000030517578125f ) - 1.0f,
                    2.0f * ( rand() * 0.000030517578125f ) - 1.0f,
                    2.0f * ( rand() * 0.000030517578125f ) - 1.0f );
    VectorNormalize( dir );
    CFxScheduler__PlayEffect_id_fwd_m( theFxScheduler, *(unsigned int *)&FX_PARTICLE(thisObj)->mDeathFxID, (float *)FX_PARTICLE(thisObj)->mOrigin1, (int *)dir );
  }
}

/* ---- CParticle__Cull  0x0048DE50 ----  [CONFIRMED] */
char __fastcall CParticle__Cull(float *thisObj)
{
  return SFxHelper__CullSphere((int)&theFxHelper, thisObj + 32, thisObj[46]);
}

/* ---- CParticle__Draw  0x0048DE70 ----  [CONFIRMED] */
int __fastcall CParticle__Draw(unsigned int *thisObj)
{
  if ( (thisObj[6] & 0x100000) != 0 )
    thisObj[16] |= 8u;
  return re_AddRefEntityToScene(thisObj + 15, 0);
}

/* ---- CParticle__Update  0x0048DE90 ----  [CONFIRMED] */
char __fastcall CParticle__Update( int thisObj )
{
  int          bolt;
  const float *orient;

  if ( FX_PARTICLE(thisObj)->mTimeStart > fxMTime )   /* signed, as retail: 0x48DE9C jle */
    return 0;
  if ( !CParticle__UpdateOrigin( thisObj ) )
    return 0;

  bolt = *(unsigned int *)&FX_PARTICLE(thisObj)->mBoltFrame;
  if ( bolt )
  {
    orient = (const float *)CFxBoltFrame__GetOrientation( bolt );
    if ( !orient )
      return 0;
    OrientationPosToWorldPos( orient, (const float *)FX_PARTICLE(thisObj)->mOrigin1, (float *)FX_PARTICLE(thisObj)->mRefEnt.origin );
  }
  else
  {
    *(unsigned int *)&FX_PARTICLE(thisObj)->mRefEnt.origin[0] = *(unsigned int *)&FX_PARTICLE(thisObj)->mOrigin1[0];
    *(unsigned int *)&FX_PARTICLE(thisObj)->mRefEnt.origin[1] = *(unsigned int *)&FX_PARTICLE(thisObj)->mOrigin1[1];
    *(unsigned int *)&FX_PARTICLE(thisObj)->mRefEnt.origin[2] = *(unsigned int *)&FX_PARTICLE(thisObj)->mOrigin1[2];
  }

  CParticle__UpdateSize( thisObj );
  CParticle__UpdateSize2( thisObj );
  CParticle__UpdateRGB( thisObj );
  CParticle__UpdateAlpha( thisObj );
  CParticle__UpdateRotation( thisObj );
  return 1;
}

/* ---- CParticle__UpdateOrigin  0x0048DF20 ----  VERIFIED */
char __cdecl CParticle__UpdateOrigin( int self )
{
  int     bolt;
  float  *orient;
  float   t;
  float   time2;
  float   newOrigin[3];
  float   startWorld[3];
  float   endWorld[3];
  trace_t trace;
  int     flags;
  float   normal[3];
  float   dot;

  CParticle__UpdateVelocity( (float *)self );

  /* x87 precision as retail: tExt / halfTT stay unrounded on the FPU stack,
   * only t is stored as a float. */
  t      = fxHelperFrameTime * 0.001f;
  time2  = t * t * 0.5f;

  newOrigin[0] = time2 * FX_PARTICLE(self)->mAccel[0] + t * FX_PARTICLE(self)->mVel[0] + FX_PARTICLE(self)->mOrigin1[0];
  newOrigin[1] = time2 * FX_PARTICLE(self)->mAccel[1] + t * FX_PARTICLE(self)->mVel[1] + FX_PARTICLE(self)->mOrigin1[1];
  newOrigin[2] = time2 * FX_PARTICLE(self)->mAccel[2] + t * FX_PARTICLE(self)->mVel[2] + FX_PARTICLE(self)->mOrigin1[2];

  if ( ( *(unsigned int *)&FX_PARTICLE(self)->mFlags & 0x2000000 ) == 0 )
    goto STORE;

  bolt   = *(unsigned int *)&FX_PARTICLE(self)->mBoltFrame;
  if ( bolt )
  {
    do   /* orient = mBoltFrame->GetOrientation() */
    {
      orient = 0;
      if ( FX_BOLTFRAME(bolt)->mBolt.dobjHandle < 0 )
        break;
      if ( *(unsigned int *)&FX_BOLTFRAME(bolt)->mSkelTimeStamp != com_skelTimeStamp )
      {
        *(unsigned int *)&FX_BOLTFRAME(bolt)->mSkelTimeStamp = com_skelTimeStamp;
        if ( !FX_GetBoneOrientation( (unsigned int *)&FX_BOLTFRAME(bolt)->mBolt, (float *)FX_BOLTFRAME(bolt)->mOrientation ) )
        {
          *(unsigned int *)&FX_BOLTFRAME(bolt)->mBolt.dobjHandle = -1;
          *(unsigned int *)&FX_BOLTFRAME(bolt)->mBolt.boneIndex = -1;
          break;
        }
      }
      orient = (float *)FX_BOLTFRAME(bolt)->mOrientation;
    }
    while ( 0 );
    if ( !orient )
      return 0;

    startWorld[0] = FX_PARTICLE(self)->mOrigin1[2] * orient[9] + orient[3] * FX_PARTICLE(self)->mOrigin1[0]
                  + FX_PARTICLE(self)->mOrigin1[1] * orient[6] + orient[0];
    startWorld[1] = FX_PARTICLE(self)->mOrigin1[0] * orient[4] + FX_PARTICLE(self)->mOrigin1[2] * orient[10]
                  + FX_PARTICLE(self)->mOrigin1[1] * orient[7] + orient[1];
    /* explicit grouping: VC7 keeps the parenthesised pair (retail sums the
     * z and y terms first in this row) */
    startWorld[2] = ( ( FX_PARTICLE(self)->mOrigin1[2] * orient[11] + FX_PARTICLE(self)->mOrigin1[1] * orient[8] )
                  + orient[5] * FX_PARTICLE(self)->mOrigin1[0] ) + orient[2];

    endWorld[0] = newOrigin[2] * orient[9] + newOrigin[0] * orient[3]
                + newOrigin[1] * orient[6] + orient[0];
    endWorld[1] = newOrigin[0] * orient[4] + newOrigin[2] * orient[10]
                + newOrigin[1] * orient[7] + orient[1];
    endWorld[2] = newOrigin[0] * orient[5] + newOrigin[2] * orient[11]
                + newOrigin[1] * orient[8] + orient[2];
  }
  else
  {
    VectorCopy( FX_PARTICLE(self)->mOrigin1, startWorld );
    VectorCopy( newOrigin, endWorld );
    orient = 0;
  }

  trace.fraction = 1.0f;
  if ( *(unsigned int *)&FX_PARTICLE(self)->mFlags & 0x4000000 )
    CM_Trace( &trace, startWorld, endWorld,
              (const float *)FX_PARTICLE(self)->mMin, (const float *)FX_PARTICLE(self)->mMax,
              0, vec3_origin, 1, 0, 0 );
  else
    CM_Trace( &trace, startWorld, endWorld, 0, 0,
              0, vec3_origin, 1, 0, 0 );

  trace.entityNum = 1022;
  if ( trace.fraction == 1.0 )
    trace.entityNum = 1023;

  if ( !( trace.fraction < 1.0f ) || trace.startsolid || trace.allsolid )
  {
STORE:
    FX_PARTICLE(self)->mOrigin1[0]  = newOrigin[0];
    FX_PARTICLE(self)->mOrigin1[1]  = newOrigin[1];
    FX_PARTICLE(self)->mOrigin1[2] = newOrigin[2];
    return 1;
  }

  if ( *(unsigned int *)&FX_PARTICLE(self)->mFlags & 0x80000000 )   /* FX_IMPACT_RUNS_FX */
    CFxScheduler__PlayEffect_id_fwd_m( theFxScheduler, *(unsigned int *)&FX_PARTICLE(self)->mImpactFxID,
                trace.endpos, (int *)trace.normal );

  flags = *(unsigned int *)&FX_PARTICLE(self)->mFlags;
  if ( ( flags & 0x40000000 ) != 0 )
    return 0;

  if ( *(unsigned int *)&FX_PARTICLE(self)->mBoltFrame )
    OrientationDirFromWorldDir( (const float *)orient, trace.normal, normal );
  else
    VectorCopy( trace.normal, normal );

  /* set the velocity: bounce off the plane, scaled by the elasticity */
  VectorMA( FX_PARTICLE(self)->mVel, trace.fraction * t, FX_PARTICLE(self)->mAccel, FX_PARTICLE(self)->mVel );
  dot = DotProduct( FX_PARTICLE(self)->mVel, normal );
  VectorMA( FX_PARTICLE(self)->mVel, -2.0f * dot, normal, FX_PARTICLE(self)->mVel );
  VectorScale( FX_PARTICLE(self)->mVel, FX_PARTICLE(self)->mElasticity, FX_PARTICLE(self)->mVel );

  if ( trace.normal[2] > 0.0f )
  {
    if ( FX_PARTICLE(self)->mVel[2] < 4.0f )
    {
      *(unsigned int *)&FX_PARTICLE(self)->mVel[2] = 0;
      *(unsigned int *)&FX_PARTICLE(self)->mVel[1] = 0;
      *(unsigned int *)&FX_PARTICLE(self)->mVel[0] = 0;
      *(unsigned int *)&FX_PARTICLE(self)->mAccel[2] = 0;
      *(unsigned int *)&FX_PARTICLE(self)->mAccel[1] = 0;
      *(unsigned int *)&FX_PARTICLE(self)->mAccel[0] = 0;
      *(unsigned int *)&FX_PARTICLE(self)->mFlags  = flags & 0x7DFFFFFF;
    }
  }

  FX_PARTICLE(self)->mOrigin1[0]  = ( newOrigin[0] - FX_PARTICLE(self)->mOrigin1[0] )  * trace.fraction + FX_PARTICLE(self)->mOrigin1[0];
  FX_PARTICLE(self)->mOrigin1[1]  = ( newOrigin[1] - FX_PARTICLE(self)->mOrigin1[1] )  * trace.fraction + FX_PARTICLE(self)->mOrigin1[1];
  FX_PARTICLE(self)->mOrigin1[2] = ( newOrigin[2] - FX_PARTICLE(self)->mOrigin1[2] ) * trace.fraction + FX_PARTICLE(self)->mOrigin1[2];
  return 1;
}

/* ---- CParticle__UpdateVelocity  0x0048E340 ----  VERIFIED */
float *__cdecl CParticle__UpdateVelocity( float *self )
{
  float timestep;
  /* fmul dword 0x568E6C = 0x3A83126F: the float 0.001f, not the double 0.001 */
  timestep = (float)fxHelperFrameTime * 0.001f;
  self[55] = (float)( timestep * self[58] + self[55] );
  timestep = (float)fxHelperFrameTime * 0.001f;
  self[56] = (float)( timestep * self[59] + self[56] );
  timestep = (float)fxHelperFrameTime * 0.001f;
  self[57] = (float)( timestep * self[60] + self[57] );
  return self;
}

/* ---- CParticle__UpdateSize  0x0048E3A0 ----  VERIFIED */
void __cdecl CParticle__UpdateSize( int self )
{
  int    flags = FX_PARTICLE(self)->mFlags;
  int    mode;
  float  linear = 1.0f;
  float  mTimeF;
  float frac   = 1.0f;                                 /* 0x48E3A6 fld 1.0: frac lives in st0 */

  /* time differences are signed ints (sub + fild / fidiv) */
  if ( ( flags & 0x100 ) != 0 )
    linear = (float)( 1.0f - (float)( fxMTime - FX_PARTICLE(self)->mTimeStart )
                          / ( FX_PARTICLE(self)->mTimeEnd - FX_PARTICLE(self)->mTimeStart ) );

  /* the 0x400 / 0xC00 fraction stays on the FPU stack through the 0x100
   * averaging and is rounded to float once (0x48E496 fstp) */
  mode = flags & 0xC00;
  if ( mode == 0x400 )
  {
    mTimeF = (float)fxMTime;                           /* 0x48E401 fst [esp+8] */
    if ( (float)fxMTime > FX_PARTICLE(self)->mSizeParm )    /* compares the exact value */
      frac = 1.0f - ( (float)mTimeF - FX_PARTICLE(self)->mSizeParm )
                 / ( (float)FX_PARTICLE(self)->mTimeEnd - FX_PARTICLE(self)->mSizeParm );
    if ( ( flags & 0x100 ) != 0 )
      frac = ( frac + linear ) * 0.5f;
    linear = (float)frac;
  }
  else if ( mode == 0x800 )
  {
    linear = (float)( cos( (float)( fxMTime - FX_PARTICLE(self)->mTimeStart )
                           * FX_PARTICLE(self)->mSizeParm ) * linear );
  }
  else if ( mode == 0xC00 )
  {
    if ( (float)fxMTime < FX_PARTICLE(self)->mSizeParm )
      frac = ( FX_PARTICLE(self)->mSizeParm - (float)fxMTime )
           / ( FX_PARTICLE(self)->mSizeParm - (float)FX_PARTICLE(self)->mTimeStart );
    else
      frac = 0.0f;
    if ( ( flags & 0x100 ) != 0 )
      frac = ( frac + linear ) * 0.5f;
    linear = (float)frac;
  }

  if ((flags & 0x200) != 0)
  {
    float fraction = rand() * 0.000030517578125f;
    linear = fraction * linear;
  }

  FX_PARTICLE(self)->mRefEnt.radius = (float)( ( 1.0f - linear ) * FX_PARTICLE(self)->mSizeEnd
                                    + linear * FX_PARTICLE(self)->mSizeStart );
}

/* ---- CParticle__UpdateSize2  0x0048E4F0 ----  VERIFIED */
void __cdecl CParticle__UpdateSize2( int self )
{
  int    flags = FX_PARTICLE(self)->mFlags;
  int    mode;
  float  linear = 1.0f;
  float  mTimeF;
  float frac   = 1.0f;                                 /* 0x48E3A6 fld 1.0: frac lives in st0 */

  /* time differences are signed ints (sub + fild / fidiv) */
  if ( ( flags & 0x10000 ) != 0 )
    linear = (float)( 1.0f - (float)( fxMTime - FX_PARTICLE(self)->mTimeStart )
                          / ( FX_PARTICLE(self)->mTimeEnd - FX_PARTICLE(self)->mTimeStart ) );

  /* the 0x40000 / 0xC0000 fraction stays on the FPU stack through the 0x10000
   * averaging and is rounded to float once (0x48E496 fstp) */
  mode = flags & 0xC0000;
  if ( mode == 0x40000 )
  {
    mTimeF = (float)fxMTime;                           /* 0x48E401 fst [esp+8] */
    if ( (float)fxMTime > FX_PARTICLE(self)->mSize2Parm )    /* compares the exact value */
      frac = 1.0f - ( (float)mTimeF - FX_PARTICLE(self)->mSize2Parm )
                 / ( (float)FX_PARTICLE(self)->mTimeEnd - FX_PARTICLE(self)->mSize2Parm );
    if ( ( flags & 0x10000 ) != 0 )
      frac = ( frac + linear ) * 0.5f;
    linear = (float)frac;
  }
  else if ( mode == 0x80000 )
  {
    linear = (float)( cos( (float)( fxMTime - FX_PARTICLE(self)->mTimeStart )
                           * FX_PARTICLE(self)->mSize2Parm ) * linear );
  }
  else if ( mode == 0xC0000 )
  {
    if ( (float)fxMTime < FX_PARTICLE(self)->mSize2Parm )
      frac = ( FX_PARTICLE(self)->mSize2Parm - (float)fxMTime )
           / ( FX_PARTICLE(self)->mSize2Parm - (float)FX_PARTICLE(self)->mTimeStart );
    else
      frac = 0.0f;
    if ( ( flags & 0x10000 ) != 0 )
      frac = ( frac + linear ) * 0.5f;
    linear = (float)frac;
  }

  if ((flags & 0x20000) != 0)
  {
    float fraction = rand() * 0.000030517578125f;
    linear = fraction * linear;
  }

  FX_PARTICLE(self)->mRefEnt.spriteSize = (float)( ( 1.0f - linear ) * FX_PARTICLE(self)->mSize2End
                                    + linear * FX_PARTICLE(self)->mSize2Start );
}

/* ---- CParticle__UpdateRGB  0x0048E640 ----  [CONFIRMED] */
/* Blend the particle RGB between its end color (@ +280) and start color
 * (@ +268) by a fade fraction selected from the flags @ +24, then write the
 * result as clamped bytes @ +168.  Fade modes mirror CParticle__UpdateSize.
 * The intermediate float/double types are kept exactly as the retail code
 * rounds them (component 0 differs from 1/2), so bit-for-bit results match. */
int __cdecl CParticle__UpdateRGB( int self )
{
  int    flags;
  int    mode;
  float blend;        
  float  scale;        
  float  scaleTmp;     

     
     
  float  rgb[3];       

  flags = *(unsigned int *)&FX_PARTICLE(self)->mFlags;
  blend = 1.0f;
  scale = 1.0f;
  
  if ( ( flags & 0x10 ) != 0 )
    scale = 1.0f - (float)( fxMTime - FX_PARTICLE(self)->mTimeStart )
                / ( FX_PARTICLE(self)->mTimeEnd - FX_PARTICLE(self)->mTimeStart );

  mode = flags & 0xC0;
  if ( mode == 0x40 )
  {
    if ( (float)fxMTime > FX_PARTICLE(self)->mRGBParm )
    {
      scaleTmp = (float)fxMTime;
      blend = 1.0f - ( scaleTmp - FX_PARTICLE(self)->mRGBParm )
                  / ( (float)FX_PARTICLE(self)->mTimeEnd - FX_PARTICLE(self)->mRGBParm );
    }
    if ( ( flags & 0x10 ) != 0 )
      blend = ( blend + scale ) * 0.5f;
    scale = blend;
  }
  else if ( mode == 0x80 )
  {
    scale = cos( (float)( fxMTime - FX_PARTICLE(self)->mTimeStart ) * FX_PARTICLE(self)->mRGBParm ) * scale;   
  }
  else if ( mode == 0xC0 )
  {
    if ((float)fxMTime < FX_PARTICLE(self)->mRGBParm)
      blend = ( FX_PARTICLE(self)->mRGBParm - (float)fxMTime )
            / ( FX_PARTICLE(self)->mRGBParm - (float)FX_PARTICLE(self)->mTimeStart );
    else
      blend = 0.0f;
    if ( ( flags & 0x10 ) != 0 )
      blend = ( blend + scale ) * 0.5f;
    scale = blend;
  }

  if ((flags & 0x20) != 0)
  {
    float fraction = rand() * 0.000030517578125f;
    scale = fraction * scale;
  }   

  rgb[0] = scale * FX_PARTICLE(self)->mRGBStart[0];
  rgb[1] = scale * FX_PARTICLE(self)->mRGBStart[1];
  rgb[2] = scale * FX_PARTICLE(self)->mRGBStart[2];
  scale = 1.0f - scale;
  rgb[0] = scale * FX_PARTICLE(self)->mRGBEnd[0] + rgb[0];
  rgb[1] = scale * FX_PARTICLE(self)->mRGBEnd[1] + rgb[1];
  rgb[2] = scale * FX_PARTICLE(self)->mRGBEnd[2] + rgb[2];
  return ClampVec( (int)rgb, self + 168 );
}

/* ---- CParticle__UpdateAlpha  0x0048E7D0 ----  VERIFIED */
void __cdecl CParticle__UpdateAlpha( int self )
{
  int    flags = *(unsigned int *)&FX_PARTICLE(self)->mFlags;
  int    mode;
  float linear = 1.0f;    
  float  mres   = 1.0f;   
  float  alpha;           
  int    r, g, b;

  
  if ( ( flags & 1 ) != 0 )
    linear = 1.0f - (float)( fxMTime - FX_PARTICLE(self)->mTimeStart )
                 / ( FX_PARTICLE(self)->mTimeEnd - FX_PARTICLE(self)->mTimeStart );

  mode = flags & 0xC;
  if ( mode == 4 )
  {
    if ( (float)fxMTime > FX_PARTICLE(self)->mAlphaParm )
      mres = (float)( 1.0f - ( (float)fxMTime - FX_PARTICLE(self)->mAlphaParm )
                          / ( (float)FX_PARTICLE(self)->mTimeEnd - FX_PARTICLE(self)->mAlphaParm ) );   
    linear = ( flags & 1 ) ? ( linear + mres ) * 0.5f : mres;
  }
  else if ( mode == 8 )
  {
    linear = linear * cos( (float)( fxMTime - FX_PARTICLE(self)->mTimeStart ) * FX_PARTICLE(self)->mAlphaParm );
  }
  else if ( mode == 0xC )
  {
    if ( (float)fxMTime < FX_PARTICLE(self)->mAlphaParm )
      mres = (float)( ( FX_PARTICLE(self)->mAlphaParm - (float)fxMTime )
                    / ( FX_PARTICLE(self)->mAlphaParm - (float)FX_PARTICLE(self)->mTimeStart ) );   
    else
      mres = 0.0f;
    linear = ( flags & 1 ) ? ( linear + mres ) * 0.5f : mres;
  }

  
  alpha = (float)( ( 1.0f - linear ) * FX_PARTICLE(self)->mAlphaEnd
                   + linear * FX_PARTICLE(self)->mAlphaStart );
  if ( alpha < 0.0f )
    alpha = 0.0f;
  else if ( alpha > 1.0f )
    alpha = 1.0f;

  if ((flags & 2) != 0)
  {
    float fraction = rand() * 0.000030517578125f;
    alpha = fraction * alpha;
  }

  if ( ( *(unsigned int *)&FX_PARTICLE(self)->mFlags & 0x8000000 ) != 0 )
  {
    FX_PARTICLE(self)->mRefEnt.shaderRGBA[3] = (byte)(int)( alpha * 255.0f );
  }
  else
  {
    r = FX_PARTICLE(self)->mRefEnt.shaderRGBA[0];
    g = FX_PARTICLE(self)->mRefEnt.shaderRGBA[1];
    b = FX_PARTICLE(self)->mRefEnt.shaderRGBA[2];
    FX_PARTICLE(self)->mRefEnt.shaderRGBA[0] = (byte)(int)( (float)r * alpha );
    FX_PARTICLE(self)->mRefEnt.shaderRGBA[1] = (byte)(int)( (float)g * alpha );
    FX_PARTICLE(self)->mRefEnt.shaderRGBA[2] = (byte)(int)( (float)b * alpha );
    FX_PARTICLE(self)->mRefEnt.shaderRGBA[3] = 0xFF;
  }
}

/* ---- CParticle__UpdateRotation  0x0048E9C0 ----  [CONFIRMED] */
int __cdecl CParticle__UpdateRotation(int self)
{
  FX_PARTICLE(self)->mRefEnt.rotation = (float)fxHelperFrameTime * FX_PARTICLE(self)->mRotationDelta * 0.01f + FX_PARTICLE(self)->mRefEnt.rotation;   /* 0x568F00 = 0.01f */
  FX_PARTICLE(self)->mRotationDelta = (1.0f - (float)fxHelperFrameTime * 0.00065f) * FX_PARTICLE(self)->mRotationDelta;               /* 0x568EFC = 0.00065f */
  return self;
}

/* ---- CParticle__TypeID  0x0048EA00 ----  [CONFIRMED] */
char CParticle__TypeID()
{
  return 1;
}

/* ---- CParticle__Archive  0x0048EA10 ----  [CONFIRMED] */
void __fastcall CParticle__Archive( byte *thisObj, int edxUnused, int archive )
{
  CEffect__Archive( (int)thisObj, edxUnused, archive );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mVel ), 12 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mAccel ), 12 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mSizeStart ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mSizeEnd ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mSizeParm ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mSize2Start ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mSize2End ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mSize2Parm ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mRGBStart ), 12 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mRGBEnd ), 12 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mRGBParm ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mAlphaStart ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mAlphaEnd ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mAlphaParm ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mRotationDelta ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_PARTICLE_OFS( mElasticity ), 4 );
}

/* ---- COrientedParticle__ctor  0x0048EC50 ----  [CONFIRMED] */
__declspec(noinline) unsigned int *__cdecl COrientedParticle__ctor(unsigned int *self)
{
  self[54] = 0;
  *self = (unsigned int)&vtbl_COrientedParticle;
  self[15] = 12;
  return self;
}

/* ---- COrientedParticle__scalar_dtor  0x0048EC70 ----  [CONFIRMED] */
char *__fastcall COrientedParticle__scalar_dtor(char *thisObj, int edxUnused, char deleteFlags)
{
  COrientedParticle__dtor(thisObj);
  if ( (deleteFlags & 1) != 0 )
    COrientedParticle__operator_delete(thisObj);
  return thisObj;
}

/* ---- COrientedParticle__dtor  0x0048ECA0 ----  VERIFIED */
__declspec(noinline) void __fastcall COrientedParticle__dtor( void *self )
{
  unsigned int *thisObj = (unsigned int *)self;
  char   *bolt;

  FX_STANDARD_CALL(COrientedParticle__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  bolt  = (char *)thisObj[54];
  if ( bolt )
    CFxBoltFrame__Release( bolt );
}

/* ---- COrientedParticle__Cull  0x0048ECC0 ----  [CONFIRMED] */
char __fastcall COrientedParticle__Cull(float *thisObj)
{
  return SFxHelper__CullSphere((int)&theFxHelper, thisObj + 32, thisObj[46]);
}

/* ---- COrientedParticle__Draw  0x0048ECE0 ----  [CONFIRMED] */
int __fastcall COrientedParticle__Draw(unsigned int *thisObj)
{
  if ( (thisObj[6] & 0x100000) != 0 )
    thisObj[16] |= 8u;
  return re_AddRefEntityToScene(thisObj + 15, 0);
}

/* ---- COrientedParticle__Update  0x0048ED00 ----  [CONFIRMED] */
char __fastcall COrientedParticle__Update( int thisObj )
{
  int          bolt;
  const float *orient;

  if ( FX_ORIENTED(thisObj)->mTimeStart > fxMTime )   /* signed, as retail: 0x48ED0C jle */
    return 0;
  if ( !CParticle__UpdateOrigin( thisObj ) )
    return 0;
  CParticle__UpdateSize( thisObj );
  CParticle__UpdateSize2( thisObj );
  CParticle__UpdateRGB( thisObj );
  CParticle__UpdateAlpha( thisObj );

  bolt = *(unsigned int *)&FX_ORIENTED(thisObj)->mBoltFrame;
  FX_ORIENTED(thisObj)->mRefEnt.rotation = (float)fxHelperFrameTime * FX_ORIENTED(thisObj)->mRotationDelta * 0.01f      /* 0x568F00 */
                           + FX_ORIENTED(thisObj)->mRefEnt.rotation;
  FX_ORIENTED(thisObj)->mRotationDelta = ( 1.0f - (float)fxHelperFrameTime * 0.00065f ) * FX_ORIENTED(thisObj)->mRotationDelta;   /* 0x568EFC */

  if ( bolt )
  {
    orient = (const float *)CFxBoltFrame__GetOrientation( bolt );
    if ( !orient )
      return 0;
    OrientationPosToWorldPos( orient, (const float *)FX_ORIENTED(thisObj)->mOrigin1, (float *)FX_ORIENTED(thisObj)->mRefEnt.origin );
    OrientationDirToWorldDir( orient, (const float *)FX_ORIENTED(thisObj)->mNormal, (float *)FX_ORIENTED(thisObj)->mRefEnt.axis[0] );
    return 1;
  }
  else
  {
    *(unsigned int *)&FX_ORIENTED(thisObj)->mRefEnt.origin[0] = *(unsigned int *)&FX_ORIENTED(thisObj)->mOrigin1[0];
    *(unsigned int *)&FX_ORIENTED(thisObj)->mRefEnt.origin[1] = *(unsigned int *)&FX_ORIENTED(thisObj)->mOrigin1[1];
    *(unsigned int *)&FX_ORIENTED(thisObj)->mRefEnt.origin[2] = *(unsigned int *)&FX_ORIENTED(thisObj)->mOrigin1[2];
    *(unsigned int *)&FX_ORIENTED(thisObj)->mRefEnt.axis[0][0]  = *(unsigned int *)&FX_ORIENTED(thisObj)->mNormal[0];
    *(unsigned int *)&FX_ORIENTED(thisObj)->mRefEnt.axis[0][1]  = *(unsigned int *)&FX_ORIENTED(thisObj)->mNormal[1];
    *(unsigned int *)&FX_ORIENTED(thisObj)->mRefEnt.axis[0][2]  = *(unsigned int *)&FX_ORIENTED(thisObj)->mNormal[2];
    return 1;
  }
}

/* ---- COrientedParticle__TypeID  0x0048EDF0 ----  [CONFIRMED] */
char COrientedParticle__TypeID()
{
  return 8;
}

/* ---- COrientedParticle__Archive  0x0048EE00 ----  [CONFIRMED] */
void __fastcall COrientedParticle__Archive( byte *thisObj, int edxUnused, int archive )
{
  CParticle__Archive( thisObj, edxUnused, archive );
  FX_AR_FIELD( archive, thisObj, FX_ORIENTED_OFS( mNormal ), 12 );
}

/* ---- CLine__ctor  0x0048EE40 ----  [CONFIRMED] */
__declspec(noinline) unsigned int *__cdecl CLine__ctor(unsigned int *self)
{
  self[54] = 0;
  *self = (unsigned int)&vtbl_CLine;
  self[15] = 13;
  return self;
}

/* ---- CLine__scalar_dtor  0x0048EE60 ----  [CONFIRMED] */
char *__fastcall CLine__scalar_dtor(char *thisObj, int edxUnused, char deleteFlags)
{
  CLine__dtor(thisObj);
  if ( (deleteFlags & 1) != 0 )
    CLine__operator_delete(thisObj);
  return thisObj;
}

/* ---- CLine__dtor  0x0048EE90 ----  VERIFIED */
__declspec(noinline) void __fastcall CLine__dtor( void *self )
{
  unsigned int *thisObj = (unsigned int *)self;
  char   *bolt;

  FX_STANDARD_CALL(CLine__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  bolt  = (char *)thisObj[54];
  if ( bolt )
    CFxBoltFrame__Release( bolt );
}

/* ---- CLine__Die  0x0048EEB0 ----  [CONFIRMED] */
void CLine__Die()
{
  ;
}

/* ---- CLine__Cull  0x0048EEC0 ----  [CONFIRMED] */
char __fastcall CLine__Cull(float *thisObj)
{
  return SFxHelper__CullCylinder((int)&theFxHelper, thisObj + 32, thisObj + 36, thisObj[46], thisObj[46]);
}

/* ---- CLine__Draw  0x0048EEF0 ----  [CONFIRMED] */
int __fastcall CLine__Draw(unsigned int *thisObj)
{
  if ( (thisObj[6] & 0x100000) != 0 )
    thisObj[16] |= 8u;
  return re_AddRefEntityToScene(thisObj + 15, 0);
}

/* ---- CLine__Update  0x0048EF10 ----  [CONFIRMED] */
char __fastcall CLine__Update( int thisObj )
{
  int          bolt;
  const float *orient;

  if ( FX_LINE(thisObj)->mTimeStart > fxMTime )   /* signed, as retail: 0x48EF1C jle */
    return 0;

  bolt = *(unsigned int *)&FX_LINE(thisObj)->mBoltFrame;
  if ( bolt )
  {
    orient = (const float *)CFxBoltFrame__GetOrientation( bolt );
    if ( !orient )
      return 0;
    OrientationPosToWorldPos( orient, (const float *)FX_LINE(thisObj)->mOrigin1,   (float *)FX_LINE(thisObj)->mRefEnt.origin );
    OrientationPosToWorldPos( orient, (const float *)FX_LINE(thisObj)->mOrigin2, (float *)FX_LINE(thisObj)->mRefEnt.oldorigin );
  }
  else
  {
    *(unsigned int *)&FX_LINE(thisObj)->mRefEnt.origin[0] = *(unsigned int *)&FX_LINE(thisObj)->mOrigin1[0];
    *(unsigned int *)&FX_LINE(thisObj)->mRefEnt.origin[1] = *(unsigned int *)&FX_LINE(thisObj)->mOrigin1[1];
    *(unsigned int *)&FX_LINE(thisObj)->mRefEnt.origin[2] = *(unsigned int *)&FX_LINE(thisObj)->mOrigin1[2];
    *(unsigned int *)&FX_LINE(thisObj)->mRefEnt.oldorigin[0] = *(unsigned int *)&FX_LINE(thisObj)->mOrigin2[0];
    *(unsigned int *)&FX_LINE(thisObj)->mRefEnt.oldorigin[1] = *(unsigned int *)&FX_LINE(thisObj)->mOrigin2[1];
    *(unsigned int *)&FX_LINE(thisObj)->mRefEnt.oldorigin[2] = *(unsigned int *)&FX_LINE(thisObj)->mOrigin2[2];
  }

  CParticle__UpdateSize( thisObj );
  CParticle__UpdateRGB( thisObj );
  CParticle__UpdateAlpha( thisObj );
  return 1;
}

/* ---- CLine__TypeID  0x0048EFC0 ----  [CONFIRMED] */
char CLine__TypeID()
{
  return 2;
}

/* ---- CLine__Archive  0x0048EFD0 ----  [CONFIRMED] */
void __fastcall CLine__Archive( byte *thisObj, int edxUnused, int archive )
{
  CParticle__Archive( thisObj, edxUnused, archive );
  FX_AR_FIELD( archive, thisObj, FX_LINE_OFS( mOrigin2 ), 12 );
}

/* ---- CElectricity__ctor  0x0048F010 ----  [CONFIRMED] */
__declspec(noinline) unsigned int *__cdecl CElectricity__ctor(unsigned int *self)
{
  self[54] = 0;
  *self = (unsigned int)&vtbl_CElectricity;
  self[15] = 14;
  return self;
}

/* ---- CElectricity__scalar_dtor  0x0048F030 ----  [CONFIRMED] */
char *__fastcall CElectricity__scalar_dtor(char *thisObj, int edxUnused, char deleteFlags)
{
  CElectricity__dtor(thisObj);
  if ( (deleteFlags & 1) != 0 )
    CElectricity__operator_delete(thisObj);
  return thisObj;
}

/* ---- CElectricity__dtor  0x0048F060 ----  VERIFIED */
__declspec(noinline) void __fastcall CElectricity__dtor( void *self )
{
  unsigned int *thisObj = (unsigned int *)self;
  char   *bolt;

  FX_STANDARD_CALL(CElectricity__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  bolt  = (char *)thisObj[54];
  if ( bolt )
    CFxBoltFrame__Release( bolt );
}

/* ---- CElectricity__Die  0x0048F080 ----  [CONFIRMED] */
void CElectricity__Die()
{
  ;
}

/* ---- CElectricity__Cull  0x0048F090 ----  [CONFIRMED] */
char CElectricity__Cull()
{
  return 0;
}

/* ---- CElectricity__Initialize  0x0048F0A0 ----  [HIGH] */
int __cdecl CElectricity__Initialize( int self )
{
  int flags;
  float fraction = rand() * 0.000030517578125f;

  *(unsigned int *)&FX_ELECTRICITY(self)->mRefEnt.frame = (int)(fraction * 1265536.0f);   /* 2^-15 exactly: retail float const @0x568E98 */
  FX_ELECTRICITY(self)->mRefEnt.rotation  = (float)(int)( theFxHelper + *(unsigned int *)&FX_ELECTRICITY(self)->mTimeEnd - *(unsigned int *)&FX_ELECTRICITY(self)->mTimeStart );   /* signed fild, retail 0x0048F0D9 */

  flags = *(unsigned int *)&FX_ELECTRICITY(self)->mFlags;
  if ( ( flags & 0x100000 ) != 0 )
    *(unsigned int *)&FX_ELECTRICITY(self)->mRefEnt.renderfx |= 8u;
  if ( ( flags & 0x2000000 ) != 0 )
    *(unsigned int *)&FX_ELECTRICITY(self)->mRefEnt.renderfx |= 0x400u;
  if ( ( flags & 0x1000000 ) != 0 )
    *(unsigned int *)&FX_ELECTRICITY(self)->mRefEnt.renderfx |= 0x800u;
  if ( ( flags & 0x4000000 ) != 0 )
    *(unsigned int *)&FX_ELECTRICITY(self)->mRefEnt.renderfx |= 0x1000u;
  return flags;
}

/* ---- CElectricity__Draw  0x0048F120 ----  [CONFIRMED] */
int __fastcall CElectricity__Draw(int thisObj)
{
  int timeEnd;

  timeEnd = *(unsigned int *)&FX_ELECTRICITY(thisObj)->mTimeEnd;
  *(unsigned int *)&FX_ELECTRICITY(thisObj)->mRefEnt.fireRiseDir[0] = *(unsigned int *)&FX_ELECTRICITY(thisObj)->mChaos;
  FX_ELECTRICITY(thisObj)->mRefEnt.fireRiseDir[1] = (float)(int)(timeEnd - *(unsigned int *)&FX_ELECTRICITY(thisObj)->mTimeStart);   /* signed fild, retail 0x0048F137 */
  return re_AddRefEntityToScene(thisObj + 60, 0);
}

/* ---- CElectricity__Update  0x0048F160 ----  [CONFIRMED] */
char __fastcall CElectricity__Update( int thisObj )
{
  int          bolt;
  const float *orient;

  if ( FX_ELECTRICITY(thisObj)->mTimeStart > fxMTime )   /* signed, as retail: 0x0048F16C jle */
    return 0;

  CParticle__UpdateSize( thisObj );
  CParticle__UpdateRGB( thisObj );
  CParticle__UpdateAlpha( thisObj );

  bolt = *(unsigned int *)&FX_ELECTRICITY(thisObj)->mBoltFrame;
  if ( bolt )
  {
    orient = (const float *)CFxBoltFrame__GetOrientation( bolt );
    if ( !orient )
      return 0;
    OrientationPosToWorldPos( orient, (const float *)FX_ELECTRICITY(thisObj)->mOrigin1,   (float *)FX_ELECTRICITY(thisObj)->mRefEnt.origin );
    OrientationPosToWorldPos( orient, (const float *)FX_ELECTRICITY(thisObj)->mOrigin2, (float *)FX_ELECTRICITY(thisObj)->mRefEnt.oldorigin );
  }
  else
  {
    *(unsigned int *)&FX_ELECTRICITY(thisObj)->mRefEnt.origin[0] = *(unsigned int *)&FX_ELECTRICITY(thisObj)->mOrigin1[0];
    *(unsigned int *)&FX_ELECTRICITY(thisObj)->mRefEnt.origin[1] = *(unsigned int *)&FX_ELECTRICITY(thisObj)->mOrigin1[1];
    *(unsigned int *)&FX_ELECTRICITY(thisObj)->mRefEnt.origin[2] = *(unsigned int *)&FX_ELECTRICITY(thisObj)->mOrigin1[2];
    *(unsigned int *)&FX_ELECTRICITY(thisObj)->mRefEnt.oldorigin[0] = *(unsigned int *)&FX_ELECTRICITY(thisObj)->mOrigin2[0];
    *(unsigned int *)&FX_ELECTRICITY(thisObj)->mRefEnt.oldorigin[1] = *(unsigned int *)&FX_ELECTRICITY(thisObj)->mOrigin2[1];
    *(unsigned int *)&FX_ELECTRICITY(thisObj)->mRefEnt.oldorigin[2] = *(unsigned int *)&FX_ELECTRICITY(thisObj)->mOrigin2[2];
  }
  return 1;
}

/* ---- CElectricity__TypeID  0x0048F210 ----  [CONFIRMED] */
char CElectricity__TypeID()
{
  return 9;
}

/* ---- CElectricity__Archive  0x0048F220 ----  [CONFIRMED] */
void __fastcall CElectricity__Archive( byte *thisObj, int edxUnused, int archive )
{
  CParticle__Archive( thisObj, edxUnused, archive );
  FX_AR_FIELD( archive, thisObj, FX_ELECTRICITY_OFS( mOrigin2 ),  12 );
  FX_AR_FIELD( archive, thisObj, FX_ELECTRICITY_OFS( mChaos ),   4 );
  FX_AR_FIELD( archive, thisObj, FX_ELECTRICITY_OFS( reserved_0x14C ), 384 );
}

/* ---- CTail__ctor  0x0048F2A0 ----  [CONFIRMED] */
__declspec(noinline) unsigned int *__cdecl CTail__ctor(unsigned int *self)
{
  self[54] = 0;
  *self = (unsigned int)&vtbl_CTail;
  self[15] = 13;
  return self;
}

/* ---- CTail__scalar_dtor  0x0048F2C0 ----  [CONFIRMED] */
char *__fastcall CTail__scalar_dtor(char *thisObj, int edxUnused, char deleteFlags)
{
  CTail__dtor(thisObj);
  if ( (deleteFlags & 1) != 0 )
    CTail__operator_delete(thisObj);
  return thisObj;
}

/* ---- CTail__dtor  0x0048F2F0 ----  VERIFIED */
__declspec(noinline) void __fastcall CTail__dtor( void *self )
{
  unsigned int *thisObj = (unsigned int *)self;
  char   *bolt;

  FX_STANDARD_CALL(CTail__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  bolt  = (char *)thisObj[54];
  if ( bolt )
    CFxBoltFrame__Release( bolt );
}

/* ---- CTail__Cull  0x0048F310 ----  [CONFIRMED] */
char __fastcall CTail__Cull(float *thisObj)
{
  return SFxHelper__CullCylinder((int)&theFxHelper, thisObj + 32, thisObj + 36, thisObj[46], thisObj[46]);
}

/* ---- CTail__Draw  0x0048F340 ----  [CONFIRMED] */
int __fastcall CTail__Draw(unsigned int *thisObj)
{
  if ( (thisObj[6] & 0x100000) != 0 )
    thisObj[16] |= 8u;
  return re_AddRefEntityToScene(thisObj + 15, 0);
}

/* ---- CTail__Update  0x0048F360 ----  [CONFIRMED] */
char __fastcall CTail__Update(int thisObj)
{
  int oldY;
  int oldZ;
  unsigned int *origin;
  int boltFrame;
  const float *boltOrient;
  int originY;
  int originZ;

  if ( FX_TAIL(thisObj)->mTimeStart > fxMTime )   /* signed, as retail: 0x0048F36C jle */
    return 0;
  oldY = *(unsigned int *)&FX_TAIL(thisObj)->mOrigin1[1];
  oldZ = *(unsigned int *)&FX_TAIL(thisObj)->mOrigin1[2];
  origin = (unsigned int *)FX_TAIL(thisObj)->mOrigin1;
  *(unsigned int *)&FX_TAIL(thisObj)->mOldOrigin[0] = *(unsigned int *)&FX_TAIL(thisObj)->mOrigin1[0];
  *(unsigned int *)&FX_TAIL(thisObj)->mOldOrigin[1] = oldY;
  *(unsigned int *)&FX_TAIL(thisObj)->mOldOrigin[2] = oldZ;
  if ( !CParticle__UpdateOrigin(thisObj) )
    return 0;
  boltFrame = *(unsigned int *)&FX_TAIL(thisObj)->mBoltFrame;
  if ( boltFrame )
  {
    boltOrient = (const float *)CFxBoltFrame__GetOrientation(boltFrame);
    if ( !boltOrient )
      return 0;
    OrientationPosToWorldPos(boltOrient, (const float *)FX_TAIL(thisObj)->mOrigin1, (float *)FX_TAIL(thisObj)->mRefEnt.origin);
  }
  else
  {
    originY = *(unsigned int *)&FX_TAIL(thisObj)->mOrigin1[1];
    originZ = *(unsigned int *)&FX_TAIL(thisObj)->mOrigin1[2];
    *(unsigned int *)&FX_TAIL(thisObj)->mRefEnt.origin[0] = *origin;
    *(unsigned int *)&FX_TAIL(thisObj)->mRefEnt.origin[1] = originY;
    *(unsigned int *)&FX_TAIL(thisObj)->mRefEnt.origin[2] = originZ;
  }
  CParticle__UpdateSize(thisObj);
  CTail__UpdateLength_m(thisObj);
  CParticle__UpdateRGB(thisObj);
  CParticle__UpdateAlpha(thisObj);
  CTail__CalcNewEndpoint_m(thisObj);
  return 1;
}

/* ---- CTail__UpdateLength_m  0x0048F400 ----  VERIFIED */
void __cdecl CTail__UpdateLength_m( int self )
{
  int    flags = FX_TAIL(self)->mFlags;
  int    mode;
  float  linear = 1.0f;
  float  mTimeF;
  float frac   = 1.0f;                                 

  
  if ( ( flags & 0x1000 ) != 0 )
    linear = (float)( 1.0f - (float)( fxMTime - FX_TAIL(self)->mTimeStart )
                          / ( FX_TAIL(self)->mTimeEnd - FX_TAIL(self)->mTimeStart ) );

  

  mode = flags & 0xC000;
  if ( mode == 0x4000 )
  {
    mTimeF = (float)fxMTime;                           
    if ( (float)fxMTime > FX_TAIL(self)->mLengthParm )    
      frac = 1.0f - ( (float)mTimeF - FX_TAIL(self)->mLengthParm )
                 / ( (float)FX_TAIL(self)->mTimeEnd - FX_TAIL(self)->mLengthParm );
    if ( ( flags & 0x1000 ) != 0 )
      frac = ( frac + linear ) * 0.5f;
    linear = (float)frac;
  }
  else if ( mode == 0x8000 )
  {
    linear = (float)( cos( (float)( fxMTime - FX_TAIL(self)->mTimeStart )
                           * FX_TAIL(self)->mLengthParm ) * linear );
  }
  else if ( mode == 0xC000 )
  {
    if ( (float)fxMTime < FX_TAIL(self)->mLengthParm )
      frac = ( FX_TAIL(self)->mLengthParm - (float)fxMTime )
           / ( FX_TAIL(self)->mLengthParm - (float)FX_TAIL(self)->mTimeStart );
    else
      frac = 0.0f;
    if ( ( flags & 0x1000 ) != 0 )
      frac = ( frac + linear ) * 0.5f;
    linear = (float)frac;
  }

  if ((flags & 0x2000) != 0)
  {
    float fraction = rand() * 0.000030517578125f;
    linear = fraction * linear;
  }

  FX_TAIL(self)->mLength = (float)( ( 1.0f - linear ) * FX_TAIL(self)->mLengthEnd
                                    + linear * FX_TAIL(self)->mLengthStart );
}

/* ---- CTail__CalcNewEndpoint_m  0x0048F550 ----  VERIFIED */
void __cdecl CTail__CalcNewEndpoint_m( int self )
{
  int    bolt;
  float *orient;
  float  dir[3];
  float x, y, z;   

  dir[0] = FX_TAIL(self)->mOldOrigin[0] - FX_TAIL(self)->mOrigin1[0];
  dir[1] = FX_TAIL(self)->mOldOrigin[1] - FX_TAIL(self)->mOrigin1[1];
  dir[2] = FX_TAIL(self)->mOldOrigin[2] - FX_TAIL(self)->mOrigin1[2];
  VectorNormalize( dir );

  bolt = *(unsigned int *)&FX_TAIL(self)->mBoltFrame;
  if (bolt)
  {
    if (FX_BOLTFRAME(bolt)->mBolt.dobjHandle < 0)
      goto no_orientation;
    if (*(unsigned int *)&FX_BOLTFRAME(bolt)->mSkelTimeStamp != com_skelTimeStamp)
    {
      *(unsigned int *)&FX_BOLTFRAME(bolt)->mSkelTimeStamp = com_skelTimeStamp;
      if (!FX_GetBoneOrientation((unsigned int *)&FX_BOLTFRAME(bolt)->mBolt, (float *)FX_BOLTFRAME(bolt)->mOrientation))
      {
        *(unsigned int *)&FX_BOLTFRAME(bolt)->mBolt.dobjHandle = -1;
        *(unsigned int *)&FX_BOLTFRAME(bolt)->mBolt.boneIndex = -1;
        goto no_orientation;
      }
    }
    orient = (float *)FX_BOLTFRAME(bolt)->mOrientation;
    goto transform_endpoint;
no_orientation:
    orient = 0;
transform_endpoint:
  x = (float)dir[0] * FX_TAIL(self)->mLength + FX_TAIL(self)->mOrigin1[0];
  y = (float)dir[1] * FX_TAIL(self)->mLength + FX_TAIL(self)->mOrigin1[1];
  z = (float)dir[2] * FX_TAIL(self)->mLength + FX_TAIL(self)->mOrigin1[2];

  FX_TAIL(self)->mRefEnt.oldorigin[0] = z * orient[9]  + y * orient[6]  + x * orient[3]  + orient[0];
  FX_TAIL(self)->mRefEnt.oldorigin[1] = z * orient[10] + y * orient[7]  + x * orient[4]  + orient[1];
  FX_TAIL(self)->mRefEnt.oldorigin[2] = z * orient[11] + y * orient[8]  + x * orient[5]  + orient[2];
    return;
  }

    FX_TAIL(self)->mRefEnt.oldorigin[0] = dir[0] * FX_TAIL(self)->mLength + FX_TAIL(self)->mOrigin1[0];
    FX_TAIL(self)->mRefEnt.oldorigin[1] = dir[1] * FX_TAIL(self)->mLength + FX_TAIL(self)->mOrigin1[1];
    FX_TAIL(self)->mRefEnt.oldorigin[2] = dir[2] * FX_TAIL(self)->mLength + FX_TAIL(self)->mOrigin1[2];

  }

/* ---- CTail__TypeID  0x0048F690 ----  [CONFIRMED] */
char CTail__TypeID()
{
  return 3;
}

/* ---- CTail__Archive  0x0048F6A0 ----  [CONFIRMED] */
void __fastcall CTail__Archive( byte *thisObj, int edxUnused, int archive )
{
  CParticle__Archive( thisObj, edxUnused, archive );
  FX_AR_FIELD( archive, thisObj, FX_TAIL_OFS( mOldOrigin ), 12 );
  FX_AR_FIELD( archive, thisObj, FX_TAIL_OFS( mLengthStart ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_TAIL_OFS( mLengthEnd ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_TAIL_OFS( mLengthParm ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_TAIL_OFS( mLength ), 4 );
}

/* ---- CCylinder__ctor  0x0048F760 ----  [CONFIRMED] */
__declspec(noinline) unsigned int *__cdecl CCylinder__ctor(unsigned int *self)
{
  self[54] = 0;
  *self = (unsigned int)&vtbl_CCylinder;
  self[15] = 15;
  return self;
}

/* ---- CCylinder__scalar_dtor  0x0048F780 ----  [CONFIRMED] */
char *__fastcall CCylinder__scalar_dtor(char *thisObj, int edxUnused, char deleteFlags)
{
  CCylinder__dtor(thisObj);
  if ( (deleteFlags & 1) != 0 )
    CCylinder__operator_delete(thisObj);
  return thisObj;
}

/* ---- CCylinder__dtor  0x0048F7B0 ----  VERIFIED */
__declspec(noinline) void __fastcall CCylinder__dtor( void *self )
{
  unsigned int *thisObj = (unsigned int *)self;
  char   *bolt;

  FX_STANDARD_CALL(CCylinder__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  bolt  = (char *)thisObj[54];
  if ( bolt )
    CFxBoltFrame__Release( bolt );
}

/* ---- CCylinder__Cull  0x0048F7D0 ----  [CONFIRMED] */
char __fastcall CCylinder__Cull(float *thisObj)
{
  return SFxHelper__CullCylinder((int)&theFxHelper, thisObj + 32, thisObj + 36, thisObj[40], thisObj[46]);
}

/* ---- CCylinder__Draw  0x0048F800 ----  [CONFIRMED] */
int __fastcall CCylinder__Draw(unsigned int *thisObj)
{
  if ( (thisObj[6] & 0x100000) != 0 )
    thisObj[16] |= 8u;
  return re_AddRefEntityToScene(thisObj + 15, 0);
}

/* ---- CCylinder__Update  0x0048F820 ----  [CONFIRMED] */
char __fastcall CCylinder__Update( int thisObj )
{
  int          bolt;
  const float *orient;
  float        pos[3];

  if ( FX_CYLINDER(thisObj)->mTimeStart > fxMTime )   
    return 0;

  CParticle__UpdateSize( thisObj );
  CParticle__UpdateSize2( thisObj );
  CTail__UpdateLength_m( thisObj );
  CParticle__UpdateRGB( thisObj );
  CParticle__UpdateAlpha( thisObj );

  bolt = *(unsigned int *)&FX_CYLINDER(thisObj)->mBoltFrame;
  if ( bolt )
  {
    orient = (const float *)CFxBoltFrame__GetOrientation( bolt );
    if ( !orient )
      return 0;
    OrientationPosToWorldPos( orient, (const float *)FX_CYLINDER(thisObj)->mOrigin1, (float *)FX_CYLINDER(thisObj)->mRefEnt.origin );
    pos[0] = FX_CYLINDER(thisObj)->mRefEnt.axis[0][0] * FX_CYLINDER(thisObj)->mLength + FX_CYLINDER(thisObj)->mOrigin1[0];
    pos[1] = FX_CYLINDER(thisObj)->mRefEnt.axis[0][1] * FX_CYLINDER(thisObj)->mLength + FX_CYLINDER(thisObj)->mOrigin1[1];
    pos[2] = FX_CYLINDER(thisObj)->mRefEnt.axis[0][2] * FX_CYLINDER(thisObj)->mLength + FX_CYLINDER(thisObj)->mOrigin1[2];
    OrientationPosToWorldPos( orient, pos, (float *)FX_CYLINDER(thisObj)->mRefEnt.oldorigin );
  }
  else
  {
    *(unsigned int *)&FX_CYLINDER(thisObj)->mRefEnt.origin[0] = *(unsigned int *)&FX_CYLINDER(thisObj)->mOrigin1[0];
    *(unsigned int *)&FX_CYLINDER(thisObj)->mRefEnt.origin[1] = *(unsigned int *)&FX_CYLINDER(thisObj)->mOrigin1[1];
    *(unsigned int *)&FX_CYLINDER(thisObj)->mRefEnt.origin[2] = *(unsigned int *)&FX_CYLINDER(thisObj)->mOrigin1[2];
    

    FX_CYLINDER(thisObj)->mRefEnt.oldorigin[0] = FX_CYLINDER(thisObj)->mRefEnt.axis[0][0] * FX_CYLINDER(thisObj)->mLength
                           + FX_CYLINDER(thisObj)->mOrigin1[0];
    FX_CYLINDER(thisObj)->mRefEnt.oldorigin[1] = FX_CYLINDER(thisObj)->mRefEnt.axis[0][1] * FX_CYLINDER(thisObj)->mLength + FX_CYLINDER(thisObj)->mOrigin1[1];
    FX_CYLINDER(thisObj)->mRefEnt.oldorigin[2] = FX_CYLINDER(thisObj)->mRefEnt.axis[0][2] * FX_CYLINDER(thisObj)->mLength + FX_CYLINDER(thisObj)->mOrigin1[2];
  }
  return 1;
}

/* ---- CCylinder__TypeID  0x0048F920 ----  [CONFIRMED] */
char CCylinder__TypeID()
{
  return 4;
}

/* ---- CCylinder__Archive  0x0048F930 ----  [CONFIRMED] */
void __fastcall CCylinder__Archive(byte *thisObj, int edxUnused, int archive)
{
  CTail__Archive( thisObj, edxUnused, archive );
}

/* ---- CEmitter__ctor  0x0048F940 ----  [CONFIRMED] */
__declspec(noinline) unsigned int *__cdecl CEmitter__ctor(unsigned int *self)
{
  self[54] = 0;
  *self = (unsigned int)&vtbl_CEmitter;
  self[15] = 1;
  return self;
}

/* ---- CEmitter__scalar_dtor  0x0048F960 ----  [CONFIRMED] */
char *__fastcall CEmitter__scalar_dtor(char *thisObj, int edxUnused, char deleteFlags)
{
  CEmitter__dtor(thisObj);
  if ( (deleteFlags & 1) != 0 )
    CEmitter__operator_delete(thisObj);
  return thisObj;
}

/* ---- CEmitter__dtor  0x0048F990 ----  VERIFIED */
__declspec(noinline) void __fastcall CEmitter__dtor( void *self )
{
  unsigned int *thisObj = (unsigned int *)self;
  char   *bolt;

  FX_STANDARD_CALL(CEmitter__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  bolt  = (char *)thisObj[54];
  if ( bolt )
    CFxBoltFrame__Release( bolt );
}

/* ---- CEmitter__Cull  0x0048F9B0 ----  [CONFIRMED] */
char CEmitter__Cull()
{
  return 0;
}

/* ---- CEmitter__Draw  0x0048F9C0 ----  [CONFIRMED] */
void __fastcall CEmitter__Draw(unsigned int *thisObj)
{


  if ( (thisObj[6] & 0x1000000) != 0 )
    ( *(void (**)(FX_ANYARGS))&re.AddRefEntityToScene )(thisObj + 15, 0);

}

/* Retail fld float / fadd qword 2^-30 / fistp: round-to-nearest under the
 * default control word, not the truncating __ftol2 an (int) cast compiles to.
 * Same idiom as FastRound 0x00408370 (cl_console_mp.c), which is not built
 * into CodMP-ded. */
static int FX_FistpRound( float f )
{
  double bias = 9.313225746154785e-10;   /* qword 0x3E10000000000000 built at 0x0049007F/0x0049008E */
  int    i;

  __asm fld   f
  __asm fadd  bias
  __asm fistp i
  return i;
}

/* ---- CEmitter__Update  0x0048F9E0 ----  [CONFIRMED] */
/* CEmitter::Update.  The inlined FX_FistpRound asm keeps `this` in its stack
 * home: every use goes through thisObj (no register copies), so it is
 * reloaded after each store as in retail. */
#if defined( _MSC_VER ) && _MSC_VER < 1310
#pragma optimize( "p", on )
#endif
char __fastcall CEmitter__Update(int thisObj)
{
  const float *orient;
  const float *boneOrient;
  char        *bolt;
  int         *boltInfo;
  vec3_t       oldOrigin;          /* also the emit-step distance vector */
  vec3_t       boltVel;
  vec3_t       scaledAxis[3];
  vec3_t       lastPos;
  vec3_t       emitOrigin;
  vec3_t       worldOrigin;
  vec3_t       newVel;
  float        vx, vy, vz;
  float        ax, ay, az;
  int          i;
  int          emitTime;
  int          stepMsec;
  int          overshoot;
  float        dt;
  float        step;
  float        stepSq;
  float        t;
  float        tc;
  float        halfTSq;
  float        tq;
  float        t2, t3, t4;
  float        velSq, velDotAccel, accelSq;
  float        denom;
  float        num;

  orient = 0;
  if ( FX_EMITTER(thisObj)->mTimeStart > fxMTime )   /* 0x0048F9F6 cmp / jle: signed */
    return 0;
  *(int *)&oldOrigin[0] = *(int *)&FX_EMITTER(thisObj)->mOrigin1[0];
  *(int *)&oldOrigin[1] = *(int *)&FX_EMITTER(thisObj)->mOrigin1[1];
  *(int *)&oldOrigin[2] = *(int *)&FX_EMITTER(thisObj)->mOrigin1[2];
  if ( !CParticle__UpdateOrigin( thisObj ) )
    return 0;

  /* not moving: damp the spin */
  if ( oldOrigin[0] == FX_EMITTER(thisObj)->mOrigin1[0]
    && oldOrigin[1] == FX_EMITTER(thisObj)->mOrigin1[1]
    && oldOrigin[2] == FX_EMITTER(thisObj)->mOrigin1[2] )
  {
    FX_EMITTER(thisObj)->mAngleDelta[0] = FX_EMITTER(thisObj)->mAngleDelta[0] * 0.69999999f;   /* fmul dword [0x005691A0] */
    FX_EMITTER(thisObj)->mAngleDelta[1] = FX_EMITTER(thisObj)->mAngleDelta[1] * 0.69999999f;
    FX_EMITTER(thisObj)->mAngleDelta[2] = FX_EMITTER(thisObj)->mAngleDelta[2] * 0.69999999f;
  }
  CEmitter__UpdateAngles_m( (float *)thisObj );
  CParticle__UpdateSize( thisObj );

  if ( FX_EMITTER(thisObj)->mBoltFrame )
  {
    orient = (const float *)CFxBoltFrame__GetOrientation( (int)FX_EMITTER(thisObj)->mBoltFrame );
    if ( !orient )
      return 0;
  }

  if ( FX_EMITTER(thisObj)->mFlags & 0x1000000 )
  {
    if ( FX_EMITTER(thisObj)->mBoltFrame )
    {
      OrientationPosToWorldPos( orient, FX_EMITTER(thisObj)->mOrigin1, FX_EMITTER(thisObj)->mRefEnt.origin );
      for ( i = 0; i < 3; i++ )
      {
        scaledAxis[i][0] = FX_EMITTER(thisObj)->mRefEnt.axis[i][0] * FX_EMITTER(thisObj)->mRefEnt.radius;
        scaledAxis[i][1] = FX_EMITTER(thisObj)->mRefEnt.axis[i][1] * FX_EMITTER(thisObj)->mRefEnt.radius;
        scaledAxis[i][2] = FX_EMITTER(thisObj)->mRefEnt.axis[i][2] * FX_EMITTER(thisObj)->mRefEnt.radius;
        OrientationDirToWorldDir( orient, scaledAxis[i], FX_EMITTER(thisObj)->mRefEnt.axis[i] );
      }
      *(int *)&FX_EMITTER(thisObj)->mRefEnt.nonNormalizedAxes = *(int *)&FX_EMITTER(thisObj)->mRefEnt.radius;

      /* bolt velocity since the last emit */
      if ( FX_EMITTER(thisObj)->mOldTime < fxMTime )
      {
        boltVel[0] = orient[0] - FX_EMITTER(thisObj)->mLastBoltOrigin[0];
        boltVel[1] = orient[1] - FX_EMITTER(thisObj)->mLastBoltOrigin[1];
        boltVel[2] = orient[2] - FX_EMITTER(thisObj)->mLastBoltOrigin[2];
        dt = (float)( fxMTime - FX_EMITTER(thisObj)->mOldTime ) * 0.001f;   /* 0x0048FBCA fmul dword [0x00568E6C] */
        boltVel[0] = dt * boltVel[0];
        boltVel[1] = dt * boltVel[1];
        boltVel[2] = dt * boltVel[2];
      }
      else
      {
        VectorClear( boltVel );
      }
    }
    else
    {
      *(int *)&FX_EMITTER(thisObj)->mRefEnt.origin[0] = *(int *)&FX_EMITTER(thisObj)->mOrigin1[0];
      *(int *)&FX_EMITTER(thisObj)->mRefEnt.origin[1] = *(int *)&FX_EMITTER(thisObj)->mOrigin1[1];
      *(int *)&FX_EMITTER(thisObj)->mRefEnt.origin[2] = *(int *)&FX_EMITTER(thisObj)->mOrigin1[2];
      FX_EMITTER(thisObj)->mRefEnt.axis[0][0] = FX_EMITTER(thisObj)->mRefEnt.radius * FX_EMITTER(thisObj)->mRefEnt.axis[0][0];
      FX_EMITTER(thisObj)->mRefEnt.axis[0][1] = FX_EMITTER(thisObj)->mRefEnt.radius * FX_EMITTER(thisObj)->mRefEnt.axis[0][1];
      FX_EMITTER(thisObj)->mRefEnt.axis[0][2] = FX_EMITTER(thisObj)->mRefEnt.radius * FX_EMITTER(thisObj)->mRefEnt.axis[0][2];
      FX_EMITTER(thisObj)->mRefEnt.axis[1][0] = FX_EMITTER(thisObj)->mRefEnt.radius * FX_EMITTER(thisObj)->mRefEnt.axis[1][0];
      FX_EMITTER(thisObj)->mRefEnt.axis[1][1] = FX_EMITTER(thisObj)->mRefEnt.radius * FX_EMITTER(thisObj)->mRefEnt.axis[1][1];
      FX_EMITTER(thisObj)->mRefEnt.axis[1][2] = FX_EMITTER(thisObj)->mRefEnt.radius * FX_EMITTER(thisObj)->mRefEnt.axis[1][2];
      FX_EMITTER(thisObj)->mRefEnt.axis[2][0] = FX_EMITTER(thisObj)->mRefEnt.radius * FX_EMITTER(thisObj)->mRefEnt.axis[2][0];
      FX_EMITTER(thisObj)->mRefEnt.axis[2][1] = FX_EMITTER(thisObj)->mRefEnt.radius * FX_EMITTER(thisObj)->mRefEnt.axis[2][1];
      FX_EMITTER(thisObj)->mRefEnt.axis[2][2] = FX_EMITTER(thisObj)->mRefEnt.radius * FX_EMITTER(thisObj)->mRefEnt.axis[2][2];
      *(int *)&FX_EMITTER(thisObj)->mRefEnt.nonNormalizedAxes = *(int *)&FX_EMITTER(thisObj)->mRefEnt.radius;
    }
  }

  if ( FX_EMITTER(thisObj)->mFlags & 0x10000000 )
  {
    /* emit one effect every mStepDistance units travelled, in 12 ms steps */
    *(int *)&step = *(int *)&FX_EMITTER(thisObj)->mStepDistance;
    emitTime = FX_EMITTER(thisObj)->mOldTime;
    stepMsec = 0;
    stepSq = step * step;
    while ( emitTime < fxMTime )
    {
      stepMsec += 12;
      t = (float)stepMsec * 0.001f;                   /* 0x0048FD2B fmul dword [0x00568E6C] */
      *(int *)&tc = *(int *)&t;
      halfTSq = tc * tc * 0.5f;
      bolt = FX_EMITTER(thisObj)->mBoltFrame;
      lastPos[0] = FX_EMITTER(thisObj)->mLastBoltOrigin[0] + FX_EMITTER(thisObj)->mOldOrigin[0];
      lastPos[1] = FX_EMITTER(thisObj)->mLastBoltOrigin[1] + FX_EMITTER(thisObj)->mOldOrigin[1];
      lastPos[2] = FX_EMITTER(thisObj)->mLastBoltOrigin[2] + FX_EMITTER(thisObj)->mOldOrigin[2];
      emitOrigin[0] = tc * FX_EMITTER(thisObj)->mOldVelocity[0] + halfTSq * FX_EMITTER(thisObj)->mAccel[0] + FX_EMITTER(thisObj)->mOldOrigin[0];
      emitOrigin[1] = tc * FX_EMITTER(thisObj)->mOldVelocity[1] + halfTSq * FX_EMITTER(thisObj)->mAccel[1] + FX_EMITTER(thisObj)->mOldOrigin[1];
      emitOrigin[2] = tc * FX_EMITTER(thisObj)->mOldVelocity[2] + halfTSq * FX_EMITTER(thisObj)->mAccel[2] + FX_EMITTER(thisObj)->mOldOrigin[2];
      if ( bolt )
      {
        emitOrigin[0] = tc * boltVel[0] + emitOrigin[0];
        emitOrigin[1] = tc * boltVel[1] + emitOrigin[1];
        emitOrigin[2] = tc * boltVel[2] + emitOrigin[2];
      }
      oldOrigin[0] = lastPos[0] - emitOrigin[0];
      oldOrigin[1] = lastPos[1] - emitOrigin[1];
      oldOrigin[2] = lastPos[2] - emitOrigin[2];
      if ( oldOrigin[2] * oldOrigin[2] + oldOrigin[1] * oldOrigin[1] + oldOrigin[0] * oldOrigin[0] < stepSq )
      {
        emitTime += 12;
        continue;
      }

      /* far enough: play the effect here */
      if ( bolt )
      {
        boneOrient = (const float *)CFxBoltFrame__GetOrientation( (int)bolt );
        boltInfo = (int *)( FX_EMITTER(thisObj)->mBoltFrame + 60 );
        worldOrigin[0] = emitOrigin[2] * boneOrient[9] + emitOrigin[1] * boneOrient[6] + emitOrigin[0] * boneOrient[3] + boneOrient[0];
        worldOrigin[1] = emitOrigin[2] * boneOrient[10] + emitOrigin[1] * boneOrient[7] + emitOrigin[0] * boneOrient[4] + boneOrient[1];
        worldOrigin[2] = emitOrigin[2] * boneOrient[11] + emitOrigin[1] * boneOrient[8] + emitOrigin[0] * boneOrient[5] + boneOrient[2];
        CFxScheduler__PlayEffect_id_axis( theFxScheduler, FX_EMITTER(thisObj)->mEmitterFxID, worldOrigin,
                                          (int *)FX_EMITTER(thisObj)->mRefEnt.axis,
                                          boltInfo );
      }
      else
      {
        CFxScheduler__PlayEffect_id_axis( theFxScheduler, FX_EMITTER(thisObj)->mEmitterFxID, emitOrigin,
                                          (int *)FX_EMITTER(thisObj)->mRefEnt.axis, 0 );
      }

      /* time at which the step distance was actually reached: solve
       * |vel*t + accel*t^2/2|^2 = step^2 with one Newton step */
      *(int *)&vz = *(int *)&FX_EMITTER(thisObj)->mOldVelocity[2];
      *(int *)&vy = *(int *)&FX_EMITTER(thisObj)->mOldVelocity[1];
      *(int *)&vx = *(int *)&FX_EMITTER(thisObj)->mOldVelocity[0];
      *(int *)&az = *(int *)&FX_EMITTER(thisObj)->mAccel[2];
      *(int *)&ay = *(int *)&FX_EMITTER(thisObj)->mAccel[1];
      *(int *)&ax = *(int *)&FX_EMITTER(thisObj)->mAccel[0];
      *(int *)&tq = *(int *)&t;
      velSq = vx * vx + vy * vy + vz * vz;
      velDotAccel = ( FX_EMITTER(thisObj)->mOldVelocity[2] * FX_EMITTER(thisObj)->mAccel[2]
                    + FX_EMITTER(thisObj)->mOldVelocity[1] * FX_EMITTER(thisObj)->mAccel[1] )
                  + FX_EMITTER(thisObj)->mOldVelocity[0] * FX_EMITTER(thisObj)->mAccel[0];
      accelSq = ax * ax + ay * ay + az * az;
      t2 = tq * tq;
      t3 = t2 * tq;
      t4 = t3 * tq;
      denom = ( t3 * accelSq + t2 * velDotAccel * 3.0f ) + ( tq * velSq + tq * velSq );
      if ( denom != 0.0f )
      {
        num = t4 * accelSq * 0.25f + t3 * velDotAccel + t2 * velSq - stepSq;
        num = num / denom * 1000.0f;
        overshoot = FX_FistpRound( num );                 /* 0x004900CD-0x004900D8 */
        stepMsec -= overshoot;
        if ( stepMsec < emitTime - FX_EMITTER(thisObj)->mOldTime )
          stepMsec = emitTime - FX_EMITTER(thisObj)->mOldTime;
        t = (float)stepMsec * 0.001f;                 /* 0x00490110 fmul dword [0x00568E6C] */
        *(int *)&tc = *(int *)&t;
        halfTSq = tc * tc * 0.5f;
        emitOrigin[0] = tc * FX_EMITTER(thisObj)->mOldVelocity[0] + halfTSq * FX_EMITTER(thisObj)->mAccel[0] + FX_EMITTER(thisObj)->mOldOrigin[0];
        emitOrigin[1] = tc * FX_EMITTER(thisObj)->mOldVelocity[1] + halfTSq * FX_EMITTER(thisObj)->mAccel[1] + FX_EMITTER(thisObj)->mOldOrigin[1];
        emitOrigin[2] = tc * FX_EMITTER(thisObj)->mOldVelocity[2] + halfTSq * FX_EMITTER(thisObj)->mAccel[2] + FX_EMITTER(thisObj)->mOldOrigin[2];
      }

      newVel[0] = t * FX_EMITTER(thisObj)->mAccel[0] + FX_EMITTER(thisObj)->mOldVelocity[0];
      newVel[1] = t * FX_EMITTER(thisObj)->mAccel[1] + FX_EMITTER(thisObj)->mOldVelocity[1];
      newVel[2] = t * FX_EMITTER(thisObj)->mAccel[2] + FX_EMITTER(thisObj)->mOldVelocity[2];
      VectorCopy( emitOrigin, FX_EMITTER(thisObj)->mOldOrigin );
      VectorCopy( newVel, FX_EMITTER(thisObj)->mOldVelocity );
      FX_EMITTER(thisObj)->mLastBoltOrigin[0] = t * boltVel[0] + FX_EMITTER(thisObj)->mLastBoltOrigin[0];
      FX_EMITTER(thisObj)->mLastBoltOrigin[1] = t * boltVel[1] + FX_EMITTER(thisObj)->mLastBoltOrigin[1];
      FX_EMITTER(thisObj)->mLastBoltOrigin[2] = t * boltVel[2] + FX_EMITTER(thisObj)->mLastBoltOrigin[2];
      FX_EMITTER(thisObj)->mOldTime += stepMsec;
      emitTime = FX_EMITTER(thisObj)->mOldTime;
      stepMsec = 0;

      /* next step distance: density +- variance */
      FX_EMITTER(thisObj)->mStepDistance = ( (float)rand() / 32768.0f * 2.0f - 1.0f ) * FX_EMITTER(thisObj)->mVariance + FX_EMITTER(thisObj)->mDensity;
      *(int *)&step = *(int *)&FX_EMITTER(thisObj)->mStepDistance;
      stepSq = step * step;
    }
  }
  return 1;
}

#if defined( _MSC_VER ) && _MSC_VER < 1310
#pragma optimize( "p", off )
#endif
/* ---- CEmitter__UpdateAngles_m  0x00490300 ----  VERIFIED */
/* /Op code in retail: each frame-time conversion goes through a 4-byte slot. */
#if defined( _MSC_VER ) && _MSC_VER < 1310
#pragma optimize( "p", on )
#endif
void AnglesToAxis( const vec3_t angles, vec3_t axis[3] );   /* com_math.c */
void __cdecl CEmitter__UpdateAngles_m( float *self )
{
  /* mAngles += mAngleDelta * frameTime * 0.01 */
  VectorMA( FX_EMITTER(self)->mAngles, (float)fxHelperFrameTime * 0.0099999998f, FX_EMITTER(self)->mAngleDelta, FX_EMITTER(self)->mAngles );

  /* com_math's AnglesToAxis, inlined by LTCG: its axis parameter is the
   * ESI base (forward) that axis[1] and axis[2] are addressed from */
  AnglesToAxis( FX_EMITTER(self)->mAngles, FX_EMITTER(self)->mRefEnt.axis );
}
#if defined( _MSC_VER ) && _MSC_VER < 1310
#pragma optimize( "p", off )
#endif

/* ---- CEmitter__TypeID  0x004903C0 ----  [CONFIRMED] */
char CEmitter__TypeID()
{
  return 5;
}

/* ---- CEmitter__Archive  0x004903D0 ----  [CONFIRMED] */
void __fastcall CEmitter__Archive( int thisObj, int edxUnused, int archive )
{
  FxArchive *ar = (FxArchive *)archive;

  CParticle__Archive( (byte *)thisObj, edxUnused, archive );
  FX_AR_FIELD( ar, thisObj, FX_EMITTER_OFS( mOldOrigin ), 12 );
  FX_AR_FIELD( ar, thisObj, FX_EMITTER_OFS( mOldVelocity ), 12 );
  FX_AR_FIELD( ar, thisObj, FX_EMITTER_OFS( mLastBoltOrigin ), 12 );
  FX_AR_FIELD( ar, thisObj, FX_EMITTER_OFS( mOldTime ),  4 );
  FX_AR_FIELD( ar, thisObj, FX_EMITTER_OFS( mStepDistance ),  4 );
  FX_AR_FIELD( ar, thisObj, FX_EMITTER_OFS( mAngles ), 12 );
  FX_AR_FIELD( ar, thisObj, FX_EMITTER_OFS( mAngleDelta ), 12 );

  /* emitter effect handle @ +384 archives as an int16 index into the
   * per-archive remap table (FxArchive.table @ +20). */
  CFxArchive__ArchiveEffectID( archive, (unsigned int *)&FX_EMITTER(thisObj)->mEmitterFxID );

  FX_AR_FIELD( ar, thisObj, FX_EMITTER_OFS( mDensity ), 4 );
  FX_AR_FIELD( ar, thisObj, FX_EMITTER_OFS( mVariance ), 4 );

  if ( !*(unsigned int *)&FX_EMITTER(thisObj)->mRefEnt.dobj )
    *(unsigned int *)&FX_EMITTER(thisObj)->mFlags &= ~0x1000000u;
}

/* ---- CLight__ctor  0x00490570 ----  [CONFIRMED] */
__declspec(noinline) unsigned int *__cdecl CLight__ctor(unsigned int *self)
{
  self[54] = 0;
  *self = (unsigned int)&vtbl_CLight;
  return self;
}

/* ---- CLight__scalar_dtor  0x00490590 ----  [CONFIRMED] */
char *__fastcall CLight__scalar_dtor(char *thisObj, int edxUnused, char deleteFlags)
{
  CLight__dtor(thisObj);
  if ( (deleteFlags & 1) != 0 )
    CLight__operator_delete(thisObj);
  return thisObj;
}

/* ---- CLight__dtor  0x004905C0 ----  VERIFIED */
__declspec(noinline) void __fastcall CLight__dtor( void *self )
{
  unsigned int *thisObj = (unsigned int *)self;
  char   *bolt;

  FX_STANDARD_CALL(CLight__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  bolt  = (char *)thisObj[54];
  if ( bolt )
    CFxBoltFrame__Release( bolt );
}

/* ---- CLight__Cull  0x004905E0 ----  [CONFIRMED] */
char __fastcall CLight__Cull(float *thisObj)
{
  return SFxHelper__CullSphere((int)&theFxHelper, thisObj + 32, thisObj[46]);
}

/* ---- CLight__Draw  0x00490600 ----  [CONFIRMED] */
void __fastcall CLight__Draw(float *thisObj)
{
  SFxHelper__AddLightToScene((int)&theFxHelper, thisObj + 32, thisObj[46], thisObj[18], thisObj[19], thisObj[20]);
}

/* ---- CLight__Update  0x00490630 ----  [CONFIRMED] */
char __fastcall CLight__Update( int thisObj )
{
  int          bolt;
  const float *orient;

  if ( FX_LIGHT(thisObj)->mTimeStart > fxMTime )   /* 0x0049063C jle: signed */
    return 0;

  CLight__UpdateSize_m( thisObj );
  CLight__UpdateRGB_m( thisObj );

  bolt = *(unsigned int *)&FX_LIGHT(thisObj)->mBoltFrame;
  if ( bolt )
  {
    orient = (const float *)CFxBoltFrame__GetOrientation( bolt );
    if ( !orient )
      return 0;
    OrientationPosToWorldPos( orient, (const float *)FX_LIGHT(thisObj)->mOrigin1, (float *)FX_LIGHT(thisObj)->mRefEnt.origin );
  }
  else
  {
    *(unsigned int *)&FX_LIGHT(thisObj)->mRefEnt.origin[0] = *(unsigned int *)&FX_LIGHT(thisObj)->mOrigin1[0];
    *(unsigned int *)&FX_LIGHT(thisObj)->mRefEnt.origin[1] = *(unsigned int *)&FX_LIGHT(thisObj)->mOrigin1[1];
    *(unsigned int *)&FX_LIGHT(thisObj)->mRefEnt.origin[2] = *(unsigned int *)&FX_LIGHT(thisObj)->mOrigin1[2];
  }
  return 1;
}

/* ---- CLight__UpdateSize_m  0x004906A0 ----  VERIFIED */
void __cdecl CLight__UpdateSize_m( int self )
{
  int    flags = FX_LIGHT(self)->mFlags;
  int    mode;
  float  linear = 1.0f;
  float  mTimeF;
  float frac   = 1.0f;                                 

  
  if ( ( flags & 0x100 ) != 0 )
    linear = (float)( 1.0f - (float)( fxMTime - FX_LIGHT(self)->mTimeStart )
                          / ( FX_LIGHT(self)->mTimeEnd - FX_LIGHT(self)->mTimeStart ) );

  

  mode = flags & 0xC00;
  if ( mode == 0x400 )
  {
    mTimeF = (float)fxMTime;                           
    if ( (float)fxMTime > FX_LIGHT(self)->mSizeParm )    
      frac = 1.0f - ( (float)mTimeF - FX_LIGHT(self)->mSizeParm )
                 / ( (float)FX_LIGHT(self)->mTimeEnd - FX_LIGHT(self)->mSizeParm );
    if ( ( flags & 0x100 ) != 0 )
      frac = ( frac + linear ) * 0.5f;
    linear = (float)frac;
  }
  else if ( mode == 0x800 )
  {
    linear = (float)( cos( (float)( fxMTime - FX_LIGHT(self)->mTimeStart )
                           * FX_LIGHT(self)->mSizeParm ) * linear );
  }
  else if ( mode == 0xC00 )
  {
    if ( (float)fxMTime < FX_LIGHT(self)->mSizeParm )
      frac = ( FX_LIGHT(self)->mSizeParm - (float)fxMTime )
           / ( FX_LIGHT(self)->mSizeParm - (float)FX_LIGHT(self)->mTimeStart );
    else
      frac = 0.0f;
    if ( ( flags & 0x100 ) != 0 )
      frac = ( frac + linear ) * 0.5f;
    linear = (float)frac;
  }

  if ((flags & 0x200) != 0)
  {
    float fraction = rand() * 0.000030517578125f;
    linear = fraction * linear;
  }

  FX_LIGHT(self)->mRefEnt.radius = (float)( ( 1.0f - linear ) * FX_LIGHT(self)->mSizeEnd
                                    + linear * FX_LIGHT(self)->mSizeStart );
}

/* ---- CLight__UpdateRGB_m  0x004907F0 ----  VERIFIED */
void __cdecl CLight__UpdateRGB_m( int self )
{
  int    flags;
  int    mode;
  float blend;        
  float  scale;        
  float  scaleTmp;     

     
     
  float  rgb[3];       

  flags = *(unsigned int *)&FX_LIGHT(self)->mFlags;
  blend = 1.0f;
  scale = 1.0f;
  
  if ( ( flags & 0x10 ) != 0 )
    scale = 1.0f - (float)( fxMTime - FX_LIGHT(self)->mTimeStart )
                / ( FX_LIGHT(self)->mTimeEnd - FX_LIGHT(self)->mTimeStart );

  mode = flags & 0xC0;
  if ( mode == 0x40 )
  {
    if ( (float)fxMTime > FX_LIGHT(self)->mRGBParm )
    {
      scaleTmp = (float)fxMTime;
      blend = 1.0f - ( scaleTmp - FX_LIGHT(self)->mRGBParm )
                  / ( (float)FX_LIGHT(self)->mTimeEnd - FX_LIGHT(self)->mRGBParm );
    }
    if ( ( flags & 0x10 ) != 0 )
      blend = ( blend + scale ) * 0.5f;
    scale = blend;
  }
  else if ( mode == 0x80 )
  {
    scale = cos( (float)( fxMTime - FX_LIGHT(self)->mTimeStart ) * FX_LIGHT(self)->mRGBParm ) * scale;   
  }
  else if ( mode == 0xC0 )
  {
    if ((float)fxMTime < FX_LIGHT(self)->mRGBParm)
      blend = ( FX_LIGHT(self)->mRGBParm - (float)fxMTime )
            / ( FX_LIGHT(self)->mRGBParm - (float)FX_LIGHT(self)->mTimeStart );
    else
      blend = 0.0f;
    if ( ( flags & 0x10 ) != 0 )
      blend = ( blend + scale ) * 0.5f;
    scale = blend;
  }

  if ((flags & 0x20) != 0)
  {
    float fraction = rand() * 0.000030517578125f;
    scale = fraction * scale;
  }   

  rgb[0] = scale * FX_LIGHT(self)->mRGBStart[0];
  rgb[1] = scale * FX_LIGHT(self)->mRGBStart[1];
  rgb[2] = scale * FX_LIGHT(self)->mRGBStart[2];
  scale = 1.0f - scale;
  FX_LIGHT(self)->mRefEnt.lightingOrigin[0] = scale * FX_LIGHT(self)->mRGBEnd[0] + rgb[0];
  FX_LIGHT(self)->mRefEnt.lightingOrigin[1] = scale * FX_LIGHT(self)->mRGBEnd[1] + rgb[1];
  FX_LIGHT(self)->mRefEnt.lightingOrigin[2] = scale * FX_LIGHT(self)->mRGBEnd[2] + rgb[2];
}

/* ---- CLight__TypeID  0x00490970 ----  [CONFIRMED] */
char CLight__TypeID()
{
  return 11;
}

/* ---- CLight__Archive  0x00490980 ----  [CONFIRMED] */
void __fastcall CLight__Archive( byte *thisObj, int edxUnused, int archive )
{
  CEffect__Archive( (int)thisObj, edxUnused, archive );
  FX_AR_FIELD( archive, thisObj, FX_LIGHT_OFS( mSizeStart ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_LIGHT_OFS( mSizeEnd ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_LIGHT_OFS( mSizeParm ),  4 );
  FX_AR_FIELD( archive, thisObj, FX_LIGHT_OFS( mRGBStart ), 12 );
  FX_AR_FIELD( archive, thisObj, FX_LIGHT_OFS( mRGBEnd ), 12 );
  FX_AR_FIELD( archive, thisObj, FX_LIGHT_OFS( mRGBParm ), 4 );
}

/* ---- cand_CFxPrimType14__Cull  0x00490A70 ----  VERIFIED */
char cand_CFxPrimType14__Cull()
{
  return 0;
}

/* one control point of the patch (84 bytes from +220) */
typedef struct
{
  float xyz[3];      /* +0  */
  float unused0[6];
  float rgb[3];      /* +36 */
  float unused1[2];
  float alpha;       /* +56 */
  float unused2[4];
  float st[2];       /* +76 */
} fxPrimType14Point_t;
typedef struct { float xyz[3]; float st[2]; float st2[2]; unsigned char modulate[4]; } fxPrimType14Vert_t;

/* ---- cand_CFxPrimType14__Draw  0x00490A80 ----  VERIFIED */
/* Two triangles through ONE 3-vertex polyVert_t buffer (retail esp+10h); the
 * second triangle rewrites the same buffer.  Filled field by field: the three
 * positions, then each vertex's colour (rgb scaled by alpha into one vec3_t,
 * retail esp+4; modulate[3] and st2 stay unwritten), then the three st pairs. */
int __fastcall cand_CFxPrimType14__Draw( int thisObj )
{
  fxPrimType14Vert_t   verts[3];
  vec3_t               color;
  fxPrimType14Point_t *pt = (fxPrimType14Point_t *)( thisObj + 220 );

  VectorCopy( pt[0].xyz, verts[0].xyz );
  VectorCopy( pt[1].xyz, verts[1].xyz );
  VectorCopy( pt[3].xyz, verts[2].xyz );
  VectorScale( pt[0].rgb, pt[0].alpha, color );
  verts[0].modulate[0] = color[0];
  verts[0].modulate[1] = color[1];
  verts[0].modulate[2] = color[2];
  VectorScale( pt[1].rgb, pt[1].alpha, color );
  verts[1].modulate[0] = color[0];
  verts[1].modulate[1] = color[1];
  verts[1].modulate[2] = color[2];
  VectorScale( pt[3].rgb, pt[3].alpha, color );
  verts[2].modulate[0] = color[0];
  verts[2].modulate[1] = color[1];
  verts[2].modulate[2] = color[2];
  verts[0].st[0] = pt[0].st[0];
  verts[0].st[1] = pt[0].st[1];
  verts[1].st[0] = pt[1].st[0];
  verts[1].st[1] = pt[1].st[1];
  verts[2].st[0] = pt[3].st[0];
  verts[2].st[1] = pt[3].st[1];
  re_AddPolyToScene( *(unsigned int *)( thisObj + 556 ), 3, verts );

  VectorCopy( pt[3].xyz, verts[0].xyz );
  VectorCopy( pt[2].xyz, verts[1].xyz );
  VectorCopy( pt[1].xyz, verts[2].xyz );
  VectorScale( pt[3].rgb, pt[3].alpha, color );
  verts[0].modulate[0] = color[0];
  verts[0].modulate[1] = color[1];
  verts[0].modulate[2] = color[2];
  VectorScale( pt[2].rgb, pt[2].alpha, color );
  verts[1].modulate[0] = color[0];
  verts[1].modulate[1] = color[1];
  verts[1].modulate[2] = color[2];
  VectorScale( pt[1].rgb, pt[1].alpha, color );
  verts[2].modulate[0] = color[0];
  verts[2].modulate[1] = color[1];
  verts[2].modulate[2] = color[2];
  verts[0].st[0] = pt[3].st[0];
  verts[0].st[1] = pt[3].st[1];
  verts[1].st[0] = pt[2].st[0];
  verts[1].st[1] = pt[2].st[1];
  verts[2].st[0] = pt[1].st[0];
  verts[2].st[1] = pt[1].st[1];
  return re_AddPolyToScene( *(unsigned int *)( thisObj + 556 ), 3, verts );
}

/* ---- cand_CFxPrimType14__Update  0x00490DC0 ----  VERIFIED */
char __fastcall cand_CFxPrimType14__Update( float *thisObj )
{
  int    startTime;
  int    endTime;
  float *elem;
  float  frac;
  float  inv;
  float  alpha;
  float  scale;
  int    remaining;

  startTime = *( (unsigned int *)thisObj + 4 );
  if ( startTime > fxMTime )
    return 0;
  endTime = *( (unsigned int *)thisObj + 5 );
  frac = (float)( endTime - fxMTime ) / ( endTime - startTime );
  elem = thisObj + 69;
  remaining = 4;
  inv = 1.0f - frac;
  do
  {
    alpha = inv * *( elem - 1 ) + frac * *( elem - 2 );
    *elem = alpha;
    if ( alpha < 0.0f )   /* 0x00490E15 fcomp / test ah,5 / jp: a NaN alpha is kept */
      *elem = 0.0f;
    /* Parenthesised frac terms: retail evaluates them before the inv terms. */
    *( elem - 5 ) = ( frac * *( elem - 11 ) ) + inv * *( elem - 8 );
    *( elem - 4 ) = ( frac * *( elem - 10 ) ) + inv * *( elem - 7 );
    *( elem - 3 ) = ( frac * *( elem -  9 ) ) + inv * *( elem - 6 );
    scale = ( frac * elem[1] ) + inv * elem[3];
    elem[5] = scale;
    if ( scale > 1.0f )
      elem[5] = 1.0f;
    elem[6] = ( frac * elem[2] ) + inv * elem[4];
    elem += 21;
    --remaining;
  }
  while ( remaining );
  return 1;
}

/* ---- cand_CFxPrimType14__TypeID  0x00490EA0 ----  [HIGH] */
char cand_CFxPrimType14__TypeID()
{
  return 14;
}

/* ---- cand_CFxPrimType14__Archive  0x00490EB0 ----  VERIFIED */
void __fastcall cand_CFxPrimType14__Archive( int thisObj, int edxUnused, int a2 )
{
  FxArchive *ar = (FxArchive *)a2;

  CEffect__Archive( thisObj, edxUnused, a2 );
  FX_AR_FIELD( ar, thisObj, 220, 336 );

  if ( ar->reading )
    *(unsigned int *)( thisObj + 556 ) = CFxArchive__ReadShader_m( (unsigned int *)ar );
  else
    CFxArchive__WriteShader_m( *(unsigned int *)( thisObj + 556 ), (int *)ar );
}

/* ---- CFlash__ctor  0x00490F10 ----  [CONFIRMED] */
__declspec(noinline) unsigned int *__cdecl CFlash__ctor(unsigned int *self)
{
  self[54] = 0;
  self[15] = 4;
  *self = (unsigned int)&vtbl_CDecal;
  return self;
}

/* ---- CFlash__scalar_dtor  0x00490F30 ----  [CONFIRMED] */
char *__fastcall CFlash__scalar_dtor(char *thisObj, int edxUnused, char deleteFlags)
{
  CFlash__dtor(thisObj);
  if ( (deleteFlags & 1) != 0 )
    CPoly__operator_delete(thisObj);
  return thisObj;
}

/* ---- CFlash__dtor  0x00490F60 ----  VERIFIED */
__declspec(noinline) void __fastcall CFlash__dtor( void *self )
{
  unsigned int *thisObj = (unsigned int *)self;
  char   *bolt;

  FX_STANDARD_CALL(CFlash__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  bolt  = (char *)thisObj[54];
  if ( bolt )
    CFxBoltFrame__Release( bolt );
}

/* ---- CFlash__Cull  0x00490F80 ----  [CONFIRMED] */
char __fastcall CFlash__Cull(float *thisObj)
{
  return SFxHelper__CullSphere((int)&theFxHelper, thisObj + 1, thisObj[46]);
}

/* ---- CFlash__Draw  0x00490FA0 ----  [CONFIRMED] */
/* CoD1 polyVert_t (32 bytes): xyz, st, st2, modulate.  A struct array keeps
 * VC7 from treating the vertex buffer as a /GS-protected byte array. */
typedef struct { float xyz[3]; float st[2]; float st2[2]; unsigned char modulate[4]; } fxPolyVert_t;

int __fastcall CFlash__Draw( int thisObj )
{
  fxPolyVert_t verts[5];
  int i;

  for ( i = 0; i < FX_DECAL(thisObj)->mCount; i++ )
  {
    /* st copied through destination/source pointers (destination declared
     * first): retail schedules the st stores after the xyz[2] store and
     * strength-reduces the mST pointer on &mST[i][0] */
    VectorAdd( FX_DECAL(thisObj)->mOrg[i], FX_DECAL(thisObj)->mOrigin1, verts[i].xyz );
    verts[i].modulate[0] = FX_DECAL(thisObj)->mRefEnt.shaderRGBA[0];
    verts[i].modulate[1] = FX_DECAL(thisObj)->mRefEnt.shaderRGBA[1];
    verts[i].modulate[2] = FX_DECAL(thisObj)->mRefEnt.shaderRGBA[2];
    verts[i].modulate[3] = FX_DECAL(thisObj)->mRefEnt.shaderRGBA[3];
    {
      float *st = verts[i].st;
      float *src = FX_DECAL(thisObj)->mST[i];
      st[0] = src[0];
      st[1] = src[1];
    }
  }
  return re_AddPolyToScene( *(unsigned int *)&FX_DECAL(thisObj)->mRefEnt.customShader, *(unsigned int *)&FX_DECAL(thisObj)->mCount, verts );
}

/* ---- CFlash__Init_m  0x00491050 ----  VERIFIED */
/* Per-frame rotation of the point cloud (vec3 array @ +336, count @ +316)
 * by angle1 (from +324) and angle2 (from +320).  Retail rounds each angle to
 * float and runs the inline fsincos block (the same block as SinCos
 * 0x0042D620), then stores -sin1, -sin2 and the four sin/cos products as
 * floats (0x00491104-0x00491165).  Each rotated point goes to a temporary
 * first (retail esp+4Ch), so all three rows read the unrotated point. */
void VectorRotate( vec3_t in, vec3_t matrix[3], vec3_t out );   /* com_math.c */
/* `self` stays in its argument slot and is reloaded after every store in
 * retail (FX_ADDRESS_ESCAPES); each frame-time conversion has its own slot. */
int __stdcall CFlash__Init_m(int self)
{
  vec3_t temp[5];   /* MAX_CPOLY_VERTS */
  vec3_t rot[3];
  float  ft, ft2, rad;
  float  cosX, cosZ, sinX, sinZ;
  int    i;

  FX_STANDARD_CALL(CFlash__Init_m);
  FX_ADDRESS_ESCAPES(self);
  /* CalcRotateMatrix(): rotate around Z (yaw) ... */
  ft  = (float)fxHelperFrameTime;
  rad = ( ( ft * FX_DECAL(self)->mRotDelta[1] * 0.0099999998f ) * M_PI ) / 180.0f;   /* DEG2RAD() */
  SinCos( rad, &sinZ, &cosZ );
  /* ... then around X (pitch) */
  ft2  = (float)fxHelperFrameTime;
  rad = ( ( ft2 * FX_DECAL(self)->mRotDelta[0] * 0.0099999998f ) * M_PI ) / 180.0f;   /* DEG2RAD() */
  SinCos( rad, &sinX, &cosX );

  /* rot[0][0] / rot[2][2] copied as dwords: retail stores the cos values into
   * the matrix with integer moves and reads them back in the loop instead of
   * forwarding cosZ / cosX into the inlined VectorRotate. */
  *(int *)&rot[0][0] = *(int *)&cosZ;
  rot[1][0] = -sinZ;
  rot[2][0] = 0;
  rot[0][1] = cosX * sinZ;
  rot[1][1] = cosX * cosZ;
  rot[2][1] = -sinX;
  rot[0][2] = sinX * sinZ;
  rot[1][2] = sinX * cosZ;
  *(int *)&rot[2][2] = *(int *)&cosX;

  /* multiply the rotation matrix by each of the offset verts to get their new position */
  for ( i = 0; i < FX_DECAL(self)->mCount; i++ )
  {
    VectorRotate( FX_DECAL(self)->mOrg[i], rot, temp[i] );
    VectorCopy( temp[i], FX_DECAL(self)->mOrg[i] );
  }
  return self;
}

/* ---- CFlash__Update  0x00491230 ----  [CONFIRMED] */
char __fastcall CFlash__Update(int thisObj)
{
  float oldX;
  float oldY;
  float oldZ;

  if ( FX_DECAL(thisObj)->mTimeStart > fxMTime )   /* 0x0049123F jg: signed */
    return 0;
  CParticle__UpdateRGB(thisObj);
  CParticle__UpdateAlpha(thisObj);
  if ( fxMTime > FX_DECAL(thisObj)->mTimeStamp )   /* 0x00491257 jle: signed */
  {
    oldX = FX_DECAL(thisObj)->mOrigin1[0];
    oldY = FX_DECAL(thisObj)->mOrigin1[1];
    oldZ = FX_DECAL(thisObj)->mOrigin1[2];
    if ( !CParticle__UpdateOrigin(thisObj) )
      return 0;
    CFlash__Init_m(thisObj);
    /* If the origin did not move, decay the flash's spread angles.  The
     * Plain ==, so a NaN coordinate counts as moved. */
    if ( oldX == FX_DECAL(thisObj)->mOrigin1[0] )
    {
      if ( oldY == FX_DECAL(thisObj)->mOrigin1[1] )
      {
        if ( oldZ == FX_DECAL(thisObj)->mOrigin1[2] )
        {
          /* fmul dword [0x0056919C] = 0x3BD4FDF3 */
          FX_DECAL(thisObj)->mRotDelta[0] = (1.0f - fxHelperFrameTime * 0.0064999997f) * FX_DECAL(thisObj)->mRotDelta[0];
          FX_DECAL(thisObj)->mRotDelta[1] = (1.0f - fxHelperFrameTime * 0.0064999997f) * FX_DECAL(thisObj)->mRotDelta[1];
          FX_DECAL(thisObj)->mRotDelta[2] = (1.0f - fxHelperFrameTime * 0.0064999997f) * FX_DECAL(thisObj)->mRotDelta[2];
        }
      }
    }
  }
  return 1;
}

/* ---- CFlash__DrawHelper_m  0x00491320 ----  VERIFIED */
/* CPoly::PolyInit: recentre the points on their midpoint (kept as the
 * origin for physics) and record the bounding radius. */
void __cdecl CFlash__DrawHelper_m( int self )
{
  int   i;
  float dist;
  float maxDist;

  if ( FX_DECAL(self)->mCount < 3 )
    return;

  float org[3] = { 0, 0, 0 };
  for ( i = 0; i < FX_DECAL(self)->mCount; i++ )
    VectorAdd( org, FX_DECAL(self)->mOrg[i], org );

  VectorScale( org, 1.0f / FX_DECAL(self)->mCount, org );
  VectorCopy( org, FX_DECAL(self)->mOrigin1 );

  maxDist = 0.0f;
  for ( i = 0; i < FX_DECAL(self)->mCount; i++ )
  {
    VectorSubtract( FX_DECAL(self)->mOrg[i], FX_DECAL(self)->mOrigin1, FX_DECAL(self)->mOrg[i] );
    dist = DotProduct( FX_DECAL(self)->mOrg[i], FX_DECAL(self)->mOrg[i] );
    if ( maxDist < dist )
      maxDist = dist;
  }
  FX_DECAL(self)->mRefEnt.radius = sqrt( maxDist );
}

/* ---- CFlash__TypeID  0x00491430 ----  [CONFIRMED] */
char CFlash__TypeID()
{
  return 15;
}

/* ---- CFlash__Archive  0x00491440 ----  [CONFIRMED] */
void __fastcall CFlash__Archive(byte *thisObj, int edxUnused, int archive)
{
  CParticle__Archive( thisObj, edxUnused, archive );
  FX_AR_FIELD( archive, thisObj, 316,  4 );
  FX_AR_FIELD( archive, thisObj, 320, 12 );
  FX_AR_FIELD( archive, thisObj, 332,  4 );
  FX_AR_FIELD( archive, thisObj, 336, 60 );
  FX_AR_FIELD( archive, thisObj, 396, 40 );
}

/* ---- cand_CFxPrimType13__Update  0x00491500 ----  VERIFIED */
char __fastcall cand_CFxPrimType13__Update(void *thisObj)
{
  CLight__UpdateRGB_m((int)thisObj);
  return 1;
}

/* ---- cand_CFxPrimType13__helper  0x00491510 ----  VERIFIED */
void __cdecl cand_CFxPrimType13__helper(float *self)
{
  float dist;
  float fade;
  float scale;
  float dir[3]; /* [esp+4h] [ebp-Ch] BYREF -- retail vec3_t */

  /* Fade this light by distance from and angle to the view point.  Use float operands and constants; VC7 keeps the intermediate values
   * on the x87 stack as in retail. */
  dir[0] = self[1] - fxHelperViewOriginX;
  dir[1] = self[2] - fxHelperViewOriginY;
  dir[2] = self[3] - fxHelperViewOriginZ;
  dist = VectorNormalize(dir);
  fade = fxHelperCullPlane0NormalZ * dir[2] + fxHelperCullPlane0NormalY * dir[1] + fxHelperCullPlane0NormalX * dir[0];
  /* 0x491567..0x4915B4: the fade tests are fcom/test ah,5/jp, so they branch on !(fade < 0.5f) and a NaN fade skips both the zeroing and the +1.1f */
  if ( dist > 600.0f || ( fade < 0.5f && dist > 100.0f ) )
    fade = 0.0f;
  else if ( fade < 0.5f && dist <= 100.0f )
    fade = fade + 1.1f;                                    /* flt_569054 = 0x3F8CCCCD */
  scale = fade * (1.0f - dist * dist * 0.0000027777778f);  /* flt_569050 = 0x363A69DC; 1.0f exact */
  self[58] = scale * self[58];
  self[59] = scale * self[59];
  self[60] = scale * self[60];
  self[61] = scale * self[61];
  self[62] = scale * self[62];
  self[63] = scale * self[63];
}

/* ---- cand_CFxPrimType13__Draw  0x00491630 ----  VERIFIED */
int __fastcall cand_CFxPrimType13__Draw(int thisObj)
{
  int    drawCmd;
  float *color;
  float *c;
  int    i;
  double g255;
  __int64 gByte; // rax
  double b255;
  float fwdZ;

  drawCmd = thisObj + 60;
  color = (float *)FX_LIGHT(thisObj)->mRefEnt.lightingOrigin;
  *(unsigned int *)&FX_LIGHT(thisObj)->mRefEnt.reType = 4;

  /* clamp the RGB color to [0,1].  0x491650: only an ordered c > 1 stores
   * 1.0f (test ah,41h; jne), and 0x491667 stores 0 only on c < 0 (test ah,5;
   * jp), so a NaN channel is left unchanged */
  c = (float *)FX_LIGHT(thisObj)->mRefEnt.lightingOrigin;
  i = 3;
  do
  {
    if ( *c > 1.0f )
      *c = 1.0f;
    else if ( *c < 0.0f )
      *c = 0.0f;
    ++c;
    --i;
  }
  while ( i );

  /* pack the clamped color into the byte RGBA at +168 (0x49168A..0x4916B2:
   * call __ftol, signed 64-bit truncation, low byte stored) */
  g255 = FX_LIGHT(thisObj)->mRefEnt.lightingOrigin[1] * 255.0f;
  FX_LIGHT(thisObj)->mRefEnt.shaderRGBA[0] = (__int64)(*color * 255.0f);
  gByte = (__int64)g255;
  b255 = FX_LIGHT(thisObj)->mRefEnt.lightingOrigin[2] * 255.0f;
  FX_LIGHT(thisObj)->mRefEnt.shaderRGBA[1] = gByte;
  FX_LIGHT(thisObj)->mRefEnt.shaderRGBA[2] = (__int64)b255;
  FX_LIGHT(thisObj)->mRefEnt.shaderRGBA[3] = -1;

  /* place the sprite 8 units in front of the view point */
  FX_LIGHT(thisObj)->mRefEnt.origin[0] = fxHelperViewOriginX;
  FX_LIGHT(thisObj)->mRefEnt.origin[1] = fxHelperViewOriginY;
  FX_LIGHT(thisObj)->mRefEnt.origin[2] = fxHelperViewOriginZ;
  FX_LIGHT(thisObj)->mRefEnt.origin[0] = fxHelperCullPlane0NormalX * 8.0f + FX_LIGHT(thisObj)->mRefEnt.origin[0];
  FX_LIGHT(thisObj)->mRefEnt.origin[1] = fxHelperCullPlane0NormalY * 8.0f + FX_LIGHT(thisObj)->mRefEnt.origin[1];
  fwdZ = fxHelperCullPlane0NormalZ;
  *(unsigned int *)&FX_LIGHT(thisObj)->mRefEnt.radius = 1094713344;   /* 12.0f, stored as its bit pattern */
  *(unsigned int *)&FX_LIGHT(thisObj)->mRefEnt.spriteSize = 1094713344;   /* 12.0f */
  FX_LIGHT(thisObj)->mRefEnt.origin[2] = fwdZ * 8.0f + FX_LIGHT(thisObj)->mRefEnt.origin[2];
  return re_AddRefEntityToScene(drawCmd, 0);
}

/* ---- cand_CFxPrimType13__TypeID  0x00491750 ----  [HIGH] */
char cand_CFxPrimType13__TypeID()
{
  return 13;
}

/* ---- cand_CFxPrimType13__Archive  0x00491760 ----  VERIFIED */
void __fastcall cand_CFxPrimType13__Archive(byte *thisObj, int edxUnused, int a2)
{
  CLight__Archive( thisObj, edxUnused, a2 );
}

/* ---- CEffect__SetTimeStart  0x00491770 ----  [HIGH] */
int __stdcall CEffect__SetTimeStart(int self, int msec)
{
  *(unsigned int *)&FX_EFFECT(self)->mTimeStart = msec;
  FX_EFFECT(self)->mRefEnt.shaderTime = msec * 0.001f;   /* seconds; flt_568E6C = 0x3A83126F; fild keeps msec exact, so keep the (double) cast */
  return self;
}

/* ---- FxPool_CtorBoltFrame_m  0x00491790 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorBoltFrame_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(481.0);
  return pool;
}

/* ---- FxPool_AllocBoltFrame  0x004917B0 ----  VERIFIED */
int *__stdcall FxPool_AllocBoltFrame( int *pool, int elemSize )
{
  int *block;
  int *node;

  /* the pool template's Alloc (memorytree.cpp FxPool_AllocPrimType14): scan the
   * slab list for a free object, moving that slab to the front, else claim a
   * new slab */
  for ( block = (int *)pool[1]; block; block = (int *)block[8190] )   /* +0x7FF8 */
  {
    if ( block[8189] )                                                 /* +0x7FF4 freeList */
    {
      if ( block != (int *)pool[1] )
        FxPool_MakeBlockCurrentBoltFrame( (int)pool, (int)block );
      goto pop;
    }
  }
  block = (int *)FxMem_ClaimBlock_m( pool[0], elemSize, pool[1] );
  if ( !block )
    return NULL;
  pool[1] = (int)block;
pop:
  node        = (int *)block[8189];
  block[8189] = *node;
  block[8188]--;                                                       /* +0x7FF0 freeCount */
  Com_Memset( node, 0, 0x44u );
  return node;
}

/* ---- FxPool_FreeBoltFrame  0x00491840 ----  VERIFIED */
/* Same code as FxPool_FreeModel, but the empty-current-block path tail-jumps to
 * FxPool_MakeBlockCurrentBoltFrame (0x491F90).  Reached by tail-jmp from
 * CFxBoltFrame__operator_delete and CFxBoltFrame__Release. */
struct fxPoolBlock_s;
extern struct fxPoolBlock_s *FxMem_ReleaseBlock(struct fxPoolBlock_s *block);
unsigned int *__fastcall FxPool_FreeBoltFrame( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if ( !cur[8189] )
    return (unsigned int *)FxPool_MakeBlockCurrentBoltFrame( (int)pool, (int)block );

  if ( count >= pool[0] )
  {
    if ( block == cur )
    {
      nxt = (int)block[8190];                       
      if ( !nxt || !*(int *)( nxt + 32752 ) )
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorModel_m  0x004918B0 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorModel_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(209.0);
  return pool;
}

/* ---- FxPool_AllocModel  0x004918D0 ----  VERIFIED */
int *__stdcall FxPool_AllocModel( int *pool, int elemSize )
{
  int *block;
  int *node;

  /* the pool template's Alloc (memorytree.cpp FxPool_AllocPrimType14): scan the
   * slab list for a free object, moving that slab to the front, else claim a
   * new slab */
  for ( block = (int *)pool[1]; block; block = (int *)block[8190] )   /* +0x7FF8 */
  {
    if ( block[8189] )                                                 /* +0x7FF4 freeList */
    {
      if ( block != (int *)pool[1] )
        FxPool_MakeBlockCurrentModel( (int)pool, (int)block );
      goto pop;
    }
  }
  block = (int *)FxMem_ClaimBlock_m( pool[0], elemSize, pool[1] );
  if ( !block )
    return NULL;
  pool[1] = (int)block;
pop:
  node        = (int *)block[8189];
  block[8189] = *node;
  block[8188]--;                                                       /* +0x7FF0 freeCount */
  Com_Memset( node, 0, 0x9Cu );
  return node;
}

/* ---- FxPool_FreeModel  0x00491960 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreeModel( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if ( !cur[8189] )
    return (unsigned int *)FxPool_MakeBlockCurrentModel( (int)pool, (int)block );

  if ( count >= pool[0] )
  {
    if ( block == cur )
    {
      nxt = (int)block[8190];                       
      if ( !nxt || !*(int *)( nxt + 32752 ) )
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorEffect_m  0x004919D0 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorEffect_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(148.0);
  return pool;
}

/* ---- FxPool_FreeEffect  0x004919F0 ----  VERIFIED */
struct fxPoolBlock_s;
extern struct fxPoolBlock_s *FxMem_ReleaseBlock(struct fxPoolBlock_s *block);
int __cdecl FxPool_MakeBlockCurrentEffect(int block, int pool)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + 4);
  *(unsigned int *)(*(unsigned int *)(pool + 4) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + 4) = block;
  return block;
}
unsigned int *__fastcall FxPool_FreeEffect( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if (!cur[8189])
    return (unsigned int *)FxPool_MakeBlockCurrentEffect((int)block, (int)pool);
  if (count >= pool[0])
  {
    if (block == cur)
    {
      nxt = (int)block[8190];
      if (!nxt || !*(int *)(nxt + 32752))
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorPrimType14_m  0x00491A60 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorPrimType14_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(58.0);
  return pool;
}

/* ---- FxPool_CtorLight_m  0x00491A80 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorLight_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(125.0);
  return pool;
}

/* ---- FxPool_FreeLight  0x00491AA0 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreeLight( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if ( !cur[8189] )
    return (unsigned int *)FxPool_MakeBlockCurrentLight( (int)pool, (int)block );

  if ( count >= pool[0] )
  {
    if ( block == cur )
    {
      nxt = (int)block[8190];                       
      if ( !nxt || !*(int *)( nxt + 32752 ) )
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorParticle_m  0x00491B10 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorParticle_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(103.0);
  return pool;
}

/* ---- FxPool_FreeParticle  0x00491B30 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreeParticle( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if ( !cur[8189] )
    return (unsigned int *)FxPool_MakeBlockCurrentParticle( (int)pool, (int)block );

  if ( count >= pool[0] )
  {
    if ( block == cur )
    {
      nxt = (int)block[8190];                       
      if ( !nxt || !*(int *)( nxt + 32752 ) )
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorLine_m  0x00491BA0 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorLine_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(99.0);
  return pool;
}

/* ---- FxPool_FreeLine  0x00491BC0 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreeLine( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if ( !cur[8189] )
    return (unsigned int *)FxPool_MakeBlockCurrentLine( (int)pool, (int)block );

  if ( count >= pool[0] )
  {
    if ( block == cur )
    {
      nxt = (int)block[8190];                       
      if ( !nxt || !*(int *)( nxt + 32752 ) )
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorElectricity_m  0x00491C30 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorElectricity_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(45.0);
  return pool;
}

/* ---- FxPool_FreeElectricity  0x00491C50 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreeElectricity( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if ( !cur[8189] )
    return (unsigned int *)FxPool_MakeBlockCurrentElectricity( (int)pool, (int)block );

  if ( count >= pool[0] )
  {
    if ( block == cur )
    {
      nxt = (int)block[8190];                       
      if ( !nxt || !*(int *)( nxt + 32752 ) )
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorOrientedParticle_m  0x00491CC0 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorOrientedParticle_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(99.0);
  return pool;
}

/* ---- FxPool_FreeOrientedParticle  0x00491CE0 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreeOrientedParticle( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if ( !cur[8189] )
    return (unsigned int *)FxPool_MakeBlockCurrentOrientedParticle( (int)pool, (int)block );

  if ( count >= pool[0] )
  {
    if ( block == cur )
    {
      nxt = (int)block[8190];                       
      if ( !nxt || !*(int *)( nxt + 32752 ) )
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorTail_m  0x00491D50 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorTail_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(95.0);
  return pool;
}

/* ---- FxPool_FreeTail  0x00491D70 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreeTail( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if ( !cur[8189] )
    return (unsigned int *)FxPool_MakeBlockCurrentTail( (int)pool, (int)block );

  if ( count >= pool[0] )
  {
    if ( block == cur )
    {
      nxt = (int)block[8190];                       
      if ( !nxt || !*(int *)( nxt + 32752 ) )
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorCylinder_m  0x00491DE0 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorCylinder_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(95.0);
  return pool;
}

/* ---- FxPool_FreeCylinder  0x00491E00 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreeCylinder( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if ( !cur[8189] )
    return (unsigned int *)FxPool_MakeBlockCurrentCylinder( (int)pool, (int)block );

  if ( count >= pool[0] )
  {
    if ( block == cur )
    {
      nxt = (int)block[8190];                       
      if ( !nxt || !*(int *)( nxt + 32752 ) )
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorEmitter_m  0x00491E70 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorEmitter_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(82.0);
  return pool;
}

/* ---- FxPool_FreeEmitter  0x00491E90 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreeEmitter( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if ( !cur[8189] )
    return (unsigned int *)FxPool_MakeBlockCurrentEmitter( (int)pool, (int)block );

  if ( count >= pool[0] )
  {
    if ( block == cur )
    {
      nxt = (int)block[8190];                       
      if ( !nxt || !*(int *)( nxt + 32752 ) )
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorDecal_m  0x00491F00 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorDecal_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(75.0);
  return pool;
}

/* ---- FxPool_FreeDecal  0x00491F20 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreeDecal( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;
  int     prv;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);


  cur = (unsigned int *)pool[1];
  if ( !cur[8189] )
    return (unsigned int *)FxPool_MakeBlockCurrentDecal( (int)pool, (int)block );

  if ( count >= pool[0] )
  {
    if ( block == cur )
    {
      nxt = (int)block[8190];                       
      if ( !nxt || !*(int *)( nxt + 32752 ) )
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_MakeBlockCurrentBoltFrame  0x00491F90 ----  VERIFIED */
int __cdecl FxPool_MakeBlockCurrentBoltFrame(int pool, int block)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- FxPool_MakeBlockCurrentModel  0x00491FF0 ----  VERIFIED */
int __cdecl FxPool_MakeBlockCurrentModel(int pool, int block)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- FxPool_MakeBlockCurrentLight  0x004920B0 ----  VERIFIED */
int __cdecl FxPool_MakeBlockCurrentLight(int pool, int block)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- FxPool_MakeBlockCurrentParticle  0x00492110 ----  VERIFIED */
int __cdecl FxPool_MakeBlockCurrentParticle(int pool, int block)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- FxPool_MakeBlockCurrentLine  0x00492170 ----  VERIFIED */
int __cdecl FxPool_MakeBlockCurrentLine(int pool, int block)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- FxPool_MakeBlockCurrentElectricity  0x004921D0 ----  VERIFIED */
int __cdecl FxPool_MakeBlockCurrentElectricity(int pool, int block)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- FxPool_MakeBlockCurrentOrientedParticle  0x00492230 ----  VERIFIED */
int __cdecl FxPool_MakeBlockCurrentOrientedParticle(int pool, int block)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- FxPool_MakeBlockCurrentTail  0x00492290 ----  VERIFIED */
int __cdecl FxPool_MakeBlockCurrentTail(int pool, int block)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- FxPool_MakeBlockCurrentCylinder  0x004922F0 ----  VERIFIED */
int __cdecl FxPool_MakeBlockCurrentCylinder(int pool, int block)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- FxPool_MakeBlockCurrentEmitter  0x00492350 ----  VERIFIED */
int __cdecl FxPool_MakeBlockCurrentEmitter(int pool, int block)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- FxPool_MakeBlockCurrentDecal  0x004923B0 ----  VERIFIED */
int __cdecl FxPool_MakeBlockCurrentDecal(int pool, int block)
{
  int next;
  int prev;

  /* unlink block from its current position in the doubly linked block list */
  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);

  /* splice it in ahead of the pool's head block (pool[1]) */
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- CGPObject__GetName  0x00492410 ----  VERIFIED */
int __cdecl CGPObject__GetName(int object)
{
  return *(unsigned int *)object;
}

/* ---- CGPGroup__GetNext  0x00492420 ----  [HIGH] */
int __cdecl CGPGroup__GetNext(int group)
{
  return *(unsigned int *)(group + FX_GPGROUP_OFS( mNext ));
}

/* ---- CGPGroup__GetSubGroups  0x00492430 ----  [HIGH] */
int __cdecl CGPGroup__GetSubGroups(int group)
{
  return *(unsigned int *)(group + FX_GPGROUP_OFS( mSubGroups ));
}

/* ---- CGenericParser2__GetBaseParseGroup  0x00492440 ----  [HIGH] */
void CGenericParser2__GetBaseParseGroup()
{
  ;
}

/* ---- stl_fxCharTraits_assignChar_m  0x00492450 ----  [HIGH] */
/* char_traits<char>::assign(dest, src); its one retail call (the map node's
 * key _Tidy in stl_fxEffectIdMap_eraseNode_m) was not inlined. */
__declspec(noinline) void __cdecl stl_fxCharTraits_assignChar_m( char *dest, const char *src )
{
  FX_STANDARD_CALL(stl_fxCharTraits_assignChar_m);
  *dest = *src;
}

/* ---- stl_fxCharTraits_compare_m  0x00492460 ----  VERIFIED */
int __cdecl stl_fxCharTraits_compare_m(const char *right, const char *left, int count)
{
  return memcmp(left, right, count);
}

/* ---- stl_fxCharTraits_length_m  0x00492480 ----  VERIFIED */
/* Retail keeps the plain stack convention; the address-taken parameter reproduces it. */
unsigned int __cdecl stl_fxCharTraits_length_m(const char *str)
{
  const char **s = &str;

  return strlen(*s);
}

/* ---- stl_fxCharTraits_copy_m  0x004924A0 ----  VERIFIED */
char *__cdecl stl_fxCharTraits_copy_m(FxCharPointerArgument dest, FxConstCharPointerArgument src, FxSizeArgument size)
{
  return (char *)memcpy(dest.pointer, src.pointer, size.count);
}

/* ---- stl_fxCharTraits_move_m  0x004924D0 ----  VERIFIED */
/* retail 0x004924D0, IDA j__memcpy: jmp _memcpy (LIBCMT memmove == memcpy body), no xrefs; next to char_traits length/copy (copy = inline rep movs): char_traits<char>::move. */
/* std::char_traits<char>::move: a tail jump to memmove. */
void *__cdecl stl_fxCharTraits_move_m(FxPointerArgument dest, FxConstPointerArgument src, FxSizeArgument size)
{
  return memmove(dest.pointer, src.pointer, size.count);
}

/* ---- FX_UnusedStub1  0x004924E0 ----  [HIGH] */
/* retail 0x004924E0, IDA nullsub_37: bare retn, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void FX_UnusedStub1()
{
  ;
}

/*
 * ---------------------------------------------------------------------------
 * <stdexcept>: std::logic_error, std::length_error and std::out_of_range as
 * VC7's header defines them (Dinkumware, 0x28 bytes: vfptr,
 * exception::_m_what / _m_doFree, logic_error::_Str).  The std::exception
 * base is LIBCMT's own class (stdexcpt.obj).  Their inline members are the
 * COMDATs at retail 0x00492500..0x00492760, which LIBCPMT's
 * _String_base::_Xran/_Xlen bind to as well: logic_error(const string &)
 * and the implicit copy constructors run under an EH frame that destroys the
 * exception base if the string copy throws.
 * ---------------------------------------------------------------------------
 */
/* Deleting-destructor flags of the CFxPrimType13/14 vftables (below). */
typedef struct {unsigned int flags;} FxCrtDeletingFlags;

}   /* extern "C" */

/* ---- operator_delete_placement_m  0x004924F0 ----  [HIGH] */
/* The global placement operator delete(void *, void *): it does nothing, and is
 * reached only from the unwind action of a placement new-expression whose
 * constructor throws (_Buynode's node construction).  <new> declares it
 * throw(); the definition leaves that out so exe_layout sees it as "delete".
 * Modern MSVC already defines this inline in <new>; VC7 did not. */
#if !defined(_MSC_VER) || _MSC_VER < 1900
void __cdecl operator delete( void *, void * )
{
}
#endif

/* VC7's libcpmt supplied std::_String_base::_Xlen/_Xran.  Modern MSVC no
 * longer has that class, so define the two out-of-line members here with
 * retail's messages; the reconstructed string code calls them directly. */
void std::_String_base::_Xlen() const
{
  throw std::length_error( "string too long" );
}

void std::_String_base::_Xran() const
{
  throw std::out_of_range( "invalid string position" );
}

/* The members of std::logic_error / length_error / out_of_range (classes in
 * fx_types.h; this is their one definition, StringEd's throws use it too), in
 * retail order.  The header defines them in the classes; out
 * here exe_layout places them (the scalar deleting destructors are the
 * compiler's).  The copy constructors are the implicit ones, spelled out. */

/* ---- std_logicError__ctor_m  0x00492500 ---- */
inline std::logic_error::logic_error( const FxStdString &message )
  : _Str( message )
{
}

/* ---- std_logicError__dtor_m  0x00492560 ---- */
inline std::logic_error::~logic_error()
{
}

/* ---- std_logicError__what_m  0x004925A0 ---- */
inline const char *std::logic_error::what() const throw()
{
  return 16 <= _Str.capacity ? _Str.bx.ptr : (const char *)_Str.bx.buf;   /* _Str.c_str() */
}

/* ---- std_lengthError__ctor_m  0x004925D0 ---- */
inline std::length_error::length_error( const FxStdString &message )
  : logic_error( message )
{
}

/* ---- std_lengthError__dtor_m  0x004925F0 ---- */
inline std::length_error::~length_error()
{
}

/* ---- std_outOfRange__ctor_m  0x00492650 ---- */
inline std::out_of_range::out_of_range( const FxStdString &message )
  : logic_error( message )
{
}

/* ---- std_outOfRange__dtor_m  0x00492670 ---- */
inline std::out_of_range::~out_of_range()
{
}

/* ---- std_lengthError__copyCtor_m  0x004926D0 ---- */
inline std::length_error::length_error( const length_error &right )
  : logic_error( right )
{
}

/* ---- std_logicError__copyCtor_m  0x004926F0 ---- */
inline std::logic_error::logic_error( const logic_error &right )
  : exception( right ), _Str( right._Str )
{
}

/* ---- std_outOfRange__copyCtor_m  0x00492760 ---- */
inline std::out_of_range::out_of_range( const out_of_range &right )
  : logic_error( right )
{
}

extern "C" {

/* ---- CMediaHandles__GetHandle  0x00492780 ----  VERIFIED */
int __cdecl CMediaHandles__GetHandle( int vec )
{
  int first;
  int count;

  first = *(unsigned int *)( vec + 4 );                     /* vector._Myfirst */
  if ( !first )
    return 0;
  count = ( *(int *)( vec + 8 ) - first ) >> 2;       /* (._Mylast - ._Myfirst) / 4 */
  if ( !count )
    return 0;
  com_randSeed_m = 214013 * com_randSeed_m + 2531011;
  return *(unsigned int *)( first + 4 * ( (int)( count * ( (unsigned int)com_randSeed_m >> 17 ) ) >> 15 ) );
}

/* ---- CFxRange__GetMax  0x004927C0 ----  [HIGH] */
double __cdecl CFxRange__GetMax( int range )
{
  return *(float *)( range + 4 );          /* range max */
}

/* ---- CFxRange__GetMin  0x004927D0 ----  [HIGH] */
double __cdecl CFxRange__GetMin( int range )
{
  return *(float *)range;                  /* range min */
}

/* ---- CFxRange__GetVal_percent  0x004927E0 ----  [HIGH] */
double __fastcall CFxRange__GetVal_percent( float *range, float frac )
{
  return ( range[1] - range[0] ) * frac + range[0];
}

/* ---- CFxRange__GetVal  0x004927F0 ----  VERIFIED */
double __cdecl CFxRange__GetVal( float *range )
{
  /* Random value in [range[0], range[1]].  Returns range[0]
   * when the bounds are equal (a NaN bound takes the random path). */
  if ( range[0] == range[1] )
    return range[0];
  else
    return Com_RandFloatRange_m( range[0], range[1] );
}

/* ---- CFxRange__GetRoundedVal  0x00492810 ----  VERIFIED */
unsigned __int64 __cdecl CFxRange__GetRoundedVal( float *range )
{
  /* Rounded random int in [range[0], range[1]]; range[0] when the bounds are equal. */
  if ( range[0] == range[1] )
    return (unsigned __int64)range[0];
  else
    return (unsigned __int64)( FCAST( Com_RandFloatRange_m( range[0], range[1] ) ) + 0.5f );   /* dword 0.5f */
}

}   /* extern "C" */

/* ---- CPrimitiveTemplate__dtor  0x00492840 ----  VERIFIED */
/* ~CPrimitiveTemplate(): the five handle vectors' destructors, last first. */
CPrimitiveTemplate::~CPrimitiveTemplate()
{
}

/* ---- CPrimitiveTemplate__operator_new  0x004928F0 ----  VERIFIED */
void *CPrimitiveTemplate::operator new( unsigned int size )
{
  return FxPool_AllocPrimitiveTemplate( &fxPool_PrimitiveTemplate, size );
}

/* ---- CPrimitiveTemplate__operator_delete  0x00492900 ----  VERIFIED */
void CPrimitiveTemplate::operator delete( void *element )
{
  FxPool_FreePrimitiveTemplate( &fxPool_PrimitiveTemplate, (char *)element );
}

/* (retail 0x00492910, inside no IDA function) */
/* vector<int>::~vector(): _Tidy(): free the array, then empty the vector. */
inline CMediaHandles::~CMediaHandles()
{
  if ( first != 0 )
    operator delete( first );   /* _Destroy is nothing for int; deallocate */
  first = 0, last = 0, end = 0;
}

extern "C" {

/* ---- SScheduledEffect__operator_le  0x00492940 ----  [HIGH] */
int __fastcall SScheduledEffect__operator_le( unsigned int *scheduledEffect, int now )
{
  return (int)*(unsigned int *)&FX_SCHED(scheduledEffect)->mStartTime <= now;   /* +0x08 scheduledTime <= now; 0x49294B setle: signed compare */
}

/* ---- SScheduledEffect__operator_new  0x00492960 ----  VERIFIED */
int *__cdecl SScheduledEffect__operator_new( int elemSize )
{
  return FxMem_AllocScheduledEffect( &fxPool_ScheduledEffect, elemSize );
}

/* ---- SScheduledEffect__operator_delete  0x00492970 ----  VERIFIED */
unsigned int *__cdecl SScheduledEffect__operator_delete( char *element )
{
  return FxPool_FreeScheduledEffect( &fxPool_ScheduledEffect, element );
}

/* ---- CFxScheduler__dtor  0x00492980 ----  VERIFIED */
void __cdecl CFxScheduler__dtor( int self )
{
  /* ~list<SScheduledEffect *>, then ~map<string, int> */
  stl_fxScheduledList_dtor_m( self + FX_SCHEDULER_SCHEDULED_LIST_OFFSET );
  stl_fxEffectIdMap_tidy_m( self + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET );
}

/* ---- FX_AxisLocalToWorld_m  0x00492A20 ----  [HIGH] */
float *__cdecl FX_AxisLocalToWorld_m( float *axis, float *out, float x, float y, float z )
{
  /* transform local (x, y, z) by the 3x3 axis (row-major) into out */
  out[0] = y * axis[3] + z * axis[6] + x * axis[0];
  out[1] = x * axis[1] + y * axis[4] + z * axis[7];
  out[2] = x * axis[2] + y * axis[5] + z * axis[8];
  return axis;
}

/* ---- CMediaHandles__operator_assign  0x00492A80 ----  VERIFIED */
/* CMediaHandles::operator=( that ): clear, then push_back every handle. */
void __stdcall CMediaHandles__operator_assign( int dst, int src )
{
  const CMediaHandles *that = (const CMediaHandles *)src;
  unsigned int         i;

  /* mMediaList.clear() */
  if ( *(unsigned int *)( dst + 4 ) )
    j__free( *(void **)( dst + 4 ) );
  *(unsigned int *)( dst + 4 ) = 0;
  *(unsigned int *)( dst + 8 ) = 0;
  *(unsigned int *)( dst + 12 ) = 0;

  for ( i = 0; i < ( that->first == 0 ? 0 : (unsigned int)( that->last - that->first ) ); i++ )
  {
    const int *item = &that->first[i];
    FX_INT_PUSH_BACK( dst, item )   /* push_back( that.mMediaList[i] ) */
  }
}

/* ---- CFxScheduler__ctor_real  0x00492B20 ----  VERIFIED */
/* CFxScheduler::CFxScheduler: construct mEffectIDs (an empty map) and
 * mFxSchedule (an empty list), then clear every effect template.  The list's
 * _Buynode can throw, so the map is destroyed by the unwind funclet; as an
 * EH-framed member LTCG keeps `this` on the stack (retn 4). */
CFxScheduler::CFxScheduler()
{
  memset( mEffectTemplates, 0, sizeof( mEffectTemplates ) );
}

/* ---- SEffectTemplate__operator_assign  0x00492BB0 ----  VERIFIED */
/* Retail is a plain __thiscall member: ECX is the SOURCE template (moved to
 * EDI), the stack argument the copy (retn 4).  GetEffectCopy's
 * `*copy = mEffectTemplates[id]` therefore reaches a member of the source;
 * as a real member VC7 allocates `this` like retail. */
struct SEffectTemplateCopier : SEffectTemplate
{
  void CopyTo( SEffectTemplate *copy ) const;
};

void SEffectTemplateCopier::CopyTo( SEffectTemplate *copy ) const
{
  int i;

  copy->mCopy = 1;
  strcpy( copy->mEffectName, this->mEffectName );
  copy->mPrimitiveCount = mPrimitiveCount;
  for ( i = 0; i < copy->mPrimitiveCount; i++ )
  {
    copy->mPrimitives[i] = new CPrimitiveTemplate;
    CPrimitiveTemplate__copy_m( (char *)copy->mPrimitives[i], (char *)mPrimitives[i] );   /* *mPrimitives[i] = *that.mPrimitives[i] */
    copy->mPrimitives[i]->mCopy = 1;   /* a copy: chucked once used up */
  }
}

/* ---- CFxScheduler__Clean  0x00492C80 ----  [CONFIRMED] */
void __stdcall CFxScheduler__Clean( int self, int clearTemplates, int keepEffectId )
{
  unsigned int       *listHead;
  unsigned int       *node;
  unsigned int       *next;
  int           tmplIndex;
  int           i;

  FX_STANDARD_CALL(CFxScheduler__Clean);
  /* --- free every scheduled effect and empty the list --- */
  listHead = *(unsigned int **)( self + FX_SCHEDULER_SCHEDULED_HEAD_OFFSET );
  node     = !listHead ? 0 : (unsigned int *)*listHead;   /* itr = mFxSchedule.begin() */
  /* the end() test re-reads _Myhead rather than reusing begin()'s load, as in retail */
  while ( node != *(unsigned int * volatile *)( self + FX_SCHEDULER_SCHEDULED_HEAD_OFFSET ) )
  {
    next = (unsigned int *)*node;
    FxPool_FreeScheduledEffect( &fxPool_ScheduledEffect, (char *)node[2] );      /* free the scheduled-effect payload */
    if ( node != *(unsigned int **)( self + FX_SCHEDULER_SCHEDULED_HEAD_OFFSET ) )   /* mFxSchedule.erase( itr ) */
    {
      *(unsigned int *)node[1]       = (int)*node;            /* prev->next = next */
      *( (unsigned int *)*node + 1 ) = node[1];               /* next->prev = prev */
      j__free( node );
      --*(unsigned int *)( self + FX_SCHEDULER_SCHEDULED_SIZE_OFFSET );
    }
    node = next;
  }

  if ( !(unsigned char)clearTemplates )
    return;

  /* --- destroy each effect template's primitives (except keepEffectId) --- */
  for ( tmplIndex = 1; tmplIndex < FX_EFFECT_TEMPLATE_COUNT; tmplIndex++ )
  {
    SEffectTemplate *effect = (SEffectTemplate *)( self + FX_EFFECT_TEMPLATE_SIZE * tmplIndex );

    if ( tmplIndex == keepEffectId )
      continue;
    if ( effect->mInUse )
    {
      /* ditch the primitives */
      for ( i = 0; i < effect->mPrimitiveCount; i++ )
        delete effect->mPrimitives[i];
    }
    effect->mInUse = 0;
  }

  /* --- rebuild the effect-id map: clear it, or keep only keepEffectId --- */
  if ( keepEffectId == 0 )
  {
    stl_fxEffectIdMap_clear_m( self + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET );   /* mEffectIDs.clear() */
  }
  else
  {
    /* clear the effect names, but first get the name of the effect to
     * preserve, and restore it after clearing.  The iterator lives in the
     * (dead) clearTemplates argument's slot, as in retail. */
    FxStdString str;
    int        *mapHeadPtr = *(int **)( self + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET + 4 );   /* map._Myhead */

    for ( clearTemplates = *mapHeadPtr; clearTemplates != (int)mapHeadPtr; stl_fxEffectIdMap_iterInc_m( (int **)&clearTemplates ) )
    {
      if ( FXN_MAPPED( clearTemplates ) == keepEffectId )
      {
        stl_fxString_assignSubstr_m( (int)&str, (int)FXN_KEY( clearTemplates ), 0, 0xFFFFFFFF );   /* str = (*iter).first */
        break;
      }
    }

    stl_fxEffectIdMap_clear_m( self + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET );   /* mEffectIDs.clear() */

    *(int *)stl_fxEffectIdMap_index_m( self + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET, str ) = keepEffectId;   /* mEffectIDs[str] = idToPreserve */
  }
}

/* ---- CFxScheduler__RegisterEffect  0x00492EB0 ----  VERIFIED */
#ifdef __cplusplus

int CFxScheduler::RegisterEffect( const char *file, bool isPath )
{
  char         sfile[64];
  char         temp[64];
  char        *bufParse;
  unsigned char *it;
  int          len;
  fileHandle_t fh;
  const char  *name;
  char         data[65536];

  /* get an extension-stripped version of the file */
  if ( isPath )
  {
    const char *last = file, *p = file;
    char       *out;

    while ( *p )
    {
      if ( *p == '/' || *p == '\\' )
        last = p + 1;
      p++;
    }
    p   = last;   /* COM_StripExtension( last, sfile ) */
    out = sfile;
    while ( *p && *p != '.' )
      *out++ = *p++;
    *out = 0;
  }
  else
  {
    const char *in  = file;
    char       *out = sfile;   /* COM_StripExtension( file, sfile ) */

    while ( *in && *in != '.' )
      *out++ = *in++;
    *out = 0;
    strlwr( sfile );
  }

  /* see if the specified file is already registered: if so, return its id */
  {
    FxStdString key( sfile );
    it = stl_fxEffectIdMap_find_m( (int)this + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET, (int)&key ).node;
  }
  if ( it != *(unsigned char **)( (char *)this + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET + 4 ) )
    return *(int *)( it + 40 );   /* (*itr).second */

  CGenericParser2 parser;
  bufParse = 0;

  if ( isPath )
  {
    name = file;
  }
  else
  {
    sprintf( temp, "%s.efx", sfile );
    name = temp;
  }

  len = FS_FOpenFileByMode( name, &fh, FS_READ );
  if ( len <= 0 )
  {
    SFxHelper__Print( (int)&theFxHelper, "Effect file load failed: %s: file not found\n", name );
    return 0;
  }
  if ( (unsigned int)len >= 0xFFFF )
  {
    SFxHelper__Print( (int)&theFxHelper, "Effect file load failed: %s: file too large\n", name );
    FS_FCloseFile( fh );
    return 0;
  }

  FS_Read( data, len, fh );
  data[len] = 0;
  bufParse = data;
  CGenericParser2__Parse( (int)parser.gp, &bufParse, 1, 0 );
  FS_FCloseFile( fh );

  return CFxScheduler__ParseEffect( sfile, (int)this, parser.gp );
}
#else
int __cdecl CFxScheduler__RegisterEffect( unsigned int *thisObj, char *Source, char isPath )
{
#ifdef __cplusplus
  unsigned int        *thisObj = (unsigned int *)this;
#endif
  const char    *src;
  char          *dst;
  const char    *file;
  int            len;
  int            id;
  fileHandle_t   f;
  unsigned char *node;
  unsigned char  key[28];
  int            it;
  char           Destination[64];
  char           Buffer[64];
  char          *dataPtr;
  int            gp2[14];
  byte          buffer[65536];

#ifdef __cplusplus
  (void)&CFxScheduler::RegisterEffect;   /* keeps the declared __thiscall under LTCG */
#endif
  if ( isPath )
  {
    const char *scan;
    src = Source;
    for ( scan = Source; *scan; ++scan )
    {
      if ( *scan == '/' || *scan == '\\' )
        src = scan + 1;
    }
  }
  else
  {
    src = Source;
  }

  dst = Destination;
  while ( *src && *src != '.' )
    *dst++ = *src++;
  *dst = 0;

  if ( !isPath )
    strlwr( Destination );

  FXS_RES ( key ) = 15;
  FXS_SIZE( key ) = 0;
  key[4]          = 0;
  stl_fxString_assignPtrCount_m((int)key, FxConstCharArgument((const char *)(Destination)), FxCountArgument((unsigned int)(strlen( Destination ))));

  node = stl_fxEffectIdMap_find_m( (int)( (char *)thisObj + 0x5400 ), (int)key ).node;

  if ( FXS_RES( key ) >= 0x10 )
    free( *(void **)FXS_BX( key ) );
  FXS_RES ( key ) = 15;
  FXS_SIZE( key ) = 0;
  key[4]          = 0;

  if ( node != *(unsigned char **)( (char *)thisObj + 0x5404 ) )
    return *(int *)( node + 40 );

  gp2[0] = (int)"Top Level";
  memset( &gp2[1], 0, 40 );
  *( (char *)&gp2[11] ) = 0;
  gp2[12] = 0;
  *( (char *)&gp2[13] ) = 0;
  dataPtr = 0;

  if ( isPath )
  {
    file = Source;
  }
  else
  {
    sprintf( Buffer, "%s.efx", Destination );
    file = Buffer;
  }

  len = FS_FOpenFileByMode( file, &f, FS_READ );
  if ( len <= 0 )
  {
    SFxHelper__Print( (int)&theFxHelper,
                      "Effect file load failed: %s: file not found\n", file );
    ( (CGenericParser2 *)gp2 )->~CGenericParser2();
    return 0;
  }
  if ( (unsigned int)len >= 0xFFFF )
  {
    SFxHelper__Print( (int)&theFxHelper,
                      "Effect file load failed: %s: file too large\n", file );
    FS_FCloseFile( f );
    ( (CGenericParser2 *)gp2 )->~CGenericParser2();
    return 0;
  }

  FS_Read( buffer, len, f );
  buffer[len] = 0;
  dataPtr = (char *)buffer;
  CGenericParser2__Parse( (int)gp2, &dataPtr, 1, 0 );
  FS_FCloseFile( f );

  id = CFxScheduler__ParseEffect( Destination, (int)thisObj, gp2 );
  ( (CGenericParser2 *)gp2 )->~CGenericParser2();
  return id;
}
#endif

/* ---- CFxScheduler__ParseEffect  0x004931B0 ----  [CONFIRMED] */
typedef struct {int pointer;} FxAddPrimitive;
void __stdcall CFxScheduler__AddPrimitiveToEffect( int effectTemplate, int unusedReg, FxAddPrimitive primitiveArg );

int __stdcall CFxScheduler__ParseEffect( char *effectName, int scheduler, int *parseTree )
{
  char       *effectTemplate;
  int         group;
  const char *groupName;
  int         primType;
  int         prim;

  /* the new template's id comes back in the scheduler argument's slot (the
   * scheduler is not used again) */
  effectTemplate = CFxScheduler__GetNewEffectTemplate( &scheduler, effectName, scheduler );
  if ( !scheduler || !effectTemplate )
    return 0;

  group = parseTree[7];   /* base->GetSubGroups() */
  while ( group )
  {
    groupName = *(const char **)group;
    if ( !_stricmp( groupName, "particle" ) )         { primType = 1;  goto ADD_PRIM; }
    if ( !_stricmp( groupName, "line" ) )             { primType = 2;  goto ADD_PRIM; }
    if ( !_stricmp( groupName, "tail" ) )             { primType = 3;  goto ADD_PRIM; }
    if ( !_stricmp( groupName, "sound" ) )            { primType = 6;  goto ADD_PRIM; }
    if ( !_stricmp( groupName, "cylinder" ) )         { primType = 4;  goto ADD_PRIM; }
    if ( !_stricmp( groupName, "electricity" ) )      { primType = 9;  goto ADD_PRIM; }
    if ( !_stricmp( groupName, "emitter" ) )          { primType = 5;  goto ADD_PRIM; }
    if ( !_stricmp( groupName, "decal" ) )            { primType = 7;  goto ADD_PRIM; }
    if ( !_stricmp( groupName, "orientedparticle" ) ) { primType = 8;  goto ADD_PRIM; }
    if ( !_stricmp( groupName, "fxrunner" ) )         { primType = 10; goto ADD_PRIM; }
    if ( !_stricmp( groupName, "light" ) )            { primType = 11; goto ADD_PRIM; }
    if ( !_stricmp( groupName, "cameraShake" ) )      { primType = 12; goto ADD_PRIM; }
    if ( !_stricmp( groupName, "flash" ) )            { primType = 13; goto ADD_PRIM; }

NEXT_GROUP:
    group = *(unsigned int *)( group + FX_GPGROUP_OFS( mNext ) );
    continue;

ADD_PRIM:
    prim = (int)new CPrimitiveTemplate;
    *(unsigned int *)&FX_TMPL(prim)->mType = primType;
    CPrimitiveTemplate__ParsePrimitive( prim, group );

    {
      FxAddPrimitive primitiveArg = { prim };
      CFxScheduler__AddPrimitiveToEffect( (int)effectTemplate, 0, primitiveArg );   /* add it to the effect */
    }
    goto NEXT_GROUP;
  }
  return scheduler;
}

void __stdcall CFxScheduler__AddPrimitiveToEffect(int effectTemplate,int unusedReg,FxAddPrimitive primitiveArg){
 int count=FX_EFFECT_TEMPLATE(effectTemplate)->mPrimitiveCount;
 if(count>=FX_EFFECT_TEMPLATE_PRIMITIVE_CAPACITY){SFxHelper__Print((int)&theFxHelper,"FxScheduler:  Error--too many primitives in an effect\n");return;}
 *(int *)(effectTemplate+count*4+72)=primitiveArg.pointer;
 ++FX_EFFECT_TEMPLATE(effectTemplate)->mPrimitiveCount;
}

/* ---- CFxScheduler__GetNewEffectTemplate  0x00493420 ----  VERIFIED */
char *__stdcall CFxScheduler__GetNewEffectTemplate( int *outId, char *name, int scheduler )
{
  int            i;
  char          *t;

  for ( i = 1; i < FX_EFFECT_TEMPLATE_COUNT; i++ )
  {
    t = (char *)( scheduler + FX_EFFECT_TEMPLATE_SIZE * i );
    if ( !*t )   /* !mInUse */
    {
      *outId = i;
      memset( t, 0, FX_EFFECT_TEMPLATE_SIZE );

      if ( name )
      {
        *(int *)stl_fxEffectIdMap_index_m( scheduler + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET, FxStdString( name ) ) = i;   /* mEffectIDs[file] = i */
        strcpy( t + 2, name );
      }

      *t = 1;
      return t;
    }
  }

  SFxHelper__Print( (int)&theFxHelper,
                    "FxScheduler:  Error--reached max effects\n" );
  *outId = 0;
  return 0;
}

/* ---- CFxScheduler__GetEffectCopy_name_m  0x00493540 ----  VERIFIED */
char *__fastcall CFxScheduler__GetEffectCopy_name_m( int scheduler, char *name, int *outId )
{
  return CFxScheduler__CopyEffect_m( *(int *)stl_fxEffectIdMap_index_m( scheduler + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET, FxStdString( name ) ),   /* mEffectIDs[file] */
                                     scheduler, outId );
}

/* ---- CFxScheduler__CopyEffect_m  0x004935E0 ----  VERIFIED */
char *__stdcall CFxScheduler__CopyEffect_m( int effectId, int scheduler, int *outId )
{
  char *dst;

  if ( effectId < FX_EFFECT_ID_FIRST || effectId >= FX_EFFECT_TEMPLATE_COUNT
       || !*( (char *)scheduler + FX_EFFECT_TEMPLATE_SIZE * effectId ) )
  {
    SFxHelper__Print( (int)&theFxHelper,
                      "FxScheduler: Bad effect file copy request\n" );
    *outId = 0;
    return 0;
  }

  dst = CFxScheduler__GetNewEffectTemplate( outId, 0, scheduler );
  if ( dst && *outId )
  {
    ( (SEffectTemplateCopier *)( (char *)scheduler + FX_EFFECT_TEMPLATE_SIZE * effectId ) )->CopyTo( (SEffectTemplate *)dst );
    dst[1] = 1;
    return dst;
  }

  *outId = 0;
  return 0;
}

/* ---- CFxScheduler__GetPrimitiveCopy  0x00493650 ----  VERIFIED */
/* Retail pops its two stack arguments (retn 8); the template travels in EDI. */
int __stdcall CFxScheduler__GetPrimitiveCopy( int effectTemplate, int unusedReg, char *primName )
{
  int i;

  (void)unusedReg;   /* unused (retained for the retail signature) */
  if ( !effectTemplate || !*(unsigned char *)effectTemplate )   /* template missing or inactive */
    return 0;

  for ( i = 0; i < FX_EFFECT_TEMPLATE(effectTemplate)->mPrimitiveCount; i++ )
  {
    if ( !_stricmp( (const char *)( *(unsigned int *)( effectTemplate + 72 + 4 * i ) + FX_PRIMITIVE_TEMPLATE_NAME_OFFSET ), primName ) )
      return *(unsigned int *)( effectTemplate + 72 + 4 * i );
  }
  return 0;
}

/* ---- ReportPlayEffectError  0x004936A0 ----  [CONFIRMED] */
void __cdecl ReportPlayEffectError( int effectId )
{
  SFxHelper__Print( (int)&theFxHelper,
                    "CFxScheduler::PlayEffect called with invalid effect ID: %i\n", effectId );
}

/* ---- CFxScheduler__PlayEffect_id_simple_m  0x004936C0 ----  [HIGH] */
__declspec(noinline) void __stdcall CFxScheduler__PlayEffect_id_simple_m( int effectId, float *origin, unsigned int *self )
{
  float axis[3][3];

  VectorSet( axis[0], 0.0f, 0.0f, 1.0f );
  VectorSet( axis[1], 1.0f, 0.0f, 0.0f );
  VectorSet( axis[2], 0.0f, 1.0f, 0.0f );
  CFxScheduler__PlayEffect_id_axis( self, effectId, origin, (int *)axis, 0 );
}

/* ---- CFxScheduler__PlayEffect_id_fwd_m  0x00493730 ----  IMPLEMENTED (retail) */
/* CFxScheduler::PlayEffect(id, origin, forward): build an axis whose first
 * row is a copy of `forward` (MakeNormalVectors fills right/up from the
 * caller's vector) and play the effect with no bolt.  Retail is __userpurge:
 * forward@<eax>, then (this, id, origin) on the stack, retn 0Ch; the tree
 * passes forward first. */
void __stdcall CFxScheduler__PlayEffect_id_fwd_m( unsigned int *self, int effectId, float *origin, int *forward )
{
  float axis[3][3];   /* forward, right, up */

  VectorCopy( (const float *)forward, axis[0] );
  MakeNormalVectors( (const float *)forward, axis[1], axis[2] );
  CFxScheduler__PlayEffect_id_axis( self, effectId, origin, (int *)axis, 0 );
}

/* ---- CFxScheduler__PlayEffect_name_bolt_m  0x00493780 ----  [HIGH] */
void __stdcall CFxScheduler__PlayEffect_name_bolt_m( char *name, unsigned int *self, float *origin,
                                                   int *axis, int *bolt )
{
  int          *entry;
  char          baseName[64];
  char         *dst;
  const char   *src;

  /* copy the effect name up to the first '.' */
  dst = baseName;
  for ( src = name; *src && *src != '.'; ++src )
    *dst++ = *src;
  *dst = 0;

  FxStdString keyStr( baseName );   /* mEffectIDs[sfile] */

  entry = (int *)stl_fxEffectIdMap_index_m( (int)self + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET, keyStr );
  CFxScheduler__PlayEffect_id_axis( self, *entry, origin, axis, bolt );
}

/* ---- CFxScheduler__PlayEffect_id_axis  0x00493870 ----  VERIFIED */
/* CFxScheduler::PlayEffect( id, origin, axis, bolt ): spawn or schedule every
 * primitive of an effect. */
vec_t DistanceSquared( const vec3_t p1, const vec3_t p2 );
void __stdcall   CFxScheduler__PlayEffect_id_axis( unsigned int *self, int id, float *origin, int *axis, int *bolt )
{
  unsigned int  *fx;
  int      tmpl;
  int      i;
  int      t;
  int      count;
  int      delay;
  int      total;
  int     *sfx;
  float    factor;
  /* retail [ebp-30h] is ONE 48-byte orientation, origin then 3x3 axis;
   * FX_GetBoneOrientation writes all 12 floats through one pointer, so keep
   * them contiguous. */
  float    orient[12];         /* [ebp-30h] BYREF */

  factor = 0.0f;

  /* 0x0049387E-0x0049389F: 1 <= id < 128 and the template must be active. */
  if ( id < 1 || id >= 128 || !*((unsigned char *)self + 0xA8 * id) )
  {
    re_SetIgnorePrecacheErrors(1);
    id = CFxScheduler__RegisterEffect( (unsigned int *)theFxScheduler, "fx/error.efx", 0 );
    re_SetIgnorePrecacheErrors(0);
    if ( !id )
    {
      SFxHelper__Print( (int)&theFxHelper,
                        "CFxScheduler::PlayEffect called with invalid effect ID: %i\n",
                        0 );
      return;
    }
  }

  /* don't bother scheduling the effect if the system is frozen or off */
  if ( !fx_freeze->integer && fx_enable->integer )
  {
    if ( bolt && *bolt >= 0 )
    {
      if ( !FX_GetBoneOrientation( (unsigned int *)bolt, orient ) )
        return;
    }
    else
    {
      if ( origin )
        VectorCopy( origin, orient );
      else
        VectorClear( orient );
      AxisCopy( (float (*)[3])axis, (float (*)[3])( orient + 3 ) );
    }

    fx    = &self[42 * id];
    total = 0;
    for ( i = 0; i < FX_EFFECT_TEMPLATE(fx)->mPrimitiveCount; i++ )
    {
      ++fxPrimitiveTemplatePlayCount;
      tmpl = (int)FX_EFFECT_TEMPLATE(fx)->mPrimitives[i];

      /* cull range is squared */
      if ( FX_TMPL(tmpl)->mCullRange
        && DistanceSquared( origin, &fxHelperViewOriginX ) > (float)( FX_TMPL(tmpl)->mCullRange * FX_TMPL(tmpl)->mCullRange ) )
        continue;

      /* count = mSpawnCount.GetRoundedVal() */
      if ( FX_TMPL(tmpl)->mSpawnCount.mMin == FX_TMPL(tmpl)->mSpawnCount.mMax )
        count = (int)FX_TMPL(tmpl)->mSpawnCount.mMin;
      else
        count = (int)( Com_RandFloatRange_m( FX_TMPL(tmpl)->mSpawnCount.mMin,
                                             FX_TMPL(tmpl)->mSpawnCount.mMax ) + 0.5f );

      /* a copy keeps a reference count so the template outlives its bits */
      if ( FX_TMPL(tmpl)->mCopy )
        FX_TMPL(tmpl)->mRefCount = count;

      if ( FX_TMPL(tmpl)->mSpawnFlags & 0x2000 )   /* FX_EVEN_DISTRIBUTION */
        {
          /* GetMax() / GetMin() copies: retail esp+30h / esp+34h */
          float mx = FX_TMPL(tmpl)->mSpawnDelay.mMax;
          float mn = FX_TMPL(tmpl)->mSpawnDelay.mMin;
          factor = (float)fabs( mx - mn ) / (float)count;
        }

      total += count;

      /* schedule the random number of bits */
      for ( t = 0; t < count; t++ )
      {
        ++fxPrimitiveSpawnCount;
        if ( FX_TMPL(tmpl)->mSpawnFlags & 0x2000 )
          delay = (int)( (float)t * factor );
        else
        {
          float val;   /* mSpawnDelay.GetVal() */
          if ( FX_TMPL(tmpl)->mSpawnDelay.mMin == FX_TMPL(tmpl)->mSpawnDelay.mMax )
            val = FX_TMPL(tmpl)->mSpawnDelay.mMin;
          else
            val = Com_RandFloatRange_m( FX_TMPL(tmpl)->mSpawnDelay.mMin, FX_TMPL(tmpl)->mSpawnDelay.mMax );
          delay = (int)val;
        }

        /* if the delay is so small, we may as well just create this bit right now */
        if ( delay < 1 )
        {
          CFxScheduler__CreateEffect( self, tmpl, bolt, orient, (float *)(int)( orient + 3 ), -delay );
        }
        else
        {
          sfx = (int *)FxMem_AllocScheduledEffect( (int *)&fxPool_ScheduledEffect, 0x44 );
          if ( sfx )
          {
            FX_SCHED(sfx)->mStartTime      = fxMTime + delay;
            FX_SCHED(sfx)->mEffectID       = id;
            FX_SCHED(sfx)->mPrimitiveIndex = i;

            if ( bolt )
            {
              FX_SCHED(sfx)->mBolt.dobjHandle = bolt[0];
              FX_SCHED(sfx)->mBolt.boneIndex  = bolt[1];
            }
            else
            {
              FX_SCHED(sfx)->mBolt.dobjHandle = -1;
              FX_SCHED(sfx)->mBolt.boneIndex  = -1;
            }

            if ( bolt && bolt[0] >= 0 )
            {
              if ( bolt[1] < 0 )
                AxisCopy( (float (*)[3])axis, FX_SCHED(sfx)->mAxis );
            }
            else
            {
              if ( origin )
                VectorCopy( origin, FX_SCHED(sfx)->mOrigin );
              else
                VectorClear( FX_SCHED(sfx)->mOrigin );
              *(int *)&FX_SCHED(sfx)->mAxis[0][0] = axis[0];
              *(int *)&FX_SCHED(sfx)->mAxis[0][1] = axis[1];
              *(int *)&FX_SCHED(sfx)->mAxis[0][2] = axis[2];
              *(int *)&FX_SCHED(sfx)->mAxis[1][0] = axis[3];
              *(int *)&FX_SCHED(sfx)->mAxis[1][1] = axis[4];
              *(int *)&FX_SCHED(sfx)->mAxis[1][2] = axis[5];
              *(int *)&FX_SCHED(sfx)->mAxis[2][0] = axis[6];
              *(int *)&FX_SCHED(sfx)->mAxis[2][1] = axis[7];
              *(int *)&FX_SCHED(sfx)->mAxis[2][2] = axis[8];
            }

            /* mFxSchedule.push_front( sfx ): the list helper, inlined */
            stl_fxScheduledList_pushFront_m( (int)( self + 5379 ), (unsigned int *)&sfx );
          }
        }
      }
    }

    if ( total && fx_count->integer )
      ((void (__cdecl *)( float *, int, unsigned int *, int ))re_AddPlume)(
          orient, total, colorDebugYellow, 3000 );

    /* a temporary template is consumed by playing it once */
    if ( FX_EFFECT_TEMPLATE(fx)->mCopy )
      FX_EFFECT_TEMPLATE(fx)->mInUse = 0;
  }
}

/* ---- CFxScheduler__PlayEffect_name_simple_m  0x00493D30 ----  [HIGH] */
void __stdcall CFxScheduler__PlayEffect_name_simple_m( char *name, unsigned int *self, float *origin )
{
  int          *entry;
  char          baseName[64];
  char         *dst;
  const char   *src;

  /* copy the effect name up to the first '.' */
  dst = baseName;
  for ( src = name; *src && *src != '.'; ++src )
    *dst++ = *src;
  *dst = 0;

  FxStdString keyStr( baseName );   /* mEffectIDs[sfile] */

  entry = (int *)stl_fxEffectIdMap_index_m( (int)self + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET, keyStr );
  CFxScheduler__PlayEffect_id_simple_m( *entry, origin, self );
}

/* ---- CFxScheduler__PlayEffect_name_m  0x00493E10 ----  [HIGH] */
void __stdcall CFxScheduler__PlayEffect_name_m( int *direction, char *name, unsigned int *self, float *origin )
{
  int           effectId;
  char          baseName[64];
  char         *dst;
  const char   *src;
  int           axis[9];   /* axis[3][3]: forward (from direction) then right/up */

  /* copy the effect name up to the first '.' */
  dst = baseName;
  for ( src = name; *src && *src != '.'; ++src )
    *dst++ = *src;
  *dst = 0;

  FxStdString keyStr( baseName );   /* mEffectIDs[sfile] */

  effectId = *(int *)stl_fxEffectIdMap_index_m( (int)self + FX_SCHEDULER_EFFECT_IDS_MAP_OFFSET, keyStr );

  /* build an axis with `direction` as forward */
  axis[0] = direction[0];
  axis[1] = direction[1];
  axis[2] = direction[2];
  MakeNormalVectors( (const float *)direction, (float *)&axis[3], (float *)&axis[6] );

  CFxScheduler__PlayEffect_id_axis( self, effectId, origin, axis, 0 );
}

void FX_DrawStats_m();
unsigned int *__cdecl stl_fxScheduledList_begin_m( unsigned int *result, int list );
unsigned int *__cdecl stl_fxScheduledList_end_m( unsigned int *result, int list );

int __cdecl stl_fxScheduledList_iterNotEqual_m( unsigned int *left, unsigned int *right );
int __cdecl stl_fxScheduledList_iterDeref_m( unsigned int *iter );
unsigned int *__fastcall stl_fxScheduledList_iterPostinc_m( unsigned int *result, unsigned int **iter, FxPostIncrementArgument postfix );
unsigned int *__stdcall stl_fxScheduledList_erase_m( int list, unsigned int *result, FxListIteratorArgument whereArg );
unsigned int *__cdecl stl_fxScheduledList_iterDefaultCtor_m( unsigned int *result );

/* ---- CFxScheduler__AddScheduledEffects  0x00493F40 ----  VERIFIED */
void __cdecl CFxScheduler__AddScheduledEffects( unsigned int *self )
{
  unsigned int *itr;
  unsigned int *next;
  unsigned int *endItr;
  unsigned int *tmp;
  unsigned int *erased;
  int    *rec;
  int     tmpl;
  float   ori[13];   /* orientation (12 floats); retail frame keeps one more dword above it (sub esp, 38h) */
  FxPostIncrementArgument postfix;

  if ( !fx_enable->integer )
    return;

  stl_fxScheduledList_begin_m( (unsigned int *)&itr, (int)( self + 5379 ) );
  while ( stl_fxScheduledList_iterNotEqual_m( (unsigned int *)&itr,
            stl_fxScheduledList_end_m( (unsigned int *)&endItr, (int)( self + 5379 ) ) ) )
  {
    next = itr;
    postfix.value = 0;
    stl_fxScheduledList_iterPostinc_m( (unsigned int *)&tmp, &next, postfix );

    rec = *(int **)stl_fxScheduledList_iterDeref_m( (unsigned int *)&itr );
    if ( rec[2] <= fxMTime )                /* +0x08 scheduledTime reached */
    {
      tmpl = self[42 * rec[0] + 18 + rec[1]];

      if ( rec[3] >= 0 )
      {
        FX_GetBoneOrientation( (unsigned int *)(rec + 3), ori );
        rec = *(int **)stl_fxScheduledList_iterDeref_m( (unsigned int *)&itr );
        CFxScheduler__CreateEffect( self, tmpl, rec + 3,
                                    ori, ori + 3,
                                    fxMTime - rec[2] );
      }
      else
      {
        CFxScheduler__CreateEffect( self, tmpl, rec + 3,
                                    (float *)(rec + 5), (float *)(rec + 8),
                                    fxMTime - rec[2] );
      }

      FxPool_FreeScheduledEffect( &fxPool_ScheduledEffect, *(char **)stl_fxScheduledList_iterDeref_m( (unsigned int *)&itr ) );
      stl_fxScheduledList_erase_m( (int)( self + 5379 ), (unsigned int *)&erased, FxListIterator( (unsigned int *)itr ) );
    }
    itr = next;
  }

  FX_DrawStats_m();
}

/* ---- CFxScheduler__CreateEffect  0x00494050 ----  VERIFIED
 * @fidelity: verified
 */
#ifdef __cplusplus
void CFxScheduler::CreateEffect( int tmpl, int *bolt, float *origin, float *axisIn, int timeOffset )
#else
void __cdecl CFxScheduler__CreateEffect( unsigned int *self, int tmpl, int *bolt,
                                         float *origin, float *axisIn,
                                         int timeOffset )
#endif
{
#ifdef __cplusplus
  unsigned int *self = (unsigned int *)this;
#endif
  float  axis[9];          
  float  start[3];         
  char  *boltFrame;             
  trace_t results;         
  int    scratch;             
  float  spinAngle;
  float  upX, startY;
  int    startXBits;
  int    selfAddr;
  int    tmplCopy;
  char *tpl = (char *)tmpl;
  float endp[3], tmp3[3], spawnOrigin[3], rng3[3];
  float velocity[3], accel[3], sum3[3];
  float ringAngle, gravity, frac;
  




  int   rangeBits;
  int   rgbComponent, *acquired, *heldFrame;
  int   life, killTime, elasticity, rgbParm, rotation, rotationDelta;
  int   alphaStart, alphaEnd, alphaParm,  sizeStart, sizeEnd, sizeParm;
  int   size2Start, size2End, size2Parm,  lengthStart, lengthEnd, lengthParm;
  int   angleX, angleY, angleZ,  angleDeltaComponent;
  int   density, variance, flags;
  int   shader, impactFxId, deathFxId, emitterFxId;
  int   oAlphaStart, oAlphaEnd, oAlphaParm, oSizeStart, oSizeEnd, oSizeParm, oSize2Start, oSize2End, oSize2Parm, decalShader;

#ifdef __cplusplus
  (void)&CFxScheduler::CreateEffect;   /* keeps the declared __thiscall under LTCG */
#endif
  selfAddr = (int)self;                       
  boltFrame = 0;                               
  tmplCopy   = tmpl;                            
  
  axis[0] = axisIn[0];  axis[1] = axisIn[1];  axis[2] = axisIn[2];
  axis[3] = axisIn[3];  axis[4] = axisIn[4];  axis[5] = axisIn[5];
  upX      = axisIn[6];
  axis[6] = upX;
  axis[7] = axisIn[7];  axis[8] = axisIn[8];
  if ( ( *(int *)(tmpl + FX_TMPL_OFS( mSpawnFlags )) & 0x1000 ) != 0 )
  {
    *(int *)&scratch = rand();                                  
    spinAngle = (float)( *(int *)&scratch / 32768.0 * 360.0 );       
    
    RotatePointAroundVector( &axis[3], &axis[0], axisIn + 3, spinAngle );
    tmplCopy = tmpl;                                               
    axis[6] = axis[1] * axis[5] - axis[2] * axis[4];          
    axis[7] = axis[2] * axis[3] - axis[0] * axis[5];          
    axis[8] = axis[0] * axis[4] - axis[1] * axis[3];          
  }
  if ( ( *(int *)(tmplCopy + FX_TMPL_OFS( mSpawnFlags )) & 0x100 ) != 0 )
  {
    if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1X.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1X.mMax )) )     
      startXBits = *(int *)(tmplCopy + FX_TMPL_OFS( mOrigin1X.mMin ));                               
    else
    {
      *(float *)&scratch = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1X.mMin )),
                                                     *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1X.mMax )) );
      startXBits = scratch;
    }
    *(int *)&start[0] = startXBits;                                   
    startY = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Y.mMin ));                               
    if ( startY != *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Y.mMax )) )
    {
      *(float *)&scratch = (float)Com_RandFloatRange_m( startY, *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Y.mMax )) );
      startY = *(float *)&scratch;
    }
    start[1] = startY;                                            
    if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Z.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Z.mMax )) )     
      start[2] = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Z.mMin ));
    else
    {
      *(float *)&scratch = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Z.mMin )),
                                                     *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Z.mMax )) );
      *(int *)&start[2] = scratch;                               
    }
  }
  else
  {
    float ofsUp, ofsRight, ofsFwd;
    if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Z.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Z.mMax )) )     
      ofsUp = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Z.mMin ));
    else
      ofsUp = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Z.mMin )),
                                           *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Z.mMax )) );
    if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Y.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Y.mMax )) )     
      ofsRight = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Y.mMin ));
    else
      ofsRight = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Y.mMin )),
                                              *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1Y.mMax )) );
    if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1X.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1X.mMax )) )     
      ofsFwd = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1X.mMin ));
    else
      ofsFwd = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1X.mMin )),
                                            *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin1X.mMax )) );
    start[0] = ofsFwd * axis[0] + ofsRight * axis[3] + ofsUp * axis[6];
    start[1] = ofsFwd * axis[1] + ofsRight * axis[4] + ofsUp * axis[7];
    start[2] = ofsFwd * axis[2] + ofsRight * axis[5] + ofsUp * axis[8];
  }
  start[0] = start[0] + origin[0];                            
  start[1] = start[1] + origin[1];
  start[2] = start[2] + origin[2];
  if ( ( *(int *)(tmplCopy + FX_TMPL_OFS( mSpawnFlags )) & 1 ) != 0 )                     
  {
    float yaw, pitch, sinYaw, cosYaw, sinPitch, cosPitch;
    float rad, hgt, horiz;
    
    float sph[3];
    *(int *)&scratch = rand();                                   
    
    yaw    = (float)( *(int *)&scratch / 32768.0 * 360.0 * 3.1415927f / 180.0 );
    cosYaw = (float)cos( yaw );                               
    sinYaw = (float)sin( yaw );                               
    *(int *)&scratch = rand();                                   
    
    pitch    = (float)( *(int *)&scratch / 32768.0 * 180.0 * 3.1415927f / 180.0 );
    cosPitch = (float)cos( pitch );                           
    sinPitch = (float)sin( pitch );                           
    tmplCopy = tmpl;
    if ( *(float *)(tmpl + FX_TMPL_OFS( mRadius.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mRadius.mMax )) )
      rad = *(float *)(tmpl + FX_TMPL_OFS( mRadius.mMin ));
    else
      rad = (float)Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRadius.mMin )),
                                         *(float *)(tmpl + FX_TMPL_OFS( mRadius.mMax )) );
    if ( *(float *)(tmpl + FX_TMPL_OFS( mHeight.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mHeight.mMax )) )
      hgt = *(float *)(tmpl + FX_TMPL_OFS( mHeight.mMin ));
    else
      hgt = (float)Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mHeight.mMin )),
                                         *(float *)(tmpl + FX_TMPL_OFS( mHeight.mMax )) );
    horiz = rad * sinPitch;                                   
    sph[0] = horiz * sinYaw;                                  
    sph[1] = horiz * cosYaw;                                  
    sph[2] = hgt   * cosPitch;                                
    start[0] = sph[0] + start[0];
    start[1] = sph[1] + start[1];
    start[2] = sph[2] + start[2];
    if ( ( *(int *)(tmpl + FX_TMPL_OFS( mSpawnFlags )) & 2 ) != 0 )
    {
      VectorNormalize2( sph, &axis[0] );                      
      MakeNormalVectors( &axis[0], &axis[3], &axis[6] );      
    }
    goto LABEL_43;
  }
  if ( ( *(int *)(tmplCopy + FX_TMPL_OFS( mSpawnFlags )) & 4 ) != 0 )                     
  {
    float hgt, rad, axial;
    float ofs[3];
    float tmp3[3];
    if ( *(float *)(tmplCopy + FX_TMPL_OFS( mHeight.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mHeight.mMax )) )
      hgt = *(float *)(tmplCopy + FX_TMPL_OFS( mHeight.mMin ));
    else
      hgt = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mHeight.mMin )),
                                         *(float *)(tmplCopy + FX_TMPL_OFS( mHeight.mMax )) );
    *(int *)&scratch = rand();                                   
    axial = (float)( ( *(int *)&scratch / 32768.0
                     + *(int *)&scratch / 32768.0 - 1.0 ) * hgt * 0.5 );
    ofs[0] = axial;
    if ( *(float *)(tmpl + FX_TMPL_OFS( mRadius.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mRadius.mMax )) )
      rad = *(float *)(tmpl + FX_TMPL_OFS( mRadius.mMin ));
    else
      rad = (float)Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRadius.mMin )),
                                         *(float *)(tmpl + FX_TMPL_OFS( mRadius.mMax )) );
    tmp3[0] = axis[3] * rad;                                  
    tmp3[1] = axis[4] * rad;
    tmp3[2] = axis[5] * rad;
    tmp3[0] = axis[0] * ofs[0] + tmp3[0];                     
    tmp3[1] = axis[1] * ofs[0] + tmp3[1];
    tmp3[2] = axis[2] * ofs[0] + tmp3[2];
    *(int *)&scratch = rand();                                   
    ringAngle = (float)( *(int *)&scratch / 32768.0 * 360.0 );
    RotatePointAroundVector( ofs, &axis[0], tmp3, ringAngle );     
    tmplCopy = tmpl;
    start[0] = ofs[0] + start[0];                             
    start[1] = ofs[1] + start[1];
    start[2] = ofs[2] + start[2];
    if ( ( *(int *)(tmpl + FX_TMPL_OFS( mSpawnFlags )) & 2 ) != 0 )                 
    {
      float refY = 0.0, refZ = 1.0;
      VectorNormalize2( ofs, &axis[0] );                      
      if ( axis[2] == 1.0 )
      {
        refY = 1.0;
        refZ = 0.0;
      }
      axis[3] = refY * axis[2] - refZ * axis[1];              
      axis[4] = refZ * axis[0] - axis[2] * 0.0;
      axis[5] = axis[1] * 0.0 - refY * axis[0];
      axis[6] = axis[1] * axis[5] - axis[2] * axis[4];        
      axis[7] = axis[2] * axis[3] - axis[0] * axis[5];        
      axis[8] = axis[0] * axis[4] - axis[1] * axis[3];        
    }
    goto LABEL_43;
  }
LABEL_43:                                     
  {
    int type = *(int *)(tmplCopy + FX_TMPL_OFS( mType ));                           
    if ( type == 1 || type == 8 || type == 3 || type == 5 )   
    {
      if ( ( *(int *)(tmplCopy + FX_TMPL_OFS( mSpawnFlags )) & 0x400 ) != 0 )             
      {
        float a, b, c;
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mVelX.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mVelX.mMax )) )
          a = *(float *)(tmplCopy + FX_TMPL_OFS( mVelX.mMin ));                         
        else
          a = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mVelX.mMin )),
                                           *(float *)(tmplCopy + FX_TMPL_OFS( mVelX.mMax )) );
        velocity[0] = a;                                             
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mVelY.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mVelY.mMax )) )
          b = *(float *)(tmplCopy + FX_TMPL_OFS( mVelY.mMin ));                         
        else
          b = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mVelY.mMin )),
                                           *(float *)(tmplCopy + FX_TMPL_OFS( mVelY.mMax )) );
        velocity[1] = b;                                             
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mVelZ.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mVelZ.mMax )) )
          velocity[2] = *(float *)(tmplCopy + FX_TMPL_OFS( mVelZ.mMin ));                      
        else
          velocity[2] = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mVelZ.mMin )),
                                              *(float *)(tmplCopy + FX_TMPL_OFS( mVelZ.mMax )) );
      }
      else
      {
        float compUp, compRight, compFwd;
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mVelZ.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mVelZ.mMax )) )
          compUp = *(float *)(tmplCopy + FX_TMPL_OFS( mVelZ.mMin ));                    
        else
          compUp = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mVelZ.mMin )),
                                                *(float *)(tmplCopy + FX_TMPL_OFS( mVelZ.mMax )) );
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mVelY.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mVelY.mMax )) )
          compRight = *(float *)(tmplCopy + FX_TMPL_OFS( mVelY.mMin ));                 
        else
          compRight = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mVelY.mMin )),
                                                   *(float *)(tmplCopy + FX_TMPL_OFS( mVelY.mMax )) );
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mVelX.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mVelX.mMax )) )
          compFwd = *(float *)(tmplCopy + FX_TMPL_OFS( mVelX.mMin ));                   
        else
          compFwd = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mVelX.mMin )),
                                                 *(float *)(tmplCopy + FX_TMPL_OFS( mVelX.mMax )) );
        velocity[0] = compRight * axis[3] + compUp * axis[6] + compFwd * axis[0];
        velocity[1] = compRight * axis[4] + compUp * axis[7] + compFwd * axis[1];
        velocity[2] = compUp    * axis[8] + compFwd  * axis[2] + compRight * axis[5];
      }
      if ( ( *(int *)(tmpl + FX_TMPL_OFS( mSpawnFlags )) & 0x10000 ) != 0 )
        Com_Printf( "FX_PORT wind TBD.\n" );
      if ( ( *(int *)(tmplCopy + FX_TMPL_OFS( mSpawnFlags )) & 0x800 ) != 0 )               
      {
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelX.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mAccelX.mMax )) )
          accel[0] = *(float *)(tmplCopy + FX_TMPL_OFS( mAccelX.mMin ));                        
        else
          accel[0] = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelX.mMin )),
                                              *(float *)(tmplCopy + FX_TMPL_OFS( mAccelX.mMax )) );
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelY.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mAccelY.mMax )) )
          accel[1] = *(float *)(tmplCopy + FX_TMPL_OFS( mAccelY.mMin ));                        
        else
          accel[1] = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelY.mMin )),
                                              *(float *)(tmplCopy + FX_TMPL_OFS( mAccelY.mMax )) );
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelZ.mMin )) != *(float *)(tmplCopy + FX_TMPL_OFS( mAccelZ.mMax )) )
          accel[2] = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelZ.mMin )),
                                              *(float *)(tmplCopy + FX_TMPL_OFS( mAccelZ.mMax )) );
        else
          accel[2] = *(float *)(tmplCopy + FX_TMPL_OFS( mAccelZ.mMin ));                        
      }
      else
      {
        float cUp, cRight, cFwd;
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelZ.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mAccelZ.mMax )) )
          cUp = *(float *)(tmplCopy + FX_TMPL_OFS( mAccelZ.mMin ));                         
        else
          cUp = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelZ.mMin )),
                                             *(float *)(tmplCopy + FX_TMPL_OFS( mAccelZ.mMax )) );
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelY.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mAccelY.mMax )) )
          cRight = *(float *)(tmplCopy + FX_TMPL_OFS( mAccelY.mMin ));                      
        else
          cRight = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelY.mMin )),
                                                *(float *)(tmplCopy + FX_TMPL_OFS( mAccelY.mMax )) );
        if ( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelX.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mAccelX.mMax )) )
          cFwd = *(float *)(tmplCopy + FX_TMPL_OFS( mAccelX.mMin ));                        
        else
          cFwd = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mAccelX.mMin )),
                                              *(float *)(tmplCopy + FX_TMPL_OFS( mAccelX.mMax )) );
        accel[0] = cRight * axis[3] + cUp * axis[6] + cFwd * axis[0];
        accel[1] = cRight * axis[4] + cUp * axis[7] + cFwd * axis[1];
        accel[2] = cUp    * axis[8] + cFwd * axis[2] + cRight * axis[5];
      }
      if ( *(float *)(tmplCopy + FX_TMPL_OFS( mGravity.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mGravity.mMax )) )
        gravity = *(float *)(tmplCopy + FX_TMPL_OFS( mGravity.mMin ));                          
      else
        gravity = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mGravity.mMin )),
                                            *(float *)(tmplCopy + FX_TMPL_OFS( mGravity.mMax )) );
      accel[2] = gravity + accel[2];                               
      if ( timeOffset > 0 )                                     
      {
        float t, half, coeff;
        int   i;
        
        t    = (float)( (double)(float)timeOffset * 0.001f );   
        half = (float)( t * t * 0.5 );                          
        velocity[0] = t * accel[0] + velocity[0];                         
        velocity[1] = t * accel[1] + velocity[1];                         
        velocity[2] = t * accel[2] + velocity[2];                         
        coeff = half + t;                                       
        for ( i = 0; i < 3; ++i )                               
          start[i] = coeff * velocity[i] + start[i];
      }
    }   
  }
  {
    int type2 = *(int *)(tmplCopy + FX_TMPL_OFS( mType ));                          
    if ( type2 == 2 || type2 == 9 )                           
    {
      int flags = *(int *)(tmplCopy + FX_TMPL_OFS( mSpawnFlags ));
      if ( ( flags & 0x10 ) != 0 )                            
      {
        float endp[3];
        endp[0] = (float)( axis[0] * 16384.0 + start[0] );    
        endp[1] = (float)( axis[1] * 16384.0 + start[1] );
        endp[2] = (float)( axis[2] * 16384.0 + start[2] );
        if ( ( flags & 0x40 ) != 0 )                          
        {
          if ( ( flags & 0x200 ) != 0 )                       
          {
            float dx, dy, dz;
            if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMax )) )
              dx = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin ));                     
            else
              dx = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin )),
                                                *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMax )) );
            if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMax )) )
              dy = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin ));                     
            else
              dy = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin )),
                                                *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMax )) );
            if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMax )) )
              dz = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin ));                    
            else
              dz = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin )),
                                                *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMax )) );
            endp[0] = dx + endp[0];                           
            endp[1] = dy + endp[1];
            endp[2] = dz + endp[2];                           
          }
          else
          {
            float lx, ly, lz, world[3];
            if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMax )) )
              lz = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin ));                    
            else
              lz = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin )),
                                                *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMax )) );
            if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMax )) )
              ly = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin ));                     
            else
              ly = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin )),
                                                *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMax )) );
            if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMax )) )
              lx = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin ));                     
            else
              lx = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin )),
                                                *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMax )) );
            FX_AxisLocalToWorld_m( axis, world, lx, ly, lz );            
            endp[0] = world[0] + endp[0];
            endp[1] = world[1] + endp[1];
            endp[2] = world[2] + endp[2];
          }
        }
        results.fraction = 1.0;                               
        CM_Trace( &results, start, endp,
                  (const float *)((void *)0), (const float *)((void *)0),
                  0, vec3_origin, 1, 0,
                  ((void *)0) );
        results.entityNum = 1022;                             
        if ( results.fraction == 1.0 )
          results.entityNum = 1023;

        


        spawnOrigin[1] = results.endpos[1];                   
        spawnOrigin[0] = results.endpos[0];                   
        spawnOrigin[2] = results.endpos[2];                   

        if ( ( *(int *)(tmplCopy + FX_TMPL_OFS( mSpawnFlags )) & 0x20 ) != 0 )            
        {
          int listBase, listCount, chosen;
          
          int chainAxis[9];

          listBase = *(int *)(tmplCopy + FX_TMPL_OFS( mImpactFxHandles.first ));                     
          if ( listBase
            && (listCount = (*(int *)(tmplCopy + FX_TMPL_OFS( mImpactFxHandles.last )) - listBase) >> 2) != 0 )
          {
            com_randSeed_m = 214013 * com_randSeed_m + 2531011;  
            chosen = *(int *)( listBase
                       + 4 * ( (int)( listCount
                                      * ( (unsigned int)com_randSeed_m >> 17 ) ) >> 15 ) );
          }
          else
          {
            chosen = 0;                                       
          }
          chainAxis[0] = *(int *)&results.normal[0];          
          chainAxis[1] = *(int *)&results.normal[1];          
          chainAxis[2] = *(int *)&results.normal[2];          
          MakeNormalVectors( results.normal,
                             (float *)&chainAxis[3],
                             (float *)&chainAxis[6] );        
          CFxScheduler__PlayEffect_id_axis( (unsigned int *)selfAddr, chosen,
                                            spawnOrigin, chainAxis, 0 ); 
        }
      }
      else                                                    
      {
        if ( ( flags & 0x200 ) != 0 )                         
        {
          
          if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMax )) )       
            spawnOrigin[0] = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin ));
          else
            spawnOrigin[0] = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin )),
                                                          *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMax )) );
          if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMax )) )      
            spawnOrigin[1] = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin ));
          else
            spawnOrigin[1] = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin )),
                                                          *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMax )) );
          if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMax )) )     
            spawnOrigin[2] = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin ));
          else
            spawnOrigin[2] = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin )),
                                                          *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMax )) );
        }
        else                                                  
        {
          float ofsX, ofsY, ofsZ;
          if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMax )) )     
            ofsZ = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin ));
          else
            ofsZ = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMin )),
                                                *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Z.mMax )) );
          if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMax )) )      
            ofsY = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin ));
          else
            ofsY = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMin )),
                                                *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2Y.mMax )) );
          if ( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin )) == *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMax )) )       
            ofsX = *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin ));
          else
            ofsX = (float)Com_RandFloatRange_m( *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMin )),
                                                *(float *)(tmplCopy + FX_TMPL_OFS( mOrigin2X.mMax )) );
          spawnOrigin[0] = ofsY * axis[3] + ofsZ * axis[6] + ofsX * axis[0]; 
          spawnOrigin[1] = ofsY * axis[4] + ofsZ * axis[7] + ofsX * axis[1]; 
          spawnOrigin[2] = ofsZ * axis[8] + ofsX * axis[2] + ofsY * axis[5]; 
        }
        
        spawnOrigin[0] = spawnOrigin[0] + origin[0];          
        spawnOrigin[1] = spawnOrigin[1] + origin[1];          
        spawnOrigin[2] = spawnOrigin[2] + origin[2];          
      }
    }
  }

  if ( *(int *)(tmpl + FX_TMPL_OFS( mType )) != 6                             
    && *(int *)(tmpl + FX_TMPL_OFS( mType )) != 10
    && *(int *)(tmpl + FX_TMPL_OFS( mType )) != 12 )                          
  {
    if ( ( *(int *)(tmpl + FX_TMPL_OFS( mSpawnFlags )) & 0x4000 ) != 0 )            
    {
      *(int *)&scratch = rand();                                 
      frac = (float)( *(int *)&scratch / 32768.0 );              
      rng3[0] = (float)( ( *(float *)(tmpl + FX_TMPL_OFS( mRedStart.mMax )) - *(float *)(tmpl + FX_TMPL_OFS( mRedStart.mMin )) )
                         * frac + *(float *)(tmpl + FX_TMPL_OFS( mRedStart.mMin )) ); 
      rng3[1] = (float)( ( *(float *)(tmpl + FX_TMPL_OFS( mGreenStart.mMax )) - *(float *)(tmpl + FX_TMPL_OFS( mGreenStart.mMin )) )
                         * frac + *(float *)(tmpl + FX_TMPL_OFS( mGreenStart.mMin )) ); 
      rng3[2] = (float)( ( *(float *)(tmpl + FX_TMPL_OFS( mBlueStart.mMax )) - *(float *)(tmpl + FX_TMPL_OFS( mBlueStart.mMin )) )
                         * frac + *(float *)(tmpl + FX_TMPL_OFS( mBlueStart.mMin )) ); 
      tmp3[0] = (float)( ( *(float *)(tmpl + FX_TMPL_OFS( mRedEnd.mMax )) - *(float *)(tmpl + FX_TMPL_OFS( mRedEnd.mMin )) )
                         * frac + *(float *)(tmpl + FX_TMPL_OFS( mRedEnd.mMin )) ); 
      tmp3[1] = (float)( ( *(float *)(tmpl + FX_TMPL_OFS( mGreenEnd.mMax )) - *(float *)(tmpl + FX_TMPL_OFS( mGreenEnd.mMin )) )
                         * frac + *(float *)(tmpl + FX_TMPL_OFS( mGreenEnd.mMin )) ); 
      tmp3[2] = (float)( ( *(float *)(tmpl + FX_TMPL_OFS( mBlueEnd.mMax )) - *(float *)(tmpl + FX_TMPL_OFS( mBlueEnd.mMin )) )
                         * frac + *(float *)(tmpl + FX_TMPL_OFS( mBlueEnd.mMin )) ); 
    }
    else
    {
      if ( *(float *)(tmpl + FX_TMPL_OFS( mRedStart.mMin )) != *(float *)(tmpl + FX_TMPL_OFS( mRedStart.mMax )) )   
        *(float *)&rgbComponent = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRedStart.mMin )),
                                              *(float *)(tmpl + FX_TMPL_OFS( mRedStart.mMax )) ); 
      else
        rgbComponent = *(int *)(tmpl + FX_TMPL_OFS( mRedStart.mMin ));
      rng3[0] = *(float *)&rgbComponent;                                

      if ( *(float *)(tmpl + FX_TMPL_OFS( mGreenStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mGreenStart.mMax )) )   
        rgbComponent = *(int *)(tmpl + FX_TMPL_OFS( mGreenStart.mMin ));                          
      else
        *(float *)&rgbComponent = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mGreenStart.mMin )),
                                              *(float *)(tmpl + FX_TMPL_OFS( mGreenStart.mMax )) ); 
      rng3[1] = *(float *)&rgbComponent;                                

      if ( *(float *)(tmpl + FX_TMPL_OFS( mBlueStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mBlueStart.mMax )) )   
        rgbComponent = *(int *)(tmpl + FX_TMPL_OFS( mBlueStart.mMin ));                          
      else
        *(float *)&rgbComponent = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mBlueStart.mMin )),
                                              *(float *)(tmpl + FX_TMPL_OFS( mBlueStart.mMax )) ); 
      rng3[2] = *(float *)&rgbComponent;                                

      if ( *(float *)(tmpl + FX_TMPL_OFS( mRedEnd.mMin )) != *(float *)(tmpl + FX_TMPL_OFS( mRedEnd.mMax )) )   
        *(float *)&rgbComponent = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRedEnd.mMin )),
                                              *(float *)(tmpl + FX_TMPL_OFS( mRedEnd.mMax )) ); 
      else
        rgbComponent = *(int *)(tmpl + FX_TMPL_OFS( mRedEnd.mMin ));
      tmp3[0] = *(float *)&rgbComponent;                                

      if ( *(float *)(tmpl + FX_TMPL_OFS( mGreenEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mGreenEnd.mMax )) )   
        rgbComponent = *(int *)(tmpl + FX_TMPL_OFS( mGreenEnd.mMin ));                          
      else
        *(float *)&rgbComponent = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mGreenEnd.mMin )),
                                              *(float *)(tmpl + FX_TMPL_OFS( mGreenEnd.mMax )) ); 
      tmp3[1] = *(float *)&rgbComponent;                                

      if ( *(float *)(tmpl + FX_TMPL_OFS( mBlueEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mBlueEnd.mMax )) )   
        rgbComponent = *(int *)(tmpl + FX_TMPL_OFS( mBlueEnd.mMin ));                          
      else
        *(float *)&rgbComponent = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mBlueEnd.mMin )),
                                              *(float *)(tmpl + FX_TMPL_OFS( mBlueEnd.mMax )) ); 
      tmp3[2] = *(float *)&rgbComponent;                                
    }
  }

  if ( ( *(int *)(tmpl + FX_TMPL_OFS( mFlags )) & 0x200000 ) != 0
       && bolt && *bolt >= 0 )                                
  {
    CFxBoltFrame__Acquire( (int **)&scratch, bolt );
    acquired = (int *)scratch;               
    if ( acquired )                                                 
    {
      heldFrame = acquired;
      ++*acquired;                                                  
      boltFrame = (char *)acquired;                                 
    }
    else
    {
      heldFrame = (int *)boltFrame;                              
    }
    if ( scratch )                                               
      CFxBoltFrame__Release( (char *)scratch );                  
    if ( !heldFrame )                                            
      return;                                                 
    if ( !CFxBoltFrame__GetOrientation( (int)heldFrame ) )                              
    {
      CFxBoltFrame__Release( (char *)heldFrame );                
      return;
    }
  }

  switch ( *(int *)(tmpl + FX_TMPL_OFS( mType )) )
  {
    case 1:
      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) )    
        life = *(int *)(tmpl + FX_TMPL_OFS( mLife.mMin ));                              
      else
        *(float *)&life = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) );   

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMax )) )  
        elasticity = *(int *)(tmpl + FX_TMPL_OFS( mElasticity.mMin ));                             
      else
        *(float *)&elasticity = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMax )) );  

      if ( *(float *)(tmpl + FX_TMPL_OFS( mRotationDelta.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mRotationDelta.mMax )) )  
        rotationDelta = *(int *)(tmpl + FX_TMPL_OFS( mRotationDelta.mMin ));                             
      else
        *(float *)&rotationDelta = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRotationDelta.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mRotationDelta.mMax )) );  
      if ( *(float *)(tmpl + FX_TMPL_OFS( mRotation.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mRotation.mMax )) )  
        rotation = *(int *)(tmpl + FX_TMPL_OFS( mRotation.mMin ));                             
      else
        *(float *)&rotation = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRotation.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mRotation.mMax )) );  

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) )  
        rgbParm = *(int *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin ));                             
      else
        *(float *)&rgbParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) );  

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) )  
        alphaParm = *(int *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin ));                           
      else
        *(float *)&alphaParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) )  
        alphaEnd = *(int *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin ));                           
      else
        *(float *)&alphaEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) )  
        alphaStart = *(int *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin ));                           
      else
        *(float *)&alphaStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) );

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSize2Parm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSize2Parm.mMax )) )  
        size2Parm = *(int *)(tmpl + FX_TMPL_OFS( mSize2Parm.mMin ));                           
      else
        *(float *)&size2Parm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSize2Parm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSize2Parm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSize2End.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSize2End.mMax )) )  
        size2End = *(int *)(tmpl + FX_TMPL_OFS( mSize2End.mMin ));                           
      else
        *(float *)&size2End = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSize2End.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSize2End.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSize2Start.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSize2Start.mMax )) )  
        size2Start = *(int *)(tmpl + FX_TMPL_OFS( mSize2Start.mMin ));                           
      else
        *(float *)&size2Start = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSize2Start.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSize2Start.mMax )) );

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) )  
        sizeParm = *(int *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin ));                           
      else
        *(float *)&sizeParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) )  
        sizeEnd = *(int *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin ));                           
      else
        *(float *)&sizeEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) )  
        sizeStart = *(int *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin ));                           
      else
        *(float *)&sizeStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) );

      flags  = *(int *)(tmpl + FX_TMPL_OFS( mFlags ));                              
      shader = CMediaHandles__GetHandle( tmpl + 0x68 );                          
      killTime  = (int)*(float *)&life; 
      impactFxId = CMediaHandles__GetHandle( tmpl + 0x78 );                          
      deathFxId = CMediaHandles__GetHandle( tmpl + 0x88 );                          

      FX_AddParticle( &boltFrame,                                  
                      (int)start,
                      velocity,
                      accel,
                      *(char *)(tmpl + FX_TMPL_OFS( mNonUniformScale )),
                      sizeStart, sizeEnd, *(float *)&sizeParm,
                      size2Start, size2End, *(float *)&size2Parm,
                      alphaStart, alphaEnd, *(float *)&alphaParm,
                      (unsigned int *)rng3, (unsigned int *)tmp3, *(float *)&rgbParm,
                      rotation, rotationDelta,
                      (unsigned int *)(tmpl + FX_TMPL_OFS( mMin )),
                      (unsigned int *)(tmpl + FX_TMPL_OFS( mMax )),
                      elasticity,
                      deathFxId, impactFxId, killTime, shader, flags );
      goto LABEL_501;                                              

    case 2:
      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) )    
        life = *(int *)(tmpl + FX_TMPL_OFS( mLife.mMin ));                              
      else
        *(float *)&life = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) );   

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) )  
        rgbParm = *(int *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin ));                             
      else
        *(float *)&rgbParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) );  

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) )  
        alphaParm = *(int *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin ));                           
      else
        *(float *)&alphaParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) )  
        alphaEnd = *(int *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin ));                           
      else
        *(float *)&alphaEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) )  
        alphaStart = *(int *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin ));                           
      else
        *(float *)&alphaStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) );

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) )  
        sizeParm = *(int *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin ));                           
      else
        *(float *)&sizeParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) )  
        sizeEnd = *(int *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin ));                           
      else
        *(float *)&sizeEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) )  
        sizeStart = *(int *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin ));                           
      else
        *(float *)&sizeStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) );

      flags  = *(int *)(tmpl + FX_TMPL_OFS( mFlags ));                              
      shader = CMediaHandles__GetHandle( tmpl + 0x68 );                          
      killTime  = (int)*(float *)&life; 

      FX_AddLine( &boltFrame,                                      
                  (int)start,
                  FxTailLineVectorArgument((float *)(spawnOrigin)),
                  sizeStart, sizeEnd, *(float *)&sizeParm,
                  alphaStart, alphaEnd, *(float *)&alphaParm,
                  (unsigned int *)rng3, (unsigned int *)tmp3,
                  *(float *)&rgbParm,
                  killTime, shader, flags );
      goto LABEL_501;                                              

    case 3:
      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) )   
        life = *(int *)(tmpl + FX_TMPL_OFS( mLife.mMin ));                             
      else
        *(float *)&life = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) );  

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMax )) ) 
        elasticity = *(int *)(tmpl + FX_TMPL_OFS( mElasticity.mMin ));                            
      else
        *(float *)&elasticity = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMax )) );  

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) ) 
        rgbParm = *(int *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin ));                            
      else
        *(float *)&rgbParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) );  

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) ) 
        alphaParm = *(int *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin ));
      else
        *(float *)&alphaParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) ) 
        alphaEnd = *(int *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin ));
      else
        *(float *)&alphaEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) ) 
        alphaStart = *(int *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin ));
      else
        *(float *)&alphaStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) );

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mLengthParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLengthParm.mMax )) ) 
        lengthParm = *(int *)(tmpl + FX_TMPL_OFS( mLengthParm.mMin ));
      else
        *(float *)&lengthParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLengthParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mLengthParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mLengthEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLengthEnd.mMax )) ) 
        lengthEnd = *(int *)(tmpl + FX_TMPL_OFS( mLengthEnd.mMin ));
      else
        *(float *)&lengthEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLengthEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mLengthEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mLengthStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLengthStart.mMax )) ) 
        lengthStart = *(int *)(tmpl + FX_TMPL_OFS( mLengthStart.mMin ));
      else
        *(float *)&lengthStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLengthStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mLengthStart.mMax )) );

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) ) 
        sizeParm = *(int *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin ));
      else
        *(float *)&sizeParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) ) 
        sizeEnd = *(int *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin ));
      else
        *(float *)&sizeEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) ) 
        sizeStart = *(int *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin ));
      else
        *(float *)&sizeStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) );

      flags  = *(int *)(tmpl + FX_TMPL_OFS( mFlags ));                             
      shader = CMediaHandles__GetHandle( tmpl + 0x68 );                         

      killTime  = (int)*(float *)&life;                              
      impactFxId = CMediaHandles__GetHandle( tmpl + 0x78 );                         
      deathFxId = CMediaHandles__GetHandle( tmpl + 0x88 );                         

      FX_AddTail( &boltFrame,                                     
                  (int)start,
                  FxTailMotionVectorArgument((float *)(velocity)),
                  FxTailMotionVectorArgument((float *)(accel)),
                  sizeStart, sizeEnd, *(float *)&sizeParm,
                  lengthStart, lengthEnd, *(float *)&lengthParm,
                  alphaStart, alphaEnd, *(float *)&alphaParm,
                  (unsigned int *)rng3, (unsigned int *)tmp3, *(float *)&rgbParm,
                  (unsigned int *)(tmpl + FX_TMPL_OFS( mMin )),
                  (unsigned int *)(tmpl + FX_TMPL_OFS( mMax )),
                  elasticity,
                  deathFxId, impactFxId, killTime, shader, flags );
      goto LABEL_501;                                             

    case 4:
      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) )    
        life = *(int *)(tmpl + FX_TMPL_OFS( mLife.mMin ));                              
      else
        *(float *)&life = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) );   

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) )  
        rgbParm = *(int *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin ));
      else
        *(float *)&rgbParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) );

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) )  
        alphaParm = *(int *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin ));
      else
        *(float *)&alphaParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) )  
        alphaEnd = *(int *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin ));
      else
        *(float *)&alphaEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) )  
        alphaStart = *(int *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin ));
      else
        *(float *)&alphaStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) );

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mLengthParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLengthParm.mMax )) )  
        lengthParm = *(int *)(tmpl + FX_TMPL_OFS( mLengthParm.mMin ));
      else
        *(float *)&lengthParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLengthParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mLengthParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mLengthEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLengthEnd.mMax )) )  
        lengthEnd = *(int *)(tmpl + FX_TMPL_OFS( mLengthEnd.mMin ));
      else
        *(float *)&lengthEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLengthEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mLengthEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mLengthStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLengthStart.mMax )) )  
        lengthStart = *(int *)(tmpl + FX_TMPL_OFS( mLengthStart.mMin ));
      else
        *(float *)&lengthStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLengthStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mLengthStart.mMax )) );

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSize2Parm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSize2Parm.mMax )) )  
        size2Parm = *(int *)(tmpl + FX_TMPL_OFS( mSize2Parm.mMin ));
      else
        *(float *)&size2Parm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSize2Parm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSize2Parm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSize2End.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSize2End.mMax )) )  
        size2End = *(int *)(tmpl + FX_TMPL_OFS( mSize2End.mMin ));
      else
        *(float *)&size2End = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSize2End.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSize2End.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSize2Start.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSize2Start.mMax )) )  
        size2Start = *(int *)(tmpl + FX_TMPL_OFS( mSize2Start.mMin ));
      else
        *(float *)&size2Start = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSize2Start.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSize2Start.mMax )) );

      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) )  
        sizeParm = *(int *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin ));
      else
        *(float *)&sizeParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) )  
        sizeEnd = *(int *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin ));
      else
        *(float *)&sizeEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) )  
        sizeStart = *(int *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin ));
      else
        *(float *)&sizeStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) );  

      flags  = *(int *)(tmpl + FX_TMPL_OFS( mFlags ));                              
      shader = CMediaHandles__GetHandle( tmpl + 0x68 );                          
      killTime  = (int)*(float *)&life; 

      FX_AddCylinder( &boltFrame,
                      (int)start,
                      &axis[0],
                      sizeStart, sizeEnd, *(float *)&sizeParm,
                      size2Start, size2End, *(float *)&size2Parm,
                      lengthStart, lengthEnd, *(float *)&lengthParm,
                      alphaStart, alphaEnd, *(float *)&alphaParm,
                      (unsigned int *)rng3, (unsigned int *)tmp3, *(float *)&rgbParm,
                      killTime, shader, flags );
      goto LABEL_501;                                              

    case 5:

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAngle1.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAngle1.mMax )) )  
        angleX = *(int *)(tmpl + FX_TMPL_OFS( mAngle1.mMin ));                           
      else
        *(float *)&angleX = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAngle1.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAngle1.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAngle2.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAngle2.mMax )) )  
        angleY = *(int *)(tmpl + FX_TMPL_OFS( mAngle2.mMin ));                           
      else
        *(float *)&angleY = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAngle2.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAngle2.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAngle3.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAngle3.mMax )) )  
        angleZ = *(int *)(tmpl + FX_TMPL_OFS( mAngle3.mMin ));                           
      else
        *(float *)&angleZ = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAngle3.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAngle3.mMax )) );

      
      vectoangles( &axis[0], endp );                               
      sum3[0] = *(float *)&angleX + endp[0];                       
      sum3[1] = *(float *)&angleY + endp[1];                       
      sum3[2] = *(float *)&angleZ + endp[2];                       

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAngle1Delta.mMin )) != *(float *)(tmpl + FX_TMPL_OFS( mAngle1Delta.mMax )) )  
        *(float *)&angleDeltaComponent = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAngle1Delta.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mAngle1Delta.mMax )) );  
      else
        angleDeltaComponent = *(int *)(tmpl + FX_TMPL_OFS( mAngle1Delta.mMin ));
      spawnOrigin[0] = *(float *)&angleDeltaComponent;                            

      if ( *(float *)(tmpl + FX_TMPL_OFS( mAngle2Delta.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAngle2Delta.mMax )) )  
        angleDeltaComponent = *(int *)(tmpl + FX_TMPL_OFS( mAngle2Delta.mMin ));                             
      else
        *(float *)&angleDeltaComponent = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAngle2Delta.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mAngle2Delta.mMax )) );  
      spawnOrigin[1] = *(float *)&angleDeltaComponent;                            

      if ( *(float *)(tmpl + FX_TMPL_OFS( mAngle3Delta.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAngle3Delta.mMax )) )  
        angleDeltaComponent = *(int *)(tmpl + FX_TMPL_OFS( mAngle3Delta.mMin ));                             
      else
        *(float *)&angleDeltaComponent = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAngle3Delta.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mAngle3Delta.mMax )) );  
      spawnOrigin[2] = *(float *)&angleDeltaComponent;                            

      shader = CMediaHandles__GetHandle( tmpl + 0x68 );                          

      if ( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) )    
        life = *(int *)(tmpl + FX_TMPL_OFS( mLife.mMin ));                              
      else
        *(float *)&life = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) );   
      if ( *(float *)(tmpl + FX_TMPL_OFS( mVariance.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mVariance.mMax )) )  
        variance = *(int *)(tmpl + FX_TMPL_OFS( mVariance.mMin ));                         
      else
        *(float *)&variance = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mVariance.mMin )),
                                                    *(float *)(tmpl + FX_TMPL_OFS( mVariance.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mDensity.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mDensity.mMax )) )  
        density = *(int *)(tmpl + FX_TMPL_OFS( mDensity.mMin ));                          
      else
        *(float *)&density = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mDensity.mMin )),
                                                   *(float *)(tmpl + FX_TMPL_OFS( mDensity.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMax )) )  
        elasticity = *(int *)(tmpl + FX_TMPL_OFS( mElasticity.mMin ));                             
      else
        *(float *)&elasticity = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMax )) );  
      if ( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) )  
        rgbParm = *(int *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin ));                             
      else
        *(float *)&rgbParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) );  

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) )  
        alphaParm = *(int *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin ));                           
      else
        *(float *)&alphaParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) )  
        alphaEnd = *(int *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin ));                           
      else
        *(float *)&alphaEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) )  
        alphaStart = *(int *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin ));                           
      else
        *(float *)&alphaStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) );

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) )  
        sizeParm = *(int *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin ));                           
      else
        *(float *)&sizeParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) )  
        sizeEnd = *(int *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin ));                           
      else
        *(float *)&sizeEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) )  
        sizeStart = *(int *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin ));                           
      else
        *(float *)&sizeStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) );

      flags     = *(int *)(tmpl + FX_TMPL_OFS( mFlags ));                           
      killTime     = (int)*(float *)&life; 
      emitterFxId    = CMediaHandles__GetHandle( tmpl + 0x98 );                       
      impactFxId    = CMediaHandles__GetHandle( tmpl + 0x78 );                       
      deathFxId    = CMediaHandles__GetHandle( tmpl + 0x88 );                       

      FX_AddEmitter( (int)start,                                   
                     &boltFrame,
                     velocity,
                     accel,
                     sizeStart, sizeEnd, *(float *)&sizeParm,
                     alphaStart, alphaEnd, *(float *)&alphaParm,
                     (unsigned int *)rng3, (unsigned int *)tmp3, *(float *)&rgbParm,
                     (unsigned int *)sum3,
                     (unsigned int *)spawnOrigin,
                     (unsigned int *)(tmpl + FX_TMPL_OFS( mMin )),
                     (unsigned int *)(tmpl + FX_TMPL_OFS( mMax )),
                     elasticity,
                     deathFxId, impactFxId, emitterFxId,
                     density, variance,
                     killTime, shader, flags );
      goto LABEL_501;                                              

    case 9:
      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) )    
        life = *(int *)(tmpl + FX_TMPL_OFS( mLife.mMin ));                              
      else
        *(float *)&life = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mLife.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mLife.mMax )) );   

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMax )) )  
        elasticity = *(int *)(tmpl + FX_TMPL_OFS( mElasticity.mMin ));                             
      else
        *(float *)&elasticity = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mElasticity.mMax )) );  

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) )  
        rgbParm = *(int *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin ));                             
      else
        *(float *)&rgbParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMin )),
                                                *(float *)(tmpl + FX_TMPL_OFS( mRGBParm.mMax )) );  

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) )  
        alphaParm = *(int *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin ));                           
      else
        *(float *)&alphaParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) )  
        alphaEnd = *(int *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin ));                           
      else
        *(float *)&alphaEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) )  
        alphaStart = *(int *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin ));                           
      else
        *(float *)&alphaStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mAlphaStart.mMax )) );

      
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) )  
        sizeParm = *(int *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin ));                           
      else
        *(float *)&sizeParm = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeParm.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) )  
        sizeEnd = *(int *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin ));                           
      else
        *(float *)&sizeEnd = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeEnd.mMax )) );
      if ( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )) == *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) )  
        sizeStart = *(int *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin ));                           
      else
        *(float *)&sizeStart = Com_RandFloatRange_m( *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMin )),
                                                  *(float *)(tmpl + FX_TMPL_OFS( mSizeStart.mMax )) );

      flags  = *(int *)(tmpl + FX_TMPL_OFS( mFlags ));                              
      shader = CMediaHandles__GetHandle( tmpl + 0x68 );                          
      killTime  = (int)*(float *)&life; 

      FX_AddElectricity( &boltFrame,                               
                         (int)start,
                         spawnOrigin,
                         sizeStart, sizeEnd, *(float *)&sizeParm,
                         alphaStart, alphaEnd, *(float *)&alphaParm,
                         (unsigned int *)rng3, (unsigned int *)tmp3, *(float *)&rgbParm,
                         elasticity,
                         killTime, shader, flags );
      goto LABEL_501;                                              

    case 7:
        if ( *(float *)(tpl + FX_TMPL_OFS( mRotation.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mRotation.mMax )) )
            rotation = *(int *)(tpl + FX_TMPL_OFS( mRotation.mMin ));
        else
        {
            *(float *)&rangeBits = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mRotation.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mRotation.mMax )) );
            rotation = rangeBits;
        }
        if ( *(float *)(tpl + FX_TMPL_OFS( mAlphaStart.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mAlphaStart.mMax )) )
            oAlphaStart = *(int *)(tpl + FX_TMPL_OFS( mAlphaStart.mMin ));
        else
        {
            *(float *)&rangeBits = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mAlphaStart.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mAlphaStart.mMax )) );
            oAlphaStart = rangeBits;
        }
        if ( *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMax )) )
            oSizeStart = *(int *)(tpl + FX_TMPL_OFS( mSizeStart.mMin ));
        else
        {
            *(float *)&rangeBits = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMax )) );
            oSizeStart = rangeBits;
        }
        if ( *(float *)(tpl + FX_TMPL_OFS( mLife.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mLife.mMax )) )
            life = *(int *)(tpl + FX_TMPL_OFS( mLife.mMin ));
        else
            *(float *)&life = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mLife.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mLife.mMax )) );
        decalShader = CMediaHandles__GetHandle( (int)(tpl + 0x68) );
        VM_Call( cgvm, 14,
                 decalShader,
                 start,
                 axis,
                 rotation,
                 *(int *)&rng3[0], *(int *)&rng3[1],
                 *(int *)&rng3[2],
                 oAlphaStart,
                 1,
                 oSizeStart,
                 0,
                 (int)*(float *)&life );
        goto LABEL_501;
    case 8:
        if ( *(float *)(tpl + FX_TMPL_OFS( mLife.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mLife.mMax )) )
            life = *(int *)(tpl + FX_TMPL_OFS( mLife.mMin ));
        else
            *(float *)&life = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mLife.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mLife.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mElasticity.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mElasticity.mMax )) )
            elasticity = *(int *)(tpl + FX_TMPL_OFS( mElasticity.mMin ));
        else
            *(float *)&elasticity = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mElasticity.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mElasticity.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mRotationDelta.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mRotationDelta.mMax )) )
            rotationDelta = *(int *)(tpl + FX_TMPL_OFS( mRotationDelta.mMin ));
        else
            *(float *)&rotationDelta = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mRotationDelta.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mRotationDelta.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mRotation.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mRotation.mMax )) )
            rotation = *(int *)(tpl + FX_TMPL_OFS( mRotation.mMin ));
        else
            *(float *)&rotation = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mRotation.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mRotation.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMax )) )
            rgbParm = *(int *)(tpl + FX_TMPL_OFS( mRGBParm.mMin ));
        else
            *(float *)&rgbParm = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mAlphaParm.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mAlphaParm.mMax )) )
            oAlphaParm = *(int *)(tpl + FX_TMPL_OFS( mAlphaParm.mMin ));
        else
            *(float *)&oAlphaParm = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mAlphaParm.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mAlphaParm.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mAlphaEnd.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mAlphaEnd.mMax )) )
            oAlphaEnd = *(int *)(tpl + FX_TMPL_OFS( mAlphaEnd.mMin ));
        else
            *(float *)&oAlphaEnd = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mAlphaEnd.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mAlphaEnd.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mAlphaStart.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mAlphaStart.mMax )) )
            oAlphaStart = *(int *)(tpl + FX_TMPL_OFS( mAlphaStart.mMin ));
        else
            *(float *)&oAlphaStart = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mAlphaStart.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mAlphaStart.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mSize2Parm.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mSize2Parm.mMax )) )
            oSize2Parm = *(int *)(tpl + FX_TMPL_OFS( mSize2Parm.mMin ));
        else
            *(float *)&oSize2Parm = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mSize2Parm.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mSize2Parm.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mSize2End.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mSize2End.mMax )) )
            oSize2End = *(int *)(tpl + FX_TMPL_OFS( mSize2End.mMin ));
        else
            *(float *)&oSize2End = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mSize2End.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mSize2End.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mSize2Start.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mSize2Start.mMax )) )
            oSize2Start = *(int *)(tpl + FX_TMPL_OFS( mSize2Start.mMin ));
        else
            *(float *)&oSize2Start = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mSize2Start.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mSize2Start.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mSizeParm.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mSizeParm.mMax )) )
            oSizeParm = *(int *)(tpl + FX_TMPL_OFS( mSizeParm.mMin ));
        else
        {
            *(float *)&rangeBits = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeParm.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeParm.mMax )) );
            oSizeParm = rangeBits;
        }
        if ( *(float *)(tpl + FX_TMPL_OFS( mSizeEnd.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mSizeEnd.mMax )) )
            oSizeEnd = *(int *)(tpl + FX_TMPL_OFS( mSizeEnd.mMin ));
        else
        {
            *(float *)&rangeBits = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeEnd.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeEnd.mMax )) );
            oSizeEnd = rangeBits;
        }
        if ( *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMax )) )
            oSizeStart = *(int *)(tpl + FX_TMPL_OFS( mSizeStart.mMin ));
        else
        {
            *(float *)&rangeBits = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMax )) );
            oSizeStart = rangeBits;
        }
        FX_AddOrientedParticle(
            &boltFrame,
            (int)axis,
            (int)start,
            velocity,
            accel,
            (char)*(unsigned char *)(tpl + FX_TMPL_OFS( mNonUniformScale )),
            oSizeStart, oSizeEnd, *(float *)&oSizeParm,
            oSize2Start, oSize2End, *(float *)&oSize2Parm,
            oAlphaStart, oAlphaEnd, *(float *)&oAlphaParm,
            (unsigned int *)rng3,
            (unsigned int *)tmp3,
            *(float *)&rgbParm,
            rotation, rotationDelta,
            (unsigned int *)(tpl + FX_TMPL_OFS( mMin )),
            (unsigned int *)(tpl + FX_TMPL_OFS( mMax )),
            elasticity,
            CMediaHandles__GetHandle( (int)(tpl + 0x88) ),
            CMediaHandles__GetHandle( (int)(tpl + 0x78) ),
            (int)*(float *)&life,
            CMediaHandles__GetHandle( (int)(tpl + 0x68) ),
            *(unsigned int *)(tpl + FX_TMPL_OFS( mFlags )) );
        goto LABEL_501;
    case 6:
        SFxHelper__PlaySound( CMediaHandles__GetHandle( (int)(tpl + 0x68) ),
                              (const void *)(int)&theFxHelper,
                              start,
                              1023 );
        goto LABEL_501;
    case 10:
        CFxScheduler__PlayEffect_id_axis(
            self,
            CMediaHandles__GetHandle( (int)(tpl + 0xA8) ),
            start,
            (int *)axis,
            boltFrame ? (int *)(boltFrame + 0x3C) : (int *)0 );
        goto LABEL_501;
    case 11:
        if ( *(float *)(tpl + FX_TMPL_OFS( mLife.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mLife.mMax )) )
            life = *(int *)(tpl + FX_TMPL_OFS( mLife.mMin ));
        else
            *(float *)&life = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mLife.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mLife.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMax )) )
            rgbParm = *(int *)(tpl + FX_TMPL_OFS( mRGBParm.mMin ));
        else
            *(float *)&rgbParm = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mSizeParm.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mSizeParm.mMax )) )
            oSizeParm = *(int *)(tpl + FX_TMPL_OFS( mSizeParm.mMin ));
        else
        {
            *(float *)&rangeBits = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeParm.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeParm.mMax )) );
            oSizeParm = rangeBits;
        }
        if ( *(float *)(tpl + FX_TMPL_OFS( mSizeEnd.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mSizeEnd.mMax )) )
            oSizeEnd = *(int *)(tpl + FX_TMPL_OFS( mSizeEnd.mMin ));
        else
        {
            *(float *)&rangeBits = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeEnd.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeEnd.mMax )) );
            oSizeEnd = rangeBits;
        }
        if ( *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMax )) )
            oSizeStart = *(int *)(tpl + FX_TMPL_OFS( mSizeStart.mMin ));
        else
        {
            *(float *)&rangeBits = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mSizeStart.mMax )) );
            oSizeStart = rangeBits;
        }
        FX_AddLight( &boltFrame,
                     start,
                     *(float *)&oSizeStart,
                     *(float *)&oSizeEnd,
                     *(float *)&oSizeParm,
                     (unsigned int *)rng3,
                     (unsigned int *)tmp3,
                     *(float *)&rgbParm,
                     (int)*(float *)&life,
                     *(int *)(tpl + FX_TMPL_OFS( mFlags )) );
        goto LABEL_501;
    case 12:
        if ( *(float *)(tpl + FX_TMPL_OFS( mLife.mMin )) != *(float *)(tpl + FX_TMPL_OFS( mLife.mMax )) )
            Com_RandFloatRange_m( *(float *)(tpl + FX_TMPL_OFS( mLife.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mLife.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mRadius.mMin )) != *(float *)(tpl + FX_TMPL_OFS( mRadius.mMax )) )
            Com_RandFloatRange_m( *(float *)(tpl + FX_TMPL_OFS( mRadius.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mRadius.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mElasticity.mMin )) != *(float *)(tpl + FX_TMPL_OFS( mElasticity.mMax )) )
            Com_RandFloatRange_m( *(float *)(tpl + FX_TMPL_OFS( mElasticity.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mElasticity.mMax )) );
        break;
    case 13:
        if ( *(float *)(tpl + FX_TMPL_OFS( mLife.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mLife.mMax )) )
            life = *(int *)(tpl + FX_TMPL_OFS( mLife.mMin ));
        else
            *(float *)&life = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mLife.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mLife.mMax )) );
        if ( *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMin )) == *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMax )) )
            rgbParm = *(int *)(tpl + FX_TMPL_OFS( mRGBParm.mMin ));
        else
        {
            *(float *)&rangeBits = (float)Com_RandFloatRange_m(
                                  *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMin )),
                                  *(float *)(tpl + FX_TMPL_OFS( mRGBParm.mMax )) );
            rgbParm = rangeBits;
        }
        FX_AddFlash(
            (unsigned int *)start,
            (unsigned int *)rng3,
            (unsigned int *)tmp3,
            *(float *)&rgbParm,
            (int)*(float *)&life,
            CMediaHandles__GetHandle( (int)(tpl + 0x68) ),
            *(int *)(tpl + FX_TMPL_OFS( mFlags )) );
        break;

    default:
      break;
  }

LABEL_501:
  tmplCopy = tmpl;                                                 

  if ( *(unsigned char *)(tmplCopy + 0) != 0 )                     
  {
    --*(int *)(tmplCopy + FX_TMPL_OFS( mRefCount ));                                      
    if ( *(int *)(tmpl + FX_TMPL_OFS( mRefCount )) <= 0 )                           
    {
      FX_TMPL( tmpl )->~CPrimitiveTemplate();
      FxPool_FreePrimitiveTemplate( (int *)(int)&fxPool_PrimitiveTemplate, (char *)tmpl );               
    }
  }

  if ( boltFrame )                                           
    CFxBoltFrame__Release( boltFrame );                      
}


/* ---- CFxScheduler__SaveState_m  0x004970E0 ----  [CONFIRMED] */
/*
 * Serialize (write mode) or restore (read mode) the FX scheduler's persistent
 * state: the effect-id remap table, the effect-name -> id map, and the live
 * scheduled-effect list.  `this` is the FxArchive; scheduler is the scheduler.
 */
void __stdcall CFxScheduler__SaveState_m(int thisObj, unsigned int *scheduler)
{
  FxArchive       *ar = (FxArchive *)thisObj;
  unsigned __int8 nameLen;          /* BYREF: name length byte (read and write) */
  __int16         index;            /* BYREF: remap-table slot */
  /* Retail gives the read count, the current scheduled effect and the write
   * pass's map iterator one 4-byte stack home (esp+14h), next to index; as
   * separate locals VC7 packs index with the write scratch instead. */
  union { int count; int *effect; int *node; } u;

  if ( ar->reading )
  {
    int             remaining;

    /* Rebuild the effect-id remap table from (int16 slot, name) pairs, ended
     * by a zero slot; each name is re-registered with the scheduler. */
    {
      char            effectName[256];  /* BYREF */

      CFxArchive__ReadData(2, (unsigned int *)ar, (byte *)&index);
      while ( (unsigned __int16)index )
      {
        CFxArchive__ReadData(1, (unsigned int *)ar, &nameLen);
        if ( nameLen )
        {
          CFxArchive__ReadData(nameLen, (unsigned int *)ar, (byte *)effectName);
          effectName[nameLen] = 0;
          ar->table[index] = CFxScheduler__RegisterEffect(scheduler, effectName, 0);
        }
        CFxArchive__ReadData(2, (unsigned int *)ar, (byte *)&index);
      }
    }

    /* Then a 4-byte count followed by that many serialized scheduled effects
     * (retail tests the count before copying it to the loop counter). */
    CFxArchive__ReadData(4, (unsigned int *)ar, (byte *)&u.count);
    if ( u.count )
    {
      remaining = u.count;
      do
      {
        int     effectId;
        int     primIndex;

        u.effect = FxMem_AllocScheduledEffect(&fxPool_ScheduledEffect, FX_SCHEDULED_EFFECT_SIZE);
        CFxArchive__ArchiveScheduledEffect_m(thisObj, (unsigned __int16 *)u.effect);
        effectId = FX_SCHED(u.effect)->mEffectID;

        /* Re-link the effect only if its owning effect template still exists
         * and still declares the primitive the effect targets; else drop it. */
        if ( effectId > 0
          && ( (SEffectTemplate *)scheduler )[effectId].mInUse
          && (primIndex = FX_SCHED(u.effect)->mPrimitiveIndex, primIndex >= 0)
          && primIndex < ( (SEffectTemplate *)scheduler )[effectId].mPrimitiveCount
          && ( (SEffectTemplate *)scheduler )[effectId].mPrimitives[primIndex] )
        {
          stl_fxScheduledList_pushBack_m((unsigned int *)&u.effect,
                              (int)((char *)scheduler + FX_SCHEDULER_SCHEDULED_LIST_OFFSET));
        }
        else
        {
          FxPool_FreeScheduledEffect(&fxPool_ScheduledEffect, (char *)u.effect);
        }
        --remaining;
      }
      while ( remaining );
    }
  }
  else
  {
    int             value;   /* BYREF: write scratch */
    const char     *name;
    int             len;
    int            *sched;
    int             id;

    /* Write the effect-name -> id map (std::map<string,int>) in key order:
     * each entry writes its mapped id (int16), name length (byte) and name.
     * Retail fetches the mapped id before strlen and the length check.
     * Retail takes the map and scheduled-list heads from the global
     * theFxScheduler by absolute address (0x0140C9A4 / 0x0140C9B0), not
     * through scheduler; both callers pass theFxScheduler. */
    for ( u.node = *(int **)fxSchedulerEffectIdsHead;
          u.node != (int *)fxSchedulerEffectIdsHead;
          stl_fxEffectIdMap_iterInc_m(&u.node) )                 /* in-order successor */
    {
      name = (const char *)FXS_PTR( FXN_KEY( u.node ) );
      id   = FXN_MAPPED( u.node );
      len  = strlen( name );
      if ( len >= 256 )
        Com_Error(ERR_DROP, fx_errSaveEffectNameTooLong);

      value = id;
      CFxArchive__WriteData((int *)ar, (byte *)&value, 2);
      nameLen = (unsigned __int8)len;
      CFxArchive__WriteData((int *)ar, &nameLen, 1);
      if ( len )
        CFxArchive__WriteData((int *)ar, (byte *)name, len);
    }
    value = 0;                                       /* zero slot terminates the list */
    CFxArchive__WriteData((int *)ar, (byte *)&value, 2);

    value = *(int *)((char *)scheduler + FX_SCHEDULER_SCHEDULED_SIZE_OFFSET);
    CFxArchive__WriteData((int *)ar, (byte *)&value, 4);

    /* Then walk the live scheduled-effect list and serialize each entry. */
    if ( fxSchedulerScheduledEffectsHead )
    {
      for ( sched = *(int **)fxSchedulerScheduledEffectsHead;
            sched != (int *)fxSchedulerScheduledEffectsHead;
            sched = (int *)*sched )
        CFxArchive__ArchiveScheduledEffect_m(thisObj, (unsigned __int16 *)sched[2]);
    }
  }
}

/* ---- CFxArchive__ArchiveScheduledEffect_m  0x00497320 ----  IMPLEMENTED (retail) */
/*
 * Archive one scheduled effect (FX_SCHEDULED_EFFECT_SIZE bytes) for
 * CFxScheduler__SaveState_m, in whichever direction the archive runs:
 *   +0x00  effectId        a 16-bit slot; on read it is remapped through
 *                          ar->table and stored as a full dword
 *   +0x04  primitive index (4)     +0x08  scheduled time (4)
 *   +0x0C  bolt info (8)           +0x14  origin (12)
 *   +0x20, +0x2C, +0x38  axis rows (12 each)
 * Retail is __usercall (archive@eax, effect@edi) and inlines the read/write
 * choice per field (cf. CFxArchive__Value_bytes_m).
 */
void __cdecl CFxArchive__ArchiveScheduledEffect_m( int archive, unsigned __int16 *effect )
{
  unsigned char *rec = (unsigned char *)effect;

  CFxArchive__ArchiveEffectID( archive, (unsigned int *)rec );
  FX_AR_FIELD( archive, rec, 0x04,  4 );
  FX_AR_FIELD( archive, rec, 0x08,  4 );
  FX_AR_FIELD( archive, rec, 0x0C,  8 );
  FX_AR_FIELD( archive, rec, 0x14, 12 );
  FX_AR_FIELD( archive, rec, 0x20, 12 );
  FX_AR_FIELD( archive, rec, 0x2C, 12 );
  FX_AR_FIELD( archive, rec, 0x38, 12 );
}

}   /* extern "C" */

/* ---- stl_fxString_ctor_m  0x00497440 ----  VERIFIED */
/* basic_string(): _Tidy(): empty, 15-char SSO capacity. */
inline FxStdString::basic_string()
{
  capacity = 15;   /* _Tidy(): _Myres = 15; _Eos(0) = _Myptr()[_Mysize = 0] = char() */
  ( 16 <= capacity ? bx.ptr : bx.buf )[size = 0] = 0;
}

/* ---- stl_fxString_ctorCopy_m  0x00497450 ---- */
/* basic_string(const basic_string &right): _Tidy(); assign(right, 0, npos).
 * Inlined into logic_error's constructors; retail keeps an out-of-line copy. */
inline FxStdString::basic_string( const FxStdString &right )
{
  capacity = 15;   /* _Tidy(): _Myres = 15; _Eos(0) */
  ( 16 <= capacity ? bx.ptr : bx.buf )[size = 0] = 0;
  ( (FxString *)this )->Assign( &right, 0, 0xFFFFFFFF );
}

/* ---- stl_fxString_ctorCStr_m  0x00497480 ----  VERIFIED */
/* basic_string(const char *ptr): _Tidy(); assign(ptr, traits::length(ptr)).
 * Then (retail 0x004974C0) ~basic_string: _Tidy(true).  C++ linkage: these are
 * the std::string members LIBCPMT's _Xran/_Xlen and every string temporary's
 * EH unwind action use. */
inline FxStdString::basic_string( const char *ptr )
{
  capacity  = 15;   /* _Tidy(): _Myres = 15; _Eos(0) */
  size      = 0;
  bx.buf[0] = 0;
  stl_fxString_assignPtrCount_m( (int)this, FxConstCharArgument( ptr ), FxCountArgument( strlen( ptr ) ) );
}

inline FxStdString::~basic_string()
{
  unsigned int newsize = 0;   /* _Tidy(true, 0), as Dinkumware spells it */

  if ( 16 <= capacity )
  {
    char *ptr = bx.ptr;
    if ( 0 < newsize )
      memcpy( bx.buf, ptr, newsize );
    operator delete( ptr );   /* _Alval.deallocate: operator delete is nothrow */
  }
  capacity = 15;
  ( 16 <= capacity ? bx.ptr : bx.buf )[size = newsize] = 0;
}

extern "C" {

/* ---- stl_fxString_assignCopy_m  0x004974F0 ----  VERIFIED */
void ***__cdecl stl_fxString_assignCopy_m(void ***right, void ***self)
{
  return (void ***)stl_fxString_assignSubstr_m((int)self, (int)right, 0, 0xFFFFFFFF);
}

/* ---- stl_fxString_cStr_m  0x00497500 ----  VERIFIED */
/* std::string::c_str: inline SSO buffer, or heap buffer once capacity >= 16. */
int __cdecl stl_fxString_cStr_m(int self)
{
  return (int)( 16 <= FXS_RES( self ) ? *(unsigned char **)FXS_BX( self ) : FXS_BX( self ) );   /* Dinkumware _Myptr order */
}

/* ---- stl_fxString_size_m  0x00497510 ----  [HIGH] */
int __fastcall stl_fxString_size_m(unsigned int *thisObj)
{
  FX_STANDARD_CALL(stl_fxString_size_m);
  return thisObj[5];
}

/* ---- stl_fxIntVector_dtor_m  0x00497520 ----  VERIFIED */
void __cdecl stl_fxIntVector_dtor_m(int vec)
{
  if ( *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst )) )
    j__free(*(void **)(vec + FX_VEC_OFS( _Myfirst )));
  *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst )) = 0;
  *(unsigned int *)(vec + FX_VEC_OFS( _Mylast )) = 0;
  *(unsigned int *)(vec + FX_VEC_OFS( _Myend )) = 0;
}

/* ---- stl_fxIntVector_size_m  0x00497550 ----  VERIFIED */
/* std::vector<int>::size: (end - begin) / sizeof(int). */
int __cdecl stl_fxIntVector_size_m(int vec)
{
  int begin;

  begin = *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst ));
  if ( !begin )
    return 0;
  return (*(int *)(vec + FX_VEC_OFS( _Mylast )) - begin) >> 2;   /* ptrdiff: sar */
}

/* ---- stl_fxIntVector_subscript_m  0x00497570 ----  [HIGH] */
int __cdecl stl_fxIntVector_subscript_m(int vec, int index)
{
  return *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst )) + 4 * index;
}

/* ---- stl_fxIntVector_subscript_dup_m  0x00497580 ----  [HIGH] */
int __cdecl stl_fxIntVector_subscript_dup_m(int vec, int index)
{
  return *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst )) + 4 * index;
}

/* ---- stl_fxIntVector_pushBack_m  0x00497590 ----  VERIFIED */
/* std::vector<int>::push_back: grow-and-insert when full, else append at end. */
__declspec(noinline) void __cdecl stl_fxIntVector_pushBack_m(unsigned int *value,unsigned int *vec)
{
  unsigned int      *end;
  unsigned int size;
  unsigned int capacity;

  size     = !vec[1] ? 0 : (unsigned int)( (int)( vec[2] - vec[1] ) >> 2 );   /* size() */
  capacity = !vec[1] ? 0 : (unsigned int)( (int)( vec[3] - vec[1] ) >> 2 );   /* capacity() */
  if ( size < capacity )
  {
    end = (unsigned int *)vec[2];
    stl_fxIntVector_uninitFillN_m(end,(unsigned int)(1),value,FxIntAllocator((void *)vec),FxScalarPointerCategory());
    vec[2] = (unsigned int)( end + 1 );
  }
  else
  {
    FxVecIter where( (unsigned int *)vec[2] );   /* end() */
    ( (struct FxIntVector *)vec )->InsertN( where, 1, *value );
  }

}

/* ---- stl_fxIntVector_tidy_dup_m  0x004975F0 ----  VERIFIED */
void __cdecl stl_fxIntVector_tidy_dup_m(int vec)
{
  if ( *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst )) )
    j__free(*(void **)(vec + FX_VEC_OFS( _Myfirst )));
  *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst )) = 0;
  *(unsigned int *)(vec + FX_VEC_OFS( _Mylast )) = 0;
  *(unsigned int *)(vec + FX_VEC_OFS( _Myend )) = 0;
}

/* ---- FxPool_CtorPrimitiveTemplate_m  0x00497620 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorPrimitiveTemplate_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(54.0);
  return pool;
}

/* ---- FxPool_AllocPrimitiveTemplate  0x00497640 ----  VERIFIED */
int *__stdcall FxPool_AllocPrimitiveTemplate( int *pool, int elemSize )
{
  int *block;
  int *node;

  /* the pool template's Alloc (memorytree.cpp FxPool_AllocPrimType14): scan the
   * slab list for a free object, moving that slab to the front, else claim a
   * new slab */
  for ( block = (int *)pool[1]; block; block = (int *)block[8190] )   /* +0x7FF8 */
  {
    if ( block[8189] )                                                 /* +0x7FF4 freeList */
    {
      if ( block != (int *)pool[1] )
        FxPool_MakeBlockCurrentPrimitiveTemplate( (int)pool, (int)block );
      goto pop;
    }
  }
  block = (int *)FxMem_ClaimBlock_m( pool[0], elemSize, pool[1] );
  if ( !block )
    return NULL;
  pool[1] = (int)block;
pop:
  node        = (int *)block[8189];
  block[8189] = *node;
  block[8188]--;                                                       /* +0x7FF0 freeCount */
  Com_Memset( node, 0, 0x25Cu );
  return node;
}

/* ---- FxPool_FreePrimitiveTemplate  0x004976D0 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreePrimitiveTemplate( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);

  cur = (unsigned int *)pool[1];
  if (!cur[8189])
    return (unsigned int *)FxPool_MakeBlockCurrentPrimitiveTemplate( (int)pool, (int)block );
  if (count >= pool[0])
  {
    if (block == cur)
    {
      nxt = (int)block[8190];
      if (!nxt || !*(int *)(nxt + 32752))
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- FxPool_CtorScheduledEffect_m  0x00497740 ----  VERIFIED */
unsigned __int64 *__cdecl FxPool_CtorScheduledEffect_m(unsigned __int64 *pool)
{
  *pool = (unsigned int)(unsigned __int64)floor(481.0);
  return pool;
}

/* ---- FxMem_AllocScheduledEffect  0x00497750 ----  VERIFIED */
int *__stdcall FxMem_AllocScheduledEffect( int *pool, int elemSize )
{
  int *block;
  int *node;

  /* the pool template's Alloc (memorytree.cpp FxPool_AllocPrimType14): scan the
   * slab list for a free object, moving that slab to the front, else claim a
   * new slab */
  for ( block = (int *)pool[1]; block; block = (int *)block[8190] )   /* +0x7FF8 */
  {
    if ( block[8189] )                                                 /* +0x7FF4 freeList */
    {
      if ( block != (int *)pool[1] )
        FxPool_MakeBlockCurrentScheduledEffect( (int)pool, (int)block );
      goto pop;
    }
  }
  block = (int *)FxMem_ClaimBlock_m( pool[0], elemSize, pool[1] );
  if ( !block )
    return NULL;
  pool[1] = (int)block;
pop:
  node        = (int *)block[8189];
  block[8189] = *node;
  block[8188]--;                                                       /* +0x7FF0 freeCount */
  Com_Memset( node, 0, FX_SCHEDULED_EFFECT_SIZE );
  return node;
}

/* ---- FxPool_FreeScheduledEffect  0x004977F0 ----  VERIFIED */
unsigned int *__fastcall FxPool_FreeScheduledEffect( int *pool, char *p )
{
  unsigned int *block;
  int     count;
  unsigned int *cur;
  int     nxt;

  block       = (unsigned int *)( (char *)&fxMemBlocks
                            + ( ( p - (char *)&fxMemBlocks ) & 0xFFFF8000 ) );
  *(unsigned int *)p = block[8189];
  block[8189]  = (unsigned int)p;
  count        = ++*(int *)(block + 8188);

  cur = (unsigned int *)pool[1];
  if (!cur[8189])
    return (unsigned int *)FxPool_MakeBlockCurrentScheduledEffect( (int)pool, (int)block );
  if (count >= pool[0])
  {
    if (block == cur)
    {
      nxt = (int)block[8190];
      if (!nxt || !*(int *)(nxt + 32752))
        return block;
      pool[1] = nxt;
    }
    return (unsigned int *)FxMem_ReleaseBlock((struct fxPoolBlock_s *)block);
  }
  return block;
}

/* ---- stl_fxEffectIdMap_ctor_m  0x00497860 ----  VERIFIED */
/* std::map/_Tree default-construct: allocate the self-referential nil head. */
int __cdecl stl_fxEffectIdMap_ctor_m(int tree)
{
  unsigned int *head;
  char    comparator;   

  *(byte *)tree = comparator;
  head = stl_fxEffectIdMap_buynodeHead_m(tree);
  *(unsigned int *)(tree + FX_TREE_OFS( _Myhead )) = (int)head;
  *(unsigned char *)(*(unsigned int *)(tree+FX_TREE_OFS( _Myhead ))+45)=1;
  *(unsigned int *)(*(unsigned int *)(tree+FX_TREE_OFS( _Myhead ))+4)=*(unsigned int *)(tree+FX_TREE_OFS( _Myhead ));
  *(unsigned int *)(*(unsigned int *)(tree+FX_TREE_OFS( _Myhead ))+0)=*(unsigned int *)(tree+FX_TREE_OFS( _Myhead ));
  *(unsigned int *)(*(unsigned int *)(tree+FX_TREE_OFS( _Myhead ))+8)=*(unsigned int *)(tree+FX_TREE_OFS( _Myhead ));
  *(unsigned int *)(tree + FX_TREE_OFS( _Mysize )) = 0;
  return tree;
}

/* ---- stl_fxEffectIdMap_index_m  0x00497890 ----  VERIFIED */
/* map<string, int>::operator[](key): insert(value_type(key, int())).first->second.
 * The value_type temporary's string is destroyed on the way out (and by the
 * EH unwind if insert throws). */
int __stdcall stl_fxEffectIdMap_index_m( int tree, const FxStdString &key )
{
  int            it[2];   /* pair<iterator, bool> */
  unsigned char *where;

  where = *(unsigned char **)stl_fxEffectIdMap_insert_m( tree, (int)it, (void ***)&FxEffectIdValue( key, 0 ) );
  return (int)( where + 40 );   /* (*where).second */
}

/* ---- stl_fxEffectIdMap_dtor_m  0x00497920 ----  VERIFIED */
/* std::map::clear: erase the whole tree, free the head, reset head/size. */
int __cdecl stl_fxEffectIdMap_dtor_m(int tree)
{
  int *erased; // BYREF: past-the-end iterator returned by erase

  stl_fxEffectIdMap_eraseRange_m(tree,FxMapIteratorArgument((void *)(&erased)),FxMapIteratorArgument((void *)(**(int ***)(tree + FX_TREE_OFS( _Myhead )))),FxMapIteratorArgument((void *)(*(int **)(tree + FX_TREE_OFS( _Myhead )))));
  j__free(*(void **)(tree + FX_TREE_OFS( _Myhead )));
  *(unsigned int *)(tree + FX_TREE_OFS( _Myhead )) = 0;
  *(unsigned int *)(tree + FX_TREE_OFS( _Mysize )) = 0;
  return 0;
}

/* ---- stl_fxEffectIdMap_begin_m  0x00497950 ----  [HIGH] */
unsigned int *__cdecl stl_fxEffectIdMap_begin_m(unsigned int *result, int tree)
{
  *result = **(unsigned int **)(tree + 4);
  return result;
}

/* ---- stl_fxEffectIdMap_end_m  0x00497960 ----  [HIGH] */
unsigned int *__cdecl stl_fxEffectIdMap_end_m(unsigned int *result, int tree)
{
  *result = *(unsigned int *)(tree + FX_TREE_OFS( _Myhead ));
  return result;
}

/* ---- stl_fxEffectIdMap_clear_m  0x00497970 ----  VERIFIED */
/* std::map::clear: destroy the whole tree, then re-point the head at itself. */
void __cdecl stl_fxEffectIdMap_clear_m(int tree)
{
  /* _Erase(_Root()): the root link is passed as the by-value node pointer
   * straight from the head node (copied through ECX as in retail). */
  stl_fxEffectIdMap_eraseSubtree_m((void *)tree,*(FxMapRootValue *)&FXN_PARENT(*(unsigned int **)(tree+FX_TREE_OFS( _Myhead ))));
  FXN_PARENT(*(unsigned int **)(tree+FX_TREE_OFS( _Myhead )))=(unsigned char *)*(unsigned int **)(tree+FX_TREE_OFS( _Myhead ));
  *(unsigned int *)(tree + FX_TREE_OFS( _Mysize )) = 0;                        
  FXN_LEFT(*(unsigned int **)(tree+FX_TREE_OFS( _Myhead )))=(unsigned char *)*(unsigned int **)(tree+FX_TREE_OFS( _Myhead ));
  FXN_RIGHT(*(unsigned int **)(tree+FX_TREE_OFS( _Myhead )))=(unsigned char *)*(unsigned int **)(tree+FX_TREE_OFS( _Myhead ));

}

/* ---- stl_fxEffectIdMap_find_m  0x004979A0 ----  VERIFIED */
FxMapIter __cdecl stl_fxEffectIdMap_find_m( int tree, int key )
{
  int           where;      /* iterator _Where = lower_bound(_Keyval) */
  int           endNode;    /* the end() temporary */
  int          *pick;
  unsigned char *node;
  unsigned int  nlen;

  where = stl_fxEffectIdMap_lbound_m( tree, (const void *)key );
  node  = (unsigned char *)where;
  /* return (_Where == end() || comp(_Keyval, _Key(_Where)) ? end() : _Where);
   * the key's size() is evaluated before its c_str() (right-to-left arguments) */
  if ( node == FXT_HEAD( tree )
       || ( nlen = FXS_SIZE( FXN_KEY( node ) ),
            stl_fxString_compare_m( key, FXS_SIZE( key ), 0, (const char *)FXS_PTR( FXN_KEY( node ) ), nlen ) < 0 ) )
  {
    endNode = (int)FXT_HEAD( tree );
    pick    = &endNode;
  }
  else
  {
    pick = &where;
  }
  return FxMapIter( (unsigned char *)*pick );
}

/* ---- stl_fxEffectIdMap_iterNotEqual_m  0x00497A00 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_iterNotEqual_m(unsigned int *left, unsigned int *right)
{
  return *left != *right;
}

/* ---- stl_fxEffectIdMap_iterDefaultCtor_m  0x00497A10 ----  [HIGH] */
unsigned int *__cdecl stl_fxEffectIdMap_iterDefaultCtor_m(unsigned int *result)
{
  *result = 0;
  return result;
}

/* ---- stl_fxEffectIdMap_iterDeref_m  0x00497A20 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_iterDeref_m(unsigned int *iter)
{
  return *iter + 12;
}

/* ---- stl_fxEffectIdMap_iterPreinc_m  0x00497A30 ----  VERIFIED */
int **__cdecl stl_fxEffectIdMap_iterPreinc_m(int **iter)
{
  stl_fxEffectIdMap_iterInc_m(iter);
  return iter;
}

/* ---- stl_fxScheduledList_ctor_m  0x00497A40 ----  VERIFIED */
int __cdecl stl_fxScheduledList_ctor_m(int list)
{
  *(unsigned int *)(list + FX_LIST_OFS( _Myhead )) = (unsigned int)stl_fxScheduledList_buynodeHead_m(list);
  *(unsigned int *)(list + FX_LIST_OFS( _Mysize )) = 0;
  return list;
}

/* ---- stl_fxScheduledList_dtor_m  0x00497A60 ----  VERIFIED */
/* std::list::clear: erase [first, head), free the head, reset head/size. */
void __cdecl stl_fxScheduledList_dtor_m(int list)
{
  unsigned int *head;
  unsigned int *first;

  head = *(unsigned int **)(list + FX_LIST_OFS( _Myhead ));
  first = head == 0 ? 0 : (unsigned int *)*head;
  stl_fxScheduledList_eraseRange_m(list,FxListIterator(first),FxListIterator(head));
  j__free(*(void **)(list + FX_LIST_OFS( _Myhead )));
  *(unsigned int *)(list + FX_LIST_OFS( _Myhead )) = 0;
  *(unsigned int *)(list + FX_LIST_OFS( _Mysize )) = 0;
}

/* ---- stl_fxScheduledList_begin_m  0x00497AA0 ----  VERIFIED */
/* std::list::begin: head->next (the first element), or 0 for an empty list.
 * Written like <list>'s `_Myhead == 0 ? 0 : _Next(_Myhead)` (two reads of
 * _Myhead): inlined into AddScheduledEffects, end() then reloads _Myhead. */
unsigned int *__cdecl stl_fxScheduledList_begin_m(unsigned int *result, int list)
{
  *result = ( *(unsigned int **)( list + 4 ) == 0 ? 0 : **(unsigned int **)( list + 4 ) );
  return ( result );
}

/* ---- stl_fxScheduledList_end_m  0x00497AB0 ----  [HIGH] */
unsigned int *__cdecl stl_fxScheduledList_end_m(unsigned int *result, int list)
{
  *result = *(unsigned int *)(list + FX_LIST_OFS( _Myhead ));
  return result;
}

/* ---- stl_fxScheduledList_size_m  0x00497AC0 ----  [HIGH] */
int __cdecl stl_fxScheduledList_size_m(int list)
{
  return *(unsigned int *)(list + FX_LIST_OFS( _Mysize ));
}

/* ---- stl_fxScheduledList_pushFront_m  0x00497AD0 ----  VERIFIED */
/* std::list insert before begin: splice a fresh node in front of head->next. */
/* __stdcall: LTCG keeps the list in a register and pops the value reference. */
int __stdcall stl_fxScheduledList_pushFront_m(int list, unsigned int *value)
{
  int    *head;
  int     first;
  unsigned int *node;
  int     result;

  head = *(int **)(list + 4);
  first = head == 0 ? 0 : *head;   /* begin() */
  node = stl_fxScheduledList_buynodeVal_m(list, first, *(unsigned int *)(first + FX_LISTNODE_OFS( _Prev )), value);
  result = stl_fxScheduledList_incsize_m(1u, list);
  *(unsigned int *)(first + FX_LISTNODE_OFS( _Prev )) = (int)node;
  *(unsigned int *)node[1] = (int)node;
  return result;
}

/* ---- stl_fxScheduledList_pushBack_m  0x00497B10 ----  VERIFIED */
/* std::list insert at head: splice a fresh node holding *value in before head. */
int __cdecl stl_fxScheduledList_pushBack_m(unsigned int *value, int list)
{
  int     head;
  unsigned int *node;
  int     result;

  head = *(unsigned int *)(list + FX_LIST_OFS( _Myhead ));
  node = stl_fxScheduledList_buynodeVal_m(list, head, *(unsigned int *)(head + FX_LISTNODE_OFS( _Prev )), value);
  result = stl_fxScheduledList_incsize_m(1u, list);
  *(unsigned int *)(head + FX_LISTNODE_OFS( _Prev )) = (int)node;
  *(unsigned int *)node[1] = (int)node;
  return result;
}

/* ---- stl_fxScheduledList_erase_m  0x00497B40 ----  VERIFIED */
/* std::list::erase(where): _Pnode = (_Where++)._Mynode(); unlink _Pnode
 * (unless it is the head), free it, return the advanced _Where.  Retail
 * userpurge: list@esi, result@edi, where on the stack (retn 4); the
 * __stdcall (list, result, where) order gets those registers from LTCG. */
unsigned int *__stdcall stl_fxScheduledList_erase_m(int list, unsigned int *result, FxListIteratorArgument whereArg)
{
  unsigned int **Block;

  Block = (unsigned int **)whereArg.node;                 /* _Pnode = (_Where++)._Mynode() */
  whereArg.node = (unsigned int *)*Block;
  if ( Block != *(unsigned int ***)(list + FX_LIST_OFS( _Myhead )) )
  {
    *Block[1] = (unsigned int)*Block;
    (*Block)[1] = (unsigned int)Block[1];
    j__free(Block);
    --*(unsigned int *)(list + FX_LIST_OFS( _Mysize ));
  }
  *result = (unsigned int)whereArg.node;
  return result;
}

/* ---- stl_fxScheduledList_iterNotEqual_m  0x00497B80 ----  [HIGH] */
int __cdecl stl_fxScheduledList_iterNotEqual_m(unsigned int *left, unsigned int *right)
{
  return *left != *right;
}

/* ---- stl_fxScheduledList_iterDefaultCtor_m  0x00497B90 ----  [HIGH] */
unsigned int *__cdecl stl_fxScheduledList_iterDefaultCtor_m(unsigned int *result)
{
  *result = 0;
  return result;
}

/* ---- stl_fxScheduledList_iterDeref_m  0x00497BA0 ----  [HIGH] */
int __cdecl stl_fxScheduledList_iterDeref_m(unsigned int *iter)
{
  return *iter + 8;
}

/* ---- stl_fxScheduledList_iterPreinc_m  0x00497BB0 ----  [HIGH] */
unsigned int **__cdecl stl_fxScheduledList_iterPreinc_m(unsigned int **result)
{
  *result = (unsigned int *)**result;
  return result;
}

/* ---- stl_fxScheduledList_iterPostinc_m  0x00497BC0 ----  VERIFIED */
/* std::list iterator post-increment: return the current node, advance to next. */
unsigned int *__fastcall stl_fxScheduledList_iterPostinc_m(unsigned int *result,unsigned int **iter,FxPostIncrementArgument postfix)
{
  unsigned int **cur;

  cur = (unsigned int **)*iter;
  *iter = (unsigned int *)**iter;
  *result = (unsigned int)cur;
  return result;
}

}   /* extern "C" */

/* (retail 0x00497BD0, inside no IDA function) */
/* ~pair<const string, int>(): the key string's destructor. */
inline FxEffectIdValue::~pair()
{
}

extern "C" {

/* ---- stl_fxString_assignStr_m  0x00497C00 ----  VERIFIED */
void ***__cdecl stl_fxString_assignStr_m(void ***right, void ***self)
{
  return (void ***)stl_fxString_assignSubstr_m((int)self, (int)right, 0, 0xFFFFFFFF);
}

/* ---- stl_fxString_assignSubstr_m  0x00497C10 ----  VERIFIED */
int FxString::Assign( const void *right, unsigned int off, unsigned int count )
{
  int            self = (int)this;
  int            src  = (int)right;
  unsigned int   n;
  unsigned char *dst;

  (void)&FxString::Assign;   /* keeps the declared __thiscall under LTCG */
  if ( FXS_SIZE( src ) < off )
    ( (const std::_String_base *)this )->_Xran();  /* retail 0x00497C1F: _Xran() */

  n = FXS_SIZE( src ) - off;
  if ( count < n )
    n = count;

  if ( self == src )
  {
    stl_fxString_erase_m( self, off + n, 0xFFFFFFFF );
    /* `self + src - src` (== self) folds away in code generation, but VC7's
     * LTCG escape summary still sees `right` handed to Erase as `this`, as in
     * Dinkumware's assign (where this == &_Right): callers then keep retail's
     * dead _Tidy stores on the source string (SE_ParseConfig_m,
     * stl_map_index_m). */
    stl_fxString_erase_m( self + src - src, 0, off );
    return self;
  }

  if ( stl_fxString_grow_m( self, n, 1 ) )
  {
    memcpy( FXS_PTR( self ), FXS_PTR( src ) + off, n );
    FXS_SIZE( self ) = n;
    dst = FXS_PTR( self );
    dst[n] = 0;
  }
  return self;
}

/* ---- stl_fxString_assignCStr_m  0x00497CC0 ----  VERIFIED */
/* basic_string::assign(const char *ptr): assign(ptr, traits::length(ptr)); retail
 * __thiscall (this@ecx, passed straight on), retn 4. */
void ***__fastcall stl_fxString_assignCStr_m( void *thisObj, int unusedEdx, const char *str )
{
  FX_STANDARD_CALL(stl_fxString_assignCStr_m);
  (void)unusedEdx;
  return (void ***)stl_fxString_assignPtrCount_m( (int)thisObj, FxConstCharArgument( str ), FxCountArgument( strlen( str ) ) );
}

/* ---- stl_fxString_myptrConst_m  0x00497CF0 ----  VERIFIED */
/* basic_string::_Myptr() const: the inline SSO buffer, or the heap buffer once
 * capacity >= 16.  Inline: this is its out-of-line (__thiscall) copy. */
inline const char *FxString::Myptr() const
{
  (void)&FxString::Myptr;   /* keeps the out-of-line copy __thiscall */
  return ( 16 <= capacity ? bx.ptr : (const char *)&bx );
}

/* ---- stl_fxString_tidy_m  0x00497D00 ----  VERIFIED */
/* basic_string::_Tidy(built): free the heap buffer if any, then re-init empty.
 * Inline (Grow / Copy expand it); this is its out-of-line (__thiscall) copy. */
inline void FxString::Tidy( bool built )
{
  (void)&FxString::Tidy;   /* keeps the out-of-line copy __thiscall */
  if ( !built )
    ;
  else if ( 16 <= capacity )
    operator delete( (char *)Myptr() );   /* _Alval.deallocate(_Myptr(), _Myres + 1) */
  capacity = 15;
  Eos( 0 );
}

/* ---- type_info__operator__type_info  0x00497D40 ----  [HIGH] */
void *__fastcall type_info__operator__type_info(void *thisObj, FxTypeInfoSourceArgument sourceArg)
{
  FX_STANDARD_CALL(type_info__operator__type_info);
  return thisObj;
}

/* ---- stl_fxAllocator_ctor_m  0x00497D50 ----  [HIGH] */
/* An empty allocator's default constructor (IDA's FLIRT label:
 * Iostream_init::Iostream_init): __thiscall, returns this.  Retail keeps
 * this out-of-line copy although nothing calls it. */
void *__fastcall stl_fxAllocator_ctor_m( void *thisObj )
{
  FX_STANDARD_CALL(stl_fxAllocator_ctor_m);
  return thisObj;
}

/* ---- stl_fxAllocator_copyCtor_m  0x00497D60 ----  [HIGH] */
/* The empty allocator's converting copy constructor: __thiscall with one
 * (unused) reference argument, retn 4, returns this.  Uncalled in retail. */
void *__fastcall stl_fxAllocator_copyCtor_m( void *thisObj, FxConstPointerArgument otherArg )
{
  FX_STANDARD_CALL(stl_fxAllocator_copyCtor_m);
  (void)otherArg;
  return thisObj;
}

/* ---- stl_fxIntVector_capacity_m  0x00497D70 ----  VERIFIED */
/* std::vector<int>::capacity: (end-of-storage - begin) / sizeof(int). */
int __cdecl stl_fxIntVector_capacity_m(int vec)
{
  int begin;

  begin = *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst ));
  if ( !begin )
    return 0;
  return (*(int *)(vec + FX_VEC_OFS( _Myend )) - begin) >> 2;   /* ptrdiff: sar */
}

/* ---- stl_fxIntVector_begin_m  0x00497D90 ----  [HIGH] */
unsigned int *__cdecl stl_fxIntVector_begin_m(unsigned int *result, int vec)
{
  *result = *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst ));
  return result;
}

/* ---- stl_fxIntVector_beginConst_m  0x00497DA0 ----  [HIGH] */
unsigned int *__cdecl stl_fxIntVector_beginConst_m(unsigned int *result, int vec)
{
  *result = *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst ));
  return result;
}

/* ---- stl_fxIntVector_end_m  0x00497DB0 ----  [HIGH] */
unsigned int *__cdecl stl_fxIntVector_end_m(unsigned int *result, int vec)
{
  *result = *(unsigned int *)(vec + FX_VEC_OFS( _Mylast ));
  return result;
}

/* ---- stl_fxIntVector_insert_m  0x00497DC0 ----  VERIFIED */
/* std::vector<int>::insert: remember the slot index across the realloc, then
 * return the iterator to the freshly inserted element. */
unsigned int *__fastcall stl_fxIntVector_insert_m(unsigned int *result,int vec,FxVectorWordArgument positionArg,FxVectorWordArgument valueArg)
{
  unsigned int *position=positionArg.pointer;
  unsigned int *value=valueArg.pointer;
  int begin;
  int index;
  unsigned int size;

  begin = *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst ));
  size = begin ? (unsigned int)((*(int *)(vec+FX_VEC_OFS( _Mylast ))-begin)>>2) : 0;
  index = size == 0 ? 0 : ( (int)position - begin ) >> 2;   /* _Off = size() == 0 ? 0 : _Where - begin() */
  stl_fxIntVector_insertN_m(vec,FxVectorWord((unsigned int*)(position)),FxVectorCount(1u),FxVectorWord((unsigned int*)(value)));
  *result = *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst )) + 4 * index;
  return result;
}

/* ---- stl_fxIntVector_tidy_m  0x00497E10 ----  VERIFIED */
void __cdecl stl_fxIntVector_tidy_m(int vec)
{
  if ( *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst )) )
    j__free(*(void **)(vec + FX_VEC_OFS( _Myfirst )));
  *(unsigned int *)(vec + FX_VEC_OFS( _Myfirst )) = 0;
  *(unsigned int *)(vec + FX_VEC_OFS( _Mylast )) = 0;
  *(unsigned int *)(vec + FX_VEC_OFS( _Myend )) = 0;
}

/* ---- stl_fxIntVector_ufill_m  0x00497E40 ----  VERIFIED */
unsigned int *__cdecl stl_fxIntVector_ufill_m(void *allocatorObject,unsigned int *value,unsigned int *dest,unsigned int count)
{
  stl_fxIntVector_uninitFillN_m(dest,(unsigned int)(count),value,FxIntAllocator(allocatorObject),FxScalarPointerCategory());
  return &dest[count];
}

/* ---- stl_fxIntVector_iterDeref_m  0x00497E60 ----  [HIGH] */
int __cdecl stl_fxIntVector_iterDeref_m(int iter)
{
  return *(unsigned int *)iter;
}

/* ---- stl_fxIntVector_iterAdd_m  0x00497E70 ----  [HIGH] */
unsigned int *__fastcall stl_fxIntVector_iterAdd_m(unsigned int *result, unsigned int *iter, int offset)
{
  *result = *iter + 4 * offset;
  return result;
}

/* ---- FxPool_MakeBlockCurrentPrimitiveTemplate  0x00497E80 ----  VERIFIED */
/* Unlink a block from its freelist and make it the pool's current block. */
int __cdecl FxPool_MakeBlockCurrentPrimitiveTemplate(int pool, int block)
{
  int next;
  int prev;

  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- FxPool_MakeBlockCurrentScheduledEffect  0x00497EE0 ----  VERIFIED */
/* Unlink a block from its freelist and make it the pool's current block. */
int __cdecl FxPool_MakeBlockCurrentScheduledEffect(int pool, int block)
{
  int next;
  int prev;

  next = *(unsigned int *)(block + FX_HDR_NEXT);
  if ( next )
    *(unsigned int *)(next + FX_HDR_PREV) = *(unsigned int *)(block + FX_HDR_PREV);
  prev = *(unsigned int *)(block + FX_HDR_PREV);
  if ( prev )
    *(unsigned int *)(prev + FX_HDR_NEXT) = *(unsigned int *)(block + FX_HDR_NEXT);
  *(unsigned int *)(block + FX_HDR_PREV) = 0;
  *(unsigned int *)(block + FX_HDR_NEXT) = 0;
  *(unsigned int *)(block + FX_HDR_PREV) = *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock ));
  *(unsigned int *)(*(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) + FX_HDR_NEXT) = block;
  *(unsigned int *)(pool + FX_POOL_OFS( mHeadBlock )) = block;
  return block;
}

/* ---- stl_fxEffectIdMap_key_m  0x00497F40 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_key_m(int node)
{
  return node + 12;
}

/* ---- stl_fxEffectIdMap_myval_m  0x00497F50 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_myval_m(int node)
{
  return node + 12;
}

/* ---- stl_fxEffectIdMap_treeCtor_m  0x00497F60 ----  VERIFIED */
/* std::map/_Tree copy-construct: copy the comparator, allocate the nil head. */
int __fastcall stl_fxEffectIdMap_treeCtor_m(byte *comparator,int tree,FxTreeAllocatorReference allocatorArg)
{
  unsigned int *head;

  *(byte *)tree = *comparator;
  head = stl_fxEffectIdMap_buynodeHead_m(tree);
  *(unsigned int *)(tree + FX_TREE_OFS( _Myhead )) = (int)head;
  FXN_ISNIL( head )  = 1;
  head = *(unsigned int **)(tree + FX_TREE_OFS( _Myhead ));
  FXN_PARENT( head ) = (unsigned char *)head;
  head = *(unsigned int **)(tree + FX_TREE_OFS( _Myhead ));
  FXN_LEFT( head )   = (unsigned char *)head;
  head = *(unsigned int **)(tree + FX_TREE_OFS( _Myhead ));
  FXN_RIGHT( head )  = (unsigned char *)head;
  *(unsigned int *)(tree + FX_TREE_OFS( _Mysize )) = 0;
  return tree;
}

/* ---- stl_fxEffectIdMap_insert_m  0x00497F90 ----  VERIFIED */
/* <xtree> insert(const value_type&).  _Addleft is an aggregate so it keeps a
 * stack home like retail's (byte stores in the loop, dword push for _Insert);
 * each _Insert's returned iterator is its own temporary (packed into the val
 * slot, as retail); the post-loop comp() goes through the less functor, which
 * LTCG inlines down to the string compare call.  _Insert takes (this, node):
 * register arguments are set up right to left, so the node (ecx) is loaded
 * before this (edi) as in retail. */
int __stdcall stl_fxEffectIdMap_insert_m( int tree, int result, void ***val )
{
  unsigned char *node;
  unsigned char *where;
  unsigned char *pred;
  unsigned char *key = (unsigned char *)val;
  FxRebalanceBool addleft;   /* _Addleft */

  node    = FXN_PARENT( FXT_HEAD( tree ) );   /* _Root() */
  where   = FXT_HEAD( tree );
  addleft.value = 1;   /* add to left of head if tree empty */
  while ( !FXN_ISNIL( node ) )
  {
    /* look for leaf to insert before (addleft) or after */
    where   = node;
    addleft.value = stl_fxStringLess_opCall_m( (int)key, (int)FXN_KEY( node ), 0 );
    node    = addleft.value ? FXN_LEFT( node ) : FXN_RIGHT( node );
  }

  pred = where;
  if ( addleft.value )
  {
    if ( where == FXN_LEFT( FXT_HEAD( tree ) ) )
    {
      unsigned char *inserted;   /* _Insert(true, _Wherenode, _Val) */
      *(int *)result       = *(int *)stl_fxEffectIdMap_insertRebalance_m(tree,(int)where,FxRebalanceOutput((void ***)&inserted),1,FxRebalanceInput((int)key));
      *(char *)( result + 4 ) = 1;
      return result;
    }
    stl_fxEffectIdMap_iterDec_m((int **)&pred);
  }

  if ( stl_fxStringLess_opCall_m( (int)FXN_KEY( pred ), (int)key, 0 ) )   /* comp(_Key(_Where), _Kfn(_Val)) */
  {
    unsigned char *inserted;
    *(int *)result       = *(int *)stl_fxEffectIdMap_insertRebalance_m(tree,(int)where,FxRebalanceOutput((void ***)&inserted),addleft.value,FxRebalanceInput((int)key));
    *(char *)( result + 4 ) = 1;
    return result;
  }

  *(int *)result          = (int)pred;
  *(char *)( result + 4 ) = 0;
  return result;
}

/* ---- stl_fxEffectIdMap_lowerBound_m  0x004980F0 ----  VERIFIED */
int **__cdecl stl_fxEffectIdMap_lowerBound_m(int **result,int tree,int key)
{
  *result=(int *)stl_fxEffectIdMap_lbound_m(tree,(const void *)key);
  return result;
}

/* ---- stl_fxEffectIdMap_eraseSubtree_m  0x00498100 ----  VERIFIED */
__declspec(noinline) void __fastcall stl_fxEffectIdMap_eraseSubtree_m(void *receiver,FxMapRootValue root)
{
  void **current=root.pointer;
  void **next=current;
  while(!FXN_ISNIL(next))
  {
    stl_fxEffectIdMap_eraseSubtree_m(receiver,FxMapRootArgument((void **)FXN_RIGHT(next)));
    next=(void **)FXN_LEFT(next);
    stl_fxEffectIdMap_nodeDtor_m((int)current);
    j__free(current);
    current=next;
  }
}

/* ---- stl_fxEffectIdMap_lmost_m  0x00498140 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_lmost_m(int tree)
{
  return *(unsigned int *)(tree + FX_TREE_OFS( _Myhead ));
}

/* ---- stl_fxEffectIdMap_rmost_m  0x00498150 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_rmost_m(int tree)
{
  return *(unsigned int *)(tree + FX_TREE_OFS( _Myhead )) + 8;
}

/* ---- stl_fxEffectIdMap_root_m  0x00498160 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_root_m(int tree)
{
  return *(unsigned int *)(tree + FX_TREE_OFS( _Myhead )) + 4;
}

/* ---- stl_fxEffectIdMap_tidy_m  0x00498170 ----  VERIFIED */
/* std::map::clear: erase the whole tree, free the head, reset head/size. */
int __cdecl stl_fxEffectIdMap_tidy_m(int tree)
{
  int *erased; // BYREF: past-the-end iterator returned by erase

  stl_fxEffectIdMap_eraseRange_m(tree,FxMapIteratorArgument((void *)(&erased)),FxMapIteratorArgument((void *)(**(int ***)(tree + FX_TREE_OFS( _Myhead )))),FxMapIteratorArgument((void *)(*(int **)(tree + FX_TREE_OFS( _Myhead )))));
  j__free(*(void **)(tree + FX_TREE_OFS( _Myhead )));
  *(unsigned int *)(tree + FX_TREE_OFS( _Myhead )) = 0;
  *(unsigned int *)(tree + FX_TREE_OFS( _Mysize )) = 0;
  return 0;
}

/* ---- FX_UnusedStub2  0x004981A0 ----  [HIGH] */
/* retail 0x004981A0, IDA nullsub_39: bare retn, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void FX_UnusedStub2()
{
  ;
}

/* ---- stl_fxStringLess_opCall_m  0x004981B0 ----  IMPLEMENTED (retail) */
/* std::less<std::string> for the effect-id map: left < right, i.e.
 * left.compare(0, left.size(), right.c_str(), right.size()) < 0 via
 * stl_fxString_compare_m.  Retail is __userpurge (right@eax, left@ecx) plus one stack
 * dword it never reads, retn 4. */
FX_BOOL __stdcall stl_fxStringLess_opCall_m( int left, int right, int unused )
{
  unsigned int count = FXS_SIZE( right );

  (void)unused;
  return stl_fxString_compare_m( left, FXS_SIZE( left ), 0, (const char *)FXS_PTR( right ),
                     count ) < 0;
}

}   /* extern "C" */

/* ---- stl_fxEffectIdMap_pairCtor_m  0x004981E0 ----  VERIFIED */
/* pair(const string &, const int &): the key copied, then the mapped value. */
inline FxEffectIdValue::pair( const FxStdString &val1, const int &val2 )
  : first( val1 ), second( val2 )
{
}

extern "C" {

/* ---- stl_fxEffectIdMap_constIterCtor_m  0x00498210 ----  [HIGH] */
unsigned int *__cdecl stl_fxEffectIdMap_constIterCtor_m(unsigned int *result, int node)
{
  *result = node;
  return result;
}

/* ---- stl_fxEffectIdMap_iterEqual_m  0x00498220 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_iterEqual_m(unsigned int *left, unsigned int *right)
{
  return *right == *left;
}

/* ---- stl_fxEffectIdMap_iterInc_m  0x00498230 ----  VERIFIED */
__inline void __fastcall stl_fxEffectIdMap_iterInc_m(int **pptr)
{
 int*p=*pptr;int*q;
 if(!*((char*)p+45)){q=(int*)p[2];if(!*((char*)q+45)){
 while(!*((char*)q[0]+45))q=(int*)q[0];*pptr=q;
 }else{p=(int*)p[1];while(!*((char*)p+45)){if(*pptr!=(int*)p[2])break;*pptr=p;p=(int*)p[1];}*pptr=p;}
 }
}

/* ---- stl_fxEffectIdMap_iterMynode_m  0x00498290 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_iterMynode_m(int iter)
{
  return *(unsigned int *)iter;
}

/* ---- stl_fxEffectIdMap_iterCtor2_m  0x004982A0 ----  [HIGH] */
unsigned int *__cdecl stl_fxEffectIdMap_iterCtor2_m(unsigned int *result, int node)
{
  *result = node;
  return result;
}

/* ---- stl_fxScheduledList_nextnode_m  0x004982B0 ----  [HIGH] */
void stl_fxScheduledList_nextnode_m()
{
  ;
}

/* ---- stl_fxScheduledList_prevnode_m  0x004982C0 ----  [HIGH] */
int __cdecl stl_fxScheduledList_prevnode_m(int node)
{
  return node + 4;
}

/* ---- stl_fxScheduledList_myval_m  0x004982D0 ----  [HIGH] */
int __cdecl stl_fxScheduledList_myval_m(int node)
{
  return node + 8;
}

/* ---- stl_fxScheduledList_insert_m  0x004982E0 ----  VERIFIED */
/* the iterator `where` is a class passed by value: it stays on the stack,
 * popped by the callee (__stdcall: LTCG moves val/list to registers) */
int __stdcall stl_fxScheduledList_insert_m( unsigned int *val, int list, FxListIteratorArgument whereArg )
{
  int where = (int)whereArg.node;
  unsigned int *node;
  int     newsize;

  /* std::list insert-before: splice a fresh node ahead of `where`. */
  node    = stl_fxScheduledList_buynodeVal_m( list, where, *(unsigned int *)( where + FX_LISTNODE_OFS( _Prev ) ), val );
  newsize = stl_fxScheduledList_incsize_m( 1u, list );
  *(unsigned int *)( where + FX_LISTNODE_OFS( _Prev ) ) = (unsigned int)node;   /* where->prev      = node */
  *(unsigned int *)node[1]       = (unsigned int)node;   /* node->prev->next = node */
  return newsize;
}__declspec(noinline) 

/* ---- stl_fxScheduledList_buynodeHead_m  0x00498310 ----  VERIFIED */
unsigned int *__stdcall stl_fxScheduledList_buynodeHead_m( int list )
{
  unsigned int *p;

  (void)list;
  p = (unsigned int *)crt_operator_new( 0xC );
  /* _Alptr.construct(&_Next(p), p), then &_Prev(p): placement new tests
   * each address for null before the store */
  { unsigned int *slot = &p[0]; if ( slot ) *slot = (unsigned int)p; }
  { unsigned int *slot = &p[1]; if ( slot ) *slot = (unsigned int)p; }
  return p;
}

/* ---- stl_fxScheduledList_tidy_m  0x00498330 ----  VERIFIED */
void __cdecl stl_fxScheduledList_tidy_m( int list )
{
  unsigned int *head;
  unsigned int *first;

  /* std::list clear: erase [first, head), then free the head node. */
  head  = *(unsigned int **)( list + FX_LIST_OFS( _Myhead ) );
  if(!head) first=0;
  else first=(unsigned int *)*head;
  stl_fxScheduledList_eraseRange_m(list,FxListIterator(first),FxListIterator(head));
  j__free( *(void **)( list + FX_LIST_OFS( _Myhead ) ) );
  *(unsigned int *)( list + FX_LIST_OFS( _Myhead ) ) = 0;
  *(unsigned int *)( list + FX_LIST_OFS( _Mysize ) ) = 0;
}

/* ---- stl_fxScheduledList_nopArg_m  0x00498370 ----  [HIGH] */
void __stdcall stl_fxScheduledList_nopArg_m(int unused)
{
  ;
}

/* ---- stl_fxScheduledList_nop_m  0x00498380 ----  [HIGH] */
void stl_fxScheduledList_nop_m()
{
  ;
}

/* ---- stl_fxScheduledList_nodeDeallocate_m  0x00498390 ----  VERIFIED */
void __fastcall stl_fxScheduledList_nodeDeallocate_m(void *block,FxNodeAllocatorReference allocator,FxNodeAllocationCount count)
{
  j__free(block);
}

/* ---- FX_UnusedStub3  0x004983A0 ----  [HIGH] */
/* retail 0x004983A0, IDA nullsub_43: bare retn 8, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void __stdcall FX_UnusedStub3(int a1, int a2)
{
  ;
}

/* ---- stl_fxScheduledList_constIterCtor_m  0x004983B0 ----  [HIGH] */
unsigned int *__cdecl stl_fxScheduledList_constIterCtor_m(unsigned int *result, int node)
{
  *result = node;
  return result;
}

/* ---- stl_fxScheduledList_iterEqual_m  0x004983C0 ----  [HIGH] */
int __cdecl stl_fxScheduledList_iterEqual_m(unsigned int *left, unsigned int *right)
{
  return *right == *left;
}

/* ---- stl_fxScheduledList_iterMynode_m  0x004983D0 ----  [HIGH] */
int __cdecl stl_fxScheduledList_iterMynode_m(int iter)
{
  return *(unsigned int *)iter;
}

/* ---- stl_fxScheduledList_iterCtor_m  0x004983E0 ----  [HIGH] */
unsigned int *__cdecl stl_fxScheduledList_iterCtor_m(unsigned int *result, int node)
{
  *result = node;
  return result;
}

/* ---- stl_fxIntVector_iterDeref_dup_m  0x004983F0 ----  [HIGH] */
int __cdecl stl_fxIntVector_iterDeref_dup_m(int iter)
{
  return *(unsigned int *)iter;
}

/* ---- stl_fxIntVector_iterAdd_dup_m  0x00498400 ----  [HIGH] */
unsigned int *__fastcall stl_fxIntVector_iterAdd_dup_m(unsigned int *result, unsigned int *iter, int offset)
{
  *result = *iter + 4 * offset;
  return result;
}

/* ---- stl_fxString_assignPtrCount_m  0x00498410 ----  VERIFIED */
int __fastcall stl_fxString_assignPtrCount_m(int self, FxConstCharPointerArgument pointerArg, FxSizeArgument countArg)
{
  const char *ptr=pointerArg.pointer;
  unsigned int count=countArg.count;
  unsigned char *data;
  unsigned char *dst;

  FX_STANDARD_CALL(stl_fxString_assignPtrCount_m);
  data = FXS_PTR( self );
  if ( (const char *)data <= ptr )
  {
    data = FXS_PTR( self );
    if ( ptr < (const char *)( data + FXS_SIZE( self ) ) )
      return stl_fxString_assignSubstr_m( self, self, (unsigned int)( ptr - (const char *)FXS_PTR( self ) ),
                         count );
  }

  if ( stl_fxString_grow_m( self, count, 1 ) )
  {
    memcpy( FXS_PTR( self ), ptr, count );
    FXS_SIZE( self ) = count;
    dst = FXS_PTR( self );
    dst[count] = 0;
  }
  return self;
}

/* ---- stl_fxString_erase_m  0x004984B0 ----  VERIFIED */
int FxString::Erase( unsigned int off, unsigned int count )
{
  unsigned int newsize;

  (void)&FxString::Erase;   /* keeps the declared __thiscall under LTCG */
  if ( size < off )
    ( (const std::_String_base *)this )->_Xran();   /* off off end */
  if ( size - off < count )
    count = size - off;   /* trim count */
  if ( 0 < count )
  {
    /* move elements down (_Traits::move: retail 0x00498500 calls the CRT memmove) */
    memmove( ( 16 <= capacity ? bx.ptr : (char *)&bx ) + off,
             ( 16 <= capacity ? bx.ptr : (char *)&bx ) + off + count, size - off - count );
    newsize = size - count;
    if ( Grow( newsize, false ) )
    {
      size = newsize;   /* _Eos(newsize): _Myptr()[_Mysize = newsize] = 0 */
      ( 16 <= capacity ? bx.ptr : (char *)&bx )[newsize] = 0;
    }
  }
  return (int)this;
}

/* ---- stl_fxString_eos_m  0x00498570 ----  VERIFIED */
/* basic_string::_Eos(newsize): set the logical length and re-terminate.
 * Inline; this is its out-of-line (__thiscall) copy. */
inline void FxString::Eos( unsigned int newsize )
{
  (void)&FxString::Eos;   /* keeps the out-of-line copy __thiscall */
  ( (char *)Myptr() )[size = newsize] = 0;   /* _Traits::assign(_Myptr()[_Mysize = newsize], _Elem()) */
}

/* ---- stl_fxString_grow_m  0x00498590 ----  VERIFIED */
bool FxString::Grow( unsigned int n, bool trim )
{
  int self = (int)this;

  (void)&FxString::Grow;   /* keeps the declared __thiscall under LTCG */
  if ( 0xFFFFFFFE < n )
    ( (const std::_String_base *)this )->_Xlen();  /* retail 0x00498596: _Xlen() */
  if ( capacity < n )
    Copy( n, trim ? 0 : size );   /* reallocate to grow */
  else if ( trim && n < 16 )
    Tidy( true );   /* deallocate if assigning small string */
  else if ( n == 0 )
    Eos( 0 );   /* new size is zero, just null terminate */
  return (0 < n);   /* true only if more work to do */
}

/* ---- stl_fxString_myptr_m  0x00498660 ----  IMPLEMENTED (retail) */
/* std::string::_Myptr(): the inline SSO buffer, or the heap buffer once
 * capacity >= 16 -- the same body as stl_fxString_myptrConst_m.  Retail __thiscall;
 * stl_fxEffectIdMap_eraseNode_m's key _Tidy(true) calls it. */
__declspec(noinline) char *__fastcall stl_fxString_myptr_m(unsigned int *self)
{
  FX_STANDARD_CALL(stl_fxString_myptr_m);
  if(FXS_RES(self)>=16) return *(char **)FXS_BX(self);
  return (char *)FXS_BX(self);
}

/* ---- stl_fxString_deallocate_m  0x00498670 ----  VERIFIED */
void __stdcall stl_fxString_deallocate_m(FxDeallocatePointer blockArg,FxNodeAllocationCount count)
{
  void *Block=blockArg.pointer;
  j__free(Block);
}

/* ---- FX_UnusedStub4  0x00498680 ----  [HIGH] */
/* retail 0x00498680, IDA nullsub_44: bare retn 0Ch, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void __stdcall FX_UnusedStub4(int a1, int a2, int a3)
{
  ;
}

/* ---- stl_fxIntVector_insertN_m  0x00498690 ----  VERIFIED */
/* vector<int>::_Insert_n(where, count, val), as <vector> writes it.  The
 * reallocating path's _Ucopy calls are inlined (straight _Uninit_copy calls);
 * the other two paths call _Ucopy. */
void FxIntVector::InsertN( FxVecIter where, unsigned int count, const unsigned int &val )
{
  unsigned int       tmp      = val;   /* in case val is in the sequence */
  unsigned int capacity = myfirst == 0 ? 0 : (unsigned int)( myend - myfirst );
  FxScalarPointerTag      scalar;
  FxIntAllocatorReference al;   /* this->_Alval */

  (void)&FxIntVector::InsertN;   /* keeps the declared __thiscall under LTCG */
  al.pointer = this;
  if ( count == 0 )
    ;
  else if ( 0x3FFFFFFF - ( myfirst == 0 ? 0 : (unsigned int)( mylast - myfirst ) ) < count )
    stl_fxIntVector_xlen_m( (int)this );   /* result too long */
  else if ( capacity < ( myfirst == 0 ? 0 : (unsigned int)( mylast - myfirst ) ) + count )
  {
    /* not enough room: reallocate, trying to grow by 50% */
    unsigned int *newvec;
    unsigned int *ptr;

    capacity = 0x3FFFFFFF - capacity / 2 < capacity ? 0 : capacity + capacity / 2;
    if ( capacity < ( myfirst == 0 ? 0 : (unsigned int)( mylast - myfirst ) ) + count )
      capacity = ( myfirst == 0 ? 0 : (unsigned int)( mylast - myfirst ) ) + count;
    newvec = (unsigned int *)crt_operator_new( capacity * 4 );   /* allocator<int>::allocate */
    ptr    = newvec;
    try
    {
      ptr = UcopyConst( this, FxVecIter( myfirst ), where, newvec );   /* copy prefix */
      stl_fxIntVector_uninitFillN_m( ptr, count, &tmp, al, scalar );   /* add new stuff */
      ptr += count;
      UcopyConst( this, where, FxVecIter( mylast ), ptr );   /* copy suffix */
    }
    catch ( ... )
    {
      stl_fxIntVector_nop3_m( (int)newvec, (int)ptr );   /* _Destroy: nothing for int */
      operator delete( newvec );   /* deallocate */
      throw;
    }

    count += myfirst == 0 ? 0 : (unsigned int)( mylast - myfirst );
    if ( myfirst != 0 )
      operator delete( myfirst );   /* destroy and deallocate the old array */
    myend   = (unsigned int *)( (char *)newvec + capacity * 4 );
    mylast  = newvec + count;
    myfirst = newvec;
  }
  else if ( (unsigned int)( mylast - where.ptr ) < count )
  {
    /* new stuff spills off the end */
    Ucopy( where, FxVecIter( mylast ), where.ptr + count );   /* copy suffix */
    try
    {
      stl_fxIntVector_uninitFillN_m( mylast, count - (unsigned int)( mylast - where.ptr ), &tmp,
                                     al, scalar );   /* insert new stuff off end */
    }
    catch ( ... )
    {
      stl_fxIntVector_nop3_m( (int)( where.ptr + count ), (int)( mylast + count ) );   /* _Destroy: nothing for int */
      throw;
    }
    mylast += count;
    stl_fxIntVector_fill_m( &tmp, where, FxVecIter( mylast - count ) );   /* insert up to old end */
  }
  else
  {
    /* new stuff can all be assigned */
    unsigned int *oldend = mylast;

    mylast = Ucopy( FxVecIter( oldend - count ), FxVecIter( oldend ), mylast );   /* copy suffix */
    stl_fxIntVector_copyBackward_m( where, FxVecIter( oldend - count ), FxVecIter( oldend ) );   /* copy hole */
    stl_fxIntVector_fill_m( &tmp, where, FxVecIter( where.ptr + count ) );   /* insert into hole */
  }
}

/* ---- stl_fxIntVector_deallocate_m  0x00498930 ----  VERIFIED */
void __fastcall stl_fxIntVector_deallocate_m(void *block,FxNodeAllocatorReference allocator,FxNodeAllocationCount count)
{
  j__free(block);
}

/* ---- stl_fxIntVector_iterCtor_m  0x00498940 ----  [HIGH] */
unsigned int *__cdecl stl_fxIntVector_iterCtor_m(unsigned int *result, int node)
{
  *result = node;
  return result;
}

/* ---- stl_fxIntVector_iterCopy_m  0x00498950 ----  [HIGH] */
unsigned int *__cdecl stl_fxIntVector_iterCopy_m(unsigned int *result, unsigned int *right)
{
  *result = *right;
  return result;
}

/* ---- stl_fxIntVector_iterDiff_m  0x00498960 ----  [HIGH] */
int __cdecl stl_fxIntVector_iterDiff_m(unsigned int *left, unsigned int *right)
{
  return (int)(*left - *right) >> 2;
}

/* ---- stl_fxEffectIdMap_isnil_m  0x00498970 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_isnil_m(int node)
{
  return node + 45;
}

/* ---- stl_fxEffectIdMap_left_m  0x00498980 ----  [HIGH] */
void stl_fxEffectIdMap_left_m()
{
  ;
}

/* ---- stl_fxEffectIdMap_parent_m  0x00498990 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_parent_m(int node)
{
  return node + 4;
}

/* ---- stl_fxEffectIdMap_right_m  0x004989A0 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_right_m(int node)
{
  return node + 8;
}

/* ---- stl_fxEffectIdMap_eraseRange_m  0x004989B0 ----  IMPLEMENTED (retail) */
/* std::_Tree::erase(first, last) for the map<string, int> the scheduler keys
 * effect ids by (retail CStringEdPackage_Destruct also calls this same
 * instantiation for its +0x98 map).  Retail is __userpurge: this@<esi>, then
 * (result, first, last) on the stack, retn 0Ch; returns `result`.
 * [begin, end) takes the inlined clear(): _Erase the root, then point the
 * head's parent/left/right back at itself and zero _Mysize.  Anything else
 * is erase(first++) one node at a time. */
int **__fastcall stl_fxEffectIdMap_eraseRange_m(int tree,FxMapIteratorValue resultArg,FxMapIteratorValue firstArg,FxMapIteratorValue lastArg)
{
  int **result;
  unsigned char *head;
  int           *where;

  head = FXT_HEAD( tree );
  if ( (int *)firstArg.pointer == (int *)FXN_LEFT( head ) && (int *)lastArg.pointer == (int *)head )
  {
    stl_fxEffectIdMap_eraseSubtree_m((void *)tree,FxMapRootArgument((void **)FXN_PARENT(head)));    /* free every node */
    FXN_PARENT( FXT_HEAD( tree ) ) = FXT_HEAD( tree );
    FXT_SIZE( tree )               = 0;
    FXN_LEFT( FXT_HEAD( tree ) )   = FXT_HEAD( tree );
    FXN_RIGHT( FXT_HEAD( tree ) )  = FXT_HEAD( tree );
    result = (int **)resultArg.pointer;
    *result = (int *)FXN_LEFT( FXT_HEAD( tree ) );  /* begin() */
    return result;
  }

  /* while (_First != _Last) erase(_First++): the iterator parameter itself advances */
  result = (int **)resultArg.pointer;
  while ( (int *)firstArg.pointer != (int *)lastArg.pointer )
  {
    where = (int *)firstArg.pointer;
    stl_fxEffectIdMap_iterInc_m( (int **)&firstArg.pointer );   /* ++first; ECX is unused */
    /* erase(_First++)'s own returned iterator is discarded; retail builds that
     * temporary in the result-pointer argument's slot (the pointer itself is
     * held in a register by then) */
    stl_fxEffectIdMap_eraseNode_m( tree, (int **)&resultArg.pointer, where );
  }
  *result = (int *)firstArg.pointer;
  return result;
}

/* ---- stl_fxEffectIdMap_init_m  0x00498A30 ----  VERIFIED */
void __cdecl stl_fxEffectIdMap_init_m( int tree )
{
  unsigned char *head;

  /* std::_Tree init: allocate the sentinel head and point it at itself. */
  head = (unsigned char *)stl_fxEffectIdMap_buynodeHead_m( tree );
  FXT_HEAD( tree )   = head;
  FXN_ISNIL ( head ) = 1;
  head=FXT_HEAD(tree);
  FXN_PARENT( head ) = head;   /* head->parent = head (root, empty)  */
  head=FXT_HEAD(tree);
  FXN_LEFT  ( head ) = head;   /* head->left   = head (leftmost)     */
  head=FXT_HEAD(tree);
  FXN_RIGHT ( head ) = head;   /* head->right  = head (rightmost)    */
  FXT_SIZE( tree ) = 0;

}

/* ---- stl_fxEffectIdMap_insertRebalance_m  0x00498A60 ----  VERIFIED */
int __fastcall stl_fxEffectIdMap_insertRebalance_m(int tree,int wherenode,FxRebalanceResult resultArg,unsigned char directionArg,FxRebalanceValue valueArg)
{
  void ***result=resultArg.pointer;
  char addleft=FxRebalanceDirection(directionArg).value;
  int val=valueArg.value;
  unsigned char *head  = FXT_HEAD( tree );
  unsigned char *where = (unsigned char *)wherenode;
  unsigned char *node;
  unsigned char *cur, *parent, *grand, *uncle;

  /* retail 0x00498A7B: max_size() - 1 <= size() -> throw length_error */
  if ( FXT_SIZE( tree ) >= 0x7FFFFFE )
    throw std::length_error( FxStdString( "map/set<T> too long" ) );

  head=FXT_HEAD(tree);
  node = (unsigned char *)stl_fxEffectIdMap_buynode_m( tree, (int)head, (int)where, (int)head,
                                      val, FX_RED );
  FXT_SIZE( tree )++;

  head = FXT_HEAD( tree );
  if ( where == head )
  {
    FXN_PARENT( head ) = node;
    FXN_LEFT  ( FXT_HEAD( tree ) ) = node;
    FXN_RIGHT ( FXT_HEAD( tree ) ) = node;
  }
  else if ( addleft )
  {
    FXN_LEFT( where ) = node;
    head = FXT_HEAD( tree );
    if ( where == FXN_LEFT( head ) )
      FXN_LEFT( head ) = node;
  }
  else
  {
    FXN_RIGHT( where ) = node;
    head = FXT_HEAD( tree );
    if ( where == FXN_RIGHT( head ) )
      FXN_RIGHT( head ) = node;
  }

  cur = node;
  while ( FXN_COLOR( FXN_PARENT( cur ) ) == FX_RED )
  {
    parent = FXN_PARENT( cur );
    grand  = FXN_PARENT( parent );

    if ( parent == FXN_LEFT( grand ) )
    {
      uncle = FXN_RIGHT( grand );
      if ( FXN_COLOR( uncle ) == FX_RED )
      {
        FXN_COLOR( parent ) = FX_BLACK;
        FXN_COLOR( uncle )  = FX_BLACK;
        FXN_COLOR( FXN_PARENT( FXN_PARENT( cur ) ) ) = FX_RED;
        cur = FXN_PARENT( FXN_PARENT( cur ) );
      }
      else
      {
        if ( cur == FXN_RIGHT( parent ) )
        {
          cur = parent;
          stl_fxEffectIdMap_lrotate_m( (int)cur, tree );
        }
        FXN_COLOR( FXN_PARENT( cur ) ) = FX_BLACK;
        FXN_COLOR( FXN_PARENT( FXN_PARENT( cur ) ) ) = FX_RED;
        stl_fxEffectIdMap_rrotate_m( (int)FXN_PARENT( FXN_PARENT( cur ) ), tree );
      }
    }
    else
    {
      uncle = FXN_LEFT( grand );
      if ( FXN_COLOR( uncle ) == FX_RED )
      {
        FXN_COLOR( parent ) = FX_BLACK;
        FXN_COLOR( uncle )  = FX_BLACK;
        FXN_COLOR( FXN_PARENT( FXN_PARENT( cur ) ) ) = FX_RED;
        cur = FXN_PARENT( FXN_PARENT( cur ) );
      }
      else
      {
        if ( cur == FXN_LEFT( parent ) )
        {
          cur = parent;
          stl_fxEffectIdMap_rrotate_m( (int)cur, tree );
        }
        FXN_COLOR( FXN_PARENT( cur ) ) = FX_BLACK;
        FXN_COLOR( FXN_PARENT( FXN_PARENT( cur ) ) ) = FX_RED;
        stl_fxEffectIdMap_lrotate_m( (int)FXN_PARENT( FXN_PARENT( cur ) ), tree );
      }
    }
  }

  FXN_COLOR( FXN_PARENT( FXT_HEAD( tree ) ) ) = FX_BLACK;
  *(int *)result = (int)node;
  return (int)result;
}

/* ---- stl_fxEffectIdMap_lbound_m  0x00498C30 ----  VERIFIED */
int __fastcall stl_fxEffectIdMap_lbound_m(int tree,const void *keyObject)
{
  int key=(int)keyObject;
  unsigned char *node  = FXN_PARENT( FXT_HEAD( tree ) );
  unsigned char *where = FXT_HEAD( tree );

  while ( !FXN_ISNIL( node ) )
  {
    if ( stl_fxStringLess_opCall_m( (int)FXN_KEY( node ), key, 0 ) )   /* comp(_Key(node), key) */
    {
      node = FXN_RIGHT( node );
    }
    else
    {
      where = node;
      node  = FXN_LEFT( node );
    }
  }
  return (int)where;
}

/* ---- stl_fxEffectIdMap_min_m  0x00498CD0 ----  VERIFIED */
unsigned int *__cdecl stl_fxEffectIdMap_min_m( unsigned int *node )
{
  /* std::_Tree _Min: walk left links until the nil sentinel. */
  while ( !FXN_ISNIL( FXN_LEFT( node ) ) )
    node = (unsigned int *)FXN_LEFT( node );
  return node;
}

/* ---- stl_fxEffectIdMap_treeBaseCtor_m  0x00498CF0 ----  [HIGH] */
byte *__fastcall stl_fxEffectIdMap_treeBaseCtor_m(byte *result, byte *allocator, int unused)
{
  *result = *allocator;
  return result;
}

/* ---- FX_UnusedStub5  0x00498D00 ----  [HIGH] */
/* retail 0x00498D00, IDA nullsub_46: bare retn, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void FX_UnusedStub5()
{
  ;
}

/* ---- FX_UnusedStub6  0x00498D10 ----  [HIGH] */
/* retail 0x00498D10, IDA nullsub_47: bare retn 4, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void __stdcall FX_UnusedStub6(int a1)
{
  ;
}

/* ---- stl_fxEffectIdMap_alnodDeallocate_m  0x00498D20 ----  VERIFIED */
void __fastcall stl_fxEffectIdMap_alnodDeallocate_m(void *block,FxNodeAllocatorReference allocator,FxNodeAllocationCount count)
{
  j__free(block);
}

/* ---- stl_fxEffectIdMap_alnodDestroy_m  0x00498D30 ----  VERIFIED */
void __fastcall stl_fxEffectIdMap_alnodDestroy_m(int node,FxNodeAllocatorReference allocator)
{
  stl_fxEffectIdMap_nodeDtor_m(node);
}

/* ---- stl_fxEffectIdMap_alptrDestroy_m  0x00498D40 ----  [HIGH] */
void __stdcall stl_fxEffectIdMap_alptrDestroy_m(int unused1, int unused2)
{
  ;
}

/* ---- stl_fxEffectIdMap_iterPredec_m  0x00498D50 ----  VERIFIED */
int **__fastcall stl_fxEffectIdMap_iterPredec_m(int **iter)
{
  stl_fxEffectIdMap_iterDec_m(iter);
  return iter;
}

/* ---- stl_fxScheduledList_eraseRange_m  0x00498D60 ----  IMPLEMENTED (retail) */
/* std::list<int>::erase(first, last) for the scheduled-effect list: unlink
 * and free each node in [first, last) and decrement _Mysize per node, never
 * touching the head sentinel.  Node (12 bytes, stl_fxScheduledList_buynodeVal_m): _Next +0,
 * _Prev +4, value +8, a plain pointer with nothing to destroy.  Retail is
 * __userpurge: this@<edi>, then (result, first, last) on the stack,
 * retn 0Ch; stores the exit iterator (== last) in *result and returns
 * result. */
FxListIter __fastcall stl_fxScheduledList_eraseRange_m(int list,FxListIteratorArgument firstArg,FxListIteratorArgument lastArg)
{
  unsigned int*first=firstArg.node;
  unsigned int*last=lastArg.node;
  unsigned int *node;

  while ( first != last )
  {
    node  = first;
    first = (unsigned int *)node[0];                       
    if ( node != *(unsigned int **)( list + FX_LIST_OFS( _Myhead ) ) )          
    {
      *(unsigned int *)node[1]         = node[0];          
      ( (unsigned int *)node[0] )[1]   = node[1];          
      j__free( node );
      --*(unsigned int *)( list + FX_LIST_OFS( _Mysize ) );                     
    }
  }
  return FxListIter( (unsigned int *)first );
}

/* ---- stl_fxScheduledList_buynodeVal_m  0x00498DB0 ----  VERIFIED */
/* list::_Buynode(next, prev, val) and _Incsize keep their own frames in retail
 * (their C++ bodies carry try/catch and a throw), so they stay out of line. */
__declspec(noinline) unsigned int *__stdcall stl_fxScheduledList_buynodeVal_m( int list, int next, int prev, unsigned int *val )
{
  unsigned int *p;

  (void)list;
  p = (unsigned int *)crt_operator_new( 0xC );
  if ( p )
  {
    p[0] = (unsigned int)next;
    p[1] = (unsigned int)prev;
    p[2] = *val;
  }
  return p;
}

/* ---- stl_fxScheduledList_incsize_m  0x00498DE0 ----  VERIFIED */
#ifdef __cplusplus
__declspec(noinline) int FxScheduledList::Incsize( unsigned int n )
#else
__declspec(noinline) int __fastcall stl_fxScheduledList_incsize_m( unsigned int n, int list )
#endif
{
#ifdef __cplusplus
  int list = (int)this;
#endif
  unsigned int size;


  size = *(unsigned int *)( list + FX_LIST_OFS( _Mysize ) );
  if ( 0x3FFFFFFF - size < n )
  {
    throw std::length_error( FxStdString( "list<T> too long" ) );
  }
  *(unsigned int *)( list + FX_LIST_OFS( _Mysize ) ) = size + n;
  return (int)( size + n );
}

/* ---- FX_UnusedStub7  0x00498E80 ----  [HIGH] */
/* retail 0x00498E80, IDA nullsub_49: bare retn 4, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void __stdcall FX_UnusedStub7(int a1)
{
  ;
}

/* ---- FX_UnusedStub8  0x00498E90 ----  [HIGH] */
/* retail 0x00498E90, IDA nullsub_50: bare retn 4, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void __stdcall FX_UnusedStub8(int a1)
{
  ;
}

/* ---- stl_fxScheduledList_nodeAllocate_m  0x00498EA0 ----  IMPLEMENTED (retail) */
/* std::allocator<list node>::allocate(count, hint): operator new(count * 12)
 * for the 12-byte std::list<int> node (cf. stl_fxScheduledList_buynodeVal_m).  Retail is
 * __userpurge with count@eax and two stack dwords it never reads, retn 8;
 * operator new is the file's malloc. */
/* __stdcall: LTCG takes count in eax and leaves the two unread dwords on
 * the stack for the callee to pop, as in retail. */
void *__stdcall stl_fxScheduledList_nodeAllocate_m( unsigned int count, int unused1, int unused2 )
{
  (void)unused1;
  (void)unused2;
  return crt_operator_new( count * 12 );
}

/* ---- stl_fxScheduledList_ptrConstruct_m  0x00498EC0 ----  VERIFIED */
unsigned int *__fastcall stl_fxScheduledList_ptrConstruct_m(unsigned int *result, unsigned int *value, int unused)
{
  if ( result )
    *result = *value;
  return result;
}

/* ---- FX_UnusedStub9  0x00498ED0 ----  [HIGH] */
/* retail 0x00498ED0, IDA nullsub_51: bare retn 8, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void __stdcall FX_UnusedStub9(int a1, int a2)
{
  ;
}

/* ---- stl_fxEffectIdMap_iterCtor_m  0x00498EE0 ----  [HIGH] */
unsigned int *__cdecl stl_fxEffectIdMap_iterCtor_m(unsigned int *result, int node)
{
  *result = node;
  return result;
}

/* ---- stl_fxEffectIdMap_pairIterBool_m  0x00498EF0 ----  [HIGH] */
int __fastcall stl_fxEffectIdMap_pairIterBool_m(int result, unsigned int *iter, byte *inserted)
{
  *(unsigned int *)result = *iter;
  *(byte *)(result + 4) = *inserted;
  return result;
}

/* ---- stl_fxString_maxSize_m  0x00498F00 ----  [HIGH] */
int stl_fxString_maxSize_m()
{
  return -2;
}

/* ---- stl_fxString_copy_m  0x00498F10 ----  VERIFIED */
void FxString::Copy( unsigned int n, unsigned int oldlen )
{
  unsigned int newres = n | 15;   /* _Newsize | _ALLOC_MASK */
  char        *ptr;

  (void)&FxString::Copy;   /* keeps the declared __thiscall under LTCG */
  if ( 0xFFFFFFFE < newres )
    newres = n;   /* undo roundup if too big */
  try
  {
    ptr = (char *)crt_operator_new( newres + 1 );
  }
  catch ( ... )
  {
    newres = n;   /* allocation failed, undo roundup and retry */
    try
    {
      ptr = (char *)crt_operator_new( newres + 1 );
    }
    catch ( ... )
    {
      Tidy( true );   /* failed again, discard storage and reraise */
      throw;
    }
  }

  if ( 0 < oldlen )
    memcpy( ptr, (char *)Myptr(), oldlen );   /* copy existing elements */
  Tidy( true );
  bx.ptr   = ptr;
  capacity = newres;
  Eos( oldlen );
}

/* ---- stl_fxString_inside_m  0x00499030 ----  VERIFIED */
int __fastcall stl_fxString_inside_m(unsigned int *self,FxInsidePointer ptrArg)
{
  unsigned char *base,*end;
  unsigned int capacity=FXS_RES(self);
  const unsigned char *ptr=ptrArg.pointer;
  FX_STANDARD_CALL(stl_fxString_inside_m);
  if(capacity>=16)base=*(unsigned char **)((unsigned char *)self+4);
  else base=(unsigned char *)self+4;
  if(base<=ptr){
    if(capacity>=16)end=*(unsigned char **)((unsigned char *)self+4);
    else end=(unsigned char *)self+4;
    if(ptr<end+FXS_SIZE(self))return 1;
  }
  return 0;
}

/* ---- stl_fxIntVector_maxSize_m  0x00499070 ----  [HIGH] */
int __stdcall stl_fxIntVector_maxSize_m(int unused)
{
  return 0x3FFFFFFF;
}

/* ---- stl_fxIntVector_xlen_m  0x00499080 ----  IMPLEMENTED (retail) */
/* std::vector<T>::_Xlen(): throws length_error("vector<T> too long") and
 * never returns.  Both retail callers (stl_fxIntVector_insertN_m, stl_fxIntVector_buy_m) push the
 * vector first; nothing reads it.  The string temporary gives it its EH frame. */
__declspec(noinline) void __stdcall stl_fxIntVector_xlen_m( int vec )
{
  (void)vec;
  throw std::length_error( FxStdString( "vector<T> too long" ) );
}

/* ---- stl_fxIntVector_allocate_m  0x00499100 ----  IMPLEMENTED (retail) */
/* std::allocator<int>::allocate(count, hint): operator new(count * 4) for a
 * vector<int> buffer.  Retail is __userpurge with count@eax and two stack
 * dwords it never reads, retn 8. */
/* __stdcall: LTCG takes count in eax and leaves the two unread dwords on
 * the stack for the callee to pop, as in retail. */
void *__stdcall stl_fxIntVector_allocate_m( unsigned int count, int unused1, int unused2 )
{
  (void)unused1;
  (void)unused2;
  return crt_operator_new( count * 4 );
}

/* ---- FX_UnusedGetField0  0x00499120 ----  [HIGH] */
/* retail 0x00499120, IDA sub_499120: mov eax,[eax]; retn (a1@eax), no xrefs; between int-vector STL copies (an iterator operator* shape, unproven): descriptive name. */
int __cdecl FX_UnusedGetField0(int a1)
{
  return *(unsigned int *)a1;
}

/* ---- stl_fxIntVector_iterSub_m  0x00499130 ----  [HIGH] */
unsigned int *__fastcall stl_fxIntVector_iterSub_m(unsigned int *result, int offset, unsigned int *iter)
{
  *result = *iter - 4 * offset;
  return result;
}

/* ---- stl_fxEffectIdMap_color_m  0x00499150 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_color_m(int node)
{
  return node + 44;
}

/* ---- stl_fxEffectIdMap_maxSize_m  0x00499160 ----  [HIGH] */
int __stdcall stl_fxEffectIdMap_maxSize_m(int unused)
{
  return 0x7FFFFFF;
}

/* ---- stl_fxEffectIdMap_eraseNode_m  0x00499170 ----  IMPLEMENTED (retail) */
/* std::_Tree::erase(iterator) for the effect-id map<string, int> (the
 * dependency of stl_fxEffectIdMap_eraseRange_m's partial-range path).  Unlinks `where` (lifting
 * its in-order successor when it has two children), rebalances the
 * red-black tree, destroys the key string, frees the node, decrements
 * _Mysize if nonzero and returns the successor.  Retail is __thiscall with
 * an ECX that is only forwarded to _Inc, then (this, result, where) on the
 * stack, retn 0Ch.  Erasing the head throws out_of_range("invalid
 * map/set<T> iterator").  Rotations: stl_fxEffectIdMap_lrotate_m _Lrotate, stl_fxEffectIdMap_rrotate_m _Rrotate;
 * stl_fxEffectIdMap_min_m _Min, stl_fxEffectIdMap_max_m _Max. */
int **__stdcall stl_fxEffectIdMap_eraseNode_m( int tree, int **result, int *where )
{
  unsigned char *erased;      /* _Erasednode */
  unsigned char *pnode;       /* _Pnode */
  unsigned char *fix;         /* _Fixnode: the node to recolor */
  unsigned char *fixParent;   /* _Fixnodeparent (fix may be nil) */
  unsigned char *head;
  unsigned char *key;
  unsigned char  color;

  if ( FXN_ISNIL( where ) )
    throw std::out_of_range( FxStdString( "invalid map/set<T> iterator" ) );

  erased = (unsigned char *)where;
  pnode  = erased;
  stl_fxEffectIdMap_iterInc_m(&where );                 /* ++where: the successor returned */

  if ( FXN_ISNIL( FXN_LEFT( pnode ) ) )
    fix = FXN_RIGHT( pnode );              /* stitch up the right subtree */
  else if ( FXN_ISNIL( FXN_RIGHT( pnode ) ) )
    fix = FXN_LEFT( pnode );               /* stitch up the left subtree */
  else
  {
    pnode = (unsigned char *)where;        /* two subtrees: lift the successor */
    fix   = FXN_RIGHT( pnode );
  }

  if ( pnode == erased )
  {
    /* at most one subtree: relink it in place of the erased node */
    fixParent = FXN_PARENT( erased );
    if ( !FXN_ISNIL( fix ) )
      FXN_PARENT( fix ) = fixParent;

    head = FXT_HEAD( tree );
    if ( FXN_PARENT( head ) == erased )
      FXN_PARENT( head ) = fix;
    else if ( FXN_LEFT( fixParent ) == erased )
      FXN_LEFT( fixParent ) = fix;
    else
      FXN_RIGHT( fixParent ) = fix;

    if ( FXN_LEFT( FXT_HEAD( tree ) ) == erased )
      FXN_LEFT( FXT_HEAD( tree ) ) =
        FXN_ISNIL( fix ) ? fixParent : (unsigned char *)stl_fxEffectIdMap_min_m( (unsigned int *)fix );

    if ( FXN_RIGHT( FXT_HEAD( tree ) ) == erased )
      FXN_RIGHT( FXT_HEAD( tree ) ) =
        FXN_ISNIL( fix ) ? fixParent : (unsigned char *)stl_fxEffectIdMap_max_m( (int)fix );
  }
  else
  {
    /* two subtrees: pnode (the successor) takes the erased node's place */
    FXN_PARENT( FXN_LEFT( erased ) ) = pnode;
    FXN_LEFT( pnode )                = FXN_LEFT( erased );

    if ( pnode == FXN_RIGHT( erased ) )
      fixParent = pnode;
    else
    {
      fixParent = FXN_PARENT( pnode );
      if ( !FXN_ISNIL( fix ) )
        FXN_PARENT( fix ) = fixParent;
      FXN_LEFT( fixParent )             = fix;
      FXN_RIGHT( pnode )                = FXN_RIGHT( erased );
      FXN_PARENT( FXN_RIGHT( erased ) ) = pnode;
    }

    head = FXT_HEAD( tree );
    if ( FXN_PARENT( head ) == erased )
      FXN_PARENT( head ) = pnode;
    else if ( FXN_LEFT( FXN_PARENT( erased ) ) == erased )
      FXN_LEFT( FXN_PARENT( erased ) ) = pnode;
    else
      FXN_RIGHT( FXN_PARENT( erased ) ) = pnode;

    FXN_PARENT( pnode ) = FXN_PARENT( erased );
    stl_fxChar_swap_m( (char *)&FXN_COLOR( erased ), (char *)&FXN_COLOR( pnode ) );   /* std::swap(_Color(_Pnode), _Color(_Erasednode)): recolor it */
  }

  if ( FXN_COLOR( erased ) == FX_BLACK )
  {
    /* erased a black link: recolor / rebalance up from fix */
    for ( ; fix != FXN_PARENT( FXT_HEAD( tree ) ) && FXN_COLOR( fix ) == FX_BLACK;
          fixParent = FXN_PARENT( fix ) )
    {
      if ( fix == FXN_LEFT( fixParent ) )
      {
        pnode = FXN_RIGHT( fixParent );
        if ( FXN_COLOR( pnode ) == FX_RED )
        {
          FXN_COLOR( pnode )     = FX_BLACK;
          FXN_COLOR( fixParent ) = FX_RED;
          stl_fxEffectIdMap_lrotate_m( (int)fixParent, tree );
          pnode = FXN_RIGHT( fixParent );
        }

        if ( FXN_ISNIL( pnode ) )
          fix = fixParent;
        else if ( FXN_COLOR( FXN_LEFT( pnode ) ) == FX_BLACK
               && FXN_COLOR( FXN_RIGHT( pnode ) ) == FX_BLACK )
        {
          FXN_COLOR( pnode ) = FX_RED;
          fix = fixParent;
        }
        else
        {
          if ( FXN_COLOR( FXN_RIGHT( pnode ) ) == FX_BLACK )
          {
            FXN_COLOR( FXN_LEFT( pnode ) ) = FX_BLACK;
            FXN_COLOR( pnode )             = FX_RED;
            stl_fxEffectIdMap_rrotate_m( (int)pnode, tree );
            pnode = FXN_RIGHT( fixParent );
          }
          FXN_COLOR( pnode )              = FXN_COLOR( fixParent );
          FXN_COLOR( fixParent )          = FX_BLACK;
          FXN_COLOR( FXN_RIGHT( pnode ) ) = FX_BLACK;
          stl_fxEffectIdMap_lrotate_m( (int)fixParent, tree );
          break;
        }
      }
      else
      {
        pnode = FXN_LEFT( fixParent );
        if ( FXN_COLOR( pnode ) == FX_RED )
        {
          FXN_COLOR( pnode )     = FX_BLACK;
          FXN_COLOR( fixParent ) = FX_RED;
          stl_fxEffectIdMap_rrotate_m( (int)fixParent, tree );
          pnode = FXN_LEFT( fixParent );
        }

        if ( FXN_ISNIL( pnode ) )
          fix = fixParent;
        else if ( FXN_COLOR( FXN_RIGHT( pnode ) ) == FX_BLACK
               && FXN_COLOR( FXN_LEFT( pnode ) ) == FX_BLACK )
        {
          FXN_COLOR( pnode ) = FX_RED;
          fix = fixParent;
        }
        else
        {
          if ( FXN_COLOR( FXN_LEFT( pnode ) ) == FX_BLACK )
          {
            FXN_COLOR( FXN_RIGHT( pnode ) ) = FX_BLACK;
            FXN_COLOR( pnode )              = FX_RED;
            stl_fxEffectIdMap_lrotate_m( (int)pnode, tree );
            pnode = FXN_LEFT( fixParent );
          }
          FXN_COLOR( pnode )             = FXN_COLOR( fixParent );
          FXN_COLOR( fixParent )         = FX_BLACK;
          FXN_COLOR( FXN_LEFT( pnode ) ) = FX_BLACK;
          stl_fxEffectIdMap_rrotate_m( (int)fixParent, tree );
          break;
        }
      }
    }
    FXN_COLOR( fix ) = FX_BLACK;           /* the stopping node ends black */
  }

  /* destroy the key string (std::string::_Tidy(true); _Myptr and
   * char_traits::assign stay calls here) */
  key = FXN_KEY( erased );
  if ( 16 <= FXS_RES( key ) )
    operator delete( (char *)( (FxString *)key )->Myptr() );   /* _Alval.deallocate(_Myptr(), _Myres + 1) */
  FXS_RES( key ) = 15;
  {
    char nul = 0;   /* _Eos(0): traits::assign(_Myptr()[_Mysize = 0], _Elem()) */
    stl_fxCharTraits_assignChar_m( stl_fxString_myptr_m( (unsigned int *)key ) + ( FXS_SIZE( key ) = 0 ), &nul );
  }
  j__free( erased );

  if ( FXT_SIZE( tree ) > 0 )
    --FXT_SIZE( tree );                    /* don't underflow */

  *result = where;
  return result;
}

/* ---- stl_fxEffectIdMap_lrotate_m  0x00499480 ----  VERIFIED */
__declspec(noinline) int __stdcall stl_fxEffectIdMap_lrotate_m( int node_, int tree )
{
  unsigned char *node = (unsigned char *)node_;
  unsigned char *r    = FXN_RIGHT( node );
  unsigned char *head;

  FXN_RIGHT( node ) = FXN_LEFT( r );
  if ( !FXN_ISNIL( FXN_LEFT( r ) ) )
    FXN_PARENT( FXN_LEFT( r ) ) = node;
  FXN_PARENT( r ) = FXN_PARENT( node );

  head = FXT_HEAD( tree );
  if ( node == FXN_PARENT( head ) )
    FXN_PARENT( head ) = r;
  else if ( node == FXN_LEFT( FXN_PARENT( node ) ) )
    FXN_LEFT( FXN_PARENT( node ) ) = r;
  else
    FXN_RIGHT( FXN_PARENT( node ) ) = r;

  FXN_LEFT( r )      = node;
  FXN_PARENT( node ) = r;
  return (int)r;
}

/* ---- stl_fxEffectIdMap_root2_m  0x004994E0 ----  [HIGH] */
int __cdecl stl_fxEffectIdMap_root2_m(int tree)
{
  return *(unsigned int *)(tree + FX_TREE_OFS( _Myhead )) + 4;
}

/* ---- stl_fxEffectIdMap_rrotate_m  0x004994F0 ----  VERIFIED */
__declspec(noinline) int __stdcall stl_fxEffectIdMap_rrotate_m( int node_, int tree )
{
  unsigned char *node = (unsigned char *)node_;
  unsigned char *l    = FXN_LEFT( node );
  unsigned char *head;

  /* std::_Tree _Rrotate: rotate `node` right over its left child `l`
   * (mirror of stl_fxEffectIdMap_lrotate_m's left rotation). */
  FXN_LEFT( node ) = FXN_RIGHT( l );
  if ( !FXN_ISNIL( FXN_RIGHT( l ) ) )
    FXN_PARENT( FXN_RIGHT( l ) ) = node;
  FXN_PARENT( l ) = FXN_PARENT( node );

  head = FXT_HEAD( tree );
  if ( node == FXN_PARENT( head ) )
    FXN_PARENT( head ) = l;
  else if ( node == FXN_RIGHT( FXN_PARENT( node ) ) )
    FXN_RIGHT( FXN_PARENT( node ) ) = l;
  else
    FXN_LEFT( FXN_PARENT( node ) ) = l;

  FXN_RIGHT( l )     = node;
  FXN_PARENT( node ) = l;
  return (int)l;
}

/* ---- stl_fxEffectIdMap_buynodeHead_m  0x00499550 ----  VERIFIED */
__declspec(noinline) unsigned int *__stdcall stl_fxEffectIdMap_buynodeHead_m( int tree )
{
  unsigned int *p;

  (void)tree;
  p = (unsigned int *)crt_operator_new( 0x30 );
  /* _Alptr.construct(&_Left(p), 0), &_Parent(p), &_Right(p): placement new
   * tests each address for null before the store */
  { unsigned int *slot = &p[0]; if ( slot ) *slot = 0; }
  { unsigned int *slot = &p[1]; if ( slot ) *slot = 0; }
  { unsigned int *slot = &p[2]; if ( slot ) *slot = 0; }
  *( (char *)p + 44 ) = 1;
  *( (char *)p + 45 ) = 0;
  return p;
}

/* ---- stl_fxEffectIdMap_buynode_m  0x00499590 ----  VERIFIED */
int __stdcall stl_fxEffectIdMap_buynode_m( int tree, int left, int parent, int right,
                        int val, char colour )
{
  unsigned char *node;

  (void)tree;

  node = (unsigned char *)crt_operator_new( 0x30 );   /* _Alnod.allocate(1) */
  try
  {
    new ( node ) FxMapNode( left, parent, right, val, colour );
  }
  catch ( ... )
  {
    j__free( node );   /* _Alnod.deallocate */
    throw;
  }
  return (int)node;
}

/* ---- stl_fxEffectIdMap_treePtrCtor_m  0x00499640 ----  [HIGH] */
byte *__fastcall stl_fxEffectIdMap_treePtrCtor_m(byte *result, byte *allocator, int unused)
{
  *result = *allocator;
  return result;
}

__inline void __fastcall stl_fxEffectIdMap_iterDec_m(int **pptr)
{
 int **p=(int **)*pptr;
 int *r,*q;
 if(*((unsigned char *)p+45)){*pptr=(int *)p[2];return;}
 q=(int *)p[0];
 if(!*((unsigned char *)q+45)){
   while(!*((unsigned char *)q[2]+45))q=(int *)q[2];
   *pptr=q;
 }else{
   r=(int *)p[1];
   while(!*((unsigned char *)r+45) && *pptr==(int *)r[0]){*pptr=r;r=(int *)r[1];}
   if(!*((unsigned char *)r+45))*pptr=r;
 }
}

int **__fastcall stl_fxEffectIdMap_iterPostinc_m(int **iter,int **out,FxPostIncrementArgument postfix)
{
 int *cur=*iter;
 (void)postfix;
 stl_fxEffectIdMap_iterPreinc_m(iter);
 *out=cur;return out;
}

/* ---- stl_fxElem4_maxSize_m  0x004996C0 ----  [HIGH] */
int __stdcall stl_fxElem4_maxSize_m(int unused)
{
  return 0x3FFFFFFF;
}

/* ---- FX_UnusedStub10  0x004996D0 ----  [HIGH] */
/* retail 0x004996D0, IDA nullsub_52: bare retn 4, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void __stdcall FX_UnusedStub10(int a1)
{
  ;
}

/* ---- stl_fxScheduledList_nodeCtor_m  0x004996E0 ----  VERIFIED */
unsigned int *__fastcall stl_fxScheduledList_nodeCtor_m(unsigned int *result, int prev, int next, unsigned int *value)
{
  *result = next;
  result[1] = prev;
  result[2] = *value;
  return result;
}

/* ---- stl_fxString_allocate_m  0x00499700 ----  IMPLEMENTED (retail) */
/* std::allocator<char>::allocate(count, hint): operator new(count) for a
 * string buffer.  Retail __stdcall (ECX unused), retn 8; the hint is never
 * read. */
void *__stdcall stl_fxString_allocate_m( size_t Size, int hint )
{
  FX_STANDARD_CALL(stl_fxString_allocate_m);
  (void)hint;
  return crt_operator_new( Size );
}

/* ---- stl_fxCharAllocator_maxSize_m  0x00499710 ----  [HIGH] */
/* allocator<char>::max_size(): size_t(-1) / sizeof(char).  __thiscall, never
 * called (IDA's FLIRT label: std::streambuf::underflow). */
unsigned int __fastcall stl_fxCharAllocator_maxSize_m( void *thisObj )
{
  FX_STANDARD_CALL(stl_fxCharAllocator_maxSize_m);
  (void)thisObj;
  return 0xFFFFFFFF;
}

/* ---- stl_fxElem4_maxSize2_m  0x00499720 ----  [HIGH] */
int __stdcall stl_fxElem4_maxSize2_m(int unused)
{
  return 0x3FFFFFFF;
}

/* ---- stl_fxEffectIdMap_max_m  0x00499730 ----  VERIFIED */
int __cdecl stl_fxEffectIdMap_max_m(int node)
{
  /* std::_Tree _Max: walk right links until the nil sentinel. */
  while ( !FXN_ISNIL( FXN_RIGHT( node ) ) )
    node = (int)FXN_RIGHT( node );
  return node;
}

/* ---- stl_fxEffectIdMap_treeNodCtor_m  0x00499750 ----  [HIGH] */
byte *__fastcall stl_fxEffectIdMap_treeNodCtor_m(byte *result, byte *allocator, int unused)
{
  *result = *allocator;
  return result;
}

/* ---- stl_fxEffectIdMap_alvalMaxSize_m  0x00499760 ----  [HIGH] */
int __stdcall stl_fxEffectIdMap_alvalMaxSize_m(int unused)
{
  return 0x7FFFFFF;
}

/* ---- stl_fxEffectIdMap_alnodAllocate_m  0x00499770 ----  IMPLEMENTED (retail) */
/* std::allocator<map node>::allocate(count, hint): operator new(count * 48)
 * for the 0x30-byte map<string, int> node (cf. stl_fxEffectIdMap_buynodeHead_m).  Retail is
 * __userpurge with count@eax and two stack dwords it never reads, retn 8. */
/* __stdcall: LTCG takes count in eax and leaves the two unread dwords on
 * the stack for the callee to pop, as in retail. */
void *__stdcall stl_fxEffectIdMap_alnodAllocate_m( unsigned int count, int unused1, int unused2 )
{
  (void)unused1;
  (void)unused2;
  return crt_operator_new( count * 48 );
}

/* ---- stl_fxEffectIdMap_nodeCtor_m  0x00499790 ----  VERIFIED */
/* std::map<string,int> red-black node constructor: link the node, then
 * default-construct its embedded key string and copy the key/value in. */
int __stdcall stl_fxEffectIdMap_nodeCtor_m( int left, int right, int parent, int node,
                        int keyPair, char color )
{
  FXN_LEFT( node )   = (unsigned char *)left;
  FXN_PARENT( node ) = (unsigned char *)parent;
  FXN_RIGHT( node )  = (unsigned char *)right;
  ( (FxMapPair *)FXN_KEY( node ) )->Construct( (const FxMapPair *)keyPair );   /* _Myval(val) */
  FXN_COLOR( node )  = color;
  FXN_ISNIL( node )  = 0;
  return node;
}

/* ---- stl_fxEffectIdMap_alptrConstruct_m  0x004997E0 ----  VERIFIED */
unsigned int *__fastcall stl_fxEffectIdMap_alptrConstruct_m( unsigned int *dest, unsigned int *src, int unused )
{
  (void)unused;
  if ( dest )
    *dest = *src;
  return dest;
}

/* ---- stl_fxElem4_maxSize3_m  0x004997F0 ----  [HIGH] */
/* retail 0x004997F0, IDA sub_4997F0: mov eax,3FFFFFFFh; retn 4 = allocator<4-byte T>::max_size ((size_t)-1/4), no xrefs; third copy after stl_fxElem4_maxSize_m / stl_fxElem4_maxSize2_m. */
int __stdcall stl_fxElem4_maxSize3_m( int unused )
{
  (void)unused;
  return 0x3FFFFFFF;
}

/* ---- stl_fxEffectIdMap_pairCopyCtor_m  0x00499800 ----  VERIFIED */
/* std::map key/value pair copy-constructor: default-construct dest's key
 * string, copy src's key into it, then copy the mapped value. */
int __cdecl stl_fxEffectIdMap_pairCopyCtor_m( int src, int dest )
{
  FXS_TIDYINIT( dest );
  stl_fxString_assignSubstr_m( (int)dest, (int)src, 0, 0xFFFFFFFF );
  FXP_MAPPED( dest ) = FXP_MAPPED( src );
  return dest;
}

/* ---- stl_fxEffectIdMap_traitsCtor_m  0x00499830 ----  [HIGH] */
byte *__fastcall stl_fxEffectIdMap_traitsCtor_m( byte *dest, FxStlAllocatorTag value )
{
  *dest = value.value;
  return dest;
}

/* ---- stl_fxIntVector_uninitializedFillN_m  0x00499840 ----  VERIFIED */
void __cdecl stl_fxIntVector_uninitializedFillN_m(void *allocatorObject,unsigned int *value,unsigned int *dest,unsigned int count)
{
  stl_fxIntVector_uninitFillN_m(dest,(unsigned int)(count),value,FxIntAllocator(allocatorObject),FxScalarPointerCategory());
}

/* ---- stl_fxString_operatorLess_m  0x00499860 ----  IMPLEMENTED (retail) */
/* operator<(const string &left, const string &right): the same compare as
 * stl_fxStringLess_opCall_m without its stray stack dword.  Retail is __usercall
 * (right@eax, left@ecx), plain retn. */
FX_BOOL __cdecl stl_fxString_operatorLess_m( int left, int right )
{
  unsigned int count = FXS_SIZE( right );
  return stl_fxString_compare_m( left, FXS_SIZE( left ), 0, (const char *)FXS_PTR( right ),
                     count ) < 0;
}

/* ---- FX_UnusedStub11  0x00499890 ----  [HIGH] */
/* retail 0x00499890, IDA nullsub_53: bare retn, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void FX_UnusedStub11()
{
  ;
}

/* ---- FX_UnusedStub12  0x004998A0 ----  [HIGH] */
/* retail 0x004998A0, IDA nullsub_54: bare retn, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void FX_UnusedStub12()
{
  ;
}

/* ---- stl_fxIntVector_ucopy_m  0x004998B0 ----  VERIFIED */
/* vector<int>::_Ucopy(first, last, ptr): _Uninitialized_copy(first, last, ptr, _Alval). */
unsigned int *FxIntVector::Ucopy( FxVecIter first, FxVecIter last, unsigned int *ptr )
{
  FxNonscalarPointerTag tag;   /* _Ptr_cat(first, ptr): an empty object */
  return stl_fxIntVector_uninitCopy_m( first, last, ptr, FxIntAllocator( this ), tag );
}

void __cdecl stl_fxIntVector_fill_m( const unsigned int *pval, FxVecIter first, FxVecIter last )
{
  unsigned int *dest = first.ptr, *end = last.ptr;
  while ( dest != end ) { *dest = *pval; ++dest; }
}

/* <xutility>'s _Copy_backward_opt(first, last, dest, _Nonscalar_ptr_iterator_tag),
 * inline in copy_backward; its out-of-line copy is retail 0x00499BB0. */
struct FxCopyBackwardOps
{
  static inline FxVecIter Opt( FxVecIter first, FxVecIter last, FxVecIter dest, FxNonscalarPointerTag );
};
FxVecIter __cdecl stl_fxIntVector_copyBackward_m( FxVecIter first, FxVecIter last, FxVecIter dest )
{
  FxNonscalarPointerTag tag;   /* _Ptr_cat(first, dest) */
  return (FxCopyBackwardOps::Opt( first, last, dest, tag ));
}

/* ---- stl_fxEffectIdMap_destroy2_m  0x00499930 ----  VERIFIED */
int __cdecl stl_fxEffectIdMap_destroy2_m( int node )
{
  return stl_fxEffectIdMap_nodeDtor_m( node );
}

/* ---- FX_UnusedStub13  0x00499940 ----  [HIGH] */
/* retail 0x00499940, IDA nullsub_55: bare retn, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void FX_UnusedStub13()
{
  ;
}

/* ---- FX_UnusedStub14  0x00499950 ----  [HIGH] */
/* retail 0x00499950, IDA nullsub_56: bare retn 4, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void __stdcall FX_UnusedStub14(int a1)
{
  ;
}

/* ---- stl_fxScheduledList_allocate2_m  0x00499960 ----  IMPLEMENTED (retail) */
/* std::_Allocate(count, (list node *)0): operator new(count * 12).  Retail
 * is __usercall count@eax; it overwrites the caller's hint slot with the
 * byte count and tail-jumps to operator new (the caller cleans). */
void *__cdecl stl_fxScheduledList_allocate2_m( unsigned int count, void *hint )
{
  (void)hint;
  return crt_operator_new( count * 12 );
}

/* ---- stl_fxScheduledList_construct2_m  0x00499970 ----  VERIFIED */
unsigned int *__cdecl stl_fxScheduledList_construct2_m( unsigned int *dest, unsigned int *src )
{
  if ( dest )
    *dest = *src;
  return dest;
}

/* ---- FX_UnusedStub15  0x00499980 ----  [HIGH] */
/* retail 0x00499980, IDA nullsub_57: bare retn, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void FX_UnusedStub15()
{
  ;
}

/* ---- stl_fxIntVector_allocate2_m  0x00499990 ----  IMPLEMENTED (retail) */
/* std::_Allocate(count, (int *)0): operator new(count * 4).  Retail is
 * __usercall count@eax, reusing the caller's hint slot for the byte count
 * and tail-jumping to operator new. */
void *__cdecl stl_fxIntVector_allocate2_m( unsigned int count, void *hint )
{
  (void)hint;
  return crt_operator_new( count * 4 );
}

/* ---- stl_fxChar_swap_m  0x004999A0 ----  VERIFIED */
/* std::swap for a single byte. */
char *__cdecl stl_fxChar_swap_m( char *a, char *b )
{
  char tmp;

  tmp = *b;
  *b  = *a;
  *a  = tmp;
  return a;
}

/* ---- FX_UnusedStub16  0x004999B0 ----  [HIGH] */
/* retail 0x004999B0, IDA nullsub_58: bare retn 4, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void __stdcall FX_UnusedStub16(int a1)
{
  ;
}

/* ---- FX_UnusedStub17  0x004999C0 ----  [HIGH] */
/* retail 0x004999C0, IDA nullsub_59: bare retn 4, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void __stdcall FX_UnusedStub17(int a1)
{
  ;
}

/* ---- stl_fxString_allocate2_m  0x004999D0 ----  IMPLEMENTED (retail) */
/* std::_Allocate(count, (char *)0): operator new(count).  Retail __cdecl,
 * count and hint on the stack (no tail call); the address-taken count
 * reproduces that convention. */
void *__cdecl stl_fxString_allocate2_m( size_t count, void *hint )
{
  size_t *n = &count;

  (void)hint;
  return crt_operator_new( *n );
}

/* ---- FX_UnusedStub18  0x004999E0 ----  [HIGH] */
/* retail 0x004999E0, IDA nullsub_60: bare retn 4, no xrefs, no vtable slot; dead STL out-of-line copy, name lost: descriptive name. */
void __stdcall FX_UnusedStub18(int a1)
{
  ;
}

/* ---- stl_fxEffectIdMap_allocate2_m  0x004999F0 ----  IMPLEMENTED (retail) */
/* std::_Allocate(count, (map node *)0): operator new(count * 48).  Retail
 * is __usercall count@eax, reusing the caller's hint slot for the byte
 * count and tail-jumping to operator new. */
void *__cdecl stl_fxEffectIdMap_allocate2_m( unsigned int count, void *hint )
{
  (void)hint;
  return crt_operator_new( count * 48 );
}

/* ---- stl_fxEffectIdMap_constructPtr2_m  0x00499A00 ----  VERIFIED */
unsigned int *__cdecl stl_fxEffectIdMap_constructPtr2_m( unsigned int *dest, unsigned int *src )
{
  if ( dest )
    *dest = *src;
  return dest;
}

void *__fastcall stl_fxEffectIdMap_nodeScalarDtor_m(void *node,FxDeletingFlags flagArg)
{
 unsigned int flags=flagArg.bits;
  stl_fxEffectIdMap_nodeDtor_m( (int)node );
  if ( ( flags & 1 ) != 0 )
    j__free( node );
  return node;
}

/* ---- stl_fxEffectIdMap_nodeDtor_m  0x00499A30 ----  VERIFIED */
/* map-node destructor: release the embedded key string's heap buffer (if the
 * string outgrew its SSO capacity) and reset it to the empty state. */
__declspec(noinline) __declspec(noinline) int __cdecl stl_fxEffectIdMap_nodeDtor_m( int node )
{
  unsigned char *key = ( (unsigned char *)(node) + 12 );

  if ( ( *(unsigned int *)( (unsigned char *)(key) + 24 ) ) >= 0x10u )
    j__free( *(void **)( (unsigned char *)(key) + 4 ) );
  ( *(unsigned int *)( (unsigned char *)(key) + 24 ) )  = 15;
  ( *(unsigned int *)( (unsigned char *)(key) + 20 ) ) = 0;
  *( (unsigned char *)(key) + 4 )  = 0;
  return 0;
}

/* ---- stl_fxString_compareStr_m  0x00499A60 ----  IMPLEMENTED (retail) */
/* std::string::compare(const string &right):
 * compare(0, size(), right.c_str(), right.size()) via stl_fxString_compare_m, returning
 * its -1 / 0 / 1.  Retail is __usercall (right@eax, this@ecx). */
int __cdecl stl_fxString_compareStr_m( int self, int right )
{
  unsigned int count = FXS_SIZE( right );
  return stl_fxString_compare_m( self, FXS_SIZE( self ), 0, (const char *)FXS_PTR( right ),
                     count );
}

/* ---- stl_fxIntVector_iterPreinc_m  0x00499A90 ----  [HIGH] */
unsigned int *__cdecl stl_fxIntVector_iterPreinc_m( unsigned int *it )
{
  *it += 4;
  return it;
}

/* ---- stl_fxIntVector_iterNotEqual_m  0x00499AA0 ----  [HIGH] */
int __cdecl stl_fxIntVector_iterNotEqual_m( unsigned int *a, unsigned int *b )
{
  return *a != *b;
}

/* ---- stl_fxString_compare_m  0x00499AB0 ----  VERIFIED */
int __stdcall stl_fxString_compare_m( int self, unsigned int n0, unsigned int off,
                        const char *ptr, unsigned int count )
{
  /* basic_string::compare(off, n0, ptr, count) */
  FxString     *str = (FxString *)self;
  unsigned int  ans;

  if ( str->size < off )
    ( (const std::_String_base *)str )->_Xran();   /* off off end */
  if ( str->size - off < n0 )
    n0 = str->size - off;   /* trim n0 to size */
  ans = n0 == 0 ? 0 : memcmp( ( 16 <= str->capacity ? str->bx.ptr : (char *)&str->bx ) + off, ptr,
                              n0 < count ? n0 : count );
  return ans != 0 ? (int)ans : n0 < count ? -1 : n0 == count ? 0 : +1;
}

/* ---- stl_fxIntVector_iterEqual_m  0x00499B20 ----  [HIGH] */
int __cdecl stl_fxIntVector_iterEqual_m( unsigned int *a, unsigned int *b )
{
  return *b == *a;
}

FxScalarPointerTag __cdecl stl_fxIntVector_ptrCat_uninitFillN_m(const unsigned int *first,const unsigned int *last)
{
 FxScalarPointerTag tag;
 (void)first;(void)last;
 return tag;
}

/* ---- stl_fxIntVector_uninitFillN_m  0x00499B40 ----  VERIFIED */
/* _Uninit_fill_n(dest, count, val, al, tag): VC7's _Ptr_cat(first, first)
 * picks the general (nonscalar) template even for int *, so this is the
 * allocator::construct loop (placement new: the null test) under a
 * try/catch that rethrows.  Nothing in it can throw, so no EH frame is left. */
__declspec(noinline) void __cdecl stl_fxIntVector_uninitFillN_m(unsigned int *dest,unsigned int count,const unsigned int *pval,FxIntAllocatorReference allocatorArg,FxScalarPointerTag scalarTag)
{
  unsigned int *next = dest;

  try
  {
    while ( count > 0 )
    {
      if ( dest )
        *dest = *pval;
      ++dest;
      --count;
    }
  }
  catch ( ... )
  {
    for ( ; next != dest; ++next )
      ;   /* allocator::destroy: nothing for int */
    throw;
  }
}

/* ---- stl_fxIntVector_nop_m  0x00499B60 ----  [HIGH] */
void stl_fxIntVector_nop_m()
{
  ;
}

/* ---- stl_fxIntVector_ucopy_dup_m  0x00499B70 ----  VERIFIED */
/* vector<int>::_Ucopy: the same body as the __thiscall stl_fxIntVector_ucopy_m, but
 * the copy _Insert_n's reallocating path inlines.  Retail's leftover out-of-line
 * copy has no caller and LTCG's custom convention (the allocator `this` in ecx,
 * caller pops: plain retn), which an inline __cdecl function taking the vector
 * explicitly reproduces. */
inline unsigned int *__cdecl UcopyConst( FxIntVector *self, FxVecIter first, FxVecIter last, unsigned int *ptr )
{
  FxNonscalarPointerTag tag;   /* _Ptr_cat(first, ptr): an empty object */
  return stl_fxIntVector_uninitCopy_m( first, last, ptr, FxIntAllocator( self ), tag );
}

FxNonscalarPointerTag __cdecl stl_fxIntVector_emptyObj_m(fxIntVecIter first,fxIntVecIter last)
{
 FxNonscalarPointerTag tag;
 (void)first;(void)last;
 return tag;
}

/* stl_fxIntVector_copyBackward_dup_m: _Copy_backward_opt (nonscalar iterators), the
 * out-of-line copy of the inline function stl_fxIntVector_copyBackward_m expands. */
inline FxVecIter FxCopyBackwardOps::Opt( FxVecIter first, FxVecIter last, FxVecIter dest, FxNonscalarPointerTag )
{
  while ( first.ptr != last.ptr )
    *--dest.ptr = *--last.ptr;
  return (dest);
}

/* ---- stl_fxIntVector_allocConstruct_m  0x00499BE0 ----  VERIFIED */
unsigned int *__fastcall stl_fxIntVector_allocConstruct_m( unsigned int *dest, unsigned int *src, int unused )
{
  (void)unused;
  if ( dest )
    *dest = *src;
  return dest;
}

/* ---- stl_fxIntVector_nop3_m  0x00499BF0 ----  [HIGH] */
void __stdcall stl_fxIntVector_nop3_m(int unused1, int unused2)
{
  ;
}

/* ---- stl_fxIntVector_iterPredec_m  0x00499C00 ----  [HIGH] */
unsigned int *__cdecl stl_fxIntVector_iterPredec_m( unsigned int *it )
{
  *it -= 4;
  return it;
}

/* ---- stl_fxIntVector_emptyObj2_m  0x00499C10 ----  VERIFIED */
typedef FxStlAllocatorTag FxLaterEmptyAllocator;
unsigned char __cdecl stl_fxIntVector_emptyObj2_m(void)
{
  FxLaterEmptyAllocator result;
  return result.value;
}

/* ---- stl_fxIntVector_uninitCopy_m  0x00499C20 ----  VERIFIED */
/* _Uninit_copy(first, last, dest, al, _Nonscalar_ptr_iterator_tag): copy
 * constructs [first, last) into raw dest (allocator::construct is a
 * placement new, hence the null test).  Its try block keeps it out of line;
 * nothing in it can throw, so no EH frame is left.  By-value iterators keep
 * first/last on the stack (dest@eax), as in retail. */
unsigned int *__cdecl stl_fxIntVector_uninitCopy_m( FxVecIter first, FxVecIter last, unsigned int *dest,
                                              FxIntAllocatorReference al, FxNonscalarPointerTag tag )
{
  unsigned int *next = dest;

  (void)al;
  (void)tag;
  try
  {
    for ( ; first.ptr != last.ptr; ++dest, ++first.ptr )
      if ( dest )
        *dest = *first.ptr;
  }
  catch ( ... )
  {
    for ( ; next != dest; ++next )
      ;   /* allocator::destroy: nothing for int */
    throw;
  }
  return dest;
}

/* ---- stl_fxIntVector_construct_m  0x00499C50 ----  VERIFIED */
unsigned int *__cdecl stl_fxIntVector_construct_m( unsigned int *dest, unsigned int *src )
{
  if ( dest )
    *dest = *src;
  return dest;
}

/* ---- stl_fxIntVector_nop2_m  0x00499C60 ----  [HIGH] */
void stl_fxIntVector_nop2_m()
{
  ;
}

/* ---- SFxHelper__ctor  0x00499C70 ----  VERIFIED */
unsigned int *__cdecl SFxHelper__ctor( unsigned int *v )
{
  v[1] = 0;
  v[2] = 0;
  v[3] = 0;
  v[4] = 0;
  return v;
}

/* ---- SFxHelper__Init  0x00499C80 ----  VERIFIED */
unsigned int *__cdecl SFxHelper__Init( unsigned int *v )
{
  v[0] = 0;
  v[1] = 0;
  v[2] = 0;
  v[3] = 0;
  v[4] = 0;
  return v;
}

/* ---- SFxHelper__Print  0x00499CA0 ----  VERIFIED */
void SFxHelper__Print( int unusedThis, char *Format, ... )
{
  char    Buffer[1024];
  va_list ArgList;

  (void)unusedThis;
  va_start( ArgList, Format );
  vsprintf( Buffer, Format, ArgList );
  Com_Printf( Buffer );
}

/* ---- SFxHelper__AdjustTime  0x00499D00 ----  VERIFIED */
void __cdecl SFxHelper__AdjustTime( int *thisObj, int realTime )
{
  if ( fx_freeze->integer )
  {
    thisObj[3] = 0;
    thisObj[0] = realTime;
    return;
  }

  if ( !thisObj[0] )
  {
    thisObj[3] = 0;
  }
  else
  {
    thisObj[3] = realTime - thisObj[0];
    if ( thisObj[3] < 0 )
      thisObj[3] = 0;
    else if ( thisObj[3] > 200 )
      thisObj[3] = 200;
  }

  thisObj[2] = thisObj[1];
  thisObj[1] = thisObj[3] + thisObj[1];
  thisObj[0] = realTime;
}

/* ---- SFxHelper__AdjustCamera  0x00499D60 ----  [CONFIRMED] */
/* SFxHelper::AdjustCamera( refdef, zfar ): copy the view origin/forward axis
 * into mCamera, build the four side frustum planes from the half fov_x /
 * fov_y sin/cos (VectorScale + VectorMA with +/-cos), add the far plane when
 * zfar > 0, then set each plane's dist = DotProduct( normal, origin ) (x, z, y
 * sum order) and pull the far plane in by zfar.
 * Retail keeps all three arguments in their stack slots and reloads them
 * after every store through a pointer (and re-reads/re-negates cos per
 * statement), as if their addresses escaped: FX_ADDRESS_ESCAPES marks them. */
void __stdcall SFxHelper__AdjustCamera( int dest, int src, float duration )
{
  float  angle;
  float  s;
  float  c;
  int    frame;

  FX_STANDARD_CALL(SFxHelper__AdjustCamera);
  FX_ADDRESS_ESCAPES(dest);
  FX_ADDRESS_ESCAPES(src);
  FX_ADDRESS_ESCAPES(duration);
  *(unsigned int *)&FX_HELPER(dest)->mCamera.origin[0] = *(unsigned int *)&FX_REFDEF(src)->vieworg[0];
  *(unsigned int *)&FX_HELPER(dest)->mCamera.origin[1] = *(unsigned int *)&FX_REFDEF(src)->vieworg[1];
  *(unsigned int *)&FX_HELPER(dest)->mCamera.origin[2] = *(unsigned int *)&FX_REFDEF(src)->vieworg[2];
  *(unsigned int *)&FX_HELPER(dest)->mCamera.planes[0].normal[0] = *(unsigned int *)&FX_REFDEF(src)->viewaxis[0][0];
  *(unsigned int *)&FX_HELPER(dest)->mCamera.planes[0].normal[1] = *(unsigned int *)&FX_REFDEF(src)->viewaxis[0][1];
  *(unsigned int *)&FX_HELPER(dest)->mCamera.planes[0].normal[2] = *(unsigned int *)&FX_REFDEF(src)->viewaxis[0][2];
  angle = FX_REFDEF(src)->fov_x * 0.0087266462f;
  SinCos(angle,&s,&c);
  FX_HELPER(dest)->mCamera.planes[1].normal[0] = s * FX_REFDEF(src)->viewaxis[0][0];
  FX_HELPER(dest)->mCamera.planes[1].normal[1] = s * FX_REFDEF(src)->viewaxis[0][1];
  FX_HELPER(dest)->mCamera.planes[1].normal[2] = s * FX_REFDEF(src)->viewaxis[0][2];
  FX_HELPER(dest)->mCamera.planes[1].normal[0] = c * FX_REFDEF(src)->viewaxis[1][0] + FX_HELPER(dest)->mCamera.planes[1].normal[0];
  FX_HELPER(dest)->mCamera.planes[1].normal[1] = c * FX_REFDEF(src)->viewaxis[1][1] + FX_HELPER(dest)->mCamera.planes[1].normal[1];
  FX_HELPER(dest)->mCamera.planes[1].normal[2] = c * FX_REFDEF(src)->viewaxis[1][2] + FX_HELPER(dest)->mCamera.planes[1].normal[2];
  FX_HELPER(dest)->mCamera.planes[2].normal[0] = s * FX_REFDEF(src)->viewaxis[0][0];
  FX_HELPER(dest)->mCamera.planes[2].normal[1] = s * FX_REFDEF(src)->viewaxis[0][1];
  FX_HELPER(dest)->mCamera.planes[2].normal[2] = s * FX_REFDEF(src)->viewaxis[0][2];
  FX_HELPER(dest)->mCamera.planes[2].normal[0] = (-c) * FX_REFDEF(src)->viewaxis[1][0] + FX_HELPER(dest)->mCamera.planes[2].normal[0];
  FX_HELPER(dest)->mCamera.planes[2].normal[1] = (-c) * FX_REFDEF(src)->viewaxis[1][1] + FX_HELPER(dest)->mCamera.planes[2].normal[1];
  FX_HELPER(dest)->mCamera.planes[2].normal[2] = (-c) * FX_REFDEF(src)->viewaxis[1][2] + FX_HELPER(dest)->mCamera.planes[2].normal[2];
  angle = FX_REFDEF(src)->fov_y * 0.0087266462f;
  SinCos(angle,&s,&c);
  FX_HELPER(dest)->mCamera.planes[3].normal[0] = s * FX_REFDEF(src)->viewaxis[0][0];
  FX_HELPER(dest)->mCamera.planes[3].normal[1] = s * FX_REFDEF(src)->viewaxis[0][1];
  FX_HELPER(dest)->mCamera.planes[3].normal[2] = s * FX_REFDEF(src)->viewaxis[0][2];
  FX_HELPER(dest)->mCamera.planes[3].normal[0] = c * FX_REFDEF(src)->viewaxis[2][0] + FX_HELPER(dest)->mCamera.planes[3].normal[0];
  FX_HELPER(dest)->mCamera.planes[3].normal[1] = c * FX_REFDEF(src)->viewaxis[2][1] + FX_HELPER(dest)->mCamera.planes[3].normal[1];
  FX_HELPER(dest)->mCamera.planes[3].normal[2] = c * FX_REFDEF(src)->viewaxis[2][2] + FX_HELPER(dest)->mCamera.planes[3].normal[2];
  FX_HELPER(dest)->mCamera.planes[4].normal[0] = s * FX_REFDEF(src)->viewaxis[0][0];
  FX_HELPER(dest)->mCamera.planes[4].normal[1] = s * FX_REFDEF(src)->viewaxis[0][1];
  FX_HELPER(dest)->mCamera.planes[4].normal[2] = s * FX_REFDEF(src)->viewaxis[0][2];
  FX_HELPER(dest)->mCamera.planes[4].normal[0] = (-c) * FX_REFDEF(src)->viewaxis[2][0] + FX_HELPER(dest)->mCamera.planes[4].normal[0];
  FX_HELPER(dest)->mCamera.planes[4].normal[1] = (-c) * FX_REFDEF(src)->viewaxis[2][1] + FX_HELPER(dest)->mCamera.planes[4].normal[1];
  FX_HELPER(dest)->mCamera.planes[4].normal[2] = (-c) * FX_REFDEF(src)->viewaxis[2][2] + FX_HELPER(dest)->mCamera.planes[4].normal[2];
  *(unsigned int *)&FX_HELPER(dest)->mCamera.numPlanes = 5;
  if ( duration > 0.0f )
  {
    FX_HELPER(dest)->mCamera.planes[5].normal[0] = -FX_REFDEF(src)->viewaxis[0][0];
    FX_HELPER(dest)->mCamera.planes[5].normal[1] = -FX_REFDEF(src)->viewaxis[0][1];
    FX_HELPER(dest)->mCamera.planes[5].normal[2] = -FX_REFDEF(src)->viewaxis[0][2];
    *(unsigned int *)&FX_HELPER(dest)->mCamera.numPlanes = 6;
  }

  for ( frame = 0; frame < FX_HELPER(dest)->mCamera.numPlanes; ++frame )
  {
    FX_HELPER(dest)->mCamera.planes[frame].dist = FX_HELPER(dest)->mCamera.planes[frame].normal[0] * FX_HELPER(dest)->mCamera.origin[0]
                                             + FX_HELPER(dest)->mCamera.planes[frame].normal[2] * FX_HELPER(dest)->mCamera.origin[2]
                                             + FX_HELPER(dest)->mCamera.planes[frame].normal[1] * FX_HELPER(dest)->mCamera.origin[1];
  }
  if ( duration > 0.0f )
    FX_HELPER(dest)->mCamera.planes[5].dist = FX_HELPER(dest)->mCamera.planes[5].dist - duration;
}


/* ---- SFxHelper__CullSphere  0x0049A0D0 ----  VERIFIED */
char __stdcall SFxHelper__CullSphere( int unusedThis, float *origin, float radius )
{
  int    i;
  float *plane;

  (void)unusedThis;
  plane = &fxHelperCullPlane0NormalY - 1;
  for ( i = 0; i < fxHelperCullPlaneCount; ++i, plane += 4 )
  {
    /* retail sum order x, z, y, then radius (0x0049A0E2-0x0049A0F6) */
    if ( plane[0] * origin[0] + plane[2] * origin[2] + origin[1] * plane[1]
         + radius < plane[3] )
      return 1;
  }
  return 0;
}

/* ---- SFxHelper__CullCylinder  0x0049A120 ----  VERIFIED */
char __stdcall SFxHelper__CullCylinder( int unusedThis, float *p1, float *p2,
                                        float radius1, float radius2 )
{
  int                  i;
  const fxCullPlane_t *plane;

  (void)unusedThis;
  plane = (const fxCullPlane_t *)( &fxHelperCullPlane0NormalY - 1 );
  for ( i = 0; i < fxHelperCullPlaneCount; ++i, ++plane )
  {
    /* retail sums z, then y, then x (0x0049A132 / 0x0049A154): (z + y) + x + r */
    if ( ( p1[2] * plane->normal[2] + p1[1] * plane->normal[1] ) + p1[0] * plane->normal[0]
         + radius1 < plane->dist )
    {
      if ( ( p2[2] * plane->normal[2] + p2[1] * plane->normal[1] ) + p2[0] * plane->normal[0]
           + radius2 < plane->dist )
        return 1;
    }
  }
  return 0;
}

/* ---- SFxHelper__OpenFile  0x0049A190 ----  [HIGH] */
/* SFxHelper::OpenFile( file, fh, mode ): `this` and `mode` are unused, so
 * LTCG leaves them on the stack (retn 8) and passes file/fh in registers. */
int __stdcall SFxHelper__OpenFile(const void *helper,const char *file,fileHandle_t *fh,int mode)
{
 (void)helper;
 (void)mode;
 return FS_FOpenFileByMode(file,fh,FS_READ);
}

/* ---- SFxHelper__ReadFile  0x0049A1A0 ----  [HIGH] */
int __stdcall SFxHelper__ReadFile(const void *helper,void *data,int len,fileHandle_t fh)
{
 (void)helper;
 FS_Read(data,len,fh);
 return 1;
}

/* ---- SFxHelper__CloseFile  0x0049A1C0 ----  [HIGH] */
void __stdcall SFxHelper__CloseFile(fileHandle_t f,const void *helper)
{
 (void)helper;
 FS_FCloseFile(f);
}

/* ---- SFxHelper__PlaySound  0x0049A1D0 ----  [HIGH] */
void __stdcall SFxHelper__PlaySound( int aliasIndex, const void *helper, float *origin, int entnum )
{
  const char **entry;
  void        *alias;

  (void)helper;
  if ( aliasIndex <= 0 || aliasIndex > snd_aliasTableCount[1] )
    return;

  
  entry = (const char **)( (char *)snd_aliasTable[1]
                           + 68 * aliasIndex - 68 );
  if ( !entry )
    return;

  alias = Com_PickSoundAlias( *entry, 1 );
  if ( !alias )
    return;



  MSS_PlaySoundAlias_Internal( alias, (float *)alias, 0.0f, entnum, origin, 0, 0 );
}

/* ---- SFxHelper__Trace  0x0049A220 ----  VERIFIED */
void __stdcall SFxHelper__Trace( int brushmask, const float *end, const float *start,
                               trace_t *results, int unusedThis,
                               const float *mins, const float *maxs, int unused4 )
{
  (void)unusedThis;
  (void)unused4;

  results->fraction = 1.0f;
  CM_Trace( results, start, end, mins, maxs, 0, vec3_origin, brushmask, 0, 0 );
  results->entityNum = ( results->fraction != 1.0 ) ? 1022 : 1023;
}

/* ---- SFxHelper__AddFxToScene  0x0049A270 ----  [HIGH] */
int __stdcall SFxHelper__AddFxToScene( int refEntity, const void *unusedThis )
{
  (void)unusedThis;
  return ( *(int (**)(FX_ANYARGS))&re.AddRefEntityToScene )( refEntity, 0 );
}

/* ---- SFxHelper__RegisterShader  0x0049A280 ----  [HIGH] */
int __stdcall SFxHelper__RegisterShader( int name, const void *unusedThis )
{
  (void)unusedThis;
  return ( *(int (**)(FX_ANYARGS))&re.RegisterShader )( name, 9 );
}

/* ---- SFxHelper__RegisterSound  0x0049A290 ----  [HIGH] */
int __stdcall SFxHelper__RegisterSound( const char *name, const void *unusedThis )
{
  (void)unusedThis;
  return Com_SoundAliasIndex( Com_PickSoundAlias( name, 1 ), 1 );
}

/* ---- SFxHelper__RegisterModel  0x0049A2D0 ----  [HIGH] */
char *__stdcall SFxHelper__RegisterModel( char *name, const void *unusedThis )
{
  (void)unusedThis;
  return CFxModel__Register( name );
}

/* ---- SFxHelper__SetIgnorePrecacheErrors  0x0049A2E0 ----  [HIGH] */
void __stdcall SFxHelper__SetIgnorePrecacheErrors( unsigned __int8 ignore, const void *unusedThis )
{
  (void)unusedThis;
  ( *(int (**)(FX_ANYARGS))&re.SetIgnorePrecacheErrors )( ignore );
}

/* ---- SFxHelper__GetShaderName  0x0049A2F0 ----  [HIGH] */
int __stdcall SFxHelper__GetShaderName( int shader, const void *unusedThis )
{
  (void)unusedThis;
  return ( *(int (**)(FX_ANYARGS))&re.GetShaderName )( shader );
}

/* ---- SFxHelper__Archive_m  0x0049A300 ----  [HIGH] */
/* SFxHelper::Archive (Mac symbol not present; name inferred): save/load the
 * helper's timing fields +4/+8/+12/+16 (fxMTime, fxHelperOldTime,
 * fxHelperFrameTime, fxHelperArchivedTimingState); when reading, clear +0. */
void __cdecl SFxHelper__Archive_m( int helper, int ar )
{
  FX_AR_FIELD( ar, helper,  4, 4 );
  FX_AR_FIELD( ar, helper,  8, 4 );
  FX_AR_FIELD( ar, helper, 12, 4 );
  FX_AR_FIELD( ar, helper, 16, 4 );
  if ( ((FxArchive *)ar)->reading )
    *(unsigned int *)helper = 0;
}

/* ---- SFxHelper__AddLightToScene  0x0049A390 ----  [HIGH] */
void __stdcall SFxHelper__AddLightToScene(int unusedThis, const float *origin, float intensity, float red, float green, float blue)
{
  (void)unusedThis;
  re.AddLightToScene(origin, intensity, red, green, blue);
}

/* ---- SFxHelper__AddPolyToScene  0x0049A3C0 ----  VERIFIED */
int __stdcall SFxHelper__AddPolyToScene( int verts, int shader, int numVerts, const void *unused4 )
{
  (void)unused4;
  return ( *(int (**)(FX_ANYARGS))&re.AddPolyToScene )( shader, numVerts, verts );
}

/* ---- SFxHelper__CameraShake  0x0049A3D0 ----  [HIGH] */
void __stdcall SFxHelper__CameraShake(int unusedThis, int origin, int intensity, int radius, int time)
{
  ;
}

/* ---- CGPObject__GetNext  0x0049A3E0 ----  [HIGH] */
int __cdecl CGPObject__GetNext( int self )
{
  return *(unsigned int *)( self + FX_GPOBJ_OFS( mNext ) );
}

/* ---- CGPValue__GetNext  0x0049A3F0 ----  [HIGH] */
int __cdecl CGPValue__GetNext( int self )
{
  return *(unsigned int *)( self + FX_GPVALUE_OFS( mNext ) );
}

/* ---- CGPValue__GetList  0x0049A400 ----  [HIGH] */
int __cdecl CGPValue__GetList( int self )
{
  return *(unsigned int *)( self + FX_GPVALUE_OFS( mList ) );
}

/* ---- CGPGroup__GetPairs  0x0049A410 ----  [HIGH] */
int __cdecl CGPGroup__GetPairs( int self )
{
  return *(unsigned int *)( self + FX_GPGROUP_OFS( mPairs ) );
}

/* ---- CMediaHandles__AddHandle  0x0049A420 ----  VERIFIED */
void __stdcall CMediaHandles__AddHandle(unsigned int *receiver,FxMediaHandleArgument argument)
{stl_fxIntVector_pushBack_m((unsigned int *)&argument.value,receiver);}

}   /* extern "C" */

/* ---- CFxRange__ctor  0x0049A430 ----  [HIGH] */
inline CFxRange::CFxRange()
{
  mMin = 0;
  mMax = 0;
}

extern "C" {

/* ---- CFxRange__SetRange  0x0049A440 ----  [HIGH] */
float *__stdcall CFxRange__SetRange( float *pair, float first, float second )
{
  pair[0] = first;
  pair[1] = second;
  return pair;
}

/* ---- CFxRange__assign_m  0x0049A450 ----  VERIFIED */
int __cdecl CFxRange__assign_m( unsigned int *src, unsigned int *dest )
{
  int second;

  dest[0] = src[0];
  second  = src[1];
  dest[1] = second;
  return second;
}

/* ---- CPrimitiveTemplate__ctor  0x0049A460 ----  [CONFIRMED] */
}   /* extern "C" */

/* The members are constructed first (CFxRange: [0, 0]; the handle vectors:
 * empty), then the body sets the defaults. */
CPrimitiveTemplate::CPrimitiveTemplate()
{
  mCopy = 0;      /* we never start out as a copy or with a name */
  mName[0] = 0;
  mCullRange = 0;
  mSpawnFlags = 0;
  mFlags = 0;
  mNonUniformScale = 0;
  CFxRange__SetRange( &mLife.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mSpawnCount.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mRadius.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mHeight.mMin, 1.0f, 1.0f );
  mMaterialImpact[0] = 0;
  *(int *)&mMin[0] = 0;
  *(int *)&mMin[1] = 0;
  *(int *)&mMin[2] = 0;
  *(int *)&mMax[0] = 0;
  *(int *)&mMax[1] = 0;
  *(int *)&mMax[2] = 0;
  CFxRange__SetRange( &mRedStart.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mGreenStart.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mBlueStart.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mRedEnd.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mGreenEnd.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mBlueEnd.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mAlphaStart.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mAlphaEnd.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mSizeStart.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mSizeEnd.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mSize2Start.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mSize2End.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mLengthStart.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mLengthEnd.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mTexCoordS.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mTexCoordT.mMin, 1.0f, 1.0f );
  CFxRange__SetRange( &mVariance.mMin, 1.0f, 1.0f );
  mDensity.mMin = 10.0f;
  mDensity.mMax = 10.0f;
}

extern "C" {
}   /* extern "C" */

/* ---- CMediaHandles__ctor_m  0x0049A880 ----  [CONFIRMED] */
inline CMediaHandles::CMediaHandles()
{
  stl_fxIntVector_buy_m( 0, (unsigned int *)this );   /* _Buy(0) */
}

extern "C" {

/* ---- CPrimitiveTemplate__copy_m  0x0049A890 ----  VERIFIED */
/* Field-by-field copy of one CPrimitiveTemplate onto another: the two
 * NUL-terminated name strings (+8 and +40) are copied byte-wise, the five
 * curve tables (+104..+168) via CMediaHandles__operator_assign, and everything else word-wise.
 * The gaps (dword 48, 69..72) and the +0..+17 header are left untouched, as
 * in retail. */
void __cdecl CPrimitiveTemplate__copy_m( char *dst, char *src )
{
  int  *d = (int *)dst;
  int  *s = (int *)src;

  strcpy(dst + 8,src + 8);

  d[18] = s[18];
  d[19] = s[19];
  d[20] = s[20];
  d[21] = s[21];
  d[22] = s[22];
  d[23] = s[23];
  d[24] = s[24];
  d[25] = s[25];

  CMediaHandles__operator_assign( (int)( dst + 104 ), (int)( src + 104 ) );
  CMediaHandles__operator_assign( (int)( dst + 120 ), (int)( src + 120 ) );
  CMediaHandles__operator_assign( (int)( dst + 136 ), (int)( src + 136 ) );
  CMediaHandles__operator_assign( (int)( dst + 152 ), (int)( src + 152 ) );
  CMediaHandles__operator_assign( (int)( dst + 168 ), (int)( src + 168 ) );

  {
    /* strcpy( dst + 40, src + 40 ), open-coded: retail's loop addresses [diff+src] like the first copy */
    char *sp = src + 40;
    char *dp = dst + 40;
    while ( ( *dp++ = *sp++ ) != 0 )
      ;
  }

  d[46] = s[46];
  d[47] = s[47];
  d[49] = s[49];
  d[50] = s[50];
  d[51] = s[51];
  d[52] = s[52];
  d[53] = s[53];
  d[54] = s[54];
  d[55] = s[55];
  d[56] = s[56];
  d[57] = s[57];
  d[58] = s[58];
  d[59] = s[59];
  d[60] = s[60];
  d[61] = s[61];
  d[62] = s[62];
  d[63] = s[63];
  d[64] = s[64];
  d[65] = s[65];
  d[66] = s[66];
  d[67] = s[67];
  d[68] = s[68];
  d[73] = s[73];
  d[74] = s[74];
  d[75] = s[75];
  d[76] = s[76];
  d[77] = s[77];
  d[78] = s[78];
  d[79] = s[79];
  d[80] = s[80];
  d[81] = s[81];
  d[82] = s[82];
  d[83] = s[83];
  d[84] = s[84];
  d[85] = s[85];
  d[86] = s[86];
  d[87] = s[87];
  d[88] = s[88];
  d[89] = s[89];
  d[90] = s[90];
  d[91] = s[91];
  d[92] = s[92];
  d[93] = s[93];
  d[94] = s[94];
  d[95] = s[95];
  d[96] = s[96];
  d[97] = s[97];
  d[98] = s[98];
  d[99] = s[99];
  d[100] = s[100];
  d[101] = s[101];
  d[102] = s[102];
  d[103] = s[103];
  d[104] = s[104];
  d[105] = s[105];
  d[106] = s[106];
  d[107] = s[107];
  d[108] = s[108];
  d[109] = s[109];
  d[110] = s[110];
  d[111] = s[111];
  d[112] = s[112];
  d[113] = s[113];
  d[114] = s[114];
  d[115] = s[115];
  d[116] = s[116];
  d[117] = s[117];
  d[118] = s[118];
  d[119] = s[119];
  d[120] = s[120];
  d[121] = s[121];
  d[122] = s[122];
  d[123] = s[123];
  d[124] = s[124];
  d[125] = s[125];
  d[126] = s[126];
  d[127] = s[127];
  d[128] = s[128];
  d[129] = s[129];
  d[130] = s[130];
  d[131] = s[131];
  d[132] = s[132];
  d[133] = s[133];
  d[134] = s[134];
  d[135] = s[135];
  d[136] = s[136];
  d[137] = s[137];
  d[138] = s[138];
  d[139] = s[139];
  d[140] = s[140];
  d[141] = s[141];
  d[142] = s[142];
  d[143] = s[143];
  d[144] = s[144];
  d[145] = s[145];
  d[146] = s[146];
  d[147] = s[147];
  d[148] = s[148];
  d[149] = s[149];
  d[150] = s[150];

}

/* ---- CPrimitiveTemplate__assign_m  0x0049ADF0 ----  VERIFIED */
/* CPrimitiveTemplate::operator= -- like CPrimitiveTemplate__copy_m, but the
 * assignment operator copies only the +8 name string (not the +40 one) and
 * leaves dword 25 untouched, as well as the dword 48 / 69..72 gaps and the
 * +0..+17 header.  The five curve tables (+104..+168) go through CMediaHandles__operator_assign;
 * everything else is copied word-wise.  Returns the last word copied (150). */
int __cdecl CPrimitiveTemplate__assign_m( char *src, char *dst )
{
  int  *d = (int *)dst;
  int  *s = (int *)src;
  int   result;

  strcpy( dst + 8, src + 8 );

  d[18] = s[18];
  d[19] = s[19];
  d[20] = s[20];
  d[21] = s[21];
  d[22] = s[22];
  d[23] = s[23];
  d[24] = s[24];

  CMediaHandles__operator_assign( (int)( dst + 104 ), (int)( src + 104 ) );
  CMediaHandles__operator_assign( (int)( dst + 120 ), (int)( src + 120 ) );
  CMediaHandles__operator_assign( (int)( dst + 136 ), (int)( src + 136 ) );
  CMediaHandles__operator_assign( (int)( dst + 152 ), (int)( src + 152 ) );
  CMediaHandles__operator_assign( (int)( dst + 168 ), (int)( src + 168 ) );

  d[46] = s[46];
  d[47] = s[47];
  d[49] = s[49];
  d[50] = s[50];
  d[51] = s[51];
  d[52] = s[52];
  d[53] = s[53];
  d[54] = s[54];
  d[55] = s[55];
  d[56] = s[56];
  d[57] = s[57];
  d[58] = s[58];
  d[59] = s[59];
  d[60] = s[60];
  d[61] = s[61];
  d[62] = s[62];
  d[63] = s[63];
  d[64] = s[64];
  d[65] = s[65];
  d[66] = s[66];
  d[67] = s[67];
  d[68] = s[68];
  d[73] = s[73];
  d[74] = s[74];
  d[75] = s[75];
  d[76] = s[76];
  d[77] = s[77];
  d[78] = s[78];
  d[79] = s[79];
  d[80] = s[80];
  d[81] = s[81];
  d[82] = s[82];
  d[83] = s[83];
  d[84] = s[84];
  d[85] = s[85];
  d[86] = s[86];
  d[87] = s[87];
  d[88] = s[88];
  d[89] = s[89];
  d[90] = s[90];
  d[91] = s[91];
  d[92] = s[92];
  d[93] = s[93];
  d[94] = s[94];
  d[95] = s[95];
  d[96] = s[96];
  d[97] = s[97];
  d[98] = s[98];
  d[99] = s[99];
  d[100] = s[100];
  d[101] = s[101];
  d[102] = s[102];
  d[103] = s[103];
  d[104] = s[104];
  d[105] = s[105];
  d[106] = s[106];
  d[107] = s[107];
  d[108] = s[108];
  d[109] = s[109];
  d[110] = s[110];
  d[111] = s[111];
  d[112] = s[112];
  d[113] = s[113];
  d[114] = s[114];
  d[115] = s[115];
  d[116] = s[116];
  d[117] = s[117];
  d[118] = s[118];
  d[119] = s[119];
  d[120] = s[120];
  d[121] = s[121];
  d[122] = s[122];
  d[123] = s[123];
  d[124] = s[124];
  d[125] = s[125];
  d[126] = s[126];
  d[127] = s[127];
  d[128] = s[128];
  d[129] = s[129];
  d[130] = s[130];
  d[131] = s[131];
  d[132] = s[132];
  d[133] = s[133];
  d[134] = s[134];
  d[135] = s[135];
  d[136] = s[136];
  d[137] = s[137];
  d[138] = s[138];
  d[139] = s[139];
  d[140] = s[140];
  d[141] = s[141];
  d[142] = s[142];
  d[143] = s[143];
  d[144] = s[144];
  d[145] = s[145];
  d[146] = s[146];
  d[147] = s[147];
  d[148] = s[148];
  d[149] = s[149];
  result = s[150];
  d[150] = result;
  return result;
}

/* ---- CPrimitiveTemplate__ParseFloat  0x0049B330 ----  [HIGH] */
/* Parses "min [max]" into two outputs; when only one value is given the
 * second (max) mirrors the first (min).  Fourth arg is unused. */
char __stdcall CPrimitiveTemplate__ParseFloat( const void *tmpl, const char *text, float *outMin, float *outMax )
{
  int count;
  (void)tmpl;
  if(outMin && outMax){
    count=sscanf(text,"%f %f",outMin,outMax);
    if(count){
      if(count==1)*outMax=*outMin;
      return 1;
    }
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseVector  0x0049B360 ----  [CONFIRMED] */
/* CPrimitiveTemplate::ParseVector( val, min, max ): parses "min[3] [max[3]]";
 * when only the first triple is given max mirrors min.  The unused `this`
 * and `val` stay on the stack; LTCG passes min/max in ESI/EDI, and the
 * declared (min, max) order gives retail's argument setup order. */
char __stdcall CPrimitiveTemplate__ParseVector( int unused, char *text, float *base, float *range )
{
 int count;
 if(base && range){
  count=sscanf(text,"%f %f %f   %f %f %f",base,base+1,base+2,range,range+1,range+2);
  if(count>=3 && count!=4 && count!=5){
   if(count==3){range[0]=base[0];range[1]=base[1];range[2]=base[2];}
   return 1;
  }
 }
 return 0;
}

/* ---- CPrimitiveTemplate__ParseGroupFlags  0x0049B3E0 ----  [CONFIRMED] */
/* Parses up to four interpolation keywords into a group-flags word.  Second
 * arg is unused.  Returns 0 on a NULL output, 1 while more tokens remain, and
 * the "all recognised" flag once every token has been consumed. */
char __stdcall CPrimitiveTemplate__ParseGroupFlags( unsigned int *outFlags, int unused, char *text )
{
  char  ok;
  int   count;
  int   i;

  if ( !outFlags )
    return 0;

  {
  char flags[4][32]={"\0","\0","\0","0"};
  ok = 1;
  count = sscanf( text, "%s %s %s %s", flags[0], flags[1], flags[2], flags[3] );
  *outFlags = 0;

  for ( i = 0; i < 4; i++ )
  {
    if ( i + 1 > count )
      return 1;

    if ( !_stricmp( flags[i], "linear" ) )
      *outFlags |= 1u;
    else if ( !_stricmp( flags[i], "nonlinear" ) )
      *outFlags |= 4u;
    else if ( !_stricmp( flags[i], "wave" ) )
      *outFlags |= 8u;
    else if ( !_stricmp( flags[i], "random" ) )
      *outFlags |= 2u;
    else if ( !_stricmp( flags[i], "clamp" ) )
      *outFlags |= 0xCu;
    else
      ok = 0;

  }
  return ok;
  }
}

/* ---- CPrimitiveTemplate__ParseMin_m  0x0049B550 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseMin_m( unsigned int *tmpl, char *text )
{
  float vec[3];

  if ( CPrimitiveTemplate__ParseVector( (int)tmpl, text, vec, vec ) == 1 ) {
  FX_TMPL(tmpl)->mMin[0] = vec[0];
  FX_TMPL(tmpl)->mMin[1] = vec[1];
  FX_TMPL(tmpl)->mMin[2] = vec[2];
  *(unsigned int *)( (char *)tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x6000000u;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseMax_m  0x0049B5A0 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseMax_m( unsigned int *tmpl, char *text )
{
  float vec[3];

  if ( CPrimitiveTemplate__ParseVector( (int)tmpl, text, vec, vec ) == 1 ) {
  FX_TMPL(tmpl)->mMax[0] = vec[0];
  FX_TMPL(tmpl)->mMax[1] = vec[1];
  FX_TMPL(tmpl)->mMax[2] = vec[2];
  *(unsigned int *)( (char *)tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x6000000u;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseLife_m  0x0049B5F0 ----  [HIGH] */
/* Shared shape of the scalar "start [end]" field parsers below: scan one or
 * two floats; the start goes to the lower field, the end (defaulting to the
 * start when only one value is given) to the higher one.  The end is a float
 * local: a double one gives the same bytes but makes LTCG keep the stack
 * 8-byte aligned through every caller (RegisterEffect, ParsePrimitive, ...). */
char __cdecl CPrimitiveTemplate__ParseLife_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mLife.mMin = startVal;
  FX_TMPL(tmpl)->mLife.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseDelay_m  0x0049B650 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseDelay_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mSpawnDelay.mMin = startVal;
  FX_TMPL(tmpl)->mSpawnDelay.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseCount  0x0049B6B0 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseCount( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mSpawnCount.mMin = startVal;
  FX_TMPL(tmpl)->mSpawnCount.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseElasticity  0x0049B710 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseElasticity( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mElasticity.mMin = startVal;
  FX_TMPL(tmpl)->mElasticity.mMax = endVal;
  *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x2000000u;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseOrigin_m  0x0049B770 ----  VERIFIED */
/* Shared shape of the vec3 "base [range]" field parsers below: ParseVector
 * fills base[] and range[] (range mirrors base when only three values are
 * given), then the six words are scattered base/range-interleaved into the
 * template starting at the field index shown. */
char __cdecl CPrimitiveTemplate__ParseOrigin_m( unsigned int *tmpl, char *text )
{
  float base[3];  
  float range[3]; 

  if ( CPrimitiveTemplate__ParseVector( (int)tmpl, text, base, range ) == 1 ) {
  CFxRange__SetRange( (float *)tmpl + 55, base[0], range[0] );
  CFxRange__SetRange( (float *)tmpl + 57, base[1], range[1] );
  CFxRange__SetRange( (float *)tmpl + 59, base[2], range[2] );
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseOrigin2_m  0x0049B7E0 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseOrigin2_m( unsigned int *tmpl, char *text )
{
  float base[3];  
  float range[3]; 

  if ( CPrimitiveTemplate__ParseVector( (int)tmpl, text, base, range ) == 1 ) {
  CFxRange__SetRange( (float *)tmpl + 61, base[0], range[0] );
  CFxRange__SetRange( (float *)tmpl + 63, base[1], range[1] );
  CFxRange__SetRange( (float *)tmpl + 65, base[2], range[2] );
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseRadius_m  0x0049B850 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseRadius_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mRadius.mMin = startVal;
  FX_TMPL(tmpl)->mRadius.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseHeight_m  0x0049B8A0 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseHeight_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mHeight.mMin = startVal;
  FX_TMPL(tmpl)->mHeight.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseWind_m  0x0049B8F0 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseWind_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mWindModifier.mMin = startVal;
  FX_TMPL(tmpl)->mWindModifier.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseRotation_m  0x0049B940 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseRotation_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mRotation.mMin = startVal;
  FX_TMPL(tmpl)->mRotation.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseRotationDelta_m  0x0049B990 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseRotationDelta_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mRotationDelta.mMin = startVal;
  FX_TMPL(tmpl)->mRotationDelta.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseAngle_m  0x0049B9E0 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseAngle_m( unsigned int *tmpl, char *text )
{
  float base[3];  
  float range[3]; 

  if ( CPrimitiveTemplate__ParseVector( (int)tmpl, text, base, range ) == 1 ) {
  CFxRange__SetRange( (float *)tmpl + 77, base[0], range[0] );
  CFxRange__SetRange( (float *)tmpl + 79, base[1], range[1] );
  CFxRange__SetRange( (float *)tmpl + 81, base[2], range[2] );
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseAngleDelta_m  0x0049BA50 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseAngleDelta_m( unsigned int *tmpl, char *text )
{
  float base[3];  
  float range[3]; 

  if ( CPrimitiveTemplate__ParseVector( (int)tmpl, text, base, range ) == 1 ) {
  CFxRange__SetRange( (float *)tmpl + 83, base[0], range[0] );
  CFxRange__SetRange( (float *)tmpl + 85, base[1], range[1] );
  CFxRange__SetRange( (float *)tmpl + 87, base[2], range[2] );
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseVelocity_m  0x0049BAC0 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseVelocity_m( unsigned int *tmpl, char *text )
{
  float base[3];  
  float range[3]; 

  if ( CPrimitiveTemplate__ParseVector( (int)tmpl, text, base, range ) == 1 ) {
  CFxRange__SetRange( (float *)tmpl + 89, base[0], range[0] );
  CFxRange__SetRange( (float *)tmpl + 91, base[1], range[1] );
  CFxRange__SetRange( (float *)tmpl + 93, base[2], range[2] );
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseFlags  0x0049BB30 ----  VERIFIED */
char __stdcall CPrimitiveTemplate__ParseFlags( int tmpl, char *text )
{
  char flags[7][32]={"\0","\0","\0","\0","\0","\0","\0"};
  char  ok;
  int   count;
  int   i;

  ok = 1;

  count = sscanf( text, "%s %s %s %s %s %s %s",
                  flags[0], flags[1], flags[2], flags[3],
                  flags[4], flags[5], flags[6] );

  for ( i = 0; i < 7; i++ )
  {
    if ( i + 1 > count )
      return 1;

    if ( !_stricmp( flags[i], "useModel" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x01000000u;
    else if ( !_stricmp( flags[i], "useBBox" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x04000000u;
    else if ( !_stricmp( flags[i], "usePhysics" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x02000000u;
    else if ( !_stricmp( flags[i], "expensivePhysics" ) )
      ;
    else if ( !_stricmp( flags[i], "impactKills" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x40000000u;
    else if ( !_stricmp( flags[i], "impactFx" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x80000000u;
    else if ( !_stricmp( flags[i], "deathFx" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x20000000u;
    else if ( !_stricmp( flags[i], "useAlpha" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x08000000u;
    else if ( !_stricmp( flags[i], "emitFx" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x10000000u;
    else if ( !_stricmp( flags[i], "depthHack" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x00100000u;
    else if ( !_stricmp( flags[i], "relative" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x00200000u;
    else if ( !_stricmp( flags[i], "setShaderTime" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x00400000u;
    else if ( !_stricmp( flags[i], "continualLighting" ) )
      *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x00800000u;
    else
      ok = 0;

  }
  return ok;
}

/* ---- CPrimitiveTemplate__ParseSpawnFlags  0x0049BE30 ----  [CONFIRMED] */
char __stdcall CPrimitiveTemplate__ParseSpawnFlags( int tmpl, char *text )
{
  char flags[7][32]={"\0","\0","\0","\0","\0","\0","\0"}; 
  char  ok;
  int   count;
  int   i;

  ok = 1;
  count = sscanf( text, "%s %s %s %s %s %s %s",
                  flags[0], flags[1], flags[2], flags[3],
                  flags[4], flags[5], flags[6] );

  for ( i = 0; i < 7; i++ )
  {
    if ( i + 1 > count )
      return 1;

    if ( !_stricmp( flags[i], "org2fromTrace" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x10u;
    else if ( !_stricmp( flags[i], "traceImpactFx" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x20u;
    else if ( !_stricmp( flags[i], "org2isOffset" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x40u;
    else if ( !_stricmp( flags[i], "cheapOrgCalc" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x100u;
    else if ( !_stricmp( flags[i], "cheapOrg2Calc" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x200u;
    else if ( !_stricmp( flags[i], "absoluteVel" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x400u;
    else if ( !_stricmp( flags[i], "absoluteAccel" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x800u;
    else if ( !_stricmp( flags[i], "orgOnSphere" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 1u;
    else if ( !_stricmp( flags[i], "orgOnCylinder" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 4u;
    else if ( !_stricmp( flags[i], "axisFromSphere" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 2u;
    else if ( !_stricmp( flags[i], "randrotaroundfwd" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x1000u;
    else if ( !_stricmp( flags[i], "evenDistribution" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x2000u;
    else if ( !_stricmp( flags[i], "rgbComponentInterpolation" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x4000u;
    else if ( !_stricmp( flags[i], "affectedByWind" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x10000u;
    else if ( !_stricmp( flags[i], "lessAttenuation" ) )
      *(unsigned int *)&FX_TMPL(tmpl)->mSpawnFlags |= 0x20000u;
    else
      ok = 0;

  }
  return ok;
}

/* ---- CPrimitiveTemplate__ParseAcceleration_m  0x0049C170 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseAcceleration_m( unsigned int *tmpl, char *text )
{
  float base[3];  
  float range[3]; 

  if ( CPrimitiveTemplate__ParseVector( (int)tmpl, text, base, range ) == 1 ) {
  CFxRange__SetRange( (float *)tmpl + 95, base[0], range[0] );
  CFxRange__SetRange( (float *)tmpl + 97, base[1], range[1] );
  CFxRange__SetRange( (float *)tmpl + 99, base[2], range[2] );
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseGravity_m  0x0049C1E0 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseGravity_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mGravity.mMin = startVal;
  FX_TMPL(tmpl)->mGravity.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseDensity_m  0x0049C230 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseDensity_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mDensity.mMin = startVal;
  FX_TMPL(tmpl)->mDensity.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseVariance_m  0x0049C280 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseVariance_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mVariance.mMin = startVal;
  FX_TMPL(tmpl)->mVariance.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseRGBStart_m  0x0049C2D0 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseRGBStart_m( char *text, unsigned int *tmpl )
{
  float base[3];  
  float range[3]; 

  if ( CPrimitiveTemplate__ParseVector( (int)tmpl, text, base, range ) == 1 ) {
  CFxRange__SetRange( (float *)tmpl + 107, base[0], range[0] );
  CFxRange__SetRange( (float *)tmpl + 109, base[1], range[1] );
  CFxRange__SetRange( (float *)tmpl + 111, base[2], range[2] );
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseRGBEnd_m  0x0049C340 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseRGBEnd_m( char *text, unsigned int *tmpl )
{
  float base[3];  
  float range[3]; 

  if ( CPrimitiveTemplate__ParseVector( (int)tmpl, text, base, range ) == 1 ) {
  CFxRange__SetRange( (float *)tmpl + 113, base[0], range[0] );
  CFxRange__SetRange( (float *)tmpl + 115, base[1], range[1] );
  CFxRange__SetRange( (float *)tmpl + 117, base[2], range[2] );
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseRGBParm_m  0x0049C3B0 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseRGBParm_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mRGBParm.mMin = startVal;
  FX_TMPL(tmpl)->mRGBParm.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseRGBFlags_m  0x0049C400 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseRGBFlags_m( char *text, int tmpl )
{
  unsigned int groupFlags; 

  if ( CPrimitiveTemplate__ParseGroupFlags( &groupFlags, tmpl, text ) == 1 ) {
  *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= groupFlags << 4;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseAlphaStart_m  0x0049C430 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseAlphaStart_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mAlphaStart.mMin = startVal;
  FX_TMPL(tmpl)->mAlphaStart.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseAlphaEnd_m  0x0049C480 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseAlphaEnd_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mAlphaEnd.mMin = startVal;
  FX_TMPL(tmpl)->mAlphaEnd.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseAlphaParm_m  0x0049C4D0 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseAlphaParm_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mAlphaParm.mMin = startVal;
  FX_TMPL(tmpl)->mAlphaParm.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseAlphaFlags_m  0x0049C520 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseAlphaFlags_m( char *text, int tmpl )
{
  int groupFlags; 

  if ( CPrimitiveTemplate__ParseGroupFlags( (unsigned int *)&groupFlags, tmpl, text ) == 1 ) {
  *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= groupFlags;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseSizeStart_m  0x0049C550 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseSizeStart_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mSizeStart.mMin = startVal;
  FX_TMPL(tmpl)->mSizeStart.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseSizeEnd_m  0x0049C5A0 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseSizeEnd_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mSizeEnd.mMin = startVal;
  FX_TMPL(tmpl)->mSizeEnd.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseSizeParm_m  0x0049C5F0 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseSizeParm_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mSizeParm.mMin = startVal;
  FX_TMPL(tmpl)->mSizeParm.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseSizeFlags_m  0x0049C640 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseSizeFlags_m( char *text, int tmpl )
{
  int groupFlags; 

  if ( CPrimitiveTemplate__ParseGroupFlags( (unsigned int *)&groupFlags, tmpl, text ) == 1 ) {
  *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= groupFlags << 8;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseSize2Start_m  0x0049C670 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseSize2Start_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mSize2Start.mMin = startVal;
  FX_TMPL(tmpl)->mSize2Start.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseSize2End_m  0x0049C6C0 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseSize2End_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mSize2End.mMin = startVal;
  FX_TMPL(tmpl)->mSize2End.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseSize2Parm_m  0x0049C710 ----  [HIGH] */
/* One more scalar "start [end]" field parser (see CPrimitiveTemplate__ParseLife_m
 * for the shared shape): the end widens to double and re-narrows on store. */
char __cdecl CPrimitiveTemplate__ParseSize2Parm_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mSize2Parm.mMin = startVal;
  FX_TMPL(tmpl)->mSize2Parm.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseSize2Flags_m  0x0049C760 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseSize2Flags_m( char *text, int tmpl )
{
  int groupFlags; 

  if ( CPrimitiveTemplate__ParseGroupFlags( (unsigned int *)&groupFlags, tmpl, text ) == 1 ) {
  *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= groupFlags << 16;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseLengthStart_m  0x0049C790 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseLengthStart_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mLengthStart.mMin = startVal;
  FX_TMPL(tmpl)->mLengthStart.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseLengthEnd_m  0x0049C7E0 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseLengthEnd_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mLengthEnd.mMin = startVal;
  FX_TMPL(tmpl)->mLengthEnd.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseLengthParm_m  0x0049C830 ----  [HIGH] */
char __cdecl CPrimitiveTemplate__ParseLengthParm_m( const char *text, int tmpl )
{
  int    count;
  float  endVal;
  float  startVal; 
  float  endScan;  

  count = sscanf( text, "%f %f", &startVal, &endScan );
  if(count) {
  endVal = ( count == 1 ) ? startVal : endScan;
  FX_TMPL(tmpl)->mLengthParm.mMin = startVal;
  FX_TMPL(tmpl)->mLengthParm.mMax = endVal;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseLengthFlags_m  0x0049C880 ----  VERIFIED */
char __cdecl CPrimitiveTemplate__ParseLengthFlags_m( char *text, int tmpl )
{
  int groupFlags; 

  if ( CPrimitiveTemplate__ParseGroupFlags( (unsigned int *)&groupFlags, tmpl, text ) == 1 ) {
  *(unsigned int *)( tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= groupFlags << 12;
  return 1;
  }
  return 0;
}

/* ---- CPrimitiveTemplate__ParseShaders  0x0049C8B0 ----  [CONFIRMED] */
/* Registers each shader named in the value's list (theFxHelper.RegisterShader)
 * and adds its handle to mMediaHandles (+0x68). */
char __cdecl CPrimitiveTemplate__ParseShaders( int tmpl, int node )
{
  const char  *val;
  int          handle;

  if ( ( (CGPValue *)node )->mList && ( (CGPValue *)node )->mList->mNext )   /* grp->IsList() */
  {
    CGPObject *list = ( (CGPValue *)node )->mList;   /* grp->GetList() */

    while ( list )
    {
      /* name is actually the value contained in the list */
      val    = list->mName;
      handle = ( *(int (**)(FX_ANYARGS))&re.RegisterShader )( val, 9 );
      FX_MEDIA_ADD_HANDLE( &FX_TMPL(tmpl)->mMediaHandles, handle )
      list = list->mNext;
    }
  }
  else
  {
    val = ( (CGPValue *)node )->mList ? ( (CGPValue *)node )->mList->mName : 0;   /* grp->GetTopValue() */
    if ( val )
    {
      handle = ( *(int (**)(FX_ANYARGS))&re.RegisterShader )( val, 9 );
      stl_fxIntVector_pushBack_m( (unsigned int *)&handle, (unsigned int *)&FX_TMPL(tmpl)->mMediaHandles );
    }
    else
    {
      /* empty "list" */
      SFxHelper__Print( (int)&theFxHelper, "CPrimitiveTemplate::ParseShaders called with an empty list!\n" );
      return 0;
    }
  }
  return 1;
}

/* ---- CPrimitiveTemplate__ParseSounds  0x0049C9A0 ----  [CONFIRMED] */
/* Resolves each named sound alias to its 1-based table index (0 if unknown,
 * theFxHelper.RegisterSound) and adds it to mMediaHandles (+0x68). */
char __cdecl CPrimitiveTemplate__ParseSounds( int tmpl, int node )
{
  const char  *val;
  int          handle;

  if ( ( (CGPValue *)node )->mList && ( (CGPValue *)node )->mList->mNext )   /* grp->IsList() */
  {
    CGPObject *list = ( (CGPValue *)node )->mList;   /* grp->GetList() */

    while ( list )
    {
      /* name is actually the value contained in the list */
      val    = list->mName;
      handle = SFxHelper__RegisterSound( val, &theFxHelper );
      FX_MEDIA_ADD_HANDLE( &FX_TMPL(tmpl)->mMediaHandles, handle )
      list = list->mNext;
    }
  }
  else
  {
    val = ( (CGPValue *)node )->mList ? ( (CGPValue *)node )->mList->mName : 0;   /* grp->GetTopValue() */
    if ( val )
    {
      handle = SFxHelper__RegisterSound( val, &theFxHelper );
      stl_fxIntVector_pushBack_m( (unsigned int *)&handle, (unsigned int *)&FX_TMPL(tmpl)->mMediaHandles );
    }
    else
    {
      /* empty "list" */
      SFxHelper__Print( (int)&theFxHelper, "CPrimitiveTemplate::ParseSounds called with an empty list!\n" );
      return 0;
    }
  }
  return 1;
}

/* ---- CPrimitiveTemplate__ParseModels  0x0049CAE0 ----  [CONFIRMED] */
/* Registers each named model, adds its handle to mMediaHandles (+0x68) and
 * marks the primitive as having models. */
char __stdcall CPrimitiveTemplate__ParseModels( int node, unsigned int *tmpl )
{
  const char  *val;
  int          handle;

  if ( ( (CGPValue *)node )->mList && ( (CGPValue *)node )->mList->mNext )   /* grp->IsList() */
  {
    CGPObject *list = ( (CGPValue *)node )->mList;   /* grp->GetList() */

    while ( list )
    {
      /* name is actually the value contained in the list */
      val    = list->mName;
      handle = (int)CFxModel__Register( (char *)val );
      FX_MEDIA_ADD_HANDLE( tmpl + 26, handle )
      list = list->mNext;
    }
  }
  else
  {
    val = ( (CGPValue *)node )->mList ? ( (CGPValue *)node )->mList->mName : 0;   /* grp->GetTopValue() */
    if ( val )
    {
      handle = (int)CFxModel__Register( (char *)val );
      stl_fxIntVector_pushBack_m( (unsigned int *)&handle, tmpl + 26 );
    }
    else
    {
      /* empty "list" */
      SFxHelper__Print( (int)&theFxHelper, "CPrimitiveTemplate::ParseModels called with an empty list!\n" );
      return 0;
    }
  }

  *(unsigned int *)( (char *)tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x1000000;
  return 1;
}

/* ---- CPrimitiveTemplate__ParseImpactFxStrings  0x0049CBD0 ----  [CONFIRMED] */
/* Registers each named effect and adds its handle to mImpactFxHandles (+0x78), then sets its flag. */
char __stdcall CPrimitiveTemplate__ParseImpactFxStrings( int node, unsigned int *tmpl )
{
  const char  *val;
  int          handle;

  if ( ( (CGPValue *)node )->mList && ( (CGPValue *)node )->mList->mNext )   /* grp->IsList() */
  {
    CGPObject *list = ( (CGPValue *)node )->mList;   /* grp->GetList() */

    while ( list )
    {
      /* name is actually the value contained in the list */
      val    = list->mName;
      handle = CFxScheduler__RegisterEffect( theFxScheduler, val, 0 );
      if ( handle )
        FX_MEDIA_ADD_HANDLE( tmpl + 30, handle )
      else
      {
        SFxHelper__Print( (int)&theFxHelper, "FxTemplate: Impact effect file not found.\n" );
        return 0;
      }
      list = list->mNext;
    }
  }
  else
  {
    val = ( (CGPValue *)node )->mList ? ( (CGPValue *)node )->mList->mName : 0;   /* grp->GetTopValue() */
    if ( val )
    {
      handle = CFxScheduler__RegisterEffect( theFxScheduler, val, 0 );
      if ( handle )
      {
        int item = handle;   /* AddHandle( int item ) */
        stl_fxIntVector_pushBack_m( (unsigned int *)&item, tmpl + 30 );
      }
      else
      {
        SFxHelper__Print( (int)&theFxHelper, "FxTemplate: Impact effect file not found.\n" );
        return 0;
      }
    }
    else
    {
      /* empty "list" */
      SFxHelper__Print( (int)&theFxHelper, "CPrimitiveTemplate::ParseImpactFxStrings called with an empty list!\n" );
      return 0;
    }
  }

  *(unsigned int *)( (char *)tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x82000000;
  return 1;
}

/* ---- CPrimitiveTemplate__ParseDeathFxStrings  0x0049CCE0 ----  [CONFIRMED] */
/* Registers each named effect and adds its handle to mDeathFxHandles (+0x88), then sets its flag. */
char __stdcall CPrimitiveTemplate__ParseDeathFxStrings( int node, unsigned int *tmpl )
{
  const char  *val;
  int          handle;

  if ( ( (CGPValue *)node )->mList && ( (CGPValue *)node )->mList->mNext )   /* grp->IsList() */
  {
    CGPObject *list = ( (CGPValue *)node )->mList;   /* grp->GetList() */

    while ( list )
    {
      /* name is actually the value contained in the list */
      val    = list->mName;
      handle = CFxScheduler__RegisterEffect( theFxScheduler, val, 0 );
      if ( handle )
        FX_MEDIA_ADD_HANDLE( tmpl + 34, handle )
      else
      {
        SFxHelper__Print( (int)&theFxHelper, "FxTemplate: Death effect file not found.\n" );
        return 0;
      }
      list = list->mNext;
    }
  }
  else
  {
    val = ( (CGPValue *)node )->mList ? ( (CGPValue *)node )->mList->mName : 0;   /* grp->GetTopValue() */
    if ( val )
    {
      handle = CFxScheduler__RegisterEffect( theFxScheduler, val, 0 );
      if ( handle )
      {
        int item = handle;   /* AddHandle( int item ) */
        stl_fxIntVector_pushBack_m( (unsigned int *)&item, tmpl + 34 );
      }
      else
      {
        SFxHelper__Print( (int)&theFxHelper, "FxTemplate: Death effect file not found.\n" );
        return 0;
      }
    }
    else
    {
      /* empty "list" */
      SFxHelper__Print( (int)&theFxHelper, "CPrimitiveTemplate::ParseDeathFxStrings called with an empty list!\n" );
      return 0;
    }
  }

  *(unsigned int *)( (char *)tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x20000000u;
  return 1;
}

/* ---- CPrimitiveTemplate__ParseEmitterFxStrings  0x0049CE00 ----  [CONFIRMED] */
/* Registers each named effect and adds its handle to mEmitterFxHandles (+0x98), then sets its flag. */
char __stdcall CPrimitiveTemplate__ParseEmitterFxStrings( int node, unsigned int *tmpl )
{
  const char  *val;
  int          handle;

  if ( ( (CGPValue *)node )->mList && ( (CGPValue *)node )->mList->mNext )   /* grp->IsList() */
  {
    CGPObject *list = ( (CGPValue *)node )->mList;   /* grp->GetList() */

    while ( list )
    {
      /* name is actually the value contained in the list */
      val    = list->mName;
      handle = CFxScheduler__RegisterEffect( theFxScheduler, val, 0 );
      if ( handle )
        FX_MEDIA_ADD_HANDLE( tmpl + 38, handle )
      else
      {
        SFxHelper__Print( (int)&theFxHelper, "FxTemplate: Emitter effect file not found.\n" );
        return 0;
      }
      list = list->mNext;
    }
  }
  else
  {
    val = ( (CGPValue *)node )->mList ? ( (CGPValue *)node )->mList->mName : 0;   /* grp->GetTopValue() */
    if ( val )
    {
      handle = CFxScheduler__RegisterEffect( theFxScheduler, val, 0 );
      if ( handle )
      {
        int item = handle;   /* AddHandle( int item ) */
        stl_fxIntVector_pushBack_m( (unsigned int *)&item, tmpl + 38 );
      }
      else
      {
        SFxHelper__Print( (int)&theFxHelper, "FxTemplate: Emitter effect file not found.\n" );
        return 0;
      }
    }
    else
    {
      /* empty "list" */
      SFxHelper__Print( (int)&theFxHelper, "CPrimitiveTemplate::ParseEmitterFxStrings called with an empty list!\n" );
      return 0;
    }
  }

  *(unsigned int *)( (char *)tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= 0x10000000u;
  return 1;
}

/* ---- CPrimitiveTemplate__ParsePlayFxStrings  0x0049CF20 ----  [CONFIRMED] */
/* Registers each named effect and adds its handle to mPlayFxHandles (+0xA8). */
char __stdcall CPrimitiveTemplate__ParsePlayFxStrings( int node, unsigned int *tmpl )
{
  const char  *val;
  int          handle;

  if ( ( (CGPValue *)node )->mList && ( (CGPValue *)node )->mList->mNext )   /* grp->IsList() */
  {
    CGPObject *list = ( (CGPValue *)node )->mList;   /* grp->GetList() */

    while ( list )
    {
      /* name is actually the value contained in the list */
      val    = list->mName;
      handle = CFxScheduler__RegisterEffect( theFxScheduler, val, 0 );
      if ( handle )
        FX_MEDIA_ADD_HANDLE( tmpl + 42, handle )
      else
      {
        SFxHelper__Print( (int)&theFxHelper, "FxTemplate: Effect file not found.\n" );
        return 0;
      }
      list = list->mNext;
    }
  }
  else
  {
    val = ( (CGPValue *)node )->mList ? ( (CGPValue *)node )->mList->mName : 0;   /* grp->GetTopValue() */
    if ( val )
    {
      handle = CFxScheduler__RegisterEffect( theFxScheduler, val, 0 );
      if ( handle )
      {
        int item = handle;   /* AddHandle( int item ) */
        stl_fxIntVector_pushBack_m( (unsigned int *)&item, tmpl + 42 );
      }
      else
      {
        SFxHelper__Print( (int)&theFxHelper, "FxTemplate: Effect file not found.\n" );
        return 0;
      }
    }
    else
    {
      /* empty "list" */
      SFxHelper__Print( (int)&theFxHelper, "CPrimitiveTemplate::ParsePlayFxStrings called with an empty list!\n" );
      return 0;
    }
  }

  return 1;
}

/* ---- CPrimitiveTemplate__ParseRGB  0x0049D040 ----  [CONFIRMED] */
/* Fills the RGB group's fields: "start" -> interleaved (base,range) vec3 at
 * +0x1AC, the "end" keyword -> ParseRGBEnd_m, "parm" -> the scalar pair at
 * +0x1DC, and "flags" -> the group-flags nibble at bits 4-7. */
char __cdecl CPrimitiveTemplate__ParseRGB( unsigned int *tmpl, int node )
{
  int         pair;
  char      **valuePtr;
  const char *key;
  char       *val;
  int         count;
  float         parmLo;     
  float         parmHi;     
  int         groupFlags; 
  float       base[3];    
  float       range[3];   

  for ( pair = *(unsigned int *)( node + FX_GPGROUP_OFS( mPairs ) ); pair; pair = *(unsigned int *)( pair + FX_GPVALUE_OFS( mNext ) ) )
  {
    valuePtr = *(char ***)( pair + FX_GPVALUE_OFS( mList ) );
    key      = *(const char **)pair;
    val      = valuePtr ? *valuePtr : 0;

    if ( !_stricmp( key, "start" ) )
    {
      if ( CPrimitiveTemplate__ParseVector( (int)tmpl, val, base, range ) == 1 )
      {
        FX_TMPL(tmpl)->mRedStart.mMin = base[0];
        FX_TMPL(tmpl)->mRedStart.mMax = range[0];
        FX_TMPL(tmpl)->mGreenStart.mMin = base[1];
        FX_TMPL(tmpl)->mGreenStart.mMax = range[1];
        FX_TMPL(tmpl)->mBlueStart.mMin = base[2];
        FX_TMPL(tmpl)->mBlueStart.mMax = range[2];
      }
    }
    else if ( !_stricmp( key, "end" ) )
    {
      CPrimitiveTemplate__ParseRGBEnd_m( val, tmpl );
    }
    else if ( !_stricmp( key, "parm" ) || !_stricmp( key, "parms" ) )
    {
      count = sscanf( val, "%f %f", &parmLo, &parmHi );
      if ( count )
      {
        if ( count == 1 )
          parmHi = parmLo;
        FX_TMPL(tmpl)->mRGBParm.mMin = parmLo;
        FX_TMPL(tmpl)->mRGBParm.mMax = parmHi;
      }
    }
    else if ( !_stricmp( key, "flags" ) || !_stricmp( key, "flag" ) )
    {
      if ( CPrimitiveTemplate__ParseGroupFlags( (unsigned int *)&groupFlags, (int)tmpl, val ) == 1 )
        *(unsigned int *)( (char *)tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= groupFlags << 4;
    }
    else
    {
      SFxHelper__Print( (int)&theFxHelper, "Unknown key parsing an RGB group: %s\n", key );
    }
  }
  return 1;
}

/* ---- CPrimitiveTemplate__ParseAlpha  0x0049D1D0 ----  [CONFIRMED] */
/* Scalar "start"/"end"/"parm" pairs at +0x1E4..+0x1F8 plus a group-flags word.
 * Each pair scans one or two floats; a single value duplicates into the high
 * slot. */
char __stdcall CPrimitiveTemplate__ParseAlpha( int node, unsigned int *tmpl )
{
  int         pair;
  char      **valuePtr;
  const char *key;
  char       *val;
  int         count;
  float         startLo;    
  float         startHi;    
  float         endLo;      
  float         endHi;      
  float         parmLo;     
  float         parmHi;     
  int         groupFlags; 

  for ( pair = *(unsigned int *)( node + FX_GPGROUP_OFS( mPairs ) ); pair; pair = *(unsigned int *)( pair + FX_GPVALUE_OFS( mNext ) ) )
  {
    valuePtr = *(char ***)( pair + FX_GPVALUE_OFS( mList ) );
    key      = *(const char **)pair;
    val      = valuePtr ? *valuePtr : 0;

    if ( !_stricmp( key, "start" ) )
    {
      count = sscanf( val, "%f %f", &startLo, &startHi );
      if ( count )
      {
        if ( count == 1 )
          startHi = startLo;
        FX_TMPL(tmpl)->mAlphaStart.mMin = startLo;
        FX_TMPL(tmpl)->mAlphaStart.mMax = startHi;
      }
    }
    else if ( !_stricmp( key, "end" ) )
    {
      count = sscanf( val, "%f %f", &endLo, &endHi );
      if ( count )
      {
        if ( count == 1 )
          endHi = endLo;
        FX_TMPL(tmpl)->mAlphaEnd.mMin = endLo;
        FX_TMPL(tmpl)->mAlphaEnd.mMax = endHi;
      }
    }
    else if ( !_stricmp( key, "parm" ) || !_stricmp( key, "parms" ) )
    {
      count = sscanf( val, "%f %f", &parmLo, &parmHi );
      if ( count )
      {
        if ( count == 1 )
          parmHi = parmLo;
        FX_TMPL(tmpl)->mAlphaParm.mMin = parmLo;
        FX_TMPL(tmpl)->mAlphaParm.mMax = parmHi;
      }
    }
    else if ( !_stricmp( key, "flags" ) || !_stricmp( key, "flag" ) )
    {
      if ( CPrimitiveTemplate__ParseGroupFlags( (unsigned int *)&groupFlags, (int)tmpl, val ) == 1 )
        *(unsigned int *)( (char *)tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= groupFlags;
    }
    else
    {
      SFxHelper__Print( (int)&theFxHelper, "Unknown key parsing an Alpha group: %s\n", key );
    }
  }
  return 1;
}

/* ---- CPrimitiveTemplate__ParseSize  0x0049D380 ----  [CONFIRMED] */
/* Scalar "start"/"end"/"parm" pairs at +0x1FC..+0x210; group flags into
 * bits 8-11 (see ParseAlpha for the shared shape). */
char __stdcall CPrimitiveTemplate__ParseSize( int node, unsigned int *tmpl )
{
  int         pair;
  char      **valuePtr;
  const char *key;
  char       *val;
  int         count;
  float         startLo;    
  float         startHi;    
  float         endLo;      
  float         endHi;      
  float         parmLo;     
  float         parmHi;     
  int         groupFlags; 

  for ( pair = *(unsigned int *)( node + FX_GPGROUP_OFS( mPairs ) ); pair; pair = *(unsigned int *)( pair + FX_GPVALUE_OFS( mNext ) ) )
  {
    valuePtr = *(char ***)( pair + FX_GPVALUE_OFS( mList ) );
    key      = *(const char **)pair;
    val      = valuePtr ? *valuePtr : 0;

    if ( !_stricmp( key, "start" ) )
    {
      count = sscanf( val, "%f %f", &startLo, &startHi );
      if ( count )
      {
        if ( count == 1 )
          startHi = startLo;
        FX_TMPL(tmpl)->mSizeStart.mMin = startLo;
        FX_TMPL(tmpl)->mSizeStart.mMax = startHi;
      }
    }
    else if ( !_stricmp( key, "end" ) )
    {
      count = sscanf( val, "%f %f", &endLo, &endHi );
      if ( count )
      {
        if ( count == 1 )
          endHi = endLo;
        FX_TMPL(tmpl)->mSizeEnd.mMin = endLo;
        FX_TMPL(tmpl)->mSizeEnd.mMax = endHi;
      }
    }
    else if ( !_stricmp( key, "parm" ) || !_stricmp( key, "parms" ) )
    {
      count = sscanf( val, "%f %f", &parmLo, &parmHi );
      if ( count )
      {
        if ( count == 1 )
          parmHi = parmLo;
        FX_TMPL(tmpl)->mSizeParm.mMin = parmLo;
        FX_TMPL(tmpl)->mSizeParm.mMax = parmHi;
      }
    }
    else if ( !_stricmp( key, "flags" ) || !_stricmp( key, "flag" ) )
    {
      if ( CPrimitiveTemplate__ParseGroupFlags( (unsigned int *)&groupFlags, (int)tmpl, val ) == 1 )
        *(unsigned int *)( (char *)tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= groupFlags << 8;
    }
    else
    {
      SFxHelper__Print( (int)&theFxHelper, "Unknown key parsing a Size group: %s\n", key );
    }
  }
  return 1;
}

/* ---- CPrimitiveTemplate__ParseSize2  0x0049D530 ----  [CONFIRMED] */
/* Scalar "start"/"end"/"parm" pairs at +0x214..+0x228; group flags into
 * bits 16-19 (see ParseAlpha for the shared shape). */
char __stdcall CPrimitiveTemplate__ParseSize2( int node, unsigned int *tmpl )
{
  int         pair;
  char      **valuePtr;
  const char *key;
  char       *val;
  int         count;
  float         startLo;    
  float         startHi;    
  float         endLo;      
  float         endHi;      
  float         parmLo;     
  float         parmHi;     
  int         groupFlags; 

  for ( pair = *(unsigned int *)( node + FX_GPGROUP_OFS( mPairs ) ); pair; pair = *(unsigned int *)( pair + FX_GPVALUE_OFS( mNext ) ) )
  {
    valuePtr = *(char ***)( pair + FX_GPVALUE_OFS( mList ) );
    key      = *(const char **)pair;
    val      = valuePtr ? *valuePtr : 0;

    if ( !_stricmp( key, "start" ) )
    {
      count = sscanf( val, "%f %f", &startLo, &startHi );
      if ( count )
      {
        if ( count == 1 )
          startHi = startLo;
        FX_TMPL(tmpl)->mSize2Start.mMin = startLo;
        FX_TMPL(tmpl)->mSize2Start.mMax = startHi;
      }
    }
    else if ( !_stricmp( key, "end" ) )
    {
      count = sscanf( val, "%f %f", &endLo, &endHi );
      if ( count )
      {
        if ( count == 1 )
          endHi = endLo;
        FX_TMPL(tmpl)->mSize2End.mMin = endLo;
        FX_TMPL(tmpl)->mSize2End.mMax = endHi;
      }
    }
    else if ( !_stricmp( key, "parm" ) || !_stricmp( key, "parms" ) )
    {
      count = sscanf( val, "%f %f", &parmLo, &parmHi );
      if ( count )
      {
        if ( count == 1 )
          parmHi = parmLo;
        FX_TMPL(tmpl)->mSize2Parm.mMin = parmLo;
        FX_TMPL(tmpl)->mSize2Parm.mMax = parmHi;
      }
    }
    else if ( !_stricmp( key, "flags" ) || !_stricmp( key, "flag" ) )
    {
      if ( CPrimitiveTemplate__ParseGroupFlags( (unsigned int *)&groupFlags, (int)tmpl, val ) == 1 )
        *(unsigned int *)( (char *)tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= groupFlags << 16;
    }
    else
    {
      SFxHelper__Print( (int)&theFxHelper, "Unknown key parsing a Size2 group: %s\n", key );
    }
  }
  return 1;
}

/* ---- CPrimitiveTemplate__ParseLength  0x0049D6E0 ----  [CONFIRMED] */
/* Scalar "start"/"end"/"parm" pairs at +0x22C..+0x240; group flags into
 * bits 12-15 (see ParseAlpha for the shared shape). */
char __stdcall CPrimitiveTemplate__ParseLength( int node, unsigned int *tmpl )
{
  int         pair;
  char      **valuePtr;
  const char *key;
  char       *val;
  int         count;
  float         startLo;    
  float         startHi;    
  float         endLo;      
  float         endHi;      
  float         parmLo;     
  float         parmHi;     
  int         groupFlags; 

  for ( pair = *(unsigned int *)( node + FX_GPGROUP_OFS( mPairs ) ); pair; pair = *(unsigned int *)( pair + FX_GPVALUE_OFS( mNext ) ) )
  {
    valuePtr = *(char ***)( pair + FX_GPVALUE_OFS( mList ) );
    key      = *(const char **)pair;
    val      = valuePtr ? *valuePtr : 0;

    if ( !_stricmp( key, "start" ) )
    {
      count = sscanf( val, "%f %f", &startLo, &startHi );
      if ( count )
      {
        if ( count == 1 )
          startHi = startLo;
        FX_TMPL(tmpl)->mLengthStart.mMin = startLo;
        FX_TMPL(tmpl)->mLengthStart.mMax = startHi;
      }
    }
    else if ( !_stricmp( key, "end" ) )
    {
      count = sscanf( val, "%f %f", &endLo, &endHi );
      if ( count )
      {
        if ( count == 1 )
          endHi = endLo;
        FX_TMPL(tmpl)->mLengthEnd.mMin = endLo;
        FX_TMPL(tmpl)->mLengthEnd.mMax = endHi;
      }
    }
    else if ( !_stricmp( key, "parm" ) || !_stricmp( key, "parms" ) )
    {
      count = sscanf( val, "%f %f", &parmLo, &parmHi );
      if ( count )
      {
        if ( count == 1 )
          parmHi = parmLo;
        FX_TMPL(tmpl)->mLengthParm.mMin = parmLo;
        FX_TMPL(tmpl)->mLengthParm.mMax = parmHi;
      }
    }
    else if ( !_stricmp( key, "flags" ) || !_stricmp( key, "flag" ) )
    {
      if ( CPrimitiveTemplate__ParseGroupFlags( (unsigned int *)&groupFlags, (int)tmpl, val ) == 1 )
        *(unsigned int *)( (char *)tmpl + FX_PRIMITIVE_TEMPLATE_FLAGS_OFFSET ) |= groupFlags << 12;
    }
    else
    {
      SFxHelper__Print( (int)&theFxHelper, "Unknown key parsing a Length group: %s\n", key );
    }
  }
  return 1;
}

/* ---- CPrimitiveTemplate__ParseMaterialImpact_m  0x0049D890 ----  VERIFIED */
/* Copies the NUL-terminated string at `src` into the template's material-impact
 * field (+0x28) via a fixed src->dst byte delta (an inlined strcpy). */
char __cdecl CPrimitiveTemplate__ParseMaterialImpact_m( char *src, int tmpl )
{
  strcpy((char *)FX_TMPL(tmpl)->mMaterialImpact, src);
  return 1;
}

/* ---- CPrimitiveTemplate__ParsePrimitive  0x0049D8B0 ----  VERIFIED */
/* The Parse* helpers it calls take the template first (member order, as the
 * Mac build's this-first methods): LTCG sets register arguments up right to
 * left, so the value goes to eax before the template goes to ebx, and the
 * value can then live in ebx (pair in ebp) as in retail. */
char __stdcall CPrimitiveTemplate__ParsePrimitive( int self, int grp )
{
  int         pair;
  int         group;
  const char *key;
  char       *val;
  int         n;
  char       *d;
  float         lo;
  float         hi;

  for ( pair = *(unsigned int *)( grp + FX_GPGROUP_OFS( mPairs ) ); pair; pair = *(unsigned int *)( pair + FX_GPVALUE_OFS( mNext ) ) )
  {
    key = *(const char **)pair;
    if ( *(unsigned int *)( pair + FX_GPVALUE_OFS( mList ) ) )
      val = **(char ***)( pair + FX_GPVALUE_OFS( mList ) );
    else
      val = 0;

    if ( !_stricmp( key, "count" ) )
    {
      n = sscanf( val, "%f %f", &lo, &hi );
      if ( n )
      {
        if ( n == 1 )
          hi = lo;
        FX_TMPL(self)->mSpawnCount.mMin = lo;
        FX_TMPL(self)->mSpawnCount.mMax = hi;
      }
    }
    else if ( !_stricmp( key, "shaders" ) || !_stricmp( key, "shader" ) )
      CPrimitiveTemplate__ParseShaders( self, pair );
    else if ( !_stricmp( key, "models" ) || !_stricmp( key, "model" ) )
      CPrimitiveTemplate__ParseModels( pair, (unsigned int *)self );
    else if ( !_stricmp( key, "sounds" ) || !_stricmp( key, "sound" ) )
      CPrimitiveTemplate__ParseSounds( self, pair );
    else if ( !_stricmp( key, "impactfx" ) )
      CPrimitiveTemplate__ParseImpactFxStrings( pair, (unsigned int *)self );
    else if ( !_stricmp( key, "deathfx" ) )
      CPrimitiveTemplate__ParseDeathFxStrings( pair, (unsigned int *)self );
    else if ( !_stricmp( key, "emitfx" ) )
      CPrimitiveTemplate__ParseEmitterFxStrings( pair, (unsigned int *)self );
    else if ( !_stricmp( key, "playfx" ) )
      CPrimitiveTemplate__ParsePlayFxStrings( pair, (unsigned int *)self );
    else if ( !_stricmp( key, "life" ) )
      CPrimitiveTemplate__ParseLife_m( val, self );
    else if ( !_stricmp( key, "cullrange" ) )
      *(unsigned int *)&FX_TMPL(self)->mCullRange = j__atol( val );
    else if ( !_stricmp( key, "delay" ) )
      CPrimitiveTemplate__ParseDelay_m( val, self );
    else if ( !_stricmp( key, "bounce" ) || !_stricmp( key, "intensity" ) )
      CPrimitiveTemplate__ParseElasticity( val, self );
    else if ( !_stricmp( key, "min" ) )
      CPrimitiveTemplate__ParseMin_m( (unsigned int *)self, val );
    else if ( !_stricmp( key, "max" ) )
      CPrimitiveTemplate__ParseMax_m( (unsigned int *)self, val );
    else if ( !_stricmp( key, "angle" ) || !_stricmp( key, "angles" ) )
      CPrimitiveTemplate__ParseAngle_m( (unsigned int *)self, val );
    else if ( !_stricmp( key, "angleDelta" ) )
      CPrimitiveTemplate__ParseAngleDelta_m( (unsigned int *)self, val );
    else if ( !_stricmp( key, "velocity" ) || !_stricmp( key, "vel" ) )
      CPrimitiveTemplate__ParseVelocity_m( (unsigned int *)self, val );
    else if ( !_stricmp( key, "acceleration" ) || !_stricmp( key, "accel" ) )
      CPrimitiveTemplate__ParseAcceleration_m( (unsigned int *)self, val );
    else if ( !_stricmp( key, "gravity" ) )
      CPrimitiveTemplate__ParseGravity_m( val, self );
    else if ( !_stricmp( key, "density" ) )
      CPrimitiveTemplate__ParseDensity_m( val, self );
    else if ( !_stricmp( key, "variance" ) )
      CPrimitiveTemplate__ParseVariance_m( val, self );
    else if ( !_stricmp( key, "origin" ) )
      CPrimitiveTemplate__ParseOrigin_m( (unsigned int *)self, val );
    else if ( !_stricmp( key, "origin2" ) )
      CPrimitiveTemplate__ParseOrigin2_m( (unsigned int *)self, val );
    else if ( !_stricmp( key, "radius" ) )
      CPrimitiveTemplate__ParseRadius_m( val, self );
    else if ( !_stricmp( key, "height" ) )
      CPrimitiveTemplate__ParseHeight_m( val, self );
    else if ( !_stricmp( key, "wind" ) )
      CPrimitiveTemplate__ParseWind_m( val, self );
    else if ( !_stricmp( key, "rotation" ) )
      CPrimitiveTemplate__ParseRotation_m( val, self );
    else if ( !Q_stricmp( key, "rotationDelta" ) )
      CPrimitiveTemplate__ParseRotationDelta_m( val, self );
    else if ( !_stricmp( key, "flags" ) || !_stricmp( key, "flag" ) )
      CPrimitiveTemplate__ParseFlags( self, val );
    else if ( !_stricmp( key, "spawnFlags" ) || !_stricmp( key, "spawnFlag" ) )
      CPrimitiveTemplate__ParseSpawnFlags( self, val );
    else if ( !_stricmp( key, "nonUniformScale" ) )
      FX_TMPL(self)->mNonUniformScale = j__atol( val ) != 0;
    else if ( !_stricmp( key, "name" ) )
    {
      if ( val )
      {
        strcpy((char *)FX_TMPL(self)->mName, val);
      }
    }
    else if ( !_stricmp( key, "materialImpact" ) )
    {
      strcpy((char *)FX_TMPL(self)->mMaterialImpact, val);
    }
    else
    {
      SFxHelper__Print( (int)&theFxHelper,
                        "Unknown key parsing an effect primitive: %s\n", key );
    }
  }

  for ( group = *(unsigned int *)( grp + FX_GPGROUP_OFS( mSubGroups ) ); group; group = *(unsigned int *)( group + FX_GPGROUP_OFS( mNext ) ) )
  {
    key = *(const char **)group;
    if ( !_stricmp( key, "rgb" ) )
      CPrimitiveTemplate__ParseRGB( (unsigned int *)self, group );
    else if ( !_stricmp( key, "alpha" ) )
      CPrimitiveTemplate__ParseAlpha( group, (unsigned int *)self );
    else if ( !_stricmp( key, "size" ) || !_stricmp( key, "width" ) )
      CPrimitiveTemplate__ParseSize( group, (unsigned int *)self );
    else if ( !_stricmp( key, "size2" ) || !_stricmp( key, "width2" ) )
      CPrimitiveTemplate__ParseSize2( group, (unsigned int *)self );
    else if ( !_stricmp( key, "length" ) || !_stricmp( key, "height" ) )
      CPrimitiveTemplate__ParseLength( group, (unsigned int *)self );
    else
    {
      SFxHelper__Print( (int)&theFxHelper,
                        "Unknown group key parsing a particle: %s\n", key );
    }
  }
  return 1;
}

/* ---- stl_fxIntVector_ctor_m  0x0049DF30 ----  VERIFIED */
unsigned int *__cdecl stl_fxIntVector_ctor_m(unsigned int *self)
{
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  return self;
}

/* ---- stl_fxIntVector_buy_m  0x0049DF40 ----  VERIFIED */
char __cdecl stl_fxIntVector_buy_m( unsigned int count, unsigned int *vec )
{
  vec[1] = 0;
  vec[2] = 0;
  vec[3] = 0;
  if ( count == 0 )
    return 0;
  else if ( 0x3FFFFFFF < count )
    stl_fxIntVector_xlen_m( (int)vec );   /* result too long */
  else
    return stl_fxIntVector_buyAllocTail_m( count, vec );
  return 1;
}

/* ---- stl_fxIntVector_buyXlenTail_m  0x0049DF5F ----  [HIGH] */
char stl_fxIntVector_buyXlenTail_m()
{
  return 1;
}

/* ---- stl_fxIntVector_buyAllocTail_m  0x0049DF62 ----  IMPLEMENTED (retail) */
/* vector<int>::_Buy's allocation tail (a separate chunk of stl_fxIntVector_buy_m in
 * the IDB, reached after the count checks): allocate count ints, set
 * _Myfirst = _Mylast = p and _Myend = p + count, return true.  Retail is
 * __usercall count@eax, vec@esi. */
char __cdecl stl_fxIntVector_buyAllocTail_m( unsigned int count, unsigned int *vec )
{
  unsigned int *first;
  unsigned int *last;

  first  = (unsigned int *)crt_operator_new( count * 4 );   /* allocator<int>::allocate */
  last=first+count;
  vec[1] = (unsigned int)first;               
  vec[2] = (unsigned int)first;               
  vec[3] = (unsigned int)last;   
  return 1;
}

/* ---- FxUtil_UnrefNop1a_m  0x0049DF90 ----  [HIGH] */
void __stdcall FxUtil_UnrefNop1a_m(int unused)
{
  ;
}

/* ---- FxUtil_UnrefNop0_m  0x0049DFA0 ----  [HIGH] */
void FxUtil_UnrefNop0_m()
{
  ;
}

/* ---- FxUtil_UnrefNop1b_m  0x0049DFB0 ----  [HIGH] */
void __stdcall FxUtil_UnrefNop1b_m(int unused)
{
  ;
}

/* ---- CEffect__SetSTScale  0x0049DFC0 ----  [HIGH] */
void __stdcall CEffect__SetSTScale(int self, float sScale, float tScale)
{
  FX_EFFECT(self)->mRefEnt.shaderTexCoord[0] = sScale;
  FX_EFFECT(self)->mRefEnt.shaderTexCoord[1] = tScale;
}

/* ---- CEffect__SetMin  0x0049DFE0 ----  VERIFIED */
unsigned int *__cdecl CEffect__SetMin(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_EFFECT(self)->mMin[0] = *vec;
    *(unsigned int *)&FX_EFFECT(self)->mMin[1] = vec[1];
    *(unsigned int *)&FX_EFFECT(self)->mMin[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_EFFECT(self)->mMin[2] = 0;
    *(unsigned int *)&FX_EFFECT(self)->mMin[1] = 0;
    *(unsigned int *)&FX_EFFECT(self)->mMin[0] = 0;
  }
  return self;
}

/* ---- CEffect__SetMax  0x0049E010 ----  VERIFIED */
unsigned int *__cdecl CEffect__SetMax(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_EFFECT(self)->mMax[0] = *vec;
    *(unsigned int *)&FX_EFFECT(self)->mMax[1] = vec[1];
    *(unsigned int *)&FX_EFFECT(self)->mMax[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_EFFECT(self)->mMax[2] = 0;
    *(unsigned int *)&FX_EFFECT(self)->mMax[1] = 0;
    *(unsigned int *)&FX_EFFECT(self)->mMax[0] = 0;
  }
  return self;
}

/* ---- CEffect__SetFlags  0x0049E040 ----  [HIGH] */
int __cdecl CEffect__SetFlags(int self, int flags)
{
  *(unsigned int *)&FX_EFFECT(self)->mFlags = flags;
  return self;
}

/* ---- CEffect__ClearFlags  0x0049E050 ----  [HIGH] */
int __cdecl CEffect__ClearFlags(int flags, int self)
{
  int result;

  result = ~flags;
  *(unsigned int *)&FX_EFFECT(self)->mFlags &= result;
  return result;
}

/* ---- CEffect__SetOrigin1  0x0049E060 ----  VERIFIED */
unsigned int *__cdecl CEffect__SetOrigin1(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_EFFECT(self)->mOrigin1[0] = *vec;
    *(unsigned int *)&FX_EFFECT(self)->mOrigin1[1] = vec[1];
    *(unsigned int *)&FX_EFFECT(self)->mOrigin1[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_EFFECT(self)->mOrigin1[2] = 0;
    *(unsigned int *)&FX_EFFECT(self)->mOrigin1[1] = 0;
    *(unsigned int *)&FX_EFFECT(self)->mOrigin1[0] = 0;
  }
  return self;
}

/* ---- CEffect__SetTimeEnd  0x0049E090 ----  [HIGH] */
int __cdecl CEffect__SetTimeEnd(int self, int msec)
{
  *(unsigned int *)&FX_EFFECT(self)->mTimeEnd = msec;
  return self;
}

/* ---- CEffect__SetImpactFxID  0x0049E0A0 ----  [HIGH] */
int __cdecl CEffect__SetImpactFxID(int self, int fxId)
{
  *(unsigned int *)&FX_EFFECT(self)->mImpactFxID = fxId;
  return self;
}

/* ---- CEffect__SetDeathFxID  0x0049E0B0 ----  [HIGH] */
int __cdecl CEffect__SetDeathFxID(int self, int fxId)
{
  *(unsigned int *)&FX_EFFECT(self)->mDeathFxID = fxId;
  return self;
}

/* ---- cand_CFxPrimType14__ctor  0x0049E0C0 ----  VERIFIED */
__declspec(noinline) unsigned int *__cdecl cand_CFxPrimType14__ctor(unsigned int *result)
{
  result[54] = 0;
  *result = (unsigned int)&vtbl_CQuad;
  return result;
}

/* ---- cand_CFxPrimType14__dtor  0x0049E0E0 ----  VERIFIED */
__declspec(noinline) void __fastcall cand_CFxPrimType14__dtor(unsigned int *thisObj)
{
  char *bolt;

  FX_STANDARD_CALL(cand_CFxPrimType14__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  bolt = (char *)thisObj[54];
  if ( bolt )
    CFxBoltFrame__Release(bolt);
}

/* ---- CQuad__operator_new  0x0049E100 ----  VERIFIED */
int *__cdecl CQuad__operator_new(int elemSize)
{
  return FxPool_AllocPrimType14(&fxPool_Quad, elemSize);
}

/* ---- CQuad__operator_delete  0x0049E110 ----  VERIFIED */
unsigned int *__cdecl CQuad__operator_delete(char *thisObj)
{
  return FxPool_FreePrimType14(&fxPool_Quad, thisObj);
}

/* ---- cand_CFxPrimType14__scalar_dtor  0x0049E120 ----  VERIFIED */
char *__fastcall cand_CFxPrimType14__scalar_dtor(char *thisObj, FxCrtDeletingFlags arg)
{
  cand_CFxPrimType14__dtor((unsigned int *)thisObj);
  if ( (arg.flags & 1) != 0 )
    CQuad__operator_delete(thisObj);
  return thisObj;
}

/* ---- CLight__SetSizeStart  0x0049E150 ----  [HIGH] */
int __fastcall CLight__SetSizeStart(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_LIGHT(thisObj)->mSizeStart = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CLight__SetSizeEnd  0x0049E160 ----  [HIGH] */
int __fastcall CLight__SetSizeEnd(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_LIGHT(thisObj)->mSizeEnd = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CLight__SetSizeParm  0x0049E170 ----  [HIGH] */
int __fastcall CLight__SetSizeParm(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_LIGHT(thisObj)->mSizeParm = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CLight__SetRGBStart  0x0049E180 ----  VERIFIED */
unsigned int *__cdecl CLight__SetRGBStart(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_LIGHT(self)->mRGBStart[0] = *vec;
    *(unsigned int *)&FX_LIGHT(self)->mRGBStart[1] = vec[1];
    *(unsigned int *)&FX_LIGHT(self)->mRGBStart[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_LIGHT(self)->mRGBStart[2] = 0;
    *(unsigned int *)&FX_LIGHT(self)->mRGBStart[1] = 0;
    *(unsigned int *)&FX_LIGHT(self)->mRGBStart[0] = 0;
  }
  return self;
}

/* ---- CLight__SetRGBEnd  0x0049E1C0 ----  VERIFIED */
unsigned int *__cdecl CLight__SetRGBEnd(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_LIGHT(self)->mRGBEnd[0] = *vec;
    *(unsigned int *)&FX_LIGHT(self)->mRGBEnd[1] = vec[1];
    *(unsigned int *)&FX_LIGHT(self)->mRGBEnd[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_LIGHT(self)->mRGBEnd[2] = 0;
    *(unsigned int *)&FX_LIGHT(self)->mRGBEnd[1] = 0;
    *(unsigned int *)&FX_LIGHT(self)->mRGBEnd[0] = 0;
  }
  return self;
}

/* ---- CLight__SetRGBParm  0x0049E200 ----  [HIGH] */
int __fastcall CLight__SetRGBParm(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_LIGHT(thisObj)->mRGBParm = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CLight__operator_new  0x0049E210 ----  VERIFIED */
int *__cdecl CLight__operator_new(int elemSize)
{
  return FxPool_AllocLight(&fxPool_Light, elemSize);
}

/* ---- cand_CFxPrimType13__ctor  0x0049E220 ----  VERIFIED */
__declspec(noinline) unsigned int *__cdecl cand_CFxPrimType13__ctor(unsigned int *result)
{
  result[54] = 0;
  *result = (unsigned int)&vtbl_CFlash;
  return result;
}

/* ---- cand_CFxPrimType13__dtor  0x0049E240 ----  VERIFIED */
__declspec(noinline) void __fastcall cand_CFxPrimType13__dtor(unsigned int *thisObj)
{
  char *boltFrame;

  FX_STANDARD_CALL(cand_CFxPrimType13__dtor);
  *thisObj = (unsigned int)&vtbl_CEffect;
  boltFrame = (char *)thisObj[54];
  if ( boltFrame )
    CFxBoltFrame__Release(boltFrame);
}

/* ---- cand_CFxPrimType13__Cull  0x0049E260 ----  [HIGH] */
char cand_CFxPrimType13__Cull()
{
  return 0;
}

/* ---- CFlash__SetShader_m  0x0049E270 ----  [HIGH] */
int __cdecl CFlash__SetShader_m(int self, int shader)
{
  *(unsigned int *)&FX_EFFECT(self)->mRefEnt.customShader = shader;
  return self;
}

/* ---- cand_CFxPrimType13__scalar_dtor  0x0049E280 ----  VERIFIED */
char *__fastcall cand_CFxPrimType13__scalar_dtor(char *thisObj, FxCrtDeletingFlags arg)
{
  cand_CFxPrimType13__dtor((unsigned int *)thisObj);
  if ( (arg.flags & 1) != 0 )
    CLight__operator_delete(thisObj);
  return thisObj;
}

/* ---- CParticle__SetShader  0x0049E2B0 ----  [HIGH] */
int __cdecl CParticle__SetShader(int self, int shader)
{
  *(unsigned int *)&FX_PARTICLE(self)->mRefEnt.customShader = shader;
  return self;
}

/* ---- CParticle__SetVel  0x0049E2C0 ----  VERIFIED */
unsigned int *__cdecl CParticle__SetVel(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_PARTICLE(self)->mVel[0] = *vec;
    *(unsigned int *)&FX_PARTICLE(self)->mVel[1] = vec[1];
    *(unsigned int *)&FX_PARTICLE(self)->mVel[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_PARTICLE(self)->mVel[2] = 0;
    *(unsigned int *)&FX_PARTICLE(self)->mVel[1] = 0;
    *(unsigned int *)&FX_PARTICLE(self)->mVel[0] = 0;
  }
  return self;
}

/* ---- CParticle__SetAccel  0x0049E300 ----  VERIFIED */
unsigned int *__cdecl CParticle__SetAccel(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_PARTICLE(self)->mAccel[0] = *vec;
    *(unsigned int *)&FX_PARTICLE(self)->mAccel[1] = vec[1];
    *(unsigned int *)&FX_PARTICLE(self)->mAccel[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_PARTICLE(self)->mAccel[2] = 0;
    *(unsigned int *)&FX_PARTICLE(self)->mAccel[1] = 0;
    *(unsigned int *)&FX_PARTICLE(self)->mAccel[0] = 0;
  }
  return self;
}

/* ---- CParticle__SetSizeStart  0x0049E340 ----  [HIGH] */
int __fastcall CParticle__SetSizeStart(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mSizeStart = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetSizeEnd  0x0049E350 ----  [HIGH] */
int __fastcall CParticle__SetSizeEnd(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mSizeEnd = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetSizeParm  0x0049E360 ----  [HIGH] */
int __fastcall CParticle__SetSizeParm(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mSizeParm = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetSize2Start_m  0x0049E370 ----  [HIGH] */
int __fastcall CParticle__SetSize2Start_m(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mSize2Start = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetSize2End_m  0x0049E380 ----  [HIGH] */
int __fastcall CParticle__SetSize2End_m(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mSize2End = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetSize2Parm_m  0x0049E390 ----  [HIGH] */
int __fastcall CParticle__SetSize2Parm_m(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mSize2Parm = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetRGBStart  0x0049E3A0 ----  VERIFIED */
unsigned int *__cdecl CParticle__SetRGBStart(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_PARTICLE(self)->mRGBStart[0] = *vec;
    *(unsigned int *)&FX_PARTICLE(self)->mRGBStart[1] = vec[1];
    *(unsigned int *)&FX_PARTICLE(self)->mRGBStart[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_PARTICLE(self)->mRGBStart[2] = 0;
    *(unsigned int *)&FX_PARTICLE(self)->mRGBStart[1] = 0;
    *(unsigned int *)&FX_PARTICLE(self)->mRGBStart[0] = 0;
  }
  return self;
}

/* ---- CParticle__SetRGBEnd  0x0049E3E0 ----  VERIFIED */
unsigned int *__cdecl CParticle__SetRGBEnd(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_PARTICLE(self)->mRGBEnd[0] = *vec;
    *(unsigned int *)&FX_PARTICLE(self)->mRGBEnd[1] = vec[1];
    *(unsigned int *)&FX_PARTICLE(self)->mRGBEnd[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_PARTICLE(self)->mRGBEnd[2] = 0;
    *(unsigned int *)&FX_PARTICLE(self)->mRGBEnd[1] = 0;
    *(unsigned int *)&FX_PARTICLE(self)->mRGBEnd[0] = 0;
  }
  return self;
}

/* ---- CParticle__SetRGBParm  0x0049E420 ----  [HIGH] */
int __fastcall CParticle__SetRGBParm(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mRGBParm = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetAlphaStart  0x0049E430 ----  [HIGH] */
int __fastcall CParticle__SetAlphaStart(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mAlphaStart = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetAlphaEnd  0x0049E440 ----  [HIGH] */
int __fastcall CParticle__SetAlphaEnd(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mAlphaEnd = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetAlphaParm  0x0049E450 ----  [HIGH] */
int __fastcall CParticle__SetAlphaParm(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mAlphaParm = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetRotation  0x0049E460 ----  [HIGH] */
int __fastcall CParticle__SetRotation(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mRefEnt.rotation = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetRotationDelta  0x0049E470 ----  [HIGH] */
int __fastcall CParticle__SetRotationDelta(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mRotationDelta = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__SetElasticity  0x0049E480 ----  [HIGH] */
int __fastcall CParticle__SetElasticity(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_PARTICLE(thisObj)->mElasticity = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CParticle__operator_new  0x0049E490 ----  VERIFIED */
int *__cdecl CParticle__operator_new(int elemSize)
{
  return FxPool_AllocParticle(&fxPool_Particle, elemSize);
}

/* ---- CLine__SetOrigin2  0x0049E4A0 ----  VERIFIED */
int __cdecl CLine__SetOrigin2(unsigned int *origin, unsigned int *self)
{
  *(unsigned int *)&FX_LINE(self)->mOrigin2[0] = *origin;
  *(unsigned int *)&FX_LINE(self)->mOrigin2[1] = origin[1];
  {
    unsigned int component = origin[2];
    *(unsigned int *)&FX_LINE(self)->mOrigin2[2] = component;
    return component;
  }
}

/* ---- CLine__operator_new  0x0049E4C0 ----  VERIFIED */
int *__cdecl CLine__operator_new(int elemSize)
{
  return FxPool_AllocLine(&fxPool_Line, elemSize);
}

/* ---- CElectricity__SetChaos  0x0049E4D0 ----  [HIGH] */
int __fastcall CElectricity__SetChaos(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_ELECTRICITY(thisObj)->mChaos = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CElectricity__operator_new  0x0049E4E0 ----  VERIFIED */
int *__cdecl CElectricity__operator_new(int elemSize)
{
  return FxPool_AllocElectricity(&fxPool_Electricity, elemSize);
}

/* ---- COrientedParticle__SetNormal  0x0049E4F0 ----  VERIFIED */
int __cdecl COrientedParticle__SetNormal(unsigned int *normal, unsigned int *self)
{
  *(unsigned int *)&FX_ORIENTED(self)->mNormal[0] = *normal;
  *(unsigned int *)&FX_ORIENTED(self)->mNormal[1] = normal[1];
  {
    unsigned int component = normal[2];
    *(unsigned int *)&FX_ORIENTED(self)->mNormal[2] = component;
    return component;
  }
}

/* ---- COrientedParticle__operator_new  0x0049E510 ----  VERIFIED */
int *__cdecl COrientedParticle__operator_new(int elemSize)
{
  return FxPool_AllocOrientedParticle(&fxPool_OrientedParticle, elemSize);
}

/* ---- CTail__SetLengthStart  0x0049E520 ----  [HIGH] */
int __fastcall CTail__SetLengthStart(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_TAIL(thisObj)->mLengthStart = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CTail__SetLengthEnd  0x0049E530 ----  [HIGH] */
int __fastcall CTail__SetLengthEnd(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_TAIL(thisObj)->mLengthEnd = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CTail__SetLengthParm  0x0049E540 ----  [HIGH] */
int __fastcall CTail__SetLengthParm(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_TAIL(thisObj)->mLengthParm = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CTail__operator_new  0x0049E550 ----  VERIFIED */
int *__cdecl CTail__operator_new(int elemSize)
{
  return FxPool_AllocTail(&fxPool_Tail, elemSize);
}

/* ---- CCylinder__SetSize2Start  0x0049E560 ----  [HIGH] */
int __fastcall CCylinder__SetSize2Start(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_CYLINDER(thisObj)->mSize2Start = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CCylinder__SetSize2End  0x0049E570 ----  [HIGH] */
int __fastcall CCylinder__SetSize2End(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_CYLINDER(thisObj)->mSize2End = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CCylinder__SetSize2Parm  0x0049E580 ----  [HIGH] */
int __fastcall CCylinder__SetSize2Parm(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_CYLINDER(thisObj)->mSize2Parm = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CCylinder__SetNormal  0x0049E590 ----  VERIFIED */
int __cdecl CCylinder__SetNormal(unsigned int *normal, unsigned int *self)
{
  *(unsigned int *)&FX_CYLINDER(self)->mRefEnt.axis[0][0] = *normal;
  *(unsigned int *)&FX_CYLINDER(self)->mRefEnt.axis[0][1] = normal[1];
  {
    unsigned int component = normal[2];
    *(unsigned int *)&FX_CYLINDER(self)->mRefEnt.axis[0][2] = component;
    return component;
  }
}

/* ---- CCylinder__operator_new  0x0049E5B0 ----  VERIFIED */
int *__cdecl CCylinder__operator_new(int elemSize)
{
  return FxPool_AllocCylinder(&fxPool_Cylinder, elemSize);
}

/* ---- CEmitter__SetModel_m  0x0049E5C0 ----  [HIGH] */
int __cdecl CEmitter__SetModel_m(int self, int model)
{
  *(unsigned int *)&FX_EMITTER(self)->mRefEnt.dobj = model;
  return self;
}

/* ---- CEmitter__SetAngles  0x0049E5D0 ----  VERIFIED */
unsigned int *__cdecl CEmitter__SetAngles(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_EMITTER(self)->mAngles[0] = *vec;
    *(unsigned int *)&FX_EMITTER(self)->mAngles[1] = vec[1];
    *(unsigned int *)&FX_EMITTER(self)->mAngles[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_EMITTER(self)->mAngles[2] = 0;
    *(unsigned int *)&FX_EMITTER(self)->mAngles[1] = 0;
    *(unsigned int *)&FX_EMITTER(self)->mAngles[0] = 0;
  }
  return self;
}

/* ---- CEmitter__SetAngleDelta  0x0049E610 ----  VERIFIED */
unsigned int *__cdecl CEmitter__SetAngleDelta(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_EMITTER(self)->mAngleDelta[0] = *vec;
    *(unsigned int *)&FX_EMITTER(self)->mAngleDelta[1] = vec[1];
    *(unsigned int *)&FX_EMITTER(self)->mAngleDelta[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_EMITTER(self)->mAngleDelta[2] = 0;
    *(unsigned int *)&FX_EMITTER(self)->mAngleDelta[1] = 0;
    *(unsigned int *)&FX_EMITTER(self)->mAngleDelta[0] = 0;
  }
  return self;
}

/* ---- CEmitter__SetEmitterFxID  0x0049E650 ----  [HIGH] */
int __cdecl CEmitter__SetEmitterFxID(int self, int fxId)
{
  *(unsigned int *)&FX_EMITTER(self)->mEmitterFxID = fxId;
  return self;
}

/* ---- CEmitter__SetDensity  0x0049E660 ----  [HIGH] */
int __fastcall CEmitter__SetDensity(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_EMITTER(thisObj)->mDensity = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CEmitter__SetVariance  0x0049E670 ----  [HIGH] */
int __fastcall CEmitter__SetVariance(unsigned int *thisObj, float value)
{
  *(unsigned int *)&FX_EMITTER(thisObj)->mVariance = *(unsigned int *)&value;
  return *(int *)&value;
}

/* ---- CEmitter__SetOldTime  0x0049E680 ----  [HIGH] */
int __cdecl CEmitter__SetOldTime(int self, int msec)
{
  *(unsigned int *)&FX_EMITTER(self)->mOldTime = msec;
  return self;
}

/* ---- CEmitter__SetLastOrg  0x0049E690 ----  VERIFIED */
unsigned int *__cdecl CEmitter__SetLastOrg(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_EMITTER(self)->mOldOrigin[0] = *vec;
    *(unsigned int *)&FX_EMITTER(self)->mOldOrigin[1] = vec[1];
    *(unsigned int *)&FX_EMITTER(self)->mOldOrigin[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_EMITTER(self)->mOldOrigin[2] = 0;
    *(unsigned int *)&FX_EMITTER(self)->mOldOrigin[1] = 0;
    *(unsigned int *)&FX_EMITTER(self)->mOldOrigin[0] = 0;
  }
  return self;
}

/* ---- CEmitter__SetLastVel  0x0049E6D0 ----  VERIFIED */
unsigned int *__cdecl CEmitter__SetLastVel(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_EMITTER(self)->mOldVelocity[0] = *vec;
    *(unsigned int *)&FX_EMITTER(self)->mOldVelocity[1] = vec[1];
    *(unsigned int *)&FX_EMITTER(self)->mOldVelocity[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_EMITTER(self)->mOldVelocity[2] = 0;
    *(unsigned int *)&FX_EMITTER(self)->mOldVelocity[1] = 0;
    *(unsigned int *)&FX_EMITTER(self)->mOldVelocity[0] = 0;
  }
  return self;
}

/* ---- CEmitter__SetLastBoltOrg_m  0x0049E710 ----  VERIFIED */
unsigned int *__cdecl CEmitter__SetLastBoltOrg_m(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_EMITTER(self)->mLastBoltOrigin[0] = *vec;
    *(unsigned int *)&FX_EMITTER(self)->mLastBoltOrigin[1] = vec[1];
    *(unsigned int *)&FX_EMITTER(self)->mLastBoltOrigin[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_EMITTER(self)->mLastBoltOrigin[2] = 0;
    *(unsigned int *)&FX_EMITTER(self)->mLastBoltOrigin[1] = 0;
    *(unsigned int *)&FX_EMITTER(self)->mLastBoltOrigin[0] = 0;
  }
  return self;
}

/* ---- CEmitter__SetLightingOrigin_m  0x0049E750 ----  VERIFIED */
unsigned int *__cdecl CEmitter__SetLightingOrigin_m(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_EMITTER(self)->mRefEnt.lightingOrigin[0] = *vec;
    *(unsigned int *)&FX_EMITTER(self)->mRefEnt.lightingOrigin[1] = vec[1];
    *(unsigned int *)&FX_EMITTER(self)->mRefEnt.lightingOrigin[2] = vec[2];
    *(unsigned int *)&FX_EMITTER(self)->mRefEnt.renderfx |= 0x80u;
  }
  return self;
}

/* ---- CEmitter__operator_new  0x0049E770 ----  VERIFIED */
int *__cdecl CEmitter__operator_new(int elemSize)
{
  return FxPool_AllocEmitter(&fxPool_Emitter, elemSize);
}

/* ---- CPoly__SetNumVerts  0x0049E780 ----  [HIGH] */
int __cdecl CPoly__SetNumVerts(int self, int numVerts)
{
  *(unsigned int *)&FX_DECAL(self)->mCount = numVerts;
  return self;
}

/* ---- CPoly__SetRot  0x0049E790 ----  VERIFIED */
unsigned int *__cdecl CPoly__SetRot(unsigned int *self, unsigned int *vec)
{
  if ( vec )
  {
    *(unsigned int *)&FX_DECAL(self)->mRotDelta[0] = *vec;
    *(unsigned int *)&FX_DECAL(self)->mRotDelta[1] = vec[1];
    *(unsigned int *)&FX_DECAL(self)->mRotDelta[2] = vec[2];
  }
  else
  {
    *(unsigned int *)&FX_DECAL(self)->mRotDelta[2] = 0;
    *(unsigned int *)&FX_DECAL(self)->mRotDelta[1] = 0;
    *(unsigned int *)&FX_DECAL(self)->mRotDelta[0] = 0;
  }
  return self;
}

/* ---- CPoly__SetMotionTimeStamp  0x0049E7D0 ----  [HIGH] */
int __cdecl CPoly__SetMotionTimeStamp(int msec, int self)
{
  *(unsigned int *)&FX_DECAL(self)->mTimeStamp = msec + fxMTime;
  return msec;
}

/* ---- CPoly__operator_new  0x0049E7E0 ----  VERIFIED */
int *__cdecl CPoly__operator_new(int elemSize)
{
  return FxPool_AllocFlash(&fxPool_Decal, elemSize);
}

/* ---- FX_UnusedGetField8  0x0049E7F0 ----  [HIGH] */
/* retail 0x0049E7F0, IDA sub_49E7F0: mov eax,[eax+8]; retn (a1@eax), no xrefs; inline accessor between CPoly__operator_new and CFxScheduler__NumScheduledFx, owner unknown: descriptive name. */
int __cdecl FX_UnusedGetField8(int a1)
{
  return *(unsigned int *)(a1 + 8);
}

/* ---- CFxScheduler__NumScheduledFx  0x0049E800 ----  [HIGH] */
int __cdecl CFxScheduler__NumScheduledFx(int scheduler)
{
  return *(unsigned int *)(scheduler + 21524);
}

/* ---- FX_Free  0x0049E810 ----  [CONFIRMED] */
char __cdecl FX_Free(int clearTemplates)
{
  unsigned int *effectSlot;

  if ( fxActiveEffects )
    FX_DELETE_EFFECT( fxActiveEffects );
  fxActiveEffects = 0;
  fxFreeListHead = (int)&fxActiveEffects;

  

  effectSlot = &(*(unsigned int *)(((unsigned char *)&fxActiveEffects) + 0x000C));
  do
  {
    if ( *effectSlot )
      FX_DELETE_EFFECT( *effectSlot );
    *effectSlot = 0;
    *(effectSlot - 1) = (unsigned int)effectSlot;
    effectSlot += 3;
  }
  while ( (int)effectSlot < (int)( ((unsigned char *)&fxActiveEffects) + ( 12 * 1800 ) ) );
  (*(int *)(((unsigned char *)&fxActiveEffects) + 0x545C)) = 0;
  fxActiveCount = 0;
  CFxModel__Clean();
  CFxScheduler__Clean((int)theFxScheduler, clearTemplates, 0);
  return 1;
}

/* ---- FX_Stop  0x0049E890 ----  VERIFIED */
void FX_Stop()
{
  int *effectSlot;

  effectSlot = &fxActiveEffects;
  do
  {
    if ( *effectSlot )
      FX_DELETE_EFFECT( *effectSlot );
    *effectSlot = 0;
    effectSlot += 3;
  }
  while ( (int)effectSlot < (int)( ((unsigned char *)&fxActiveEffects) + ( 12 * 1800 ) ) );
  fxActiveCount = 0;
  CFxScheduler__Clean((int)theFxScheduler, 0, 0);
}

/* ---- FX_GetBoneOrientation  0x0049E8D0 ----  VERIFIED */
/* /Op code in retail: the float locals (debug scale, origin z) go through 4-byte slots.
 * (bolt, out) order gives retail's LTCG convention: out in eax, bolt in ecx. */
#if defined( _MSC_VER ) && _MSC_VER < 1310
#pragma optimize( "p", on )
#endif
char __cdecl FX_GetBoneOrientation(unsigned int *bolt, float *out)
{
  signed __int16 dobjHandle;
  DObj *dobj;
  float *boneMat;
  float originZ;
  float entOrigin[3];  /* [esp+1Ch] [ebp-30h] BYREF -- retail vec3_t origin */
  float entAxis[9];    /* [esp+28h] [ebp-24h] BYREF -- retail 3x3 axis */
  float fxDebugScale;
  float fxDebugEnd[3];

  /* bolt[0] = entity number, bolt[1] = bone/part index (<0 means no bone).
   * VM_Call 12 fetches the entity origin (entOrigin) and 3x3 axis (entAxis). */
  VM_Call(cgvm, 12, *bolt, entOrigin, entAxis);
  if ( (int)bolt[1] < 0 )
  {
    /* No bone attached: copy the entity orientation straight through
     * (out[0..2] = origin, out[3..11] = 3x3 axis). */
    out[0] = entOrigin[0];
    out[1] = entOrigin[1];
    out[2] = entOrigin[2];
    out[3] = entAxis[0];
    out[4] = entAxis[1];
    out[5] = entAxis[2];
    out[6] = entAxis[3];
    out[7] = entAxis[4];
    out[8] = entAxis[5];
    out[9] = entAxis[6];
    out[10] = entAxis[7];
    out[11] = entAxis[8];
    return 1;
  }

  /* Com_GetClientDObj inlined: retail jumps from the zero-handle test straight
   * into the !dobj return.  retail 0x0049E96A-0x0049E96D `imul esi, 58h` then
   * `add esi, offset dobj_pool`.  dobj_pool is com_dobjPool, stride 0x58. */
  dobjHandle = (short)com_clientDObjHandles[*bolt];
  if ( dobjHandle )
    dobj = (DObj *)&com_dobjPool[dobjHandle * 0x58];
  else
    dobj = 0;
  if ( !dobj )
    return 0;
  if ( (int)bolt[1] >= dobj->partCount )
    return 0;

  VM_Call(cgvm, 11, *bolt, bolt[1]);
  /* boneMat -> the bone's transform inside evalStorage (16 floats/bone). */
  boneMat = &((float *)dobj->evalStorage)[16 * ( dobj->childPartBaseIndices[0] + bolt[1] ) + 12];
  /* Rotate the bone axis/translation by the entity axis and add the origin. */
  out[3] = entAxis[6] * boneMat[2] + entAxis[3] * boneMat[1] + entAxis[0] * *boneMat;
  out[4] = entAxis[7] * boneMat[2] + entAxis[4] * boneMat[1] + entAxis[1] * *boneMat;
  out[5] = entAxis[8] * boneMat[2] + entAxis[5] * boneMat[1] + entAxis[2] * *boneMat;
  out[6] = entAxis[0] * boneMat[4] + entAxis[6] * boneMat[6] + entAxis[3] * boneMat[5];
  out[7] = entAxis[1] * boneMat[4] + entAxis[7] * boneMat[6] + entAxis[4] * boneMat[5];
  out[8] = entAxis[2] * boneMat[4] + entAxis[8] * boneMat[6] + entAxis[5] * boneMat[5];
  out[9] = entAxis[0] * boneMat[8] + entAxis[6] * boneMat[10] + entAxis[3] * boneMat[9];
  out[10] = entAxis[1] * boneMat[8] + entAxis[7] * boneMat[10] + entAxis[4] * boneMat[9];
  out[11] = entAxis[2] * boneMat[8] + entAxis[8] * boneMat[10] + entAxis[5] * boneMat[9];
  *out = entAxis[0] * boneMat[12] + entAxis[6] * boneMat[14] + entAxis[3] * boneMat[13] + entOrigin[0];
  out[1] = entAxis[1] * boneMat[12] + entAxis[7] * boneMat[14] + entAxis[4] * boneMat[13] + entOrigin[1];
#ifdef COD1_VC7
  originZ = entAxis[2] * boneMat[12] + entAxis[8] * boneMat[14] + entAxis[5] * boneMat[13] + entOrigin[2];
#else
  originZ = (double)( entAxis[2] * boneMat[12] + entAxis[8] * boneMat[14] ) + entAxis[5] * boneMat[13] + entOrigin[2];
#endif
  out[2] = originZ;
  if ( fx_debugBolt->integer )
  {
    fxDebugScale = fx_debugBolt->integer;

    fxDebugEnd[0] = fxDebugScale * out[3] + out[0];
    fxDebugEnd[1] = fxDebugScale * out[4] + out[1];
    fxDebugEnd[2] = fxDebugScale * out[5] + originZ;
    CL_AddDebugLine( out, fxDebugEnd, (const float *)colorDebugRed, 1, 0, 0 );

    fxDebugScale = fx_debugBolt->integer;
    fxDebugEnd[0] = fxDebugScale * out[6] + out[0];
    fxDebugEnd[1] = fxDebugScale * out[7] + out[1];
    fxDebugEnd[2] = fxDebugScale * out[8] + out[2];
    CL_AddDebugLine( out, fxDebugEnd, (const float *)colorDebugGreen, 1, 0, 0 );

    fxDebugScale = fx_debugBolt->integer;
    fxDebugEnd[0] = fxDebugScale * out[9] + out[0];
    fxDebugEnd[1] = fxDebugScale * out[10] + out[1];
    fxDebugEnd[2] = fxDebugScale * out[11] + out[2];
    CL_AddDebugLine( out, fxDebugEnd, (const float *)colorDebugBlue, 1, 0, 0 );
  }
  return 1;
}

#if defined( _MSC_VER ) && _MSC_VER < 1310
#pragma optimize( "p", off )
#endif

/* ---- FX_Init  0x0049EC10 ----  [CONFIRMED] */
int __cdecl FX_Init()
{
  int *effectSlot;

  if ( !fxActiveEffectsInitialized )
  {
    fxActiveEffectsInitialized = 1;
    effectSlot = &fxActiveEffects;
    do
    {
      *effectSlot = 0;
      effectSlot += 3;
    }
    while ( (int)effectSlot < (int)fxActiveEffectsEnd );
  }
  FX_Free(1);
  theFxHelper = 0;
  fxMTime = 0;
  fxHelperOldTime = 0;
  fxHelperFrameTime = 0;
  fxHelperArchivedTimingState = 0;
  return 1;
}

/* ---- FX_FreeMember  0x0049EC70 ----  [HIGH] */
int __cdecl FX_FreeMember(unsigned int *effectSlot)
{
  int newCount;

  (*(void (__fastcall **)(unsigned int))(*(unsigned int *)*effectSlot + 4))(*effectSlot);
  if ( *effectSlot )
    FX_DELETE_EFFECT( *effectSlot );
  *effectSlot = 0;
  effectSlot[2] = fxFreeListHead;
  newCount = fxActiveCount - 1;
  fxFreeListHead = (int)effectSlot;
  fxActiveCount = newCount;
  return newCount;
}

/* ---- FX_GetValidEffect  0x0049ECB0 ----  [CONFIRMED] */
int *FX_GetValidEffect()
{
  int *result;

  if ( !fxFreeListHead )
  {
    /* out of slots: recycle the oldest effect */
    if ( com_statmon->integer )
      StatMon_Warning(7, 3000, "gfx/2d/warning@maxeffects.jpg");
    FX_FreeMember( (unsigned int *)&fxActiveEffects );
    fxFreeListHead = 0;
    return &fxActiveEffects;
  }

  result = (int *)fxFreeListHead;
  if ( !*result )
  {
    fxFreeListHead = result[2];
    return result;
  }
  return 0;
}

/* ---- FX_ActiveFx  0x0049ED40 ----  [HIGH] */
int FX_ActiveFx()
{
  return fxActiveCount > 0 || *(int *)fxScheduledCount > 0;
}

/* ---- FX_Save  0x0049ED60 ----  VERIFIED */
/*
 * Serialize the whole live FX system into a write-mode FxArchive over buffer
 * buffer: the scheduler state, then a (typeTag, slotField, per-effect data) record
 * for every live effect slot, terminated by a zero type tag.  Returns the
 * number of bytes written (the archive's final position).
 */
int __cdecl FX_Save(int buffer, int size)
{
  /* The one-byte type tag lives in its own dword slot (retail writes the low
   * byte at [esp+10h]); a plain char local is packed at +3 by VC7. */
  int        typeTag;   
  FxArchive  ar;
  FxPointerArgument archiveArg;
  int       *effectSlot;
  int        remaining;
  int        slotField;    

  archiveArg.pointer=&ar;
  ar.buffer         = (unsigned char *)buffer;
  ar.size           = size;
  ar.pos            = 0;
  ar.reading        = 0;
  ar.writing        = 1;
  ar.bytesProcessed = 0;
  ar.rleMarker      = 0;
  ar.rleState       = 0;
  ar.rleCount       = 0;
  SFxHelper__Archive_m((int)&theFxHelper, (int)&ar);
  CFxScheduler__SaveState_m((int)&ar, theFxScheduler);

  effectSlot = &fxActiveEffects;
  remaining = 1800;
  do
  {
    if ( *effectSlot )
    {
      
      *(byte *)&typeTag = (*(int (__fastcall **)(int))(*(unsigned int *)*effectSlot + 20))(*effectSlot);
      CFxArchive__WriteData((int *)&ar, (byte *)&typeTag, 1);
      slotField = effectSlot[1];
      CFxArchive__WriteData((int *)&ar, (byte *)&slotField, 4);
      (*(void (__fastcall **)(int, FxPointerArgument))(*(unsigned int *)*effectSlot + 24))(*effectSlot, archiveArg);
    }
    effectSlot += 3;
    --remaining;
  }
  while ( remaining );
  *(byte *)&typeTag = 0;
  CFxArchive__WriteData((int *)&ar, (byte *)&typeTag, 1);
  return ar.pos;
}

/* ---- FX_Add  0x0049EE40 ----  [HIGH] */
/* CFxArchive ar( buffer, size, read ): the inline constructor clears the
 * archive, the open re-sets every field.  Each record re-creates its
 * primitive with `new` (the pool operator new; the constructor runs only on
 * success and stays out of line here) and calls its virtual Archive( ar ). */
int __cdecl FX_Add(int buffer, int size)
{
  FxArchive     ar;
  unsigned char typeTag;    /* BYREF: record type, 0 ends the list */
  int           recordId;   /* BYREF: the slot's kill time */
  
  int          *slot;      
  int           slotIndex;
  int          *p;         
  int           type;

  /* CFxArchive::CFxArchive(): an empty archive */
  ar.buffer         = 0;
  ar.size           = 0;
  ar.pos            = 0;
  ar.reading        = 0;
  ar.writing        = 0;
  ar.bytesProcessed = 0;
  ar.rleMarker      = 0;
  ar.rleState       = 0;
  ar.rleCount       = 0;

  FX_Free(0);

  ar.buffer         = (unsigned char *)buffer;
  ar.size           = size;
  ar.pos            = 0;
  ar.reading        = 1;
  ar.writing        = 0;
  ar.bytesProcessed = 0;
  ar.rleMarker      = 0;
  ar.rleState       = 0;
  ar.rleCount       = 0;
  memset(ar.table, 0, sizeof(ar.table));

  fxFreeListHead = 0;
  SFxHelper__Archive_m((int)&theFxHelper, (int)&ar);
  CFxScheduler__SaveState_m((int)&ar, theFxScheduler);

  for ( slotIndex = 0, slot = &fxActiveEffects; slotIndex < 1800; ++slotIndex, slot += 3 )
  {
    CFxArchive__ReadData(1, (unsigned int *)&ar, &typeTag);
    type = typeTag;
    if ( !type )
    {
      fxFreeListHead = (int)&fxActiveEffects + 12 * slotIndex;
      return ar.pos;
    }
    CFxArchive__ReadData(4, (unsigned int *)&ar, (byte *)&recordId);
    slot[1] = recordId;
    switch ( type )
    {
      case 1:
        p = FxPool_AllocParticle(&fxPool_Particle, 316);
        p = p ? (int *)CParticle__ctor((unsigned int *)p) : 0;
        *slot = (int)p;
        ((FxArchivable *)p)->Archive( &ar );
        break;
      case 2:
        p = FxPool_AllocLine(&fxPool_Line, 328);
        p = p ? (int *)CLine__ctor((unsigned int *)p) : 0;
        *slot = (int)p;
        ((FxArchivable *)p)->Archive( &ar );
        break;
      case 3:
        p = FxPool_AllocTail(&fxPool_Tail, 344);
        p = p ? (int *)CTail__ctor((unsigned int *)p) : 0;
        *slot = (int)p;
        ((FxArchivable *)p)->Archive( &ar );
        break;
      case 4:
        p = FxPool_AllocCylinder(&fxPool_Cylinder, 344);
        p = p ? (int *)CCylinder__ctor((unsigned int *)p) : 0;
        *slot = (int)p;
        ((FxArchivable *)p)->Archive( &ar );
        break;
      case 5:
        p = FxPool_AllocEmitter(&fxPool_Emitter, 396);
        p = p ? (int *)CEmitter__ctor((unsigned int *)p) : 0;
        *slot = (int)p;
        ((FxArchivable *)p)->Archive( &ar );
        break;
      case 8:
        p = FxPool_AllocOrientedParticle(&fxPool_OrientedParticle, 328);
        p = p ? (int *)COrientedParticle__ctor((unsigned int *)p) : 0;
        *slot = (int)p;
        ((FxArchivable *)p)->Archive( &ar );
        break;
      case 9:
        p = FxPool_AllocElectricity(&fxPool_Electricity, 716);
        p = p ? (int *)CElectricity__ctor((unsigned int *)p) : 0;
        *slot = (int)p;
        ((FxArchivable *)p)->Archive( &ar );
        break;
      case 11:
        p = FxPool_AllocLight(&fxPool_Light, 260);
        p = p ? (int *)CLight__ctor((unsigned int *)p) : 0;
        *slot = (int)p;
        ((FxArchivable *)p)->Archive( &ar );
        break;
      case 13:
        p = FxPool_AllocLight(&fxPool_Light, 260);
        p = p ? (int *)cand_CFxPrimType13__ctor((unsigned int *)p) : 0;
        *slot = (int)p;
        ((FxArchivable *)p)->Archive( &ar );
        break;
      case 14:
        p = FxPool_AllocPrimType14(&fxPool_Quad, 560);
        p = p ? (int *)cand_CFxPrimType14__ctor((unsigned int *)p) : 0;
        *slot = (int)p;
        ((FxArchivable *)p)->Archive( &ar );
        break;
      case 15:
        p = FxPool_AllocFlash(&fxPool_Decal, 436);
        p = p ? (int *)CFlash__ctor((unsigned int *)p) : 0;
        *slot = (int)p;
        ((FxArchivable *)p)->Archive( &ar );
        break;
      default:
        *slot = 0;
        slot[1] = 0;
        break;
    }
  }
  return ar.pos;
}

/* ---- FX_DrawStats_m  0x0049F1E0 ----  VERIFIED */
void FX_DrawStats_m()
{
  int    *slot;      
  int     remaining;
  unsigned int *effect;    

  fxDrawnCount = 0;
  slot = &fxActiveEffects;
  for ( remaining = 1800; remaining; slot += 3, --remaining )
  {
    effect = (unsigned int *)*slot;
    if ( !*slot )
      continue;
    if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x04)) > slot[1] )
    {
      /* expired */
      effect[6] &= ~0x40000000u;
      FX_FreeMember( (unsigned int *)slot );
    }
    else if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x0C)) > 0
              && !(*(unsigned __int8 (__fastcall **)(unsigned int *))(*effect + 8))(effect) )
    {
      /* Update() says the effect is done */
      FX_FreeMember( (unsigned int *)slot );
    }
    else if ( fx_draw->integer && (!fx_cull->integer || !(*(unsigned __int8 (__fastcall **)(int))(*(unsigned int *)*slot+12))(*slot)) )
    {
      ++fxDrawnCount;
      (*(void (__fastcall **)(int))(*(unsigned int *)*slot+16))(*slot);
    }
  }
  if ( fx_debug->integer )
  {
    SFxHelper__Print((int)&theFxHelper, "Active    FX: %i\n", fxActiveCount);
    SFxHelper__Print((int)&theFxHelper, "Drawn     FX: %i\n", fxDrawnCount);
    SFxHelper__Print((int)&theFxHelper, "Scheduled FX: %i\n", *(unsigned int *)((char *)(((unsigned char *)theFxScheduler) + 0x5414)));
  }
}

/* ---- FX_AddPrimitive  0x0049F310 ----  [HIGH] */
void __cdecl FX_AddPrimitive(int *pPrimitive, int lifeMsec)
{
  int *slot;
  int  primitive;
  int currentTime;

  slot = FX_GetValidEffect();
  *slot = *pPrimitive;                 
  slot[1] = lifeMsec + (*(int *)(((unsigned char *)&theFxHelper) + 0x04));        
  currentTime=(*(int *)(((unsigned char *)&theFxHelper)+0x04));
  ++fxActiveCount;

  primitive = *pPrimitive;
  *(unsigned int *)(primitive + 16) = currentTime;                       
  *(float *)(primitive + 180) = (float)currentTime * 0.001f;      
  *(unsigned int *)(*pPrimitive + 20) = lifeMsec + (*(int *)(((unsigned char *)&theFxHelper) + 0x04));          

}

/* ---- FX_AddParticle  0x0049F360 ----  [CONFIRMED] */
/* Register shape: retail keeps bolt/org in esi/edi, the null constant in ebx
 * and the particle in ebp, so vel/accel and sizeStart/sizeEnd are re-read
 * from their argument slots at each use (volatile here) and `flags` is the
 * argument itself, loaded into a scratch register at its first test.  The
 * size2 copies follow the flag merge, and the trailing setters go through the
 * member address (see the FX_AddLine note) so VC7 keeps them ahead of the
 * mins test. */
int __cdecl FX_AddParticle(
        char **bolt,
        int org,
        float *volatile vel,
        float *volatile accel,
        char useSize2,
        int volatile sizeStart,
        int volatile sizeEnd,
        float sizeParm,
        int size2Start,
        int size2End,
        float size2Parm,
        int alphaStart,
        int alphaEnd,
        float alphaParm,
        unsigned int *rgbStart,
        unsigned int *rgbEnd,
        float rgbParm,
        int rotation,
        int rotationDelta,
        unsigned int *mins,
        unsigned int *maxs,
        int elasticity,
        int deathFxId,
        int impactFxId,
        int killTime,
        int shader,
        unsigned int flags)
{
  int         *p;
  int          particle;
  char        *oldBolt;
  const float *boltOrient;
  float       *dir;          
  float        sizeWave;
  float        sizeRate;
  int          record;       
  float        worldPos[3];  
  float        dir0[3];      
  float        dir1[3];      

  if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x0C)) < 1 )
    return 0;
  p = FxPool_AllocParticle(&fxPool_Particle, 316);
  if ( p )
  {
    p[54] = 0;                       
    *p = (int)&vtbl_CParticle;           
    p[15] = 4;                       
    particle = (int)p;
  }
  else
  {
    particle = 0;
  }
  record = particle;
  if ( particle )
  {
    CFxBoltFramePtr__assign_m( bolt, (char **)(particle + FX_PARTICLE_OFS( mBoltFrame )) );

    if ( *bolt )
    {
      boltOrient = (const float *)CFxBoltFrame__GetOrientation( (int)*bolt );
      OrientationPosFromWorldPos(boltOrient, (float *)org, worldPos);
      OrientationDirFromWorldDir(boltOrient, vel, dir0);
      OrientationDirFromWorldDir(boltOrient, accel, dir1);
      FX_PARTICLE(particle)->mOrigin1[0] = worldPos[0];
      FX_PARTICLE(particle)->mOrigin1[1] = worldPos[1];
      FX_PARTICLE(particle)->mOrigin1[2] = worldPos[2];
      CParticle__SetVel((unsigned int *)particle, (unsigned int *)dir0);
      CParticle__SetAccel((unsigned int *)particle, (unsigned int *)dir1);
    }
    else
    {
      if ( org )
      {
        *(unsigned int *)&FX_PARTICLE(particle)->mOrigin1[0] = *(unsigned int *)org;
        *(unsigned int *)&FX_PARTICLE(particle)->mOrigin1[1] = *(unsigned int *)(org + 4);
        *(unsigned int *)&FX_PARTICLE(particle)->mOrigin1[2] = *(unsigned int *)(org + 8);
      }
      else
      {
        *(unsigned int *)&FX_PARTICLE(particle)->mOrigin1[2] = 0;
        *(unsigned int *)&FX_PARTICLE(particle)->mOrigin1[1] = 0;
        *(unsigned int *)&FX_PARTICLE(particle)->mOrigin1[0] = 0;
      }
      CParticle__SetVel((unsigned int *)particle, (unsigned int *)vel);
      CParticle__SetAccel((unsigned int *)particle, (unsigned int *)accel);
    }

    if ( rgbStart )
    {
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBStart[0] = *rgbStart;
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBStart[1] = rgbStart[1];
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBStart[2] = rgbStart[2];
    }
    else
    {
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBStart[2] = 0;
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBStart[1] = 0;
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBStart[0] = 0;
    }
    if ( rgbEnd )
    {
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBEnd[0] = *rgbEnd;
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBEnd[1] = rgbEnd[1];
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBEnd[2] = rgbEnd[2];
    }
    else
    {
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBEnd[2] = 0;
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBEnd[1] = 0;
      *(unsigned int *)&FX_PARTICLE(particle)->mRGBEnd[0] = 0;
    }

    if ( (flags & 0xC0) == 0x80 )
      FX_PARTICLE(particle)->mRGBParm = rgbParm * 0.0031415902f;
    else if ( (flags & 0xC0) != 0 )
      FX_PARTICLE(particle)->mRGBParm = (float)killTime * rgbParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_PARTICLE(particle)->mAlphaStart; *member = alphaStart; }
    { int *member = (int *)&FX_PARTICLE(particle)->mAlphaEnd; *member = alphaEnd; }
    if ( (flags & 0xC) == 8 )
      FX_PARTICLE(particle)->mAlphaParm = alphaParm * 0.0031415902f;
    else if ( (flags & 0xC) != 0 )
      FX_PARTICLE(particle)->mAlphaParm = (float)killTime * alphaParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_PARTICLE(particle)->mSizeStart; *member = sizeStart; }
    { int *member = (int *)&FX_PARTICLE(particle)->mSizeEnd; *member = sizeEnd; }
    if ( (flags & 0xC00) == 0x800 )
    {
      sizeWave = sizeParm * 0.0031415902f;
      FX_PARTICLE(particle)->mSizeParm = sizeWave;
      if ( !useSize2 )
        FX_PARTICLE(particle)->mSize2Parm = sizeWave;
    }
    else if ( (flags & 0xC00) != 0 )
    {
      sizeRate = (float)killTime * sizeParm * 0.0099999998f;
      FX_PARTICLE(particle)->mSizeParm = (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04)) + sizeRate;
      if ( !useSize2 )
        FX_PARTICLE(particle)->mSize2Parm = (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04)) + sizeRate;
    }
    if ( useSize2 )
    {
      { int *member = (int *)&FX_PARTICLE(particle)->mSize2Start; *member = size2Start; }
      { int *member = (int *)&FX_PARTICLE(particle)->mSize2End; *member = size2End; }
      /* retail tests the size2 parm mask against 0x800 (FX_SIZE_WAVE's
       * value in the size field), so the wave branch never runs */
      if ( (flags & 0xC0000) == 0x800 )
        FX_PARTICLE(particle)->mSize2Parm = size2Parm * 0.0031415902f;
      else if ( (flags & 0xC0000) != 0 )
        FX_PARTICLE(particle)->mSize2Parm = (float)killTime * size2Parm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));
    }
    else
    {
      /* size2 follows size: copy the size parm-mode bits into the size2 field */
      flags &= 0xFFF0FFFF;
      flags |= ( flags & 0xF00 ) << 8;
      { int *member = (int *)&FX_PARTICLE(particle)->mSize2Start; *member = sizeStart; }
      { int *member = (int *)&FX_PARTICLE(particle)->mSize2End; *member = sizeEnd; }
    }
    { int *member = (int *)&FX_PARTICLE(particle)->mFlags; *member = flags; }
    { int *member = (int *)&FX_PARTICLE(particle)->mRefEnt.customShader; *member = shader; }
    { int *member = (int *)&FX_PARTICLE(particle)->mRefEnt.rotation; *member = rotation; }
    { int *member = (int *)&FX_PARTICLE(particle)->mRotationDelta; *member = rotationDelta; }
    { int *member = (int *)&FX_PARTICLE(particle)->mElasticity; *member = elasticity; }
    if ( mins )
    {
      *(unsigned int *)&FX_PARTICLE(particle)->mMin[0] = *mins;
      *(unsigned int *)&FX_PARTICLE(particle)->mMin[1] = mins[1];
      *(unsigned int *)&FX_PARTICLE(particle)->mMin[2] = mins[2];
    }
    else
    {
      *(unsigned int *)&FX_PARTICLE(particle)->mMin[2] = 0;
      *(unsigned int *)&FX_PARTICLE(particle)->mMin[1] = 0;
      *(unsigned int *)&FX_PARTICLE(particle)->mMin[0] = 0;
    }
    if ( maxs )
    {
      *(unsigned int *)&FX_PARTICLE(particle)->mMax[0] = *maxs;
      *(unsigned int *)&FX_PARTICLE(particle)->mMax[1] = maxs[1];
      *(unsigned int *)&FX_PARTICLE(particle)->mMax[2] = maxs[2];
    }
    else
    {
      *(unsigned int *)&FX_PARTICLE(particle)->mMax[2] = 0;
      *(unsigned int *)&FX_PARTICLE(particle)->mMax[1] = 0;
      *(unsigned int *)&FX_PARTICLE(particle)->mMax[0] = 0;
    }
    { int *member = (int *)&FX_PARTICLE(particle)->mDeathFxID; *member = deathFxId; }
    { int *member = (int *)&FX_PARTICLE(particle)->mImpactFxID; *member = impactFxId; }
    FX_AddPrimitive(&record, killTime);
  }
  return particle;
}

/* FX_AddLine .. FX_AddFlash: the C++ originals fill the new primitive
 * through inline setters (fx->SetSizeStart( size1 ), fx->SetFlags( flags ),
 * fx->SetSTScale( 1.0f, 1.0f ), ...).  Where retail keeps such stores in
 * source order, the C here writes them through the member's own address,
 * `{ int *member = (int *)(fx + offset); *member = value; }`: VC7 cannot
 * disambiguate that store from its neighbours, so it is neither sunk past
 * the following flag test nor reordered behind call setup, as in retail.
 * The bolt test reads the smart pointer again (`if ( *bolt )`) the way
 * CFxBoltFramePtr::operator bool does, which lets VC7 thread the null case
 * straight from the inlined assignment. */

/* ---- FX_AddLine  0x0049F740 ----  [CONFIRMED] */
int __cdecl FX_AddLine(
        char **bolt,
        int start,
        FxTailLineVectorPointer endArg,
        int sizeStart,
        int sizeEnd,
        float sizeParm,
        int alphaStart,
        int alphaEnd,
        float alphaParm,
        unsigned int *rgbStart,
        unsigned int *rgbEnd,
        float rgbParm,
        int killTime,
        int shader,
        int flags)
{
  int         *p;
  int          line;
  char        *oldBolt;
  const float *boltOrient;
  int          record;       
  float        worldPos[3];  
  float        endPos[3];    

  if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x0C)) < 1 )
    return 0;
  p = FxPool_AllocLine(&fxPool_Line, 328);
  if ( p )
  {
    p[54] = 0;                       
    *p = (int)&vtbl_CLine;           
    p[15] = 13;                      
    line = (int)p;
  }
  else
  {
    line = 0;
  }
  record = line;
  if ( line )
  {

    CFxBoltFramePtr__assign_m( bolt, (char **)(line + FX_LINE_OFS( mBoltFrame )) );

    if ( *bolt )
    {
      boltOrient = (const float *)CFxBoltFrame__GetOrientation( (int)*bolt );
      OrientationPosFromWorldPos(boltOrient, (float *)start, worldPos);
      OrientationPosFromWorldPos(boltOrient, endArg.value, endPos);
      FX_LINE(line)->mOrigin1[0] = worldPos[0];
      FX_LINE(line)->mOrigin1[1] = worldPos[1];
      FX_LINE(line)->mOrigin1[2] = worldPos[2];
      FX_LINE(line)->mOrigin2[0] = endPos[0];
      FX_LINE(line)->mOrigin2[1] = endPos[1];
      FX_LINE(line)->mOrigin2[2] = endPos[2];
    }
    else
    {
      if ( start )
      {
        *(unsigned int *)&FX_LINE(line)->mOrigin1[0] = *(unsigned int *)start;
        *(unsigned int *)&FX_LINE(line)->mOrigin1[1] = *(unsigned int *)(start + 4);
        *(unsigned int *)&FX_LINE(line)->mOrigin1[2] = *(unsigned int *)(start + 8);
      }
      else
      {
        *(unsigned int *)&FX_LINE(line)->mOrigin1[2] = 0;
        *(unsigned int *)&FX_LINE(line)->mOrigin1[1] = 0;
        *(unsigned int *)&FX_LINE(line)->mOrigin1[0] = 0;
      }
      FX_LINE(line)->mOrigin2[0] = *endArg.value;
      FX_LINE(line)->mOrigin2[1] = endArg.value[1];
      FX_LINE(line)->mOrigin2[2] = endArg.value[2];
    }

    if ( rgbStart )
    {
      *(unsigned int *)&FX_LINE(line)->mRGBStart[0] = *rgbStart;
      *(unsigned int *)&FX_LINE(line)->mRGBStart[1] = rgbStart[1];
      *(unsigned int *)&FX_LINE(line)->mRGBStart[2] = rgbStart[2];
    }
    else
    {
      *(unsigned int *)&FX_LINE(line)->mRGBStart[2] = 0;
      *(unsigned int *)&FX_LINE(line)->mRGBStart[1] = 0;
      *(unsigned int *)&FX_LINE(line)->mRGBStart[0] = 0;
    }
    if ( rgbEnd )
    {
      *(unsigned int *)&FX_LINE(line)->mRGBEnd[0] = *rgbEnd;
      *(unsigned int *)&FX_LINE(line)->mRGBEnd[1] = rgbEnd[1];
      *(unsigned int *)&FX_LINE(line)->mRGBEnd[2] = rgbEnd[2];
    }
    else
    {
      *(unsigned int *)&FX_LINE(line)->mRGBEnd[2] = 0;
      *(unsigned int *)&FX_LINE(line)->mRGBEnd[1] = 0;
      *(unsigned int *)&FX_LINE(line)->mRGBEnd[0] = 0;
    }

  

    if ( (flags & 0xC0) == 0x80 )
      FX_LINE(line)->mRGBParm = rgbParm * 0.0031415902f;
    else if ( (flags & 0xC0) != 0 )
      FX_LINE(line)->mRGBParm = (float)killTime * rgbParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_LINE(line)->mAlphaStart; *member = alphaStart; }
    { int *member = (int *)&FX_LINE(line)->mAlphaEnd; *member = alphaEnd; }
    if ( (flags & 0xC) == 8 )
      FX_LINE(line)->mAlphaParm = alphaParm * 0.0031415902f;
    else if ( (flags & 0xC) != 0 )
      FX_LINE(line)->mAlphaParm = (float)killTime * alphaParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_LINE(line)->mSizeStart; *member = sizeStart; }
    { int *member = (int *)&FX_LINE(line)->mSizeEnd; *member = sizeEnd; }
    if ( (flags & 0xC00) == 0x800 )
      FX_LINE(line)->mSizeParm = sizeParm * 0.0031415902f;
    else if ( (flags & 0xC00) != 0 )
      FX_LINE(line)->mSizeParm = (float)killTime * sizeParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_LINE(line)->mRefEnt.customShader; *member = shader; }
    { int *member = (int *)&FX_LINE(line)->mFlags; *member = flags; }
    { float *member = (float *)FX_LINE(line)->mRefEnt.shaderTexCoord; member[0] = 1.0f; member[1] = 1.0f; }
    FX_AddPrimitive(&record, killTime);
  }
  return line;
}

/* ---- FX_AddElectricity  0x0049F9D0 ----  [CONFIRMED] */
int __cdecl FX_AddElectricity(
        char **bolt,
        int start,
        float *end,
        int sizeStart,
        int sizeEnd,
        float sizeParm,
        int alphaStart,
        int alphaEnd,
        float alphaParm,
        unsigned int *rgbStart,
        unsigned int *rgbEnd,
        float rgbParm,
        int chaos,
        int killTime,
        int shader,
        int flags)
{
  int         *p;
  int          elec;
  char        *oldBolt;
  const float *boltOrient;
  int          record;       
  float        worldPos[3];  
  float        endPos[3];    

  if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x0C)) < 1 )
    return 0;
  p = FxPool_AllocElectricity(&fxPool_Electricity, 716);
  if ( p )
  {
    p[54] = 0;                       
    *p = (int)&vtbl_CElectricity;           
    p[15] = 14;                      
    elec = (int)p;
  }
  else
  {
    elec = 0;
  }
  record = elec;
  if ( elec )
  {

    CFxBoltFramePtr__assign_m( bolt, (char **)(elec + FX_ELECTRICITY_OFS( mBoltFrame )) );

    if ( *bolt )
    {
      boltOrient = (const float *)CFxBoltFrame__GetOrientation( (int)*bolt );
      /* Retail re-reads `end` from its argument slot here instead of
       * caching it in a callee-saved register across the first call; the
       * volatile read reproduces that allocation. */
      OrientationPosFromWorldPos(boltOrient, (float *)start, worldPos);
      OrientationPosFromWorldPos(boltOrient, *(float *volatile *)&end, endPos);
      /* Original bug kept: SetOrigin1 is called twice (the second call was
       * meant to be SetOrigin2), so origin1 ends up as the end point and
       * origin2 stays unset on this path.  The first store goes through the
       * member's address so VC7 keeps it, and with it the first transform. */
      { float *member = (float *)FX_ELECTRICITY(elec)->mOrigin1; member[0] = worldPos[0]; member[1] = worldPos[1]; member[2] = worldPos[2]; }
      FX_ELECTRICITY(elec)->mOrigin1[0] = endPos[0];
      FX_ELECTRICITY(elec)->mOrigin1[1] = endPos[1];
      FX_ELECTRICITY(elec)->mOrigin1[2] = endPos[2];
    }
    else
    {
      if ( start )
      {
        *(unsigned int *)&FX_ELECTRICITY(elec)->mOrigin1[0] = *(unsigned int *)start;
        *(unsigned int *)&FX_ELECTRICITY(elec)->mOrigin1[1] = *(unsigned int *)(start + 4);
        *(unsigned int *)&FX_ELECTRICITY(elec)->mOrigin1[2] = *(unsigned int *)(start + 8);
      }
      else
      {
        *(unsigned int *)&FX_ELECTRICITY(elec)->mOrigin1[2] = 0;
        *(unsigned int *)&FX_ELECTRICITY(elec)->mOrigin1[1] = 0;
        *(unsigned int *)&FX_ELECTRICITY(elec)->mOrigin1[0] = 0;
      }
      FX_ELECTRICITY(elec)->mOrigin2[0] = *end;
      FX_ELECTRICITY(elec)->mOrigin2[1] = end[1];
      FX_ELECTRICITY(elec)->mOrigin2[2] = end[2];
    }

    if ( rgbStart )
    {
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBStart[0] = *rgbStart;
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBStart[1] = rgbStart[1];
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBStart[2] = rgbStart[2];
    }
    else
    {
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBStart[2] = 0;
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBStart[1] = 0;
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBStart[0] = 0;
    }
    if ( rgbEnd )
    {
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBEnd[0] = *rgbEnd;
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBEnd[1] = rgbEnd[1];
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBEnd[2] = rgbEnd[2];
    }
    else
    {
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBEnd[2] = 0;
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBEnd[1] = 0;
      *(unsigned int *)&FX_ELECTRICITY(elec)->mRGBEnd[0] = 0;
    }

  

    if ( (flags & 0xC0) == 0x80 )
      FX_ELECTRICITY(elec)->mRGBParm = rgbParm * 0.0031415902f;
    else if ( (flags & 0xC0) != 0 )
      FX_ELECTRICITY(elec)->mRGBParm = (float)killTime * rgbParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_ELECTRICITY(elec)->mAlphaStart; *member = alphaStart; }
    { int *member = (int *)&FX_ELECTRICITY(elec)->mAlphaEnd; *member = alphaEnd; }
    if ( (flags & 0xC) == 8 )
      FX_ELECTRICITY(elec)->mAlphaParm = alphaParm * 0.0031415902f;
    else if ( (flags & 0xC) != 0 )
      FX_ELECTRICITY(elec)->mAlphaParm = (float)killTime * alphaParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_ELECTRICITY(elec)->mSizeStart; *member = sizeStart; }
    { int *member = (int *)&FX_ELECTRICITY(elec)->mSizeEnd; *member = sizeEnd; }
    if ( (flags & 0xC00) == 0x800 )
      FX_ELECTRICITY(elec)->mSizeParm = sizeParm * 0.0031415902f;
    else if ( (flags & 0xC00) != 0 )
      FX_ELECTRICITY(elec)->mSizeParm = (float)killTime * sizeParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_ELECTRICITY(elec)->mRefEnt.customShader; *member = shader; }
    { int *member = (int *)&FX_ELECTRICITY(elec)->mFlags; *member = flags; }
    { int *member = (int *)&FX_ELECTRICITY(elec)->mChaos; *member = chaos; }
    { float *member = (float *)FX_ELECTRICITY(elec)->mRefEnt.shaderTexCoord; member[0] = 1.0f; member[1] = 1.0f; }
    FX_AddPrimitive(&record, killTime);
    CElectricity__Initialize(elec);
  }
  return elec;
}

/* ---- FX_AddTail  0x0049FC60 ----  [CONFIRMED] */
int __cdecl FX_AddTail(
        char **bolt,
        int org,
        FxTailMotionVectorPointer velArg,
        FxTailMotionVectorPointer accelArg,
        int sizeStart,
        int sizeEnd,
        float sizeParm,
        int lengthStart,
        int lengthEnd,
        float lengthParm,
        int alphaStart,
        int alphaEnd,
        float alphaParm,
        unsigned int *rgbStart,
        unsigned int *rgbEnd,
        float rgbParm,
        unsigned int *mins,
        unsigned int *maxs,
        int elasticity,
        int deathFxId,
        int impactFxId,
        int killTime,
        int shader,
        int flags)
{
  int         *p;
  int          tail;
  char        *oldBolt;
  const float *boltOrient;
  float       *dir;          
  int          record;       
  float        worldPos[3];  
  float        dir0[3];      
  float        dir1[3];      

  if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x0C)) < 1 )
    return 0;
  p = FxPool_AllocTail(&fxPool_Tail, 344);
  if ( p )
  {
    p[54] = 0;                       
    *p = (int)&vtbl_CTail;           
    p[15] = 13;                      
    tail = (int)p;
  }
  else
  {
    tail = 0;
  }
  record = tail;
  if ( tail )
  {

    CFxBoltFramePtr__assign_m( bolt, (char **)(tail + FX_TAIL_OFS( mBoltFrame )) );

    if ( *bolt )
    {
      boltOrient = (const float *)CFxBoltFrame__GetOrientation( (int)*bolt );
      OrientationPosFromWorldPos(boltOrient, (float *)org, worldPos);
      OrientationDirFromWorldDir(boltOrient, velArg.value, dir0);
      OrientationDirFromWorldDir(boltOrient, accelArg.value, dir1);
      FX_TAIL(tail)->mOrigin1[0] = worldPos[0];
      FX_TAIL(tail)->mOrigin1[1] = worldPos[1];
      FX_TAIL(tail)->mOrigin1[2] = worldPos[2];
      CParticle__SetVel((unsigned int *)tail, (unsigned int *)dir0);
      CParticle__SetAccel((unsigned int *)tail, (unsigned int *)dir1);
    }
    else
    {
      if ( org )
      {
        *(unsigned int *)&FX_TAIL(tail)->mOrigin1[0] = *(unsigned int *)org;
        *(unsigned int *)&FX_TAIL(tail)->mOrigin1[1] = *(unsigned int *)(org + 4);
        *(unsigned int *)&FX_TAIL(tail)->mOrigin1[2] = *(unsigned int *)(org + 8);
      }
      else
      {
        *(unsigned int *)&FX_TAIL(tail)->mOrigin1[2] = 0;
        *(unsigned int *)&FX_TAIL(tail)->mOrigin1[1] = 0;
        *(unsigned int *)&FX_TAIL(tail)->mOrigin1[0] = 0;
      }
      CParticle__SetVel((unsigned int *)tail, (unsigned int *)velArg.value);
      CParticle__SetAccel((unsigned int *)tail, (unsigned int *)accelArg.value);
    }

    if ( rgbStart )
    {
      *(unsigned int *)&FX_TAIL(tail)->mRGBStart[0] = *rgbStart;
      *(unsigned int *)&FX_TAIL(tail)->mRGBStart[1] = rgbStart[1];
      *(unsigned int *)&FX_TAIL(tail)->mRGBStart[2] = rgbStart[2];
    }
    else
    {
      *(unsigned int *)&FX_TAIL(tail)->mRGBStart[2] = 0;
      *(unsigned int *)&FX_TAIL(tail)->mRGBStart[1] = 0;
      *(unsigned int *)&FX_TAIL(tail)->mRGBStart[0] = 0;
    }
    if ( rgbEnd )
    {
      *(unsigned int *)&FX_TAIL(tail)->mRGBEnd[0] = *rgbEnd;
      *(unsigned int *)&FX_TAIL(tail)->mRGBEnd[1] = rgbEnd[1];
      *(unsigned int *)&FX_TAIL(tail)->mRGBEnd[2] = rgbEnd[2];
    }
    else
    {
      *(unsigned int *)&FX_TAIL(tail)->mRGBEnd[2] = 0;
      *(unsigned int *)&FX_TAIL(tail)->mRGBEnd[1] = 0;
      *(unsigned int *)&FX_TAIL(tail)->mRGBEnd[0] = 0;
    }

  

    if ( (flags & 0xC0) == 0x80 )
      FX_TAIL(tail)->mRGBParm = rgbParm * 0.0031415902f;
    else if ( (flags & 0xC0) != 0 )
      FX_TAIL(tail)->mRGBParm = (float)killTime * rgbParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_TAIL(tail)->mAlphaStart; *member = alphaStart; }
    { int *member = (int *)&FX_TAIL(tail)->mAlphaEnd; *member = alphaEnd; }
    if ( (flags & 0xC) == 8 )
      FX_TAIL(tail)->mAlphaParm = alphaParm * 0.0031415902f;
    else if ( (flags & 0xC) != 0 )
      FX_TAIL(tail)->mAlphaParm = (float)killTime * alphaParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_TAIL(tail)->mSizeStart; *member = sizeStart; }
    { int *member = (int *)&FX_TAIL(tail)->mSizeEnd; *member = sizeEnd; }
    if ( (flags & 0xC00) == 0x800 )
      FX_TAIL(tail)->mSizeParm = sizeParm * 0.0031415902f;
    else if ( (flags & 0xC00) != 0 )
      FX_TAIL(tail)->mSizeParm = (float)killTime * sizeParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_TAIL(tail)->mLengthStart; *member = lengthStart; }
    { int *member = (int *)&FX_TAIL(tail)->mLengthEnd; *member = lengthEnd; }
    if ( (flags & 0xC000) == 0x8000 )
      FX_TAIL(tail)->mLengthParm = lengthParm * 0.0031415902f;
    else if ( (flags & 0xC000) != 0 )
      FX_TAIL(tail)->mLengthParm = (float)killTime * lengthParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    *(unsigned int *)&FX_TAIL(tail)->mFlags = flags;
    *(unsigned int *)&FX_TAIL(tail)->mRefEnt.customShader = shader;
    *(unsigned int *)&FX_TAIL(tail)->mElasticity = elasticity;
    if ( mins )
    {
      *(unsigned int *)&FX_TAIL(tail)->mMin[0] = *mins;
      *(unsigned int *)&FX_TAIL(tail)->mMin[1] = mins[1];
      *(unsigned int *)&FX_TAIL(tail)->mMin[2] = mins[2];
    }
    else
    {
      *(unsigned int *)&FX_TAIL(tail)->mMin[2] = 0;
      *(unsigned int *)&FX_TAIL(tail)->mMin[1] = 0;
      *(unsigned int *)&FX_TAIL(tail)->mMin[0] = 0;
    }
    if ( maxs )
    {
      *(unsigned int *)&FX_TAIL(tail)->mMax[0] = *maxs;
      *(unsigned int *)&FX_TAIL(tail)->mMax[1] = maxs[1];
      *(unsigned int *)&FX_TAIL(tail)->mMax[2] = maxs[2];
    }
    else
    {
      *(unsigned int *)&FX_TAIL(tail)->mMax[2] = 0;
      *(unsigned int *)&FX_TAIL(tail)->mMax[1] = 0;
      *(unsigned int *)&FX_TAIL(tail)->mMax[0] = 0;
    }
    { float *member = (float *)FX_TAIL(tail)->mRefEnt.shaderTexCoord; member[0] = 1.0f; member[1] = 1.0f; }
    { int *member = (int *)&FX_TAIL(tail)->mDeathFxID; *member = deathFxId; }
    { int *member = (int *)&FX_TAIL(tail)->mImpactFxID; *member = impactFxId; }
    FX_AddPrimitive(&record, killTime);
  }
  return tail;
}

/* ---- FX_AddCylinder  0x0049FFB0 ----  [CONFIRMED] */
int __cdecl FX_AddCylinder(
        char **bolt,
        int start,
        float *normal,
        int sizeStart,
        int sizeEnd,
        float sizeParm,
        int size2Start,
        int size2End,
        float size2Parm,
        int lengthStart,
        int lengthEnd,
        float lengthParm,
        int alphaStart,
        int alphaEnd,
        float alphaParm,
        unsigned int *rgbStart,
        unsigned int *rgbEnd,
        float rgbParm,
        int killTime,
        int shader,
        int flags)
{
  int         *p;
  int          cyl;
  char        *oldBolt;
  const float *boltOrient;
  int          record;       
  float        worldPos[3];  
  float        axis[3];      

  if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x0C)) < 1 )
    return 0;
  p = FxPool_AllocCylinder(&fxPool_Cylinder, 344);
  if ( p )
  {
    p[54] = 0;                       
    *p = (int)&vtbl_CCylinder;           
    p[15] = 15;                      
    cyl = (int)p;
  }
  else
  {
    cyl = 0;
  }
  record = cyl;
  if ( cyl )
  {

    CFxBoltFramePtr__assign_m( bolt, (char **)(cyl + FX_CYLINDER_OFS( mBoltFrame )) );

    if ( *bolt )
    {
      boltOrient = (const float *)CFxBoltFrame__GetOrientation( (int)*bolt );
      OrientationPosFromWorldPos(boltOrient, (float *)start, worldPos);
      OrientationDirFromWorldDir(boltOrient, normal, axis);
      FX_CYLINDER(cyl)->mOrigin1[0] = worldPos[0];
      FX_CYLINDER(cyl)->mOrigin1[1] = worldPos[1];
      FX_CYLINDER(cyl)->mOrigin1[2] = worldPos[2];
      FX_CYLINDER(cyl)->mRefEnt.axis[0][0] = axis[0];
      FX_CYLINDER(cyl)->mRefEnt.axis[0][1] = axis[1];
      FX_CYLINDER(cyl)->mRefEnt.axis[0][2] = axis[2];
    }
    else
    {
      if ( start )
      {
        *(unsigned int *)&FX_CYLINDER(cyl)->mOrigin1[0] = *(unsigned int *)start;
        *(unsigned int *)&FX_CYLINDER(cyl)->mOrigin1[1] = *(unsigned int *)(start + 4);
        *(unsigned int *)&FX_CYLINDER(cyl)->mOrigin1[2] = *(unsigned int *)(start + 8);
      }
      else
      {
        *(unsigned int *)&FX_CYLINDER(cyl)->mOrigin1[2] = 0;
        *(unsigned int *)&FX_CYLINDER(cyl)->mOrigin1[1] = 0;
        *(unsigned int *)&FX_CYLINDER(cyl)->mOrigin1[0] = 0;
      }
      FX_CYLINDER(cyl)->mRefEnt.axis[0][0] = *normal;
      FX_CYLINDER(cyl)->mRefEnt.axis[0][1] = normal[1];
      FX_CYLINDER(cyl)->mRefEnt.axis[0][2] = normal[2];
    }

    if ( rgbStart )
    {
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBStart[0] = *rgbStart;
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBStart[1] = rgbStart[1];
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBStart[2] = rgbStart[2];
    }
    else
    {
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBStart[2] = 0;
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBStart[1] = 0;
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBStart[0] = 0;
    }
    if ( rgbEnd )
    {
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBEnd[0] = *rgbEnd;
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBEnd[1] = rgbEnd[1];
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBEnd[2] = rgbEnd[2];
    }
    else
    {
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBEnd[2] = 0;
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBEnd[1] = 0;
      *(unsigned int *)&FX_CYLINDER(cyl)->mRGBEnd[0] = 0;
    }

  

    if ( (flags & 0xC0) == 0x80 )
      FX_CYLINDER(cyl)->mRGBParm = rgbParm * 0.0031415902f;
    else if ( (flags & 0xC0) != 0 )
      FX_CYLINDER(cyl)->mRGBParm = (float)killTime * rgbParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    *(unsigned int *)&FX_CYLINDER(cyl)->mSizeStart = sizeStart;
    *(unsigned int *)&FX_CYLINDER(cyl)->mSizeEnd = sizeEnd;
    if ( (flags & 0xC00) == 0x800 )
      FX_CYLINDER(cyl)->mSizeParm = sizeParm * 0.0031415902f;
    else if ( (flags & 0xC00) != 0 )
      FX_CYLINDER(cyl)->mSizeParm = (float)killTime * sizeParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    *(unsigned int *)&FX_CYLINDER(cyl)->mSize2Start = size2Start;
    *(unsigned int *)&FX_CYLINDER(cyl)->mSize2End = size2End;
    if ( (flags & 0xC0000) == 0x80000 )
      FX_CYLINDER(cyl)->mSize2Parm = size2Parm * 0.0031415902f;
    else if ( (flags & 0xC0000) != 0 )
      FX_CYLINDER(cyl)->mSize2Parm = (float)killTime * size2Parm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    *(unsigned int *)&FX_CYLINDER(cyl)->mLengthStart = lengthStart;
    *(unsigned int *)&FX_CYLINDER(cyl)->mLengthEnd = lengthEnd;
    if ( (flags & 0xC000) == 0x8000 )
      FX_CYLINDER(cyl)->mLengthParm = lengthParm * 0.0031415902f;
    else if ( (flags & 0xC000) != 0 )
      FX_CYLINDER(cyl)->mLengthParm = (float)killTime * lengthParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    *(unsigned int *)&FX_CYLINDER(cyl)->mAlphaStart = alphaStart;
    *(unsigned int *)&FX_CYLINDER(cyl)->mAlphaEnd = alphaEnd;
    if ( (flags & 0xC) == 8 )
      FX_CYLINDER(cyl)->mAlphaParm = alphaParm * 0.0031415902f;
    else if ( (flags & 0xC) != 0 )
      FX_CYLINDER(cyl)->mAlphaParm = (float)killTime * alphaParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_CYLINDER(cyl)->mRefEnt.customShader; *member = shader; }
    { int *member = (int *)&FX_CYLINDER(cyl)->mFlags; *member = flags; }
    FX_AddPrimitive(&record, killTime);
  }
  return cyl;
}

/* ---- FX_AddEmitter  0x004A02C0 ----  [CONFIRMED] */
/* `flags` is the argument used in place; mFlags/dobj/elasticity go through
 * the member address; the step distance is 2 * (r / 32768) - 1 in floats
 * (fadd st,st).  Remaining difference: retail receives bolt in ecx (esi) and
 * keeps the constant 1 in ebx; LTCG passes bolt on the stack here. */
int __cdecl FX_AddEmitter(
        int org,
        char **bolt,
        float *vel,
        float *accel,
        int sizeStart,
        int sizeEnd,
        float sizeParm,
        int alphaStart,
        int alphaEnd,
        float alphaParm,
        unsigned int *rgbStart,
        unsigned int *rgbEnd,
        float rgbParm,
        unsigned int *angles,
        unsigned int *angleDelta,
        unsigned int *mins,
        unsigned int *maxs,
        int elasticity,
        int deathFxId,
        int impactFxId,
        int emitterFxId,
        int density,
        int variance,
        int killTime,
        int model,
        unsigned int flags)
{
  int         *p;
  int          emitter;
  char        *oldBolt;
  float       *boltOrient;
  int          r;
  int          record;       
  float        worldPos[3];  
  float        dir0[3];      
  float        dir1[3];      

  if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x0C)) < 1 )
    return 0;
  p = FxPool_AllocEmitter(&fxPool_Emitter, 396);
  if ( p )
  {
    p[54] = 0;                       
    p[15] = 1;                       
    *p = (int)&vtbl_CEmitter;           
    emitter = (int)p;
  }
  else
  {
    emitter = 0;
  }
  record = emitter;
  if ( emitter )
  {

    CFxBoltFramePtr__assign_m( bolt, (char **)(emitter + FX_EMITTER_OFS( mBoltFrame )) );

    if ( *bolt )
    {
      boltOrient = (float *)CFxBoltFrame__GetOrientation( (int)*bolt );
      OrientationPosFromWorldPos(boltOrient, (float *)org, worldPos);
      OrientationDirFromWorldDir(boltOrient, vel, dir0);
      OrientationDirFromWorldDir(boltOrient, accel, dir1);
      FX_EMITTER(emitter)->mOrigin1[0] = worldPos[0];
      FX_EMITTER(emitter)->mOrigin1[1] = worldPos[1];
      FX_EMITTER(emitter)->mOrigin1[2] = worldPos[2];
      CParticle__SetVel((unsigned int *)emitter, (unsigned int *)dir0);
      CParticle__SetAccel((unsigned int *)emitter, (unsigned int *)dir1);
      CEmitter__SetLastOrg((unsigned int *)emitter, (unsigned int *)worldPos);
      CEmitter__SetLastVel((unsigned int *)emitter, (unsigned int *)dir0);
      CEmitter__SetLastBoltOrg_m((unsigned int *)emitter, (unsigned int *)boltOrient);
    }
    else
    {
      if ( org )
      {
        *(unsigned int *)&FX_EMITTER(emitter)->mOrigin1[0] = *(unsigned int *)org;
        *(unsigned int *)&FX_EMITTER(emitter)->mOrigin1[1] = *(unsigned int *)(org + 4);
        *(unsigned int *)&FX_EMITTER(emitter)->mOrigin1[2] = *(unsigned int *)(org + 8);
      }
      else
      {
        *(unsigned int *)&FX_EMITTER(emitter)->mOrigin1[2] = 0;
        *(unsigned int *)&FX_EMITTER(emitter)->mOrigin1[1] = 0;
        *(unsigned int *)&FX_EMITTER(emitter)->mOrigin1[0] = 0;
      }
      CParticle__SetVel((unsigned int *)emitter, (unsigned int *)vel);
      CParticle__SetAccel((unsigned int *)emitter, (unsigned int *)accel);
      CEmitter__SetLastOrg((unsigned int *)emitter, (unsigned int *)org);
      CEmitter__SetLastVel((unsigned int *)emitter, (unsigned int *)vel);
      *(unsigned int *)&FX_EMITTER(emitter)->mLastBoltOrigin[2] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mLastBoltOrigin[1] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mLastBoltOrigin[0] = 0;
    }

    if ( (flags & 0x800000) == 0 )
    {
      if ( org )
      {
        *(unsigned int *)&FX_EMITTER(emitter)->mRefEnt.lightingOrigin[0] = *(unsigned int *)org;
        *(unsigned int *)&FX_EMITTER(emitter)->mRefEnt.lightingOrigin[1] = *(unsigned int *)(org + 4);
        *(unsigned int *)&FX_EMITTER(emitter)->mRefEnt.lightingOrigin[2] = *(unsigned int *)(org + 8);
        *(unsigned int *)&FX_EMITTER(emitter)->mRefEnt.renderfx |= 0x80u;
      }
    }

    if ( rgbStart )
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBStart[0] = *rgbStart;
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBStart[1] = rgbStart[1];
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBStart[2] = rgbStart[2];
    }
    else
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBStart[2] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBStart[1] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBStart[0] = 0;
    }
    if ( rgbEnd )
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBEnd[0] = *rgbEnd;
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBEnd[1] = rgbEnd[1];
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBEnd[2] = rgbEnd[2];
    }
    else
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBEnd[2] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBEnd[1] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mRGBEnd[0] = 0;
    }

  

    if ( (flags & 0xC0) == 0x80 )
      FX_EMITTER(emitter)->mRGBParm = rgbParm * 0.0031415902f;
    else if ( (flags & 0xC0) != 0 )
      FX_EMITTER(emitter)->mRGBParm = (float)killTime * rgbParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    *(unsigned int *)&FX_EMITTER(emitter)->mSizeStart = sizeStart;
    *(unsigned int *)&FX_EMITTER(emitter)->mSizeEnd = sizeEnd;
    if ( (flags & 0xC00) == 0x800 )
      FX_EMITTER(emitter)->mSizeParm = sizeParm * 0.0031415902f;
    else if ( (flags & 0xC00) != 0 )
      FX_EMITTER(emitter)->mSizeParm = (float)killTime * sizeParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    *(unsigned int *)&FX_EMITTER(emitter)->mAlphaStart = alphaStart;
    *(unsigned int *)&FX_EMITTER(emitter)->mAlphaEnd = alphaEnd;
    if ( (flags & 0xC) == 8 )
      FX_EMITTER(emitter)->mAlphaParm = alphaParm * 0.0031415902f;
    else if ( (flags & 0xC) != 0 )
      FX_EMITTER(emitter)->mAlphaParm = (float)killTime * alphaParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    if ( !model )
      flags &= 0xFEFFFFFF;
    if ( angles )
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mAngles[0] = *angles;
      *(unsigned int *)&FX_EMITTER(emitter)->mAngles[1] = angles[1];
      *(unsigned int *)&FX_EMITTER(emitter)->mAngles[2] = angles[2];
    }
    else
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mAngles[2] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mAngles[1] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mAngles[0] = 0;
    }
    if ( angleDelta )
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mAngleDelta[0] = *angleDelta;
      *(unsigned int *)&FX_EMITTER(emitter)->mAngleDelta[1] = angleDelta[1];
      *(unsigned int *)&FX_EMITTER(emitter)->mAngleDelta[2] = angleDelta[2];
    }
    else
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mAngleDelta[2] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mAngleDelta[1] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mAngleDelta[0] = 0;
    }
    { int *member = (int *)&FX_EMITTER(emitter)->mFlags; *member = flags; }
    { int *member = (int *)&FX_EMITTER(emitter)->mRefEnt.dobj; *member = model; }
    { int *member = (int *)&FX_EMITTER(emitter)->mElasticity; *member = elasticity; }
    if ( mins )
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mMin[0] = *mins;
      *(unsigned int *)&FX_EMITTER(emitter)->mMin[1] = mins[1];
      *(unsigned int *)&FX_EMITTER(emitter)->mMin[2] = mins[2];
    }
    else
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mMin[2] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mMin[1] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mMin[0] = 0;
    }
    if ( maxs )
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mMax[0] = *maxs;
      *(unsigned int *)&FX_EMITTER(emitter)->mMax[1] = maxs[1];
      *(unsigned int *)&FX_EMITTER(emitter)->mMax[2] = maxs[2];
    }
    else
    {
      *(unsigned int *)&FX_EMITTER(emitter)->mMax[2] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mMax[1] = 0;
      *(unsigned int *)&FX_EMITTER(emitter)->mMax[0] = 0;
    }
    *(unsigned int *)&FX_EMITTER(emitter)->mDeathFxID = deathFxId;
    *(unsigned int *)&FX_EMITTER(emitter)->mImpactFxID = impactFxId;
    *(unsigned int *)&FX_EMITTER(emitter)->mEmitterFxID = emitterFxId;
    *(unsigned int *)&FX_EMITTER(emitter)->mDensity = density;
    *(unsigned int *)&FX_EMITTER(emitter)->mVariance = variance;
    *(unsigned int *)&FX_EMITTER(emitter)->mOldTime = (*(int *)(((unsigned char *)&theFxHelper) + 0x04));
    r = rand();
  

    FX_EMITTER(emitter)->mStepDistance = (2.0f * ((float)r * 0.000030517578125f) - 1.0f)
                              * FX_EMITTER(emitter)->mVariance
                              + FX_EMITTER(emitter)->mDensity;
    FX_AddPrimitive(&record, killTime);
  }
  return emitter;
}

/* ---- FX_AddLight  0x004A06F0 ----  [CONFIRMED] */
int __cdecl FX_AddLight(
        char **bolt,
        float *org,
        float sizeStart,
        float sizeEnd,
        float sizeParm,
        unsigned int *rgbStart,
        unsigned int *rgbEnd,
        float rgbParm,
        int killTime,
        int flags)
{
  int         *p;
  int          light;
  char        *oldBolt;
  const float *boltOrient;
  int          record;       
  float        worldPos[3];  

  if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x0C)) < 1 )
    return 0;
  p = FxPool_AllocLight(&fxPool_Light, 260);
  if ( p )
  {
    p[54] = 0;                       
    *p = (int)&vtbl_CLight;           
    light = (int)p;
  }
  else
  {
    light = 0;
  }
  record = light;
  if ( light )
  {

    CFxBoltFramePtr__assign_m( bolt, (char **)(light + FX_LIGHT_OFS( mBoltFrame )) );

    if ( *bolt )
    {
      boltOrient = (const float *)CFxBoltFrame__GetOrientation( (int)*bolt );
      OrientationPosFromWorldPos(boltOrient, org, worldPos);
      FX_LIGHT(light)->mOrigin1[0] = worldPos[0];
      FX_LIGHT(light)->mOrigin1[1] = worldPos[1];
      FX_LIGHT(light)->mOrigin1[2] = worldPos[2];
    }
    else
    {
      if ( org )
      {
        FX_LIGHT(light)->mOrigin1[0] = *org;
        FX_LIGHT(light)->mOrigin1[1] = org[1];
        FX_LIGHT(light)->mOrigin1[2] = org[2];
      }
      else
      {
        *(unsigned int *)&FX_LIGHT(light)->mOrigin1[2] = 0;
        *(unsigned int *)&FX_LIGHT(light)->mOrigin1[1] = 0;
        *(unsigned int *)&FX_LIGHT(light)->mOrigin1[0] = 0;
      }
    }

    if ( rgbStart )
    {
      *(unsigned int *)&FX_LIGHT(light)->mRGBStart[0] = *rgbStart;
      *(unsigned int *)&FX_LIGHT(light)->mRGBStart[1] = rgbStart[1];
      *(unsigned int *)&FX_LIGHT(light)->mRGBStart[2] = rgbStart[2];
    }
    else
    {
      *(unsigned int *)&FX_LIGHT(light)->mRGBStart[2] = 0;
      *(unsigned int *)&FX_LIGHT(light)->mRGBStart[1] = 0;
      *(unsigned int *)&FX_LIGHT(light)->mRGBStart[0] = 0;
    }
    if ( rgbEnd )
    {
      *(unsigned int *)&FX_LIGHT(light)->mRGBEnd[0] = *rgbEnd;
      *(unsigned int *)&FX_LIGHT(light)->mRGBEnd[1] = rgbEnd[1];
      *(unsigned int *)&FX_LIGHT(light)->mRGBEnd[2] = rgbEnd[2];
    }
    else
    {
      *(unsigned int *)&FX_LIGHT(light)->mRGBEnd[2] = 0;
      *(unsigned int *)&FX_LIGHT(light)->mRGBEnd[1] = 0;
      *(unsigned int *)&FX_LIGHT(light)->mRGBEnd[0] = 0;
    }

  

    if ( (flags & 0xC0) == 0x80 )
      FX_LIGHT(light)->mRGBParm = rgbParm * 0.0031415902f;
    else if ( (flags & 0xC0) != 0 )
      FX_LIGHT(light)->mRGBParm = (float)killTime * rgbParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    /* SetSizeStart/SetSizeEnd (member stores: see the note above FX_AddLine) */
    { float *member = (float *)&FX_LIGHT(light)->mSizeStart; *member = sizeStart; }
    { float *member = (float *)&FX_LIGHT(light)->mSizeEnd; *member = sizeEnd; }
    if ( (flags & 0xC00) == 0x800 )
      FX_LIGHT(light)->mSizeParm = sizeParm * 0.0031415902f;
    else if ( (flags & 0xC00) != 0 )
      FX_LIGHT(light)->mSizeParm = (float)killTime * sizeParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    *(unsigned int *)&FX_LIGHT(light)->mFlags = flags;
    FX_AddPrimitive(&record, killTime);
  }
  return light;
}

/* ---- FX_AddOrientedParticle  0x004A08D0 ----  [CONFIRMED] */
/* Same register shape as FX_AddParticle (volatile vel/accel/sizeStart/
 * sizeEnd, `flags` used in place, member-address setters).  Remaining
 * difference: LTCG passes org in eax/edi and normal in ebx here, retail the
 * other way round (normal in eax, org in ebx). */
int __cdecl FX_AddOrientedParticle(
        char **bolt,
        int normal,
        int org,
        float *volatile vel,
        float *volatile accel,
        char useSize2,
        int volatile sizeStart,
        int volatile sizeEnd,
        float sizeParm,
        int size2Start,
        int size2End,
        float size2Parm,
        int alphaStart,
        int alphaEnd,
        float alphaParm,
        unsigned int *rgbStart,
        unsigned int *rgbEnd,
        float rgbParm,
        int rotation,
        int rotationDelta,
        unsigned int *mins,
        unsigned int *maxs,
        int elasticity,
        int deathFxId,
        int impactFxId,
        int killTime,
        int shader,
        unsigned int flags)
{
  int         *p;
  int          op;           
  char        *oldBolt;
  const float *boltOrient;
  float       *dir;          
  float        sizeWave;
  float        sizeRate;
  int          record;       
  float        worldPos[3];  
  float        fwd[3];       
  float        dir0[3];      
  float        dir1[3];      

  if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x0C)) < 1 )
    return 0;
  p = FxPool_AllocOrientedParticle(&fxPool_OrientedParticle, 328);
  if ( p )
  {
    p[54] = 0;                       
    *p = (int)&vtbl_COrientedParticle;           
    p[15] = 12;                       
    op = (int)p;
  }
  else
  {
    op = 0;
  }
  record = op;
  if ( op )
  {
    CFxBoltFramePtr__assign_m( bolt, (char **)(op + FX_ORIENTED_OFS( mBoltFrame )) );

    if ( *bolt )
    {
      boltOrient = (const float *)CFxBoltFrame__GetOrientation( (int)*bolt );
      OrientationPosFromWorldPos(boltOrient, (float *)org, worldPos);
      OrientationDirFromWorldDir(boltOrient, (const float *)normal, fwd);
      OrientationDirFromWorldDir(boltOrient, vel, dir0);
      OrientationDirFromWorldDir(boltOrient, accel, dir1);
      FX_ORIENTED(op)->mOrigin1[0] = worldPos[0];
      FX_ORIENTED(op)->mOrigin1[1] = worldPos[1];
      FX_ORIENTED(op)->mOrigin1[2] = worldPos[2];
      FX_ORIENTED(op)->mNormal[0] = fwd[0];
      FX_ORIENTED(op)->mNormal[1] = fwd[1];
      FX_ORIENTED(op)->mNormal[2] = fwd[2];
      CParticle__SetVel((unsigned int *)op, (unsigned int *)dir0);
      CParticle__SetAccel((unsigned int *)op, (unsigned int *)dir1);
    }
    else
    {
      if ( org )
      {
        *(unsigned int *)&FX_ORIENTED(op)->mOrigin1[0] = *(unsigned int *)org;
        *(unsigned int *)&FX_ORIENTED(op)->mOrigin1[1] = *(unsigned int *)(org + 4);
        *(unsigned int *)&FX_ORIENTED(op)->mOrigin1[2] = *(unsigned int *)(org + 8);
      }
      else
      {
        *(unsigned int *)&FX_ORIENTED(op)->mOrigin1[2] = 0;
        *(unsigned int *)&FX_ORIENTED(op)->mOrigin1[1] = 0;
        *(unsigned int *)&FX_ORIENTED(op)->mOrigin1[0] = 0;
      }
      *(unsigned int *)&FX_ORIENTED(op)->mNormal[0] = *(unsigned int *)normal;
      *(unsigned int *)&FX_ORIENTED(op)->mNormal[1] = *(unsigned int *)(normal + 4);
      *(unsigned int *)&FX_ORIENTED(op)->mNormal[2] = *(unsigned int *)(normal + 8);
      CParticle__SetVel((unsigned int *)op, (unsigned int *)vel);
      CParticle__SetAccel((unsigned int *)op, (unsigned int *)accel);
    }

    if ( rgbStart )
    {
      *(unsigned int *)&FX_ORIENTED(op)->mRGBStart[0] = *rgbStart;
      *(unsigned int *)&FX_ORIENTED(op)->mRGBStart[1] = rgbStart[1];
      *(unsigned int *)&FX_ORIENTED(op)->mRGBStart[2] = rgbStart[2];
    }
    else
    {
      *(unsigned int *)&FX_ORIENTED(op)->mRGBStart[2] = 0;
      *(unsigned int *)&FX_ORIENTED(op)->mRGBStart[1] = 0;
      *(unsigned int *)&FX_ORIENTED(op)->mRGBStart[0] = 0;
    }
    if ( rgbEnd )
    {
      *(unsigned int *)&FX_ORIENTED(op)->mRGBEnd[0] = *rgbEnd;
      *(unsigned int *)&FX_ORIENTED(op)->mRGBEnd[1] = rgbEnd[1];
      *(unsigned int *)&FX_ORIENTED(op)->mRGBEnd[2] = rgbEnd[2];
    }
    else
    {
      *(unsigned int *)&FX_ORIENTED(op)->mRGBEnd[2] = 0;
      *(unsigned int *)&FX_ORIENTED(op)->mRGBEnd[1] = 0;
      *(unsigned int *)&FX_ORIENTED(op)->mRGBEnd[0] = 0;
    }

    if ( (flags & 0xC0) == 0x80 )
      FX_ORIENTED(op)->mRGBParm = rgbParm * 0.0031415902f;
    else if ( (flags & 0xC0) != 0 )
      FX_ORIENTED(op)->mRGBParm = (float)killTime * rgbParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_ORIENTED(op)->mAlphaStart; *member = alphaStart; }
    { int *member = (int *)&FX_ORIENTED(op)->mAlphaEnd; *member = alphaEnd; }
    if ( (flags & 0xC) == 8 )
      FX_ORIENTED(op)->mAlphaParm = alphaParm * 0.0031415902f;
    else if ( (flags & 0xC) != 0 )
      FX_ORIENTED(op)->mAlphaParm = (float)killTime * alphaParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_ORIENTED(op)->mSizeStart; *member = sizeStart; }
    { int *member = (int *)&FX_ORIENTED(op)->mSizeEnd; *member = sizeEnd; }
    if ( (flags & 0xC00) == 0x800 )
    {
      sizeWave = sizeParm * 0.0031415902f;
      FX_ORIENTED(op)->mSizeParm = sizeWave;
      if ( !useSize2 )
        FX_ORIENTED(op)->mSize2Parm = sizeWave;
    }
    else if ( (flags & 0xC00) != 0 )
    {
      sizeRate = (float)killTime * sizeParm * 0.0099999998f;
      FX_ORIENTED(op)->mSizeParm = (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04)) + sizeRate;
      if ( !useSize2 )
        FX_ORIENTED(op)->mSize2Parm = (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04)) + sizeRate;
    }
    if ( useSize2 )
    {
      { int *member = (int *)&FX_ORIENTED(op)->mSize2Start; *member = size2Start; }
      { int *member = (int *)&FX_ORIENTED(op)->mSize2End; *member = size2End; }
      /* retail tests the size2 parm mask against 0x800 (FX_SIZE_WAVE's
       * value in the size field), so the wave branch never runs */
      if ( (flags & 0xC0000) == 0x800 )
        FX_ORIENTED(op)->mSize2Parm = size2Parm * 0.0031415902f;
      else if ( (flags & 0xC0000) != 0 )
        FX_ORIENTED(op)->mSize2Parm = (float)killTime * size2Parm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));
    }
    else
    {
      /* size2 follows size: copy the size parm-mode bits into the size2 field */
      flags &= 0xFFF0FFFF;
      flags |= ( flags & 0xF00 ) << 8;
      { int *member = (int *)&FX_ORIENTED(op)->mSize2Start; *member = sizeStart; }
      { int *member = (int *)&FX_ORIENTED(op)->mSize2End; *member = sizeEnd; }
    }
    { int *member = (int *)&FX_ORIENTED(op)->mFlags; *member = flags; }
    { int *member = (int *)&FX_ORIENTED(op)->mRefEnt.customShader; *member = shader; }
    { int *member = (int *)&FX_ORIENTED(op)->mRefEnt.rotation; *member = rotation; }
    { int *member = (int *)&FX_ORIENTED(op)->mRotationDelta; *member = rotationDelta; }
    { int *member = (int *)&FX_ORIENTED(op)->mElasticity; *member = elasticity; }
    if ( mins )
    {
      *(unsigned int *)&FX_ORIENTED(op)->mMin[0] = *mins;
      *(unsigned int *)&FX_ORIENTED(op)->mMin[1] = mins[1];
      *(unsigned int *)&FX_ORIENTED(op)->mMin[2] = mins[2];
    }
    else
    {
      *(unsigned int *)&FX_ORIENTED(op)->mMin[2] = 0;
      *(unsigned int *)&FX_ORIENTED(op)->mMin[1] = 0;
      *(unsigned int *)&FX_ORIENTED(op)->mMin[0] = 0;
    }
    if ( maxs )
    {
      *(unsigned int *)&FX_ORIENTED(op)->mMax[0] = *maxs;
      *(unsigned int *)&FX_ORIENTED(op)->mMax[1] = maxs[1];
      *(unsigned int *)&FX_ORIENTED(op)->mMax[2] = maxs[2];
    }
    else
    {
      *(unsigned int *)&FX_ORIENTED(op)->mMax[2] = 0;
      *(unsigned int *)&FX_ORIENTED(op)->mMax[1] = 0;
      *(unsigned int *)&FX_ORIENTED(op)->mMax[0] = 0;
    }
    { int *member = (int *)&FX_ORIENTED(op)->mDeathFxID; *member = deathFxId; }
    { int *member = (int *)&FX_ORIENTED(op)->mImpactFxID; *member = impactFxId; }
    FX_AddPrimitive(&record, killTime);
  }
  return op;
}

/* ---- cand_CFlash_Create  0x004A0D00 ----  [CONFIRMED] */
int __cdecl cand_CFlash_Create(
        int a1,
        int a2,
        int a3,
        unsigned int *a4,
        unsigned int *a5,
        float a6,
        float a7,
        float a8,
        unsigned int *a9,
        unsigned int *a10,
        float a11,
        unsigned int *a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17)
{
  unsigned int *color;      
  int    *p;
  int     flash;
  int     i;
  unsigned int *colorDst;   
  unsigned int *src;        
  unsigned int *dst;        
  int     record;     

  color = a4;
  if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x0C)) < 1 || !a2 )
    return 0;

  p = FxPool_AllocFlash(&fxPool_Decal, 436);
  if ( p )
  {
    p[54] = 0;                       
    p[15] = 4;                       
    *p = (int)&vtbl_CDecal;           
    flash = (int)p;
  }
  else
  {
    flash = 0;
  }
  record = flash;
  if ( flash )
  {

  
    for ( i = 0; i < a3; i++ )
    {
      VectorCopy( ( (float (*)[3])a2 )[i], FX_DECAL(flash)->mOrg[i] );
      float *stDst = FX_DECAL(flash)->mST[i];
      stDst[0] = ( (float (*)[2])a1 )[i][0];
      stDst[1] = ( (float (*)[2])a1 )[i][1];
    }

    if ( color )
    {
      *(unsigned int *)&FX_DECAL(flash)->mVel[0] = *color;
      *(unsigned int *)&FX_DECAL(flash)->mVel[1] = color[1];
      *(unsigned int *)&FX_DECAL(flash)->mVel[2] = color[2];
    }
    else
    {
      *(unsigned int *)&FX_DECAL(flash)->mVel[2] = 0;
      *(unsigned int *)&FX_DECAL(flash)->mVel[1] = 0;
      *(unsigned int *)&FX_DECAL(flash)->mVel[0] = 0;
    }
    if ( a5 )
    {
      *(unsigned int *)&FX_DECAL(flash)->mAccel[0] = *a5;
      *(unsigned int *)&FX_DECAL(flash)->mAccel[1] = a5[1];
      *(unsigned int *)&FX_DECAL(flash)->mAccel[2] = a5[2];
    }
    else
    {
      *(unsigned int *)&FX_DECAL(flash)->mAccel[2] = 0;
      *(unsigned int *)&FX_DECAL(flash)->mAccel[1] = 0;
      *(unsigned int *)&FX_DECAL(flash)->mAccel[0] = 0;
    }
    if ( a9 )
    {
      *(unsigned int *)&FX_DECAL(flash)->mRGBStart[0] = *a9;
      *(unsigned int *)&FX_DECAL(flash)->mRGBStart[1] = a9[1];
      *(unsigned int *)&FX_DECAL(flash)->mRGBStart[2] = a9[2];
    }
    else
    {
      *(unsigned int *)&FX_DECAL(flash)->mRGBStart[2] = 0;
      *(unsigned int *)&FX_DECAL(flash)->mRGBStart[1] = 0;
      *(unsigned int *)&FX_DECAL(flash)->mRGBStart[0] = 0;
    }
    if ( a10 )
    {
      *(unsigned int *)&FX_DECAL(flash)->mRGBEnd[0] = *a10;
      *(unsigned int *)&FX_DECAL(flash)->mRGBEnd[1] = a10[1];
      *(unsigned int *)&FX_DECAL(flash)->mRGBEnd[2] = a10[2];
    }
    else
    {
      *(unsigned int *)&FX_DECAL(flash)->mRGBEnd[2] = 0;
      *(unsigned int *)&FX_DECAL(flash)->mRGBEnd[1] = 0;
      *(unsigned int *)&FX_DECAL(flash)->mRGBEnd[0] = 0;
    }

  

    if ( (a17 & 0xC0) == 0x80 )
      FX_DECAL(flash)->mRGBParm = a11 * 0.0031415902f;
    else if ( (a17 & 0xC0) != 0 )
      FX_DECAL(flash)->mRGBParm = (float)a15 * a11 * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { float *member = &FX_DECAL(flash)->mAlphaStart; *member = a6; }
    { float *member = &FX_DECAL(flash)->mAlphaEnd; *member = a7; }
    if ( (a17 & 0xC) == 8 )
      FX_DECAL(flash)->mAlphaParm = a8 * 0.0031415902f;
    else if ( (a17 & 0xC) != 0 )
      FX_DECAL(flash)->mAlphaParm = (float)a15 * a8 * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    *(unsigned int *)&FX_DECAL(flash)->mFlags = a17;
    *(unsigned int *)&FX_DECAL(flash)->mRefEnt.customShader = a16;
    if ( a12 )
    {
      *(unsigned int *)&FX_DECAL(flash)->mRotDelta[0] = *a12;
      *(unsigned int *)&FX_DECAL(flash)->mRotDelta[1] = a12[1];
      *(unsigned int *)&FX_DECAL(flash)->mRotDelta[2] = a12[2];
    }
    else
    {
      *(unsigned int *)&FX_DECAL(flash)->mRotDelta[2] = 0;
      *(unsigned int *)&FX_DECAL(flash)->mRotDelta[1] = 0;
      *(unsigned int *)&FX_DECAL(flash)->mRotDelta[0] = 0;
    }
    *(unsigned int *)&FX_DECAL(flash)->mElasticity = a13;
    *(unsigned int *)&FX_DECAL(flash)->mTimeStamp = a14 + (*(int *)(((unsigned char *)&theFxHelper) + 0x04));
    *(unsigned int *)&FX_DECAL(flash)->mCount = a3;
    CFlash__DrawHelper_m( flash );
    FX_AddPrimitive(&record, a15);
  }
  return flash;
}

/* ---- FX_AddFlash  0x004A0FA0 ----  VERIFIED */
int __cdecl FX_AddFlash(unsigned int *org, unsigned int *rgbStart, unsigned int *rgbEnd, float rgbParm, int killTime, int shader, int flags)
{
  int *p;
  int  flash;
  int  record;   

  if ( (*(int *)(((unsigned char *)&theFxHelper) + 0x0C)) < 1 )
    return 0;
  p = FxPool_AllocLight(&fxPool_Light, 260);
  if ( p )
  {
    p[54] = 0;                       
    *p = (int)&vtbl_CFlash;           
    flash = (int)p;
  }
  else
  {
    flash = 0;
  }
  record = flash;
  if ( flash )
  {
    if ( org )
    {
      *(unsigned int *)&FX_LIGHT(flash)->mOrigin1[0] = *org;
      *(unsigned int *)&FX_LIGHT(flash)->mOrigin1[1] = org[1];
      *(unsigned int *)&FX_LIGHT(flash)->mOrigin1[2] = org[2];
    }
    else
    {
      *(unsigned int *)&FX_LIGHT(flash)->mOrigin1[2] = 0;
      *(unsigned int *)&FX_LIGHT(flash)->mOrigin1[1] = 0;
      *(unsigned int *)&FX_LIGHT(flash)->mOrigin1[0] = 0;
    }
    if ( rgbStart )
    {
      *(unsigned int *)&FX_LIGHT(flash)->mRGBStart[0] = *rgbStart;
      *(unsigned int *)&FX_LIGHT(flash)->mRGBStart[1] = rgbStart[1];
      *(unsigned int *)&FX_LIGHT(flash)->mRGBStart[2] = rgbStart[2];
    }
    else
    {
      *(unsigned int *)&FX_LIGHT(flash)->mRGBStart[2] = 0;
      *(unsigned int *)&FX_LIGHT(flash)->mRGBStart[1] = 0;
      *(unsigned int *)&FX_LIGHT(flash)->mRGBStart[0] = 0;
    }
    if ( rgbEnd )
    {
      *(unsigned int *)&FX_LIGHT(flash)->mRGBEnd[0] = *rgbEnd;
      *(unsigned int *)&FX_LIGHT(flash)->mRGBEnd[1] = rgbEnd[1];
      *(unsigned int *)&FX_LIGHT(flash)->mRGBEnd[2] = rgbEnd[2];
    }
    else
    {
      *(unsigned int *)&FX_LIGHT(flash)->mRGBEnd[2] = 0;
      *(unsigned int *)&FX_LIGHT(flash)->mRGBEnd[1] = 0;
      *(unsigned int *)&FX_LIGHT(flash)->mRGBEnd[0] = 0;
    }

  

    if ( (flags & 0xC0) == 0x80 )
      FX_LIGHT(flash)->mRGBParm = rgbParm * 0.0031415902f;
    else if ( (flags & 0xC0) != 0 )
      FX_LIGHT(flash)->mRGBParm = (float)killTime * rgbParm * 0.0099999998f + (float)(*(int *)(((unsigned char *)&theFxHelper) + 0x04));

    { int *member = (int *)&FX_LIGHT(flash)->mRefEnt.customShader; *member = shader; }
    { int *member = (int *)&FX_LIGHT(flash)->mFlags; *member = flags; }
    cand_CFxPrimType13__helper((float *)flash);
    FX_AddPrimitive(&record, killTime);
  }
  return flash;
}

#ifdef __cplusplus
}   /* extern "C" */
#endif
