enum
{
  KEY_NONE=10000,
  KEY_IDLE,
  KEY_DRAGCOPY,
  KEY_DRAGMOVE,
  KEY_LOCKSCREEN,

  KEY_BS=8,
  KEY_TAB=9,
  KEY_ENTER=13,
  KEY_ESC=27,

  KEY_SPACE=32,

  KEY_F1=256,
  KEY_F2,
  KEY_F3,
  KEY_F4,
  KEY_F5,
  KEY_F6,
  KEY_F7,
  KEY_F8,
  KEY_F9,
  KEY_F10,
  KEY_F11,
  KEY_F12,

  KEY_SHIFTF1,
  KEY_SHIFTF2,
  KEY_SHIFTF3,
  KEY_SHIFTF4,
  KEY_SHIFTF5,
  KEY_SHIFTF6,
  KEY_SHIFTF7,
  KEY_SHIFTF8,
  KEY_SHIFTF9,
  KEY_SHIFTF10,
  KEY_SHIFTF11,
  KEY_SHIFTF12,

  KEY_CTRLF1,
  KEY_CTRLF2,
  KEY_CTRLF3,
  KEY_CTRLF4,
  KEY_CTRLF5,
  KEY_CTRLF6,
  KEY_CTRLF7,
  KEY_CTRLF8,
  KEY_CTRLF9,
  KEY_CTRLF10,
  KEY_CTRLF11,
  KEY_CTRLF12,

  KEY_ALTF1,
  KEY_ALTF2,
  KEY_ALTF3,
  KEY_ALTF4,
  KEY_ALTF5,
  KEY_ALTF6,
  KEY_ALTF7,
  KEY_ALTF8,
  KEY_ALTF9,
  KEY_ALTF10,
  KEY_ALTF11,
  KEY_ALTF12,

  KEY_HOME,
  KEY_END,
  KEY_UP,
  KEY_DOWN,
  KEY_LEFT,
  KEY_RIGHT,
  KEY_PGUP,
  KEY_PGDN,
  KEY_INS,
  KEY_DEL,
  KEY_NUMPAD5,

  KEY_APPS,

  KEY_CTRLA,
  KEY_CTRLB,
  KEY_CTRLC,
  KEY_CTRLD,
  KEY_CTRLE,
  KEY_CTRLF,
  KEY_CTRLG,
  KEY_CTRLH,
  KEY_CTRLI,
  KEY_CTRLJ,
  KEY_CTRLK,
  KEY_CTRLL,
  KEY_CTRLM,
  KEY_CTRLN,
  KEY_CTRLO,
  KEY_CTRLP,
  KEY_CTRLQ,
  KEY_CTRLR,
  KEY_CTRLS,
  KEY_CTRLT,
  KEY_CTRLU,
  KEY_CTRLV,
  KEY_CTRLW,
  KEY_CTRLX,
  KEY_CTRLY,
  KEY_CTRLZ,


  KEY_CTRLBRACKET,
  KEY_CTRLBACKBRACKET,
  KEY_CTRLCOMMA,
  KEY_CTRLQUOTE,
  KEY_CTRLDOT,
  KEY_CTRLBS,
  KEY_CTRLENTER,
  KEY_CTRLTAB,

  KEY_CTRL0,
  KEY_CTRL1,
  KEY_CTRL2,
  KEY_CTRL3,
  KEY_CTRL4,
  KEY_CTRL5,
  KEY_CTRL6,
  KEY_CTRL7,
  KEY_CTRL8,
  KEY_CTRL9,

  KEY_RCTRL0,
  KEY_RCTRL1,
  KEY_RCTRL2,
  KEY_RCTRL3,
  KEY_RCTRL4,
  KEY_RCTRL5,
  KEY_RCTRL6,
  KEY_RCTRL7,
  KEY_RCTRL8,
  KEY_RCTRL9,

  KEY_CTRLSHIFTF1,
  KEY_CTRLSHIFTF2,
  KEY_CTRLSHIFTF3,
  KEY_CTRLSHIFTF4,
  KEY_CTRLSHIFTF5,
  KEY_CTRLSHIFTF6,
  KEY_CTRLSHIFTF7,
  KEY_CTRLSHIFTF8,
  KEY_CTRLSHIFTF9,
  KEY_CTRLSHIFTF10,
  KEY_CTRLSHIFTF11,
  KEY_CTRLSHIFTF12,

  KEY_ALTSHIFTF1,
  KEY_ALTSHIFTF2,
  KEY_ALTSHIFTF3,
  KEY_ALTSHIFTF4,
  KEY_ALTSHIFTF5,
  KEY_ALTSHIFTF6,
  KEY_ALTSHIFTF7,
  KEY_ALTSHIFTF8,
  KEY_ALTSHIFTF9,
  KEY_ALTSHIFTF10,
  KEY_ALTSHIFTF11,
  KEY_ALTSHIFTF12,

