/*
 * @fidelity: verified
 * @fidelity-default: verified
 */

#include "../qcommon/qcommon.h"
#include "cl_records.h"
#include "cl_vm.h"
#include "cl_local.h"

/* cl.snap.valid (0x01432964), the head of the cl.snap record (storage in cl_main_mp.c) */
extern int cl_snap_valid;

/* cvars (RTCW cl_input.c; registered in CL_Init) */
cvar_t *cl_bypassMouseInput;        /* 0x0142F604 */
cvar_t *cl_run;                     /* 0x0142F614 */
cvar_t *cl_stance;                  /* 0x0142F5E8 */
cvar_t *cl_stanceTemp;              /* 0x0142F5F0 */
cvar_t *cl_anglespeedkey;
cvar_t *cl_pitchspeed;
cvar_t *cl_yawspeed;

/* cvars registered in CL_InitInput */
cvar_t *cl_debugMove;
cvar_t *cl_nodelta;

/* RTCW cl_input.c input state */
kbutton_t kb[NUM_BUTTONS];   /* 0x0087A028 */
int cl_lastStandTime;
int cl_oldFrameTime;                /* old_com_frameTime */
unsigned int frame_msecStorage;   /* 0x0142F608, frame_msec */

/* cl_local.h declares these; retail keeps the input ring and the current
 * server id in this unit's tail (0x0143A948..0x0143A9AC). */
int cl_mouseDx[11];                 /* 0x0143A948 */
int cl_mouseDy[9];                  /* 0x0143A950 */
int cl_mouseIndex;                  /* 0x0143A958 */
int cl_joystickAxis[6];             /* 0x0143A95C */
int cl_serverId;                    /* 0x0143A9AC */

extern void CL_Netchan_Encode( byte *data, int length );
extern void MSG_SetDefaultUserCmd( const byte *ps, usercmd_t *ucmd );
extern void MSG_WriteBits( msg_t *msg, int value, int bits );
extern int  MSG_WriteBitsCompress( const byte *datasrc, int bytecount, byte *buffdest );
extern void MSG_WriteByte( msg_t *msg, int c );
extern void MSG_WriteLong( msg_t *msg, int c );
extern void MSG_WriteDeltaUsercmdKey( msg_t *msg, int key, const usercmd_t *from,
									  const usercmd_t *to );
extern void MSG_WriteString( msg_t *sb, const char *s );
extern void Netchan_Transmit( netchan_t *chan, int length, const byte *data );
extern void Netchan_TransmitNextFragment( netchan_t *chan );
extern int  Com_HashKey( const char *string, int maxlen );

#define in_strafe_active		( kb[KB_STRAFE].active )		/* 0x0087A0F8 */
#define in_speed_active			( kb[KB_SPEED].active )		/* 0x0087A110 */
#define in_down_active			( kb[KB_DOWN].active )		/* 0x0087A140 */
#define in_prone_active			( kb[KB_WBUTTONS6].active )	/* 0x0087A2C0 */


#define cl_viewangles_PITCH		( *(float *)&cl_viewanglesPitch )
#define cl_viewangles_YAW		( *(float *)&cl_viewanglesYaw )
#define cl_viewangles_ROLL		cl_viewanglesRoll

#define cgameUserAim_PITCH		( *(float *)&cgameUserAim_x )
#define cgameUserAim_YAW		( *(float *)&cgameUserAim_y )
#define cgameUserAim_ROLL		( *(float *)&cgameUserAim_z )

/* cl.cgameMaxPitchSpeed / cl.cgameMaxYawSpeed -- degrees per second, set by CL_CgameSystemCalls at 0x004041A5 / 0x004041AE and read only by CL_MouseMove. Zero disables the clamp. */
#define cgameMaxPitchSpeed		( *(float *)&cgameMaxPitchSpeedStorage )
#define cgameMaxYawSpeed		( *(float *)&cgameMaxYawSpeedStorage )

#define frame_msec				frame_msecStorage
#define old_com_frameTime		cl_oldFrameTime

#define cl_mouseDx				cl_mouseDx
#define cl_mouseDy				cl_mouseDy
#define cl_mouseIndex			cl_mouseIndex
#define cl_joystickAxis			cl_joystickAxis

#define cl_cmds					( (usercmd_t *)cl_cmdsStorage )

#define OUTPACKET_CMDNUMBER( i )	cl_outPackets_p_cmdNumber[ ( (i) & PACKET_MASK ) * 3 ]
#define OUTPACKET_SERVERTIME( i )	cl_outPackets_p_serverTime[ ( (i) & PACKET_MASK ) * 3 ]
#define OUTPACKET_REALTIME( i )		cl_outPackets_p_realtime[ ( (i) & PACKET_MASK ) * 3 ]

#define clc_netchan				clc.netchan

#define clc_reliableCommand( i )	( &clc_reliableCommands[ MAX_STRING_CHARS_CMD * ( (i) & 0x3F ) ] )
#define clc_serverCommand( i )		( &clc_serverCommands[ MAX_STRING_CHARS_CMD * ( (i) & 0x3F ) ] )
#define MAX_STRING_CHARS_CMD		1024


#define cl_serverId				cl_serverId

#define cl_snap_ps				( (const byte *)&cl_snap_valid + SNAP_PS )

#define cl_snap_ps_flags_80	cl_snap_ps_eFlags

#define BUTTON_ATTACK			0x01
#define BUTTON_TALK				0x02
#define BUTTON_WALKING			0x10
#define WBUTTON_STANCEHELD		0x02
#define WBUTTON_SHELLSHOCK		0x04
#define WBUTTON_PRONE			0x40
#define WBUTTON_CROUCH			0x80
#define WBUTTON_STANCE_MASK		0xC0

#define clc_move				0
#define clc_moveNoDelta			1
#define clc_clientCommand		2
#define clc_EOF					3

#define MAX_PACKET_USERCMDS		32
#define CL_ENCODE_START			9

#define ANGLE2SHORT_SCALE		182.04445f
#define SHORT2ANGLE_SCALE		0.0054931640625f

#define cl_debugMove_cvar		( (cvar_t *)cl_debugMove )

#define DEBUGGRAPH_MASK			0x3FF

void __cdecl IN_CenterView( void );

/* ---- IN_MLookDown  0x0040A450 ----  VERIFIED */
void __cdecl IN_MLookDown( void )
{
  kb[KB_MLOOK].active = qtrue;
}

/* ---- IN_MLookUp  0x0040A460 ----  VERIFIED */
void __cdecl IN_MLookUp( void )
{
	kb[KB_MLOOK].active = qfalse;
	if ( !cl_freelook->integer ) {
		IN_CenterView();
	}
}

