Language::Language()
{
  MsgList=NULL;
  MsgAddr=NULL;
  MsgCount=0;
  MsgSize=0;
}


int Language::Init(char *Path)
{
  if (MsgList!=NULL)
    return(TRUE);

  int LastError=GetLastError();

  FILE *LangFile=OpenLangFile(Path,LangFileMask,Opt.Language,MessageFile);
  if (LangFile==NULL)
    return(FALSE);

  char ReadStr[1024];

  while (fgets(ReadStr,sizeof(ReadStr),LangFile)!=NULL)
  {
    char DestStr[1024];
    if (*ReadStr!='\"')
      continue;
    RemoveTrailingSpaces(ReadStr);
    int SrcLength=strlen(ReadStr);
    if (ReadStr[SrcLength-1]=='\"')
      ReadStr[SrcLength-1]=0;
    ConvertString(ReadStr+1,DestStr);
    int DestLength=strlen(DestStr)+1;
    if ((MsgList=(char *)realloc(MsgList,MsgSize+DestLength))==NULL)
    {
      fclose(LangFile);
      return(FALSE);
    }
    strcpy(MsgList+MsgSize,DestStr);
    MsgSize+=DestLength;
    MsgCount++;
  }
  char *CurAddr=MsgList;
  MsgAddr=new LPSTR[MsgCount];
  if (MsgAddr==NULL)
  {
    fclose(LangFile);
    return(FALSE);
  }
  for (int I=0;I<MsgCount;I++)
  {
    MsgAddr[I]=CurAddr;
    CurAddr+=strlen(CurAddr)+1;
  }
  fclose(LangFile);
  SetLastError(LastError);
  return(TRUE);
}


void Language::Close()
{
  delete MsgList;
  MsgList=NULL;
  delete MsgAddr;
  MsgAddr=NULL;
  MsgCount=0;
  MsgSize=0;
}


void Language::ConvertString(char *Src,char *Dest)
{
  while (*Src)
    switch(*Src)
    {
      case '\\':
        switch(Src[1])
        {
          case '\\':
            *(Dest++)='\\';
            Src+=2;
            break;
          case '\"':
            *(Dest++)='\"';
            Src+=2;
            break;
          case 'n':
            *(Dest++)='\n';
            Src+=2;
            break;
          case 'r':
            *(Dest++)='\r';
            Src+=2;
            break;
          case 'b':
            *(Dest++)='\b';
            Src+=2;
            break;
          case 't':
            *(Dest++)='\t';
            Src+=2;
            break;
          default:
            *(Dest++)='\\';
            Src++;
            break;
        }
        break;
      case '"':
        *(Dest++)='"';
        Src+=(Src[1]=='"') ? 2:1;
        break;
      default:
        *(Dest++)=*(Src++);
        break;
    }
  *Dest=0;
}


char* Language::GetMsg(int MsgId)
{
  if (MsgId>=MsgCount)
  {
    char Msg1[100],Msg2[100];
    sprintf(Msg1,"Incorrect or damaged %s",MessageFile);
    sprintf(Msg2,"Message %d not found",MsgId);
    if (Message(MSG_WARNING,2,"Error",Msg1,Msg2,"Ok","Quit")==1)
      exit(0);
    return("");
  }
  return(MsgAddr[MsgId]);
}


FILE* Language::OpenLangFile(char *Path,char *Mask,char *Language,char *FileName)
{
  *FileName=0;

  FILE *LangFile=NULL;
  char FullName[NM],EngFileName[NM];
  WIN32_FIND_DATA FindData;

  *EngFileName=0;

  ScanTree ScTree(FALSE,FALSE);
  ScTree.SetFindPath(Path,Mask);
  while (ScTree.GetNextName(&FindData,FullName))
  {
    strcpy(FileName,FullName);
    if (Language==NULL)
      break;
    if ((LangFile=fopen(FileName,"rb"))==NULL)
      *FileName=0;
    else
    {
      char LangName[100];
      if (GetLangParam(LangFile,"Language",LangName,NULL) && stricmp(LangName,Language)==0)
        break;
      if (stricmp(LangName,"English")==0)
        strcpy(EngFileName,FileName);
      fclose(LangFile);
      LangFile=NULL;
    }
  }

  if (LangFile==NULL)
  {
    if (*EngFileName)
      strcpy(FileName,EngFileName);
    if (*FileName)
      LangFile=fopen(FileName,"rb");
  }

  return(LangFile);
}


int Language::GetLangParam(FILE *SrcFile,char *ParamName,char *Param1,char *Param2)
{
  char ReadStr[1024],FullParamName[64];
  sprintf(FullParamName,".%s=",ParamName);
  int Length=strlen(FullParamName);
  fseek(SrcFile,0,SEEK_SET);
  while (fgets(ReadStr,sizeof(ReadStr),SrcFile)!=NULL)
    if (strnicmp(ReadStr,FullParamName,Length)==0)
    {
      strcpy(Param1,ReadStr+Length);
      char *EndPtr=strchr(Param1,',');
      if (Param2)
        *Param2=0;
      if (EndPtr!=NULL)
      {
        if (Param2)
        {
          strcpy(Param2,EndPtr+1);
          RemoveTrailingSpaces(Param2);
        }
        *EndPtr=0;
      }
      RemoveTrailingSpaces(Param1);
      return(TRUE);
    }
  return(FALSE);
}


int Language::Select(int HelpLanguage,VMenu **MenuPtr)
{
  char *Title,*Mask,*Dest;
  if (HelpLanguage)
  {
    Title=MSG(MHelpLangTitle);
    Mask=HelpFileMask;
    Dest=Opt.HelpLanguage;
  }
  else
  {
    Title=MSG(MLangTitle);
    Mask=LangFileMask;
    Dest=Opt.Language;
  }

  struct MenuItem LangMenuItem;
  LangMenuItem.Checked=LangMenuItem.Separator=*LangMenuItem.UserData=LangMenuItem.UserDataSize=0;
  VMenu *LangMenu=new VMenu(Title,NULL,0,ScrY-4);
  *MenuPtr=LangMenu;
  LangMenu->SetFlags(MENU_WRAPMODE);
  LangMenu->SetPosition(ScrX/2-8+5*HelpLanguage,ScrY/2-4+2*HelpLanguage,0,0);

  char FullName[NM];
  WIN32_FIND_DATA FindData;
  ScanTree ScTree(FALSE,FALSE);
  ScTree.SetFindPath(FarPath,Mask);
  while (ScTree.GetNextName(&FindData,FullName))
  {
    FILE *LangFile=fopen(FullName,"rb");
    if (LangFile==NULL)
      continue;
    char LangName[200],LangDescr[200];
    if (GetLangParam(LangFile,"Language",LangName,LangDescr))
    {
      sprintf(LangMenuItem.Name,"%.40s",*LangDescr ? LangDescr:LangName);
      LangMenuItem.Selected=(stricmp(Dest,LangName)==0);
      strcpy(LangMenuItem.UserData,LangName);
      LangMenuItem.UserDataSize=strlen(LangName)+1;
      LangMenu->AddItem(&LangMenuItem);
    }
    fclose(LangFile);
  }
  LangMenu->AssignHighlights(FALSE);
  LangMenu->Process();
  if (LangMenu->GetExitCode()<0)
    return(FALSE);
  return(LangMenu->GetUserData(Dest,100));
}
