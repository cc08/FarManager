#ifndef __KEYMACRO_HPP__
#define __KEYMACRO_HPP__
/*
macro.hpp

�������

*/

#include "farconst.hpp"
#include "syntax.hpp"

class Panel;

struct MacroRecord
{
  DWORD  Flags;         // ����� �����������������������
  int    Key;           // ����������� �������
  int    BufferSize;    // ������ ������ ��������������� ������������������
  DWORD *Buffer;        // ��������������� ������������������ (OpCode) �������
  char  *Src;           // ������������ "�����" �������
  DWORD  Reserved[3];   // ���������������
};

#define STACKLEVEL      16

struct MacroState
{
  int Executing;
  int MacroPC;
  int ExecLIBPos;
  int MacroWORKCount;
  struct MacroRecord *MacroWORK; // �.�. ������� ����������
};

/* $TODO:
    1. ������� IndexMode[], Sort()
    2. �� MacroLIB �������
       struct MacroRecord *MacroLIB[MACRO_LAST];
*/
class KeyMacro
{
  private:
    DWORD MacroVersion;
    // ��� ������ - � ������� ������� �������� ���...
    // 0 - ��� ������, 1 - ������� ������, 2 - ����� ������� ��������
    int Recording;
    int InternalInput;
    int IsRedrawEditor;

    int Mode;
    int StartMode;

    struct MacroState Work;
    struct MacroState PCStack[STACKLEVEL];
    int CurPCStack;

    // ���� "�����" ������ ������ ��� ������ �������� (��������� ������),
    // � ��������� ����� MacroWORK
    int MacroLIBCount;
    struct MacroRecord *MacroLIB;

    int IndexMode[MACRO_LAST][2];

    int RecBufferSize;
    DWORD *RecBuffer;

    class LockScreen *LockScr;

  private:
    int ReadVarsConst(int ReadMode, char *Buffer, int BufferSize);
    int WriteVarsConst(int ReadMode);
    int ReadMacros(int ReadMode, char *Buffer, int BufferSize);
    DWORD AssignMacroKey();
    int GetMacroSettings(int Key,DWORD &Flags);
    void InitInternalVars(BOOL InitedRAM=TRUE);
    void InitInternalLIBVars();
    void ReleaseWORKBuffer(BOOL All=FALSE); // ������� ��������� �����

    DWORD SwitchFlags(DWORD& Flags,DWORD Value);
    char *MkRegKeyName(int IdxMacro,char *RegKeyName);

    BOOL CheckEditSelected(DWORD CurFlags);
    BOOL CheckInsidePlugin(DWORD CurFlags);
    BOOL CheckPanel(int PanelMode,DWORD CurFlags, BOOL IsPassivePanel);
    BOOL CheckCmdLine(int CmdLength,DWORD Flags);
    BOOL CheckFileFolder(Panel *ActivePanel,DWORD CurFlags, BOOL IsPassivePanel);
    BOOL CheckAll(int CheckMode,DWORD CurFlags);
    void Sort(void);
    TVar FARPseudoVariable(DWORD Flags,DWORD Code);
    DWORD GetOpCode(struct MacroRecord *MR,int PC);
    DWORD SetOpCode(struct MacroRecord *MR,int PC,DWORD OpCode);

  private:
    static LONG_PTR WINAPI AssignMacroDlgProc(HANDLE hDlg,int Msg,int Param1,LONG_PTR Param2);
    static LONG_PTR WINAPI ParamMacroDlgProc(HANDLE hDlg,int Msg,int Param1,LONG_PTR Param2);

  public:
    KeyMacro();
    ~KeyMacro();

  public:
    int ProcessKey(int Key);
    int GetKey();
    int PeekKey();

    int PushState();
    int PopState();
    int GetLevelState(){return CurPCStack;};

    int  IsRecording() {return(Recording);};
    int  IsExecuting() {return(Work.Executing);};
    int  IsExecutingLastKey();
    int  IsDsableOutput() {return CheckCurMacroFlags(MFLAGS_DISABLEOUTPUT);};
    void SetMode(int Mode) {KeyMacro::Mode=Mode;};
    int  GetMode() {return(Mode);};

    void RunStartMacro();

    // ��������� ��������� ��������� ������������� �������
    int PostNewMacro(char *PlainText,DWORD Flags=0);
    // ��������� ��������� ������ (�������� �������������)
    int PostNewMacro(struct MacroRecord *MRec,BOOL NeedAddSendFlag=0);

    int  LoadMacros(BOOL InitedRAM=TRUE);
    void SaveMacros(BOOL AllSaved=TRUE);

    int GetStartIndex(int Mode) {return IndexMode[Mode<MACRO_LAST-1?Mode:MACRO_LAST-1][0];}
    // ������� ��������� ������� ������� ������� � �������
    int GetIndex(int Key, int Mode);
    // ��������� �������, ����������� ��������� ��������
    int GetRecordSize(int Key, int Mode);

    char *GetPlainText(char *Dest);
    int   GetPlainTextSize();

    void SetRedrawEditor(int Sets){IsRedrawEditor=Sets;}

    void RestartAutoMacro(int Mode);

    // �������� ������ � ������� (���������� ������)
    int GetCurRecord(struct MacroRecord* RBuf=NULL,int *KeyPos=NULL);
    // ��������� ����� �������� ������������ �������.
    BOOL CheckCurMacroFlags(DWORD Flags);

    static char* GetSubKey(int Mode);
    static int   GetSubKey(char *Mode);
    static int   GetMacroKeyInfo(int Mode,int Pos,char *KeyName,char *Description,int DescriptionSize);
    static char *MkTextSequence(DWORD *Buffer,int BufferSize,const char *Src=NULL);
    // �� ���������� ������������� ������� ������� MacroRecord
    int ParseMacroString(struct MacroRecord *CurMacro,const char *BufPtr);
    void DropProcess();
};

#endif // __KEYMACRO_HPP__