/* ---- IN_KeyDown  0x0040A490 ----  VERIFIED */
void __cdecl IN_KeyDown( void *button )
{
	kbutton_t	*b = (kbutton_t *)button;
	int			k;
	char		*c;

	c = Cmd_Argv( 1 );
	if ( c[0] ) {
		k = atoi( c );
	} else {
		k = -1;
	}

	if ( k == b->down[0] || k == b->down[1] ) {
		return;
	}

	if ( !b->down[0] ) {
		b->down[0] = k;
	} else if ( !b->down[1] ) {
		b->down[1] = k;
	} else {
		Com_Printf( "Three keys down for a button!\n" );
		return;
	}

	if ( b->active ) {
		return;
	}

	c = Cmd_Argv( 2 );
	b->downtime = atoi( c );

	b->active = qtrue;
	b->wasPressed = qtrue;
}

/* ---- IN_KeyUp  0x0040A510 ----  VERIFIED */
void __cdecl IN_KeyUp( void *button )
{
	kbutton_t		*b = (kbutton_t *)button;
	int				k;
	char			*c;
	unsigned int	uptime;

	c = Cmd_Argv( 1 );
	if ( c[0] ) {
		k = atoi( c );
	} else {
		b->down[0] = b->down[1] = 0;
		b->active = qfalse;
		return;
	}

	if ( b->down[0] == k ) {
		b->down[0] = 0;
	} else if ( b->down[1] == k ) {
		b->down[1] = 0;
	} else {
		return;
	}
	if ( b->down[0] || b->down[1] ) {
		return;
	}

	b->active = qfalse;

	c = Cmd_Argv( 2 );
	uptime = atoi( c );
	if ( uptime ) {
		b->msec += uptime - b->downtime;
	} else {
		b->msec += frame_msec / 2;
	}

	b->active = qfalse;
}

/* ---- CL_KeyState  0x0040A5A0 ----  VERIFIED */
float __cdecl CL_KeyState( void *button )
{
	kbutton_t	*key = (kbutton_t *)button;
	float		val;
	int			msec;

	msec = key->msec;
	key->msec = 0;

	if ( key->active ) {
		if ( !key->downtime ) {
			msec = com_frameTime;
		} else {
			msec += com_frameTime - key->downtime;
		}
		key->downtime = com_frameTime;
	}

#ifdef COD1_VC7
	val = (float)msec / (float)frame_msec;
#else
	val = (float)( (double)msec / (double)frame_msec );
#endif
	if ( val < 0 ) {
		val = 0;
	}
	if ( val > 1 ) {
		val = 1;
	}

	return val;
}

/* ---- CL_SetTempStanceStatus  0x0040A620 ----  VERIFIED */
void __cdecl CL_SetTempStanceStatus( void )
{
  if ( in_prone_active || in_down_active )
    Cvar_Set2("cl_stanceTemp", "1", qtrue);
  else
    Cvar_Set2("cl_stanceTemp", "0", qtrue);
}

/* ---- IN_UpDown  0x0040A670 ----  VERIFIED */
void __cdecl IN_UpDown( void )
{
	int		stance;

	IN_KeyDown( &kb[KB_MOVEUP] );

	if ( !in_prone_active && !in_down_active ) {
		stance = cl_stance->integer;
		if ( stance > 1 ) {
			Cvar_Set2( "cl_stance", "1", qtrue );
		} else if ( stance > 0 ) {
			Cvar_Set2( "cl_stance", "0", qtrue );
		} else {
			IN_KeyDown( &kb[KB_UP] );
		}
	}
}

/* ---- IN_UpUp  0x0040A6E0 ----  VERIFIED */
void __cdecl IN_UpUp( void )
{
  IN_KeyUp(&kb[KB_MOVEUP]);
  IN_KeyUp(&kb[KB_UP]);
}

/* ---- IN_DownDown  0x0040A700 ----  VERIFIED */
void __cdecl IN_DownDown( void )
{
  IN_KeyDown(&kb[KB_DOWN]);
  if ( in_prone_active || in_down_active )
    Cvar_Set2("cl_stanceTemp", "1", qtrue);
  else
    Cvar_Set2("cl_stanceTemp", "0", qtrue);
}

/* ---- IN_DownUp  0x0040A750 ----  VERIFIED */
void __cdecl IN_DownUp( void )
{
  IN_KeyUp(&kb[KB_DOWN]);
  if ( in_prone_active || in_down_active )
    Cvar_Set2("cl_stanceTemp", "1", qtrue);
  else
    Cvar_Set2("cl_stanceTemp", "0", qtrue);
}

/* ---- IN_LeftDown  0x0040A7A0 ----  VERIFIED */
void __cdecl IN_LeftDown( void )
{
  IN_KeyDown(&kb[KB_LEFT]);
}

/* ---- IN_LeftUp  0x0040A7B0 ----  VERIFIED */
void __cdecl IN_LeftUp( void )
{
  IN_KeyUp(&kb[KB_LEFT]);
}

/* ---- IN_RightDown  0x0040A7C0 ----  VERIFIED */
void __cdecl IN_RightDown( void )
{
  IN_KeyDown(&kb[KB_RIGHT]);
}

/* ---- IN_RightUp  0x0040A7D0 ----  VERIFIED */
void __cdecl IN_RightUp( void )
{
  IN_KeyUp(&kb[KB_RIGHT]);
}

/* ---- IN_ForwardDown  0x0040A7E0 ----  VERIFIED */
void __cdecl IN_ForwardDown( void )
{
  IN_KeyDown(&kb[KB_FORWARD]);
}

/* ---- IN_ForwardUp  0x0040A7F0 ----  VERIFIED */
void __cdecl IN_ForwardUp( void )
{
  IN_KeyUp(&kb[KB_FORWARD]);
}

/* ---- IN_BackDown  0x0040A800 ----  VERIFIED */
void __cdecl IN_BackDown( void )
{
  IN_KeyDown(&kb[KB_BACK]);
}

/* ---- IN_BackUp  0x0040A810 ----  VERIFIED */
void __cdecl IN_BackUp( void )
{
  IN_KeyUp(&kb[KB_BACK]);
}

/* ---- IN_LookupDown  0x0040A820 ----  VERIFIED */
void __cdecl IN_LookupDown( void )
{
  IN_KeyDown(&kb[KB_LOOKUP]);
}

/* ---- IN_LookupUp  0x0040A830 ----  VERIFIED */
void __cdecl IN_LookupUp( void )
{
  IN_KeyUp(&kb[KB_LOOKUP]);
}

/* ---- IN_LookdownDown  0x0040A840 ----  VERIFIED */
void __cdecl IN_LookdownDown( void )
{
  IN_KeyDown(&kb[KB_LOOKDOWN]);
}

