/* See LICENSE file for copyright and license details. */
/* Copyright (C) 2020-2022 Aditya Shakya <adi1090x@gmail.com>
 * 
 * DWM Configuration for Archcraft
 * Patched By : siduck76 <https://github.com/siduck76>
 * 
 * */

/* ******************** Configurations ******************** */
/* The border pixel determines the size of the window border. */
static const unsigned int borderpx  		= 2;	/* border pixel of windows */
static const unsigned int default_border 	= 0;	// to switch back to default border after dynamic border resizing via keybinds
/* The snap pixel controls two things:
 *    - how close to the window area border a window must be before it "snaps" (or docks) against
 *      that border when moving a floating window using the mouse
 *    - how far the mouse needs to move before a tiled window "snaps" out to become floating when
 *      moving or resizing a window using the mouse
 */
static const unsigned int snap      		= 20;	/* snap pixel */
static const unsigned int gappih    		= 8;	/* horiz inner gap between windows */
static const unsigned int gappiv    		= 8;	/* vert inner gap between windows */
static const unsigned int gappoh    		= 8;	/* horiz outer gap between windows and screen edge */
static const unsigned int gappov    		= 8;	/* vert outer gap between windows and screen edge */
static int smartgaps                        = 0;	/* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning 	= 0;	/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing 	= 10;	/* systray spacing */
static const int systraypinningfailfirst 	= 1;	/* 1: if pinning fails,display systray on the 1st monitor,False: display systray on last monitor*/
static const int showsystray        		= 0;	/* 0 means no systray */
/* Whether the bar is shown by default on startup or not. */
static const int showbar            		= 1;	/* 0 means no bar */

enum showtab_modes 
{ 
    showtab_never, 
    showtab_auto, 
    showtab_nmodes, 
    showtab_always 
};

static const int showtab            		= showtab_auto;
static const int toptab             		= True;
/* Whether the bar is shown at the top or at the bottom of the monitor. */
static const int topbar             		= 0;	/* 0 means bottom bar */
static const int horizpadbar        		= 15;
static const int vertpadbar         		= 15;
static const int vertpadtab         		= 34;
static const int horizpadtabi       		= 10;
static const int horizpadtabo       		= 10;
static const int scalepreview       		= 4;
static int tag_preview      			    = 1;	/* 1 means enable, 0 is off */

/* ******************** Fonts ******************** */
/* This defines the primary font and optionally fallback fonts. If a glyph does not exist for a
 * character (code point) in the primary font then fallback fonts will be checked.
 * If the fallback fonts also do not have that character then system fonts will be checked for the
 * missing character. If a system font was found then that font will be added to the list of
 * fallback fonts for future reference.
 *
 * Note that "monospace" is not an actual font, it is an alias for another font which the system
 * denotes as the main monospace font. E.g.
 *
 *    $ fc-match monospace
 *    NotoSansMono-Regular.ttf: "Noto Sans Mono" "Regular"
 *
 * Use fc-list to find specific fonts to use, e.g.
 *
 *    $ fc-list | grep DejaVu
 *    /usr/share/fonts/TTF/DejaVuSansMono.ttf: DejaVu Sans Mono:style=Book
 *
 * Then add the family to the fonts array, e.g.
 *
 *    static const char *fonts[] = { "DejaVu Sans Mono:style=Book:pixelsize=16" };
 *
 * A note about pixelsize vs size; 1 pixel (px) is usually assumed to be 1/96th of an inch while
 * 1 point (pt) is assumed to be 1/72nd of an inch. Therefore a (point) size of 12 is the same as
 * a pixelsize of 16.
 *
 * For general information on font setup refer to:
 *    https://wiki.archlinux.org/title/font_configuration
 *
 * The fonts array here will only be read once when the fonts are initially loaded.
 */
static const char *fonts[]          		= { "JetBrainsMono Nerd Font:size=12" };
static const char dmenufont[]       		= "monospace:size=10";
static const int colorfultag        		= 1;  /* 0 means use SchemeSel for selected non vacant tag */

