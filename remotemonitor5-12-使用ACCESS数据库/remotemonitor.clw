; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRemotemonitorView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "remotemonitor.h"
LastPage=0

ClassCount=49
Class1=CRemotemonitorApp
Class2=CRemotemonitorDoc
Class3=CRemotemonitorView
Class4=CMainFrame

ResourceCount=33
Resource1=IDD_CABLEINFOSET
Class5=CAboutDlg
Resource2=IDD_FENJICABLEVIEW
Resource3=IDD_SENDCDDLG
Class6=CPenProperties
Resource4=IDD_VIEWCABLEALARMINFO
Class7=CMapSelectDlg
Class8=CLogindlg
Class9=CSendAAdlg
Resource5=IDD_SENDCBDLG
Resource6=IDD_ABOUTBOX
Class10=CSendABdlg
Class11=CSendCCdlg
Resource7=IDD_FENJIINFO
Class12=CSendCDdlg
Resource8=IDD_SETCENTERTELDLG
Class13=CSendDAdlg
Resource9=IDD_SETNODENUM
Class14=CSetNodeNumdlg
Class15=CStaffTable
Class16=CDutyTable
Resource10=IDD_SENDAADLG
Class17=CDutyRecordDlg
Resource11=IDD_CABLENUM
Class18=CJiaoBanDlg
Resource12=IDD_ADDORCHANGEUSER
Resource13=IDD_DUTYRECORD
Class19=CFenjiPropertySheet
Class20=CFenjiInfoPage
Class21=CFenjiParaPage
Resource14=IDD_PENPROPERTIES
Class22=CFenjiInfoTable
Class23=CFenjiParaTable
Class24=CFenjiNumDlg
Resource15=IDD_CHANGEFENJINUM
Class25=CChangeFenjinumdlg
Class26=CFenjiTable
Resource16=IDD_LOGIN
Class27=CAddorChangeUserDlg
Resource17=IDD_DUTYRECORDDLG
Class28=CAddorChangeMaintenanceDlg
Class29=CCableInfoTable
Resource18=IDD_FENJICABLESET
Class30=CCableNumDlg
Resource19=IDD_ADDCABLECONFIG
Class31=CCangeCableNumDlg
Resource20=IDD_SENDABDLG
Class32=CCableInfoDlg
Resource21=IDD_SENDCCDLG
Class33=CFenjiCableSet
Resource22=IDD_CHANGECABLENUM
Class34=CAddorChangeFenjiInfo
Resource23=IDD_ADDFENJIINFO
Class35=CCableInfoSet
Resource24=IDD_FENJIPARA
Class36=CUserSetDlg
Resource25=IDD_JIAOBAN
Class37=CAddUserdlg
Resource26=IDD_ADDUSERDLG
Class38=CViewDutyInfo
Resource27=IDD_CABLEINFO
Class39=CViewFenjiCableInfo
Class40=CFenjiAlarmTable
Resource28=IDD_USERSET
Class41=CViewFenjiAlarm
Resource29=IDD_ADDORCHANGEMAIN
Class42=CViewCableAlarmInfo
Class43=CCableAlarmTable
Resource30=IDD_SENDDADLG
Class44=CAddCableConfig
Resource31=IDD_SENDDCDLG
Class45=CCenterTelTable
Class46=CSendCBdlg
Class47=CSetCenterTeldlg
Class48=CTempSet
Resource32=IDD_FENJINUM
Class49=CSendDCDlg
Resource33=IDR_MAINFRAME

[CLS:CRemotemonitorApp]
Type=0
HeaderFile=remotemonitor.h
ImplementationFile=remotemonitor.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CRemotemonitorApp

