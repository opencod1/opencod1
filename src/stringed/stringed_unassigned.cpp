/*
 * stringed/stringed_unassigned.cpp
 *
 * Original translation unit:
 *   /Volumes/BigCheese/ Source/AspyrP4/CoD/Source/stringed/stringed_unassigned.cpp
 *
 * Retail range 0x004A99B0-0x004B08C0, 284 functions.
 *
 * @fidelity: likely
 * @fidelity-default: unreviewed
 */

#ifdef __cplusplus
/* retail built this unit as C++ with exceptions (/TP /GX); every name keeps C linkage */
extern "C" {
#endif

/* Native allocator value objects are copied on the stack. */
typedef struct { unsigned char value; } FxStlAllocatorTag;

typedef struct { void *allocator; } SeMapAllocatorReference;

typedef struct { char *where; } SeInsertWhere;
typedef struct { unsigned int count; } SeInsertCount;
static __inline SeInsertWhere SeInsertWhereArgument(char * where){SeInsertWhere value;value.where=where;return value;}
static __inline SeInsertCount SeInsertCountArgument(unsigned int count){SeInsertCount value;value.count=count;return value;}

typedef struct { struct seStlTreeNode_s *pointer; } SeDistanceEnd;

typedef struct { struct seStlStr_s *dest; } SeStringPlacementDestination;
typedef struct { struct seStlStr_s *source; } SeStringPlacementSource;
typedef struct { int allocator; } SeStringPlacementAllocator;
static __inline SeStringPlacementDestination SeStringDestinationArgument(struct seStlStr_s *dest){SeStringPlacementDestination value;value.dest=dest;return value;}
static __inline SeStringPlacementSource SeStringSourceArgument(struct seStlStr_s *source){SeStringPlacementSource value;value.source=source;return value;}
#include "../qcommon/crt_cpp_runtime.h"
#include "../qcommon/qcommon.h"
/* ---- module-owned globals ---- */
char se_szTokenBuf[64];
unsigned char MD5_PADDING[64] = { 0x80 };   /* 0x00571AF0  RFC 1321 padding: 0x80 then 63 zero bytes */
int seStrFileCount;   /* 0x00CA26C4  .str files found by SE_EnumerateStrFiles_m */
int TheStringPackage[5493];   /* 0x01407450  CStringEdPackage storage, built by TheStringPackage_static_init */


extern char **FS_ListFilteredFiles( const char *path, const char *extension, char *filter, int *numfiles );
/* The existing package receiver is one actual four-byte stack value. */
typedef struct { int package; } SePackageWord;
static __inline SePackageWord SePackageWordArgument(int package) { SePackageWord word; word.package=package; return word; }
/* CStringEdPackage::Clear keeps its receiver on the stack (retail __stdcall(this, bKeepFileInfo), retn 8). */
typedef struct { void *package; } SePackageRef;
static __inline SePackageRef SePackageRefArgument(void *package) { SePackageRef ref; ref.package=package; return ref; }
extern int j__atol( const char *string );
extern int strtok_m();
extern int std_logicError__ctor_m();
extern int __stdcall stl_fxEffectIdMap_index_m( int tree, void *key );            /* map<string,int>::operator[] */
extern int __cdecl   stl_fxEffectIdMap_find_m( int *result, int tree, int key );  /* map<string,int>::find */
/* std::string (fx_unassigned.cpp): copy constructor and assign(right, roff, count). */
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
};
#define stl_fxString_erase_m( self, off, count ) ( ( (struct FxString *)(self) )->Erase( (off), (count) ) )
/* _Myptr(): the small-string buffer while capacity < 16, else the heap pointer */
#define SE_FXPTR( s ) ( 16 <= (s)->capacity ? (s)->bx.ptr : (char *)&(s)->bx )
#define stl_fxString_grow_m( self, n, trim ) ( ( (struct FxString *)(self) )->Grow( (n), (trim) ) )
#define stl_fxString_copy_m( self, n, oldlen ) ( ( (struct FxString *)(self) )->Copy( (n), (oldlen) ) )
#define stl_fxString_assignSubstr_m( self, src, off, count ) \
  ( ( (struct FxString *)(self) )->Assign( (const void *)(src), (off), (count) ) )
typedef struct {void **pointer;} FxMapRootValue;
static __inline FxMapRootValue FxMapRootArgument(void **node){FxMapRootValue arg;arg.pointer=node;return arg;}
extern void __fastcall stl_fxEffectIdMap_eraseSubtree_m(void *receiver,FxMapRootValue root);           /* map<string,int>::_Erase */
typedef struct { const char *pointer; } FxConstCharPointerArgument;
typedef struct { unsigned int count; } FxSizeArgument;
static __inline FxConstCharPointerArgument FxConstCharArgument(const char *pointer) { FxConstCharPointerArgument arg; arg.pointer=pointer; return arg; }
static __inline FxSizeArgument FxCountArgument(unsigned int count) { FxSizeArgument arg; arg.count=count; return arg; }
extern int __fastcall stl_fxString_assignPtrCount_m(void *self, FxConstCharPointerArgument pointerArg, FxSizeArgument countArg);
typedef struct {void *pointer;} FxMapIteratorValue;
static __inline FxMapIteratorValue FxMapIteratorArgument(void *p){FxMapIteratorValue a;a.pointer=p;return a;}
extern int **__fastcall stl_fxEffectIdMap_eraseRange_m(int tree,FxMapIteratorValue resultArg,FxMapIteratorValue firstArg,FxMapIteratorValue lastArg);  /* map<string,int>::erase */
extern struct seStlTreeNode_s *__stdcall stl_fxEffectIdMap_buynodeHead_m( int tree );                   /* map<string,int>::_Buynode */
extern int __stdcall stl_fxString_compare_m( const void *self, unsigned int n0, unsigned int off,
                                 const char *ptr, unsigned int count );  /* string::compare */

/* Compiler-generated atexit destructors for the function-local static
 * std::strings of SE_UnescapeNewlines_m / SE_UnquoteAndTrim_m. */
static void __cdecl SE_UnescapeNewlines_static_fini_m( void );
static void __cdecl SE_UnquoteAndTrim_static_fini_m( void );

extern int __stdcall Clear__16CStringEdPackageFi( SePackageRef packageRef, int bKeepFileInfo );

char *__stdcall SE_UnescapeNewlines_m( const char *text, SePackageWord packageWord );
char *__stdcall SE_UnquoteAndTrim_m( const char *text, SePackageWord packageWord );
int   __stdcall SE_FindConfigValue_m( char *name, int package );
/* Retail flagName@<ecx>, then (package, reference) on the stack, retn 8. */
void  __fastcall SE_ParseVersion_m( char *flagName, SePackageWord packageWord, FxConstCharPointerArgument referenceWord );

/* Retail __usercall: result@<ebx>, tree@<edi>, key@<esi> (a std::string). */
void  __stdcall stl_vector_push_back_m( struct seStlVec_s *vector, struct seStlStr_s *value );

/* Retail __userpurge: package@<ebx>, line on the stack, retn 4. */
char *__stdcall SE_ParseLine_m( int package, char *line );
int   __stdcall SE_ParseConfig_m( int package, char *reference );
/* Retail __thiscall: reference@<ecx>, then (package, text, isEnglish), retn 0Ch. */
void  __stdcall SE_ParseLanguageString_m( const char *reference, int package, char *text, int isEnglish );
/* Retail: path@<ecx>, then (returnReference, optional) caller-cleaned. */
char *__cdecl   SE_LoadLanguageFile_m( const char *path, int returnReference, int optional );
/* Retail __usercall: list@<esi> (a std::string). */
char *__cdecl   SE_NextSemicolonToken_m( struct seStlStr_s *list );
/* Retail __usercall: key@<edx>; the leading (ecx) slot is dead, see SE_LookupStringForLanguage_m. */
int __cdecl SE_LookupString_m(const char *key);
/* Retail __usercall: key@<edx>, wantReference on the stack. */
char *SE_GetString( const char *key, int wantReference );
typedef struct { struct seStlStr_s *receiver; } SeStringReceiver;
static __inline SeStringReceiver SeStringReceiverArgument(struct seStlStr_s *r) { SeStringReceiver a;a.receiver=r;return a;}
int __fastcall stl_string_assign_cstr_m(char *src, SeStringReceiver receiver);
/* Retail __thiscall: ptr@<ecx>, then the std::string on the stack, retn 4. */
struct seStlStr_s *__stdcall stl_string_append_cstr_m( struct seStlStr_s *self, const char *ptr );
int   __stdcall stl_map_index_m( struct seStlTree_s *tree, struct seStlStr_s *key );
/* Retail __usercall: count@<eax>, self@<edx>, ptr@<ecx>  (std::string::append(ptr, count)). */
struct seStlStr_s *__cdecl stl_string_append_m( struct seStlStr_s *self, const char *ptr, unsigned int count );
/* std::string::append(right, roff, count).
 * Retail __userpurge: count@<eax>, right@<ecx>, self@<ebx>, then roff on the stack, retn 4. */
struct seStlStr_s *__stdcall stl_string_replace_m( struct seStlStr_s *self, struct seStlStr_s *right, unsigned int roff, unsigned int count );
/* Retail __usercall: tree@<eax>, key@<ecx>; returns the first node whose key is not less than key. */
struct seStlTreeNode_s *__cdecl   stl_map_lower_bound_m( struct seStlTree_s *tree, struct seStlStr_s *key );

/* std::vector<std::string> growth helpers. */
/* Retail __userpurge: vec@<edi>, then (result, where, val) on the stack, retn 0Ch. */
typedef struct { void **result; } SeVectorResult;
static __inline SeVectorResult SeVectorResultArgument(void **result) { SeVectorResult a;a.result=result;return a;}
typedef struct { void ****where; } SeVectorPosition;
static __inline SeVectorPosition SeVectorPositionArgument(void ****where) { SeVectorPosition a;a.where=where;return a;}
typedef struct { struct seStlStr_s *val; } SeVectorValue;
static __inline SeVectorValue SeVectorValueArgument(struct seStlStr_s *val) { SeVectorValue a;a.val=val;return a;}
/* Retail __usercall: count@<eax>, vec@<esi>; returns _Buy's bool in al. */
char  __cdecl   stl_vector_buy_m( struct seStlVec_s *vec, unsigned int count );
/* Retail pushes the vector but never reads it; throws length_error. */
void  __stdcall stl_vector_xlen_m( struct seStlVec_s *vec );
/* Retail __usercall: result@<esi>, then (first, last, dest); std::copy_backward. */
/* Retail __usercall: val@<ebx>, then (first, last); std::fill. */
/* Retail __usercall: first@<eax>, last@<edi>. */
void  __cdecl   stl_vector_destroy_range_impl_m( struct seStlStr_s *first, struct seStlStr_s *last, void *alloc, FxStlAllocatorTag cat );
/* std::uninitialized_fill_n.  Retail __usercall: count@<ecx>, then (dest, val)
 * and the allocator on the stack; the allocator is only read by the unwind path. */
/* std::copy_backward, result returned through *result.  Retail __cdecl; the
 * caller pushes a fifth (iterator-tag) word that is never read. */
/* allocator<std::string>::construct(dest, src).  Retail __cdecl(dest, src). */
__declspec(noinline) void __cdecl stl_string_construct_copy_m(SeStringPlacementDestination position, SeStringPlacementSource value);

/* A tree iterator passed by value: a one-pointer struct, so it stays on the stack. */
typedef struct seStlIter_s
{
  struct seStlTreeNode_s *ptr;
} seStlIter_t;

/* std::map<std::string, CStringEdString> (104-byte nodes) helpers. */
struct seStlPairIterBool_s *__stdcall stl_map_insert_m( struct seStlTree_s *tree, struct seStlPairIterBool_s *result, struct seStrMapPair_s *pair );
/* ~pair (retail __usercall: pair@<esi>) is SeStrMapPair::~SeStrMapPair, below. */
/* Retail __usercall: node@<eax>. */
void  __cdecl   stl_map_node_destroy_m( struct seStrMapNode_s *node );
/* Retail __thiscall: tree@<ecx> (only forwarded to the recursion), node on the stack, retn 4. */
void  __fastcall stl_tree_erase_all_m( struct seStlTree_s *tree, seStlIter_t node );
/* Retail __userpurge: whereNode@<ecx>, tree@<edi>, then (result, addLeft, val), retn 0Ch. */
/* Retail __usercall: iter@<edx>. */
inline void __cdecl stl_map_iter_prev_m( struct seStlTreeNode_s **iter );
inline void __cdecl stl_map_iter_next104_m( struct seStlTreeNode_s **iter );
/* Retail __userpurge: tree@<esi>, then (result, first, last), retn 0Ch. */
struct seStlTreeNode_s **__stdcall stl_map_erase_range_m( struct seStlTree_s *tree, struct seStlTreeNode_s **result, seStlIter_t first, seStlIter_t last );
/* Retail __stdcall(tree, result, where), retn 0Ch; returns the successor through result. */
struct seStlTreeNode_s **__stdcall stl_map_erase_node_m( struct seStlTree_s *tree, struct seStlTreeNode_s **result, struct seStlTreeNode_s *where );
/* Retail __stdcall(tree), retn 4: buys the head (sentinel) node. */
__declspec(noinline) struct seStlTreeNode_s *__stdcall stl_map_buynode_str_m( struct seStlTree_s *tree );
struct seStlTreeNode_s *__stdcall stl_map_buynode_init_m( struct seStlTree_s *tree, struct seStlTreeNode_s *left, struct seStlTreeNode_s *parent, struct seStlTreeNode_s *right, struct seStrMapPair_s *val, char color );
/* Retail __thiscall: node@<ecx>, tree on the stack, retn 4. */
struct seStlTreeNode_s *__stdcall stl_map_lrotate_m( struct seStlTreeNode_s *node, struct seStlTree_s *tree );
struct seStlTreeNode_s *__stdcall stl_map_rrotate_m( struct seStlTreeNode_s *node, struct seStlTree_s *tree );
/* Retail __usercall: node@<eax>; leftmost / rightmost node of the subtree. */
struct seStlTreeNode_s *__cdecl stl_map_subtree_min_m( struct seStlTreeNode_s *node );
struct seStlTreeNode_s *__cdecl stl_map_subtree_max_m( struct seStlTreeNode_s *node );

/* std::set<std::string> (44-byte nodes) helpers. */
/* Retail __userpurge: whereNode@<ecx>, tree@<edi>, then (result, addLeft, key), retn 0Ch. */
struct seStlTreeNode_s *__stdcall stl_map44_buynode_init_m( struct seStlTree_s *tree, struct seStlTreeNode_s *left, struct seStlTreeNode_s *parent, struct seStlTreeNode_s *right, struct seStlStr_s *key, char color );
/* Retail __thiscall: node@<ecx>, tree on the stack, retn 4. */
struct seStlTreeNode_s *__stdcall stl_map44_lrotate_m( struct seStlTreeNode_s *node, struct seStlTree_s *tree );
struct seStlTreeNode_s *__stdcall stl_map44_rrotate_m( struct seStlTreeNode_s *node, struct seStlTree_s *tree );
/* Retail __usercall: iter@<edx>. */
inline void __cdecl stl_map44_iter_prev_m( struct seStlTreeNode_s **iter );
inline void __cdecl stl_map44_iter_next_m( struct seStlTreeNode_s **iter );
/* Retail __userpurge: tree@<esi>, then (result, first, last), retn 0Ch. */
struct seStlTreeNode_s **__stdcall stl_map44_erase_range_m( struct seStlTree_s *tree, struct seStlTreeNode_s **result, seStlIter_t first, seStlIter_t last );
/* Retail __stdcall(tree, result, where), retn 0Ch; returns the successor through result. */
struct seStlTreeNode_s **__stdcall stl_map44_erase_node_m( struct seStlTree_s *tree, struct seStlTreeNode_s **result, struct seStlTreeNode_s *where );
/* Retail __thiscall: the tree (ecx) is only handed on to the recursion; node on the stack, retn 4. */
void  __fastcall stl_map44_erase_all_m( struct seStlTree_s *tree, seStlIter_t node );
/* Retail __usercall: tree@<eax>. */
void  __cdecl   stl_map44_clear_m( struct seStlTree_s *tree );
/* Retail __stdcall(tree), retn 4: buys the head (sentinel) node. */
__declspec(noinline) struct seStlTreeNode_s *__stdcall stl_map44_buynode_m( struct seStlTree_s *tree );
/* Retail __usercall: tree@<eax>, key@<ecx>; the first node whose key is not less than key. */
struct seStlTreeNode_s *__cdecl   stl_map44_lower_bound_m( struct seStlTree_s *tree, struct seStlStr_s *key );
/* Retail __usercall: tree@<eax>, key on the stack, retn 4; the first node whose key is greater than key. */
struct seStlTreeNode_s *__stdcall stl_map44_upper_bound_m( struct seStlTree_s *tree, struct seStlStr_s *key );
/* Retail __usercall: node@<eax>; leftmost / rightmost node of the subtree. */
struct seStlTreeNode_s *__cdecl stl_map44_subtree_min_m( struct seStlTreeNode_s *node );
struct seStlTreeNode_s *__cdecl stl_map44_subtree_max_m( struct seStlTreeNode_s *node );
/* Retail __usercall: node@<esi>; destroys the node's key string. */
int   __cdecl   stl_map44_node_destroy_m( struct seStrSetNode_s *node );
/* std::set<std::string>::count(key).  Retail __usercall: key@<eax>, tree@<ebx>. */
int   __cdecl   stl_map44_count_m( struct seStlTree_s *tree, struct seStlStr_s *key );

/* std::allocator<std::string>::allocate: retail __userpurge, count@<eax> plus two unread stack words, retn 8. */
void *__stdcall stl_alloc_str_allocate_m( unsigned int count, int unused1, int unused2 );
/* The tree-node allocators (44- and 104-byte nodes), same shape. */
void *__stdcall stl_alloc_node44_allocate_m( unsigned int count, int unused1, int unused2 );
void *__stdcall stl_alloc_node104_allocate_m( unsigned int count, int unused1, int unused2 );
/* The second copies: retail __usercall count@<eax> plus one caller-cleaned stack
 * word that is overwritten, never read (it becomes operator new's argument). */
void *__cdecl   stl_alloc_str_allocate2_m( unsigned int count, int unused );
void *__cdecl   stl_alloc_node44_allocate2_m( unsigned int count, int unused );
void *__cdecl   stl_alloc_node104_allocate2_m( unsigned int count, int unused );

/* Retail __thiscall: ptr@<ecx>, then the std::string on the stack, retn 4. */
struct seStlStr_s *__stdcall stl_string_append_cstr2_m( struct seStlStr_s *self, const char *ptr );
/* std::string::append(count, ch).  Retail __userpurge: count@<eax>, self@<esi>, ch on the stack, retn 4. */
struct seStlStr_s *__stdcall stl_string_append_fill_m( struct seStlStr_s *self, unsigned int count, char ch );
/* std::string::append(1, ch).  Retail __usercall: ch@<al>, self@<esi>. */
struct seStlStr_s *__cdecl stl_string_append_char_m( struct seStlStr_s *self, char ch );
/* std::string::find(ptr, off, count).  Retail __userpurge: off@<eax>, then (self, ptr, count), retn 0Ch. */
unsigned int __stdcall stl_string_find_m( unsigned int startPos, struct seStlStr_s *self, char *needle, unsigned int needleLen );

/* .str file enumeration into a ';'-separated std::string (out). */
void  __cdecl   SE_EnumerateStrFiles_m( const char *extension, const char *path, struct seStlStr_s *out );
/* Retail __usercall: out@<esi>, path on the stack. */
int   __cdecl   SE_CountStrFiles_m( struct seStlStr_s *out, const char *path );

/*
 * Retail Dinkumware std::string (size 0x1C).  The 16-byte union is the
 * small-string buffer while capacity < 16, otherwise it holds a heap pointer.
 * The leading word is the allocator/proxy slot and is untouched by these
 * helpers.
 */
typedef struct seStlStr_s
{
  void *unused0;                 /* +0x00  allocator/proxy slot */
  union
  {
    int   bufw[4];               /* +0x04  inline 16-char buffer (capacity <  16), see seStlStr_buf */
    char *ptr;                   /* +0x04  heap pointer   (capacity >= 16) */
  } bx;
  unsigned int size;             /* +0x14  string length */
  unsigned int capacity;         /* +0x18  reserved capacity */
} seStlStr_t;

/* The inline buffer is declared as ints: a char array in a C struct local
 * makes VC7 /GS add a cookie, which most of retail's C++ string locals do not
 * get. */
#define seStlStr_buf(s)  ((char *)(s)->bx.bufw)
/* _Tidy() in Dinkumware form: _Myres = _BUF_SIZE - 1; _Eos(0), i.e.
 * _Traits::assign(_Myptr()[_Mysize = 0], _Elem()).  The _Myptr() test on the
 * just-stored capacity folds away, but it sets VC7's schedule of the stores. */
#define seStlStr_tidyInit(s) { (s)->capacity = 15; ( 16 <= (s)->capacity ? (s)->bx.ptr : (char *)&(s)->bx )[(s)->size = 0] = 0; }

/* seStlStr_t with the inline buffer as chars, for the string locals of the
 * functions whose retail frame does carry a /GS cookie. */
typedef struct seStlStrGS_s
{
  void *unused0;
  union
  {
    char  buf[16];
    char *ptr;
  } bx;
  unsigned int size;
  unsigned int capacity;
} seStlStrGS_t;

#ifdef __cplusplus
/* vector<std::string>::iterator (Dinkumware _Ptrit): a class, so a by-value
 * argument is copy-constructed in its stack slot (push ecx; mov eax,esp; mov [eax],x). */
struct SeStrIter
{
  seStlStr_t *ptr;
  SeStrIter( seStlStr_t *p );
  SeStrIter( const SeStrIter &other );
  SeStrIter operator+( int offset ) const;           /* _Ptrit::operator+ */
  SeStrIter operator-( int offset ) const;           /* _Ptrit::operator- */
  int operator-( const SeStrIter &right ) const;     /* _Ptrit::operator-(iterator): difference */
};

/* <new>: the global placement operator new (inline) and its placement
 * operator delete (fx_unassigned.cpp, retail 0x004924F0), which the unwind
 * action of a placement new-expression whose constructor throws calls. */
extern "C++"
{
#if !defined(_MSC_VER) || _MSC_VER < 1900
inline void *__cdecl operator new( size_t, void *where ) throw() { return where; }
#endif
void __cdecl operator delete( void *, void * ) throw();
}

/* allocator<std::string>::construct(dest, src): new (dest) std::string(*src). */
struct SeStrCopy
{
  seStlStr_t str;
  SeStrCopy( seStlStr_t *src ) { Construct( src ); }
  void Construct( seStlStr_t *src )
  {
    str.capacity = 15;   /* _Tidy(): _Myres = 15; _Eos(0) */
    ( 16 <= str.capacity ? str.bx.ptr : (char *)str.bx.bufw )[str.size = 0] = 0;
    stl_fxString_assignSubstr_m(&str, src, 0, 0xFFFFFFFF);   /* assign(src, 0, npos) */
  }
};
/* std::_Uninit_copy(first, last, dest, al, _Nonscalar_ptr_iterator_tag). */
seStlStr_t *__cdecl stl_vector_ucopy_m( SeStrIter first, SeStrIter last, seStlStr_t *dest, void *alloc, FxStlAllocatorTag cat );
/* vector<std::string>::_Ucopy(first, last, dest).
 * Retail really is __fastcall: vec@<ecx>, dest@<edx>, then (first, last), retn 8. */
seStlStr_t *__fastcall stl_vector_ucopy_wrap2_m( void *vec, SeStrIter first, SeStrIter last, seStlStr_t *dest );
/* std::copy_backward(first, last, dest) and its _Copy_backward_opt worker; the
 * iterator result comes back through the hidden return pointer. */
SeStrIter __cdecl stl_vector_ucopy_backward_wrap_m( SeStrIter first, SeStrIter last, SeStrIter dest );
SeStrIter __cdecl stl_vector_ucopy_backward_m( SeStrIter first, SeStrIter last, SeStrIter dest, FxStlAllocatorTag cat );
#endif
/* std::_Uninit_fill_n(first, count, val, al, _Nonscalar_ptr_iterator_tag).
 * Retail: count@<ecx>, then (first, val, al, tag) on the stack. */
void __cdecl stl_vector_ufill_n_impl_m( seStlStr_t *first, unsigned int count, seStlStr_t *val, void *alloc, FxStlAllocatorTag cat );
#ifdef __cplusplus
/* vector<std::string>::insert(where, val), returning the iterator through the hidden
 * result pointer.  Retail: vec@<edi>, then (result, where, val), retn 0Ch. */
SeStrIter __stdcall stl_vector_insert_at_m( struct seStlVec_s *vec, SeStrIter where, SeVectorValue valueArgument );
/* std::vector<std::string> (the seStlVec_t layout) with its _Insert_n(where, count, val)
 * member.  Retail is a __stdcall member: (this, where, count, val), retn 10h. */
struct SeStrVecM
{
  void *proxy;
  char *first;
  char *last;
  char *end;
  void __stdcall InsertN( SeStrIter position, unsigned int count, const struct seStlStr_s &element );
  void Destroy( seStlStr_t *first, seStlStr_t *last );   /* _Destroy(first, last) */
};
/* std::fill(first, last, val) over constructed strings.  Retail: val@<ebx>, then (first, last). */
void __cdecl stl_vector_ufill_range_m( SeStrIter first, SeStrIter last, seStlStr_t *val );

/* map<std::string, CStringEdString>::iterator: a class, returned through a hidden pointer. */
struct SeMapIter
{
  struct seStlTreeNode_s *node;
  SeMapIter( struct seStlTreeNode_s *n ) : node( n ) {}
  SeMapIter( const SeMapIter &other ) : node( other.node ) {}
};
/* map<std::string, CStringEdString>::find.  Retail: result@<ebx>, tree@<edi>, key@<esi>. */
struct SeMap { __declspec(noinline) SeMapIter Find( seStlStr_t *key ); };   /* map::find, a member: key, result, this */
#define stl_map_find_m( tree, key ) ( ( (struct SeMap *)(tree) )->Find( (key) ) )
/* pair<iterator, bool>: a class, returned through the hidden result pointer. */
struct SePairIterBool
{
  struct seStlTreeNode_s *first;
  char                    second;
  SePairIterBool( struct seStlTreeNode_s *const &node, const char &inserted );
};
/* std::set<std::string>::insert(key).  Retail is a __stdcall member: (this, result, key), retn 0Ch. */
struct SeStrSet { SePairIterBool __stdcall Insert( seStlStr_t *key ); };
#define stl_map44_insert_m( tree, key ) ( ( (struct SeStrSet *)(tree) )->Insert( (key) ) )
/* _Tree::_Insert(addLeft, where, val), the iterator coming back through the hidden
 * result pointer.  Retail: whereNode@<ecx>, tree@<edi>, then (result, addLeft, val), retn 0Ch. */
SeMapIter __stdcall stl_map_insert_rebalance_m( struct seStlTree_s *tree, struct seStlTreeNode_s *whereNode, char addLeft, struct seStrMapPair_s *val );
SeMapIter __stdcall stl_map44_insert_rebalance_m( struct seStlTree_s *tree, struct seStlTreeNode_s *whereNode, char addLeft, struct seStlStr_s *key );

}   /* extern "C" */
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
#include "../EffectsCore/fx_types.h"   /* std::basic_string<char> (FxStdString) */

/* The shared std::string's members are defined once, in fx_unassigned.cpp
 * (LTCG inlines them here: the const char * constructor at every use; the
 * destructor's out-of-line COMDAT, retail 0x004974C0, is what every string
 * temporary's unwind action jumps to). */

/* A std::string temporary as the seStlStr_t the helpers take (taking the
 * address of a class rvalue is a VC7 extension). */
#define SE_TMPSTR( ptr )  ( (seStlStr_t *)&FxStdString( ptr ) )
#define SE_STR( s )       ( (seStlStr_t *)&(s) )