/* ******************** Colors ******************** */
#include "colors.h"
static const char *colors[][3]  = {
    /*               	   fg      bg      border   */
    [SchemeNorm]       = { gray3,  black,  gray2 },
    [SchemeSel]        = { gray4,  blue,   blue  },
    [TabSel]           = { blue,   gray2,  black  },
    [TabNorm]          = { gray3,  black,  black },
    [SchemeTag]        = { gray3,  black,  black },
    [SchemeTag1]       = { blue,   black,  black },
    [SchemeTag2]       = { red,    black,  black },
    [SchemeTag3]       = { green,  black,  black },
    [SchemeTag4]       = { orange, black,  black },
    [SchemeTag5]       = { purple, black,  black },
    [SchemeTag6]       = { yellow, black,  black },
    [SchemeTag7]       = { pink,   black,  black },
    [SchemeTag8]       = { cyan,   black,  black },
    [SchemeLayout]     = { green,  black,  black }, 
    [SchemeBtnPrev]    = { green,  black,  black }, 
    [SchemeBtnNext]    = { yellow, black,  black }, 
    [SchemeBtnClose]   = { red,    black,  black }, 
};

/* ******************** Tags/Workspaces ******************** */
/* These define the tag icons (or text) used in the bar while the number of strings in the array
 * determine the number of tags being used by dwm. This has an upper limit of 32 tags and anything
 * above that will result in a compilation error. */
static char *tags[] = {"", "", "", ""};

static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3,
                                  SchemeTag4, SchemeTag5, SchemeTag6,
                                  SchemeTag7, SchemeTag8
                                };

static const unsigned int ulinepad		= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 1;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 				= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

/* ******************** Window Rules ******************** */
/* This array controls the client rules which consists of three rule matching filters (the class,
 * instance and title) and four rule options (tags, whether the client is floating or not and the
 * monitor it is supposed to be start on).
 *
 * Refer to the writeup of the applyrules function for more details on this.
 */
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      			            instance    title       tags mask       iscentered   isfloating   monitor */
	{ "st",                             NULL,       NULL,       0,              1,           1,           -1 }, 
    { "Gimp",     			            NULL,       NULL,       0,              0,           1,           -1 },
	{ "Inkscape",     		            NULL,       NULL,       0,              0,           1,           -1 },
	//{ "Firefox",  			            NULL,       NULL,       1 << 8,         0,           0,           -1 },
	{ "Viewnior",  			            NULL,       NULL,       0,              1,           1,           -1 },
	{ "MPlayer",  			            NULL,       NULL,       0,              1,           1,           -1 },
	{ "Thunar",  			            NULL,       NULL,       0,              1,           1,           -1 },
	{ "Music",  			            NULL,       NULL,       0,              1,           1,           -1 },
	{ "Yad",  		        	        NULL,       NULL,       0,              1,           1,           -1 },
	{ "feh",  			                NULL,       NULL,       0,              1,           1,           -1 },
	{ "Pavucontrol",  		            NULL,       NULL,       0,              1,           1,           -1 },
	{ "Lxappearance",  		            NULL,       NULL,       0,              1,           1,           -1 },
	{ "alacritty-float",  	            NULL,       NULL,       0,       	    1,           1,           -1 },
	{ "VirtualBox Manager",  		    NULL,       NULL,       0,              1,           1,           -1 },
	{ "Nm-connection-editor",  		    NULL,       NULL,       0,              1,           1,           -1 },
	{ "Xfce4-power-manager-settings",  	NULL,       NULL,       0,              1,           1,           -1 },
};

/* ******************** Layout(s) ******************** */

/* The master / stack factor controls how much of the window area is designated for the master area
 * vs the stack area for the tile layout. Refer to the writeup for the setmfact function for more
 * details. */
static const float mfact     		= 0.35;		/* factor of master area size [0.05..0.95] */
/* The nmaster variable controls the number of clients that are placed in the the master area when
 * tiled. Refer to the incnmaster function writeup for more details. */
static const int nmaster     		= 1;		/* number of clients in master area */
/* This controls whether or not the window manager will respect the size hints of a client window
 * when the client is tiled. Refer to the applysizehints function writeup for more details. */
static const int resizehints 		= 0;		/* 1 means respect size hints in tiled resizals */
/* The lockfullscreen variable controls whether or not focus is allowed to drift from a fullscreen
 * window. Refer to the writeup of the focusstack function for which this feature is isolated. */
static const int lockfullscreen 	= 1;		/* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1		/* nrowgrid layout: force two clients to always split vertically */
#include "functions.h"

