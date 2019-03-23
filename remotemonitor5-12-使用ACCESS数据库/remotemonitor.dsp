# Microsoft Developer Studio Project File - Name="remotemonitor" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=remotemonitor - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "remotemonitor.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "remotemonitor.mak" CFG="remotemonitor - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "remotemonitor - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "remotemonitor - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "remotemonitor - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 odbccp32.lib winmm.lib /nologo /subsystem:windows /machine:I386 /out:"remotemonitor.exe"

!ELSEIF  "$(CFG)" == "remotemonitor - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 odbccp32.lib winmm.lib /nologo /subsystem:windows /debug /machine:I386 /out:"remotemonitor.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "remotemonitor - Win32 Release"
# Name "remotemonitor - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AddCableConfig.cpp
# End Source File
# Begin Source File

SOURCE=.\AddorChangeFenjiInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\AddorChangeMaintenanceDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddorChangeUserDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddUserdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CableAlarmTable.cpp
# End Source File
# Begin Source File

SOURCE=.\CableInfoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CableInfoSet.cpp
# End Source File
# Begin Source File

SOURCE=.\CableInfoTable.cpp
# End Source File
# Begin Source File

SOURCE=.\CableNumDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CangeCableNumDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CenterTelTable.cpp
# End Source File
# Begin Source File

SOURCE=.\ChangeFenjinumdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ComboColorPicker.cpp
# End Source File
# Begin Source File

SOURCE=.\Comm32.cpp
# End Source File
# Begin Source File

SOURCE=.\Draw.cpp
# End Source File
# Begin Source File

SOURCE=.\DutyRecordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DutyTable.cpp
# End Source File
# Begin Source File

SOURCE=.\FenjiCableSet.cpp
# End Source File
# Begin Source File

SOURCE=.\FenjiInfoPage.cpp
# End Source File
# Begin Source File

SOURCE=.\FenjiNumDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FenjiPropertySheet.cpp
# End Source File
# Begin Source File

SOURCE=.\FenjiTable.cpp
# End Source File
# Begin Source File

SOURCE=.\JiaoBanDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LinePicker.cpp
# End Source File
# Begin Source File

SOURCE=.\Logindlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\PenProperties.cpp
# End Source File
# Begin Source File

SOURCE=.\remotemonitor.cpp
# End Source File
# Begin Source File

SOURCE=.\remotemonitor.rc
# End Source File
# Begin Source File

SOURCE=.\remotemonitorDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\remotemonitorView.cpp
# End Source File
# Begin Source File

SOURCE=.\SCBARG.CPP
# End Source File
# Begin Source File

SOURCE=.\SendAAdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SendABdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SendCBdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SendCCdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SendCDdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SendDAdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SendDCDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SetCenterTeldlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SetNodeNumdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SIZECBAR.CPP
# End Source File
# Begin Source File

SOURCE=.\StaffTable.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\UserSetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewCableAlarmInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewDutyInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\ViewFenjiCableInfo.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AddCableConfig.h
# End Source File
# Begin Source File

SOURCE=.\AddorChangeFenjiInfo.h
# End Source File
# Begin Source File

SOURCE=.\AddorChangeMaintenanceDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddorChangeUserDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddUserdlg.h
# End Source File
# Begin Source File

SOURCE=.\CableAlarmTable.h
# End Source File
# Begin Source File

SOURCE=.\CableInfoDlg.h
# End Source File
# Begin Source File

SOURCE=.\CableInfoSet.h
# End Source File
# Begin Source File

SOURCE=.\CableInfoTable.h
# End Source File
# Begin Source File

SOURCE=.\CableNumDlg.h
# End Source File
# Begin Source File

SOURCE=.\CangeCableNumDlg.h
# End Source File
# Begin Source File

SOURCE=.\CenterTelTable.h
# End Source File
# Begin Source File

SOURCE=.\ChangeFenjinumdlg.h
# End Source File
# Begin Source File

SOURCE=.\ComboColorPicker.h
# End Source File
# Begin Source File

SOURCE=.\define.h
# End Source File
# Begin Source File

SOURCE=.\Draw.h
# End Source File
# Begin Source File

SOURCE=.\DutyRecordDlg.h
# End Source File
# Begin Source File

SOURCE=.\DutyTable.h
# End Source File
# Begin Source File

SOURCE=.\FenjiCableSet.h
# End Source File
# Begin Source File

SOURCE=.\FenjiInfoPage.h
# End Source File
# Begin Source File

SOURCE=.\FenjiNumDlg.h
# End Source File
# Begin Source File

SOURCE=.\FenjiPropertySheet.h
# End Source File
# Begin Source File

SOURCE=.\FenjiTable.h
# End Source File
# Begin Source File

SOURCE=.\JiaoBanDlg.h
# End Source File
# Begin Source File

SOURCE=.\LinePicker.h
# End Source File
# Begin Source File

SOURCE=.\Logindlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\PenProperties.h
# End Source File
# Begin Source File

SOURCE=.\remotemonitor.h
# End Source File
# Begin Source File

SOURCE=.\remotemonitorDoc.h
# End Source File
# Begin Source File

SOURCE=.\remotemonitorView.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SCBARG.H
# End Source File
# Begin Source File

SOURCE=.\SendAAdlg.h
# End Source File
# Begin Source File

SOURCE=.\SendABdlg.h
# End Source File
# Begin Source File

SOURCE=.\SendCBdlg.h
# End Source File
# Begin Source File

SOURCE=.\SendCCdlg.h
# End Source File
# Begin Source File

SOURCE=.\SendCDdlg.h
# End Source File
# Begin Source File

SOURCE=.\SendDAdlg.h
# End Source File
# Begin Source File

SOURCE=.\SendDCDlg.h
# End Source File
# Begin Source File

SOURCE=.\SetCenterTeldlg.h
# End Source File
# Begin Source File

SOURCE=.\SetNodeNumdlg.h
# End Source File
# Begin Source File

SOURCE=.\SIZECBAR.H
# End Source File
# Begin Source File

SOURCE=.\StaffTable.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\UserSetDlg.h
# End Source File
# Begin Source File

SOURCE=.\ViewCableAlarmInfo.h
# End Source File
# Begin Source File

SOURCE=.\ViewDutyInfo.h
# End Source File
# Begin Source File

SOURCE=.\ViewFenjiCableInfo.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\cur00001.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00002.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00003.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\mainfram.bmp
# End Source File
# Begin Source File

SOURCE=.\res\pan.cur
# End Source File
# Begin Source File

SOURCE=.\res\remotemonitor.ico
# End Source File
# Begin Source File

SOURCE=.\res\remotemonitor.rc2
# End Source File
# Begin Source File

SOURCE=.\res\remotemonitorDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\select.cur
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\userdraw.cur
# End Source File
# Begin Source File

SOURCE=.\res\usermoving.cur
# End Source File
# Begin Source File

SOURCE=.\res\zoomin.cur
# End Source File
# Begin Source File

SOURCE=.\res\zoomin1.cur
# End Source File
# Begin Source File

SOURCE=.\res\zoomout.cur
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