[CLS:CRemotemonitorDoc]
Type=0
HeaderFile=remotemonitorDoc.h
ImplementationFile=remotemonitorDoc.cpp
Filter=N
LastObject=CRemotemonitorDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CRemotemonitorView]
Type=0
HeaderFile=remotemonitorView.h
ImplementationFile=remotemonitorView.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=ID_FILE_SAVE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_SENDAA
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=remotemonitor.cpp
ImplementationFile=remotemonitor.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_USERSET
Command8=ID_FENJICABLESET
Command9=ID_SETCENTERTEL
Command10=ID_VIEWDUTYRECORD
Command11=ID_VIEWFENJICABLEINFO
Command12=ID_VIEWCABLEALARMINFO
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_VIEW_LISTBAR
Command16=ID_DELETELISTITEM
Command17=ID_MAPCHANGE
Command18=ID_PAN
Command19=ID_ZOOMIN
Command20=ID_ZOOMOUT
Command21=ID_DRAW
Command22=ID_DRAWLINE
Command23=ID_DRAWCIRCLE
Command24=ID_SELECT
Command25=ID_DELETE
Command26=ID_SENDAA
Command27=ID_SENDAB
Command28=ID_SENDCA
Command29=ID_SENDCC
Command30=ID_SENDDA
Command31=ID_SENDDC
Command32=ID_SENDCB
Command33=ID_CLEARALARM
Command34=ID_DUTYRECORD
Command35=ID_JIAOBAN
Command36=ID_APP_ABOUT
CommandCount=36

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_VIEWFENJICABLEINFO
Command2=ID_VIEWFENJIALARMINFO
Command3=ID_CLEARALARM
Command4=ID_VIEWDUTYRECORD
Command5=ID_DELETE
Command6=ID_VIEWCABLEALARMINFO
Command7=ID_FENJICABLESET
Command8=ID_ZOOMIN
Command9=ID_DRAWLINE
Command10=ID_FILE_NEW
Command11=ID_FILE_OPEN
Command12=ID_ZOOMOUT
Command13=ID_FILE_PRINT
Command14=ID_PAN
Command15=ID_DRAWCIRCLE
Command16=ID_FILE_SAVE
Command17=ID_SELECT
Command18=ID_DRAW
Command19=ID_USERSET
Command20=ID_EDIT_PASTE
Command21=ID_EDIT_UNDO
Command22=ID_EDIT_CUT
Command23=ID_NEXT_PANE
Command24=ID_PREV_PANE
Command25=ID_EDIT_COPY
Command26=ID_EDIT_PASTE
Command27=ID_MAPCHANGE
Command28=ID_EDIT_CUT
Command29=ID_EDIT_UNDO
CommandCount=29

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_ARROW
Command5=ID_MAPCHANGE
Command6=ID_ZOOMIN
Command7=ID_ZOOMOUT
Command8=ID_PAN
Command9=ID_SELECT
Command10=ID_DELETE
Command11=ID_DRAWLINE
Command12=ID_DRAWCIRCLE
Command13=ID_APP_ABOUT
CommandCount=13

[DLG:IDD_PENPROPERTIES]
Type=1
Class=CPenProperties
ControlCount=9
Control1=IDC_PENCOLORCOMBO,combobox,1344340499
Control2=IDC_PENWIDTHCOMBO,combobox,1344340499
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BRUSHSTYLECOMBO,combobox,1344340499
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,button,1342177287
Control8=IDC_TEXTCOLOR,combobox,1344340499
Control9=IDC_STATIC,button,1342177287

[CLS:CPenProperties]
Type=0
HeaderFile=PenProperties.h
ImplementationFile=PenProperties.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_TEXTCOLOR

[CLS:CMapSelectDlg]
Type=0
HeaderFile=MapSelectDlg.h
ImplementationFile=MapSelectDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_MAPLIST

[DLG:IDD_LOGIN]
Type=1
Class=CLogindlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_PWD,edit,1350631584
Control6=IDC_STATIC,static,1342308352
Control7=IDC_PORT,combobox,1344339971
Control8=IDC_STATIC,static,1342308352
Control9=IDC_BAUDRATE,combobox,1344339971
Control10=IDC_USERNAME,combobox,1344339971

[CLS:CLogindlg]
Type=0
HeaderFile=Logindlg.h
ImplementationFile=Logindlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLogindlg
VirtualFilter=dWC

[DLG:IDD_SENDAADLG]
Type=1
Class=CSendAAdlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FENJINUMBER,edit,1350631552
Control5=IDC_LIST1,SysListView32,1350631429
Control6=IDC_STATIC,button,1342177287
Control7=IDC_ADD,button,1342242816
Control8=IDC_DELETE,button,1342242816

[CLS:CSendAAdlg]
Type=0
HeaderFile=SendAAdlg.h
ImplementationFile=SendAAdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSendAAdlg

[CLS:CSendABdlg]
Type=0
HeaderFile=SendABdlg.h
ImplementationFile=SendABdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSendABdlg

[DLG:IDD_SENDCCDLG]
Type=1
Class=CSendCCdlg
ControlCount=30
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FENJINUMBER,edit,1350631552
Control5=IDC_STATIC,button,1342177287
Control6=IDC_RADIO1,button,1342308361
Control7=IDC_EDIT1,edit,1350639744
Control8=IDC_SPIN1,msctls_updown32,1342177335
Control9=IDC_RADIO2,button,1342177289
Control10=IDC_RADIO3,button,1342177289
Control11=IDC_RADIO4,button,1342177289
Control12=IDC_RADIO5,button,1342177289
Control13=IDC_RADIO6,button,1342177289
Control14=IDC_RADIO7,button,1342177289
Control15=IDC_PROBE,button,1342242819
Control16=IDC_EDIT2,edit,1350639744
Control17=IDC_SPIN2,msctls_updown32,1342177335
Control18=IDC_EDIT3,edit,1350639744
Control19=IDC_SPIN3,msctls_updown32,1342177335
Control20=IDC_EDIT4,edit,1350639744
Control21=IDC_SPIN4,msctls_updown32,1342177335
Control22=IDC_COMBO6,combobox,1344339971
Control23=IDC_EDIT7,edit,1350639744
Control24=IDC_SPIN7,msctls_updown32,1342177335
Control25=IDC_EDIT5,edit,1350631552
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352

[CLS:CSendCCdlg]
Type=0
HeaderFile=SendCCdlg.h
ImplementationFile=SendCCdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT5

[DLG:IDD_SENDCDDLG]
Type=1
Class=CSendCDdlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_GBK,edit,1350635524
Control5=IDC_STATIC,static,1342308352
Control6=IDC_FENJINUMBER,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_COMBO1,combobox,1344339971

[CLS:CSendCDdlg]
Type=0
HeaderFile=SendCDdlg.h
ImplementationFile=SendCDdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_GBK

[DLG:IDD_SENDABDLG]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FENJINUMBER,edit,1350631552

[DLG:IDD_SENDDADLG]
Type=1
Class=CSendDAdlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FENJINUMBER,edit,1350631552

[CLS:CSendDAdlg]
Type=0
HeaderFile=SendDAdlg.h
ImplementationFile=SendDAdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSendDAdlg

[DLG:IDD_SETNODENUM]
Type=1
Class=CSetNodeNumdlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FENGJINUM,edit,1350631552
Control5=IDC_CABLESTATIC,static,1342308352
Control6=IDC_CABLENUM,combobox,1344340226

[CLS:CSetNodeNumdlg]
Type=0
HeaderFile=SetNodeNumdlg.h
ImplementationFile=SetNodeNumdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSetNodeNumdlg

[CLS:CStaffTable]
Type=0
HeaderFile=StaffTable.h
ImplementationFile=StaffTable.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CStaffTable]
DB=1
DBType=ODBC
ColumnCount=8
Column1=[Id], 4, 4
Column2=[Name], 12, 10
Column3=[Password], 12, 6
Column4=[Right], -6, 1
Column5=[Duty], 12, 20
Column6=[Telephone], 12, 16
Column7=[Department], 12, 20
Column8=[Address], 12, 40

[CLS:CDutyTable]
Type=0
HeaderFile=DutyTable.h
ImplementationFile=DutyTable.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CDutyTable]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[Id], 4, 4
Column2=[Name], 12, 10
Column3=[dutytime], 11, 16
Column4=[lefttime], 11, 16

[DLG:IDD_DUTYRECORD]
Type=1
Class=CDutyRecordDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RECORD,edit,1350631428
Control4=IDC_STATIC,button,1342177287

[CLS:CDutyRecordDlg]
Type=0
HeaderFile=DutyRecordDlg.h
ImplementationFile=DutyRecordDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RECORD

[DLG:IDD_JIAOBAN]
Type=1
Class=CJiaoBanDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PASSWORD1,edit,1350631584
Control7=IDC_COMBO1,combobox,1344339971

[CLS:CJiaoBanDlg]
Type=0
HeaderFile=JiaoBanDlg.h
ImplementationFile=JiaoBanDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CJiaoBanDlg

[CLS:CFenjiPropertySheet]
Type=0
HeaderFile=FenjiPropertySheet.h
ImplementationFile=FenjiPropertySheet.cpp
BaseClass=CPropertySheet
LastObject=ID_ARROW