/* ---- IN_LookdownUp  0x0040A850 ----  VERIFIED */
void __cdecl IN_LookdownUp( void )
{
  IN_KeyUp(&kb[KB_LOOKDOWN]);
}

/* ---- IN_MoveleftDown  0x0040A860 ----  VERIFIED */
void __cdecl IN_MoveleftDown( void )
{
  IN_KeyDown(&kb[KB_MOVELEFT]);
}

/* ---- IN_MoveleftUp  0x0040A870 ----  VERIFIED */
void __cdecl IN_MoveleftUp( void )
{
  IN_KeyUp(&kb[KB_MOVELEFT]);
}

/* ---- IN_MoverightDown  0x0040A880 ----  VERIFIED */
void __cdecl IN_MoverightDown( void )
{
  IN_KeyDown(&kb[KB_MOVERIGHT]);
}

/* ---- IN_MoverightUp  0x0040A890 ----  VERIFIED */
void __cdecl IN_MoverightUp( void )
{
  IN_KeyUp(&kb[KB_MOVERIGHT]);
}

/* ---- IN_SpeedDown  0x0040A8A0 ----  VERIFIED */
void __cdecl IN_SpeedDown( void )
{
  IN_KeyDown(&kb[KB_SPEED]);
}

/* ---- IN_SpeedUp  0x0040A8B0 ----  VERIFIED */
void __cdecl IN_SpeedUp( void )
{
  IN_KeyUp(&kb[KB_SPEED]);
}

/* ---- IN_StrafeDown  0x0040A8C0 ----  VERIFIED */
void __cdecl IN_StrafeDown( void )
{
  IN_KeyDown(&kb[KB_STRAFE]);
}

/* ---- IN_StrafeUp  0x0040A8D0 ----  VERIFIED */
void __cdecl IN_StrafeUp( void )
{
  IN_KeyUp(&kb[KB_STRAFE]);
}

/* ---- IN_AttackDown  0x0040A8E0 ----  VERIFIED */
void __cdecl IN_AttackDown( void )
{
  IN_KeyDown(&kb[KB_BUTTONS0]);
}

/* ---- IN_AttackUp  0x0040A8F0 ----  VERIFIED */
void __cdecl IN_AttackUp( void )
{
  IN_KeyUp(&kb[KB_BUTTONS0]);
}

/* ---- IN_Button1Down  0x0040A900 ----  VERIFIED */
void __cdecl IN_Button1Down( void )
{
  IN_KeyDown(&kb[KB_BUTTONS1]);
}

/* ---- IN_Button1Up  0x0040A910 ----  VERIFIED */
void __cdecl IN_Button1Up( void )
{
  IN_KeyUp(&kb[KB_BUTTONS1]);
}

/* ---- IN_UseItemDown  0x0040A920 ----  VERIFIED */
void __cdecl IN_UseItemDown( void )
{
  IN_KeyDown(&kb[KB_BUTTONS2]);
}

/* ---- IN_UseItemUp  0x0040A930 ----  VERIFIED */
void __cdecl IN_UseItemUp( void )
{
  IN_KeyUp(&kb[KB_BUTTONS2]);
}

/* ---- IN_Button3Down  0x0040A940 ----  VERIFIED */
void __cdecl IN_Button3Down( void )
{
  IN_KeyDown(&kb[KB_BUTTONS3]);
}

/* ---- IN_Button3Up  0x0040A950 ----  VERIFIED */
void __cdecl IN_Button3Up( void )
{
  IN_KeyUp(&kb[KB_BUTTONS3]);
}

/* ---- IN_Button4Down  0x0040A960 ----  VERIFIED */
void __cdecl IN_Button4Down( void )
{
  IN_KeyDown(&kb[KB_BUTTONS4]);
}

/* ---- IN_Button4Up  0x0040A970 ----  VERIFIED */
void __cdecl IN_Button4Up( void )
{
  IN_KeyUp(&kb[KB_BUTTONS4]);
}

/* ---- IN_MeleeDown  0x0040A980 ----  VERIFIED */
void __cdecl IN_MeleeDown( void )
{
  IN_KeyDown(&kb[KB_BUTTONS5]);
}

/* ---- IN_MeleeUp  0x0040A990 ----  VERIFIED */
void __cdecl IN_MeleeUp( void )
{
  IN_KeyUp(&kb[KB_BUTTONS5]);
}

/* ---- IN_ActivateDown  0x0040A9A0 ----  VERIFIED */
void __cdecl IN_ActivateDown( void )
{
  IN_KeyDown(&kb[KB_BUTTONS6]);
}

/* ---- IN_ActivateUp  0x0040A9B0 ----  VERIFIED */
void __cdecl IN_ActivateUp( void )
{
  IN_KeyUp(&kb[KB_BUTTONS6]);
}

/* ---- IN_KickDown  0x0040A9C0 ----  VERIFIED */
void __cdecl IN_KickDown( void )
{
  IN_KeyDown(&kb[KB_WBUTTONS0]);
}

/* ---- IN_KickUp  0x0040A9D0 ----  VERIFIED */
void __cdecl IN_KickUp( void )
{
  IN_KeyUp(&kb[KB_WBUTTONS0]);
}

/* ---- IN_SprintDown  0x0040A9E0 ----  VERIFIED */
void __cdecl IN_SprintDown( void )
{
  IN_KeyDown(&kb[KB_WBUTTONS2]);
}

/* ---- IN_SprintUp  0x0040A9F0 ----  VERIFIED */
void __cdecl IN_SprintUp( void )
{
  IN_KeyUp(&kb[KB_WBUTTONS2]);
}

/* ---- IN_ReloadDown  0x0040AA00 ----  VERIFIED */
void __cdecl IN_ReloadDown( void )
{
  IN_KeyDown(&kb[KB_WBUTTONS3]);
}

/* ---- IN_ReloadUp  0x0040AA10 ----  VERIFIED */
void __cdecl IN_ReloadUp( void )
{
  IN_KeyUp(&kb[KB_WBUTTONS3]);
}

/* ---- IN_LeanLeftDown  0x0040AA20 ----  VERIFIED */
void __cdecl IN_LeanLeftDown( void )
{
  IN_KeyDown(&kb[KB_WBUTTONS4]);
}

/* ---- IN_LeanLeftUp  0x0040AA30 ----  VERIFIED */
void __cdecl IN_LeanLeftUp( void )
{
  IN_KeyUp(&kb[KB_WBUTTONS4]);
}

/* ---- IN_LeanRightDown  0x0040AA40 ----  VERIFIED */
void __cdecl IN_LeanRightDown( void )
{
  IN_KeyDown(&kb[KB_WBUTTONS5]);
}