  KEY_CTRLALTF1,
  KEY_CTRLALTF2,
  KEY_CTRLALTF3,
  KEY_CTRLALTF4,
  KEY_CTRLALTF5,
  KEY_CTRLALTF6,
  KEY_CTRLALTF7,
  KEY_CTRLALTF8,
  KEY_CTRLALTF9,
  KEY_CTRLALTF10,
  KEY_CTRLALTF11,
  KEY_CTRLALTF12,

  KEY_CTRLSHIFT0,
  KEY_CTRLSHIFT1,
  KEY_CTRLSHIFT2,
  KEY_CTRLSHIFT3,
  KEY_CTRLSHIFT4,
  KEY_CTRLSHIFT5,
  KEY_CTRLSHIFT6,
  KEY_CTRLSHIFT7,
  KEY_CTRLSHIFT8,
  KEY_CTRLSHIFT9,

  KEY_CTRLSHIFTA,
  KEY_CTRLSHIFTB,
  KEY_CTRLSHIFTC,
  KEY_CTRLSHIFTD,
  KEY_CTRLSHIFTE,
  KEY_CTRLSHIFTF,
  KEY_CTRLSHIFTG,
  KEY_CTRLSHIFTH,
  KEY_CTRLSHIFTI,
  KEY_CTRLSHIFTJ,
  KEY_CTRLSHIFTK,
  KEY_CTRLSHIFTL,
  KEY_CTRLSHIFTM,
  KEY_CTRLSHIFTN,
  KEY_CTRLSHIFTO,
  KEY_CTRLSHIFTP,
  KEY_CTRLSHIFTQ,
  KEY_CTRLSHIFTR,
  KEY_CTRLSHIFTS,
  KEY_CTRLSHIFTT,
  KEY_CTRLSHIFTU,
  KEY_CTRLSHIFTV,
  KEY_CTRLSHIFTW,
  KEY_CTRLSHIFTX,
  KEY_CTRLSHIFTY,
  KEY_CTRLSHIFTZ,


  KEY_CTRLSHIFTINS,
  KEY_CTRLSHIFTDOWN,
  KEY_CTRLSHIFTLEFT,
  KEY_CTRLSHIFTRIGHT,
  KEY_CTRLSHIFTUP,
  KEY_CTRLSHIFTEND,
  KEY_CTRLSHIFTHOME,
  KEY_CTRLSHIFTPGDN,
  KEY_CTRLSHIFTPGUP,
  KEY_CTRLSHIFTSLASH,
  KEY_CTRLSHIFTBACKSLASH,
  KEY_CTRLSHIFTSUBTRACT,
  KEY_CTRLSHIFTADD,
  KEY_CTRLSHIFTENTER,
  KEY_CTRLSHIFTDOT,
  KEY_CTRLSHIFTTAB,
  KEY_CTRLSHIFTBS,
  KEY_CTRLSHIFTBRACKET,
  KEY_CTRLSHIFTBACKBRACKET,

  KEY_ALT_BASE,
  KEY_ALT0=KEY_ALT_BASE+'0',
  KEY_ALT1,
  KEY_ALT2,
  KEY_ALT3,
  KEY_ALT4,
  KEY_ALT5,
  KEY_ALT6,
  KEY_ALT7,
  KEY_ALT8,
  KEY_ALT9,

  KEY_ALTADD=KEY_ALT_BASE+'+',
  KEY_ALTDOT=KEY_ALT_BASE+'.',
  KEY_ALTCOMMA=KEY_ALT_BASE+',',
  KEY_ALTMULTIPLY=KEY_ALT_BASE+'*',

  KEY_ALTA=KEY_ALT_BASE+'A',
  KEY_ALTB,
  KEY_ALTC,
  KEY_ALTD,
  KEY_ALTE,
  KEY_ALTF,
  KEY_ALTG,
  KEY_ALTH,
  KEY_ALTI,
  KEY_ALTJ,
  KEY_ALTK,
  KEY_ALTL,
  KEY_ALTM,
  KEY_ALTN,
  KEY_ALTO,
  KEY_ALTP,
  KEY_ALTQ,
  KEY_ALTR,
  KEY_ALTS,
  KEY_ALTT,
  KEY_ALTU,
  KEY_ALTV,
  KEY_ALTW,
  KEY_ALTX,
  KEY_ALTY,
  KEY_ALTZ,

  KEY_END_ALT_BASE=KEY_ALT_BASE+256,

  KEY_ALTINS,
  KEY_ALTDEL,
  KEY_ALTBS,
  KEY_ALTHOME,
  KEY_ALTEND,
  KEY_ALTPGUP,
  KEY_ALTPGDN,
  KEY_ALTUP,
  KEY_ALTDOWN,
  KEY_ALTLEFT,
  KEY_ALTRIGHT,
  KEY_ALTSUBTRACT,