[CLS:CFenjiInfoPage]
Type=0
HeaderFile=FenjiInfoPage.h
ImplementationFile=FenjiInfoPage.cpp
BaseClass=CPropertyPage
LastObject=CFenjiInfoPage
Filter=D
VirtualFilter=idWC

[CLS:CFenjiParaPage]
Type=0
HeaderFile=FenjiInfoPage.h
ImplementationFile=FenjiInfoPage.cpp
BaseClass=CPropertyPage
LastObject=IDC_EDIT1
Filter=D
VirtualFilter=idWC

[DLG:IDD_FENJIPARA]
Type=1
Class=CFenjiParaPage
ControlCount=14
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT1,edit,1350633472
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT2,edit,1350633472
Control9=IDC_EDIT3,edit,1350633472
Control10=IDC_EDIT4,edit,1350633472
Control11=IDC_EDIT5,edit,1350633472
Control12=IDC_EDIT7,edit,1350633472
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT6,edit,1350633472

[DLG:IDD_FENJIINFO]
Type=1
Class=CFenjiInfoPage
ControlCount=16
Control1=IDC_STATIC,static,1342308352
Control2=IDC_FENJINUM,edit,1350633600
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FENJINAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_FENJITEL,edit,1350631552
Control7=IDC_STATIC,button,1342177287
Control8=IDC_USERINFOLIST,SysListView32,1350631437
Control9=IDC_ADD1,button,1342242816
Control10=IDC_CHANGE1,button,1342242816
Control11=IDC_DELETE1,button,1342242816
Control12=IDC_STATIC,button,1342177287
Control13=IDC_MAINTENANCELIST,SysListView32,1350631429
Control14=IDC_ADD2,button,1342242816
Control15=IDC_CHANGE2,button,1342242816
Control16=IDC_DELETE2,button,1342242816

[CLS:CFenjiInfoTable]
Type=0
HeaderFile=FenjiInfoTable.h
ImplementationFile=FenjiInfoTable.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CFenjiInfoTable

[DB:CFenjiInfoTable]
DB=1
DBType=ODBC
ColumnCount=27
Column1=[Id], 4, 4
Column2=[Name], 12, 20
Column3=[telephone], 12, 13
Column4=[username1], 12, 10
Column5=[usertel1], 12, 13
Column6=[username2], 12, 10
Column7=[usertel2], 12, 13
Column8=[username3], 12, 10
Column9=[usertel3], 12, 13
Column10=[username4], 12, 10
Column11=[usertel4], 12, 13
Column12=[username5], 12, 10
Column13=[usertel5], 12, 13
Column14=[username6], 12, 10
Column15=[usertel6], 12, 13
Column16=[maintenance1], 12, 10
Column17=[maintenancetel1], 12, 13
Column18=[maintenance2], 12, 10
Column19=[maintenancetel2], 12, 13
Column20=[maintenance3], 12, 10
Column21=[maintenancetel3], 12, 13
Column22=[maintenance4], 12, 10
Column23=[maintenancetel4], 12, 13
Column24=[maintenance5], 12, 10
Column25=[maintenancetel5], 12, 13
Column26=[maintenance6], 12, 10
Column27=[maintenancetel6], 12, 13

[CLS:CFenjiParaTable]
Type=0
HeaderFile=FenjiParaTable.h
ImplementationFile=FenjiParaTable.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CFenjiParaTable

[DB:CFenjiParaTable]
DB=1
DBType=ODBC
ColumnCount=8
Column1=[Id], 4, 4
Column2=[ackwaittime], -6, 1
Column3=[sensitive], -6, 1
Column4=[callnumber], -6, 1
Column5=[waittime], -6, 1
Column6=[xudianchi], 7, 4
Column7=[mode], -6, 1
Column8=[zejuxisu], -6, 1

[DLG:IDD_FENJINUM]
Type=1
Class=CFenjiNumDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_NUMEDIT,edit,1350633472
Control4=IDC_CHANGEFENJINUM,button,1342242816
Control5=IDC_DISPLAYFENJIINFO,button,1342242816

[CLS:CFenjiNumDlg]
Type=0
HeaderFile=FenjiNumDlg.h
ImplementationFile=FenjiNumDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_NUMEDIT

[DLG:IDD_CHANGEFENJINUM]
Type=1
Class=CChangeFenjinumdlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NEWFENJINUM,edit,1350631552