/* ---- IN_LeanRightUp  0x0040AA50 ----  VERIFIED */
void __cdecl IN_LeanRightUp( void )
{
  IN_KeyUp(&kb[KB_WBUTTONS5]);
}

/* ---- IN_ProneDown  0x0040AA60 ----  VERIFIED */
void __cdecl IN_ProneDown( void )
{
  IN_KeyDown(&kb[KB_WBUTTONS6]);
  if ( in_prone_active || in_down_active )
    Cvar_Set2("cl_stanceTemp", "1", qtrue);
  else
    Cvar_Set2("cl_stanceTemp", "0", qtrue);
}

/* ---- IN_ProneUp  0x0040AAB0 ----  VERIFIED */
void __cdecl IN_ProneUp( void )
{
  IN_KeyUp(&kb[KB_WBUTTONS6]);
  if ( in_prone_active || in_down_active )
    Cvar_Set2("cl_stanceTemp", "1", qtrue);
  else
    Cvar_Set2("cl_stanceTemp", "0", qtrue);
}

/* ---- IN_MP_DropWeaponDown  0x0040AB00 ----  VERIFIED */
void __cdecl IN_MP_DropWeaponDown( void )
{
  IN_KeyDown(&kb[KB_BUTTONS2]);
}

/* ---- IN_MP_DropWeaponUp  0x0040AB10 ----  VERIFIED */
void __cdecl IN_MP_DropWeaponUp( void )
{
  IN_KeyUp(&kb[KB_BUTTONS2]);
}

/* ---- IN_Wbutton7Down  0x0040AB20 ----  VERIFIED */
void __cdecl IN_Wbutton7Down( void )
{
  IN_KeyDown(&kb[KB_WBUTTONS7]);
}

/* ---- IN_Wbutton7Up  0x0040AB30 ----  VERIFIED */
void __cdecl IN_Wbutton7Up( void )
{
  IN_KeyUp(&kb[KB_WBUTTONS7]);
}

/* ---- IN_ButtonDown  0x0040AB40 ----  VERIFIED */
void __cdecl IN_ButtonDown( void )
{
  IN_KeyDown(&kb[KB_BUTTONS1]);
}

/* ---- IN_ButtonUp  0x0040AB50 ----  VERIFIED */
void __cdecl IN_ButtonUp( void )
{
  IN_KeyUp(&kb[KB_BUTTONS1]);
}

/* ---- IN_CenterView  0x0040AB60 ----  VERIFIED */
void __cdecl IN_CenterView( void )
{
	cl_viewangles_PITCH = -( (float)cl_snap_ps_deltaPitch * SHORT2ANGLE_SCALE );
}

/* ---- IN_LowerStance  0x0040AB80 ----  VERIFIED */
void __cdecl IN_LowerStance( void )
{
	int		stance;

	if ( !in_prone_active && !in_down_active ) {
		stance = cl_stance->integer;
		if ( stance < 1 ) {
			Cvar_Set2( "cl_stance", "1", qtrue );
		} else if ( stance < 2 ) {
			Cvar_Set2( "cl_stance", "2", qtrue );
		}
	}
}

/* ---- IN_RaiseStance  0x0040ABE0 ----  VERIFIED */
void __cdecl IN_RaiseStance( void )
{
	int		stance;

	if ( !in_prone_active && !in_down_active ) {
		stance = cl_stance->integer;
		if ( stance > 1 ) {
			Cvar_Set2( "cl_stance", "1", qtrue );
		} else if ( stance > 0 ) {
			Cvar_Set2( "cl_stance", "0", qtrue );
		}
	}
}

/* ---- IN_ToggleCrouch  0x0040AC40 ----  VERIFIED */
void __cdecl IN_ToggleCrouch( void )
{
	if ( !in_prone_active && !in_down_active ) {
		if ( cl_stance->integer != 1 ) {
			Cvar_Set2( "cl_stance", "1", qtrue );
		} else {
			Cvar_Set2( "cl_stance", "0", qtrue );
		}
	}
}

/* ---- IN_ToggleProne  0x0040AC90 ----  VERIFIED */
void __cdecl IN_ToggleProne( void )
{
	if ( !in_prone_active && !in_down_active ) {
		if ( cl_stance->integer != 2 ) {
			Cvar_Set2( "cl_stance", "2", qtrue );
		} else {
			Cvar_Set2( "cl_stance", "0", qtrue );
		}
	}
}

/* ---- IN_GoProne  0x0040ACE0 ----  VERIFIED */
void __cdecl IN_GoProne( void )
{
  if ( !in_prone_active && !in_down_active )
    Cvar_Set2("cl_stance", "2", qtrue);
}

/* ---- IN_GoCrouch  0x0040AD10 ----  VERIFIED */
void __cdecl IN_GoCrouch( void )
{
  if ( !in_prone_active && !in_down_active )
    Cvar_Set2("cl_stance", "1", qtrue);
}

/* ---- IN_GoStandDown  0x0040AD40 ----  VERIFIED */
void __cdecl IN_GoStandDown( void )
{
	int		jumpTime;

	IN_KeyDown( &kb[KB_MOVEUP] );

	jumpTime = cl_goStandJumpTime->integer;
	if ( jumpTime <= 0 ) {
		if ( !cl_stance->integer ) {
			IN_KeyDown( &kb[KB_UP] );
			cl_lastStandTime = 0;
			return;
		}
	} else if ( com_frameTime - cl_lastStandTime < jumpTime ) {
		IN_KeyDown( &kb[KB_UP] );
		cl_lastStandTime = 0;
		return;
	}

	cl_lastStandTime = com_frameTime;
	if ( !in_prone_active && !in_down_active ) {
		Cvar_Set2( "cl_stance", "0", qtrue );
	}
}

/* ---- IN_GoStandUp  0x0040ADC0 ----  VERIFIED */
void __cdecl IN_GoStandUp( void )
{
  IN_KeyUp(&kb[KB_MOVEUP]);
  IN_KeyUp(&kb[KB_UP]);
}

/* ---- CL_AdjustAngles  0x0040ADE0 ----  VERIFIED */
void __cdecl CL_AdjustAngles( void )
{
	float	speed;

	/* Keep frame-time multiplication in x87 until the final float speed spill. */
	speed = (float)cls_frametime;
	if ( in_speed_active )
		speed *= cl_anglespeedkey->value;
	speed *= 0.001f;

	if ( !in_strafe_active ) {
		/* the grouping parentheses only steer VC7's x87 operand order (keystate*yawspeed*speed as retail) */
		cl_viewangles_YAW -= speed * ( cl_yawspeed->value * CL_KeyState( &kb[KB_RIGHT] ) );
		cl_viewangles_YAW += speed * ( cl_yawspeed->value * CL_KeyState( &kb[KB_LEFT] ) );
	}

	cl_viewangles_PITCH -= speed * cl_pitchspeed->value * CL_KeyState( &kb[KB_LOOKUP] );
	cl_viewangles_PITCH += speed * cl_pitchspeed->value * CL_KeyState( &kb[KB_LOOKDOWN] );
}

