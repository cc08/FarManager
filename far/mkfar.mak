#
# ��������� FAR Manager
# Modify: 25.06.2000 SVS
# Modify: 27.06.2000 tran (precompiled headers)
# Modify: 29.06.2000 SVS (������� +BccW32.cfg -
#                         � �������� �� � ������� ��� ��ப�)
#                        + 䠩� FAR.EXE ᮧ������ � ⥪�饬 ��⠫���
#                          ��᫥ 祣� ��������� � final
# Modify: 04.07.2000 SVS +����஢���� hlf&lng 䠩��� � final
#                        +��⠢�� ��८�।������� �㭪橨 ����� �����
#
# Modify: 12.07.2000 SVS +$(FARCMEM) - ��� ����祭�� � ��⮢�� 楫��
#                         ����� cmem
# Modify: 06.12.2000 SVS + $(OBJPATH)\mix.obj: mix.cpp cc.bat
#              �⮡� ��窠�� �� 㤠���� mix.obj, �᫨ ���⠢��� 䫠� SYSLOG
#
# Modify: 30.12.2000 SVS + fileattr
#
# make -fmkfar.mak [options]
#   -DALLOC - ��⠢��� ��८�।������ �㭪樨 ࠡ��� � �������
# ����, ���� �� �㤥� ��४�������� �� ��������� H*-䠩���
.AUTODEPEND

# ������� �� ��६����� �।� (env)
LIBPATH=$(FARLIB)
INCLUDEPATH=$(FARINC)
BCCPATH=$(FARBCC)
# bccpath �㦥� ��� ⮣�, �⮡� ��אַ �ᯮ�짮���� ��� � exe 䠩���
# set bccpath=e:\bc5, ���� � path ����� ᨤ��� ᮢᥬ ��㣮� ��ૠ��

# ���� ��� �㡫���� HPP-䠩���
FARINCLUDE=Include

# � �㤥� ����饭 १����
FINALPATH=final

# ���� � ��⠫��� � �६���묨 䠩���� - obj, etc
!ifdef DEBUG
OBJPATH=OBJD
!else
OBJPATH=OBJ
!endif

.path.obj = $(OBJPATH)
.path.cpp = .
.path.c   = .
.path.exe = $(FINALPATH)


!ifdef DEBUG
OPTDEBUG=-v -R -y
OPTDEBUG2=
CSMFILE=Far.csm
OPTLINKDEBUG=-v
# FAR_STDHDR_OBJ - �� ��� ࠧ �� 䠩�, � ���஬ �� ����� �� DEBUG ��� �� ��.��஢
FAR_STDHDR_OBJ="$(OBJPATH)\Far.#00"
!else
OPTDEBUG=-v- -R- -y-
OPTDEBUG2=-DNDEBUG
CSMFILE=Far.csm
OPTLINKDEBUG=-v-
FAR_STDHDR_OBJ=
!endif


!ifdef PRECOMP
PRECOMPOPT=-H -H=$(OBJPATH)\$(CSMFILE)
!else
PRECOMPOPT=-H-
!endif


#
# Borland C++ tools
#
BCC32   = $(BCCPATH)\bin\Bcc32 +BccW32.cfg
!ifdef ILINK
TLINK32 = $(BCCPATH)\bin\ilink32
BRC32   = $(BCCPATH)\bin\Brcc32
!else
TLINK32 = $(BCCPATH)\bin\Tlink32
BRC32   = $(BCCPATH)\bin\Brc32
!endif
# TLIB    = $(BCCPATH)\TLib - � ��祬 �� ��� �㦥�?
# IMPLIB  = $(BCCPATH)\bin\Implib - � ��� ⮦�?


#
# Options
#
LINKFLAGS =  -L$(LIBPATH) -Tpe -ap -c $(OPTLINKDEBUG) -s -V4.0 -j.\$(OBJPATH)


CCFLAGS =

