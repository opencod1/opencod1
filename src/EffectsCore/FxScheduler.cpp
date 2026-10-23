/*
 * Reconstructed from Call of Duty 1.1 (Windows, CoDMP.exe).
 * Original translation unit:
 * /Volumes/BigCheese/ Source/AspyrP4/CoD/Source/EffectsCore/FxScheduler.cpp
 * Only the unit's pool dynamic initializers are reconstructed so far.
 */

#include <math.h>

/* The pool objects are defined with C linkage in FxMemMgr.cpp; keep these
 * initializers matching so the linker resolves them. */
#ifdef __cplusplus
extern "C" {
#endif

/*
 * The scheduler's two block pools ({ elements per 32K block, free list }, see
 * FxPrimitives.cpp), defined with the arena in FxMemMgr.cpp; retail keeps them
 * in BSS beside theFxScheduler (0x014075A0).  Their C++ dynamic initializers
 * floor a compile-time count (CRT _floor, _ftol2) and clear the free list.
 * Retail lists them at __xc_a + 0x10 and + 0x14 of .CRT$XCU, just before the
 * theFxScheduler constructor (__xc_a + 0x18, FxScheduler_static_init, which
 * the tree still runs from Com_Init through FX_StaticInit in FxMemMgr.cpp).
 */
extern int fxPool_PrimitiveTemplate[2];   /* 0x0140758C */
extern int fxPool_ScheduledEffect[2];     /* 0x01407594 */

/* ---- fxPool_PrimitiveTemplate_static_init  0x0053C180 ---- */
static void __cdecl fxPool_PrimitiveTemplate_static_init( void )
{
	fxPool_PrimitiveTemplate[0] = (int)floor( 54.0 );
	fxPool_PrimitiveTemplate[1] = 0;
}

/* ---- fxPool_ScheduledEffect_static_init  0x0053C1B0 ---- */
static void __cdecl fxPool_ScheduledEffect_static_init( void )
{
	fxPool_ScheduledEffect[0] = (int)floor( 481.0 );
	fxPool_ScheduledEffect[1] = 0;
}

/* The unit's .CRT$XCU entries; the CRT's _initterm calls them before WinMain. */
typedef void ( __cdecl *fxSchedulerStaticInit_t )( void );
#pragma data_seg( ".CRT$XCU" )
static fxSchedulerStaticInit_t fxSchedulerStaticInit[] = {
	fxPool_PrimitiveTemplate_static_init,
	fxPool_ScheduledEffect_static_init,
};
#pragma data_seg()

#ifdef __cplusplus
}
#endif