/* ---- CL_KeyMove  0x0040AE90 ----  VERIFIED */
void __cdecl CL_KeyMove( void *cmd )
{
	usercmd_t	*c = (usercmd_t *)cmd;
	int			forward, side, up;

	if ( in_prone_active || in_down_active ) {
		if ( in_prone_active ) {
			c->wbuttons = (byte)((c->wbuttons & ~0xC0) | 0x40);
		} else {
			c->wbuttons = (byte)((c->wbuttons & ~0xC0) | 0x80);
		}
		c->wbuttons |= 0x02;
	} else {
		switch (cl_stance->integer) {
		case 1: c->wbuttons = (byte)((c->wbuttons & ~0xC0) | 0x80); break;
		case 2: c->wbuttons = (byte)((c->wbuttons & ~0xC0) | 0x40); break;
		default: c->wbuttons &= (byte)~0xC0; break;
		}
		c->wbuttons &= (byte)~0x02;
	}

	if ( cl_run->integer ^ in_speed_active ) {
		c->buttons &= (byte)~0x10;
	} else {
		c->buttons |= 0x10;
	}

	side = 0;
	up = 0;

	if ( in_strafe_active ) {
		side  = (int)( CL_KeyState( &kb[KB_RIGHT] ) * 127.0f );
		side += (int)( CL_KeyState( &kb[KB_LEFT] ) * -127.0f );
	}
	side += (int)( CL_KeyState( &kb[KB_MOVERIGHT] ) * 127.0f );
	side += (int)( CL_KeyState( &kb[KB_MOVELEFT] ) * -127.0f );

	if ( cl_snap_ps_pm_type == 2 || cl_snap_ps_pm_type == 3 || cl_snap_ps_pm_type == 4 ) {
		up = (int)( CL_KeyState( &kb[KB_MOVEUP] ) * 127.0f );
	}
	up += (int)( CL_KeyState( &kb[KB_UP] ) * 127.0f );

	if ( c->wbuttons & 0x80 ) {
		if ( in_down_active ) {
			up += (int)( CL_KeyState( &kb[KB_DOWN] ) * -127.0f );
		} else {
			up -= 127;
		}
	} else if ( c->wbuttons & 0x40 ) {
		up -= 127;
	}

	forward  = (int)( CL_KeyState( &kb[KB_FORWARD] ) * 127.0f );
	forward += (int)( CL_KeyState( &kb[KB_BACK] ) * -127.0f );

	if ( ( cl_snap_ps_flags_80 & 0xC000 ) == 0 ) {
		c->forwardmove = ClampChar( forward );
		c->rightmove   = ClampChar( side );
		c->upmove      = ClampChar( up );
	}
}

/* ---- CL_JoystickMove  0x0040B130 ----  VERIFIED */
void __cdecl CL_JoystickMove( void *cmd )
{
	usercmd_t	*c = (usercmd_t *)cmd;
	float		anglespeed;

	if ( !( cl_run->integer ^ in_speed_active ) ) {
		c->buttons |= BUTTON_WALKING;
	}

	/* Retail rounds only (float)cls_frametime (fstp/fld at 0x0040B15C), then
	   keeps [* anglespeedkey] * 0.001f in x87 and rounds once (0x0040B17E). */
	if ( in_speed_active ) {
		anglespeed = (float)cls_frametime * cl_anglespeedkey->value * 0.001f;
	} else {
		anglespeed = (float)cls_frametime * 0.001f;
	}

	if ( !in_strafe_active ) {
		cl_viewangles_YAW += (float)cl_joystickAxis[0] * cl_yawspeed->value * anglespeed;
	} else {
		c->rightmove = ClampChar( c->rightmove + cl_joystickAxis[0] );
	}

	if ( kb[KB_MLOOK].active ) {
		cl_viewangles_PITCH += (float)cl_joystickAxis[1] * cl_pitchspeed->value * anglespeed;
	} else {
		c->forwardmove = ClampChar( c->forwardmove + cl_joystickAxis[1] );
	}

	c->upmove = ClampChar( c->upmove + cl_joystickAxis[2] );
}

/* ---- CL_MouseMove  0x0040B240 ----  VERIFIED */
void __cdecl CL_MouseMove( void *cmd )
{
	usercmd_t	*c = (usercmd_t *)cmd;
	float		mx, my;
	float		accelSensitivity;
	float		rate;
	float		maxDelta;
	float		yawDelta;
	float		pitchDelta;

	if ( m_filter->integer ) {
		mx = (float)( cl_mouseDx[0] + cl_mouseDx[1] ) * 0.5f;
		my = (float)( cl_mouseDy[0] + cl_mouseDy[1] ) * 0.5f;
	} else {
		mx = (float)cl_mouseDx[cl_mouseIndex];
		my = (float)cl_mouseDy[cl_mouseIndex];
	}
	cl_mouseIndex ^= 1;
	cl_mouseDx[cl_mouseIndex] = 0;
	cl_mouseDy[cl_mouseIndex] = 0;

	/* Retail: __CIsqrt result stored to float (0x0040B2F3), divided by
	   (float)frame_msec (unsigned fild + 2^32 fixup, stored to float). */
	rate = (float)sqrt( (double)( my * my + mx * mx ) ) / (float)frame_msec;
	accelSensitivity = rate * cl_mouseAccel->value + cl_sensitivity->value;

	accelSensitivity = cgameSensitivity * accelSensitivity;

	if ( rate != 0.0f && cl_showmouserate->integer ) {
		Com_Printf( "%f : %f\n", rate, accelSensitivity );
	}

	if ( cl_snap_ps_pm_flags & 0x4000 ) {
		return;
	}

	if ( cl_snap_ps_flags_80 & 0xC000 ) {
		mx = mx * 2.5;
		my = my + my;
	} else {
		mx = accelSensitivity * mx;
		my = accelSensitivity * my;
	}

	if ( mx == 0.0f && my == 0.0f ) {
		return;
	}

	if ( in_strafe_active ) {
		c->rightmove = ClampChar( (int)( mx * m_side->value ) + c->rightmove );
	} else {
		yawDelta = mx * m_yaw->value;
		/* the CRT __max/__min macros: retail materializes -maxDelta and the
		   inner minimum as float stack temporaries, in both clamps */
		if ( cgameMaxYawSpeed != 0.0f ) {
			maxDelta = (float)frame_msec * cgameMaxYawSpeed * 0.001f;
			yawDelta = __max( -maxDelta, __min( maxDelta, yawDelta ) );
		}
		cl_viewangles_YAW -= yawDelta;
	}

	if ( ( kb[KB_MLOOK].active || cl_freelook->integer ) && !in_strafe_active ) {
		pitchDelta = my * m_pitch->value;
		if ( cgameMaxPitchSpeed != 0.0f ) {
			maxDelta = (float)frame_msec * cgameMaxPitchSpeed * 0.001f;
			pitchDelta = __max( -maxDelta, __min( maxDelta, pitchDelta ) );
		}
		cl_viewangles_PITCH += pitchDelta;
		return;
	}

	c->forwardmove = ClampChar( c->forwardmove - (int)( my * m_forward->value ) );
}