RESFLAGS = -i$(INCLUDEPATH)


FAROBJ=\
   $(OBJPATH)\checkver.obj\
   $(OBJPATH)\udlist.obj\
   $(OBJPATH)\FileMasksProcessor.obj\
   $(OBJPATH)\FileMasksWithExclude.obj\
   $(OBJPATH)\CFileMask.obj\
   $(OBJPATH)\chgmmode.obj\
   $(OBJPATH)\chgprior.obj\
   $(OBJPATH)\clipboard.obj\
   $(OBJPATH)\cmdline.obj\
   $(OBJPATH)\config.obj\
   $(OBJPATH)\constitle.obj\
   $(OBJPATH)\copy.obj\
   $(OBJPATH)\ctrlobj.obj\
   $(OBJPATH)\delete.obj\
   $(OBJPATH)\dialog.obj\
   $(OBJPATH)\dizlist.obj\
   $(OBJPATH)\edit.obj\
   $(OBJPATH)\editor.obj\
   $(OBJPATH)\eject.obj\
   $(OBJPATH)\farqueue.obj\
   $(OBJPATH)\farrtl.obj\
   $(OBJPATH)\ffolders.obj\
   $(OBJPATH)\fileattr.obj\
   $(OBJPATH)\fileedit.obj\
   $(OBJPATH)\filelist.obj\
   $(OBJPATH)\filepanels.obj\
   $(OBJPATH)\filestr.obj\
   $(OBJPATH)\filetype.obj\
   $(OBJPATH)\fileview.obj\
   $(OBJPATH)\filter.obj\
   $(OBJPATH)\findfile.obj\
   $(OBJPATH)\flink.obj\
   $(OBJPATH)\flmodes.obj\
   $(OBJPATH)\flplugin.obj\
   $(OBJPATH)\flshow.obj\
   $(OBJPATH)\flupdate.obj\
   $(OBJPATH)\foldtree.obj\
   $(OBJPATH)\gettable.obj\
   $(OBJPATH)\cvtname.obj\
   $(OBJPATH)\global.obj\
   $(OBJPATH)\grabber.obj\
   $(OBJPATH)\grpsort.obj\
   $(OBJPATH)\help.obj\
   $(OBJPATH)\hilight.obj\
   $(OBJPATH)\history.obj\
   $(OBJPATH)\hmenu.obj\
   $(OBJPATH)\infolist.obj\
   $(OBJPATH)\int64.obj\
   $(OBJPATH)\interf.obj\
   $(OBJPATH)\iswind.obj\
   $(OBJPATH)\keybar.obj\
   $(OBJPATH)\keyboard.obj\
   $(OBJPATH)\language.obj\
   $(OBJPATH)\local.obj\
   $(OBJPATH)\lockscrn.obj\
   $(OBJPATH)\macro.obj\
   $(OBJPATH)\manager.obj\
   $(OBJPATH)\menubar.obj\
   $(OBJPATH)\message.obj\
   $(OBJPATH)\strftime.obj\
   $(OBJPATH)\mix.obj\
   $(OBJPATH)\mkdir.obj\
   $(OBJPATH)\modal.obj\
   $(OBJPATH)\namelist.obj\
   $(OBJPATH)\options.obj\
   $(OBJPATH)\palette.obj\
   $(OBJPATH)\execute.obj\
   $(OBJPATH)\fnparce.obj\
   $(OBJPATH)\panel.obj\
   $(OBJPATH)\plist.obj\
   $(OBJPATH)\plognmn.obj\
   $(OBJPATH)\plugapi.obj\
   $(OBJPATH)\plugins.obj\
   $(OBJPATH)\poscache.obj\
   $(OBJPATH)\print.obj\
   $(OBJPATH)\mktemp.obj\
   $(OBJPATH)\qsortex.obj\
   $(OBJPATH)\qview.obj\
   $(OBJPATH)\rdrwdsk.obj\
   $(OBJPATH)\registry.obj\
   $(OBJPATH)\savefpos.obj\
   $(OBJPATH)\savescr.obj\
   $(OBJPATH)\scantree.obj\
   $(OBJPATH)\scrbuf.obj\
   $(OBJPATH)\scrobj.obj\
   $(OBJPATH)\scrsaver.obj\
   $(OBJPATH)\setattr.obj\
   $(OBJPATH)\setcolor.obj\
   $(OBJPATH)\stddlg.obj\
   $(OBJPATH)\strmix.obj\
   $(OBJPATH)\syslog.obj\
   $(OBJPATH)\treelist.obj\
   $(OBJPATH)\usermenu.obj\
   $(OBJPATH)\viewer.obj\
   $(OBJPATH)\vmenu.obj\
   $(OBJPATH)\frame.obj\
   $(OBJPATH)\xlat.obj\
   $(OBJPATH)\farexcpt.obj\
   $(OBJPATH)\strncpy.obj\
   $(OBJPATH)\cmem.obj\
   $(OBJPATH)\main.obj