/* This array contains the list of available layout options.
 *
 * When dwm starts the first layout in the list is the default layout and the last layout in the
 * array will be set as the previous layout.
 *
 * The layout symbol will be copied into the monitor's layout symbol when the layout is set. The
 * layout function may make changes to the layout symbol, for example the monocle layout that shows
 * the number of clients visible.
 *
 * Refer to the setlayout function writeup for more details.
 */
static const Layout layouts[] = {
    /* symbol     arrange function */     
	{ "|M|",      centeredmaster },
    { "[][]=",    tilewide },    
    { "[]=",      tile },    /* first entry is default */
    { "|+|",      tatami },
    { "M[]",      monocle },
    { "@[]",      spiral },
    { "/[]",      dwindle },
    { "H[]",      deck },
    { "TTT",      bstack },
    { "===",      bstackhoriz },
    { "HHH",      grid },
    { "###",      nrowgrid },
    { "---",      horizgrid },
    { ":::",      gaplessgrid },
    { ">M>",      centeredfloatingmaster },
    { "><>",      NULL },    /* no layout function means floating behavior */
};

/* ******************** Key definitions ******************** */

/* This defines the primary modifier used by dwm. It is a macro which means that at compile time
 * all the references to MODKEY below will be replaced with the content of this macro.
 *
 * To see the available modifiers run the xmodmap command in a terminal, but typically there will
 * be a setup along the lines of:
 *
 *    Mod1Mask - the Alt key (and/or Meta key)
 *    Mod2Mask - Num_Lock
 *    Mod3Mask - often not used
 *    Mod4Mask - the Super / Windows key (and/or Hyper key)
 *    Mod5Mask - ISO_Level3_Shift (AltGr) and/or Mode_switch
 *
 * Note that you can use xmodmap to change e.g. the right control key to become another
 * modifier should you need it.
 */
#define MODKEY Mod1Mask
#define ALTKEY Mod4Mask

/* TAGKEYS is another macro that just avoids having to repeat the same thing nine times
 * for each tag.
 *
 * Consider this being used in the keys array further down.
 *
 *    TAGKEYS(                        XK_3,                      2)
 *
 * In this case the KEY variable will be XK_3 and the TAG value will be 2. This would then
 * expand in the keys array to:
 *
 *    { MODKEY,                       XK_3,     view,           {.ui = 1 << 2} }, \
 *    { MODKEY|ControlMask,           XK_3,     toggleview,     {.ui = 1 << 2} }, \
 *    { MODKEY|ShiftMask,             XK_3,     tag,            {.ui = 1 << 2} }, \
 *    { MODKEY|ControlMask|ShiftMask, XK_3,     toggletag,      {.ui = 1 << 2} },
 *
 * Using a macro also makes it easier to change the modifiers used for the functions
 * if need be.
 */
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* ******************** Commands ******************** */ 
/* The dmenumon variable holds a reference to the current monitor number, to be passed to dmenu.
 * This is quite strictly not necessary as dmenu can work out on its own what monitor has focus.
 * Refer to the writeup in the spawn function for more details on this. */
static char dmenumon[2] 				= "0"; /* component of dmenucmd, manipulated in spawn() */
/* The command to launch dmenu. dmenu is a simple program that takes a series of options as input
 * and presents these to the user via a menu, when the user selects an option then that option is
 * printed to standard out. dmenu is often confused with dmenu_run, which is a shell script that
 * looks for executable commands, presents these options to the user, and runs whatever the user
 * selected.
 *
 * In the dmenu command we specify via command line arguments the font and colours that dmenu
 * should use. This is to make it appear stylistically similar to the bar in dwm.
 */
static const char *dmenucmd[]  			= { "dmenu", NULL };

/* Launch Apps */
/* dwm launches st as the terminal of choice by default. */
static const char *stcmd[]  			= { "st", NULL };
static const char *termcmd[]  			= { "/home/ahsan/.config/bin/dwmterm.sh", NULL };
static const char *floatterm[]  		= { "/home/ahsan/.config/bin/dwmterm.sh", "-f", NULL };
static const char *fmcmd[]    			= { "/home/ahsan/.config/bin/dwmapps.sh", "-f", NULL };
static const char *webcmd[]  			= { "/home/ahsan/.config/bin/dwmapps.sh", "-w", NULL };