extern "C" {

/* Forward declarations for reconstructed helpers that are defined later in
 * this translation unit.  C++ has no implicit function declarations, so the
 * calls below need these prototypes; VC7's permissive mode masked the issue. */
unsigned int __stdcall stl_string_find_cstr_m( char *needle, seStlStr_t *str, unsigned int startPos );
seStlStr_t *__cdecl stl_vector_ufill_n_m( void *vec, seStlStr_t *ptr, unsigned int count, seStlStr_t *val );
int __stdcall stl_string_tidy_m( seStlStr_t *self, int unused );

/* The containers' _Xlen / erase(end()) paths throw std::length_error /
 * std::out_of_range (fx_types.h; members in fx_unassigned.cpp):
 * _THROW(length_error, "...") = throw length_error(string("...")). */
#endif

COD1_STATIC_ASSERT(offsetof(seStlStr_t, bx)       == 0x04, "seStlStr_t.bx");
COD1_STATIC_ASSERT(offsetof(seStlStr_t, size)     == 0x14, "seStlStr_t.size");
COD1_STATIC_ASSERT(offsetof(seStlStr_t, capacity) == 0x18, "seStlStr_t.capacity");
COD1_ASSERT_SIZE(seStlStr_t, 0x1C);

/* A localized-string entry: reference key, translated value and a flag word. */
typedef struct CStringEdString_s
{
  seStlStr_t key;                /* +0x00 */
  seStlStr_t value;              /* +0x1C */
  int        flags;              /* +0x38 */
} CStringEdString_t;

COD1_STATIC_ASSERT(offsetof(CStringEdString_t, value) == 0x1C, "CStringEdString_t.value");
COD1_STATIC_ASSERT(offsetof(CStringEdString_t, flags) == 0x38, "CStringEdString_t.flags");
COD1_ASSERT_SIZE(CStringEdString_t, 0x3C);

#ifdef __cplusplus
/*
 * class CStringEdString: CStringEdString_t as a C++ object (the same layout),
 * its two strings being member objects.  The copy constructor destroys the
 * copied key again when copying the value throws; the destructor runs ~value,
 * then ~key.
 */
struct CStringEdString
{
  FxStdString key;     /* +0x00 */
  FxStdString value;   /* +0x1C */
  int         flags;   /* +0x38 */
  CStringEdString();
  CStringEdString( const CStringEdString &other );
  ~CStringEdString();
};
#endif

/* Small-string-optimized c-string accessor. */
static char *seStlStr_cstr(seStlStr_t *s)
{
  return 0x10u <= s->capacity ? s->bx.ptr : seStlStr_buf(s);
}

/* ---- SE_Init__Fv  0x004A9CD0 ---- VERIFIED */
int SE_Init__Fv(void)
{
  return Clear__16CStringEdPackageFi(SePackageRefArgument(&TheStringPackage), 0);
}

/* ---- SE_ShutDown__Fv  0x004A9CE0 ---- VERIFIED */
int SE_ShutDown__Fv(void)
{
  return Clear__16CStringEdPackageFi(SePackageRefArgument(&TheStringPackage), 0);
}

/* ---- SE_NewLanguage__Fv  0x004A9CF0 ---- VERIFIED */
int SE_NewLanguage__Fv(void)
{
  return Clear__16CStringEdPackageFi(SePackageRefArgument(&TheStringPackage), 1);
}

/* ---- Korean_ValidKSC5601HangulCode  0x004AA360 ---- VERIFIED */
int __cdecl Korean_ValidKSC5601HangulCode(unsigned char hi, unsigned char lo)
{
  return hi >= 0xB0u && hi <= 0xC8u && lo > 0xA0u && lo < 0xFFu;
}

/* ---- Korean_ValidKSC5601HangulCodeWord  0x004AA380 ---- VERIFIED */
int __cdecl Korean_ValidKSC5601HangulCodeWord(unsigned int uiCode)
{
  return Korean_ValidKSC5601HangulCode((unsigned char)(uiCode >> 8), (unsigned char)(uiCode & 0xFF));
}

/* ---- Korean_CollapseKSC5601HangulCode  0x004AA3A0 ---- VERIFIED */
unsigned int __fastcall Korean_CollapseKSC5601HangulCode(int uiCode)   /* __fastcall: tr_font.c's prototype */
{
  if ( Korean_ValidKSC5601HangulCodeWord(uiCode) )
  {
    uiCode -= 0xB0A0;                              /* sneakily removes the hi-byte too */
    return (((unsigned int)uiCode >> 8) * 96) + (uiCode & 0xFF);
  }
  return 0;
}

/* The Taiwanese/Japanese predicates are C++ bool in retail (returned in al). */

/* ---- Taiwanese_ValidBig5Code  0x004AA3E0 ---- VERIFIED */
unsigned char __cdecl Taiwanese_ValidBig5Code(unsigned int uiCode)
{
  const unsigned char hi = (unsigned char)(uiCode >> 8);
  const unsigned char lo = (unsigned char)(uiCode & 0xFF);

  return (unsigned char)(((hi >= 0xA1 && hi <= 0xC6) || (hi >= 0xC9 && hi <= 0xF9))
                     && ((lo >= 0x40 && lo <= 0x7E) || (lo >= 0xA1 && lo <= 0xFE)));
}

/* ---- Taiwanese_IsTrailingPunctuation  0x004AA410 ---- VERIFIED */
unsigned char __cdecl Taiwanese_IsTrailingPunctuation(unsigned int code)
{
  return (unsigned char)(code >= 0xA140 && code < 0xA154);
}

/* ---- Taiwanese_CollapseBig5Code  0x004AA430 ---- VERIFIED */
int __fastcall Taiwanese_CollapseBig5Code(int uiCode)   /* __fastcall: tr_font.c's prototype */
{
  if ( Taiwanese_ValidBig5Code(uiCode) )
  {
    uiCode -= 0xA140;                              /* sneakily removes the hi-byte too */
    if ( (unsigned int)(uiCode & 0xFF) >= 0x60u )
      uiCode -= 0x20;                              /* skip the gap between the two lo-byte ranges */
    return (((unsigned int)uiCode >> 8) * 160) + (uiCode & 0xFF);
  }
  return 0;
}

/* ---- Japanese_ValidShiftJISCode  0x004AA490 ---- VERIFIED */
unsigned char __cdecl Japanese_ValidShiftJISCode(unsigned char hi, unsigned char lo)
{
  return (unsigned char)(((hi >= 0x81 && hi <= 0x9F) || (hi >= 0xE0 && hi <= 0xEF))
                     && ((lo >= 0x40 && lo <= 0x7E) || (lo >= 0x80 && lo <= 0xFC)));
}

/* ---- Japanese_ValidShiftJISCodeWord  0x004AA4C0 ---- VERIFIED */
unsigned char __cdecl Japanese_ValidShiftJISCodeWord(unsigned int uiCode)
{
  return Japanese_ValidShiftJISCode((unsigned char)(uiCode >> 8), (unsigned char)(uiCode & 0xFF));
}

/* ---- Japanese_IsTrailingPunctuation  0x004AA4F0 ---- VERIFIED */
unsigned char __cdecl Japanese_IsTrailingPunctuation(unsigned int uiCode)
{
  return (unsigned char)(uiCode >= 0x8140 && uiCode < 0x8152);
}

/* ---- Japanese_CollapseShiftJISCode  0x004AA510 ---- VERIFIED */
unsigned int __fastcall Japanese_CollapseShiftJISCode(int uiCode)   /* __fastcall: tr_font.c's prototype */
{
  if ( Japanese_ValidShiftJISCodeWord(uiCode) )
  {
    uiCode -= 0x8140;                              /* sneakily removes the hi-byte offset too */
    if ( (unsigned int)(uiCode & 0xFF) >= 0x40u )
      uiCode--;                                    /* the gap at lo 0x7F */
    if ( (unsigned int)(uiCode & 0xFF00) >= 0x5F00u )
      uiCode -= 0x4000;                            /* the gap at hi 0xA0..0xDF */
    return (((unsigned int)uiCode >> 8) * 188) + (uiCode & 0xFF);
  }
  return 0;
}

/* ---- SEH_ReadCharFromString  0x004AA580 ---- VERIFIED */
int __cdecl SEH_ReadCharFromString(unsigned char **pCursor, int *pIsPunct)
{
  unsigned char *s;
  int              c;

  s = *pCursor;

  if ( g_currentAsian )
  {
    switch ( cl_language->integer )
    {
      case 8:                                  /* Korean (KSC5601) */
        if ( Korean_ValidKSC5601HangulCode(s[0], s[1]) )
        {
          c = (s[0] * 256) + s[1];
          *pCursor = s + 2;
          if ( pIsPunct )
            *pIsPunct = 0;
          return c;
        }
        break;
      case 9:                                  /* Taiwanese (Big5) */
        if ( Taiwanese_ValidBig5Code((s[0] * 256) + s[1]) )
        {
          c = (s[0] * 256) + s[1];
          *pCursor = s + 2;
          if ( pIsPunct )
            *pIsPunct = Taiwanese_IsTrailingPunctuation(c);
          return c;
        }
        break;
      case 10:                                 /* Japanese (Shift-JIS) */
        if ( Japanese_ValidShiftJISCode(s[0], s[1]) )
        {
          c = (s[0] * 256) + s[1];
          *pCursor = s + 2;
          if ( pIsPunct )
            *pIsPunct = Japanese_IsTrailingPunctuation(c);
          return c;
        }
        break;
    }
  }

  /* Single byte: non-Asian text, or a multibyte sequence that did not decode. */
  c = s[0];
  *pCursor = s + 1;
  if ( pIsPunct )
    *pIsPunct = c == 33 || c == 63 || c == 44 || c == 46 || c == 59 || c == 58;
  return c;
}

/* ---- Language_IsAsian  0x004AA690 ---- VERIFIED */
int Language_IsAsian()
{
  return g_currentAsian;
}

/* ---- Language_UsesSpaceWordBreak_m  0x004AA6A0 ---- VERIFIED */
int Language_UsesSpaceWordBreak_m()
{
  int lang;

  lang = cl_language->integer;
  return lang < 9 || lang > 10;
}

/* ---- SEH_PrintStrlen  0x004AA6C0 ---- VERIFIED */
int __cdecl SEH_PrintStrlen(char *string)
{
  char *p;
  int   len;

  if ( !string )
    return 0;

  len = 0;
  p = string;
  while ( *p )
  {
    int code = SEH_ReadCharFromString( (unsigned char **)&p, NULL );
    if ( code == '^' && p && *p != '^' && *p >= '0' && *p <= '7' )
      ++p;
    else if ( code != '\n' && code != '\r' )
      ++len;
  }
  return len;
}

/* ---- stl_string_find_ch_m  0x004AA7F0 ---- MEDIUM */
void *__cdecl stl_string_find_ch_m(size_t count, char *pChar, void *buf)
{
  return memchr(buf, *pChar, count);
}

/* ---- CStringEdString::CStringEdString (CStringEdString_Construct)  0x004AA810 ---- HIGH */
/* The default constructor: both strings empty (_Tidy()), flags 0.  Out of line here,
 * at its retail address; LTCG inlines it at every use. */
CStringEdString::CStringEdString() : flags( 0 )
{
}

/*
 * Retail Dinkumware std::_Tree container header (the object behind std::map and
 * std::set).  Only the low byte of the leading allocator-proxy word is ever
 * touched by these helpers.  "head" is the sentinel node whose left/parent/right
 * links anchor the tree; an empty tree points all three links at the head node.
 */
typedef struct seStlTree_s
{
  char         proxy;   /* +0x00  allocator/proxy slot (low byte only) */
  struct seStlTreeNode_s *head;    /* +0x04  sentinel head node (_Myhead) */
  unsigned int size;    /* +0x08  element count (_Mysize) */
} seStlTree_t;

COD1_STATIC_ASSERT(offsetof(seStlTree_t, head) == 0x04, "seStlTree_t.head");
COD1_STATIC_ASSERT(offsetof(seStlTree_t, size) == 0x08, "seStlTree_t.size");
COD1_ASSERT_SIZE(seStlTree_t, 0x0C);

/*
 * Link header shared by every tree node.  The _Color and _Isnil bytes plus the
 * key/value payload follow these three links; the payload size differs per map
 * instantiation (44-byte and 104-byte nodes here), so only the links are typed
 * and the tail bytes are written raw.
 */
typedef struct seStlTreeNode_s
{
  struct seStlTreeNode_s *left;     /* +0x00  _Left */
  struct seStlTreeNode_s *parent;   /* +0x04  _Parent */
  struct seStlTreeNode_s *right;    /* +0x08  _Right */
} seStlTreeNode_t;

COD1_STATIC_ASSERT(offsetof(seStlTreeNode_t, parent) == 0x04, "seStlTreeNode_t.parent");
COD1_STATIC_ASSERT(offsetof(seStlTreeNode_t, right)  == 0x08, "seStlTreeNode_t.right");

/*
 * The three node layouts of this unit's trees.  Each starts with the
 * seStlTreeNode_t links; the value follows, then the _Color (0 red, 1 black)
 * and _Isnil bytes.
 *   seStrSetNode_t  std::set<std::string>                   44-byte node
 *   seStrIntNode_t  std::map<std::string, int>  (FLAGS bits) 48-byte node
 *   seStrMapNode_t  std::map<std::string, CStringEdString>  104-byte node
 * SE_SETNODE / SE_INTNODE / SE_MAPNODE view a link (or an int-typed node
 * handle) as one of them.
 */
typedef struct seStrSetNode_s
{
  struct seStlTreeNode_s *left;     /* +0x00 */
  struct seStlTreeNode_s *parent;   /* +0x04 */
  struct seStlTreeNode_s *right;    /* +0x08 */
  seStlStr_t              key;      /* +0x0C */
  unsigned char           color;    /* +0x28 */
  unsigned char           isnil;    /* +0x29 */
} seStrSetNode_t;

typedef struct seStrIntNode_s
{
  struct seStlTreeNode_s *left;     /* +0x00 */
  struct seStlTreeNode_s *parent;   /* +0x04 */
  struct seStlTreeNode_s *right;    /* +0x08 */
  seStlStr_t              key;      /* +0x0C  pair.first */
  int                     value;    /* +0x28  pair.second */
  unsigned char           color;    /* +0x2C */
  unsigned char           isnil;    /* +0x2D */
} seStrIntNode_t;

/* std::pair<const std::string, CStringEdString>, the 104-byte node's value (0x58 bytes). */
typedef struct seStrMapPair_s
{
  seStlStr_t        first;    /* +0x00  key */
  CStringEdString_t second;   /* +0x1C  mapped value */
} seStrMapPair_t;

typedef struct seStrMapNode_s
{
  struct seStlTreeNode_s *left;     /* +0x00 */
  struct seStlTreeNode_s *parent;   /* +0x04 */
  struct seStlTreeNode_s *right;    /* +0x08 */
  seStrMapPair_t          myval;    /* +0x0C  _Myval: pair<const string, CStringEdString> */
  unsigned char           color;    /* +0x64 */
  unsigned char           isnil;    /* +0x65 */
} seStrMapNode_t;

COD1_STATIC_ASSERT(offsetof(seStrSetNode_t, key)   == 0x0C, "seStrSetNode_t.key");
COD1_STATIC_ASSERT(offsetof(seStrSetNode_t, color) == 0x28, "seStrSetNode_t.color");
COD1_STATIC_ASSERT(offsetof(seStrSetNode_t, isnil) == 0x29, "seStrSetNode_t.isnil");
COD1_ASSERT_SIZE(seStrSetNode_t, 0x2C);
COD1_STATIC_ASSERT(offsetof(seStrIntNode_t, value) == 0x28, "seStrIntNode_t.value");
COD1_STATIC_ASSERT(offsetof(seStrIntNode_t, isnil) == 0x2D, "seStrIntNode_t.isnil");
COD1_ASSERT_SIZE(seStrIntNode_t, 0x30);
COD1_ASSERT_SIZE(seStrMapPair_t, 0x58);
COD1_STATIC_ASSERT(offsetof(seStrMapNode_t, myval)  == 0x0C, "seStrMapNode_t.myval");
COD1_STATIC_ASSERT(offsetof(seStrMapNode_t, color)  == 0x64, "seStrMapNode_t.color");
COD1_STATIC_ASSERT(offsetof(seStrMapNode_t, isnil)  == 0x65, "seStrMapNode_t.isnil");
COD1_ASSERT_SIZE(seStrMapNode_t, 0x68);

#ifdef __cplusplus
/*
 * std::pair<const std::string, CStringEdString> (seStrMapPair_t) as a C++
 * object.  Both constructors unwind the key when the value's copy throws.
 * Constructed in place (an explicit constructor call on a seStrMapPair_t)
 * or as stl_map_index_m's value_type temporary; its destructor (retail
 * 0x004ACFC0) runs ~second, then ~first.
 */
struct SeStrMapPair
{
  FxStdString     first;    /* +0x00 */
  CStringEdString second;   /* +0x1C */
  SeStrMapPair( const FxStdString &key, const CStringEdString &mapped );
  SeStrMapPair( const SeStrMapPair &other );
  ~SeStrMapPair();
};
/* The C++ view of a seStrMapPair_t. */
#define SE_STRMAPPAIR( p )  ( *(SeStrMapPair *)(p) )
/* _Alnod.destroy(p): ~pair on a seStrMapPair_t. */
#define stl_map_pair_destroy_m( p )  ( SE_STRMAPPAIR(p).SeStrMapPair::~SeStrMapPair() )
#endif

/* std::pair<iterator, bool> (insert's result) and std::pair<iterator, iterator>. */
typedef struct seStlPairIterBool_s
{
  struct seStlTreeNode_s *first;    /* +0x00  iterator */
  char                    second;   /* +0x04  inserted */
} seStlPairIterBool_t;

typedef struct seStlPairIterIter_s
{
  struct seStlTreeNode_s *first;    /* +0x00 */
  struct seStlTreeNode_s *second;   /* +0x04 */
} seStlPairIterIter_t;

#define SE_SETNODE( n )  ( (seStrSetNode_t *)(n) )
#define SE_INTNODE( n )  ( (seStrIntNode_t *)(n) )
#define SE_MAPNODE( n )  ( (seStrMapNode_t *)(n) )

/*
 * Retail Dinkumware std::vector container.  The vectors handled here hold
 * seStlStr_t elements, so the element stride is sizeof(seStlStr_t) == 0x1C.
 */
typedef struct seStlVec_s
{
  void *proxy;    /* +0x00  allocator/proxy slot */
  char *first;    /* +0x04  _Myfirst */
  char *last;     /* +0x08  _Mylast */
  char *end;      /* +0x0C  _Myend */
} seStlVec_t;

COD1_STATIC_ASSERT(offsetof(seStlVec_t, first) == 0x04, "seStlVec_t.first");
COD1_STATIC_ASSERT(offsetof(seStlVec_t, last)  == 0x08, "seStlVec_t.last");
COD1_STATIC_ASSERT(offsetof(seStlVec_t, end)   == 0x0C, "seStlVec_t.end");
COD1_ASSERT_SIZE(seStlVec_t, 0x10);
int __cdecl stl_vector_size_m( seStlVec_t *thisPtr );

/* The language list SE_GetNumLanguages__Fv builds (retail 0x014074F4, a
 * std::vector<std::string> just past TheStringPackage), read back by
 * SE_GetStrFileName_m / SE_GetLanguageFilePath_m.  Zero-initialized; its
 * atexit destructor is registered by SE_StaticInit. */
static seStlVec_t seLanguageVector;

/*
 * Retail CStringEdPackage (TheStringPackage, 0x01407450), as pinned by its
 * constructor/destructor and Clear.  The two maps and the vector are
 * Dinkumware containers spelled out field by field (the same layouts as
 * seStlTree_t/seStlVec_t above):
 *   strings   std::map<std::string, CStringEdString>  104-byte nodes, _Isnil +101
 *   flagNames std::vector<std::string>                 FLAGS names in first-seen order
 *   flagBits  std::map<std::string, int>               48-byte nodes, _Isnil +45
 * Raven's CStringEdPackage (Mac 1.3 symbols, stringed_ingame) names them
 * m_bEndMarkerFound_ParseOnly, m_strCurrentEntryRef_ParseOnly,
 * m_strCurrentEntryEnglish_ParseOnly, m_strCurrentFileRef_ParseOnly,
 * m_strLoadingLanguage_ParseOnly, m_bLoadingEnglish_ParseOnly,
 * m_StringEntries, m_bLoadDebug, m_vstrFlagNames and m_mapFlagMasks.
 */
typedef struct CStringEdPackage_s
{
  int           endMarker;         /* +0x00  set by ENDMARKER */
  seStlStr_t    reference;         /* +0x04  current REFERENCE key */
  seStlStr_t    currentEntryEnglish; /* +0x20  last english string (for #same), reset by Clear */
  seStlStr_t    baseName;          /* +0x3C  upper-cased file base name */
  seStlStr_t    dirName;           /* +0x58  parent (language) directory name */
  int           isEnglish;         /* +0x74 */
  seStlTree_t   strings;           /* +0x78  map<string, CStringEdString> (proxy, _Myhead, _Mysize) */
  int           returnReference;   /* +0x84 */
  seStlVec_t    flagNames;         /* +0x88  vector<string>: FLAGS names in first-seen order */
  seStlTree_t   flagBits;          /* +0x98  map<string, int>: FLAGS name -> bit */
} CStringEdPackage_t;

COD1_STATIC_ASSERT(offsetof(CStringEdPackage_t, reference)       == 0x04, "CStringEdPackage_t.reference");
COD1_STATIC_ASSERT(offsetof(CStringEdPackage_t, currentEntryEnglish) == 0x20, "CStringEdPackage_t.currentEntryEnglish");
COD1_STATIC_ASSERT(offsetof(CStringEdPackage_t, baseName)        == 0x3C, "CStringEdPackage_t.baseName");
COD1_STATIC_ASSERT(offsetof(CStringEdPackage_t, dirName)         == 0x58, "CStringEdPackage_t.dirName");
COD1_STATIC_ASSERT(offsetof(CStringEdPackage_t, isEnglish)       == 0x74, "CStringEdPackage_t.isEnglish");
COD1_STATIC_ASSERT(offsetof(CStringEdPackage_t, strings)         == 0x78, "CStringEdPackage_t.strings");
COD1_STATIC_ASSERT(offsetof(CStringEdPackage_t, returnReference) == 0x84, "CStringEdPackage_t.returnReference");
COD1_STATIC_ASSERT(offsetof(CStringEdPackage_t, flagNames)       == 0x88, "CStringEdPackage_t.flagNames");
COD1_STATIC_ASSERT(offsetof(CStringEdPackage_t, flagBits)        == 0x98, "CStringEdPackage_t.flagBits");
COD1_ASSERT_SIZE(CStringEdPackage_t, 0xA4);

#ifdef __cplusplus
/*
 * The package's container members as C++ objects, so the constructor and
 * destructor get retail's member construction / unwind order.  Same layouts
 * as the seStlTree_t / seStlVec_t views the rest of the unit uses.
 */
/* std::map<std::string, CStringEdString>: the constructor buys the head node;
 * the destructor (_Tidy: erase(begin(), end()), free the head; retail
 * 0x004AAA70, this@<eax>) is what the package's unwind actions call. */
struct SeStrMap : seStlTree_t
{
  SeStrMap()
  {
    FxStlAllocatorTag allocator;   /* allocator_type(): an empty object, copied uninitialized */

    proxy = allocator.value;
    head = stl_map_buynode_str_m(this);
    SE_MAPNODE(head)->isnil = 1;   /* head->_Isnil = 1 (104-byte node) */
    head->parent = head;
    head->left   = head;
    head->right  = head;
    size = 0;
  }
  ~SeStrMap()
  {
    seStlIter_t      first;
    seStlIter_t      last;
    seStlTreeNode_t *iter;

    first.ptr = head->left;
    last.ptr  = head;
    stl_map_erase_range_m(this, &iter, first, last);
    operator delete(head);
    head = 0;
    size = 0;
  }
};

/* std::vector<std::string>: the constructor only zeroes the three pointers;
 * the destructor (retail 0x004ACBF0, this@<esi>) destroys the elements and
 * frees the block. */
struct SeStrVector : seStlVec_t
{
  SeStrVector()
  {
    first = 0;
    last  = 0;
    end   = 0;
  }
  ~SeStrVector()
  {
    FxStlAllocatorTag cat;

    if ( first )
    {
      stl_vector_destroy_range_impl_m((seStlStr_t *)first, (seStlStr_t *)last, this, cat);
      char *p = first;   /* allocator::deallocate(_Ptr): the parameter is its own temp (retail eax, 0x004AA98E) */
      operator delete(p);
    }
    first = 0;
    last  = 0;
    end   = 0;
  }
};

/* std::map<std::string, int> (48-byte nodes): same pattern; the destructor is
 * retail 0x004929F0 (this@<eax>), shared with CFxScheduler's effect-id map. */
struct SeStrIntMap : seStlTree_t
{
  SeStrIntMap()
  {
    FxStlAllocatorTag allocator;

    proxy = allocator.value;
    head = stl_fxEffectIdMap_buynodeHead_m((int)this);
    SE_INTNODE(head)->isnil = 1;   /* head->_Isnil = 1 (48-byte node) */
    head->parent = head;
    head->left   = head;
    head->right  = head;
    size = 0;
  }
  ~SeStrIntMap()
  {
    seStlTreeNode_t *erased;
    seStlTreeNode_t *h;

    stl_fxEffectIdMap_eraseRange_m((int)this, FxMapIteratorArgument((void *)&erased), FxMapIteratorArgument(head->left), FxMapIteratorArgument(head));
    h = head;   /* _Freenode/deallocate(_Myhead): the parameter copy (retail eax, 0x004AA95E) */
    operator delete(h);
    head = 0;
    size = 0;
  }
};

/* CStringEdPackage itself (the C++ view of CStringEdPackage_t). */
struct CStringEdPackage
{
  int          endMarker;             /* +0x00 */
  FxStdString  reference;             /* +0x04 */
  FxStdString  currentEntryEnglish;   /* +0x20 */
  FxStdString  baseName;              /* +0x3C */
  FxStdString  dirName;               /* +0x58 */
  int          isEnglish;             /* +0x74 */
  SeStrMap     strings;               /* +0x78 */
  int          returnReference;       /* +0x84 */
  SeStrVector  flagNames;             /* +0x88 */
  SeStrIntMap  flagBits;              /* +0x98 */
  CStringEdPackage();
  ~CStringEdPackage();
  void SetupNewFileParse( char *path, int returnReference );   /* SE_SetPackageFileInfo_m */
  char *__stdcall Filename_PathOnly( char *path );      /* SE_StripFilename_m */
  char *__stdcall Filename_WithoutExt( char *path );    /* SE_StripExtension_m */
  char *__stdcall Filename_WithoutPath( char *path );   /* SE_SkipPath_m */
  char *ExtractLanguageFromPath( char *path );          /* SE_GetParentDirName_m */
};

COD1_STATIC_ASSERT(sizeof(CStringEdPackage) == sizeof(CStringEdPackage_t), "CStringEdPackage size");
#endif

/* Inlined std::string default constructor: empty, SSO buffer in use. */
static void seStlStr_init(seStlStr_t *s)
{
  s->capacity  = 15;
  s->size      = 0;
  seStlStr_buf(s)[0] = 0;
}

/* Inlined std::string::_Tidy(true, newsize) in its Dinkumware text: free the
 * heap buffer, back to SSO.  The dead copy branch is kept: it moves VC7's
 * register choice for the freed pointer to retail's. */
static void seStlStr_tidyTo(seStlStr_t *s, unsigned int newsize)
{
  if ( 0x10 <= s->capacity )
  {
    char *ptr = s->bx.ptr;
    if ( 0 < newsize )
      memcpy(seStlStr_buf(s), ptr, newsize);
    operator delete(ptr);
  }
  s->capacity = 15;
  seStlStr_cstr(s)[s->size = newsize] = 0;   /* Dinkumware _Eos(newsize) */
}

/* Inlined std::string destructor (_Tidy(true)): free the heap buffer, back to empty SSO. */
static void seStlStr_tidy(seStlStr_t *s)
{
  seStlStr_tidyTo(s, 0);
}

/*
 * Inlined std::less<std::string>: left.compare(0, left.size(), right.c_str(),
 * right.size()), the form the tree-insert descents expand in place.  A
 * non-empty left compares min(sizes) bytes (retail uses repe cmpsb, so only
 * the sign matters); an empty left or a tie falls through to the size
 * comparison.
 */
/* basic_string::compare(off, n0, ptr, count) in its Dinkumware text (every caller passes off 0, so the _Xran range check folds away). */
static int seStlStr_compareTo(seStlStr_t *self, unsigned int off, unsigned int n0, const char *ptr, unsigned int count)
{
  unsigned int ans;

  if ( self->size < off )
    ( (const std::_String_base *)self )->_Xran();   /* off past end */
  if ( self->size - off < n0 )
    n0 = self->size - off;
  ans = n0 == 0 ? 0 : memcmp(seStlStr_cstr(self) + off, ptr, n0 < count ? n0 : count);
  return ans != 0 ? (int)ans : n0 < count ? -1 : n0 == count ? 0 : +1;
}

/* basic_string::size(). */
static unsigned int seStlStr_size(seStlStr_t *s)
{
  return s->size;
}

/* compare(right): compare(0, _Mysize, right._Myptr(), right.size()); the size()
 * call is what orders right's loads as retail's. */
static int seStlStr_compare(seStlStr_t *left, seStlStr_t *right)
{
  return seStlStr_compareTo(left, 0, left->size, seStlStr_cstr(right), seStlStr_size(right));
}

/* ---- CStringEdPackage::CStringEdPackage  0x004AA830 ----  IMPLEMENTED (retail) */
/*
 * Static constructor of TheStringPackage (called from the CRT init table via
 * sub_53C200).  Retail keeps the receiver on the stack (retn 4) and returns
 * this.  The members are constructed in order (the four strings, the map,
 * the vector, the flag map), each unwound by its destructor if a later one
 * throws; the body then clears the package.
 */
CStringEdPackage::CStringEdPackage()
{
  Clear__16CStringEdPackageFi(SePackageRefArgument(this), 0);
}

/* ---- CStringEdPackage::~CStringEdPackage  0x004AA910 ----  IMPLEMENTED (retail) */
/*
 * atexit destructor of TheStringPackage (registered via sub_53C240).  Retail
 * keeps the receiver on the stack, retn 4.  After Clear the members are torn
 * down in reverse order (their destructors inlined).
 */
CStringEdPackage::~CStringEdPackage()
{
  Clear__16CStringEdPackageFi(SePackageRefArgument(this), 0);
}

/* ---- CStringEdPackage_static_fini_m  0x0053C240 ----  IMPLEMENTED (retail) */
/* atexit thunk for TheStringPackage, registered by the 0x0053C200 initializer. */
static void __cdecl CStringEdPackage_static_fini_m( void )
{
  ((CStringEdPackage *)TheStringPackage)->CStringEdPackage::~CStringEdPackage();
}

/* ---- SE_LanguageVector_static_fini_m  0x0053C2B0 ----  IMPLEMENTED (retail) */
/* atexit destructor of seLanguageVector (~vector<std::string>, retail 0x014074F4). */
static void __cdecl SE_LanguageVector_static_fini_m( void )
{
  FxStlAllocatorTag cat;

  if ( seLanguageVector.first )
  {
    stl_vector_destroy_range_impl_m((seStlStr_t *)seLanguageVector.first, (seStlStr_t *)seLanguageVector.last, &seLanguageVector, cat);
    operator delete(seLanguageVector.first);
  }
  seLanguageVector.first = 0;
  seLanguageVector.last  = 0;
  seLanguageVector.end   = 0;
}

/* ---- TheStringPackage_static_init  0x0053C200 ---- */
/* Dynamic initializer of TheStringPackage: construct it, register its destructor. */
static void __cdecl TheStringPackage_static_init( void )
{
  ((CStringEdPackage *)TheStringPackage)->CStringEdPackage::CStringEdPackage();
  atexit(CStringEdPackage_static_fini_m);
}

/* ---- SE_LanguageVector_static_init  0x0053C220 ---- */
/* Dynamic initializer of seLanguageVector (zero-initialized): register its destructor. */
static void __cdecl SE_LanguageVector_static_init( void )
{
  atexit(SE_LanguageVector_static_fini_m);
}

/* The unit's .CRT$XCU entries (__xc_a + 0x08 / + 0x0C, before the FX entries); the CRT's
 * _initterm runs them before WinMain, so the package's map head nodes exist before anything
 * calls Clear__16CStringEdPackageFi. */
typedef void ( __cdecl *seStaticInit_t )( void );
#pragma data_seg( ".CRT$XCU" )
static seStaticInit_t seStaticInit[] = {
  TheStringPackage_static_init,
  SE_LanguageVector_static_init,
};
#pragma data_seg()

/* ---- CStringEdPackage_HasEndMarker_m  0x004AAA60 ---- VERIFIED */
int __cdecl CStringEdPackage_HasEndMarker_m(CStringEdPackage_t *package)
{
  return package->endMarker;
}

/* ---- Clear__16CStringEdPackageFi  0x004AAAA0 ----  IMPLEMENTED (retail) */
/*
 * CStringEdPackage::Clear(bKeepFileInfo): empties the strings map.  Unless
 * bKeepFileInfo is set, it also destroys the FLAGS-name vector and empties
 * the FLAGS-bit map.  Then it drops the ENDMARKER flag and blanks the current
 * REFERENCE and the last english string (+0x20).  Returns the last assign's
 * result (&package->currentEntryEnglish).
 * Retail is __stdcall(this, bKeepFileInfo), retn 8.
 */
int __stdcall Clear__16CStringEdPackageFi( SePackageRef packageRef, int bKeepFileInfo )
{
  CStringEdPackage_t *pkg = (CStringEdPackage_t *)packageRef.package;
  FxStlAllocatorTag   cat;

  /* strings.clear(), inlined (this = &strings): _Erase(root), then reset the head and size. */
  {
    seStlTree_t *strings = &pkg->strings;

    stl_tree_erase_all_m(strings, *(seStlIter_t *)&strings->head->parent);
    strings->head->parent = strings->head;
    strings->size         = 0;
    strings->head->left   = strings->head;
    strings->head->right  = strings->head;
  }

  if ( !bKeepFileInfo )
  {
    /* flagNames: destroy the elements, free the block, zero the pointers. */
    seStlVec_t  *flagNames = &pkg->flagNames;
    seStlTree_t *flagBits;

    if ( flagNames->first )
    {
      stl_vector_destroy_range_impl_m((seStlStr_t *)flagNames->first, (seStlStr_t *)flagNames->last, flagNames, cat);
      operator delete(flagNames->first);
    }
    flagNames->first = 0;
    flagNames->last  = 0;
    flagNames->end   = 0;

    /* flagBits.clear(), inlined as above. */
    flagBits = &pkg->flagBits;
    stl_fxEffectIdMap_eraseSubtree_m(flagBits, *(FxMapRootValue *)&flagBits->head->parent);
    flagBits->head->parent = flagBits->head;
    flagBits->size         = 0;
    flagBits->head->left   = flagBits->head;
    flagBits->head->right  = flagBits->head;
  }

  pkg->endMarker = 0;
  stl_string_assign_cstr_m("", SeStringReceiverArgument(&pkg->reference));   /* = "" */
  return stl_string_assign_cstr_m("", SeStringReceiverArgument(&pkg->currentEntryEnglish));   /* = "" */
}

static char se_szDirNameBuf[64];        /* retail 0x0140CAA8 */
static char se_szNoExtBuf[64];          /* retail 0x0140CA68 */
static char se_szBaseNameBuf[64];       /* retail 0x0140CA28 */

/*
 * The package's path helpers (Raven's Filename_PathOnly / Filename_WithoutExt /
 * Filename_WithoutPath and CStringEdPackage::ExtractLanguageFromPath).  In this
 * build they are CStringEdPackage members: retail pushes the package as their
 * (unread) receiver, path@<eax> (Filename_WithoutPath: path@<edx>), retn 4.
 */
/* ---- CStringEdPackage::Filename_PathOnly (SE_StripFilename_m)  0x004AAB80 ---- VERIFIED */
char *__stdcall CStringEdPackage::Filename_PathOnly( char *path )
{
  char *slash;
  char *backslash;

  strcpy(se_szDirNameBuf, path);   /* retail 0x4AAB80: inline unbounded strcpy */

  backslash = strrchr(se_szDirNameBuf, '\\');
  slash     = strrchr(se_szDirNameBuf, '/');
  if ( backslash > slash )
    slash = backslash;
  if ( slash )
    *slash = '\0';

  return se_szDirNameBuf;
}

/* ---- CStringEdPackage::Filename_WithoutExt (SE_StripExtension_m)  0x004AABD0 ---- VERIFIED */
char *__stdcall CStringEdPackage::Filename_WithoutExt( char *path )
{
  char *dot;
  char *backslash;
  char *slash;

  strcpy(se_szNoExtBuf, path);     /* retail 0x4AABD0: inline unbounded strcpy */

  dot       = strrchr(se_szNoExtBuf, '.');
  backslash = strrchr(se_szNoExtBuf, '\\');
  slash     = strrchr(se_szNoExtBuf, '/');
  if ( dot && (!backslash || dot > backslash) && (!slash || dot > slash) )
    *dot = '\0';

  return se_szNoExtBuf;
}

/* ---- CStringEdPackage::Filename_WithoutPath (SE_SkipPath_m)  0x004AAC30 ---- VERIFIED */
char *__stdcall CStringEdPackage::Filename_WithoutPath( char *path )
{
  const char *base;
  const char *p;

  base = path;
  while ( *path )
  {
    if ( *path == '/' || *path == '\\' )
      base = path + 1;
    path++;
  }

  strcpy(se_szBaseNameBuf, base);  /* retail 0x4AAC4D: inline unbounded strcpy */
  return se_szBaseNameBuf;
}

/* ---- CStringEdPackage::ExtractLanguageFromPath (SE_GetParentDirName_m)  0x004AAC70 ---- VERIFIED */
/* The immediate parent directory (the language) of a .str path.  Retail: path@<eax>,
 * this@<esi>; SE_GetNumLanguages__Fv and SE_LoadAllLanguageFiles_m inline it. */
char *CStringEdPackage::ExtractLanguageFromPath( char *path )
{
  return Filename_WithoutPath( Filename_PathOnly( path ) );
}

/* ---- CStringEdPackage::SetupNewFileParse (SE_SetPackageFileInfo_m)  0x004AAC80 ---- VERIFIED */
/* Raven's CStringEdPackage::SetupNewFileParse: records the file's upper-cased base name
 * and its language directory, whether that is "english", and the returnReference flag.
 * Retail (LTCG): path@<ecx>, this@<esi>, returnReference on the stack, retn 4. */
void CStringEdPackage::SetupNewFileParse( char *path, int returnReference )
{
  CStringEdPackage_t *package = (CStringEdPackage_t *)this;
  char        *ext;
  char        *dir;
  char        *dirBase;
  seStlStr_t  *baseNameStr;
  seStlStr_t  *dirNameStr;
  int         isEnglish;
  char         fileBase[64];

  ext = Filename_WithoutExt(path);
  strcpy(fileBase, Filename_WithoutPath(ext));
  strupr(fileBase);
  stl_fxString_assignPtrCount_m(&package->baseName, FxConstCharArgument(fileBase), FxCountArgument(strlen(fileBase)));

  dir     = Filename_PathOnly(path);
  dirBase = Filename_WithoutPath(dir);
  stl_fxString_assignPtrCount_m(&package->dirName, FxConstCharArgument(dirBase), FxCountArgument(strlen(dirBase)));

  isEnglish = _stricmp(seStlStr_cstr(&package->dirName), "english") == 0;
  package->isEnglish = isEnglish;
  package->returnReference = returnReference;
}

/* ---- SE_MatchKeyword_m  0x004AAD50 ---- VERIFIED */
int __stdcall SE_MatchKeyword_m(const char *keyword, const char **pp, SePackageWord packageWord)
{
  int unused=packageWord.package;
 (void)unused;
 if (!_strnicmp(keyword,*pp,strlen(keyword)))
 {
  *pp+=strlen(keyword);
  while (**pp=='\t' || **pp==' ') ++*pp;
  return 1;
 }
 return 0;
}

/* Function-local static std::string of SE_UnescapeNewlines_m, hoisted to file scope. */
static seStlStr_t   se_strUnescapeScratch;        /* retail 0x0140CB48 */
static unsigned int se_strUnescapeScratchGuard;   /* retail 0x0140CB64, bit 0 = constructed */

/* ---- SE_UnescapeNewlines_static_fini_m  0x0053C250 ----  IMPLEMENTED (retail) */
/* atexit destructor emitted for se_strUnescapeScratch. */
static void __cdecl SE_UnescapeNewlines_static_fini_m( void )
{
  seStlStr_tidy(&se_strUnescapeScratch);
}

/* ---- SE_UnescapeNewlines_m  0x004AADA0 ----  IMPLEMENTED (retail) */
/*
 * Copies `text` into a static std::string and turns every two-character
 * "\n" escape into a real newline; returns the static's c_str().
 * Retail is __userpurge: text@<eax> plus one dead stack word, retn 4.
 */
char *__stdcall SE_UnescapeNewlines_m( const char *text, SePackageWord packageWord )
{
  int unused=packageWord.package;
  unsigned int pos;

  (void)unused;

  if ( !(se_strUnescapeScratchGuard & 1) )
  {
    se_strUnescapeScratchGuard |= 1;
    seStlStr_init(&se_strUnescapeScratch);
    atexit(SE_UnescapeNewlines_static_fini_m);
  }

  stl_fxString_assignPtrCount_m(&se_strUnescapeScratch, FxConstCharArgument(text), FxCountArgument(strlen(text)));
  for ( pos = stl_string_find_cstr_m("\\n", &se_strUnescapeScratch, 0);
        pos != (unsigned int)-1;
        pos = stl_string_find_cstr_m("\\n", &se_strUnescapeScratch, 0) )
  {
    seStlStr_cstr(&se_strUnescapeScratch)[pos] = '\n';   /* the backslash becomes the newline */
    stl_fxString_erase_m(&se_strUnescapeScratch, pos + 1, 1); /* and the 'n' is erased */
  }

  return seStlStr_cstr(&se_strUnescapeScratch);
}

/* ---- SE_StripComment_m  0x004AAEA0 ---- VERIFIED */
/* CStringEdPackage::REMKill: cut the line at the first // outside double
 * quotes, then strip trailing white space. */
void __stdcall SE_StripComment_m(char *psBuffer, SePackageWord packageWord)
{
  char *psScanPos = psBuffer;
  char *p;
  int   iDoubleQuotesSoFar = 0;

  (void)packageWord;

  /* scan forwards in case there are more than one (and the first is inside quotes)... */
  while ( ( p = strstr( psScanPos, "//" ) ) != NULL )
  {
    /* count the number of double quotes before this point, if odd number, then we're inside quotes... */
    int iDoubleQuoteCount = iDoubleQuotesSoFar;
    int i;

    for ( i = 0; i < p - psScanPos; i++ )
    {
      if ( psScanPos[i] == '"' )
        iDoubleQuoteCount++;
    }
    if ( !( iDoubleQuoteCount & 1 ) )
    {
      /* not inside quotes, so kill line here... */
      *p = '\0';

      /* and remove any trailing whitespace... */
      if ( psScanPos[0] )
      {
        int iWhiteSpaceScanPos = strlen( psScanPos ) - 1;
        while ( iWhiteSpaceScanPos >= 0 && isspace( psScanPos[iWhiteSpaceScanPos] ) )
        {
          psScanPos[iWhiteSpaceScanPos] = '\0';
          iWhiteSpaceScanPos--;
        }
      }
      return;
    }
    else
    {
      /* inside quotes (blast), oh well, skip past and keep scanning... */
      psScanPos = p + 1;
      iDoubleQuotesSoFar = iDoubleQuoteCount;
    }
  }
}

/* ---- SE_GetNextLine_m  0x004AAF30 ---- VERIFIED */
int __stdcall SE_GetNextLine_m(const char **pp, char *out, SePackageWord packageWord)
{
  int unused=packageWord.package;
  const char *cursor;
  const char *nl;
  size_t      len;
  int         i;

  if ( **pp )
  {
    nl = strchr(*pp, '\n');
    if ( nl )
    {
      len = nl - *pp;
      strncpy(out, *pp, len);
      out[len] = '\0';

      *pp += len;
      while ( **pp && strchr("\r\n", **pp) )
        ++*pp;
    }
    else
    {
      strcpy(out, *pp);
      *pp += strlen(*pp);
    }

    if ( *out )
    {
      for ( i = (int)strlen(out) - 1 ; i >= 0 ; i-- )
      {
        if ( !isspace( out[i] ) )
          break;
        out[i] = '\0';
      }
      SE_StripComment_m(out, SePackageWordArgument(unused));
    }
    return 1;
  }
  return 0;
}

/* Function-local static std::string of SE_UnquoteAndTrim_m, hoisted to file scope. */
/* The string and the compiler's construction guard right behind it, as the
 * function-local static and its $S guard sit in retail. */
static struct
{
  seStlStr_t   str;     /* retail 0x0140CB28 */
  unsigned int guard;   /* retail 0x0140CB44, bit 0 = constructed */
} se_strUnquote;

/* ---- SE_UnquoteAndTrim_static_fini_m  0x0053C280 ----  IMPLEMENTED (retail) */
/* atexit destructor emitted for se_strUnquote.str. */
static void __cdecl SE_UnquoteAndTrim_static_fini_m( void )
{
  seStlStr_tidy(&se_strUnquote.str);
}

/* ---- SE_UnquoteAndTrim_m  0x004AB020 ----  IMPLEMENTED (retail) */
/*
 * Turns a .str value field into its text: skips leading spaces/tabs, drops
 * one opening '"', trims trailing spaces/tabs and then one closing '"'.
 * Works in a static std::string and returns its c_str().
 * Retail is __userpurge: text@<eax> plus one dead stack word, retn 4.
 */
char *__stdcall SE_UnquoteAndTrim_m( const char *text, SePackageWord packageWord )
{
  int unused=packageWord.package;
  char   *data;
  size_t  len;

  (void)unused;

  if ( !(se_strUnquote.guard & 1) )
  {
    se_strUnquote.guard |= 1;
    seStlStr_init(&se_strUnquote.str);
    atexit(SE_UnquoteAndTrim_static_fini_m);
  }

  stl_string_assign_cstr_m("", SeStringReceiverArgument(&se_strUnquote.str));   /* = "" */

  while ( *text == ' ' || *text == '\t' )
    text++;
  if ( *text == '"' )
    text++;

  stl_fxString_assignPtrCount_m(&se_strUnquote.str, FxConstCharArgument(text), FxCountArgument(strlen(text)));

  if ( *text )
  {
    







    while (seStlStr_cstr(&se_strUnquote.str)[strlen(seStlStr_cstr(&se_strUnquote.str))-1]==' ' || seStlStr_cstr(&se_strUnquote.str)[strlen(seStlStr_cstr(&se_strUnquote.str))-1]=='\t')
      stl_fxString_erase_m(&se_strUnquote.str,strlen(seStlStr_cstr(&se_strUnquote.str))-1,1);
    if (seStlStr_cstr(&se_strUnquote.str)[strlen(seStlStr_cstr(&se_strUnquote.str))-1]=='"')
      stl_fxString_erase_m(&se_strUnquote.str,strlen(seStlStr_cstr(&se_strUnquote.str))-1,1);
  }

  return seStlStr_cstr(&se_strUnquote.str);
}

/* ---- SE_FindConfigValue_m  0x004AB1F0 ----  IMPLEMENTED (retail) */
/*
 * Looks `name` up in the package's flag-bit map (map<string,int> at +0x98)
 * and returns its bit, or 0 when the flag has not been seen yet.
 * Retail is __fastcall with a dead ecx: name@<edx>, package on the stack,
 * retn 4 (an EH function, so LTCG leaves it alone).  __stdcall(name, package)
 * gives the same caller shape here without the dead parameter.
 */
int __stdcall SE_FindConfigValue_m(char *name, int package)
{
  CStringEdPackage_t *pkg = (CStringEdPackage_t *)package;
  int                 node;

  stl_fxEffectIdMap_find_m(&node, (int)&pkg->flagBits, (int)SE_TMPSTR(name));   /* m_mapFlagBits.find(name) */
  if ( node != (int)pkg->flagBits.head )
    return SE_INTNODE(node)->value;   /* node->second */
  return 0;
}

/* ---- SE_ParseVersion_m  0x004AB2A0 ----  IMPLEMENTED (retail) */
/*
 * Handler for one token of a FLAGS line (SE_ParseLine_m upper-cases each
 * token and passes the current REFERENCE).  A flag seen for the first time is
 * appended to the package's flag-name vector and given the bit
 * 1 << (index in that vector).  The bit is then OR'd into the flags word of
 * the string "<BASENAME>_<reference>", if that string exists.  Returns the
 * found map iterator (end() on a miss).
 * Retail is __thiscall: flagName@<ecx>, then (package, reference), retn 8.
 */
void __fastcall SE_ParseVersion_m( char *flagName, SePackageWord packageWord, FxConstCharPointerArgument referenceWord )
{
  int                 package = packageWord.package;
  const char         *reference = referenceWord.pointer;
  CStringEdPackage_t *pkg = (CStringEdPackage_t *)package;
  int                 flagBit;

  /* taking the address keeps the declared ecx/stack convention under LTCG */
  (void)&SE_ParseVersion_m;

  /* add the flag to the list of known ones... */
  flagBit = SE_FindConfigValue_m(flagName, package);
  if ( !flagBit )
  {
    stl_vector_push_back_m(&pkg->flagNames, SE_TMPSTR(flagName));   /* m_vstrFlagNames */
    /* x86 shl masks the count, so an empty vector would give bit 31. */
    flagBit = (int)(1u << (stl_vector_size_m(&pkg->flagNames) - 1));
    *(int *)stl_fxEffectIdMap_index_m((int)&pkg->flagBits, SE_TMPSTR(flagName)) = flagBit;
  }

  /* ...then add the reference to this flag to the currently-parsed reference */
  {
    SeMapIter itEntry( stl_map_find_m(&pkg->strings,
                                      SE_TMPSTR(va("%s_%s", seStlStr_cstr(&pkg->baseName), reference))) );

    if ( itEntry.node != pkg->strings.head )
      SE_MAPNODE(itEntry.node)->myval.second.flags |= flagBit;   /* node +0x60 */
  }
}

/* ---- SE_ParseLine_m  0x004AB470 ----  IMPLEMENTED (retail) */
/*
 * Dispatches one non-empty .str line on its leading keyword (SE_MatchKeyword_m
 * is a case-insensitive PREFIX match, hence FILENOTES before NOTES).  Returns
 * NULL on success, otherwise an error string (a literal or a va() buffer).
 * SE_MatchKeyword_m, SE_UnquoteAndTrim_m and SE_UnescapeNewlines_m each get
 * the package in their dead stack slot, as retail pushes ebx for them.
 * Retail is __userpurge: package@<ebx>, line on the stack, retn 4.
 */
char *__stdcall SE_ParseLine_m( int package, char *line )
{
  CStringEdPackage_t *pkg = (CStringEdPackage_t *)package;
  char               *err;

  err = NULL;
  if ( line )
  {
    if ( SE_MatchKeyword_m("VERSION", (const char **)&line, SePackageWordArgument(package)) )
    {
      int version = j__atol(SE_UnquoteAndTrim_m(line, SePackageWordArgument(package)));

      if ( version != 1 )
        err = va("Unexpected version number %d, expecting %d!\n", version, 1);
    }
    else if ( SE_MatchKeyword_m("CONFIG", (const char **)&line, SePackageWordArgument(package))
           || SE_MatchKeyword_m("FILENOTES", (const char **)&line, SePackageWordArgument(package))
           || SE_MatchKeyword_m("NOTES", (const char **)&line, SePackageWordArgument(package)) )
    {
      /* not used ingame, but the token is absorbed */
    }
    else if ( SE_MatchKeyword_m("REFERENCE", (const char **)&line, SePackageWordArgument(package)) )
    {
      SE_ParseConfig_m(package, SE_UnquoteAndTrim_m(line, SePackageWordArgument(package)));
    }
    else if ( SE_MatchKeyword_m("FLAGS", (const char **)&line, SePackageWordArgument(package)) )
    {
      char *reference = seStlStr_cstr(&pkg->reference);

      if ( *reference )
      {
        char  flags[1024] = { 0 };
        char *token;

        strncpy(flags, line, sizeof(flags) - 1);
        token = strtok(flags, " \t");
        while ( token )
        {
          strupr(token);
          SE_ParseVersion_m(token, SePackageWordArgument(package), FxConstCharArgument(reference));
          token = strtok(NULL, " \t");
        }
      }
      else
      {
        err = "Error parsing file: Unexpected \"FLAGS\"\n";
      }
    }
    else if ( SE_MatchKeyword_m("ENDMARKER", (const char **)&line, SePackageWordArgument(package)) )
    {
      pkg->endMarker = 1;
    }
    else if ( !_strnicmp("LANG_", line, 5) )
    {
      char *reference = seStlStr_cstr(&pkg->reference);

      if ( *reference )
      {
        char   *nameEnd;
        char   *text;

        line += 5;
        for ( nameEnd = line; *nameEnd && *nameEnd != ' ' && *nameEnd != '\t'; nameEnd++ )
          ;
        char    language[1024] = { 0 };
        size_t  nameLen = nameEnd - line;
        if ( nameLen > sizeof(language) - 1 )
          nameLen = sizeof(language) - 1;
        strncpy(language, line, nameLen);
        line += strlen(language);
        text = SE_UnquoteAndTrim_m(line, SePackageWordArgument(package));
        text = SE_UnescapeNewlines_m(text, SePackageWordArgument(package));

        if ( pkg->isEnglish )
        {
          SE_ParseLanguageString_m(reference, package, text, 0);
        }
        else
        {
          int isEnglishLang = _stricmp(language, "english") == 0;

          if ( !isEnglishLang )
          {
            if ( _stricmp(seStlStr_cstr(&pkg->dirName), language) )
              err = va("Language \"%s\" found when expecting \"%s\"!\n", language, seStlStr_cstr(&pkg->dirName));
          }
          if ( !err )
            SE_ParseLanguageString_m(reference, package, text, isEnglishLang);
        }
      }
      else
      {
        err = "Error parsing file: Unexpected \"LANG_\"\n";
      }
    }
    else
    {
      err = va("Unknown keyword at linestart: \"%s\"\n", line);
    }
  }
  return err;
}

/* ---- CStringEdPackage_GetFileName_m  0x004AB780 ---- MEDIUM */
const char *__cdecl CStringEdPackage_GetFileName_m(CStringEdPackage_t *package)
{
  return seStlStr_cstr(&package->reference);   /* package +0x04 */
}

/* ---- SE_ParseConfig_m  0x004AB790 ----  IMPLEMENTED (retail) */
/*
 * REFERENCE handler (the name is historical).  Makes sure the strings map
 * holds an entry for "<BASENAME>_<reference>" -- a missing one is created and
 * assigned a blank CStringEdString, i.e. strings[key] = CStringEdString() --
 * then stores the reference as the package's current REFERENCE.  Returns the
 * assign's result (&pkg->reference).
 * Retail is __stdcall(package, reference), retn 8.
 */
int __stdcall SE_ParseConfig_m( int package, char *reference )
{
  CStringEdPackage_t *pkg = (CStringEdPackage_t *)package;
  SeMapIter           itEntry( stl_map_find_m(&pkg->strings, SE_TMPSTR(va("%s_%s", seStlStr_cstr(&pkg->baseName), reference))) );

  if ( itEntry.node == SeMapIter(pkg->strings.head).node )   /* itEntry == m_StringEntries.end() */
  {
    CStringEdString    blank;   /* CStringEdString() */
    FxStdString        key( va("%s_%s", seStlStr_cstr(&pkg->baseName), reference) );   /* formatted a second time */
    CStringEdString_t *entry;

    /* m_StringEntries[key] = blank */
    entry = (CStringEdString_t *)stl_map_index_m(&pkg->strings, SE_STR(key));
    /* Inlined CStringEdString::operator=. */
    stl_fxString_assignSubstr_m(&entry->key,   SE_STR(blank.key),   0, 0xFFFFFFFF);
    stl_fxString_assignSubstr_m(&entry->value, SE_STR(blank.value), 0, 0xFFFFFFFF);
    entry->flags = blank.flags;
  }

  return stl_fxString_assignPtrCount_m(&pkg->reference, FxConstCharArgument(reference), FxCountArgument(strlen(reference)));
}

/* ---- CStringEdString::~CStringEdString  0x004AB9F0 ---- */
/*
 * Out of line only for the unwind funclets (SE_ParseConfig_m's blank and
 * stl_map_index_m's mapped_type() temporary); retail has it inside
 * SE_ParseConfig_m's IDA span.  The members go in reverse order.
 */
inline CStringEdString::~CStringEdString()
{
}

/* ---- CStringEdString_Copy  0x004ABA40 ---- HIGH */
int __cdecl CStringEdString_Copy(int srcPtr, int dstPtr)
{
  CStringEdString_t *src = (CStringEdString_t *)srcPtr;
  CStringEdString_t *dst = (CStringEdString_t *)dstPtr;

  stl_fxString_assignSubstr_m(&dst->key,   &src->key,   0, 0xFFFFFFFF);
  stl_fxString_assignSubstr_m(&dst->value, &src->value, 0, 0xFFFFFFFF);
  dst->flags = src->flags;
  return dstPtr;
}

/* ---- SE_ParseLanguageString_m  0x004ABA70 ----  IMPLEMENTED (retail) */
/*
 * Stores the text of one LANG_ line into the entry "<BASENAME>_<reference>"
 * (created earlier by the REFERENCE line); a missing entry is ignored.
 *   english text:  entry +0x00 = text, and when returnReference is set
 *                  entry +0x1C = "[" text "]"; the text is also kept in
 *                  pkg->currentEntryEnglish as the last english string.
 *   other text:    "#same" copies that last english string (and, with
 *                  returnReference, sets +0x1C to "[#same]"); anything else
 *                  is assigned to entry +0x00 as is.
 * Raven's CStringEdPackage::SetString; the lookup key is a std::string
 * temporary.  Retail: reference@<ecx>, then (package, text, isEnglish), retn 0Ch
 * (declared __stdcall; LTCG passes the reference in ecx).
 */
void __stdcall SE_ParseLanguageString_m( const char *reference, int package, char *text, int isEnglish )
{
  CStringEdPackage_t *pkg = (CStringEdPackage_t *)package;
  SeMapIter           itEntry( stl_map_find_m(&pkg->strings,
                                      SE_TMPSTR(va("%s_%s", seStlStr_cstr(&pkg->baseName), reference))) );

  if ( itEntry.node != pkg->strings.head )
  {
    CStringEdString_t *entry = &SE_MAPNODE(itEntry.node)->myval.second;   /* (*itEntry).second */

    if ( !isEnglish && !pkg->isEnglish )
    {
      /* a foreign string: "#same" means the last english one */
      if ( !_stricmp(text, "#same") )
      {
        stl_fxString_assignSubstr_m(&entry->key, &pkg->currentEntryEnglish, 0, 0xFFFFFFFF);
        if ( pkg->returnReference )
        {
          seStlStr_t *shown = &entry->value;

          stl_string_assign_cstr_m("[", SeStringReceiverArgument(shown));
          stl_string_append_cstr_m(shown, "#same");
          stl_string_append_cstr_m(shown, "]");
        }
      }
      else
      {
        stl_string_assign_cstr_m(text, SeStringReceiverArgument(&entry->key));
      }
    }
    else
    {
      stl_fxString_assignPtrCount_m(&entry->key, FxConstCharArgument(text), FxCountArgument(strlen(text)));
      if ( pkg->returnReference )
      {
        stl_string_assign_cstr_m("[", SeStringReceiverArgument(&entry->value));
        stl_string_append_cstr_m(&entry->value, text);
        stl_string_append_cstr_m(&entry->value, "]");
      }
      stl_fxString_assignPtrCount_m(&pkg->currentEntryEnglish, FxConstCharArgument(text), FxCountArgument(strlen(text)));
    }
  }
}

/* ---- SE_LoadLanguageFile_m  0x004ABC50 ----  IMPLEMENTED (retail) */
/*
 * Reads one .str file into TheStringPackage: records the file's base name and
 * language directory, then feeds every non-empty line to SE_ParseLine_m until
 * the buffer ends or a line reports an error.  Returns NULL on success, the
 * line's error, "Truncated file..." when no ENDMARKER was seen, or (unless
 * `optional`) "Unable to load...".  The line buffer is 16 KB and unbounded,
 * as in retail (see SE_GetNextLine_m).
 * Retail: path@<ecx>, then (returnReference, optional), caller-cleaned.
 */
char *__cdecl SE_LoadLanguageFile_m( const char *path, int returnReference, int optional )
{
  CStringEdPackage_t *pkg = (CStringEdPackage_t *)TheStringPackage;
  char               *err;
  void               *buffer;
  const char         *cursor;
  char                line[0x4000];

  err = NULL;
  if ( FS_ReadFile(path, &buffer) > 0 && buffer )
  {
    cursor = (const char *)buffer;
    ((CStringEdPackage *)TheStringPackage)->SetupNewFileParse((char *)path, returnReference);
    while ( !err && SE_GetNextLine_m(&cursor, line, SePackageWordArgument((int)TheStringPackage)) )
    {
      if ( strlen(line) )
        err = SE_ParseLine_m((int)TheStringPackage, line);
    }
    FS_FreeFile(buffer);

    if ( !err && !pkg->endMarker )
      err = va("Truncated file, failed to find \"%s\" at file end!", "ENDMARKER");
  }
  else if ( !optional )
  {
    err = va("Unable to load \"%s\"!", path);
  }
  return err;
}

/* ---- SE_NextSemicolonToken_m  0x004ABD60 ----  IMPLEMENTED (retail) */
/*
 * Pops the next ';'-separated token off a std::string list: copies at most
 * 63 characters into se_szTokenBuf, cuts at the first ';' and erases the
 * token plus its ';' from the list (the whole list when there is no ';' in
 * the copied part).  Returns se_szTokenBuf, or NULL once the list is empty.
 * Retail is __usercall: list@<esi>.
 */
char *__cdecl SE_NextSemicolonToken_m( seStlStr_t *list )
{
  seStlStr_t *str = list;
  char *semicolon;

  if ( !strlen(seStlStr_cstr(str)) )
    return NULL;

  strncpy(se_szTokenBuf, seStlStr_cstr(str), sizeof(se_szTokenBuf) - 1);
  se_szTokenBuf[sizeof(se_szTokenBuf) - 1] = 0;

  semicolon = strchr(se_szTokenBuf, ';');
  if ( semicolon )
  {
    *semicolon = 0;
    stl_fxString_erase_m(list, 0, (unsigned int)(semicolon - se_szTokenBuf) + 1);
  }
  else
  {
    stl_fxString_erase_m(list, 0, 0xFFFFFFFF);   /* erase(0, npos) */
  }
  return se_szTokenBuf;
}

/* ---- SE_LoadStringEditFile_m  0x004ABDF0 ---- HIGH */
char *__cdecl SE_LoadStringEditFile_m(char *path, int returnReference)
{
  char        *err;
  char        *ext;
  char         stePath[64];

  
  err = SE_LoadLanguageFile_m(path, returnReference, 0);
  if (!err)
  {
    strncpy(stePath,path,63);
    stePath[63]=0;
    ext=strrchr(stePath,'.');
    if (ext && strlen(ext)==4)
    {
      strcpy(ext,".ste");
      return SE_LoadLanguageFile_m(stePath,returnReference,1);
    }
  }
  return err;
}

/* ---- SE_GetStringForLanguage_m  0x004ABEA0 ---- MEDIUM */
char *__cdecl SE_GetStringForLanguage_m(const char *prefix, const char *lang, int wantReference)
{
  char key[256];   /* the /GS cookie of retail's frame comes with this buffer */

  sprintf(key, "%s_%s", prefix, lang);
  return SE_GetString(key, wantReference);
}

/* ---- SE_GetString  0x004ABF00 ----  IMPLEMENTED (retail) */
/*
 * Looks `key` up in TheStringPackage's strings map.  Returns NULL when the key
 * is unknown.  Otherwise it returns the entry's "[...]" reference copy (+0x1C)
 * when both wantReference and the package's returnReference flag are set,
 * and the localized text (+0x00) in every other case.  An entry that a
 * REFERENCE line created and no LANG_ line filled returns "".  key is not
 * checked for NULL.
 * Retail is __usercall: key@<edx>, wantReference on the stack.
 */
char *SE_GetString( const char *key, int wantReference )
{
  CStringEdPackage_t *pkg = (CStringEdPackage_t *)TheStringPackage;
  SeMapIter           itEntry( stl_map_find_m(&pkg->strings, SE_TMPSTR(key)) );

  if ( itEntry.node != pkg->strings.head )
  {
    CStringEdString_t *entry = &SE_MAPNODE(itEntry.node)->myval.second;   /* (*itEntry).second */

    if ( wantReference && pkg->returnReference )
      return seStlStr_cstr(&entry->value);              /* node +0x44 */
    return seStlStr_cstr(&entry->key);                  /* node +0x28 */
  }
  return NULL;
}

/* ---- SE_LookupStringForLanguage_m  0x004AC010 ---- MEDIUM */
int __cdecl SE_LookupStringForLanguage_m(const char *prefix, const char *lang)
{
  char key[256];   /* the /GS cookie of retail's frame comes with this buffer */

  sprintf(key, "%s_%s", prefix, lang);
  return SE_LookupString_m(key);
}

/* ---- SE_LookupString_m  0x004AC070 ----  IMPLEMENTED (retail) */
/*
 * Looks `key` up in TheStringPackage's strings map and returns that entry's
 * FLAGS word (node +0x60), or 0 when the key is unknown.
 * Retail passes the sole explicit key argument in edx; a dead register
 * slot does not introduce an additional source argument.
 */
int __cdecl SE_LookupString_m(const char *key)
{
  CStringEdPackage_t *pkg = (CStringEdPackage_t *)TheStringPackage;
  SeMapIter           itEntry( stl_map_find_m(&pkg->strings, SE_TMPSTR(key)) );

  if ( itEntry.node != pkg->strings.head )
    return SE_MAPNODE(itEntry.node)->myval.second.flags;   /* (*itEntry).second.m_iFlags */
  return 0;
}

/* ---- SE_GetNumLanguageDirs_m  0x004AC120 ---- */
/*
 * Despite the name this is Raven's SE_GetNumFlags: retail reads
 * TheStringPackage+0x8C/+0x90 (absolute 0x014074DC/0x014074E0), the
 * package's FLAGS-name vector<string> that SE_ParseVersion_m appends to.
 * Signed divide by 0x1C, as retail's imul 92492493h / sar 4 sequence.
 */
int SE_GetNumLanguageDirs_m()
{
  CStringEdPackage_t *pkg = (CStringEdPackage_t *)TheStringPackage;   /* 0x014074DC / 0x014074E0 */

  return !pkg->flagNames.first ? 0 : (int)(pkg->flagNames.last - pkg->flagNames.first) / (int)sizeof(seStlStr_t);
}

/* ---- SE_GetLanguageDirName_m  0x004AC150 ---- HIGH */
/*
 * Raven's SE_GetFlagName: the index-th entry of the package's FLAGS-name
 * vector (TheStringPackage+0x8C/+0x90), or "" (0x00559228) when the vector is
 * unallocated or index is out of range (unsigned compare against the signed
 * element count, as retail).
 */
char *__cdecl SE_GetLanguageDirName_m(unsigned int index)
{
  CStringEdPackage_t *pkg = (CStringEdPackage_t *)TheStringPackage;
  seStlStr_t         *entry;

  if ( !pkg->flagNames.first
    || index >= (unsigned int)((int)(pkg->flagNames.last - pkg->flagNames.first) / (int)sizeof(seStlStr_t)) )
    return "";   /* 0x00559228 */

  entry = (seStlStr_t *)(pkg->flagNames.first + sizeof(seStlStr_t) * index);
  return seStlStr_cstr(entry);
}

/* ---- SE_GetConfigValue_m  0x004AC1A0 ---- HIGH */
/* name is passed straight through in its register; package pushed. */
int __stdcall SE_GetConfigValue_m(char *name)
{
  return SE_FindConfigValue_m(name, (int)TheStringPackage);
}

/* ---- SE_GetNumLanguages__Fv  0x004AC1B0 ----  IMPLEMENTED (retail) */
/*
 * Rebuilds seLanguageVector (retail 0x014074F4) from the .str files found
 * recursively under "localizedstrings" and returns its size.  Each distinct
 * immediate parent directory name is added once, in discovery order, and
 * "english" (_stricmp) is inserted at the front.  Distinct means distinct in
 * a case-sensitive std::set<std::string>.  Retail inlines SE_CountStrFiles_m
 * (seStrFileCount = 0, list = "", SE_EnumerateStrFiles_m), set::count
 * (stl_map44_count_m) and the set's constructor and destructor.
 */
#ifdef __cplusplus
/* std::set<std::string>, as a local: the constructor buys the head node, the
 * destructor erases everything and frees it.  (Retail copies an uninitialized
 * allocator byte into the proxy slot.) */
struct SeStrSetLocal
{
  seStlTree_t tree;
  SeStrSetLocal()
  {
    FxStlAllocatorTag allocator;   /* allocator_type(): an empty object, copied uninitialized */
    seStlTreeNode_t  *head;

    tree.proxy = allocator.value;
    head = stl_map44_buynode_m(&tree);
    tree.head = head;
    SE_SETNODE(head)->isnil = 1;   /* head->_Isnil = 1 (44-byte node) */
    tree.head->parent = tree.head;
    tree.head->left   = tree.head;
    tree.head->right  = tree.head;
    tree.size = 0;
  }
  ~SeStrSetLocal()
  {
    seStlTreeNode_t *erased;
    seStlIter_t      first;
    seStlIter_t      last;

    first.ptr = tree.head->left;   /* erase(begin(), end()) */
    last.ptr  = tree.head;
    stl_map44_erase_range_m(&tree, &erased, first, last);
    operator delete(tree.head);
    tree.head = 0;
    tree.size = 0;
  }
};
#endif
int SE_GetNumLanguages__Fv( void )
{
  FxStlAllocatorTag cat;
  char             *tok;

  /* languages = vector(): destroy the elements, free the block, zero the pointers. */
  if ( seLanguageVector.first )
  {
    stl_vector_destroy_range_impl_m((seStlStr_t *)seLanguageVector.first, (seStlStr_t *)seLanguageVector.last, &seLanguageVector, cat);
    operator delete(seLanguageVector.first);
  }
  seLanguageVector.first = 0;
  seLanguageVector.last  = 0;
  seLanguageVector.end   = 0;

  FxStdString list;   /* a named local: its char buffer gives the frame a /GS cookie */
  SE_CountStrFiles_m(SE_STR(list), "localizedstrings");

  SeStrSetLocal seen;   /* std::set<std::string>: each language once */
  for ( tok = SE_NextSemicolonToken_m(SE_STR(list)); tok; tok = SE_NextSemicolonToken_m(SE_STR(list)) )
  {
    char *lang = ((CStringEdPackage *)TheStringPackage)->ExtractLanguageFromPath(tok);

    if ( !stl_map44_count_m(&seen.tree, SE_TMPSTR(lang)) )
    {
      stl_map44_insert_m(&seen.tree, SE_TMPSTR(lang));
      if ( !_stricmp(lang, "english") )
        stl_vector_insert_at_m(&seLanguageVector, SeStrIter((seStlStr_t *)seLanguageVector.first),
                               SeVectorValueArgument(SE_TMPSTR(lang)));   /* english first */
      else
        stl_vector_push_back_m(&seLanguageVector, SE_TMPSTR(lang));
    }
  }

  return !seLanguageVector.first ? 0 : (int)(seLanguageVector.last - seLanguageVector.first) / (int)sizeof(seStlStr_t);
}

/* ---- SE_GetStrFileName_m  0x004AC6C0 ---- HIGH */
/* Raven's SE_GetLanguageName: the index-th entry of seLanguageVector. */
char *__cdecl SE_GetStrFileName_m(unsigned int index)
{
  seStlStr_t *entry;

  if ( !seLanguageVector.first
    || index >= (unsigned int)((int)(seLanguageVector.last - seLanguageVector.first) / (int)sizeof(seStlStr_t)) )
    return "";   /* 0x00559228 */

  entry = (seStlStr_t *)(seLanguageVector.first + sizeof(seStlStr_t) * index);
  return seStlStr_cstr(entry);
}

/* ---- SE_GetLanguageFilePath_m  0x004AC710 ---- VERIFIED */
char *__cdecl SE_GetLanguageFilePath_m(unsigned int index)
{
  seStlStr_t *entry;

  if ( !seLanguageVector.first
    || index >= (unsigned int)((int)(seLanguageVector.last - seLanguageVector.first) / (int)sizeof(seStlStr_t)) )
    return "";   /* 0x00559228 */

  entry = (seStlStr_t *)(seLanguageVector.first + sizeof(seStlStr_t) * index);
  return va("%s/%s", "localizedstrings", seStlStr_cstr(entry));
}

/* ---- SE_NewLanguage_m  0x004AC780 ---- VERIFIED */
int SE_NewLanguage_m(void)
{
  return Clear__16CStringEdPackageFi(SePackageRefArgument(&TheStringPackage), 1);
}

/* ---- SE_Init_m  0x004AC790 ---- VERIFIED */
int SE_Init_m(void)
{
  return Clear__16CStringEdPackageFi(SePackageRefArgument(&TheStringPackage), 0);
}

/* ---- SE_ShutDown_m  0x004AC7A0 ---- VERIFIED */
int SE_ShutDown_m(void)
{
  return Clear__16CStringEdPackageFi(SePackageRefArgument(&TheStringPackage), 0);
}

/* ---- SE_LoadAllLanguageFiles_m  0x004AC7B0 ----  IMPLEMENTED (retail) */
/*
 * Loads every .str file (plus its optional .ste companion) found recursively
 * under "localizedstrings" whose immediate parent directory _stricmp-matches
 * languageName into TheStringPackage, whose strings are cleared first
 * (keeping the FLAGS info).  Stops at the first file that reports an error
 * and returns that error string; returns NULL on success.  A NULL or empty
 * languageName returns NULL at once without clearing (0x4AC7DF/0x4AC7E9).
 * force is handed to SE_LoadStringEditFile_m as its returnReference flag.
 * Nothing is printed.
 */
char *SE_LoadAllLanguageFiles_m( const char *languageName, int force )
{
  char *err = NULL;

  if ( languageName && *languageName )
  {
    char          *tok;

    Clear__16CStringEdPackageFi(SePackageRefArgument(TheStringPackage), 1);   /* SE_NewLanguage */
    FxStdString    list;
    SE_CountStrFiles_m(SE_STR(list), "localizedstrings");
    while ( (tok = SE_NextSemicolonToken_m(SE_STR(list))) != NULL && !err )
    {
      if ( !_stricmp(languageName, ((CStringEdPackage *)TheStringPackage)->ExtractLanguageFromPath(tok)) )
        err = SE_LoadStringEditFile_m(tok, force);   /* retail: tok@<ecx>, force@<ebx> */
    }
  }
  return err;
}

/* ---- stl_string_assign_cstr_m  0x004AC930 ---- MEDIUM */
int __fastcall stl_string_assign_cstr_m(char *src, SeStringReceiver receiver)
{
 seStlStr_t *dst=receiver.receiver;
  return (stl_fxString_assignPtrCount_m(dst, FxConstCharArgument(src), FxCountArgument(strlen(src))));
}

/* ---- stl_string_append_cstr_m  0x004AC950 ----  IMPLEMENTED (retail) */
/*
 * std::string::append(const char *ptr) == append(ptr, strlen(ptr)); returns self.
 * Retail is __thiscall with ptr@<ecx> and the string on the stack, retn 4.
 */
seStlStr_t *__stdcall stl_string_append_cstr_m( seStlStr_t *self, const char *ptr )
{
  return stl_string_append_m(self, ptr, strlen(ptr));
}

/* ---- stl_string_at_m  0x004AC970 ---- MEDIUM */
char *__cdecl stl_string_at_m(seStlStr_t *self, int offset)
{
  /* &data[offset], where data is the SSO buffer or the heap pointer. */
  return seStlStr_cstr(self) + offset;
}

/* ---- stl_string_find_cstr_m  0x004AC990 ---- MEDIUM */
/* std::string::find(ptr, off).  Retail __usercall: needle@<edx>, then (str, startPos), retn 8. */
unsigned int __stdcall stl_string_find_cstr_m(char *needle, seStlStr_t *str, unsigned int startPos)
{
  return stl_string_find_m(startPos, str, needle, strlen(needle));
}

/* ---- stl_map_construct_m  0x004AC9C0 ---- MEDIUM */
seStlTree_t *__cdecl stl_map_construct_m(seStlTree_t *tree)
{
  seStlTree_t     *map = tree;
  seStlTreeNode_t *head;
  FxStlAllocatorTag alloc;   /* the allocator argument: an empty object, copied in uninitialised */

  map->proxy = alloc.value;
  head = stl_map_buynode_str_m(tree);
  map->head = head;
  SE_MAPNODE(head)->isnil = 1;   /* head->_Isnil = 1 (104-byte node) */
  map->head->parent=map->head;
  map->head->left=map->head;
  map->head->right=map->head;
  map->size = 0;
  return tree;
}

/* ---- stl_map_index_m  0x004AC9F0 ---- HIGH */
/*
 * std::map::operator[]: build a {key, mapped_type()} pair on the stack, insert
 * it (a no-op if the key already exists) and return a pointer to the mapped
 * value inside the resident node.  The mapped_type() temporary is one
 * contiguous 0x3C-byte CStringEdString (retail ebp-0xA8: key +0, value +0x1C,
 * flags +0x38) whose address the pair constructor copy-constructs pair.second
 * from; its two strings are freed (capacity >= 0x10) on the way out, value
 * first.
 */
int __stdcall stl_map_index_m(seStlTree_t *tree, seStlStr_t *key)
{
  seStlPairIterBool_t insertResult;      /* pair<iterator,bool>, retail ebp-0x6C */
  seStlTreeNode_t    *valueNode;

  /* insert(value_type(key, mapped_type())).first; both temporaries die at the end of the statement
   * (taking the member address of a class rvalue is a VC7 extension) */
  valueNode = stl_map_insert_m(tree, &insertResult, (seStrMapPair_t *)&SeStrMapPair(*(FxStdString *)key, CStringEdString()))->first;
  return (int)&SE_MAPNODE(valueNode)->myval.second;   /* &node->second (mapped value) */
}

/* ---- stl_map_tidy_m  0x004ACAE0 ---- HIGH */
int __cdecl stl_map_tidy_m(seStlTree_t *tree)
{
  seStlTree_t     *map = tree;
  seStlIter_t      first;
  seStlIter_t      last;
  seStlTreeNode_t *iter;

  first.ptr = map->head->left;
  last.ptr  = map->head;
  stl_map_erase_range_m(tree, &iter, first, last);
  operator delete(map->head);
  map->head = 0;
  map->size = 0;
  return 0;
}

/* ---- stl_map_end_m  0x004ACB10 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map_end_m(seStlTreeNode_t **result, seStlTree_t *tree)
{
  /* end() == the sentinel head node. */
  *result = tree->head;
  return result;
}