[CLS:CChangeFenjinumdlg]
Type=0
HeaderFile=ChangeFenjinumdlg.h
ImplementationFile=ChangeFenjinumdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CChangeFenjinumdlg

[CLS:CFenjiTable]
Type=0
HeaderFile=FenjiTable.h
ImplementationFile=FenjiTable.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CFenjiTable]
DB=1
DBType=ODBC
ColumnCount=34
Column1=[Id], 4, 4
Column2=[Name], 12, 20
Column3=[telephone], 12, 13
Column4=[username1], 12, 10
Column5=[usertel1], 12, 13
Column6=[username2], 12, 10
Column7=[usertel2], 12, 13
Column8=[username3], 12, 10
Column9=[usertel3], 12, 13
Column10=[username4], 12, 10
Column11=[usertel4], 12, 13
Column12=[username5], 12, 10
Column13=[usertel5], 12, 13
Column14=[username6], 12, 10
Column15=[usertel6], 12, 13
Column16=[maintenance1], 12, 10
Column17=[maintenancetel1], 12, 13
Column18=[maintenance2], 12, 10
Column19=[maintenancetel2], 12, 13
Column20=[maintenance3], 12, 10
Column21=[maintenancetel3], 12, 13
Column22=[maintenance4], 12, 10
Column23=[maintenancetel4], 12, 13
Column24=[maintenance5], 12, 10
Column25=[maintenancetel5], 12, 13
Column26=[maintenance6], 12, 10
Column27=[maintenancetel6], 12, 13
Column28=[ackwaittime], -6, 1
Column29=[sensitive], -6, 1
Column30=[callnumber], -6, 1
Column31=[waittime], -6, 1
Column32=[xudianchi], 7, 4
Column33=[mode], -6, 1
Column34=[zejuxisu], -6, 1

[DLG:IDD_ADDORCHANGEUSER]
Type=1
Class=CAddorChangeUserDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2,edit,1350631552

[CLS:CAddorChangeUserDlg]
Type=0
HeaderFile=AddorChangeUserDlg.h
ImplementationFile=AddorChangeUserDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_ADDORCHANGEMAIN]
Type=1
Class=CAddorChangeMaintenanceDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_NAME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_TEL,edit,1350631552

[CLS:CAddorChangeMaintenanceDlg]
Type=0
HeaderFile=AddorChangeMaintenanceDlg.h
ImplementationFile=AddorChangeMaintenanceDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CCableInfoTable]
Type=0
HeaderFile=CableInfoTable.h
ImplementationFile=CableInfoTable.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CCableInfoTable

[DB:CCableInfoTable]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[Id], 4, 4
Column2=[name], 12, 30
Column3=[state], -6, 1

[DLG:IDD_CABLENUM]
Type=1
Class=CCableNumDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_FENJINUMBER,edit,1350633472
Control4=IDC_CHANGECABLENUM,button,1342242816
Control5=IDC_DISPLAYCABLEINFO,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_CABLENUMBER,edit,1350633472

[CLS:CCableNumDlg]
Type=0
HeaderFile=CableNumDlg.h
ImplementationFile=CableNumDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCableNumDlg

[DLG:IDD_CHANGECABLENUM]
Type=1
Class=CCangeCableNumDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NEWFENJINUM,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_CABLECOMBO,combobox,1344339971

[CLS:CCangeCableNumDlg]
Type=0
HeaderFile=CangeCableNumDlg.h
ImplementationFile=CangeCableNumDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_CABLEINFO]
Type=1
Class=CCableInfoDlg
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FENJINUM,edit,1350633600
Control5=IDC_STATIC,static,1342308352
Control6=IDC_CABLENUM,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STARTADDR,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_ENDADDR,edit,1350631552
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATE,edit,1350633600

[CLS:CCableInfoDlg]
Type=0
HeaderFile=CableInfoDlg.h
ImplementationFile=CableInfoDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCableInfoDlg

[DLG:IDD_FENJICABLESET]
Type=1
Class=CFenjiCableSet
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDC_FENJILIST,SysListView32,1350631429
Control3=IDC_CABLELIST,SysListView32,1350631429
Control4=IDC_ADD1,button,1342242816
Control5=IDC_CHANGE1,button,1342242816
Control6=IDC_DELETE1,button,1342242816
Control7=IDC_ADD2,button,1342242816
Control8=IDC_CHANGE2,button,1342242816
Control9=IDC_DELETE2,button,1342242816