/* ---- CL_CmdButtons  0x0040B600 ----  VERIFIED */
void __cdecl CL_CmdButtons( usercmd_t *cmd )
{
	int i;

	for ( i = 0 ; i < 7 ; i++ ) {
		if ( kb[KB_BUTTONS0 + i].active || kb[KB_BUTTONS0 + i].wasPressed ) {
			cmd->buttons |= 1 << i;
		}
		kb[KB_BUTTONS0 + i].wasPressed = qfalse;
	}

	for ( i = 0 ; i < 7 ; i++ ) {
		if ( kb[KB_WBUTTONS0 + i].active || kb[KB_WBUTTONS0 + i].wasPressed ) {
			cmd->wbuttons |= 1 << i;
		}
		kb[KB_WBUTTONS0 + i].wasPressed = qfalse;
	}

	if ( cls_keyCatchers && !cl_bypassMouseInput->integer ) {
		cmd->buttons |= BUTTON_TALK;
	}

	if ( cgameUserCmdInShellshock ) {
		cmd->wbuttons |= WBUTTON_SHELLSHOCK;
	}
}

/* ---- CL_FinishMove  0x0040B690 ----  VERIFIED */
void __cdecl CL_FinishMove( void *cmd )
{
	usercmd_t	*c = (usercmd_t *)cmd;
	int			serverTime;

	c->weapon = (byte)cgameUserCmdValue;

	serverTime = cl_serverTime;
	if ( serverTime - cl_snap_serverTime > 5000 ) {
		serverTime = cl_snap_serverTime + 5000;
	}
	c->serverTime = serverTime;

	c->angles[0] = (int)( ( cgameUserAim_PITCH + cl_viewangles_PITCH ) * ANGLE2SHORT_SCALE ) & 0xFFFF;
	c->angles[1] = (int)( ( cl_viewangles_YAW + cgameUserAim_YAW ) * ANGLE2SHORT_SCALE ) & 0xFFFF;
	c->angles[2] = (int)( ( cl_viewangles_ROLL + cgameUserAim_ROLL ) * ANGLE2SHORT_SCALE ) & 0xFFFF;
}

/* cl_scrn_mp.c 0x00416BC0.  Without this prototype the float argument was promoted to
   double and the inlined body stored the double's low dword as the graph value. */
void SCR_DebugGraph( float value, int color );

/* ---- CL_CreateCmd  0x0040B720 ----  VERIFIED */
usercmd_t __cdecl CL_CreateCmd( void )
{
	usercmd_t	cmd;
	vec3_t		oldAngles;

	oldAngles[0] = cl_viewangles_PITCH;
	oldAngles[1]   = cl_viewangles_YAW;
	oldAngles[2]  = cl_viewangles_ROLL;

	CL_AdjustAngles();

	memset( &cmd, 0, sizeof( cmd ) );

	CL_CmdButtons( &cmd );

	CL_KeyMove( &cmd );

	CL_MouseMove( &cmd );

	CL_JoystickMove( &cmd );

	if ( cl_viewPitchCompensate->value != 0.0f ) {
		cl_viewangles_PITCH += cl_viewPitchCompensate->value;
		Cvar_Set2( "cl_viewPitchCompensate", "0", qtrue );
	}
	if ( cl_viewYawCompensate->value != 0.0f ) {
		cl_viewangles_YAW += cl_viewYawCompensate->value;
		Cvar_Set2( "cl_viewYawCompensate", "0", qtrue );
	}

	if ( cl_viewangles_PITCH - oldAngles[0] > 90.0f ) {
		cl_viewangles_PITCH = oldAngles[0] + 90.0f;
	} else if ( oldAngles[0] - cl_viewangles_PITCH > 90.0f ) {
		cl_viewangles_PITCH = oldAngles[0] - 90.0f;
	}

	CL_FinishMove( &cmd );

	if ( cl_debugMove_cvar->integer ) {
		if ( cl_debugMove_cvar->integer == 1 ) {
			SCR_DebugGraph( (float)fabs( cl_viewangles_YAW - oldAngles[1] ), 0 );
		}
		if ( cl_debugMove_cvar->integer == 2 ) {
			SCR_DebugGraph( (float)fabs( cl_viewangles_PITCH - oldAngles[0] ), 0 );
		}
	}

	return cmd;
}

/* ---- CL_CreateNewCommands  0x0040B8D0 ----  VERIFIED */
void __cdecl CL_CreateNewCommands( void )
{
	int		cmdNum;

	if ( cls_state < 5 ) {
		return;
	}

	frame_msec = com_frameTime - old_com_frameTime;

	if ( frame_msec > 200 ) {
		frame_msec = 200;
	}
	old_com_frameTime = com_frameTime;

	cl_cmdNumber++;
	cmdNum = cl_cmdNumber & CMD_MASK;
	cl_cmds[cmdNum] = CL_CreateCmd();
}

/* ---- CL_ReadyToSendPacket  0x0040B940 ----  VERIFIED */
qboolean __cdecl CL_ReadyToSendPacket( void )
{
	int		oldPacketNum;
	int		delta;

	if ( clc_demoplaying || cls_state == 7 || cls_state == 8 ) {
		return qfalse;
	}

	if ( cls_downloadTempName[0] ) {
		delta = clc_lastPacketSentTime;
		delta = cls_realtime - delta;
		if (delta < 50) return qfalse;
	}

	if ( cls_state != 6
		 && cls_state != 5
		 && !cls_downloadTempName[0]
		 && cls_realtime - clc_lastPacketSentTime < 1000 ) {
		return qfalse;
	}

	if ( clc_netchan.remoteAddress.type == NA_LOOPBACK ) {
		return qtrue;
	}
	if ( Sys_IsLANAddress( clc_netchan.remoteAddress ) ) {
		return qtrue;
	}

	if ( cl_maxpackets->integer < 15 ) {
		Cvar_Set2( "cl_maxpackets", "15", qtrue );
	} else if ( cl_maxpackets->integer > 100 ) {
		Cvar_Set2( "cl_maxpackets", "100", qtrue );
	}

	oldPacketNum = ( clc_netchan.outgoingSequence - 1 ) & PACKET_MASK;
	delta = cls_realtime - OUTPACKET_REALTIME( oldPacketNum );
	if ( delta < 1000 / cl_maxpackets->integer ) {
		return qfalse;
	}

	return qtrue;
}