/* ---- stl_map_clear_m  0x004ACB20 ---- HIGH */
void __cdecl stl_map_clear_m(seStlTree_t *tree)
{
  seStlTree_t *map = tree;

  stl_tree_erase_all_m(tree, *(seStlIter_t *)&map->head->parent);
  map->head->parent = map->head;   /* _Myhead re-read after every store */
  map->size = 0;
  map->head->left   = map->head;
  map->head->right  = map->head;
}

/* ---- stl_map_find_m  0x004ACB50 ----  IMPLEMENTED (retail) */
/*
 * std::map<std::string, CStringEdString>::find: lower_bound, then end() unless
 * the found node's key is not greater than `key` (i.e. equal).
 * Retail is __usercall: result@<ebx>, tree@<edi>, key@<esi>; returns result.
 */
__declspec(noinline) SeMapIter SeMap::Find( seStlStr_t *key )
{
  seStlTree_t *tree = (seStlTree_t *)this;
  seStlTree_t *map = tree;
  SeMapIter    where( stl_map_lower_bound_m(tree, key) );
  seStlStr_t  *nodeKey;
  unsigned int count;

  /* where == end() || comp(key, _Key(where)) ? end() : where */
  return ( where.node == map->head
           || ( nodeKey = &SE_MAPNODE(where.node)->myval.first, count = nodeKey->size,
                stl_fxString_compare_m(key, key->size, 0, seStlStr_cstr(nodeKey), count) < 0 ) )
         ? SeMapIter(map->head) : where;
}