[CLS:CFenjiCableSet]
Type=0
HeaderFile=FenjiCableSet.h
ImplementationFile=FenjiCableSet.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CFenjiCableSet

[DLG:IDD_ADDFENJIINFO]
Type=1
Class=CAddorChangeFenjiInfo
ControlCount=18
Control1=IDC_STATIC,static,1342308352
Control2=IDC_FENJINUM,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FENJINAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_FENJITEL,edit,1350631552
Control7=IDC_STATIC,button,1342177287
Control8=IDC_USERINFOLIST,SysListView32,1350631437
Control9=IDC_ADD1,button,1342242816
Control10=IDC_CHANGE1,button,1342242816
Control11=IDC_DELETE1,button,1342242816
Control12=IDC_STATIC,button,1342177287
Control13=IDC_MAINTENANCELIST,SysListView32,1350631429
Control14=IDC_ADD2,button,1342242816
Control15=IDC_CHANGE2,button,1342242816
Control16=IDC_DELETE2,button,1342242816
Control17=IDOK,button,1342242816
Control18=IDCANCEL,button,1342242816

[CLS:CAddorChangeFenjiInfo]
Type=0
HeaderFile=AddorChangeFenjiInfo.h
ImplementationFile=AddorChangeFenjiInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAddorChangeFenjiInfo

[DLG:IDD_CABLEINFOSET]
Type=1
Class=CCableInfoSet
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=65535,static,1342308352
Control4=IDC_FENJINUM,edit,1350631552
Control5=65535,static,1342308352
Control6=65535,static,1342308352
Control7=IDC_STARTADDR,edit,1350631552
Control8=65535,static,1342308352
Control9=IDC_ENDADDR,edit,1350631552
Control10=65535,button,1342177287
Control11=IDC_CABLECOMBO,combobox,1344339971

[CLS:CCableInfoSet]
Type=0
HeaderFile=CableInfoSet.h
ImplementationFile=CableInfoSet.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_USERSET]
Type=1
Class=CUserSetDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_LIST1,SysListView32,1350631429
Control3=IDC_ADD,button,1342242816
Control4=IDC_CHANGE,button,1342242816
Control5=IDC_DELETE,button,1342242816

[CLS:CUserSetDlg]
Type=0
HeaderFile=UserSetDlg.h
ImplementationFile=UserSetDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CUserSetDlg

[DLG:IDD_ADDUSERDLG]
Type=1
Class=CAddUserdlg
ControlCount=19
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_NAME,edit,1350631552
Control10=IDC_PWD,edit,1350631552
Control11=IDC_DUTY,edit,1350631552
Control12=IDC_TEL,edit,1350631552
Control13=IDC_DEPARTMENT,edit,1350631552
Control14=IDC_ADDRESS,edit,1350631552
Control15=IDC_STATIC,button,1342177287
Control16=IDC_RIGHTB,button,1342242819
Control17=IDC_RIGHTA,button,1342242819
Control18=IDC_RIGHTC,button,1342242819
Control19=IDC_RIGHTD,button,1342242819

[CLS:CAddUserdlg]
Type=0
HeaderFile=AddUserdlg.h
ImplementationFile=AddUserdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAddUserdlg

[DLG:IDD_DUTYRECORDDLG]
Type=1
Class=CViewDutyInfo
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDC_LIST1,SysListView32,1350631429
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_MODECOMBO,combobox,1344340227
Control6=IDC_BUTTON1,button,1342242816
Control7=IDC_BUTTON2,button,1342242816
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_EDIT2,edit,1350631552
Control10=IDC_MYSTATIC,static,1342308352
Control11=IDC_BUTTON3,button,1342242816
Control12=IDC_EXPORT4,button,1342242816

[CLS:CViewDutyInfo]
Type=0
HeaderFile=ViewDutyInfo.h
ImplementationFile=ViewDutyInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EXPORT4

