/*
 * Reconstructed from Call of Duty 1.1 (Windows, CoDMP.exe).
 * Original translation unit:
 * /Volumes/BigCheese/ Source/AspyrP4/CoD/Source/EffectsCore/FxPrimitives.cpp
 * Only the unit's C++ dynamic initializers are reconstructed so far.
 */

#include <math.h>

/* The pool objects are defined with C linkage in FxMemMgr.cpp; keep these
 * initializers matching so the linker resolves them. */
#ifdef __cplusplus
extern "C" {
#endif

/*
 * The primitive block pools.  Each is { elements per 32K block, free list },
 * handed to the FxPool_Alloc / FxPool_Free helpers.  The objects live with the
 * arena in FxMemMgr.cpp (retail keeps them zeroed, in BSS 0x0140C9B8..
 * 0x0140CA1F).  Their element counts are set at startup by this unit's C++
 * dynamic initializers: each floors a compile-time constant (CRT _floor, then
 * _ftol2) and clears the free list.  Retail lists the thirteen initializers at
 * __xc_a + 0x1C .. + 0x4C of .CRT$XCU, in the order below.
 */
extern int fxPool_Emitter[2];             /* 0x0140C9B8 */
extern int fxPool_Electricity[2];         /* 0x0140C9C0 */
extern int fxPool_Model[2];               /* 0x0140C9C8 */
extern int fxPool_Particle[2];            /* 0x0140C9D0 */
extern int fxPool_Cylinder[2];            /* 0x0140C9D8 */
extern int fxPool_BoltFrame[2];           /* 0x0140C9E0 */
extern int fxPool_Light[2];               /* 0x0140C9E8 */
extern int fxPool_Decal[2];               /* 0x0140C9F0 */
extern int fxPool_OrientedParticle[2];    /* 0x0140C9F8 */
extern int fxPool_Tail[2];                /* 0x0140CA00 */
extern int fxPool_Effect[2];              /* 0x0140CA08 */
extern int fxPool_Quad[2];                /* 0x0140CA10 */
extern int fxPool_Line[2];                /* 0x0140CA18 */

/* ---- fxPool_BoltFrame_static_init  0x0053BF10 ---- */
static void __cdecl fxPool_BoltFrame_static_init( void )
{
	fxPool_BoltFrame[0] = (int)floor( 481.0 );
	fxPool_BoltFrame[1] = 0;
}

/* ---- fxPool_Model_static_init  0x0053BF40 ---- */
static void __cdecl fxPool_Model_static_init( void )
{
	fxPool_Model[0] = (int)floor( 209.0 );
	fxPool_Model[1] = 0;
}

/* ---- fxPool_Effect_static_init  0x0053BF70 ---- */
static void __cdecl fxPool_Effect_static_init( void )
{
	fxPool_Effect[0] = (int)floor( 148.0 );
	fxPool_Effect[1] = 0;
}

/* ---- fxPool_Quad_static_init  0x0053BFA0 ---- */
static void __cdecl fxPool_Quad_static_init( void )
{
	fxPool_Quad[0] = (int)floor( 58.0 );
	fxPool_Quad[1] = 0;
}

/* ---- fxPool_Light_static_init  0x0053BFD0 ---- */
static void __cdecl fxPool_Light_static_init( void )
{
	fxPool_Light[0] = (int)floor( 125.0 );
	fxPool_Light[1] = 0;
}

/* ---- fxPool_Particle_static_init  0x0053C000 ---- */
static void __cdecl fxPool_Particle_static_init( void )
{
	fxPool_Particle[0] = (int)floor( 103.0 );
	fxPool_Particle[1] = 0;
}

/* ---- fxPool_Line_static_init  0x0053C030 ---- */
static void __cdecl fxPool_Line_static_init( void )
{
	fxPool_Line[0] = (int)floor( 99.0 );
	fxPool_Line[1] = 0;
}

/* ---- fxPool_Electricity_static_init  0x0053C060 ---- */
static void __cdecl fxPool_Electricity_static_init( void )
{
	fxPool_Electricity[0] = (int)floor( 45.0 );
	fxPool_Electricity[1] = 0;
}

/* ---- fxPool_OrientedParticle_static_init  0x0053C090 ---- */
static void __cdecl fxPool_OrientedParticle_static_init( void )
{
	fxPool_OrientedParticle[0] = (int)floor( 99.0 );
	fxPool_OrientedParticle[1] = 0;
}

/* ---- fxPool_Tail_static_init  0x0053C0C0 ---- */
static void __cdecl fxPool_Tail_static_init( void )
{
	fxPool_Tail[0] = (int)floor( 95.0 );
	fxPool_Tail[1] = 0;
}

/* ---- fxPool_Cylinder_static_init  0x0053C0F0 ---- */
static void __cdecl fxPool_Cylinder_static_init( void )
{
	fxPool_Cylinder[0] = (int)floor( 95.0 );
	fxPool_Cylinder[1] = 0;
}

/* ---- fxPool_Emitter_static_init  0x0053C120 ---- */
static void __cdecl fxPool_Emitter_static_init( void )
{
	fxPool_Emitter[0] = (int)floor( 82.0 );
	fxPool_Emitter[1] = 0;
}

/* ---- fxPool_Decal_static_init  0x0053C150 ---- */
static void __cdecl fxPool_Decal_static_init( void )
{
	fxPool_Decal[0] = (int)floor( 75.0 );
	fxPool_Decal[1] = 0;
}

/* The unit's .CRT$XCU entries; the CRT's _initterm calls them before WinMain. */
typedef void ( __cdecl *fxPrimitivesStaticInit_t )( void );
#pragma data_seg( ".CRT$XCU" )
static fxPrimitivesStaticInit_t fxPrimitivesStaticInit[] = {
	fxPool_BoltFrame_static_init,
	fxPool_Model_static_init,
	fxPool_Effect_static_init,
	fxPool_Quad_static_init,
	fxPool_Light_static_init,
	fxPool_Particle_static_init,
	fxPool_Line_static_init,
	fxPool_Electricity_static_init,
	fxPool_OrientedParticle_static_init,
	fxPool_Tail_static_init,
	fxPool_Cylinder_static_init,
	fxPool_Emitter_static_init,
	fxPool_Decal_static_init,
};
#pragma data_seg()

#ifdef __cplusplus
}
#endif
