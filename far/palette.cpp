unsigned char DefaultPalette[]=
{
  F_WHITE|B_CYAN,F_WHITE|B_BLACK,F_YELLOW|B_CYAN,F_YELLOW|B_BLACK,
  F_WHITE|B_CYAN,F_WHITE|B_CYAN,

  F_BLACK|B_CYAN,F_WHITE|B_BLACK,F_YELLOW|B_CYAN,F_YELLOW|B_BLACK,

  F_LIGHTCYAN|B_BLUE,F_YELLOW|B_BLUE,F_LIGHTGRAY|B_BLUE,F_YELLOW|B_BLUE,
  F_BLACK|B_CYAN,F_YELLOW|B_CYAN,F_LIGHTCYAN|B_BLUE,F_BLACK|B_CYAN,
  F_YELLOW|B_BLUE,F_LIGHTCYAN|B_BLUE,F_YELLOW|B_CYAN,

  F_BLACK|B_LIGHTGRAY,F_YELLOW|B_LIGHTGRAY,F_BLACK|B_LIGHTGRAY,
  F_BLACK|B_LIGHTGRAY,F_YELLOW|B_LIGHTGRAY,F_BLACK|B_CYAN,
  F_BLACK|B_LIGHTGRAY,F_BLACK|B_CYAN,F_YELLOW|B_LIGHTGRAY,F_YELLOW|B_CYAN,

  F_BLACK|B_LIGHTGRAY,F_WHITE|B_BLACK,F_YELLOW|B_LIGHTGRAY,F_YELLOW|B_BLACK,

  F_WHITE|B_RED,F_YELLOW|B_RED,F_WHITE|B_RED,F_WHITE|B_RED,F_YELLOW|B_RED,
  F_BLACK|B_CYAN,F_WHITE|B_RED,F_BLACK|B_LIGHTGRAY,F_YELLOW|B_RED,
  F_YELLOW|B_LIGHTGRAY,

  F_LIGHTGRAY|B_BLACK,F_BLACK|B_CYAN,F_LIGHTGRAY|B_BLACK,

  F_LIGHTGRAY|B_BLACK,

  F_BLACK|B_CYAN,

  F_LIGHTCYAN|B_BLUE,F_BLACK|B_CYAN,F_BLACK|B_CYAN,

  F_LIGHTCYAN|B_BLUE,F_BLACK|B_CYAN,F_BLACK|B_CYAN,

  F_BLACK|B_CYAN,F_WHITE|B_CYAN,F_YELLOW|B_CYAN,F_WHITE|B_BLACK,
  F_BLACK|B_CYAN,F_BLACK|B_CYAN,

  F_YELLOW|B_CYAN,
  F_DARKGRAY|B_CYAN,
  F_LIGHTCYAN|B_BLUE,
  F_BLACK|B_CYAN,
  F_LIGHTCYAN|B_BLUE,
  F_LIGHTCYAN|B_BLACK,
  F_WHITE|B_BLACK,
  F_BLACK|B_LIGHTGRAY,
  F_YELLOW|B_BLUE,
  0,0,0,0,0
};


unsigned char BlackPalette[]=
{
  F_BLACK|B_LIGHTGRAY,F_LIGHTGRAY|B_BLACK,F_WHITE|B_LIGHTGRAY,F_WHITE|B_BLACK,
  F_BLACK|B_LIGHTGRAY,F_BLACK|B_LIGHTGRAY,

  F_BLACK|B_LIGHTGRAY,F_LIGHTGRAY|B_BLACK,F_WHITE|B_LIGHTGRAY,F_WHITE|B_BLACK,

  F_LIGHTGRAY|B_BLACK,F_WHITE|B_BLACK,F_LIGHTGRAY|B_BLACK,F_WHITE|B_BLACK,
  F_BLACK|B_LIGHTGRAY,F_WHITE|B_LIGHTGRAY,F_LIGHTGRAY|B_BLACK,
  F_BLACK|B_LIGHTGRAY,F_WHITE|B_BLACK,F_LIGHTGRAY|B_BLACK,
  F_BLACK|B_LIGHTGRAY,

  F_BLACK|B_LIGHTGRAY,F_WHITE|B_LIGHTGRAY,F_BLACK|B_LIGHTGRAY,
  F_BLACK|B_LIGHTGRAY,F_WHITE|B_BLACK,F_LIGHTGRAY|B_BLACK,
  F_BLACK|B_LIGHTGRAY,F_LIGHTGRAY|B_BLACK,F_WHITE|B_LIGHTGRAY,F_WHITE|B_BLACK,

  F_BLACK|B_LIGHTGRAY,F_WHITE|B_BLACK,F_WHITE|B_LIGHTGRAY,F_WHITE|B_BLACK,

  F_BLACK|B_LIGHTGRAY,F_WHITE|B_LIGHTGRAY,F_BLACK|B_LIGHTGRAY,
  F_BLACK|B_LIGHTGRAY,F_WHITE|B_BLACK,F_LIGHTGRAY|B_BLACK,F_BLACK|B_LIGHTGRAY,
  F_LIGHTGRAY|B_BLACK,F_WHITE|B_LIGHTGRAY,F_WHITE|B_BLACK,

  F_LIGHTGRAY|B_BLACK,F_BLACK|B_LIGHTGRAY,F_LIGHTGRAY|B_BLACK,

  F_LIGHTGRAY|B_BLACK,

  F_BLACK|B_LIGHTGRAY,

  F_LIGHTGRAY|B_BLACK,F_BLACK|B_LIGHTGRAY,F_BLACK|B_LIGHTGRAY,

  F_LIGHTGRAY|B_BLACK,F_BLACK|B_LIGHTGRAY,F_BLACK|B_LIGHTGRAY,

  F_LIGHTGRAY|B_BLACK,F_LIGHTGRAY|B_BLACK,F_WHITE|B_BLACK,
  F_BLACK|B_LIGHTGRAY,F_LIGHTGRAY|B_BLACK,F_LIGHTGRAY|B_BLACK,

  F_BLACK|B_LIGHTGRAY,
  F_WHITE|B_BLACK,
  F_LIGHTGRAY|B_BLACK,
  F_LIGHTGRAY|B_BLACK,
  F_LIGHTGRAY|B_BLACK,
  F_WHITE|B_BLACK,
  F_BLACK|B_LIGHTGRAY,
  F_BLACK|B_LIGHTGRAY,
  F_WHITE|B_BLACK,
  0,0,0,0,0
};

unsigned char Palette[sizeof(DefaultPalette)/sizeof(DefaultPalette[0])];

int FarColorToReal(int FarColor)
{
  if (FarColor<COL_FIRSTPALETTECOLOR)
    return(FarColor);
  else
    return(Palette[FarColor-COL_FIRSTPALETTECOLOR]);
}

