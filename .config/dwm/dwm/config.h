/* See LICENSE file for copyright and license details. */
#include "fibonacci.c"
/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappx     = 7; 				/* gaps between windows */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMonoNerdFontMono:size=11:style=Bold", }; 
//Font Awesome 6 Free Solid:size=11
//static const char dmenufont[]       = "monospace:size=13";


// gruvbox
static const char col_bg1[]       = "#282828";
static const char col_bg2[]       = "#3c3836";
static const char col_fg1[]       = "#ebdbb2";
static const char col_fg2[]       = "#fbf1c7";
static const char col_main[]        = "#d65d0e";

// gruvbox 2 (laptop)
//static const char col_main_laptop[]        = "#076678";
//static const char active_border[]	= "#8cb37b";

// black and white
//static const char col_bg1[]       = "#E0E0E0";
//static const char col_bg2[]       = "#FFF0F5";
//static const char col_fg1[]       = "#262626";
//static const char col_fg2[]       = "#FFFFFF";
//static const char col_main[]        = "#262626";


static const char *colors[][3]      = {
 /*               	fg          bg         border   */
	[SchemeNorm] = { col_fg1, col_bg1, col_bg1 },
	[SchemeSel]  = { col_fg2, col_main,  col_main  },
	[SchemeHid]  = { col_main,  col_bg1, col_main  },
};

/* tagging */
static const char *tags[] = { "i", "ii", "iii", "iv", "v" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]	= { "dmenu_run", NULL };
static const char *roficmd[]	= { "rofi", "-show", "drun", NULL };
static const char *termcmd[]	= { "ghostty", NULL };
static const char *firefox[]	= { "firefox", NULL };
static const char *emacs[]	= { "emacs", NULL };
static const char *yazi[]	= { "ghostty", "-e", "yazi", NULL };
static const char *nvim[]	= { "ghostty", "-e", "nvim", NULL };
//static const char *spotify[]	= { "spotify-launcher", NULL };
static const char *vesktop[]	= { "vesktop", NULL };
static const char *volupcmd[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%",  NULL };
static const char *voldowncmd[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL };
static const char *volmute[] = { "/usr/bin/pactl", "set-sink-mute", "@DEFAULT_SINK@", "toggle", NULL };
static const char *shutcmd[]	= { "ghostty", "-e", "shutdown", "now", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_a,      spawn,          {.v = roficmd } },
	{ MODKEY,			XK_t, 	   spawn,          {.v = termcmd } },
	{ MODKEY,			XK_f,      spawn, 	       {.v = firefox } },
	{ MODKEY,			XK_c,	   spawn, 	       {.v = emacs } },
	{ MODKEY,			XK_e,	   spawn,	         {.v = yazi } },
	{ MODKEY,			XK_n,	   spawn,	{.v = nvim } },
	//{ MODKEY,			XK_s, 	   spawn,	{.v = spotify } },
	{ MODKEY,			XK_d,	   spawn,	   {.v = vesktop } },
        { MODKEY,                       XK_F10,    spawn,          {.v = volmute} },
        { MODKEY,                       XK_o,    spawn,          {.v = voldowncmd} },
        { MODKEY,                       XK_p,    spawn,          {.v = volupcmd} },
	{ MODKEY|ShiftMask,		XK_s,	   spawn,	   {.v = shutcmd} },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      focusstackhid,  {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      focusstackhid,  {.i = -1 } },
//	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
//	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Tab,    zoom,           {0} },
	{ MODKEY,                       XK_Return, view,           {0} },
	{ MODKEY,			XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[0]} },
//	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,             		XK_s,      showall,        {0} },
	{ MODKEY,             		XK_h,      hide,           {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