/* ---- stl_map_iter_eq_m  0x004ACBB0 ---- MEDIUM */
int __cdecl stl_map_iter_eq_m(seStlTreeNode_t **left, seStlTreeNode_t **right)
{
  return *right == *left;
}

/* ---- stl_map_iter_ne_m  0x004ACBC0 ---- MEDIUM */
int __cdecl stl_map_iter_ne_m(seStlTreeNode_t **left, seStlTreeNode_t **right)
{
  return *left != *right;
}

/* ---- stl_map_iter_deref_m  0x004ACBD0 ---- MEDIUM */
seStlStr_t *__cdecl stl_map_iter_deref_m(seStlTreeNode_t **iter)
{
  return &SE_MAPNODE(*iter)->myval.first;   /* *iter: the node's pair, key first */
}

/* ---- stl_vector_construct_m  0x004ACBE0 ---- HIGH */
seStlVec_t *__cdecl stl_vector_construct_m(seStlVec_t *result)
{
  seStlVec_t *vec = result;

  vec->first = 0;
  vec->last  = 0;
  vec->end   = 0;
  return result;
}

/* ---- stl_vector_begin_m  0x004ACC30 ---- MEDIUM */
seStlStr_t **__cdecl stl_vector_begin_m(seStlStr_t **result, seStlVec_t *vector)
{
  *result = (seStlStr_t *)vector->first;
  return result;
}

/* ---- stl_vector_size_m  0x004ACC40 ---- HIGH */
int __cdecl stl_vector_size_m(seStlVec_t *thisPtr)
{
  seStlVec_t *vec = thisPtr;

  return !vec->first ? 0 : (int)(vec->last - vec->first) / (int)sizeof(seStlStr_t);
}

/* ---- stl_vector_at_m  0x004ACC70 ---- MEDIUM */
int __cdecl stl_vector_at_m(int index, seStlVec_t *vector)
{
  seStlVec_t *vec = vector;

  return (int)( vec->first + sizeof(seStlStr_t) * index );
}

/* ---- stl_vector_push_back_m  0x004ACC80 ---- HIGH */
/* vector<std::string>::push_back(val).  Retail: vec@<eax>, val on the stack, retn 4. */
void __stdcall stl_vector_push_back_m( seStlVec_t *vector, seStlStr_t *value )
{
  seStlVec_t *vec = vector;

  if ( (vec->first == 0 ? 0 : (unsigned int)((vec->last - vec->first) / (int)sizeof(seStlStr_t)))
     < (vec->first == 0 ? 0 : (unsigned int)((vec->end - vec->first) / (int)sizeof(seStlStr_t))) )
  {
    /* _Mylast = _Ufill(_Mylast, 1, val) */
    seStlStr_t        *ptr = (seStlStr_t *)vec->last;
    FxStlAllocatorTag  cat;   /* _Ptr_cat: an empty tag object */

    stl_vector_ufill_n_impl_m(ptr, 1, value, vec, cat);
    vec->last = (char *)(ptr + 1);
  }
  else
  {
    stl_vector_insert_at_m(vector, SeStrIter((seStlStr_t *)vec->last), SeVectorValueArgument(value));
  }
}

/* ---- stl_vector_insert_at_m  0x004ACD10 ----  IMPLEMENTED (retail) */
/*
 * std::vector<std::string>::insert(where, val): remembers where's element
 * offset, lets _Insert_n add one copy (which may reallocate), then returns the
 * iterator rebuilt from the new _Myfirst through *result.
 * Retail is __userpurge: vec@<edi>, then (result, where, val), retn 0Ch.
 */
SeStrIter __stdcall stl_vector_insert_at_m( seStlVec_t *vec, SeStrIter where, SeVectorValue valueArgument )
{
  seStlVec_t   *v = (seStlVec_t *)vec;
  unsigned int  offset = ( v->first == 0 ? 0 : (unsigned int)((v->last - v->first) / (int)sizeof(seStlStr_t)) ) == 0
                         ? 0 : (unsigned int)( where.ptr - (seStlStr_t *)v->first );

  ((SeStrVecM *)vec)->InsertN(where, 1, *valueArgument.val);
  return SeStrIter((seStlStr_t *)v->first + offset);
}

/* ---- stl_vector_tidy_m  0x004ACD80 ---- HIGH */
void __cdecl stl_vector_tidy_m(int *vector)
{
  seStlVec_t *vec = (seStlVec_t *)vector;
  FxStlAllocatorTag cat;

  if ( vec->first )
  {
    stl_vector_destroy_range_impl_m((seStlStr_t *)vec->first, (seStlStr_t *)vec->last, vec, cat);
    operator delete(vec->first);
  }
  vec->first = 0;
  vec->last  = 0;
  vec->end   = 0;
}

/* ---- stl_map44_construct_alloccopy_m  0x004ACDC0 ---- HIGH */
seStlTree_t *__cdecl stl_map44_construct_alloccopy_m(seStlTree_t *tree)
{
  seStlTree_t     *map = tree;
  seStlTreeNode_t *head;
  FxStlAllocatorTag alloc;   /* the allocator argument: an empty object, copied in uninitialised */

  map->proxy = alloc.value;
  head = stl_map44_buynode_m(tree);
  map->head = head;
  SE_SETNODE(head)->isnil = 1;   
  map->head->parent=map->head;
  map->head->left=map->head;
  map->head->right=map->head;
  map->size = 0;
  return tree;
}

/* ---- stl_map44_tidy_m  0x004ACDF0 ---- HIGH */
int __cdecl stl_map44_tidy_m(seStlTree_t *tree)
{
  seStlTree_t     *map = tree;
  seStlIter_t      first;
  seStlIter_t      last;
  seStlTreeNode_t *iter;

  first.ptr = map->head->left;
  last.ptr  = map->head;
  stl_map44_erase_range_m(tree, &iter, first, last);
  operator delete(map->head);
  map->head = 0;
  map->size = 0;
  return 0;
}

/* ---- SeStrSet::Insert (stl_map44_insert_m)  0x004ACE20 ----  IMPLEMENTED (retail) */
/*
 * std::set<std::string>::insert(key) for the 44-byte-node tree (key string at
 * node+12, _Isnil at +41).  Descends from the root remembering the last node
 * and which side the key fell to, then either inserts there or reports the
 * equal element already present.  Returns pair<iterator, bool> (iterator at
 * +0, bool at +4) by value, through the hidden result pointer.  Retail is a
 * __stdcall member: (this, result, key), retn 0Ch.
 */
SePairIterBool __stdcall SeStrSet::Insert( seStlStr_t *key )
{
  seStlTree_t     *tree      = (seStlTree_t *)this;
  seStlTree_t     *set       = tree;
  seStlStr_t      *keyStr    = key;
  seStlTreeNode_t *node      = set->head->parent;   /* _Root() */
  seStlTreeNode_t *whereNode = set->head;
  unsigned char    addLeft   = 1;
  seStlTreeNode_t *iter;
  seStlTreeNode_t *inserted;
  int              insertionIterator;
  seStlStr_t      *iterKey;
  unsigned int     keySize;

  while ( !SE_SETNODE(node)->isnil )
  {
    whereNode = node;
    addLeft   = seStlStr_compare(keyStr, &SE_SETNODE(node)->key) < 0;
    node      = ( addLeft ? node->left : node->right );
  }

  iter = whereNode;
  if ( addLeft )
  {
    if ( whereNode == set->head->left )   
    {
      inserted = stl_map44_insert_rebalance_m(tree, whereNode, 1, key).node;
      return SePairIterBool(inserted, 1);
    }
    stl_map44_iter_prev_m(&iter);
  }

  
  keySize = keyStr->size;
  iterKey = &SE_SETNODE(iter)->key;
  if ( stl_fxString_compare_m(iterKey, iterKey->size, 0, seStlStr_cstr(keyStr), keySize) < 0 )
  {
    inserted = stl_map44_insert_rebalance_m(tree, whereNode, addLeft, key).node;
    return SePairIterBool(inserted, 1);
  }
  return SePairIterBool(iter, 0);
}

/* ---- stl_map44_count_m  0x004ACF80 ---- HIGH */
/*
 * set<string>::count(key): _Ans = equal_range(key) (its pair constructor
 * evaluates upper_bound before lower_bound), then _Distance(_Ans.first,
 * _Ans.second).  Retail is tree@<ebx>, key@<eax>.
 */
int __cdecl stl_map44_count_m(seStlTree_t *tree, seStlStr_t *key)
{
  seStlPairIterIter_t ans;
  int count;
  seStlTreeNode_t *iter;

  ans.second = stl_map44_upper_bound_m(tree, key);
  ans.first = stl_map44_lower_bound_m(tree, key);
  count = 0;
  iter = ans.first;
  for ( ; iter != ans.second; stl_map44_iter_next_m(&iter) )
    ++count;
  return count;
}

/* ---- SeStrMapPair::~SeStrMapPair  0x004ACFC0 ----  IMPLEMENTED (retail) */
/*
 * ~pair<const std::string, CStringEdString>: the pair is { key 0x00,
 * CStringEdString 0x1C } (0x58 bytes), and its three strings are released in
 * reverse member order (~second: value, key; then ~first).  Retail is
 * __usercall with pair@<esi> (LTCG's own convention for this).
 */
SeStrMapPair::~SeStrMapPair()
{
}

/* ---- stl_string_append_cstr2_m  0x004AD030 ----  IMPLEMENTED (retail) */
/*
 * Second instantiation of std::string::append(const char *ptr): append(ptr,
 * strlen(ptr)), returning self.  Retail is __thiscall with ptr@<ecx> and the
 * string on the stack, retn 4 -- the same shape as stl_string_append_cstr_m.
 */
seStlStr_t *__stdcall stl_string_append_cstr2_m( seStlStr_t *self, const char *ptr )
{
  return stl_string_append_m(self, ptr, strlen(ptr));
}

/* ---- stl_string_find_m  0x004AD050 ---- HIGH */
/* std::string::find(needle, startPos, needleLen), in its Dinkumware text. */
unsigned int __stdcall stl_string_find_m( unsigned int startPos, seStlStr_t *self, char *needle, unsigned int needleLen )
{
  seStlStr_t   *str = self;
  unsigned int  nm;
  const char   *uptr;
  const char   *vptr;

  if ( needleLen == 0 && startPos <= str->size )
    return startPos;   /* null string always matches (if inside string) */

  if ( startPos < str->size && needleLen <= (nm = str->size - startPos) )
  {
    /* room for match, look for it */
    for ( nm -= needleLen - 1, vptr = seStlStr_cstr(str) + startPos;
          (uptr = (const char *)memchr(vptr, *needle, nm)) != 0;
          nm -= uptr - vptr + 1, vptr = uptr + 1 )
      if ( memcmp(uptr, needle, needleLen) == 0 )
        return uptr - seStlStr_cstr(str);   /* found a match */
  }

  return (unsigned int)-1;   /* no match */
}

/* ---- stl_map_node_key_m  0x004AD120 ---- MEDIUM */
seStlStr_t *__cdecl stl_map_node_key_m(seStrMapNode_t *node)
{
  return &node->myval.first;
}

/* ---- stl_map_node_myval_m  0x004AD130 ---- MEDIUM */
seStlStr_t *__cdecl stl_map_node_myval_m(seStrMapNode_t *node)
{
  return &node->myval.first;   /* _Myval: the pair, key first */
}

/* ---- stl_map_construct_alloc_m  0x004AD140 ---- HIGH */
seStlTree_t *__fastcall stl_map_construct_alloc_m(FxStlAllocatorTag *allocator, seStlTree_t *tree, SeMapAllocatorReference allocatorReference)
{
  seStlTree_t     *map = tree;
  seStlTreeNode_t *head;

  map->proxy = allocator->value;
  head = stl_map_buynode_str_m(tree);
  map->head = head;
  SE_MAPNODE(head)->isnil = 1;   
  map->head->parent=map->head;
  map->head->left=map->head;
  map->head->right=map->head;
  map->size = 0;
  return tree;
}

/* ---- stl_map_insert_m  0x004AD170 ----  IMPLEMENTED (retail) */
/*
 * std::map<std::string, CStringEdString>::insert(pair) for the 104-byte-node
 * tree (key string at node+12, _Isnil at +101): the same descent as
 * stl_map44_insert_m, keyed on pair.first.  Writes pair<iterator, bool> to `result`
 * (iterator at +0, bool at +4) and returns it.  Retail is __stdcall, retn 0Ch.
 */
seStlPairIterBool_t *__stdcall stl_map_insert_m( seStlTree_t *tree, seStlPairIterBool_t *result, seStrMapPair_t *pair )
{
  seStlTree_t     *map       = tree;
  seStlStr_t      *keyStr    = &pair->first;   
  seStlTreeNode_t *node      = map->head->parent;   /* _Root() */
  seStlTreeNode_t *whereNode = map->head;
  unsigned char    addLeft   = 1;
  seStlTreeNode_t *iter;
  seStlTreeNode_t *inserted;
  int              insertionIterator;
  seStlStr_t      *iterKey;
  unsigned int     keySize;

  while ( !SE_MAPNODE(node)->isnil )
  {
    whereNode = node;
    addLeft   = seStlStr_compare(keyStr, &SE_MAPNODE(node)->myval.first) < 0;
    node      = ( addLeft ? node->left : node->right );
  }

  iter = whereNode;
  if ( addLeft )
  {
    if ( whereNode == map->head->left )   
    {
      inserted = stl_map_insert_rebalance_m(tree, whereNode, 1, pair).node;
      result->first  = inserted;
      result->second = 1;
      return result;
    }
    stl_map_iter_prev_m(&iter);
  }

  
  keySize = keyStr->size;
  iterKey = &SE_MAPNODE(iter)->myval.first;
  if ( stl_fxString_compare_m(iterKey, iterKey->size, 0, seStlStr_cstr(keyStr), keySize) < 0 )
  {
    inserted = stl_map_insert_rebalance_m(tree, whereNode, addLeft, pair).node;
    result->first  = inserted;
    result->second = 1;
    return result;
  }
  result->first  = iter;
  result->second = 0;
  return result;
}

/* ---- stl_map_lower_bound_iter_m  0x004AD2D0 ---- */
seStlTreeNode_t **__cdecl stl_map_lower_bound_iter_m(seStlTree_t *tree, seStlStr_t *key, seStlTreeNode_t **result)
{
  *result = stl_map_lower_bound_m(tree, key);
  return result;
}

/* ---- stl_tree_erase_all_m  0x004AD2E0 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Erase(node) for the 104-byte-node map: recurses into each right
 * subtree, walks the left spine iteratively, destroying each node's pair and
 * freeing it.  Retail is __thiscall (tree@<ecx>, node on the stack, retn 4):
 * the tree is only handed on to the recursive call.  __fastcall with the node
 * as a one-pointer struct gives that convention (the struct stays on the stack).
 */
void __fastcall stl_tree_erase_all_m( seStlTree_t *tree, seStlIter_t node )
{
  seStlTreeNode_t *cur;
  seStlIter_t      right;

  /* _Rootnode is the parameter itself, advanced in place (Dinkumware text). */
  for ( cur = node.ptr; !SE_MAPNODE(cur)->isnil; node.ptr = cur )
  {
    right.ptr = cur->right;
    stl_tree_erase_all_m(tree, right);
    cur = cur->left;
    stl_map_node_destroy_m(SE_MAPNODE(node.ptr));
    operator delete(node.ptr);
  }
}

/* ---- stl_map_lmost_m  0x004AD320 ---- */
seStlTreeNode_t **__cdecl stl_map_lmost_m(seStlTree_t *tree)
{
  return &tree->head->left;     /* _Lmost(): reference to head->_Left */
}

/* ---- stl_map_rmost_m  0x004AD330 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map_rmost_m(seStlTree_t *tree)
{
  return &tree->head->right;    /* _Rmost(): reference to head->_Right */
}

/* ---- stl_map_root_m  0x004AD340 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map_root_m(seStlTree_t *tree)
{
  return &tree->head->parent;   /* _Root(): reference to head->_Parent */
}

/* ---- stl_map_tidy_dup_m  0x004AD350 ---- MEDIUM */
int __cdecl stl_map_tidy_dup_m(seStlTree_t *tree)
{
  seStlTree_t     *map = tree;
  seStlIter_t      first;
  seStlIter_t      last;
  seStlTreeNode_t *iter;

  first.ptr = map->head->left;
  last.ptr  = map->head;
  stl_map_erase_range_m(tree, &iter, first, last);
  operator delete(map->head);
  map->head = 0;
  map->size = 0;
  return 0;
}

/* ---- stl_alloc_pair_ctor_m  0x004AD380 ---- HIGH */
void stl_alloc_pair_ctor_m()
{
  ;
}

/* ---- SeStrMapPair::SeStrMapPair(key, mapped)  0x004AD390 ---- HIGH */
/* pair(const std::string &key, const CStringEdString &mapped), stl_map_index_m's value_type. */
SeStrMapPair::SeStrMapPair( const FxStdString &key, const CStringEdString &mapped ) : first( key ), second( mapped )
{
}

/* ---- stl_alloc_str_ctor_m  0x004AD400 ---- HIGH */
void stl_alloc_str_ctor_m()
{
  ;
}