/* ---- CL_WritePacket  0x0040BA50 ----  VERIFIED */
void __cdecl CL_WritePacket( void )
{
	msg_t		msg;
	byte		data[MAX_MSGLEN];
	byte		packet[MAX_MSGLEN];
	usercmd_t	nullcmd;
	usercmd_t	*cmd, *oldcmd;
	int			i, j;
	int			packetNum, oldPacketNum;
	int			count, key, size;

	if ( clc_demoplaying || cls_state == 7 || cls_state == 8 ) {
		return;
	}

	MSG_SetDefaultUserCmd( cl_snap_ps, &nullcmd );
	oldcmd = &nullcmd;

	if ( msgInit == qfalse ) {
		MSG_initHuffman();
	}
	memset( &msg, 0, sizeof( msg ) );
	msg.data = data;
	msg.maxsize = MAX_MSGLEN;

	MSG_WriteByte( &msg, (byte)cl_serverId );

	MSG_WriteLong( &msg, clc_serverMessageSequence );

	MSG_WriteLong( &msg, clc_serverCommandSequence );

	for ( i = clc_reliableAcknowledge + 1 ; i <= clc_reliableSequence ; i++ ) {
		MSG_WriteBits( &msg, clc_clientCommand, 2 );
		MSG_WriteLong( &msg, i );
		MSG_WriteString( &msg, clc_reliableCommand( i ) );
	}

	if ( cl_packetdup->integer < 0 ) {
		Cvar_Set2( "cl_packetdup", "0", qtrue );
	} else if ( cl_packetdup->integer > 5 ) {
		Cvar_Set2( "cl_packetdup", "5", qtrue );
	}

	oldPacketNum = ( clc_netchan.outgoingSequence - cl_packetdup->integer - 1 ) & PACKET_MASK;
	count = cl_cmdNumber - OUTPACKET_CMDNUMBER( oldPacketNum );
	if ( count > MAX_PACKET_USERCMDS ) {
		count = MAX_PACKET_USERCMDS;
		Com_Printf( "MAX_PACKET_USERCMDS\n" );
	}

	if ( count >= 1 ) {
		if ( cl_showSend->integer ) {
			Com_Printf( "(%i)", count );
		}

		if ( cl_nodelta->integer
			 || !cl_snap_valid
			 || clc_demowaiting
			 || clc_serverMessageSequence != *(int *)cl_snap_messageNum ) {
			MSG_WriteBits( &msg, clc_moveNoDelta, 2 );
		} else {
			MSG_WriteBits( &msg, clc_move, 2 );
		}

		MSG_WriteByte( &msg, count );

		key = clc_checksumFeed;
		key ^= clc_serverMessageSequence;
		key ^= Com_HashKey( clc_serverCommand( clc_serverCommandSequence ), 32 );

		for ( i = 0 ; i < count ; i++ ) {
			j = ( cl_cmdNumber - count + i + 1 ) & CMD_MASK;
			cmd = &cl_cmds[j];
			MSG_WriteDeltaUsercmdKey( &msg, key, oldcmd, cmd );
			oldcmd = cmd;
		}
	}

	MSG_WriteBits( &msg, clc_EOF, 2 );

	memcpy( packet, msg.data, CL_ENCODE_START );
	size = MSG_WriteBitsCompress( msg.data + CL_ENCODE_START,
								  msg.cursize - CL_ENCODE_START,
								  packet + CL_ENCODE_START );

	packetNum = clc_netchan.outgoingSequence & PACKET_MASK;
	OUTPACKET_REALTIME( packetNum )  = cls_realtime;
	OUTPACKET_SERVERTIME( packetNum ) = oldcmd->serverTime;
	OUTPACKET_CMDNUMBER( packetNum ) = cl_cmdNumber;
	clc_lastPacketSentTime = cls_realtime;

	size += CL_ENCODE_START;
	if ( cl_showSend->integer ) {
		Com_Printf( "%i ", size );
	}

	CL_Netchan_Encode( packet + CL_ENCODE_START, size - CL_ENCODE_START );
	Netchan_Transmit( &clc_netchan, size, packet );

	while ( clc_netchan.unsentFragments ) {
		Netchan_TransmitNextFragment( &clc_netchan );
	}
}

/* ---- CL_SendCmd  0x0040BF30 ----  VERIFIED */
void __cdecl CL_SendCmd( void )
{
	if ( cls_state < 3 ) {
		return;
	}

	if ( com_sv_running->integer && sv_paused->integer == 1 && cl_paused->integer == 1 ) {
		return;
	}

	CL_CreateNewCommands();

	if ( !CL_ReadyToSendPacket() ) {
		if ( cl_showSend->integer ) {
			Com_Printf( ". " );
		}
		return;
	}

	CL_WritePacket();
}