  KEY_CTRLDOWN,
  KEY_CTRLLEFT,
  KEY_CTRLRIGHT,
  KEY_CTRLUP,
  KEY_CTRLEND,
  KEY_CTRLHOME,
  KEY_CTRLPGDN,
  KEY_CTRLPGUP,
  KEY_CTRLSLASH,
  KEY_CTRLBACKSLASH,
  KEY_CTRLSUBTRACT,
  KEY_CTRLADD,
  KEY_CTRLMULTIPLY,
  KEY_CTRLCLEAR,

  KEY_ADD,
  KEY_SUBTRACT,
  KEY_MULTIPLY,
  KEY_DIVIDE,

  KEY_BREAK,

  KEY_SHIFTINS,
  KEY_SHIFTDEL,
  KEY_SHIFTEND,
  KEY_SHIFTHOME,
  KEY_SHIFTLEFT,
  KEY_SHIFTUP,
  KEY_SHIFTRIGHT,
  KEY_SHIFTDOWN,
  KEY_SHIFTPGUP,
  KEY_SHIFTPGDN,
  KEY_SHIFTENTER,
  KEY_SHIFTBS,
  KEY_SHIFTTAB,
  KEY_SHIFTADD,
  KEY_SHIFTSUBTRACT,

  KEY_CTRLINS,
  KEY_CTRLDEL,

  KEY_ALTSHIFTA,
  KEY_ALTSHIFTB,
  KEY_ALTSHIFTC,
  KEY_ALTSHIFTD,
  KEY_ALTSHIFTE,
  KEY_ALTSHIFTF,
  KEY_ALTSHIFTG,
  KEY_ALTSHIFTH,
  KEY_ALTSHIFTI,
  KEY_ALTSHIFTJ,
  KEY_ALTSHIFTK,
  KEY_ALTSHIFTL,
  KEY_ALTSHIFTM,
  KEY_ALTSHIFTN,
  KEY_ALTSHIFTO,
  KEY_ALTSHIFTP,
  KEY_ALTSHIFTQ,
  KEY_ALTSHIFTR,
  KEY_ALTSHIFTS,
  KEY_ALTSHIFTT,
  KEY_ALTSHIFTU,
  KEY_ALTSHIFTV,
  KEY_ALTSHIFTW,
  KEY_ALTSHIFTX,
  KEY_ALTSHIFTY,
  KEY_ALTSHIFTZ,

  KEY_ALTSHIFTINS,
  KEY_ALTSHIFTDOWN,
  KEY_ALTSHIFTLEFT,
  KEY_ALTSHIFTRIGHT,
  KEY_ALTSHIFTUP,
  KEY_ALTSHIFTEND,
  KEY_ALTSHIFTHOME,
  KEY_ALTSHIFTPGDN,
  KEY_ALTSHIFTPGUP,
  KEY_ALTSHIFTENTER,

  KEY_CTRLALTA,
  KEY_CTRLALTB,
  KEY_CTRLALTC,
  KEY_CTRLALTD,
  KEY_CTRLALTE,
  KEY_CTRLALTF,
  KEY_CTRLALTG,
  KEY_CTRLALTH,
  KEY_CTRLALTI,
  KEY_CTRLALTJ,
  KEY_CTRLALTK,
  KEY_CTRLALTL,
  KEY_CTRLALTM,
  KEY_CTRLALTN,
  KEY_CTRLALTO,
  KEY_CTRLALTP,
  KEY_CTRLALTQ,
  KEY_CTRLALTR,
  KEY_CTRLALTS,
  KEY_CTRLALTT,
  KEY_CTRLALTU,
  KEY_CTRLALTV,
  KEY_CTRLALTW,
  KEY_CTRLALTX,
  KEY_CTRLALTY,
  KEY_CTRLALTZ,

  KEY_CTRLALTINS,
  KEY_CTRLALTDOWN,
  KEY_CTRLALTLEFT,
  KEY_CTRLALTRIGHT,
  KEY_CTRLALTUP,
  KEY_CTRLALTEND,
  KEY_CTRLALTHOME,
  KEY_CTRLALTPGDN,
  KEY_CTRLALTPGUP,
  KEY_CTRLALTENTER,

  KEY_ALT,
  KEY_CTRL,
  KEY_SHIFT,
  KEY_RALT,
  KEY_RCTRL,

  KEY_CTRL_BASE,
  KEY_END_CTRL_BASE=KEY_CTRL_BASE+256,
  KEY_CTRLSHIFT_BASE,
  KEY_END_CTRLSHIFT_BASE=KEY_CTRLSHIFT_BASE+256,
  KEY_ALTSHIFT_BASE,
  KEY_END_ALTSHIFT_BASE=KEY_ALTSHIFT_BASE+256,
  KEY_CTRLALT_BASE,
  KEY_END_CTRLALT_BASE=KEY_CTRLALT_BASE+256,
};