/* Rofi Menus */
static const char *rofi_cmd[] 			= { "/home/ahsan/.config/rofi/launchers/slate/launcher.sh", NULL };
static const char *rofi_rootcmd[] 		= { "/home/ahsan/.config/rofi/bin/asroot", NULL };
static const char *rofi_layoutcmd[]     = { "/home/ahsan/.config/rofi/bin/layouts", NULL };
static const char *rofi_mpdcmd[] 		= { "/home/ahsan/.config/rofi/bin/mpd", NULL };
static const char *rofi_nmcmd[]    		= { "/home/ahsan/.config/rofi/bin/network_menu", NULL };
static const char *rofi_powercmd[]      = { "/home/ahsan/.config/rofi/powermenu/powermenu.sh", NULL };
static const char *rofi_shotcmd[]  		= { "/home/ahsan/.config/rofi/bin/screenshot", NULL };
static const char *rofi_wincmd[]  		= { "/home/ahsan/.config/rofi/bin/windows", NULL };

/* Misc */
static const char *cpickcmd[]  			= { "color-gpick", NULL };
static const char *lockcmd[]  			= { "betterlockscreen", "--lock", NULL };
static const char *ewwcmd[]             = { "/home/ahsan/bin/eww open eww", NULL };

/* Hardware keys for volume and brightness */
#include <X11/XF86keysym.h>
/* Add somewhere in your constants definition section */
static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "0", "+5%",     NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "-5%",     NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "0", "toggle",  NULL };


static const char *upbl[] 			    = { "brightness", "--inc",    NULL };
static const char *downbl[] 			= { "brightness", "--dec",  NULL };

/* Screenshot */
static const char *shotnow[]  			= { "takeshot", "--now", NULL };
static const char *shotin5[]  			= { "takeshot", "--in5", NULL };
static const char *shotin10[]  			= { "takeshot", "--in10", NULL };
static const char *shotwin[]  			= { "takeshot", "--win", NULL };
static const char *shotarea[]  			= { "takeshot", "--area", NULL };

/* ******************** Keybindings ******************** */
/* The keys array contains user defined keybindings and the functions that said keybindings should
 * run. Refer to the grabkeys function for details on how the window manager tells the X server
 * it is interested in receiving key press events corresponding to the given key combinations.
 * Refer to the keypress function for details on how the window manager interprets the events
 * received for the key combinations and calls the designated functions. */