# ************************************************************************
ALL : BccW32.cfg $(FINALPATH)\Far.exe $(FARINCLUDE)\farcolor.hpp $(FARINCLUDE)\farkeys.hpp $(FARINCLUDE)\plugin.hpp
  @echo MakeNode

# �� �� ����ᨬ��� �� �㦭�
# ���� ����뢠�� ���� �ࠢ��� � �� %)
.cpp.obj:
  @settitle "{$.} - Compiling..."
  @if not exist $(OBJPATH) mkdir $(OBJPATH)
  @$(BCC32) -c -o$@ {$. }

.c.obj:
  @settitle "{$.} - Compiling..."
  @if not exist $(OBJPATH) mkdir $(OBJPATH)
  @$(BCC32) -c -o$@ {$. }

# ��筥���
$(OBJPATH)\syslog.obj: syslog.cpp cc.bat
$(OBJPATH)\flink.obj: flink.cpp cc.bat
$(OBJPATH)\copy.obj: copy.cpp cc.bat
$(OBJPATH)\global.obj: global.cpp global.hpp farversion.inc copyright.inc

# ************************************************************************
# ����ᨬ��� ��� �㡫���� 䠩���
# ************************************************************************
$(FARINCLUDE)\farcolor.hpp : colors.hpp
   @if not exist $(FARINCLUDE) mkdir $(FARINCLUDE)
   -@awk -f plugins.awk -v p1=1 -v p2=70 colors.hpp > $(FARINCLUDE)\farcolor.hpp

$(FARINCLUDE)\farkeys.hpp : keys.hpp
   @if not exist $(FARINCLUDE) mkdir $(FARINCLUDE)
   -@awk -f plugins.awk -v p1=1 -v p2=70 keys.hpp   > $(FARINCLUDE)\farkeys.hpp

$(FARINCLUDE)\plugin.hpp : plugin.hpp
   @if not exist $(FARINCLUDE) mkdir $(FARINCLUDE)
   -@awk -f plugins.awk -v p1=1 -v p2=70 plugin.hpp > $(FARINCLUDE)\plugin.hpp

# ************************************************************************
$(OBJPATH)\Far.res :  Far.rc
  -@settitle "Compiling resource..."
  @if not exist $(OBJPATH) mkdir $(OBJPATH)
  $(BRC32) -R @&&|
 $(RESFLAGS)  -FO$@ Far.rc
|

!ifdef ILINK
$(FINALPATH)\Far.exe : BccW32.cfg Far.def $(OBJPATH)\Far.res $(FAROBJ)
  -@settitle "Linking..."
  @if not exist $(FARINCLUDE) mkdir $(FARINCLUDE)
  @$(TLINK32)  $(LINKFLAGS) @&&|
