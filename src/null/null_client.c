/*
 * null/null_client.c -- the client half of the engine, for the dedicated
 * server build only.  Quake III's null_client.c shape: every entry point
 * common and server code call into the client is here as an empty body, so
 * the dedicated exe links without client_mp/, the renderer, the sound engine
 * or the two client VMs.  Nothing in here is retail code; retail's Windows
 * client is one binary and reads `dedicated` at run time, and its Linux
 * dedicated server (cod_lnxded) is the binary this build imitates.
 */

#include "qcommon.h"
#include "../renderer/tr_public.h"

vm_t    *cgvm;
vm_t    *uivm;

/* Client and renderer state that the units this build shares with the client
 * (qcommon, server, win32, jpeg, stringed, fx) still name.  The client build
 * defines each in its owner: cls, clc, re and the cvars in client_mp/cl_main_mp.c,
 * cl_connectedToPureServer in cl_parse_mp.c, scr_updatingScreen in cl_scrn_mp.c,
 * ri in renderer/tr_main.c, the debug colours in renderer/tr_debug.c.  RTCW's
 * null_client.c keeps cl_shownet and cl_language the same way. */
clientStatic_t      cls;
clientConnection_t  clc;
refexport_t         re;
refimport_t         ri;
int                 cl_connectedToPureServer;
int                 scr_updatingScreen;
char                cl_cdkeychecksum[10];   /* client: client_mp/cl_refstorage.c; read by qcommon/common.c */
cvar_t  *cl_shownet;
cvar_t  *cl_language;
cvar_t  *cl_languagetranslate;
cvar_t  *cl_languagewarnings;
cvar_t  *cl_languagewarningsaserrors;
cvar_t  *fx_count;
cvar_t  *fx_cull;
cvar_t  *fx_debug;
cvar_t  *fx_debugBolt;
cvar_t  *fx_draw;
cvar_t  *fx_enable;
cvar_t  *fx_freeze;
unsigned int colorDebugRed[9];
unsigned int colorDebugGreen[5];
unsigned int colorDebugBlue[92];
unsigned int colorDebugYellow[88];

void CL_Init( void ) {
}

void CL_Shutdown( void ) {
}

void CL_Frame( int msec ) {
	(void)msec;
}

void CL_Disconnect( qboolean showMainMenu ) {
	(void)showMainMenu;
}

void CL_ShutdownAll( void ) {
}

void CL_ShutdownRef( void ) {
}

void CL_ShutdownCGame( void ) {
}

void CL_ShutdownUI( void ) {
}

void CL_FlushMemory( void ) {
}

void CL_StartHunkUsers( void ) {
}

void CL_MapLoading( void ) {
}

void CL_ForwardCommandToServer( const char *string ) {
	(void)string;
}

void CL_ConsolePrint( int channel, const char *txt, int msgtime, int width ) {
	(void)channel; (void)txt; (void)msgtime; (void)width;
}

void CL_ConsoleFixPosition( void ) {
}

void CL_PacketEvent( netadr_t from, msg_t *msg ) {
	(void)from; (void)msg;
}

void CL_KeyEvent( int key, int down, unsigned time ) {
	(void)key; (void)down; (void)time;
}

void CL_CharEvent( int key ) {
	(void)key;
}

void CL_MouseEvent( int dx, int dy, int time ) {
	(void)dx; (void)dy; (void)time;
}

void CL_JoystickEvent( int axis, int value, int time ) {
	(void)axis; (void)value; (void)time;
}

void CL_InitKeyCommands( void ) {
}

void Key_WriteBindings( fileHandle_t f ) {
	(void)f;
}

void Key_Bind_f( void ) {
}

void Key_Bindlist_f( void ) {
}

void Key_Unbind_f( void ) {
}

void Key_UnbindAll_f( void ) {
}

qboolean CL_CDKeyValidate( const char *key, const char *checksum ) {
	(void)key; (void)checksum;
	return qtrue;
}

void CL_Netchan_PrintProfileStats( qboolean bPrintToConsole ) {
	(void)bPrintToConsole;
}

void CIN_CloseAllVideos( void ) {
}

/* the server's debug-draw requests are drawn by the client; nobody here */
void CL_AddDebugLine( const float *start, const float *end, const float *color,
					  int depthTest, int duration, int fromServer ) {
	(void)start; (void)end; (void)color;
	(void)depthTest; (void)duration; (void)fromServer;
}

void CL_AddDebugString( const float *origin, const float *color, float scale,
						const char *text, int fromServer ) {
	(void)origin; (void)color; (void)scale; (void)text; (void)fromServer;
}

void CL_FlushDebugData( int fromServer ) {
	(void)fromServer;
}

/* server_mp/sv_game_mp.c asks the client whether a DObj's skeleton is current;
 * the dedicated server has no renderer, so report "not up to date". */
qboolean CL_DObjSkelAreBonesUpToDate( int dobj, const int *partBits ) {
	(void)dobj; (void)partBits;
	return qfalse;
}

/* miles/ is not linked into the dedicated server, but the shared FX unit still
 * names its sound entry point.  Silence it. */
int __cdecl MSS_PlaySoundAlias_Internal( void *alias, float *alias2, float blend,
                                         int entnum, float *origin, int *outChan,
                                         int startMs ) {
	(void)alias; (void)alias2; (void)blend; (void)entnum;
	(void)origin; (void)outChan; (void)startMs;
	return 0;
}