/* ---- stl_map_iter_mynode_m  0x004AD410 ---- MEDIUM */
seStlTreeNode_t *__cdecl stl_map_iter_mynode_m(seStlTreeNode_t **iter)
{
  return *iter;
}

/* ---- stl_map_iter_construct_m  0x004AD420 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map_iter_construct_m(seStlTreeNode_t **result, seStlTreeNode_t *node)
{
  *result = node;
  return result;
}

/* ---- stl_vector_capacity_m  0x004AD430 ---- HIGH */
int __cdecl stl_vector_capacity_m(seStlVec_t *thisPtr)
{
  seStlVec_t *vec = thisPtr;

  return !vec->first ? 0 : (int)(vec->end - vec->first) / (int)sizeof(seStlStr_t);
}

/* ---- stl_vector_end_m  0x004AD460 ---- HIGH */
seStlStr_t **__cdecl stl_vector_end_m(seStlStr_t **result, seStlVec_t *vector)
{
  *result = (seStlStr_t *)vector->last;
  return result;
}

/* ---- stl_vector_buy_m  0x004AD470 ----  IMPLEMENTED (retail) */
/*
 * std::vector<std::string>::_Buy(count): clear the three pointers, then
 * allocate room for `count` elements (none for 0; _Xlen past max_size(),
 * 0x9249249).  Returns false only for count == 0.  Retail is __usercall with
 * count@<eax> and vec@<esi>; operator new is the file's malloc.
 */
char __cdecl stl_vector_buy_m( seStlVec_t *vec, unsigned int count )
{
  seStlVec_t *v = vec;
  char       *first;

  v->first = 0;
  v->last  = 0;
  v->end   = 0;
  if ( !count )
    return 0;

  if ( count > 0x9249249 )
  {
    stl_vector_xlen_m(vec);
    return 1;
  }

  first = (char *)crt_operator_new(sizeof(seStlStr_t) * count);
  v->first = first;
  v->last  = first;
  v->end   = first + sizeof(seStlStr_t) * count;
  return 1;
}

/* ---- stl_vector_tidy_dup_m  0x004AD4C0 ---- MEDIUM */
void __cdecl stl_vector_tidy_dup_m(int *vector)
{
  seStlVec_t *vec = (seStlVec_t *)vector;
  FxStlAllocatorTag cat;

  if ( vec->first )
  {
    stl_vector_destroy_range_impl_m((seStlStr_t *)vec->first, (seStlStr_t *)vec->last, vec, cat);
    operator delete(vec->first);
  }
  vec->first = 0;
  vec->last  = 0;
  vec->end   = 0;
}

/* ---- SeStrVecM::InsertN (stl_vector_insert_n_m)  0x004AD500 ----  IMPLEMENTED (retail) */
/*
 * std::vector<std::string>::_Insert_n(where, count, val), the engine behind
 * insert/push_back.  val is copied first because it may live in the vector.
 * Three cases: reallocate (grow capacity by half, at least to size() + count),
 * the new elements spill past _Mylast, or they all fit inside the existing
 * elements.  Retail is __stdcall, retn 10h.  The two _TRY/_CATCH_ALL blocks
 * (destroy the partial copy, free, rethrow) follow Dinkumware; the iterators
 * are SeStrIter class objects, copy-constructed in their argument slots as
 * retail's _Ptrit; operator new is the file's malloc.
 * The copies and fills go through the vector's _Ucopy (stl_vector_ucopy_wrap2_m)
 * and _Ufill (stl_vector_ufill_n_m) members, as in Dinkumware; LTCG inlines
 * them in the reallocation case.
 */
void __stdcall SeStrVecM::InsertN( SeStrIter position, unsigned int count, const seStlStr_t &element )
{
  seStlVec_t        *v = (seStlVec_t *)this;
  FxStdString        tmp( *(const FxStdString *)&element );   /* in case val is in the sequence */
  unsigned int       capacity = (v->first == 0 ? 0 : (unsigned int)((v->end - v->first) / (int)sizeof(seStlStr_t)));
  FxStlAllocatorTag  cat;   /* _Ptr_cat: an empty tag object */

  if ( count == 0 )
    ;
  else if ( 0x9249249 - (v->first == 0 ? 0 : (unsigned int)((v->last - v->first) / (int)sizeof(seStlStr_t))) < count )   /* max_size() - size() < count */
    stl_vector_xlen_m(v);
  else if ( capacity < (v->first == 0 ? 0 : (unsigned int)((v->last - v->first) / (int)sizeof(seStlStr_t))) + count )
  {
    /* not enough room, reallocate */
    seStlStr_t *newvec;
    seStlStr_t *ptr;

    capacity = 0x9249249 - capacity / 2 < capacity ? 0 : capacity + capacity / 2;   /* grow by 50% if possible */
    if ( capacity < (v->first == 0 ? 0 : (unsigned int)((v->last - v->first) / (int)sizeof(seStlStr_t))) + count )
      capacity = stl_vector_size_m(v) + count;
    newvec = (seStlStr_t *)crt_operator_new(capacity * sizeof(seStlStr_t));
    ptr = newvec;
    try
    {
      ptr = stl_vector_ucopy_wrap2_m(v, SeStrIter((seStlStr_t *)v->first), position, newvec);   /* copy prefix */
      stl_vector_ufill_n_m(v, ptr, count, (seStlStr_t *)&tmp);                      /* add new stuff */
      ptr += count;
      stl_vector_ucopy_wrap2_m(v, position, SeStrIter((seStlStr_t *)v->last), ptr);            /* copy suffix */
    }
    catch ( ... )
    {
      Destroy(newvec, ptr);
      operator delete(newvec);
      throw;
    }
    count += (v->first == 0 ? 0 : (unsigned int)((v->last - v->first) / (int)sizeof(seStlStr_t)));
    if ( v->first != 0 )
    {
      /* destroy and deallocate old array */
      stl_vector_destroy_range_impl_m((seStlStr_t *)v->first, (seStlStr_t *)v->last, v, cat);
      operator delete(v->first);
    }
    v->end = (char *)(newvec + capacity);
    v->last = (char *)(newvec + count);
    v->first = (char *)newvec;
  }
  else if ( (unsigned int)(SeStrIter((seStlStr_t *)v->last) - position) < count )
  {
    /* new stuff spills off end */
    stl_vector_ucopy_wrap2_m(v, position, SeStrIter((seStlStr_t *)v->last), (position + count).ptr);   /* copy suffix */
    try
    {
      stl_vector_ufill_n_m(v, (seStlStr_t *)v->last, count - (SeStrIter((seStlStr_t *)v->last) - position),
                                (seStlStr_t *)&tmp);   /* insert new stuff off end */
    }
    catch ( ... )
    {
      Destroy((position + count).ptr, (seStlStr_t *)v->last + count);
      throw;
    }
    v->last = (char *)((seStlStr_t *)v->last + count);
    stl_vector_ufill_range_m(position, SeStrIter((seStlStr_t *)v->last) - count, (seStlStr_t *)&tmp);   /* insert up to old end */
  }
  else
  {
    /* new stuff can all be assigned */
    SeStrIter oldend( (seStlStr_t *)v->last );

    v->last = (char *)stl_vector_ucopy_wrap2_m(v, oldend - count, oldend, (seStlStr_t *)v->last);   /* copy suffix */
    stl_vector_ucopy_backward_wrap_m(position, oldend - count, oldend);   /* copy hole */
    stl_vector_ufill_range_m(position, position + count, (seStlStr_t *)&tmp);    /* insert into hole */
  }
}

/* ---- stl_vector_ufill_n_m  0x004AD8B0 ---- HIGH */
/* vector<std::string>::_Ufill(ptr, count, val): _Uninitialized_fill_n(ptr, count, val,
 * _Alval), returning ptr + count.  Retail: ptr@<edi>, count@<esi>, val@<edx>, the
 * vector (allocator) @<ecx>. */
seStlStr_t *__cdecl stl_vector_ufill_n_m( void *vec, seStlStr_t *ptr, unsigned int count, seStlStr_t *val )
{
  FxStlAllocatorTag cat;   /* _Ptr_cat: an empty tag object */

  stl_vector_ufill_n_impl_m(ptr, count, val, vec, cat);
  return ptr + count;
}

/* ---- stl_vector_val_construct_m  0x004AD8D0 ---- HIGH */
void __stdcall stl_vector_val_construct_m(int allocator)
{
  ;
}

/* ---- SeStrIter::SeStrIter(pointer) (stl_vector_iter_construct_m)  0x004AD8E0 ---- MEDIUM */
/* vector<std::string>::iterator(ptr) and its copy constructor, out of line here at
 * their retail addresses (LTCG inlines them everywhere). */
SeStrIter::SeStrIter( seStlStr_t *p ) : ptr( p )
{
}

/* ---- SeStrIter::SeStrIter(const SeStrIter &) (stl_vector_iter_construct_copy_m)  0x004AD8F0 ---- MEDIUM */
SeStrIter::SeStrIter( const SeStrIter &other ) : ptr( other.ptr )
{
}

/* ---- stl_vector_iter_deref_m  0x004AD900 ---- MEDIUM */
seStlStr_t *__cdecl stl_vector_iter_deref_m(seStlStr_t **iter)
{
  return *iter;
}

/* ---- SeStrIter::operator+ (stl_vector_iter_add_m)  0x004AD910 ---- HIGH */
/* vector<std::string>::iterator + offset (advance offset elements), returned by value. */
SeStrIter SeStrIter::operator+( int offset ) const
{
  return SeStrIter( ptr + offset );
}

/* ---- SeStrIter::operator-(iterator) (stl_vector_iter_diff_m)  0x004AD920 ---- HIGH */
/* iterator - iterator: the element distance (a signed divide by 0x1C, as retail). */
int SeStrIter::operator-( const SeStrIter &right ) const
{
  return (int)( ptr - right.ptr );
}

/* ---- stl_map44_node_isnil_m  0x004AD940 ---- HIGH */
unsigned char *__cdecl stl_map44_node_isnil_m(seStrSetNode_t *node)
{
  return &node->isnil;
}

/* ---- stl_map44_node_key_m  0x004AD950 ---- MEDIUM */
seStlStr_t *__cdecl stl_map44_node_key_m(seStrSetNode_t *node)
{
  return &node->key;
}

/* ---- stl_map44_node_left_m  0x004AD960 ---- HIGH */
void stl_map44_node_left_m()
{
  ;
}

/* ---- stl_map44_node_right_m  0x004AD970 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_node_right_m(seStrSetNode_t *node)
{
  return &node->right;
}

/* ---- stl_map44_construct_alloc_m  0x004AD980 ---- HIGH */
seStlTree_t *__fastcall stl_map44_construct_alloc_m(FxStlAllocatorTag *allocator, seStlTree_t *tree, SeMapAllocatorReference allocatorReference)
{
  seStlTree_t     *map = tree;
  seStlTreeNode_t *head;

  map->proxy = allocator->value;
  head = stl_map44_buynode_m(tree);
  map->head = head;
  SE_SETNODE(head)->isnil = 1;   
  map->head->parent=map->head;
  map->head->left=map->head;
  map->head->right=map->head;
  map->size = 0;
  return tree;
}

/* ---- stl_map44_begin_m  0x004AD9B0 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_begin_m(seStlTreeNode_t **result, seStlTree_t *tree)
{
  *result = tree->head->left;   /* begin() == _Lmost() */
  return result;
}

/* ---- stl_map44_equal_range_m  0x004AD9C0 ---- HIGH */
seStlTreeNode_t **__cdecl stl_map44_equal_range_m(seStlTree_t *tree, seStlStr_t *key, seStlTreeNode_t **result)
{
  seStlTreeNode_t *upperBound;

  upperBound = stl_map44_upper_bound_m(tree, key);
  result[0] = stl_map44_lower_bound_m(tree, key);   /* pair.first  = lower bound */
  result[1] = upperBound;                             /* pair.second = upper bound */
  return result;
}

/* ---- stl_map44_insert_rebalance_m  0x004AD9E0 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Insert(addLeft, whereNode, key) for the 44-byte-node set: buys a
 * red node under whereNode, links it (updating the head's leftmost/rightmost
 * links), then restores the red-black invariants with the textbook recolour /
 * rotate loop.  _Color lives at +40 (0 red, 1 black).  Writes the new node's
 * iterator to *result and returns result.
 * Retail is __userpurge: whereNode@<ecx>, tree@<edi>, then (result, addLeft,
 * key), retn 0Ch.  Too many elements throws length_error("map/set<T> too
 * long") (std::length_error).  The body follows <xtree>'s _Insert, re-reading
 * _Myhead for every _Root()/_Lmost()/_Rmost() as retail does.
 */
#define SE_NODE44_COLOR( n )  ( SE_SETNODE(n)->color )
#define SE_NODE_PARENT( n )   ( ((seStlTreeNode_t *)(n))->parent )

SeMapIter __stdcall stl_map44_insert_rebalance_m( seStlTree_t *tree, seStlTreeNode_t *whereNode, char addLeft, seStlStr_t *key )
{
  seStlTree_t     *set = tree;
  seStlTreeNode_t *where = whereNode;
  seStlTreeNode_t *newNode;
  seStlTreeNode_t *node;

  if ( set->size >= 0x9249248 )   /* max_size() - 1 <= size() */
    throw std::length_error( FxStdString("map/set<T> too long") );
  newNode = stl_map44_buynode_init_m(tree, set->head, where, set->head, key, 0 /* red */);

  ++set->size;
  if ( where == set->head )
  {
    /* first node in tree, just set head values: _Root(), _Lmost(), _Rmost() */
    set->head->parent = newNode;
    set->head->left   = newNode;
    set->head->right  = newNode;
  }
  else if ( addLeft )
  {
    /* add to left of where */
    where->left = newNode;
    if ( where == set->head->left )
      set->head->left = newNode;
  }
  else
  {
    /* add to right of where */
    where->right = newNode;
    if ( where == set->head->right )
      set->head->right = newNode;
  }

  for ( node = newNode; SE_NODE44_COLOR(SE_NODE_PARENT(node)) == 0; )
    if ( SE_NODE_PARENT(node) == SE_NODE_PARENT(SE_NODE_PARENT(node))->left )
    {
      /* fixup red-red in left subtree */
      where = SE_NODE_PARENT(SE_NODE_PARENT(node))->right;
      if ( SE_NODE44_COLOR(where) == 0 )
      {
        /* parent has two red children, blacken both */
        SE_NODE44_COLOR(SE_NODE_PARENT(node)) = 1;
        SE_NODE44_COLOR(where) = 1;
        SE_NODE44_COLOR(SE_NODE_PARENT(SE_NODE_PARENT(node))) = 0;
        node = SE_NODE_PARENT(SE_NODE_PARENT(node));
      }
      else
      {
        /* parent has red and black children */
        if ( node == SE_NODE_PARENT(node)->right )
        {
          /* rotate right child to left */
          node = SE_NODE_PARENT(node);
          stl_map44_lrotate_m(node, tree);
        }
        SE_NODE44_COLOR(SE_NODE_PARENT(node)) = 1;   /* propagate red up */
        SE_NODE44_COLOR(SE_NODE_PARENT(SE_NODE_PARENT(node))) = 0;
        stl_map44_rrotate_m(SE_NODE_PARENT(SE_NODE_PARENT(node)), tree);
      }
    }
    else
    {
      /* fixup red-red in right subtree */
      where = SE_NODE_PARENT(SE_NODE_PARENT(node))->left;
      if ( SE_NODE44_COLOR(where) == 0 )
      {
        /* parent has two red children, blacken both */
        SE_NODE44_COLOR(SE_NODE_PARENT(node)) = 1;
        SE_NODE44_COLOR(where) = 1;
        SE_NODE44_COLOR(SE_NODE_PARENT(SE_NODE_PARENT(node))) = 0;
        node = SE_NODE_PARENT(SE_NODE_PARENT(node));
      }
      else
      {
        /* parent has red and black children */
        if ( node == SE_NODE_PARENT(node)->left )
        {
          /* rotate left child to right */
          node = SE_NODE_PARENT(node);
          stl_map44_rrotate_m(node, tree);
        }
        SE_NODE44_COLOR(SE_NODE_PARENT(node)) = 1;   /* propagate red up */
        SE_NODE44_COLOR(SE_NODE_PARENT(SE_NODE_PARENT(node))) = 0;
        stl_map44_lrotate_m(SE_NODE_PARENT(SE_NODE_PARENT(node)), tree);
      }
    }

  SE_NODE44_COLOR(set->head->parent) = 1;   /* root is always black */
  return SeMapIter(newNode);
}

#undef SE_NODE44_COLOR
#undef SE_NODE_PARENT

/* ---- stl_map44_root_m  0x004ADBB0 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_root_m(seStlTree_t *tree)
{
  return &tree->head->parent;   /* _Root(): reference to head->_Parent */
}

/* ---- stl_map44_tidy_dup_m  0x004ADBC0 ---- MEDIUM */
int __cdecl stl_map44_tidy_dup_m(seStlTree_t *tree)
{
  seStlTree_t     *map = tree;
  seStlIter_t      first;
  seStlIter_t      last;
  seStlTreeNode_t *iter;

  first.ptr = map->head->left;
  last.ptr  = map->head;
  stl_map44_erase_range_m(tree, &iter, first, last);
  operator delete(map->head);
  map->head = 0;
  map->size = 0;
  return 0;
}

/* ---- stl_map44_kfn_m  0x004ADBF0 ---- HIGH */
void stl_map44_kfn_m()
{
  ;
}

/* ---- stl_map44_iter_eq_m  0x004ADC00 ---- MEDIUM */
int __cdecl stl_map44_iter_eq_m(seStlTreeNode_t **left, seStlTreeNode_t **right)
{
  return *right == *left;
}

/* ---- stl_map44_iter_mynode_m  0x004ADC10 ---- MEDIUM */
seStlTreeNode_t *__cdecl stl_map44_iter_mynode_m(seStlTreeNode_t **iter)
{
  return *iter;
}

/* ---- stl_map44_iter_construct_m  0x004ADC20 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_iter_construct_m(seStlTreeNode_t **result, seStlTreeNode_t *node)
{
  *result = node;
  return result;
}

/* ---- stl_map44_iter_prev_wrap_m  0x004ADC30 ---- HIGH */
seStlTreeNode_t **__cdecl stl_map44_iter_prev_wrap_m(seStlTreeNode_t **iter)
{
  stl_map44_iter_prev_m(iter);
  return iter;
}

/* ---- stl_pair_iter_bool_m  0x004ADC40 ---- HIGH */
seStlPairIterBool_t *__stdcall stl_pair_iter_bool_m(seStlPairIterBool_t *result, seStlTreeNode_t **iter, char *inserted)
{
  result->first  = *iter;       /* pair.first  = iterator */
  result->second = *inserted;   /* pair.second = bool     */
  return result;
}

/* ---- CStringEdString::CStringEdString(const CStringEdString &)  0x004ADC50 ---- HIGH */
CStringEdString::CStringEdString( const CStringEdString &other ) : key( other.key ), value( other.value ), flags( other.flags )
{
}

/* ---- stl_string_append_m  0x004ADCC0 ----  IMPLEMENTED (retail) */
/*
 * std::string::append(const char *ptr, size_type count); returns self.  A ptr
 * that points into this string's own characters is appended through
 * append(*this, ptr - data, count), which re-reads the source after any
 * reallocation.  Otherwise _Grow(size + count) and copy.  The two _Xlen
 * throws are std::_String_base::_Xlen (length_error "string too long").
 * Retail is __usercall: count@<eax>, self@<edx>, ptr@<ecx>.
 */
seStlStr_t *__cdecl stl_string_append_m( seStlStr_t *self, const char *ptr, unsigned int count )
{
  FxString     *str = (FxString *)self;
  unsigned int  num;

  if ( SE_FXPTR( str ) <= ptr && ptr < SE_FXPTR( str ) + str->size )   /* _Inside(ptr) */
    return stl_string_replace_m(self, self, (unsigned int)(ptr - SE_FXPTR( str )), count);   /* substring */
  if ( 0xFFFFFFFFu - str->size <= count )    /* npos - _Mysize <= count */
    ( (const std::_String_base *)str )->_Xlen();   /* result too long */
  if ( 0 < count && str->Grow( num = str->size + count, false ) )
  {
    /* make room and append new stuff */
    memcpy(SE_FXPTR( str ) + str->size, ptr, count);
    str->size = num;   /* _Eos(num) */
    SE_FXPTR( str )[num] = 0;
  }
  return self;
}

/* ---- stl_map_node_isnil_m  0x004ADDC0 ---- HIGH */
unsigned char *__cdecl stl_map_node_isnil_m(seStrMapNode_t *node)
{
  return &node->isnil;
}

/* ---- stl_map_node_left_m  0x004ADDD0 ---- HIGH */
void stl_map_node_left_m()
{
  ;
}

/* ---- stl_map_node_parent_m  0x004ADDE0 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map_node_parent_m(seStrMapNode_t *node)
{
  return &node->parent;
}

/* ---- stl_map_node_right_m  0x004ADDF0 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map_node_right_m(seStrMapNode_t *node)
{
  return &node->right;
}

/* ---- stl_map_begin_m  0x004ADE00 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map_begin_m(seStlTreeNode_t **result, seStlTree_t *tree)
{
  *result = tree->head->left;   /* begin() == _Lmost() */
  return result;
}

/* ---- stl_map_erase_range_m  0x004ADE10 ----  IMPLEMENTED (retail) */
/*
 * std::map<std::string, CStringEdString>::erase(first, last).  The whole
 * range [begin(), end()) is dropped with one _Erase(root) and the head is
 * reset (clear()); otherwise the nodes are erased one by one.  Writes the
 * iterator after the range (last, or begin() of the emptied map) to *result
 * and returns result.
 * Retail is __userpurge: tree@<esi>, then (result, first, last), retn 0Ch.
 */
seStlTreeNode_t **__stdcall stl_map_erase_range_m( seStlTree_t *tree, seStlTreeNode_t **result, seStlIter_t first, seStlIter_t last )
{
  seStlTree_t     *map  = tree;
  seStlTreeNode_t *head = map->head;
  seStlTreeNode_t *node;
  seStlTreeNode_t *erased;   /* erase(where)'s returned iterator; retail aims it at the dead result slot */

  if ( first.ptr == head->left && last.ptr == head )
  {
    stl_tree_erase_all_m(tree, *(seStlIter_t *)&head->parent);
    map->head->parent = map->head;   /* _Myhead re-read after every store */
    map->size = 0;
    map->head->left   = map->head;
    map->head->right  = map->head;
    *result = map->head->left;
    return result;
  }

  while ( first.ptr != last.ptr )
  {
    node = first.ptr;
    stl_map_iter_next104_m(&first.ptr);
    stl_map_erase_node_m(tree, &erased, node);
  }
  *result = first.ptr;
  return result;
}

/* ---- stl_map_construct_dup_m  0x004ADE90 ---- MEDIUM */
void __cdecl stl_map_construct_dup_m(seStlTree_t *tree)
{
  seStlTree_t     *map = tree;
  seStlTreeNode_t *head;

  head = stl_map_buynode_str_m(tree);
  map->head = head;
  SE_MAPNODE(head)->isnil = 1;   
  map->head->parent=map->head;
  map->head->left=map->head;
  map->head->right=map->head;
  map->size = 0;

}

/* ---- stl_map_insert_rebalance_m  0x004ADEC0 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Insert(addLeft, whereNode, val) for the 104-byte-node map, the
 * twin of stl_map44_insert_rebalance_m: buys a red node holding a copy of the
 * {key, CStringEdString} pair under whereNode, links it (updating the head's
 * leftmost/rightmost links), then restores the red-black invariants with the
 * recolour / rotate loop.  _Color lives at +100 (0 red, 1 black).  Writes the
 * new node's iterator to *result and returns result.
 * Retail is __userpurge: whereNode@<ecx>, tree@<edi>, then (result, addLeft,
 * val), retn 0Ch.  Too many elements throws length_error("map/set<T> too
 * long") (std::length_error).  The body follows <xtree>'s _Insert.
 */
#define SE_NODE104_COLOR( n )  ( SE_MAPNODE(n)->color )
#define SE_NODE_PARENT( n )    ( ((seStlTreeNode_t *)(n))->parent )

SeMapIter __stdcall stl_map_insert_rebalance_m( seStlTree_t *tree, seStlTreeNode_t *whereNode, char addLeft, seStrMapPair_t *val )
{
  seStlTree_t     *map = tree;
  seStlTreeNode_t *where = whereNode;
  seStlTreeNode_t *newNode;
  seStlTreeNode_t *node;

  if ( map->size >= 0x2E8BA2D )   /* max_size() - 1 <= size() */
    throw std::length_error( FxStdString("map/set<T> too long") );
  newNode = stl_map_buynode_init_m(tree, map->head, where, map->head, val, 0 /* red */);

  ++map->size;
  if ( where == map->head )
  {
    /* first node in tree, just set head values: _Root(), _Lmost(), _Rmost() */
    map->head->parent = newNode;
    map->head->left   = newNode;
    map->head->right  = newNode;
  }
  else if ( addLeft )
  {
    /* add to left of where */
    where->left = newNode;
    if ( where == map->head->left )
      map->head->left = newNode;
  }
  else
  {
    /* add to right of where */
    where->right = newNode;
    if ( where == map->head->right )
      map->head->right = newNode;
  }

  for ( node = newNode; SE_NODE104_COLOR(SE_NODE_PARENT(node)) == 0; )
    if ( SE_NODE_PARENT(node) == SE_NODE_PARENT(SE_NODE_PARENT(node))->left )
    {
      /* fixup red-red in left subtree */
      where = SE_NODE_PARENT(SE_NODE_PARENT(node))->right;
      if ( SE_NODE104_COLOR(where) == 0 )
      {
        /* parent has two red children, blacken both */
        SE_NODE104_COLOR(SE_NODE_PARENT(node)) = 1;
        SE_NODE104_COLOR(where) = 1;
        SE_NODE104_COLOR(SE_NODE_PARENT(SE_NODE_PARENT(node))) = 0;
        node = SE_NODE_PARENT(SE_NODE_PARENT(node));
      }
      else
      {
        /* parent has red and black children */
        if ( node == SE_NODE_PARENT(node)->right )
        {
          /* rotate right child to left */
          node = SE_NODE_PARENT(node);
          stl_map_lrotate_m(node, tree);
        }
        SE_NODE104_COLOR(SE_NODE_PARENT(node)) = 1;   /* propagate red up */
        SE_NODE104_COLOR(SE_NODE_PARENT(SE_NODE_PARENT(node))) = 0;
        stl_map_rrotate_m(SE_NODE_PARENT(SE_NODE_PARENT(node)), tree);
      }
    }
    else
    {
      /* fixup red-red in right subtree */
      where = SE_NODE_PARENT(SE_NODE_PARENT(node))->left;
      if ( SE_NODE104_COLOR(where) == 0 )
      {
        /* parent has two red children, blacken both */
        SE_NODE104_COLOR(SE_NODE_PARENT(node)) = 1;
        SE_NODE104_COLOR(where) = 1;
        SE_NODE104_COLOR(SE_NODE_PARENT(SE_NODE_PARENT(node))) = 0;
        node = SE_NODE_PARENT(SE_NODE_PARENT(node));
      }
      else
      {
        /* parent has red and black children */
        if ( node == SE_NODE_PARENT(node)->left )
        {
          /* rotate left child to right */
          node = SE_NODE_PARENT(node);
          stl_map_rrotate_m(node, tree);
        }
        SE_NODE104_COLOR(SE_NODE_PARENT(node)) = 1;   /* propagate red up */
        SE_NODE104_COLOR(SE_NODE_PARENT(SE_NODE_PARENT(node))) = 0;
        stl_map_lrotate_m(SE_NODE_PARENT(SE_NODE_PARENT(node)), tree);
      }
    }

  SE_NODE104_COLOR(map->head->parent) = 1;   /* root is always black */
  return SeMapIter(newNode);
}

#undef SE_NODE104_COLOR
#undef SE_NODE_PARENT

/* ---- stl_map_lower_bound_m  0x004AE090 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Lbound(key) for the 104-byte-node map: the first node whose
 * key is not less than `key`, or the head (end()) when there is none.  The
 * std::less<std::string> test is inlined (see seStlStr_compare).
 * Retail is __usercall: tree@<eax>, key@<ecx>.
 */
seStlTreeNode_t *__cdecl stl_map_lower_bound_m( seStlTree_t *tree, seStlStr_t *key )
{
  seStlTree_t     *map       = tree;
  seStlStr_t      *keyStr    = key;
  seStlTreeNode_t *whereNode = map->head;
  seStlTreeNode_t *node      = whereNode->parent;   /* root */

  while ( !SE_MAPNODE(node)->isnil )
  {
    if ( seStlStr_compare(&SE_MAPNODE(node)->myval.first, keyStr) < 0 )
    {
      node = node->right;   /* node key < key */
    }
    else
    {
      whereNode = node;
      node      = node->left;
    }
  }
  return whereNode;
}

/* ---- stl_map_tree_val_construct_m  0x004AE130 ---- HIGH */
FxStlAllocatorTag *__stdcall stl_map_tree_val_construct_m(FxStlAllocatorTag *result, FxStlAllocatorTag *allocator, int unused)
{
  *result = *allocator;
  return result;
}

/* ---- stl_map_kfn_m  0x004AE140 ---- HIGH */
void stl_map_kfn_m()
{
  ;
}

/* ---- stl_alloc_pair_copy_ctor_m  0x004AE150 ---- HIGH */
void __stdcall stl_alloc_pair_copy_ctor_m(int other)
{
  ;
}

/* ---- stl_alloc_node104_deallocate_m  0x004AE160 ---- HIGH */
void __stdcall stl_alloc_node104_deallocate_m(void *ptr, int count, int unused)
{
  operator delete(ptr);
}

/* ---- stl_map_node_destroy2_m  0x004AE170 ---- HIGH */
void __stdcall stl_map_node_destroy2_m(seStrMapNode_t *node, int unused)
{
  stl_map_node_destroy_m(node);
}

/* ---- stl_alloc_nodeptr104_destroy_m  0x004AE180 ---- HIGH */
void __stdcall stl_alloc_nodeptr104_destroy_m(int ptr, int unused)
{
  ;
}

/* ---- stl_alloc_str_copy_ctor_m  0x004AE190 ---- HIGH */
void __stdcall stl_alloc_str_copy_ctor_m(int other)
{
  ;
}

/* ---- stl_alloc_str_allocate_m  0x004AE1A0 ----  IMPLEMENTED (retail) */
/*
 * std::allocator<std::string>::allocate(count, hint): operator new(count *
 * 0x1C).  No retail caller.  Retail is __userpurge with count@<eax> and two
 * stack words it never reads, retn 8; operator new is the file's malloc.
 */
void *__stdcall stl_alloc_str_allocate_m( unsigned int count, int unused1, int unused2 )
{
  (void)unused1;
  (void)unused2;
  return crt_operator_new(count * sizeof(seStlStr_t));
}

/* ---- stl_alloc_str_deallocate_m  0x004AE1B0 ---- HIGH */
void __stdcall stl_alloc_str_deallocate_m(void *ptr, int count, int unused)
{
  operator delete(ptr);
}

/* ---- stl_map_const_iter_construct_m  0x004AE1C0 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map_const_iter_construct_m(seStlTreeNode_t **result, seStlTreeNode_t *node)
{
  *result = node;
  return result;
}

/* ---- stl_map_iter_prev_wrap_m  0x004AE1D0 ---- HIGH */
seStlTreeNode_t **__cdecl stl_map_iter_prev_wrap_m(seStlTreeNode_t **iter)
{
  stl_map_iter_prev_m(iter);
  return iter;
}