/* ---- CL_InitInput  0x0040BF90 ----  VERIFIED */
void __cdecl CL_InitInput( void )
{
  Cmd_AddCommand("centerview", IN_CenterView);
  Cmd_AddCommand("+moveup", IN_UpDown);
  Cmd_AddCommand("-moveup", IN_UpUp);
  Cmd_AddCommand("+movedown", IN_DownDown);
  Cmd_AddCommand("-movedown", IN_DownUp);
  Cmd_AddCommand("+left", IN_LeftDown);
  Cmd_AddCommand("-left", IN_LeftUp);
  Cmd_AddCommand("+right", IN_RightDown);
  Cmd_AddCommand("-right", IN_RightUp);
  Cmd_AddCommand("+forward", IN_ForwardDown);
  Cmd_AddCommand("-forward", IN_ForwardUp);
  Cmd_AddCommand("+back", IN_BackDown);
  Cmd_AddCommand("-back", IN_BackUp);
  Cmd_AddCommand("+lookup", IN_LookupDown);
  Cmd_AddCommand("-lookup", IN_LookupUp);
  Cmd_AddCommand("+lookdown", IN_LookdownDown);
  Cmd_AddCommand("-lookdown", IN_LookdownUp);
  Cmd_AddCommand("+strafe", IN_StrafeDown);
  Cmd_AddCommand("-strafe", IN_StrafeUp);
  Cmd_AddCommand("+moveleft", IN_MoveleftDown);
  Cmd_AddCommand("-moveleft", IN_MoveleftUp);
  Cmd_AddCommand("+moveright", IN_MoverightDown);
  Cmd_AddCommand("-moveright", IN_MoverightUp);
  Cmd_AddCommand("+speed", IN_SpeedDown);
  Cmd_AddCommand("-speed", IN_SpeedUp);
  Cmd_AddCommand("+attack", IN_AttackDown);
  Cmd_AddCommand("-attack", IN_AttackUp);
  Cmd_AddCommand("+melee", IN_MeleeDown);
  Cmd_AddCommand("-melee", IN_MeleeUp);
  Cmd_AddCommand("+activate", IN_ActivateDown);
  Cmd_AddCommand("-activate", IN_ActivateUp);
  Cmd_AddCommand("+reload", IN_ReloadDown);
  Cmd_AddCommand("-reload", IN_ReloadUp);
  Cmd_AddCommand("+leanleft", IN_LeanLeftDown);
  Cmd_AddCommand("-leanleft", IN_LeanLeftUp);
  Cmd_AddCommand("+leanright", IN_LeanRightDown);
  Cmd_AddCommand("-leanright", IN_LeanRightUp);
  Cmd_AddCommand("+dropweapon", IN_MP_DropWeaponDown);
  Cmd_AddCommand("-dropweapon", IN_MP_DropWeaponUp);
  Cmd_AddCommand("+prone", IN_ProneDown);
  Cmd_AddCommand("-prone", IN_ProneUp);
  Cmd_AddCommand("+mlook", IN_MLookDown);
  Cmd_AddCommand("-mlook", IN_MLookUp);
  Cmd_AddCommand("lowerstance", IN_LowerStance);
  Cmd_AddCommand("raisestance", IN_RaiseStance);
  Cmd_AddCommand("togglecrouch", IN_ToggleCrouch);
  Cmd_AddCommand("toggleprone", IN_ToggleProne);
  Cmd_AddCommand("goprone", IN_GoProne);
  Cmd_AddCommand("gocrouch", IN_GoCrouch);
  Cmd_AddCommand("+gostand", IN_GoStandDown);
  Cmd_AddCommand("-gostand", IN_GoStandUp);
  cl_nodelta = Cvar_Get("cl_nodelta", "0", 0);
  cl_debugMove = Cvar_Get("cl_debugMove", "0", 0);
}

/* ---- CL_ShutdownInput  0x0040C2D0 ----  VERIFIED */
void __cdecl CL_ShutdownInput( void )
{
  Cmd_RemoveCommand("centerview");
  Cmd_RemoveCommand("+moveup");
  Cmd_RemoveCommand("-moveup");
  Cmd_RemoveCommand("+movedown");
  Cmd_RemoveCommand("-movedown");
  Cmd_RemoveCommand("+left");
  Cmd_RemoveCommand("-left");
  Cmd_RemoveCommand("+right");
  Cmd_RemoveCommand("-right");
  Cmd_RemoveCommand("+forward");
  Cmd_RemoveCommand("-forward");
  Cmd_RemoveCommand("+back");
  Cmd_RemoveCommand("-back");
  Cmd_RemoveCommand("+lookup");
  Cmd_RemoveCommand("-lookup");
  Cmd_RemoveCommand("+lookdown");
  Cmd_RemoveCommand("-lookdown");
  Cmd_RemoveCommand("+strafe");
  Cmd_RemoveCommand("-strafe");
  Cmd_RemoveCommand("+moveleft");
  Cmd_RemoveCommand("-moveleft");
  Cmd_RemoveCommand("+moveright");
  Cmd_RemoveCommand("-moveright");
  Cmd_RemoveCommand("+speed");
  Cmd_RemoveCommand("-speed");
  Cmd_RemoveCommand("+attack");
  Cmd_RemoveCommand("-attack");
  Cmd_RemoveCommand("+melee");
  Cmd_RemoveCommand("-melee");
  Cmd_RemoveCommand("+activate");
  Cmd_RemoveCommand("-activate");
  Cmd_RemoveCommand("+reload");
  Cmd_RemoveCommand("-reload");
  Cmd_RemoveCommand("+leanleft");
  Cmd_RemoveCommand("-leanleft");
  Cmd_RemoveCommand("+leanright");
  Cmd_RemoveCommand("-leanright");
  Cmd_RemoveCommand("+dropweapon");
  Cmd_RemoveCommand("-dropweapon");
  Cmd_RemoveCommand("+prone");
  Cmd_RemoveCommand("-prone");
  Cmd_RemoveCommand("+mlook");
  Cmd_RemoveCommand("-mlook");
  Cmd_RemoveCommand("lowerstance");
  Cmd_RemoveCommand("raisestance");
  Cmd_RemoveCommand("togglecrouch");
  Cmd_RemoveCommand("toggleprone");
  Cmd_RemoveCommand("goprone");
  Cmd_RemoveCommand("gocrouch");
  Cmd_RemoveCommand("+gostand");
  Cmd_RemoveCommand("-gostand");
}

/* ---- CL_ClearKeys  0x0040C4E0 ----  VERIFIED */
void __cdecl CL_ClearKeys( void )
{
	memset( kb, 0, sizeof( kb ) );
}

#define cl_mouseDx      cl_mouseDx
#define cl_mouseDy      cl_mouseDy
#define cl_mouseIndex   cl_mouseIndex
#define cl_joystickAxis cl_joystickAxis

/* ---- CL_MouseEvent  0x0040B0A0 ----  [CONFIRMED] */
void CL_MouseEvent( int dx, int dy, int time ) {
	(void)time;

	if ( cls_keyCatchers & KEYCATCH_UI ) {
		if ( cl_bypassMouseInput->integer == 1 ) {
			cl_mouseDx[cl_mouseIndex] += dx;
			cl_mouseDy[cl_mouseIndex] += dy;
		} else {
			VM_Call( uivm, UI_MOUSE_EVENT, dx, dy );
		}
	} else if ( cls_keyCatchers & KEYCATCH_CGAME ) {
		VM_Call( cgvm, CG_MOUSE_EVENT, dx, dy );
	} else {
		cl_mouseDx[cl_mouseIndex] += dx;
		cl_mouseDy[cl_mouseIndex] += dy;
	}
}

/* ---- CL_JoystickEvent  0x0040B100 ----  [CONFIRMED] */
void CL_JoystickEvent( int axis, int value, int time ) {
	(void)time;

	if ( axis < 0 || axis >= 6 ) {
		Com_Error( ERR_DROP, "\x15" "CL_JoystickEvent: bad axis %i", axis );
	}
	cl_joystickAxis[axis] = value;
}