[DLG:IDD_FENJICABLEVIEW]
Type=1
Class=CViewFenjiCableInfo
ControlCount=19
Control1=IDC_EDIT3,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDC_FENJILIST,SysListView32,1350631429
Control4=IDC_CABLELIST,SysListView32,1350631429
Control5=IDC_PROBE1,button,1342242816
Control6=IDC_MYSTATIC1,static,1342308352
Control7=IDC_EDIT1,edit,1350631552
Control8=IDC_MYSTATIC2,static,1342308352
Control9=IDC_EDIT2,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_MODE1,combobox,1344339971
Control12=IDC_PROBE2,button,1342242816
Control13=IDC_MYSTATIC3,static,1342308352
Control14=IDC_MYSTATIC4,static,1342308352
Control15=IDC_EDIT4,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_MODE2,combobox,1344339971
Control18=IDC_EXPORT1,button,1342242816
Control19=IDC_EXPORT2,button,1342242816

[CLS:CViewFenjiCableInfo]
Type=0
HeaderFile=ViewFenjiCableInfo.h
ImplementationFile=ViewFenjiCableInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EXPORT1

[CLS:CFenjiAlarmTable]
Type=0
HeaderFile=FenjiAlarmTable.h
ImplementationFile=FenjiAlarmTable.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CFenjiAlarmTable

[DB:CFenjiAlarmTable]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[Id], 4, 4
Column2=[type], -6, 1
Column3=[alarmtime], 11, 16
Column4=[refreshtime], 11, 16

[CLS:CViewFenjiAlarm]
Type=0
HeaderFile=ViewFenjiAlarm.h
ImplementationFile=ViewFenjiAlarm.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON2

[DLG:IDD_VIEWCABLEALARMINFO]
Type=1
Class=CViewCableAlarmInfo
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDC_LIST1,SysListView32,1350631429
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_COMBO1,combobox,1344339971
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT1,edit,1350631552
Control8=IDC_EDIT2,edit,1350631552
Control9=IDC_MYSTATIC,static,1342308352
Control10=IDC_EDIT3,edit,1350631552
Control11=IDC_BUTTON2,button,1342242816
Control12=IDC_BUTTON3,button,1342242816
Control13=IDC_COMBO2,combobox,1344339971
Control14=IDC_EXPORT3,button,1342242816

[CLS:CViewCableAlarmInfo]
Type=0
HeaderFile=ViewCableAlarmInfo.h
ImplementationFile=ViewCableAlarmInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EXPORT3

[CLS:CCableAlarmTable]
Type=0
HeaderFile=CableAlarmTable.h
ImplementationFile=CableAlarmTable.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CCableAlarmTable

[DB:CCableAlarmTable]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[Id], 4, 4
Column2=[cablenumber], 4, 4
Column3=[distant], 4, 4
Column4=[alarmtime], 11, 16
Column5=[recovertime], 11, 16

[DLG:IDD_ADDCABLECONFIG]
Type=1
Class=CAddCableConfig
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO1,combobox,1344339971
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO2,combobox,1344339971

[CLS:CAddCableConfig]
Type=0
HeaderFile=AddCableConfig.h
ImplementationFile=AddCableConfig.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAddCableConfig

[CLS:CCenterTelTable]
Type=0
HeaderFile=CenterTelTable.h
ImplementationFile=CenterTelTable.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CCenterTelTable

[DB:CCenterTelTable]
DB=1
DBType=ODBC
ColumnCount=2
Column1=[Id], 4, 4
Column2=[telephone], 12, 13

[DLG:IDD_SENDCBDLG]
Type=1
Class=CSendCBdlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FENJINUMBER,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_NEWFENJINUMBER,edit,1350631552

[CLS:CSendCBdlg]
Type=0
HeaderFile=SendCBdlg.h
ImplementationFile=SendCBdlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_CHECK1

[DLG:IDD_SETCENTERTELDLG]
Type=1
Class=CSetCenterTeldlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TEL,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CSetCenterTeldlg]
Type=0
HeaderFile=SetCenterTeldlg.h
ImplementationFile=SetCenterTeldlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSetCenterTeldlg

[CLS:CTempSet]
Type=0
HeaderFile=TempSet.h
ImplementationFile=TempSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CTempSet

[DB:CTempSet]
DB=1
DBType=ODBC
ColumnCount=2
Column1=[Id], 4, 4
Column2=[abc], 4, 4

[DLG:IDD_SENDDCDLG]
Type=1
Class=CSendDCDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_FENJINUMBER,edit,1350631552

[CLS:CSendDCDlg]
Type=0
HeaderFile=SendDCDlg.h
ImplementationFile=SendDCDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