/* ---- stl_alloc_str_max_size_m  0x004AE1E0 ---- HIGH */
int __stdcall stl_alloc_str_max_size_m(int unused)
{
  return 153391689;
}

/* ---- SeStrVecM::Destroy (stl_vector_destroy_range_m)  0x004AE1F0 ---- HIGH */
/* vector<std::string>::_Destroy(first, last), a member: _Destroy_range(first, last, _Alval) with
 * the (empty) pointer category.  Retail: first on the stack (retn 4), last@<edi>, the
 * vector (whose allocator is its first member) @<ecx>. */
void SeStrVecM::Destroy( seStlStr_t *first, seStlStr_t *last )
{
  FxStlAllocatorTag cat;

  stl_vector_destroy_range_impl_m(first, last, this, cat);
}

/* ---- stl_vector_xlen_m  0x004AE210 ----  IMPLEMENTED (retail) */
/*
 * std::vector<std::string>::_Xlen(): throws length_error("vector<T> too
 * long") and never returns.  Both retail callers push the vector first;
 * nothing reads it.  The string temporary gives it its EH frame.  It is never
 * inlined and pops its argument; auto_inline(off) + __stdcall reproduce that.
 */
#pragma auto_inline(off)
void __stdcall stl_vector_xlen_m( seStlVec_t *vec )
{
  (void)vec;
  throw std::length_error( FxStdString("vector<T> too long") );
}
#pragma auto_inline(on)

/* ---- stl_vector_iter_base_m  0x004AE290 ---- MEDIUM */
seStlStr_t *__cdecl stl_vector_iter_base_m(seStlStr_t **iter)
{
  return *iter;
}

/* ---- SeStrIter::operator- (stl_vector_iter_sub_m)  0x004AE2A0 ---- HIGH */
/* vector<std::string>::iterator - offset (retreat offset elements), returned by value. */
SeStrIter SeStrIter::operator-( int offset ) const
{
  return SeStrIter( ptr - offset );
}

/* ---- stl_map_node_mapped_m  0x004AE2B0 ---- HIGH */
CStringEdString_t *__cdecl stl_map_node_mapped_m(seStrMapNode_t *node)
{
  return &node->myval.second;
}

/* ---- stl_map44_node_parent_m  0x004AE2C0 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_node_parent_m(seStrSetNode_t *node)
{
  return &node->parent;
}

/* ---- stl_map44_node_myval_m  0x004AE2D0 ---- MEDIUM */
seStlStr_t *__cdecl stl_map44_node_myval_m(seStrSetNode_t *node)
{
  return &node->key;
}

/* ---- stl_map44_end_m  0x004AE2E0 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_end_m(seStlTreeNode_t **result, seStlTree_t *tree)
{
  *result = tree->head;         /* end() == the sentinel head node */
  return result;
}

/* ---- stl_alloc_str_max_size_dup_m  0x004AE2F0 ---- HIGH */
int __stdcall stl_alloc_str_max_size_dup_m(int unused)
{
  return 153391689;
}

/* ---- stl_map44_erase_range_m  0x004AE300 ----  IMPLEMENTED (retail) */
/*
 * std::set<std::string>::erase(first, last) for the 44-byte-node tree, the
 * twin of stl_map_erase_range_m: [begin(), end()) is dropped with one
 * _Erase(root) and a head reset, anything else node by node.  Writes the
 * iterator after the range to *result and returns result.
 * Retail is __userpurge: tree@<esi>, then (result, first, last), retn 0Ch.
 */
seStlTreeNode_t **__stdcall stl_map44_erase_range_m( seStlTree_t *tree, seStlTreeNode_t **result, seStlIter_t first, seStlIter_t last )
{
  seStlTree_t     *set  = tree;
  seStlTreeNode_t *head = set->head;
  seStlTreeNode_t *node;
  seStlTreeNode_t *erased;   /* erase(where)'s returned iterator; retail aims it at the dead result slot */

  if ( first.ptr == head->left && last.ptr == head )
  {
    stl_map44_erase_all_m(tree, *(seStlIter_t *)&head->parent);
    set->head->parent = set->head;   /* _Myhead re-read after every store */
    set->size = 0;
    set->head->left   = set->head;
    set->head->right  = set->head;
    *result = set->head->left;
    return result;
  }

  while ( first.ptr != last.ptr )
  {
    node = first.ptr;
    stl_map44_iter_next_m(&first.ptr);
    stl_map44_erase_node_m(tree, &erased, node);
  }
  *result = first.ptr;
  return result;
}

/* ---- stl_map44_lower_bound_iter_m  0x004AE380 ---- HIGH */
seStlTreeNode_t **__cdecl stl_map44_lower_bound_iter_m(seStlTree_t *tree, seStlStr_t *key, seStlTreeNode_t **result)
{
  *result = stl_map44_lower_bound_m(tree, key);
  return result;
}

/* ---- stl_map44_upper_bound_iter_m  0x004AE390 ---- HIGH */
seStlTreeNode_t **__stdcall stl_map44_upper_bound_iter_m(seStlStr_t *key, seStlTreeNode_t **result, seStlTree_t *tree)
{
  *result = stl_map44_upper_bound_m(tree, key);
  return result;
}

/* ---- stl_map44_construct_dup_m  0x004AE3B0 ---- MEDIUM */
void __cdecl stl_map44_construct_dup_m(seStlTree_t *tree)
{
  seStlTree_t     *map = tree;
  seStlTreeNode_t *head;

  head = stl_map44_buynode_m(tree);
  map->head = head;
  SE_SETNODE(head)->isnil = 1;   
  map->head->parent=map->head;
  map->head->left=map->head;
  map->head->right=map->head;
  map->size = 0;
}

/* ---- stl_map44_lmost_m  0x004AE3E0 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_lmost_m(seStlTree_t *tree)
{
  return &tree->head->left;     /* _Lmost(): reference to head->_Left */
}

/* ---- stl_map44_lrotate_m  0x004AE3F0 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Lrotate(node) for the 44-byte-node set (_Isnil at +41): the
 * right child is lifted into node's place and node becomes its left child.
 * Returns the lifted node (left in eax by retail).
 * Retail is __thiscall: node@<ecx>, tree on the stack, retn 4.
 */
seStlTreeNode_t *__stdcall stl_map44_lrotate_m( seStlTreeNode_t *node, seStlTree_t *tree )
{
  seStlTreeNode_t *where = node;
  seStlTreeNode_t *pivot = where->right;
  seStlTreeNode_t *head;
  seStlTreeNode_t *parent;

  where->right = pivot->left;
  if ( !SE_SETNODE(pivot->left)->isnil )
    pivot->left->parent = where;
  pivot->parent = where->parent;

  head = tree->head;
  if ( where == head->parent )
  {
    head->parent = pivot;                    /* where was the root */
  }
  else
  {
    parent = where->parent;
    if ( where == parent->left )
      parent->left = pivot;
    else
      parent->right = pivot;
  }
  pivot->left   = where;
  where->parent = pivot;
  return pivot;
}

/* ---- stl_map44_rmost_m  0x004AE450 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_rmost_m(seStlTree_t *tree)
{
  return &tree->head->right;    /* _Rmost(): reference to head->_Right */
}

/* ---- stl_map44_rrotate_m  0x004AE460 ---- HIGH */
seStlTreeNode_t *__stdcall stl_map44_rrotate_m(seStlTreeNode_t *node, seStlTree_t *tree)
{
  seStlTreeNode_t *where = node;
  seStlTreeNode_t *pivot;
  seStlTreeNode_t *pivotRight;
  seStlTreeNode_t *head;
  seStlTreeNode_t *parent;

  pivot = where->left;
  where->left = where->left->right;
  pivotRight = pivot->right;
  if ( !SE_SETNODE(pivotRight)->isnil )
    pivotRight->parent = where;
  pivot->parent = where->parent;
  head = (tree)->head;
  if ( where == head->parent )
  {
    head->parent = pivot;                    /* where was the root */
    pivot->right = where;
    where->parent = pivot;
  }
  else
  {
    parent = where->parent;
    if ( where == parent->right )
      parent->right = pivot;
    else
      parent->left = pivot;
    pivot->right = where;
    where->parent = pivot;
  }
  return pivot;
}

/* ---- stl_map44_buynode_init_m  0x004AE4C0 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Buynode(left, parent, right, key, color) for the 44-byte-node
 * set: operator new(0x2C), then (only when that returned non-NULL) the three
 * links, a copy of the key string at +12, _Color +40 and _Isnil +41 = 0 --
 * stl_map44_node_init_m's work, inlined.  The tree argument (the allocator)
 * is not read.  Retail wraps the construction in try { } catch (...) { free;
 * rethrow; }, which has no counterpart here; operator new is the file's
 * malloc.  Retail is __stdcall, retn 18h.
 */
struct SeMapNode44 {
  seStlTreeNode_t links;
  SeMapNode44( seStlTreeNode_t *left, seStlTreeNode_t *parent, seStlTreeNode_t *right, seStlStr_t *key, char color )
  {
    links.left   = left;
    links.parent = parent;
    links.right  = right;
    ( (SeStrCopy *)&SE_SETNODE(this)->key )->Construct( key );   /* _Myval(key) */
    SE_SETNODE(this)->color = color;   /* _Color */
    SE_SETNODE(this)->isnil = 0;       /* _Isnil */
  }
};
seStlTreeNode_t *__stdcall stl_map44_buynode_init_m( seStlTree_t *tree, seStlTreeNode_t *left, seStlTreeNode_t *parent, seStlTreeNode_t *right, seStlStr_t *key, char color )
{
  seStlTreeNode_t *node;

  (void)tree;

  node = (seStlTreeNode_t *)crt_operator_new(44);
  try
  {
    new ( node ) SeMapNode44( left, parent, right, key, color );
  }
  catch ( ... )
  {
    operator delete( node );
    throw;
  }
  return node;
}

/* ---- stl_map44_tree_val_construct_m  0x004AE570 ---- HIGH */
FxStlAllocatorTag *__stdcall stl_map44_tree_val_construct_m(FxStlAllocatorTag *result, FxStlAllocatorTag *allocator, int unused)
{
  *result = *allocator;
  return result;
}

/* ---- stl_alloc_node44_deallocate_m  0x004AE580 ---- HIGH */
void __stdcall stl_alloc_node44_deallocate_m(void *ptr, int count, int unused)
{
  operator delete(ptr);
}

/* ---- stl_alloc_nodeptr44_destroy_m  0x004AE590 ---- HIGH */
void __stdcall stl_alloc_nodeptr44_destroy_m(int ptr, int unused)
{
  ;
}

/* ---- stl_map44_const_iter_construct_m  0x004AE5A0 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_const_iter_construct_m(seStlTreeNode_t **result, seStlTreeNode_t *node)
{
  *result = node;
  return result;
}

/* ---- stl_map44_iter_prev_m  0x004AE5B0 ----  IMPLEMENTED (retail) */
/*
 * std::set<std::string>::iterator::operator-- (_Dec) for the 44-byte-node
 * tree (_Isnil at +41): end() steps to the rightmost node (head->right), a
 * node with a left subtree to that subtree's maximum, anything else climbs
 * while it is a left child.  The iterator is updated in place; void like
 * Dinkumware's _Dec (no caller reads eax), with _Max's single-pointer loop.
 * Retail is __usercall: iter@<edx>.
 */
#define SE_NODE44_ISNIL( n )  ( SE_SETNODE(n)->isnil )

inline void __cdecl stl_map44_iter_prev_m( seStlTreeNode_t **iter )
{
  seStlTreeNode_t *node = *iter;
  seStlTreeNode_t *parent;

  if ( SE_NODE44_ISNIL(node) )
  {
    *iter = node->right;              /* end() -> rightmost */
    return;
  }

  if ( !SE_NODE44_ISNIL(node->left) )
  {
    /* _Max(_Left(ptr)), inlined */
    node = node->left;
    while ( !SE_NODE44_ISNIL(node->right) )
      node = node->right;
    *iter = node;
    return;
  }

  for ( parent = node->parent;
        !SE_NODE44_ISNIL(parent) && *iter == parent->left;
        parent = parent->parent )
  {
    *iter = parent;
  }
  if ( !SE_NODE44_ISNIL(parent) )
    *iter = parent;
}

#undef SE_NODE44_ISNIL

/* ---- SePairIterBool::SePairIterBool (stl_pair_iter_bool_dup_m)  0x004AE610 ---- */
/* pair<iterator, bool>(const iterator &, const bool &), SeStrSet::Insert's result:
 * first = node, second = inserted.  Retail: this@<eax>, node@<ecx>, inserted on the
 * stack, retn 4. */
SePairIterBool::SePairIterBool( seStlTreeNode_t *const &node, const char &inserted ) : first( node ), second( inserted )
{
}

/* ---- stl_pair_iter_iter_m  0x004AE620 ---- HIGH */
/* Build the std::pair<iterator,iterator> return value: first = *lower, second = *upper. */
seStlPairIterIter_t *__stdcall stl_pair_iter_iter_m(seStlPairIterIter_t *result, seStlTreeNode_t **lower, seStlTreeNode_t **upper)
{
  result->first  = *lower;   /* pair.first  = lower iterator */
  result->second = *upper;   /* pair.second = upper iterator */
  return result;
}

/* ---- stl_string_replace_m  0x004AE630 ----  IMPLEMENTED (retail) */
/*
 * std::string::append(const string &right, size_type roff, size_type count)
 * (the IDB name is historical); returns self.  Its only retail caller is
 * stl_string_append_m appending a piece of the string to itself, which is
 * why right's buffer is only fetched after _Grow may have reallocated.  The
 * _Xran (out_of_range "invalid string position") and _Xlen (length_error
 * "string too long") throws are std::_String_base's (LIBCPMT string.obj).
 * Retail is __userpurge: count@<eax>, right@<ecx>, self@<ebx>, then roff on
 * the stack, retn 4.
 */
seStlStr_t *__stdcall stl_string_replace_m( seStlStr_t *self, seStlStr_t *right, unsigned int roff, unsigned int count )
{
  FxString       *str = (FxString *)self;
  const FxString *src = (const FxString *)right;
  unsigned int    num;

  if ( src->size < roff )
    ( (const std::_String_base *)str )->_Xran();   /* roff off end */
  num = src->size - roff;
  if ( num < count )
    count = num;   /* trim count to size */
  if ( 0xFFFFFFFFu - str->size <= count )    /* npos - _Mysize <= count */
    ( (const std::_String_base *)str )->_Xlen();   /* result too long */
  if ( 0 < count && str->Grow( num = str->size + count, false ) )
  {
    /* make room and append new stuff */
    memcpy(SE_FXPTR( str ) + str->size, SE_FXPTR( src ) + roff, count);
    str->size = num;   /* _Eos(num) */
    SE_FXPTR( str )[num] = 0;
  }
  return self;
}

/* ---- stl_map_node_color_m  0x004AE720 ---- HIGH */
unsigned char *__cdecl stl_map_node_color_m(seStrMapNode_t *node)
{
  return &node->color;
}

/* ---- stl_alloc_pair_max_size_m  0x004AE730 ---- HIGH */
int __stdcall stl_alloc_pair_max_size_m(int unused)
{
  return 48806446;
}

/* ---- stl_map_erase_node_m  0x004AE740 ----  IMPLEMENTED (retail) */
/*
 * std::map<std::string, CStringEdString>::erase(where) (Dinkumware
 * _Tree::erase) for the 104-byte-node tree: _Color at +100 (0 red, 1 black),
 * _Isnil at +101.  Unlinks the node (lifting its successor into its place
 * when it has two subtrees), rebalances when a black node was removed, then
 * destroys the {key, CStringEdString} pair at +12, frees the node and
 * decrements the size.  Writes the successor iterator to *result and returns
 * result.  Erasing the head throws out_of_range("invalid map/set<T>
 * iterator") (std::out_of_range); the EH frame only serves that throw.  The body
 * follows <xtree>'s erase(iterator).
 * Retail is __stdcall(tree, result, where), retn 0Ch (ecx is not read).
 */
#define SE_NODE104_COLOR( n )  ( SE_MAPNODE(n)->color )
#define SE_NODE104_ISNIL( n )  ( SE_MAPNODE(n)->isnil )
#define SE_LEFT( n )           ( ((seStlTreeNode_t *)(n))->left )
#define SE_RIGHT( n )          ( ((seStlTreeNode_t *)(n))->right )
#define SE_PARENT( n )         ( ((seStlTreeNode_t *)(n))->parent )

seStlTreeNode_t **__stdcall stl_map_erase_node_m( seStlTree_t *tree, seStlTreeNode_t **result, seStlTreeNode_t *where )
{
  seStlTree_t     *map = tree;
  seStlTreeNode_t *fixnode;     /* the node to recolor as needed */
  seStlTreeNode_t *fixparent;   /* parent of fixnode (which may be nil) */
  seStlTreeNode_t *erased;      /* node to erase */
  seStlTreeNode_t *pnode;       /* convenience pointer */
  unsigned char    color;

  if ( SE_NODE104_ISNIL(where) )
    throw std::out_of_range( FxStdString("invalid map/set<T> iterator") );
  erased = where;
  pnode  = erased;
  stl_map_iter_next104_m(&where);   /* ++where: save successor iterator for return */

  fixnode = SE_LEFT(pnode);
  if ( SE_NODE104_ISNIL(fixnode) )
    fixnode = SE_RIGHT(pnode);     /* must stitch up right subtree */
  else if ( SE_NODE104_ISNIL(SE_RIGHT(pnode)) )
    ;                              /* must stitch up left subtree */
  else
  {
    /* two subtrees, must lift successor node to replace erased */
    pnode   = where;               /* pnode is successor node */
    fixnode = SE_RIGHT(pnode);     /* fixnode is its only subtree */
  }

  if ( pnode == erased )
  {
    /* at most one subtree, relink it */
    fixparent = SE_PARENT(erased);
    if ( !SE_NODE104_ISNIL(fixnode) )
      fixnode->parent = fixparent;   /* link up */

    if ( map->head->parent == erased )
      map->head->parent = fixnode;    /* link down from root */
    else if ( SE_LEFT(fixparent) == erased )
      fixparent->left = fixnode;          /* link down to left */
    else
      fixparent->right = fixnode;         /* link down to right */

    if ( map->head->left == erased )
      map->head->left = SE_NODE104_ISNIL(fixnode) ? fixparent   /* smallest is parent of erased node */
                                         : stl_map_subtree_min_m(fixnode);   /* smallest in relinked subtree */

    if ( map->head->right == erased )
      map->head->right = SE_NODE104_ISNIL(fixnode) ? fixparent   /* largest is parent of erased node */
                                          : stl_map_subtree_max_m(fixnode);   /* largest in relinked subtree */
  }
  else
  {
    /* erased has two subtrees, pnode is successor to erased */
    SE_LEFT(erased)->parent = pnode;   /* link left up */
    pnode->left = SE_LEFT(erased);     /* link successor down */

    if ( pnode == SE_RIGHT(erased) )
      fixparent = pnode;                 /* successor is next to erased */
    else
    {
      /* successor further down, link in place of erased */
      fixparent = SE_PARENT(pnode);      /* parent is successor's */
      if ( !SE_NODE104_ISNIL(fixnode) )
        fixnode->parent = fixparent;     /* link fix up */
      fixparent->left = fixnode;         /* link fix down */
      pnode->right = SE_RIGHT(erased);   /* link successor down */
      SE_RIGHT(erased)->parent = pnode;  /* link erased up */
    }

    if ( map->head->parent == erased )
      map->head->parent = pnode;                 /* link down from root */
    else if ( SE_LEFT(SE_PARENT(erased)) == erased )
      SE_PARENT(erased)->left = pnode;               /* link down to left */
    else
      SE_PARENT(erased)->right = pnode;              /* link down to right */

    pnode->parent = SE_PARENT(erased);   /* erased's parent is now successor's */
    {
      /* std::swap(_Color(pnode), _Color(erased)): recolor it */
      unsigned char &left  = SE_NODE104_COLOR(pnode);
      unsigned char &right = SE_NODE104_COLOR(erased);
      color = left;
      left  = right;
      right = color;
    }
  }

  if ( SE_NODE104_COLOR(erased) == 1 )
  {
    /* erasing black link, must recolor/rebalance tree */
    for ( ; fixnode != map->head->parent && SE_NODE104_COLOR(fixnode) == 1;
          fixnode = fixparent, fixparent = SE_PARENT(fixnode) )
      if ( fixnode == SE_LEFT(fixparent) )
      {
        /* fixup left subtree */
        pnode = SE_RIGHT(fixparent);
        if ( SE_NODE104_COLOR(pnode) == 0 )
        {
          /* rotate red up from right subtree */
          SE_NODE104_COLOR(pnode)     = 1;
          SE_NODE104_COLOR(fixparent) = 0;
          stl_map_lrotate_m(fixparent, tree);
          pnode = SE_RIGHT(fixparent);
        }

        if ( SE_NODE104_ISNIL(pnode) )
          fixnode = fixparent;   /* shouldn't happen */
        else if ( SE_NODE104_COLOR(SE_LEFT(pnode)) == 1 && SE_NODE104_COLOR(SE_RIGHT(pnode)) == 1 )
        {
          /* redden right subtree with black children */
          SE_NODE104_COLOR(pnode) = 0;
          fixnode = fixparent;
        }
        else
        {
          /* must rearrange right subtree */
          if ( SE_NODE104_COLOR(SE_RIGHT(pnode)) == 1 )
          {
            /* rotate red up from left sub-subtree */
            SE_NODE104_COLOR(SE_LEFT(pnode)) = 1;
            SE_NODE104_COLOR(pnode) = 0;
            stl_map_rrotate_m(pnode, tree);
            pnode = SE_RIGHT(fixparent);
          }
          SE_NODE104_COLOR(pnode)     = SE_NODE104_COLOR(fixparent);
          SE_NODE104_COLOR(fixparent) = 1;
          SE_NODE104_COLOR(SE_RIGHT(pnode)) = 1;
          stl_map_lrotate_m(fixparent, tree);
          break;   /* tree now recolored/rebalanced */
        }
      }
      else
      {
        /* fixup right subtree */
        pnode = SE_LEFT(fixparent);
        if ( SE_NODE104_COLOR(pnode) == 0 )
        {
          /* rotate red up from left subtree */
          SE_NODE104_COLOR(pnode)     = 1;
          SE_NODE104_COLOR(fixparent) = 0;
          stl_map_rrotate_m(fixparent, tree);
          pnode = SE_LEFT(fixparent);
        }

        if ( SE_NODE104_ISNIL(pnode) )
          fixnode = fixparent;   /* shouldn't happen */
        else if ( SE_NODE104_COLOR(SE_RIGHT(pnode)) == 1 && SE_NODE104_COLOR(SE_LEFT(pnode)) == 1 )
        {
          /* redden left subtree with black children */
          SE_NODE104_COLOR(pnode) = 0;
          fixnode = fixparent;
        }
        else
        {
          /* must rearrange left subtree */
          if ( SE_NODE104_COLOR(SE_LEFT(pnode)) == 1 )
          {
            /* rotate red up from right sub-subtree */
            SE_NODE104_COLOR(SE_RIGHT(pnode)) = 1;
            SE_NODE104_COLOR(pnode) = 0;
            stl_map_lrotate_m(pnode, tree);
            pnode = SE_LEFT(fixparent);
          }
          SE_NODE104_COLOR(pnode)     = SE_NODE104_COLOR(fixparent);
          SE_NODE104_COLOR(fixparent) = 1;
          SE_NODE104_COLOR(SE_LEFT(pnode)) = 1;
          stl_map_rrotate_m(fixparent, tree);
          break;   /* tree now recolored/rebalanced */
        }
      }
    SE_NODE104_COLOR(fixnode) = 1;   /* ensure stopping node is black */
  }

  stl_map_pair_destroy_m(&SE_MAPNODE(erased)->myval);   /* _Alnod.destroy(erased) */
  operator delete(erased);                                       /* _Alnod.deallocate(erased, 1) */

  if ( 0 < map->size )
    --map->size;

  *result = where;   /* return successor iterator */
  return result;
}

#undef SE_NODE104_COLOR
#undef SE_NODE104_ISNIL
#undef SE_LEFT
#undef SE_RIGHT
#undef SE_PARENT

/* ---- stl_map_lrotate_m  0x004AEA20 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Lrotate(node) for the 104-byte-node map (_Isnil at +101), the
 * twin of stl_map44_lrotate_m: the right child is lifted into node's place
 * and node becomes its left child.  Returns the lifted node (left in eax by
 * retail).
 * Retail is __thiscall: node@<ecx>, tree on the stack, retn 4.
 */
seStlTreeNode_t *__stdcall stl_map_lrotate_m( seStlTreeNode_t *node, seStlTree_t *tree )
{
  seStlTreeNode_t *where = node;
  seStlTreeNode_t *pivot = where->right;
  seStlTreeNode_t *head;
  seStlTreeNode_t *parent;

  where->right = pivot->left;
  if ( !SE_MAPNODE(pivot->left)->isnil )
    pivot->left->parent = where;
  pivot->parent = where->parent;

  head = tree->head;
  if ( where == head->parent )
  {
    head->parent = pivot;                    /* where was the root */
  }
  else
  {
    parent = where->parent;
    if ( where == parent->left )
      parent->left = pivot;
    else
      parent->right = pivot;
  }
  pivot->left   = where;
  where->parent = pivot;
  return pivot;
}

/* ---- stl_map_root_const_m  0x004AEA80 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map_root_const_m(seStlTree_t *tree)
{
  return &tree->head->parent;
}

/* ---- stl_map_rrotate_m  0x004AEA90 ---- HIGH */
seStlTreeNode_t *__stdcall stl_map_rrotate_m(seStlTreeNode_t *node, seStlTree_t *tree)
{
  seStlTreeNode_t *where = node;
  seStlTreeNode_t *pivot;
  seStlTreeNode_t *pivotRight;
  seStlTreeNode_t *head;
  seStlTreeNode_t *parent;

  pivot = where->left;
  where->left = where->left->right;
  pivotRight = pivot->right;
  if ( !SE_MAPNODE(pivotRight)->isnil )
    pivotRight->parent = where;
  pivot->parent = where->parent;
  head = (tree)->head;
  if ( where == head->parent )
  {
    head->parent = pivot;                    /* where was the root */
    pivot->right = where;
    where->parent = pivot;
  }
  else
  {
    parent = where->parent;
    if ( where == parent->right )
      parent->right = pivot;
    else
      parent->left = pivot;
    pivot->right = where;
    where->parent = pivot;
  }
  return pivot;
}

/* ---- stl_map_buynode_str_m  0x004AEAF0 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Buynode() for the 104-byte-node map: operator new(0x68) for
 * the head (sentinel) node, the three links zeroed, _Color +100 = 1 (black)
 * and _Isnil +101 = 0 (the callers then set _Isnil themselves); the pair
 * payload is left unconstructed.  Each link is placement-constructed, so
 * retail tests node, node+4 and node+8 for NULL before storing.  The tree
 * argument (the allocator) is not read.  Retail is __stdcall(tree), retn 4;
 * retail's operator new (0x528637) is the CRT's, the file's malloc here.
 */
__declspec(noinline) seStlTreeNode_t *__stdcall stl_map_buynode_str_m( seStlTree_t *tree )
{
  seStlTreeNode_t *node;

  (void)tree;

  node = (seStlTreeNode_t *)crt_operator_new(104);
  /* _Alnod.construct(&_Left(node), 0) etc.: placement new tests each address */
  { seStlTreeNode_t **link = &node->left;   if ( link ) *link = 0; }
  { seStlTreeNode_t **link = &node->parent; if ( link ) *link = 0; }
  { seStlTreeNode_t **link = &node->right;  if ( link ) *link = 0; }
  SE_MAPNODE(node)->color = 1;   /* _Color = black */
  SE_MAPNODE(node)->isnil = 0;   /* _Isnil */
  return node;
}

/* ---- stl_map_buynode_init_m  0x004AEB30 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Buynode(left, parent, right, val, color) for the 104-byte-node
 * map, the twin of stl_map44_buynode_init_m: operator new(0x68), then
 * new (node) _Node(left, parent, right, val, color) -- the three links, a copy
 * of the {key, CStringEdString} pair at +12, _Color +100 and _Isnil +101 = 0
 * (stl_map_node_init_m is that constructor's out-of-line copy) -- inside
 * try { } catch (...) { free; throw; }.  The tree argument (the allocator) is
 * not read.  Retail is __stdcall, retn 18h; retail's operator new is the
 * CRT's, the file's malloc here.
 */
struct SeMapNode104 {
  seStlTreeNode_t links;
  SeMapNode104( seStlTreeNode_t *left, seStlTreeNode_t *parent, seStlTreeNode_t *right, seStrMapPair_t *val, char color )
  {
    links.left   = left;
    links.parent = parent;
    links.right  = right;
    SE_STRMAPPAIR(&SE_MAPNODE(this)->myval).SeStrMapPair::SeStrMapPair( SE_STRMAPPAIR(val) );   /* _Myval(val) */
    SE_MAPNODE(this)->color = color;   /* _Color */
    SE_MAPNODE(this)->isnil = 0;       /* _Isnil */
  }
};
seStlTreeNode_t *__stdcall stl_map_buynode_init_m( seStlTree_t *tree, seStlTreeNode_t *left, seStlTreeNode_t *parent, seStlTreeNode_t *right, seStrMapPair_t *val, char color )
{
  seStlTreeNode_t *node;

  (void)tree;

  node = (seStlTreeNode_t *)crt_operator_new(104);
  try
  {
    new ( node ) SeMapNode104( left, parent, right, val, color );
  }
  catch ( ... )
  {
    operator delete( node );
    throw;
  }
  return node;
}

/* ---- stl_map_tree_ptr_construct_m  0x004AEBD0 ---- HIGH */
FxStlAllocatorTag *__stdcall stl_map_tree_ptr_construct_m(FxStlAllocatorTag *result, FxStlAllocatorTag *allocator, int unused)
{
  *result = *allocator;
  return result;
}

/* ---- stl_alloc_str_max_size_dup2_m  0x004AEBE0 ---- HIGH */
int __stdcall stl_alloc_str_max_size_dup2_m(int unused)
{
  return 153391689;
}

/* ---- stl_map_iter_prev_m  0x004AEBF0 ----  IMPLEMENTED (retail) */
/*
 * std::map<std::string, CStringEdString>::iterator::operator-- (_Dec) for the
 * 104-byte-node tree (_Isnil at +101), the twin of stl_map44_iter_prev_m:
 * end() steps to the rightmost node (head->right), a node with a left
 * subtree to that subtree's maximum, anything else climbs while it is a left
 * child.  The iterator is updated in place; void like Dinkumware's _Dec
 * (no caller reads eax), with _Max's single-pointer loop.
 * Retail is __usercall: iter@<edx>.
 */
#define SE_NODE104_ISNIL( n )  ( SE_MAPNODE(n)->isnil )

inline void __cdecl stl_map_iter_prev_m( seStlTreeNode_t **iter )
{
  seStlTreeNode_t *node = *iter;
  seStlTreeNode_t *parent;

  if ( SE_NODE104_ISNIL(node) )
  {
    *iter = node->right;              /* end() -> rightmost */
    return;
  }

  if ( !SE_NODE104_ISNIL(node->left) )
  {
    /* _Max(_Left(ptr)), inlined */
    node = node->left;
    while ( !SE_NODE104_ISNIL(node->right) )
      node = node->right;
    *iter = node;
    return;
  }

  for ( parent = node->parent;
        !SE_NODE104_ISNIL(parent) && *iter == parent->left;
        parent = parent->parent )
  {
    *iter = parent;
  }
  if ( !SE_NODE104_ISNIL(parent) )
    *iter = parent;
}