$(LIBPATH)\c0x32.obj $(FAROBJ) $(FAR_STDHDR_OBJ)
$<,$*
$(LIBPATH)\import32.lib $(LIBPATH)\cw32mt.lib
Far.def
$(OBJPATH)\Far.res
|
!else
$(FINALPATH)\Far.exe : BccW32.cfg Far.def $(OBJPATH)\Far.res $(FAROBJ)
  -@settitle "Linking..."
  @if not exist $(FINALPATH) mkdir $(FINALPATH)
  @$(TLINK32)  $(LINKFLAGS) @&&|
$(LIBPATH)\c0x32.obj $(FAROBJ) $(FAR_STDHDR_OBJ)
$<,$*
$(LIBPATH)\import32.lib $(LIBPATH)\cw32mt.lib
Far.def
|
   @copy Far.map $(FINALPATH)\Far.map
   @$(BRC32) $(OBJPATH)\Far.res $(OBJPATH)\Far.res $<
!endif

# ��易⥫쭮! �� �� � ����� �� ������...
   -@del $(FINALPATH)\FarEng.hlf  >nul
   -@del $(FINALPATH)\FarRus.hlf  >nul
   -@del $(FINALPATH)\FarEng.lng  >nul
   -@del $(FINALPATH)\FarRus.lng  >nul
!ifdef ILINK
   -@del $(FINALPATH)\Far.ilc  >nul
   -@del $(FINALPATH)\Far.ild  >nul
   -@del $(FINALPATH)\Far.ilf  >nul
   -@del $(FINALPATH)\Far.ils  >nul
   -@del $(FINALPATH)\Far.tds  >nul
!endif
   @awk -f mkhlf.awk -v FV1=$(FV1) -v FV2=$(FV2) -v FV3=$(FV3) FarEng.hlf > $(FINALPATH)\FarEng.hlf
   @awk -f mkhlf.awk -v FV1=$(FV1) -v FV2=$(FV2) -v FV3=$(FV3) FarRus.hlf > $(FINALPATH)\FarRus.hlf
   @copy FarEng.lng $(FINALPATH)\FarEng.lng >nul
   @copy FarRus.lng $(FINALPATH)\FarRus.lng >nul

   -@if exist plugin.pas awk -f plugins.awk -v p1=1 -v p2=70 -v Lang=pas plugin.pas > $(FARINCLUDE)\plugin.pas
   -@if exist fmt.hpp awk -f plugins.awk -v p1=1 -v p2=70 fmt.hpp > $(FARINCLUDE)\fmt.hpp
   -@if exist fmt.pas awk -f plugins.awk -v p1=1 -v p2=70 -v Lang=pas fmt.pas > $(FARINCLUDE)\fmt.pas


# Compiler configuration file
# ��� ��, � ���� ����� ���. ��ப� ��࠭�祭�
BccW32.cfg : mkfar.mak cc.bat
   Copy &&|
-WC
-WM
-K
-d
-f-
-k-
-RT
-Og
-Ot
-Z
-a8
-O
-Oe
-Ol
-Ob
-Om
-Op
-Ov
-w-csu
-x
-I$(INCLUDEPATH)
$(FARCMEM)
$(FARALLOC)
$(PRECOMPOPT)
$(OPTDEBUG)
$(OPTDEBUG2)
$(FARSYSLOG)
$(FARADDMACRO)
$(FUTUREMACRO)
| $@

# ************************************************************************
# ���⪠
# ************************************************************************
CLEAN :
    -@del /q /f $(OBJPATH)\*.*           > nul
	-@del /q /f $(FINALPATH)\Far.exe     > nul
	-@del /q /f $(FINALPATH)\Far.map     > nul
	-@del /q /f $(FINALPATH)\FarEng.hlf  > nul
	-@del /q /f $(FINALPATH)\FarEng.lng  > nul
	-@del /q /f $(FINALPATH)\FarRus.hlf  > nul
	-@del /q /f $(FINALPATH)\FarRus.lng  > nul