static Key keys[] = {
    /* modifier 			        key 			                function        argument */

    // Hardware Keys -----------
    { 0,                            XF86XK_AudioMute,               spawn,          {.v = mutevol   } },
    { 0,                            XF86XK_AudioRaiseVolume,        spawn,          {.v = upvol   } },
    { 0,                            XF86XK_AudioLowerVolume,        spawn,          {.v = downvol   } },
    { 0, 				            XF86XK_MonBrightnessUp,         spawn,          {.v = upbl   } },
    { 0, 				            XF86XK_MonBrightnessDown,       spawn,          {.v = downbl   } },

    // Print Keys ----------
    { 0, 				            XK_Print, 			            spawn,          {.v = shotnow } },
    { ALTKEY, 				        XK_Print, 			            spawn,          {.v = shotin5 } },
    { ShiftMask, 		            XK_Print, 		                spawn,          {.v = shotin10 } },
    { ControlMask, 		            XK_Print, 	        	        spawn,          {.v = shotwin } },
    { ALTKEY|ControlMask,           XK_Print, 		                spawn,          {.v = shotarea } },

	// Terminals -----------
    { MODKEY, 			            XK_Return, 			            spawn,          {.v = stcmd } },
    { MODKEY|ShiftMask,             XK_Return, 			            spawn,          {.v = floatterm } },
    { MODKEY|ControlMask,           XK_Return, 			            spawn,          {.v = termcmd } },

	// Launch Apps -----------
    { MODKEY|ShiftMask,             XK_f, 				            spawn,          {.v = fmcmd } },
    //{ MODKEY|ShiftMask,             XK_e, 				            spawn,          {.v = editcmd } },
    { MODKEY|ShiftMask,             XK_w, 				            spawn,          {.v = webcmd } },
	
	// Rofi Menus -----------
    { MODKEY, 				        XK_d, 				            spawn,          {.v = rofi_cmd } },
    { MODKEY, 				        XK_m, 				            spawn,          {.v = rofi_mpdcmd } },
    { MODKEY, 				        XK_n, 				            spawn,          {.v = rofi_nmcmd } },
    { MODKEY, 				        XK_r, 				            spawn,          {.v = rofi_rootcmd } },
    { MODKEY, 				        XK_x, 				            spawn,          {.v = rofi_powercmd } },
    { MODKEY, 				        XK_s, 				            spawn,          {.v = rofi_shotcmd } },
    //{ MODKEY, 				        XK_w, 				            spawn,          {.v = rofi_wincmd } },

	// Misc -----------
    { MODKEY, 				        XK_p, 				            spawn,          {.v = cpickcmd } },
    { ALTKEY|ControlMask,           XK_l, 				            spawn,          {.v = lockcmd } },

	// Tags -----------
    TAGKEYS( 				        XK_1, 					                        0)
    TAGKEYS( 				        XK_2, 					                        1)
    TAGKEYS( 				        XK_3, 					                        2)
    TAGKEYS( 				        XK_4, 					                        3)
    TAGKEYS( 				        XK_5, 					                        4)
    TAGKEYS( 				        XK_6, 					                        5)
    TAGKEYS( 				        XK_7, 					                        6)
    TAGKEYS( 				        XK_8, 					                        7)
    TAGKEYS( 				        XK_9, 					                        8)

	// DWM Session	-----------
    { MODKEY|ControlMask,           XK_q, 				            quit,           {0} }, // Quit DWM
    { MODKEY|ShiftMask,             XK_r, 				            quit,           {1} }, // Restart DWM

	// Border and Gaps -----------
	/* Borders */
    { MODKEY|ShiftMask,             XK_equal, 			            setborderpx,    {.i = +1 } }, // Increase border width
    { MODKEY|ShiftMask,             XK_minus, 			            setborderpx,    {.i = -1 } }, // Decrease border width
    { MODKEY|ShiftMask,             XK_BackSpace, 			        setborderpx,    {.i = default_border } },

	/* Gaps */
    // overall gaps
    { MODKEY|ShiftMask, 	        XK_bracketleft,      	        incrgaps,       {.i = +1 } },
    { MODKEY|ShiftMask, 	        XK_bracketright,      	        incrgaps,       {.i = -1 } },
    { MODKEY|ShiftMask, 	        XK_backslash, 			        defaultgaps,    {0} }, // Default gaps
    { MODKEY|ShiftMask, 	        XK_g, 				            togglegaps,     {0} }, // Toggle gaps

    // inner gaps
    { MODKEY|ShiftMask, 		    XK_i, 			                incrigaps,      {.i = +1 } },
    { MODKEY|ControlMask|ShiftMask, XK_i, 			                incrigaps,      {.i = -1 } },

    // outer gaps
    { MODKEY|ControlMask, 	        XK_o,   			            incrogaps,      {.i = +1 } },
    { MODKEY|ControlMask|ShiftMask, XK_o, 			                incrogaps,      {.i = -1 } },
	
	// Window Management -----------
	/* Murder */
    { MODKEY, 				        XK_q, 				            killclient,     {0} }, // Kill window
    { MODKEY, 				        XK_Escape, 			            spawn,          SHCMD("xkill") }, // xkill

	/* Switch */
    { MODKEY, 				        XK_j, 				            focusstack,     {.i = +1 } }, // Cycle window
    { MODKEY, 				        XK_k, 				            focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask, 	        XK_j, 				            movestack,      {.i = +1 } }, // Switch master
    { MODKEY|ShiftMask, 	        XK_k, 				            movestack,      {.i = -1 } },

    { MODKEY, 				        XK_Left, 			            focusstack,     {.i = +1 } }, // Cycle window
    { MODKEY, 				        XK_Right, 			            focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask, 	        XK_Left, 			            movestack,      {.i = +1 } }, // Switch master
    { MODKEY|ShiftMask, 	        XK_Right, 			            movestack,      {.i = -1 } },

    { MODKEY, 				        XK_i, 				            incnmaster,     {.i = +1 } }, // Verticle
    { MODKEY, 				        XK_u, 				            incnmaster,     {.i = -1 } }, // Horizontal

	/* Resize */
    { MODKEY, 				        XK_h, 				            setmfact,       {.f = -0.02} }, // Shrink left 
    { MODKEY, 				        XK_l, 				            setmfact,       {.f = +0.02} }, // Shrink right

    { MODKEY|ControlMask, 	        XK_Left, 			            setmfact,       {.f = -0.01} }, // Shrink left 
    { MODKEY|ControlMask, 	        XK_Right, 			            setmfact,       {.f = +0.01} }, // Shrink right

	/* Misc */
    { MODKEY, 				        XK_b, 				            togglebar,      {0} }, // Toggle bar
    { MODKEY, 				        XK_Tab, 			            zoom,           {0} }, // Switch to master
    { ALTKEY, 				        XK_Tab, 			            view,           {0} }, // Switch to last tag
    { MODKEY, 				        XK_w, 				            hidewin,        {0} }, // Hide window
    { MODKEY|ShiftMask, 	        XK_w, 				            restorewin,     {0} }, // Restore window
    { MODKEY, 				        XK_0, 				            view,           {.ui = ~0 } },
    { MODKEY|ShiftMask, 	        XK_0, 				            tag,            {.ui = ~0 } },
    { MODKEY,                        XK_e,                           spawn,          {.v = ewwcmd } },

	// Layouts -----------
    { ALTKEY|ControlMask, 	        XK_space, 			            spawn,          {.v = rofi_layoutcmd } },

    { MODKEY|ControlMask, 	        XK_comma, 			            cyclelayout,    {.i = -1 } },
    { MODKEY|ControlMask, 	        XK_period, 			            cyclelayout,    {.i = +1 } },
    { MODKEY|ShiftMask,             XK_space, 			            togglefloating, {0} },
    { MODKEY, 			            XK_f, 				            togglefullscr,  {0} },

    { MODKEY, 				        XK_space, 			            setlayout,      {0} }, 
    { MODKEY, 				        XK_t, 				            setlayout,      {.v = &layouts[0]} }, // 
	//{ MODKEY,                       XK_w,                           setlayout,      {.v = &layouts[3]} },    
    //Tile
    { MODKEY, 				        XK_g, 				            setlayout,      {.v = &layouts[10]} }, // Grid
    { MODKEY|ShiftMask, 	        XK_m, 				            setlayout,      {.v = &layouts[1]} }, // Monocle
    { MODKEY|ShiftMask, 	        XK_s, 				            setlayout,      {.v = &layouts[2]} }, // Spiral
    { MODKEY|ShiftMask, 	        XK_t, 				            setlayout,      {.v = &layouts[5]} }, // Stack
    { MODKEY|ShiftMask, 	        XK_c, 				            setlayout,      {.v = &layouts[11]} }, // Centered master
	{ MODKEY,                       XK_c,                           setlayout,      {.v = &layouts[4]} },    
    { MODKEY|ShiftMask, 	        XK_x, 				            setlayout,      {.v = &layouts[13]} }, // Tatami
    
};