#undef SE_NODE104_ISNIL

/* ---- stl_map_iter_postinc_m  0x004AEC50 ---- */
seStlTreeNode_t **__stdcall stl_map_iter_postinc_m(seStlTreeNode_t **iter, seStlTreeNode_t **result, int unused)
{
  seStlTreeNode_t *old;

  old = *iter;
  stl_map_iter_next104_m(iter);
  *result = old;
  return result;
}

/* ---- stl_map44_erase_node_m  0x004AEC60 ----  IMPLEMENTED (retail) */
/*
 * std::set<std::string>::erase(where) (Dinkumware _Tree::erase) for the
 * 44-byte-node tree, the twin of stl_map_erase_node_m: _Color at +40 (0 red,
 * 1 black), _Isnil at +41.  Unlinks the node (lifting its successor into its
 * place when it has two subtrees), rebalances when a black node was removed,
 * then destroys the key string at +12 (the destructor is inlined here, not a
 * call to stl_map44_node_destroy_m), frees the node and decrements the size.
 * Writes the successor iterator to *result and returns result.  Erasing the
 * head throws out_of_range("invalid map/set<T> iterator") (std::out_of_range);
 * the EH frame only serves that throw.  The body follows <xtree>'s
 * erase(iterator).
 * Retail is __stdcall(tree, result, where), retn 0Ch (ecx is not read).
 */
#define SE_NODE44_COLOR( n )  ( SE_SETNODE(n)->color )
#define SE_NODE44_ISNIL( n )  ( SE_SETNODE(n)->isnil )
#define SE_LEFT( n )          ( ((seStlTreeNode_t *)(n))->left )
#define SE_RIGHT( n )         ( ((seStlTreeNode_t *)(n))->right )
#define SE_PARENT( n )        ( ((seStlTreeNode_t *)(n))->parent )

seStlTreeNode_t **__stdcall stl_map44_erase_node_m( seStlTree_t *tree, seStlTreeNode_t **result, seStlTreeNode_t *where )
{
  seStlTree_t     *set = tree;
  seStlTreeNode_t *fixnode;     /* the node to recolor as needed */
  seStlTreeNode_t *fixparent;   /* parent of fixnode (which may be nil) */
  seStlTreeNode_t *erased;      /* node to erase */
  seStlTreeNode_t *pnode;       /* convenience pointer */
  unsigned char    color;

  if ( SE_NODE44_ISNIL(where) )
    throw std::out_of_range( FxStdString("invalid map/set<T> iterator") );
  erased = where;
  pnode  = erased;
  stl_map44_iter_next_m(&where);   /* ++where: save successor iterator for return */

  fixnode = SE_LEFT(pnode);
  if ( SE_NODE44_ISNIL(fixnode) )
    fixnode = SE_RIGHT(pnode);     /* must stitch up right subtree */
  else if ( SE_NODE44_ISNIL(SE_RIGHT(pnode)) )
    ;                              /* must stitch up left subtree */
  else
  {
    /* two subtrees, must lift successor node to replace erased */
    pnode   = where;               /* pnode is successor node */
    fixnode = SE_RIGHT(pnode);     /* fixnode is its only subtree */
  }

  if ( pnode == erased )
  {
    /* at most one subtree, relink it */
    fixparent = SE_PARENT(erased);
    if ( !SE_NODE44_ISNIL(fixnode) )
      fixnode->parent = fixparent;   /* link up */

    if ( set->head->parent == erased )
      set->head->parent = fixnode;    /* link down from root */
    else if ( SE_LEFT(fixparent) == erased )
      fixparent->left = fixnode;          /* link down to left */
    else
      fixparent->right = fixnode;         /* link down to right */

    if ( set->head->left == erased )
      set->head->left = SE_NODE44_ISNIL(fixnode) ? fixparent   /* smallest is parent of erased node */
                                         : stl_map44_subtree_min_m(fixnode);   /* smallest in relinked subtree */

    if ( set->head->right == erased )
      set->head->right = SE_NODE44_ISNIL(fixnode) ? fixparent   /* largest is parent of erased node */
                                          : stl_map44_subtree_max_m(fixnode);   /* largest in relinked subtree */
  }
  else
  {
    /* erased has two subtrees, pnode is successor to erased */
    SE_LEFT(erased)->parent = pnode;   /* link left up */
    pnode->left = SE_LEFT(erased);     /* link successor down */

    if ( pnode == SE_RIGHT(erased) )
      fixparent = pnode;                 /* successor is next to erased */
    else
    {
      /* successor further down, link in place of erased */
      fixparent = SE_PARENT(pnode);      /* parent is successor's */
      if ( !SE_NODE44_ISNIL(fixnode) )
        fixnode->parent = fixparent;     /* link fix up */
      fixparent->left = fixnode;         /* link fix down */
      pnode->right = SE_RIGHT(erased);   /* link successor down */
      SE_RIGHT(erased)->parent = pnode;  /* link erased up */
    }

    if ( set->head->parent == erased )
      set->head->parent = pnode;                 /* link down from root */
    else if ( SE_LEFT(SE_PARENT(erased)) == erased )
      SE_PARENT(erased)->left = pnode;               /* link down to left */
    else
      SE_PARENT(erased)->right = pnode;              /* link down to right */

    pnode->parent = SE_PARENT(erased);   /* erased's parent is now successor's */
    {
      /* std::swap(_Color(pnode), _Color(erased)): recolor it */
      unsigned char &left  = SE_NODE44_COLOR(pnode);
      unsigned char &right = SE_NODE44_COLOR(erased);
      color = left;
      left  = right;
      right = color;
    }
  }

  if ( SE_NODE44_COLOR(erased) == 1 )
  {
    /* erasing black link, must recolor/rebalance tree */
    for ( ; fixnode != set->head->parent && SE_NODE44_COLOR(fixnode) == 1;
          fixnode = fixparent, fixparent = SE_PARENT(fixnode) )
      if ( fixnode == SE_LEFT(fixparent) )
      {
        /* fixup left subtree */
        pnode = SE_RIGHT(fixparent);
        if ( SE_NODE44_COLOR(pnode) == 0 )
        {
          /* rotate red up from right subtree */
          SE_NODE44_COLOR(pnode)     = 1;
          SE_NODE44_COLOR(fixparent) = 0;
          stl_map44_lrotate_m(fixparent, tree);
          pnode = SE_RIGHT(fixparent);
        }

        if ( SE_NODE44_ISNIL(pnode) )
          fixnode = fixparent;   /* shouldn't happen */
        else if ( SE_NODE44_COLOR(SE_LEFT(pnode)) == 1 && SE_NODE44_COLOR(SE_RIGHT(pnode)) == 1 )
        {
          /* redden right subtree with black children */
          SE_NODE44_COLOR(pnode) = 0;
          fixnode = fixparent;
        }
        else
        {
          /* must rearrange right subtree */
          if ( SE_NODE44_COLOR(SE_RIGHT(pnode)) == 1 )
          {
            /* rotate red up from left sub-subtree */
            SE_NODE44_COLOR(SE_LEFT(pnode)) = 1;
            SE_NODE44_COLOR(pnode) = 0;
            stl_map44_rrotate_m(pnode, tree);
            pnode = SE_RIGHT(fixparent);
          }
          SE_NODE44_COLOR(pnode)     = SE_NODE44_COLOR(fixparent);
          SE_NODE44_COLOR(fixparent) = 1;
          SE_NODE44_COLOR(SE_RIGHT(pnode)) = 1;
          stl_map44_lrotate_m(fixparent, tree);
          break;   /* tree now recolored/rebalanced */
        }
      }
      else
      {
        /* fixup right subtree */
        pnode = SE_LEFT(fixparent);
        if ( SE_NODE44_COLOR(pnode) == 0 )
        {
          /* rotate red up from left subtree */
          SE_NODE44_COLOR(pnode)     = 1;
          SE_NODE44_COLOR(fixparent) = 0;
          stl_map44_rrotate_m(fixparent, tree);
          pnode = SE_LEFT(fixparent);
        }

        if ( SE_NODE44_ISNIL(pnode) )
          fixnode = fixparent;   /* shouldn't happen */
        else if ( SE_NODE44_COLOR(SE_RIGHT(pnode)) == 1 && SE_NODE44_COLOR(SE_LEFT(pnode)) == 1 )
        {
          /* redden left subtree with black children */
          SE_NODE44_COLOR(pnode) = 0;
          fixnode = fixparent;
        }
        else
        {
          /* must rearrange left subtree */
          if ( SE_NODE44_COLOR(SE_LEFT(pnode)) == 1 )
          {
            /* rotate red up from right sub-subtree */
            SE_NODE44_COLOR(SE_RIGHT(pnode)) = 1;
            SE_NODE44_COLOR(pnode) = 0;
            stl_map44_lrotate_m(pnode, tree);
            pnode = SE_LEFT(fixparent);
          }
          SE_NODE44_COLOR(pnode)     = SE_NODE44_COLOR(fixparent);
          SE_NODE44_COLOR(fixparent) = 1;
          SE_NODE44_COLOR(SE_LEFT(pnode)) = 1;
          stl_map44_rrotate_m(fixparent, tree);
          break;   /* tree now recolored/rebalanced */
        }
      }
    SE_NODE44_COLOR(fixnode) = 1;   /* ensure stopping node is black */
  }

  seStlStr_tidy(&SE_SETNODE(erased)->key);   /* _Alnod.destroy(erased): ~key, inlined */
  operator delete(erased);                           /* _Alnod.deallocate(erased, 1) */

  if ( 0 < set->size )
    --set->size;

  *result = where;   /* return successor iterator */
  return result;
}

#undef SE_NODE44_COLOR
#undef SE_NODE44_ISNIL
#undef SE_LEFT
#undef SE_RIGHT
#undef SE_PARENT

/* ---- stl_map44_clear_m  0x004AEF60 ----  IMPLEMENTED (retail) */
/*
 * std::set<std::string>::clear() for the 44-byte-node tree, the twin of
 * stl_map_clear_m: _Erase(root), then the head is reset to an empty tree.
 * No retail caller.  Retail is __usercall: tree@<eax> (also passed as the
 * ecx of _Erase).
 */
void __cdecl stl_map44_clear_m( seStlTree_t *tree )
{
  seStlTree_t *set = tree;

  stl_map44_erase_all_m(tree, *(seStlIter_t *)&set->head->parent);
  set->head->parent = set->head;   /* _Myhead re-read after every store */
  set->size = 0;
  set->head->left   = set->head;
  set->head->right  = set->head;
}

/* ---- stl_map44_lower_bound_m  0x004AEF90 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Lbound(key) for the 44-byte-node set, the twin of
 * stl_map_lower_bound_m: the first node whose key is not less than `key`, or
 * the head (end()) when there is none.  The std::less<std::string> test is
 * inlined (see seStlStr_compare).
 * Retail is __usercall: tree@<eax>, key@<ecx>.
 */
seStlTreeNode_t *__cdecl stl_map44_lower_bound_m( seStlTree_t *tree, seStlStr_t *key )
{
  seStlTree_t     *set       = tree;
  seStlStr_t      *keyStr    = key;
  seStlTreeNode_t *whereNode = set->head;
  seStlTreeNode_t *node      = whereNode->parent;   /* root */

  while ( !SE_SETNODE(node)->isnil )
  {
    if ( seStlStr_compare(&SE_SETNODE(node)->key, keyStr) < 0 )
    {
      node = node->right;   /* node key < key */
    }
    else
    {
      whereNode = node;
      node      = node->left;
    }
  }
  return whereNode;
}

/* ---- stl_map44_subtree_max_m  0x004AF030 ---- HIGH */
/* Rightmost node of the subtree: follow _Right links until the nil sentinel (44-byte nodes, _Isnil@41). */
seStlTreeNode_t *__cdecl stl_map44_subtree_max_m(seStlTreeNode_t *node)
{
  while ( !SE_SETNODE(node->right)->isnil )
    node = node->right;
  return node;
}

/* ---- stl_map44_upper_bound_m  0x004AF050 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Ubound(key) for the 44-byte-node set: the first node whose
 * key is greater than `key`, or the head (end()) when there is none.  The
 * std::less<std::string> test (key.compare(node key) < 0) is inlined.
 * Retail is __usercall: tree@<eax>, key on the stack, retn 4.
 */
seStlTreeNode_t *__stdcall stl_map44_upper_bound_m( seStlTree_t *tree, seStlStr_t *key )
{
  seStlTree_t     *set       = tree;
  seStlStr_t      *keyStr    = key;
  seStlTreeNode_t *whereNode = set->head;
  seStlTreeNode_t *node      = whereNode->parent;   /* root */

  while ( !SE_SETNODE(node)->isnil )
  {
    if ( seStlStr_compare(keyStr, &SE_SETNODE(node)->key) < 0 )
    {
      whereNode = node;                        /* key < node key */
      node      = node->left;
    }
    else
    {
      node = node->right;
    }
  }
  return whereNode;
}

/* ---- stl_map44_buynode_m  0x004AF100 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Buynode() for the 44-byte-node set, the twin of
 * stl_map_buynode_str_m: operator new(0x2C) for the head (sentinel) node,
 * the three links zeroed, _Color +40 = 1 (black) and _Isnil +41 = 0 (the
 * callers then set _Isnil themselves); the key string is left
 * unconstructed.  Each link is placement-constructed, so retail tests node,
 * node+4 and node+8 for NULL before storing.  The tree argument (the
 * allocator) is not read.  Retail is __stdcall(tree), retn 4; retail's
 * operator new (0x528637) is the CRT's, the file's malloc here.
 */
__declspec(noinline) seStlTreeNode_t *__stdcall stl_map44_buynode_m( seStlTree_t *tree )
{
  seStlTreeNode_t *node;

  (void)tree;

  node = (seStlTreeNode_t *)crt_operator_new(44);
  /* _Alnod.construct(&_Left(node), 0) etc.: placement new tests each address */
  { seStlTreeNode_t **link = &node->left;   if ( link ) *link = 0; }
  { seStlTreeNode_t **link = &node->parent; if ( link ) *link = 0; }
  { seStlTreeNode_t **link = &node->right;  if ( link ) *link = 0; }
  SE_SETNODE(node)->color = 1;    /* _Color = black */
  SE_SETNODE(node)->isnil = 0;    /* _Isnil */
  return node;
}

/* ---- stl_map44_tree_ptr_construct_m  0x004AF140 ---- */
FxStlAllocatorTag *__stdcall stl_map44_tree_ptr_construct_m(FxStlAllocatorTag *result, FxStlAllocatorTag *allocator, int unused)
{
  *result = *allocator;
  return result;
}

/* ---- stl_alloc_node44_allocate_m  0x004AF150 ----  IMPLEMENTED (retail) */
/*
 * std::allocator<_Tree_nod::_Node>::allocate(count, hint) for the 44-byte
 * nodes: operator new(count * 0x2C).  No retail caller.  Retail is
 * __userpurge with count@<eax> and two stack words it never reads, retn 8;
 * operator new is the file's malloc.
 */
void *__stdcall stl_alloc_node44_allocate_m( unsigned int count, int unused1, int unused2 )
{
  (void)unused1;
  (void)unused2;
  return crt_operator_new(count * 44);
}

/* ---- stl_map44_node_init_m  0x004AF160 ---- HIGH */
/* Initialize an allocated 44-byte tree node: three links, an inline (SSO) string key copied from keySrc, then the _Color/_Isnil bytes. */
seStrSetNode_t *__stdcall stl_map44_node_init_m(seStlTreeNode_t *left, seStlTreeNode_t *right, seStlTreeNode_t *parent, seStrSetNode_t *node, seStlStr_t *keySrc, char color)
{
  node->left   = left;
  node->parent = parent;
  node->right  = right;
  ( (SeStrCopy *)&node->key )->Construct( keySrc );   /* _Myval(_Val): key = *keySrc */
  node->color = color; /* node->_Color */
  node->isnil = 0;     /* node->_Isnil = 0 */
  return node;
}

/* ---- stl_map44_iter_ne_m  0x004AF1A0 ---- MEDIUM */
int __cdecl stl_map44_iter_ne_m(seStlTreeNode_t **left, seStlTreeNode_t **right)
{
  return *left != *right;
}

/* ---- stl_map44_iter_postinc_m  0x004AF1B0 ---- HIGH */
seStlTreeNode_t **__stdcall stl_map44_iter_postinc_m(seStlTreeNode_t **iter, seStlTreeNode_t **result, int unused)
{
  seStlTreeNode_t *old;

  old = *iter;
  stl_map44_iter_next_m(iter);
  *result = old;
  return result;
}

/* ---- stl_map_subtree_max_m  0x004AF1C0 ---- HIGH */
/* Rightmost node of the subtree: follow _Right links until the nil sentinel (104-byte nodes, _Isnil@101). */
seStlTreeNode_t *__cdecl stl_map_subtree_max_m(seStlTreeNode_t *node)
{
  while ( !SE_MAPNODE(node->right)->isnil )
    node = node->right;
  return node;
}

/* ---- stl_map_subtree_min_m  0x004AF1E0 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Min(node) for the 104-byte-node map: follow _Left links until
 * the nil sentinel (_Isnil at +101) and return the leftmost node.
 * Retail is __usercall: node@<eax>.
 */
seStlTreeNode_t *__cdecl stl_map_subtree_min_m( seStlTreeNode_t *node )
{
  seStlTreeNode_t *cur = node;

  while ( !SE_MAPNODE(cur->left)->isnil )
    cur = cur->left;
  return cur;
}

/* ---- stl_map_tree_nod_construct_m  0x004AF200 ---- HIGH */
FxStlAllocatorTag *__stdcall stl_map_tree_nod_construct_m(FxStlAllocatorTag *result, FxStlAllocatorTag *allocator, int unused)
{
  *result = *allocator;
  return result;
}

/* ---- stl_alloc_pair_max_size_dup_m  0x004AF210 ---- HIGH */
int __stdcall stl_alloc_pair_max_size_dup_m(int unused)
{
  return 48806446;
}

/* ---- stl_alloc_node104_allocate_m  0x004AF220 ----  IMPLEMENTED (retail) */
/*
 * std::allocator<_Tree_nod::_Node>::allocate(count, hint) for the 104-byte
 * nodes: operator new(count * 0x68).  No retail caller.  Retail is
 * __userpurge with count@<eax> and two stack words it never reads, retn 8;
 * operator new is the file's malloc.
 */
void *__stdcall stl_alloc_node104_allocate_m( unsigned int count, int unused1, int unused2 )
{
  (void)unused1;
  (void)unused2;
  return crt_operator_new(count * 104);
}

/* ---- stl_map_node_init_m  0x004AF230 ---- HIGH */
/* Initialize an allocated 104-byte tree node: three links, a {key,value} pair copy-constructed from pairSrc, then the _Color/_Isnil bytes. */
seStrMapNode_t *__stdcall stl_map_node_init_m(seStlTreeNode_t *left, seStlTreeNode_t *right, seStlTreeNode_t *parent, seStrMapNode_t *node, seStrMapPair_t *pairSrc, char color)
{
  node->left   = left;
  node->parent = parent;
  node->right  = right;
  SE_STRMAPPAIR(&node->myval).SeStrMapPair::SeStrMapPair( SE_STRMAPPAIR(pairSrc) );   /* _Myval(pairSrc) */
  node->color = color; /* node->_Color */
  node->isnil = 0;     /* node->_Isnil = 0 */
  return node;
}

/* ---- stl_alloc_nodeptr104_construct_m  0x004AF260 ---- MEDIUM */
seStlTreeNode_t **__stdcall stl_alloc_nodeptr104_construct_m(seStlTreeNode_t **result, seStlTreeNode_t **value, int unused)
{
  if ( result )
    *result = *value;
  return result;
}

/* ---- stl_map_iter_next_wrap_m  0x004AF270 ---- HIGH */
seStlTreeNode_t **__cdecl stl_map_iter_next_wrap_m(seStlTreeNode_t **iter)
{
  stl_map_iter_next104_m(iter);
  return iter;
}

/* ---- stl_map44_erase_all_m  0x004AF280 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Erase(node) for the 44-byte-node set, the twin of
 * stl_tree_erase_all_m: recurses into each right subtree, walks the left
 * spine iteratively, destroying each node's key string and freeing it.
 * Retail is __thiscall (tree@<ecx>, node on the stack, retn 4): the tree is
 * only handed on to the recursive call.  __fastcall with the node as a
 * one-pointer struct gives that convention (the struct stays on the stack).
 */
void __fastcall stl_map44_erase_all_m( seStlTree_t *tree, seStlIter_t node )
{
  seStlTreeNode_t *root = node.ptr;
  seStlTreeNode_t *cur;
  seStlIter_t      right;

  for ( cur = root; !SE_SETNODE(cur)->isnil; root = cur )
  {
    right.ptr = cur->right;
    stl_map44_erase_all_m(tree, right);
    cur = cur->left;
    stl_map44_node_destroy_m(SE_SETNODE(root));
    operator delete(root);
  }
}

/* ---- stl_map44_subtree_min_m  0x004AF2C0 ----  IMPLEMENTED (retail) */
/*
 * std::_Tree::_Min(node) for the 44-byte-node set: follow _Left links until
 * the nil sentinel (_Isnil at +41) and return the leftmost node.
 * Retail is __usercall: node@<eax>.
 */
seStlTreeNode_t *__cdecl stl_map44_subtree_min_m( seStlTreeNode_t *node )
{
  seStlTreeNode_t *cur = node;

  while ( !SE_SETNODE(cur->left)->isnil )
    cur = cur->left;
  return cur;
}

/* ---- stl_map44_root_const_m  0x004AF2E0 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_root_const_m(seStlTree_t *tree)
{
  return &tree->head->parent;
}

/* ---- stl_map44_tree_nod_construct_m  0x004AF2F0 ---- HIGH */
FxStlAllocatorTag *__stdcall stl_map44_tree_nod_construct_m(FxStlAllocatorTag *result, FxStlAllocatorTag *allocator, int unused)
{
  *result = *allocator;
  return result;
}

/* ---- stl_map44_node_destroy2_m  0x004AF300 ---- HIGH */
int __stdcall stl_map44_node_destroy2_m(seStrSetNode_t *node, int unused)
{
  return stl_map44_node_destroy_m(node);
}

/* ---- stl_alloc_nodeptr44_construct_m  0x004AF310 ---- MEDIUM */
seStlTreeNode_t **__stdcall stl_alloc_nodeptr44_construct_m(seStlTreeNode_t **result, seStlTreeNode_t **value, int unused)
{
  if ( result )
    *result = *value;
  return result;
}

/* ---- stl_map44_iter_next_wrap_m  0x004AF320 ---- HIGH */
seStlTreeNode_t **__cdecl stl_map44_iter_next_wrap_m(seStlTreeNode_t **iter)
{
  stl_map44_iter_next_m(iter);
  return iter;
}

/* ---- SeStrMapPair::SeStrMapPair(const SeStrMapPair &)  0x004AF330 ---- HIGH */
/* The tree node's _Myval(val): copies the { std::string key, CStringEdString value } payload. */
SeStrMapPair::SeStrMapPair( const SeStrMapPair &other ) : first( other.first ), second( other.second )
{
}

/* ---- stl_map_traits_construct_m  0x004AF3A0 ---- HIGH */
FxStlAllocatorTag *__fastcall stl_map_traits_construct_m(FxStlAllocatorTag *result, FxStlAllocatorTag allocator)
{
  result->value = allocator.value;
  return result;
}

/* ---- stl_map_iter_next104_m  0x004AF3B0 ----  IMPLEMENTED (retail) */
/*
 * std::map<std::string, CStringEdString>::iterator::operator++ (_Inc) for
 * the 104-byte-node tree (_Isnil at +101): end() is not moved, a node with a
 * right subtree steps to that subtree's minimum, anything else climbs while
 * it is a right child and lands on the first parent it is not (the head,
 * i.e. end(), past the last node).  The iterator is updated in place; void
 * like Dinkumware's _Inc (no caller reads eax), with _Min's single-pointer loop.
 * Retail is __usercall: iter@<edx>.
 */
#define SE_NODE104_ISNIL( n )  ( SE_MAPNODE(n)->isnil )

inline void __cdecl stl_map_iter_next104_m( seStlTreeNode_t **iter )
{
  seStlTreeNode_t *node = *iter;
  seStlTreeNode_t *parent;

  if ( SE_NODE104_ISNIL(node) )
    return;                                  /* end() stays put */

  if ( !SE_NODE104_ISNIL(node->right) )
  {
    /* _Min(_Right(ptr)), inlined */
    node = node->right;
    while ( !SE_NODE104_ISNIL(node->left) )
      node = node->left;
    *iter = node;
    return;
  }

  for ( parent = node->parent;
        !SE_NODE104_ISNIL(parent) && *iter == parent->right;
        parent = parent->parent )
  {
    *iter = parent;
  }
  *iter = parent;
}

#undef SE_NODE104_ISNIL

/* ---- stl_map44_traits_construct_m  0x004AF410 ---- */
FxStlAllocatorTag *__fastcall stl_map44_traits_construct_m(FxStlAllocatorTag *result, FxStlAllocatorTag allocator)
{
  result->value = allocator.value;
  return result;
}

/* ---- stl_map44_iter_next_m  0x004AF420 ----  IMPLEMENTED (retail) */
/*
 * std::set<std::string>::iterator::operator++ (_Inc) for the 44-byte-node
 * tree (_Isnil at +41), the twin of stl_map_iter_next104_m: end() is not
 * moved, a node with a right subtree steps to that subtree's minimum,
 * anything else climbs while it is a right child and lands on the first
 * parent it is not.  The iterator is updated in place; void like
 * Dinkumware's _Inc (no caller reads eax), with _Min's single-pointer loop.
 * Retail is __usercall: iter@<edx>.
 */
#define SE_NODE44_ISNIL( n )  ( SE_SETNODE(n)->isnil )

inline void __cdecl stl_map44_iter_next_m( seStlTreeNode_t **iter )
{
  seStlTreeNode_t *node = *iter;
  seStlTreeNode_t *parent;

  if ( SE_NODE44_ISNIL(node) )
    return;                                  /* end() stays put */

  if ( !SE_NODE44_ISNIL(node->right) )
  {
    /* _Min(_Right(ptr)), inlined */
    node = node->right;
    while ( !SE_NODE44_ISNIL(node->left) )
      node = node->left;
    *iter = node;
    return;
  }

  for ( parent = node->parent;
        !SE_NODE44_ISNIL(parent) && *iter == parent->right;
        parent = parent->parent )
  {
    *iter = parent;
  }
  *iter = parent;
}

#undef SE_NODE44_ISNIL

/* ---- stl_map44_distance_m  0x004AF480 ---- */
/* std::distance: walk [first, last), accumulating the step count into *count. */
void __cdecl stl_map44_distance_m(int *count, seStlIter_t first, SeDistanceEnd last)
{
  seStlTreeNode_t *iterator=first.ptr;
  seStlTreeNode_t *end;
  int  n;

  for ( end = last.pointer; iterator != end; stl_map44_iter_next_m(&iterator) )
  {
    n = *count + 1;
    *count = n;
  }
}

/* ---- stl_vector_ucopy_wrap2_m  0x004AF4B0 ----  IMPLEMENTED (retail) */
/*
 * std::vector<std::string>::_Ucopy(first, last, dest): uninitialized_copy of
 * [first, last) into the raw storage at dest; returns the end of the copy.
 * Retail is __fastcall (vec@<ecx>, dest@<edx>, then first/last, retn 8): the
 * vector and Dinkumware's (first, last, dest) order, so the arguments are
 * evaluated dest first, as in retail; the
 * vector is only pushed as the (stateless) allocator argument, along with a
 * trailing iterator-tag word; stl_vector_ucopy_m reads the allocator only on
 * its unwind path.
 */
seStlStr_t *__fastcall stl_vector_ucopy_wrap2_m( void *vec, SeStrIter first, SeStrIter last, seStlStr_t *dest )
{
  FxStlAllocatorTag cat;   /* _Ptr_cat(first, dest): an empty tag object */

  return stl_vector_ucopy_m(first, last, dest, vec, cat);
}

/* ---- stl_vector_ufill_range_m  0x004AF4E0 ----  IMPLEMENTED (retail) */
/*
 * std::fill(first, last, val) over constructed std::string elements: each one
 * is assigned from val (assign(val, 0, npos)).
 * Retail is __usercall: val@<ebx>, then (first, last) on the stack.
 */
void __cdecl stl_vector_ufill_range_m( SeStrIter first, SeStrIter last, seStlStr_t *val )
{
  for ( ; first.ptr != last.ptr; ++first.ptr )
    stl_fxString_assignSubstr_m(first.ptr, val, 0, 0xFFFFFFFF);   /* *first = val */
}

/* ---- stl_vector_ucopy_backward_wrap_m  0x004AF510 ----  IMPLEMENTED (retail) */
/*
 * std::copy_backward(first, last, dest): forwards to stl_vector_ucopy_backward_m
 * (which stores the new dest iterator through result) and returns result.
 * Retail is __usercall: result@<esi>, then (first, last, dest) on the stack,
 * plus the (empty) iterator-tag word for the worker.
 */
SeStrIter __cdecl stl_vector_ucopy_backward_wrap_m( SeStrIter first, SeStrIter last, SeStrIter dest )
{
  FxStlAllocatorTag cat;   /* _Ptr_cat(first, dest): an empty tag object */

  return stl_vector_ucopy_backward_m(first, last, dest, cat);
}

/* ---- stl_vector_ufill_wrap_m  0x004AF540 ---- HIGH */
/*
 * Retail is __usercall val@<edx>, then (dest, count) on the stack, and hands
 * count to stl_vector_ufill_n_impl_m in ecx.  No caller in retail or the tree.
 */
/* std::_Uninitialized_fill_n(first, count, val, al): forwards with the pointer category. */
void __cdecl stl_vector_ufill_wrap_m( seStlStr_t *first, unsigned int count, seStlStr_t *val, void *alloc )
{
  FxStlAllocatorTag cat;   /* _Ptr_cat: an empty tag object */

  stl_vector_ufill_n_impl_m(first, count, val, alloc, cat);
}

/* ---- stl_map_node_destroy1_m  0x004AF560 ---- HIGH */
void __cdecl stl_map_node_destroy1_m(seStrMapNode_t *node)
{
  stl_map_node_destroy_m(node);
}

/* ---- stl_map_nodeptr_destroy1_m  0x004AF570 ---- HIGH */
void stl_map_nodeptr_destroy1_m()
{
  ;
}

/* ---- stl_alloc_str_allocate2_m  0x004AF580 ----  IMPLEMENTED (retail) */
/*
 * Second copy of std::allocator<std::string>::allocate: operator new(count *
 * 0x1C).  No retail caller.  Retail is __usercall count@<eax>; it overwrites
 * its one caller-cleaned stack word with the byte count and tail-jumps to
 * operator new, which is the file's malloc.
 */
void *__cdecl stl_alloc_str_allocate2_m( unsigned int count, int unused )
{
  (void)unused;
  return crt_operator_new(count * sizeof(seStlStr_t));
}

/* ---- stl_vector_destroy_range_dup_m  0x004AF590 ---- MEDIUM */
/* std::_Destroy_range(first, last, al): forwards to the four-argument form with
 * the (empty) pointer category.  Retail: first on the stack, last@<edi>, al@<ecx>. */
void __cdecl stl_vector_destroy_range_dup_m(seStlStr_t *first, seStlStr_t *last, void *alloc)
{
  FxStlAllocatorTag cat;

  stl_vector_destroy_range_impl_m(first, last, alloc, cat);
}

/* ---- stl_map44_nodeptr_destroy1_m  0x004AF5B0 ---- HIGH */
void stl_map44_nodeptr_destroy1_m()
{
  ;
}

/* ---- stl_alloc_nodeptr104_rebind_ctor_m  0x004AF5C0 ---- HIGH */
void __stdcall stl_alloc_nodeptr104_rebind_ctor_m(int other)
{
  ;
}

/* ---- SE_UnusedStub1  0x004AF5D0 ---- HIGH */
/* retail 0x004AF5D0, IDA nullsub_83: bare retn 4, no xrefs; between the stringed STL allocator copies, name lost: descriptive name. */
void __stdcall SE_UnusedStub1(int a1)
{
  ;
}

/* ---- stl_alloc_node44_allocate2_m  0x004AF5E0 ----  IMPLEMENTED (retail) */
/*
 * Second copy of the 44-byte tree-node allocate: operator new(count * 0x2C).
 * No retail caller.  Retail is __usercall count@<eax>, one caller-cleaned
 * stack word reused as operator new's argument; operator new is malloc here.
 */
void *__cdecl stl_alloc_node44_allocate2_m( unsigned int count, int unused )
{
  (void)unused;
  return crt_operator_new(count * 44);
}

/* ---- SE_UnusedStub2  0x004AF5F0 ---- HIGH */
/* retail 0x004AF5F0, IDA nullsub_84: bare retn 4, no xrefs; between the stringed STL allocator copies, name lost: descriptive name. */
void __stdcall SE_UnusedStub2(int a1)
{
  ;
}

/* ---- stl_alloc_node104_allocate2_m  0x004AF600 ----  IMPLEMENTED (retail) */
/*
 * Second copy of the 104-byte tree-node allocate: operator new(count * 0x68).
 * No retail caller.  Retail is __usercall count@<eax>, one caller-cleaned
 * stack word reused as operator new's argument; operator new is malloc here.
 */
void *__cdecl stl_alloc_node104_allocate2_m( unsigned int count, int unused )
{
  (void)unused;
  return crt_operator_new(count * 104);
}

/* ---- stl_map_nodeptr_construct2_m  0x004AF610 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map_nodeptr_construct2_m(seStlTreeNode_t **result, seStlTreeNode_t **value)
{
  if ( result )
    *result = *value;
  return result;
}

/* ---- SE_UnusedStub3  0x004AF620 ---- HIGH */
/* retail 0x004AF620, IDA nullsub_85: bare retn 4, no xrefs; between the stringed STL allocator copies, name lost: descriptive name. */
void __stdcall SE_UnusedStub3(int a1)
{
  ;
}

/* ---- stl_map44_node_destroy1_m  0x004AF630 ---- HIGH */
int __cdecl stl_map44_node_destroy1_m(seStrSetNode_t *node)
{
  return stl_map44_node_destroy_m(node);
}

/* ---- stl_map44_nodeptr_construct2_m  0x004AF640 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_nodeptr_construct2_m(seStlTreeNode_t **result, seStlTreeNode_t **value)
{
  if ( result )
    *result = *value;
  return result;
}

/* ---- stl_map_node_scalar_delete_m  0x004AF650 ---- HIGH */
void *__stdcall stl_map_node_scalar_delete_m(void *node, char deleteFlags)
{
  stl_map_node_destroy_m(SE_MAPNODE(node));
  if ( (deleteFlags & 1) != 0 )
    operator delete(node);
  return node;
}

/* ---- stl_map44_node_scalar_delete_m  0x004AF670 ---- HIGH */
void *__stdcall stl_map44_node_scalar_delete_m(void *node, char deleteFlags)
{
  stl_map44_node_destroy_m(SE_SETNODE(node));
  if ( (deleteFlags & 1) != 0 )
    operator delete(node);
  return node;
}

/* ---- stl_map_node_destroy_m  0x004AF690 ----  IMPLEMENTED (retail) */
/*
 * allocator::destroy for a 104-byte tree node: runs ~pair<const std::string,
 * CStringEdString> on the payload at node+0x0C (after the three links).
 * Retail is __usercall: node@<eax>.  Retail never inlines either node
 * destroy (C++ destructor calls); auto_inline(off) keeps them out of line.
 */
#pragma auto_inline(off)
void __cdecl stl_map_node_destroy_m( seStrMapNode_t *node )
{
  stl_map_pair_destroy_m(&node->myval);
}

/* ---- stl_map44_node_destroy_m  0x004AF6A0 ---- HIGH */
int __cdecl stl_map44_node_destroy_m(seStrSetNode_t *node)
{
  seStlStr_t *key = &node->key;

  if ( key->capacity >= 0x10u )
    operator delete(key->bx.ptr);
  key->capacity = 15;
  key->size = 0;
  seStlStr_buf(key)[0] = 0;
  return 0;
}
#pragma auto_inline(on)

/* ---- stl_vector_iter_preinc_m  0x004AF6D0 ---- HIGH */
seStlStr_t **__cdecl stl_vector_iter_preinc_m(seStlStr_t **result)
{
  ++*result;
  return result;
}

/* ---- stl_vector_iter_ne_m  0x004AF6E0 ---- MEDIUM */
int __cdecl stl_vector_iter_ne_m(seStlStr_t **left, seStlStr_t **right)
{
  return *left != *right;
}

/* ---- stl_vector_iter_eq_m  0x004AF6F0 ---- MEDIUM */
int __cdecl stl_vector_iter_eq_m(seStlStr_t **left, seStlStr_t **right)
{
  return *right == *left;
}

/* ---- stl_map44_iter_cat_m  0x004AF700 ---- HIGH */
FxStlAllocatorTag *__cdecl stl_map44_iter_cat_m(FxStlAllocatorTag *result, int iter)
{
  FxStlAllocatorTag cat;   /* _Iter_cat: an empty tag object, copied out uninitialised */

  result->value = cat.value;
  return result;
}

/* ---- stl_map44_distance_dup_m  0x004AF710 ---- MEDIUM */
/* std::distance: walk [first, last), accumulating the step count into *count. */
void __cdecl stl_map44_distance_dup_m(int *count, seStlTreeNode_t *first, SeDistanceEnd last)
{
  seStlTreeNode_t *end;
  int  n;

  for ( end = last.pointer; first != end; stl_map44_iter_next_m(&first) )
  {
    n = *count + 1;
    *count = n;
  }
}

/* ---- stl_vector_ucopy_wrap_m  0x004AF740 ---- HIGH */
/* std::_Uninitialized_copy(first, last, dest, al): forwards with the pointer category.
 * Retail: (first, last) on the stack, dest@<edx>, al@<ecx>. */
seStlStr_t *__cdecl stl_vector_ucopy_wrap_m( SeStrIter first, SeStrIter last, seStlStr_t *dest, void *alloc )
{
  FxStlAllocatorTag cat;   /* _Ptr_cat(first, dest): an empty tag object */

  return stl_vector_ucopy_m(first, last, dest, alloc, cat);
}

/* ---- stl_vector_ptr_cat_backward_m  0x004AF770 ---- HIGH */
char __cdecl stl_vector_ptr_cat_backward_m(void)
{
  FxStlAllocatorTag cat;   /* _Ptr_cat: an empty tag object, returned uninitialised */

  return cat.value;
}

/* ---- stl_vector_ucopy_backward_m  0x004AF780 ----  IMPLEMENTED (retail) */
/*
 * std::copy_backward for std::string elements: assigns *--dest = *--last until
 * last reaches first, then stores the final dest iterator through result and
 * returns result (an empty range stores dest unchanged).  Retail is __cdecl;
 * its fifth (iterator-tag) stack word is never read.
 */
SeStrIter __cdecl stl_vector_ucopy_backward_m( SeStrIter first, SeStrIter last, SeStrIter dest, FxStlAllocatorTag cat )
{
  (void)cat;
  while ( first.ptr != last.ptr )
  {
    --last.ptr;
    --dest.ptr;
    stl_fxString_assignSubstr_m(dest.ptr, last.ptr, 0, 0xFFFFFFFF);   /* *--dest = *--last */
  }
  return dest;
}

/* ---- stl_vector_ptr_cat_ufill_m  0x004AF7D0 ---- HIGH */
char __cdecl stl_vector_ptr_cat_ufill_m(void)
{
  FxStlAllocatorTag cat;   /* _Ptr_cat: an empty tag object, returned uninitialised */

  return cat.value;
}

/* ---- stl_vector_ufill_n_impl_m  0x004AF7E0 ----  IMPLEMENTED (retail) */
/*
 * std::_Uninit_fill_n(first, count, val, al, tag) for std::string: placement-
 * constructs count copies of val at first (a null slot is skipped but still
 * stepped over) inside _TRY/_CATCH_ALL (destroy the elements built so far,
 * rethrow).  Retail is __usercall: count@<ecx>, then (first, val, al, tag) on
 * the stack; void.
 */
void __cdecl stl_vector_ufill_n_impl_m( seStlStr_t *first, unsigned int count, seStlStr_t *val, void *alloc, FxStlAllocatorTag cat )
{
  seStlStr_t *next = first;

  (void)cat;
  try
  {
    for ( ; 0 < count; --count, ++first )
      new ( first ) SeStrCopy( val );
  }
  catch ( ... )
  {
    for ( ; next != first; ++next )
      stl_string_tidy_m(next, (int)alloc);   /* allocator::destroy: ~basic_string() */
    throw;
  }
}

/* ---- stl_vector_destroy_range_impl_m  0x004AF880 ----  IMPLEMENTED (retail) */
/*
 * _Destroy_range over std::string elements [first, last): frees each heap
 * buffer (capacity >= 16) and resets the string to empty SSO state.
 * Retail is __usercall: first@<eax>, last@<edi>.
 */
void __cdecl stl_vector_destroy_range_impl_m( seStlStr_t *first, seStlStr_t *last, void *alloc, FxStlAllocatorTag cat )
{
  /* _Destroy_range(first, last, alloc, _Ptr_cat(first, last)): the allocator
     reference and the empty iterator-category tag are passed but never read. */
  for ( ; first != last; ++first )
  {
    if ( first->capacity >= 0x10u )
      operator delete(first->bx.ptr);
    first->capacity  = 15;
    first->size      = 0;
    seStlStr_buf(first)[0] = 0;
  }
}

/* ---- stl_string_construct_wrap_m  0x004AF8C0 ---- MEDIUM */
void __fastcall stl_string_construct_wrap_m(seStlStr_t *source, seStlStr_t *dest, SeStringPlacementAllocator allocator)
{
  (void)allocator;
  stl_string_construct_copy_m(SeStringDestinationArgument(dest),SeStringSourceArgument(source));
}

/* ---- stl_string_tidy_m  0x004AF8D0 ---- HIGH */
int __stdcall stl_string_tidy_m(seStlStr_t *self, int unused)
{
  seStlStr_t *s = self;

  if ( s->capacity >= 0x10u )
    operator delete(s->bx.ptr);
  s->capacity = 15;
  s->size = 0;
  seStlStr_buf(s)[0] = 0;
  return 0;
}

/* ---- stl_vector_iter_predec_m  0x004AF900 ---- HIGH */
seStlStr_t **__cdecl stl_vector_iter_predec_m(seStlStr_t **result)
{
  --*result;
  return result;
}

/* ---- stl_map44_iter_next_wrap_dup_m  0x004AF910 ---- MEDIUM */
seStlTreeNode_t **__cdecl stl_map44_iter_next_wrap_dup_m(seStlTreeNode_t **iter)
{
  stl_map44_iter_next_m(iter);
  return iter;
}

/* ---- stl_vector_ptr_cat_ucopy_m  0x004AF920 ---- HIGH */
char __cdecl stl_vector_ptr_cat_ucopy_m(void)
{
  FxStlAllocatorTag cat;   /* _Ptr_cat: an empty tag object, returned uninitialised */

  return cat.value;
}

/* ---- stl_vector_ucopy_m  0x004AF930 ---- HIGH */
/* Uninitialized copy of the seStlStr_t range [src, srcEnd) into dst. */
seStlStr_t *__cdecl stl_vector_ucopy_m( SeStrIter first, SeStrIter last, seStlStr_t *dest, void *alloc, FxStlAllocatorTag cat )
{
  seStlStr_t *next = dest;

  (void)cat;
  try
  {
    for ( ; first.ptr != last.ptr; ++dest, ++first.ptr )
      new ( dest ) SeStrCopy( first.ptr );
  }
  catch ( ... )
  {
    for ( ; next != dest; ++next )
      stl_string_tidy_m(next, (int)alloc);   /* allocator::destroy: ~basic_string() */
    throw;
  }
  return dest;
}

/* ---- stl_string_construct_copy_m  0x004AF9D0 ----  IMPLEMENTED (retail) */
/*
 * allocator<std::string>::construct(dest, src): placement copy-construct a
 * std::string at dest (skipped for a null dest).  Returns what retail leaves
 * in eax: 0 for a null dest, otherwise assign's return value (dest).  The
 * retail EH frame only covers placement delete on a throw.
 */
__declspec(noinline) void __cdecl stl_string_construct_copy_m(SeStringPlacementDestination position, SeStringPlacementSource value)
{
  new ( position.dest ) SeStrCopy( value.source );   /* new ((void *)ptr) std::string(val) */
}

/* ---- stl_string_tidy_dup_m  0x004AFA30 ---- MEDIUM */
int __cdecl stl_string_tidy_dup_m(seStlStr_t *self)
{
  seStlStr_t *s = self;

  if ( s->capacity >= 0x10u )
    operator delete(s->bx.ptr);
  s->capacity = 15;
  s->size = 0;
  seStlStr_buf(s)[0] = 0;
  return 0;
}

/* ---- stl_string_scalar_delete_m  0x004AFA60 ---- HIGH */
seStlStr_t *__stdcall stl_string_scalar_delete_m(seStlStr_t *self, char deleteFlags)
{
  seStlStr_t *s = self;

  if ( s->capacity >= 0x10u )
    operator delete(s->bx.ptr);
  s->size = 0;
  s->capacity = 15;
  seStlStr_buf(s)[s->size] = 0;         /* _Eos(0): indexed by the size just stored */
  if ( (deleteFlags & 1) != 0 )   /* scalar-deleting dtor: bit 0 => free the object */
    operator delete(self);
  return self;
}

/* ---- stl_char_traits_assign_m  0x004AFAA0 ---- HIGH */
/* std::char_traits<char>::assign: fill dest[0..count) with the byte `ch`. */
char *__cdecl stl_char_traits_assign_m(char ch, char *dest, unsigned int count)
{
  return (char *)memset(dest,ch,count);
}

/* ---- SE_LoadFile_m  0x004AFAD0 ---- VERIFIED */
void *__cdecl SE_LoadFile_m(char *qpath, int *lenOut)
{
  int len;
  void *buffer;
  void *result=0;
  if (lenOut) *lenOut=0;
  len=FS_ReadFile(qpath,&buffer);
  if (len>0) {
    result=buffer;
    if (lenOut) *lenOut=len;
  }
  return result;
}

/* ---- SE_FreeFile_m  0x004AFB00 ---- VERIFIED */
void __cdecl SE_FreeFile_m(void *buffer)
{
  if ( buffer )
    FS_FreeFile(buffer);
}

/* ---- SE_EnumerateStrFiles_m  0x004AFB10 ----  IMPLEMENTED (retail) */
/*
 * Recursively collect every file with the given extension under path into the
 * std::string out as "path/file;" entries (the ';'-separated list that
 * SE_NextSemicolonToken_m walks), bumping seStrFileCount per file.  The
 * subdirectories come first ("/" is the directories-only extension), skipping
 * names that are empty or start with '.'.  Both file lists are released with
 * FS_FreeFileList (inlined by LTCG).  The 64-byte path buffer is
 * filled with an unbounded sprintf, as in retail.
 */
void __cdecl SE_EnumerateStrFiles_m( const char *extension, const char *path, seStlStr_t *out )
{
  char    buffer[64];
  char  **dirs;
  char  **files;
  int     numDirs;
  int     numFiles;
  int     i;

  dirs = FS_ListFilteredFiles(path, "/", 0, &numDirs);
  for ( i = 0; i < numDirs; i++ )
  {
    if ( dirs[i][0] && dirs[i][0] != '.' )
    {
      sprintf(buffer, "%s/%s", path, dirs[i]);
      SE_EnumerateStrFiles_m(extension, buffer, out);
    }
  }

  files = FS_ListFilteredFiles(path, extension, 0, &numFiles);
  for ( i = 0; i < numFiles; i++ )
  {
    sprintf(buffer, "%s/%s", path, files[i]);
    stl_string_append_m(out, buffer, strlen(buffer));
    stl_string_append_fill_m(out, 1, ';');
    ++seStrFileCount;
  }

  FS_FreeFileList(files);
  FS_FreeFileList(dirs);
}

/* ---- SE_CountStrFiles_m  0x004AFC80 ----  IMPLEMENTED (retail) */
/*
 * Reset seStrFileCount, clear out (assign ""), gather every .str file under
 * path into it and return how many were found.
 * Retail is __usercall: out@<esi>, path on the stack.
 */
int __cdecl SE_CountStrFiles_m( seStlStr_t *out, const char *path )
{
  seStrFileCount = 0;
  {
    const char *emptyText = "";   /* 0x00559228 */
    stl_fxString_assignPtrCount_m(out, FxConstCharArgument(emptyText), FxCountArgument((unsigned int)strlen(emptyText)));
  }
  SE_EnumerateStrFiles_m(".str", path, out);
  return seStrFileCount;
}

/* ---- stl_string_append_char_m  0x004AFCD0 ----  IMPLEMENTED (retail) */
/*
 * std::string::append(1, ch) (operator+= / push_back); returns self.  No
 * retail caller.  Retail is __usercall: ch@<al>, self@<esi>.
 */
seStlStr_t *__cdecl stl_string_append_char_m( seStlStr_t *self, char ch )
{
  return stl_string_append_fill_m(self, 1, ch);
}

/* ---- stl_string_append_fill_m  0x004AFCE0 ----  IMPLEMENTED (retail) */
/*
 * std::string::append(size_type count, char ch); returns self.  _Grow(size +
 * count), fill the new tail with ch (char_traits::assign, inlined as a
 * dword-then-byte rep stos), then _Eos.  The two _Xlen throws (length_error
 * "string too long") are std::_String_base::_Xlen.
 * Retail is __userpurge: count@<eax>, self@<esi>, ch on the stack, retn 4.
 */
seStlStr_t *__stdcall stl_string_append_fill_m( seStlStr_t *self, unsigned int count, char ch )
{
  FxString     *str = (FxString *)self;
  unsigned int  num;

  if ( 0xFFFFFFFFu - str->size <= count )    /* npos - _Mysize <= count */
    ( (const std::_String_base *)str )->_Xlen();   /* result too long */
  if ( 0 < count )
  {
    num = str->size + count;
    if ( str->Grow( num, false ) )
    {
      /* make room and append new stuff using assign */
      memset(SE_FXPTR( str ) + str->size, ch, count);
      str->size = num;   /* _Eos(num) */
      SE_FXPTR( str )[num] = 0;
    }
  }
  return self;
}

/*
 * RFC 1321 MD5 core.  F/G/H/I are the four per-round nonlinear mixing
 * functions; FF/GG/HH/II apply one step: a = b + rotl(a + mix + X + T, s).
 * These are #undef'd immediately after MD5Transform.
 */
#define MD5_F(x, y, z) (((x) & (y)) | (~(x) & (z)))
#define MD5_G(x, y, z) (((x) & (z)) | ((y) & ~(z)))
#define MD5_H(x, y, z) ((x) ^ (y) ^ (z))
#define MD5_I(x, y, z) ((y) ^ ((x) | ~(z)))
#define MD5_ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define FF(a, b, c, d, x, s, ac) {(a) += MD5_F ((b), (c), (d)) + (x) + (UINT4)(ac); (a) = MD5_ROTL ((a), (s)); (a) += (b); }
#define GG(a, b, c, d, x, s, ac) {(a) += MD5_G ((b), (c), (d)) + (x) + (UINT4)(ac); (a) = MD5_ROTL ((a), (s)); (a) += (b); }
#define HH(a, b, c, d, x, s, ac) {(a) += MD5_H ((b), (c), (d)) + (x) + (UINT4)(ac); (a) = MD5_ROTL ((a), (s)); (a) += (b); }
#define II(a, b, c, d, x, s, ac) {(a) += MD5_I ((b), (c), (d)) + (x) + (UINT4)(ac); (a) = MD5_ROTL ((a), (s)); (a) += (b); }

typedef unsigned int UINT4;

/* ---- MD5Transform  0x004AFDB0 ---- VERIFIED */
/* RSA Transform (buf, in): the state words first, then the 16 input words. */
__declspec(noinline) void __cdecl MD5Transform( UINT4 *buf, UINT4 *in )
{
  UINT4 a = buf[0], b = buf[1], c = buf[2], d = buf[3];

  /* Round 1 */
  FF ( a, b, c, d, in[ 0],  7, 0xd76aa478u); /* 1 */
  FF ( d, a, b, c, in[ 1], 12, 0xe8c7b756u); /* 2 */
  FF ( c, d, a, b, in[ 2], 17, 0x242070dbu); /* 3 */
  FF ( b, c, d, a, in[ 3], 22, 0xc1bdceeeu); /* 4 */
  FF ( a, b, c, d, in[ 4],  7, 0xf57c0fafu); /* 5 */
  FF ( d, a, b, c, in[ 5], 12, 0x4787c62au); /* 6 */
  FF ( c, d, a, b, in[ 6], 17, 0xa8304613u); /* 7 */
  FF ( b, c, d, a, in[ 7], 22, 0xfd469501u); /* 8 */
  FF ( a, b, c, d, in[ 8],  7, 0x698098d8u); /* 9 */
  FF ( d, a, b, c, in[ 9], 12, 0x8b44f7afu); /* 10 */
  FF ( c, d, a, b, in[10], 17, 0xffff5bb1u); /* 11 */
  FF ( b, c, d, a, in[11], 22, 0x895cd7beu); /* 12 */
  FF ( a, b, c, d, in[12],  7, 0x6b901122u); /* 13 */
  FF ( d, a, b, c, in[13], 12, 0xfd987193u); /* 14 */
  FF ( c, d, a, b, in[14], 17, 0xa679438eu); /* 15 */
  FF ( b, c, d, a, in[15], 22, 0x49b40821u); /* 16 */

  /* Round 2 */
  GG ( a, b, c, d, in[ 1],  5, 0xf61e2562u); /* 17 */
  GG ( d, a, b, c, in[ 6],  9, 0xc040b340u); /* 18 */
  GG ( c, d, a, b, in[11], 14, 0x265e5a51u); /* 19 */
  GG ( b, c, d, a, in[ 0], 20, 0xe9b6c7aau); /* 20 */
  GG ( a, b, c, d, in[ 5],  5, 0xd62f105du); /* 21 */
  GG ( d, a, b, c, in[10],  9, 0x02441453u); /* 22 */
  GG ( c, d, a, b, in[15], 14, 0xd8a1e681u); /* 23 */
  GG ( b, c, d, a, in[ 4], 20, 0xe7d3fbc8u); /* 24 */
  GG ( a, b, c, d, in[ 9],  5, 0x21e1cde6u); /* 25 */
  GG ( d, a, b, c, in[14],  9, 0xc33707d6u); /* 26 */
  GG ( c, d, a, b, in[ 3], 14, 0xf4d50d87u); /* 27 */
  GG ( b, c, d, a, in[ 8], 20, 0x455a14edu); /* 28 */
  GG ( a, b, c, d, in[13],  5, 0xa9e3e905u); /* 29 */
  GG ( d, a, b, c, in[ 2],  9, 0xfcefa3f8u); /* 30 */
  GG ( c, d, a, b, in[ 7], 14, 0x676f02d9u); /* 31 */
  GG ( b, c, d, a, in[12], 20, 0x8d2a4c8au); /* 32 */

  /* Round 3 */
  HH ( a, b, c, d, in[ 5],  4, 0xfffa3942u); /* 33 */
  HH ( d, a, b, c, in[ 8], 11, 0x8771f681u); /* 34 */
  HH ( c, d, a, b, in[11], 16, 0x6d9d6122u); /* 35 */
  HH ( b, c, d, a, in[14], 23, 0xfde5380cu); /* 36 */
  HH ( a, b, c, d, in[ 1],  4, 0xa4beea44u); /* 37 */
  HH ( d, a, b, c, in[ 4], 11, 0x4bdecfa9u); /* 38 */
  HH ( c, d, a, b, in[ 7], 16, 0xf6bb4b60u); /* 39 */
  HH ( b, c, d, a, in[10], 23, 0xbebfbc70u); /* 40 */
  HH ( a, b, c, d, in[13],  4, 0x289b7ec6u); /* 41 */
  HH ( d, a, b, c, in[ 0], 11, 0xeaa127fau); /* 42 */
  HH ( c, d, a, b, in[ 3], 16, 0xd4ef3085u); /* 43 */
  HH ( b, c, d, a, in[ 6], 23, 0x04881d05u); /* 44 */
  HH ( a, b, c, d, in[ 9],  4, 0xd9d4d039u); /* 45 */
  HH ( d, a, b, c, in[12], 11, 0xe6db99e5u); /* 46 */
  HH ( c, d, a, b, in[15], 16, 0x1fa27cf8u); /* 47 */
  HH ( b, c, d, a, in[ 2], 23, 0xc4ac5665u); /* 48 */

  /* Round 4 */
  II ( a, b, c, d, in[ 0],  6, 0xf4292244u); /* 49 */
  II ( d, a, b, c, in[ 7], 10, 0x432aff97u); /* 50 */
  II ( c, d, a, b, in[14], 15, 0xab9423a7u); /* 51 */
  II ( b, c, d, a, in[ 5], 21, 0xfc93a039u); /* 52 */
  II ( a, b, c, d, in[12],  6, 0x655b59c3u); /* 53 */
  II ( d, a, b, c, in[ 3], 10, 0x8f0ccc92u); /* 54 */
  II ( c, d, a, b, in[10], 15, 0xffeff47du); /* 55 */
  II ( b, c, d, a, in[ 1], 21, 0x85845dd1u); /* 56 */
  II ( a, b, c, d, in[ 8],  6, 0x6fa87e4fu); /* 57 */
  II ( d, a, b, c, in[15], 10, 0xfe2ce6e0u); /* 58 */
  II ( c, d, a, b, in[ 6], 15, 0xa3014314u); /* 59 */
  II ( b, c, d, a, in[13], 21, 0x4e0811a1u); /* 60 */
  II ( a, b, c, d, in[ 4],  6, 0xf7537e82u); /* 61 */
  II ( d, a, b, c, in[11], 10, 0xbd3af235u); /* 62 */
  II ( c, d, a, b, in[ 2], 15, 0x2ad7d2bbu); /* 63 */
  II ( b, c, d, a, in[ 9], 21, 0xeb86d391u); /* 64 */

  buf[0] += a;
  buf[1] += b;
  buf[2] += c;
  buf[3] += d;
}
#undef MD5_F
#undef MD5_G
#undef MD5_H
#undef MD5_I
#undef MD5_ROTL
#undef FF
#undef GG
#undef HH
#undef II

/* RSA Data Security MD5 (1990 md5.c): MD5_CTX and the byte-wise update */
typedef struct {
  UINT4 i[2];                   /* number of _bits_ handled mod 2^64 */
  UINT4 buf[4];                                    /* scratch buffer */
  unsigned char in[64];                              /* input buffer */
  unsigned char digest[16];     /* actual digest after MD5Final call */
} MD5_CTX;

/* ---- MD5Init  0x004B0700 ----  (unnamed in the retail IDB; no callers) */
/* RSA MD5Init with the seeded constants; LTCG gives the unreferenced extern a
 * register convention (mdContext@ecx, pseudoRandomNumber@eax). */
void __cdecl MD5Init( MD5_CTX *mdContext, unsigned long pseudoRandomNumber )
{
  mdContext->i[0] = mdContext->i[1] = (UINT4)0;

  /* Load magic initialization constants. */
  mdContext->buf[0] = (UINT4)0x67452301 + ( pseudoRandomNumber * 11 );
  mdContext->buf[1] = (UINT4)0xefcdab89 + ( pseudoRandomNumber * 71 );
  mdContext->buf[2] = (UINT4)0x98badcfe + ( pseudoRandomNumber * 37 );
  mdContext->buf[3] = (UINT4)0x10325476 + ( pseudoRandomNumber * 97 );
}

/* ---- MD5Update  0x004B0750 ---- VERIFIED */
void __cdecl MD5Update( unsigned int inLen, MD5_CTX *mdContext, unsigned char *inBuf )
{
  UINT4 in[16];
  int mdi;
  unsigned int i, ii;

  /* compute number of bytes mod 64 */
  mdi = (int)((mdContext->i[0] >> 3) & 0x3F);

  /* update number of bits */
  if ((mdContext->i[0] + ((UINT4)inLen << 3)) < mdContext->i[0])
    mdContext->i[1]++;
  mdContext->i[0] += ((UINT4)inLen << 3);
  mdContext->i[1] += ((UINT4)inLen >> 29);

  while (inLen--) {
    /* add new character to buffer, increment mdi */
    mdContext->in[mdi++] = *inBuf++;

    /* transform if necessary */
    if (mdi == 0x40) {
      for (i = 0, ii = 0; i < 16; i++, ii += 4)
        in[i] = (((UINT4)mdContext->in[ii+3]) << 24) |
                (((UINT4)mdContext->in[ii+2]) << 16) |
                (((UINT4)mdContext->in[ii+1]) << 8) |
                ((UINT4)mdContext->in[ii]);
      MD5Transform (mdContext->buf, in);
      mdi = 0;
    }
  }
}

/* ---- MD5Final  0x004B08C0 ---- VERIFIED */
void __cdecl MD5Final( MD5_CTX *mdContext )
{
  UINT4 in[16];
  int mdi;
  unsigned int i, ii;
  unsigned int padLen;

  /* save number of bits */
  in[14] = mdContext->i[0];
  in[15] = mdContext->i[1];

  /* compute number of bytes mod 64 */
  mdi = (int)((mdContext->i[0] >> 3) & 0x3F);

  /* pad out to 56 mod 64 */
  padLen = (mdi < 56) ? (56 - mdi) : (120 - mdi);
  MD5Update (padLen, mdContext, MD5_PADDING);

  /* append length in bits and transform */
  for (i = 0, ii = 0; i < 14; i++, ii += 4)
    in[i] = (((UINT4)mdContext->in[ii+3]) << 24) |
            (((UINT4)mdContext->in[ii+2]) << 16) |
            (((UINT4)mdContext->in[ii+1]) << 8) |
            ((UINT4)mdContext->in[ii]);
  MD5Transform (mdContext->buf, in);

  /* store buffer in digest */
  for (i = 0, ii = 0; i < 4; i++, ii += 4) {
    mdContext->digest[ii] = (unsigned char)(mdContext->buf[i] & 0xFF);
    mdContext->digest[ii+1] =
      (unsigned char)((mdContext->buf[i] >> 8) & 0xFF);
    mdContext->digest[ii+2] =
      (unsigned char)((mdContext->buf[i] >> 16) & 0xFF);
    mdContext->digest[ii+3] =
      (unsigned char)((mdContext->buf[i] >> 24) & 0xFF);
  }
}

#ifdef __cplusplus
}
#endif