/* ******************** Button definitions ******************** */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
/* Mouse button definitions.
 * The buttons array contains user defined mouse button bindings and the functions that said
 * bindings should trigger. Refer to the grabbuttons function for details on how the window manager
 * tells the X server it is interested in receiving button press events corresponding to the given
 * modifier + button combinations. An event mask of 0 means no modifier.
 * Refer to the buttonpress function for details on how the window manager interprets the events
 * received for the button presses and calls the designated functions.
 *
 * What the user clicks on can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin,
 * or ClkRootWin.
 *
 * Button1 through Button5 are macros that are defined within the X11 libraries. They simply have
 * values of 1 through 5. To bind additional buttons you can either define them yourself or just
 * use the button value directly. E.g.
 *
 *    #define Button6 6
 *    #define Button7 7
 *    #define Button8 8
 *    #define Button9 9
 *
 *    { ClkClientWin,         MODKEY,         Button8,        myfunc,         {0} },
 * or
 *    { ClkClientWin,         MODKEY,         8,              myfunc,         {0} },SHCMD("pamixer -i 5")}
 **/
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        spawn,     		{.v = rofi_layoutcmd } },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },

    { ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkClientWin,         ControlMask,    Button1,        dragmfact,      {0} },
    { ClkClientWin,         ControlMask,    Button3,        dragcfact,      {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
    { ClkTabBar,            0,              Button1,        focuswin,       {0} },
    { ClkTabBar,            0,              Button1,        focuswin,       {0} },
    { ClkTabPrev,           0,              Button1,        movestack,      { .i = -1 } },
    { ClkTabNext,           0,              Button1,        movestack,      { .i = +1 } },
    { ClkTabClose,          0,              Button1,        killclient,     {0} },
};

/* ******************** DWMC ******************** */
void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
	{ "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
};
