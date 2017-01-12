// CodeGear C++Builder
// Copyright (c) 1995-2010 Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Shellctrls.pas' rev: 21.00

#ifndef ShellctrlsHPP
#define ShellctrlsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <Sysinit.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Sysutils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Comctrls.hpp>	// Pascal unit
#include <Commctrl.hpp>	// Pascal unit
#include <Shlobj.hpp>	// Pascal unit
#include <Activex.hpp>	// Pascal unit
#include <Stdctrls.hpp>	// Pascal unit
#include <Imglist.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Shellctrls
{
//-- type declarations -------------------------------------------------------
typedef System::UnicodeString TRoot;

#pragma option push -b-
enum TRootFolder { rfDesktop, rfMyComputer, rfNetwork, rfRecycleBin, rfAppData, rfCommonDesktopDirectory, rfCommonPrograms, rfCommonStartMenu, rfCommonStartup, rfControlPanel, rfDesktopDirectory, rfFavorites, rfFonts, rfInternet, rfPersonal, rfPrinters, rfPrintHood, rfPrograms, rfRecent, rfSendTo, rfStartMenu, rfStartup, rfTemplates };
#pragma option pop

#pragma option push -b-
enum TShellFolderCapability { fcCanCopy, fcCanDelete, fcCanLink, fcCanMove, fcCanRename, fcDropTarget, fcHasPropSheet };
#pragma option pop

typedef Set<TShellFolderCapability, fcCanCopy, fcHasPropSheet>  TShellFolderCapabilities;

#pragma option push -b-
enum TShellFolderProperty { fpCut, fpIsLink, fpReadOnly, fpShared, fpFileSystem, fpFileSystemAncestor, fpRemovable, fpValidate };
#pragma option pop

typedef Set<TShellFolderProperty, fpCut, fpValidate>  TShellFolderProperties;

#pragma option push -b-
enum TShellObjectType { otFolders, otNonFolders, otHidden };
#pragma option pop

typedef Set<TShellObjectType, otFolders, otHidden>  TShellObjectTypes;

class DELPHICLASS EInvalidPath;
class PASCALIMPLEMENTATION EInvalidPath : public Sysutils::Exception
{
	typedef Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EInvalidPath(const System::UnicodeString Msg) : Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EInvalidPath(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidPath(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidPath(int Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EInvalidPath(const System::UnicodeString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidPath(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidPath(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidPath(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EInvalidPath(void) { }
	
};


__interface IShellCommandVerb;
typedef System::DelphiInterface<IShellCommandVerb> _di_IShellCommandVerb;
__interface  INTERFACE_UUID("{7D2A7245-2376-4D33-8008-A130935A2E8B}") IShellCommandVerb  : public System::IInterface 
{
	
public:
	virtual void __fastcall ExecuteCommand(System::UnicodeString Verb, bool &Handled) = 0 ;
	virtual void __fastcall CommandCompleted(System::UnicodeString Verb, bool Succeeded) = 0 ;
};

class DELPHICLASS TShellFolder;
class PASCALIMPLEMENTATION TShellFolder : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	_ITEMIDLIST *FPIDL;
	_ITEMIDLIST *FFullPIDL;
	TShellFolder* FParent;
	_di_IShellFolder FIShellFolder;
	_di_IShellFolder2 FIShellFolder2;
	_di_IShellDetails FIShellDetails;
	System::_di_IInterface FDetailInterface;
	int FLevel;
	unsigned FViewHandle;
	Classes::TStrings* FDetails;
	System::_di_IInterface __fastcall GetDetailInterface(void);
	_di_IShellDetails __fastcall GetShellDetails(void);
	_di_IShellFolder2 __fastcall GetShellFolder2(void);
	System::UnicodeString __fastcall GetDetails(int Index);
	void __fastcall SetDetails(int Index, const System::UnicodeString Value);
	void __fastcall LoadColumnDetails(TShellFolder* RootFolder, unsigned Handle, int ColumnCount);
	
public:
	__fastcall virtual TShellFolder(TShellFolder* AParent, Shlobj::PItemIDList ID, _di_IShellFolder SF);
	__fastcall virtual ~TShellFolder(void);
	TShellFolderCapabilities __fastcall Capabilities(void);
	System::UnicodeString __fastcall DisplayName(void);
	int __fastcall ExecuteDefault(void);
	int __fastcall ImageIndex(bool LargeIcon);
	bool __fastcall IsFolder(void);
	_di_IShellFolder __fastcall ParentShellFolder(void);
	System::UnicodeString __fastcall PathName(void);
	TShellFolderProperties __fastcall Properties(void);
	bool __fastcall Rename(const System::WideString NewName);
	bool __fastcall SubFolders(void);
	__property Shlobj::PItemIDList AbsoluteID = {read=FFullPIDL};
	__property System::UnicodeString Details[int Index] = {read=GetDetails, write=SetDetails};
	__property int Level = {read=FLevel, nodefault};
	__property TShellFolder* Parent = {read=FParent};
	__property Shlobj::PItemIDList RelativeID = {read=FPIDL};
	__property _di_IShellFolder ShellFolder = {read=FIShellFolder};
	__property _di_IShellFolder2 ShellFolder2 = {read=GetShellFolder2};
	__property _di_IShellDetails ShellDetails = {read=GetShellDetails};
	__property unsigned ViewHandle = {read=FViewHandle, write=FViewHandle, nodefault};
};


#pragma option push -b-
enum TNotifyFilter { nfFileNameChange, nfDirNameChange, nfAttributeChange, nfSizeChange, nfWriteChange, nfSecurityChange };
#pragma option pop

typedef Set<TNotifyFilter, nfFileNameChange, nfSecurityChange>  TNotifyFilters;

class DELPHICLASS TShellChangeThread;
class PASCALIMPLEMENTATION TShellChangeThread : public Classes::TThread
{
	typedef Classes::TThread inherited;
	
private:
	int FMutex;
	int FWaitHandle;
	Classes::TThreadMethod FChangeEvent;
	System::UnicodeString FDirectory;
	bool FWatchSubTree;
	bool FWaitChanged;
	unsigned FNotifyOptionFlags;
	
protected:
	virtual void __fastcall Execute(void);
	
public:
	__fastcall virtual TShellChangeThread(Classes::TThreadMethod ChangeEvent);
	__fastcall virtual ~TShellChangeThread(void);
	void __fastcall SetDirectoryOptions(System::UnicodeString Directory, bool WatchSubTree, unsigned NotifyOptionFlags);
	__property Classes::TThreadMethod ChangeEvent = {read=FChangeEvent, write=FChangeEvent};
};


class DELPHICLASS TCustomShellChangeNotifier;
class PASCALIMPLEMENTATION TCustomShellChangeNotifier : public Classes::TComponent
{
	typedef Classes::TComponent inherited;
	
private:
	TNotifyFilters FFilters;
	bool FWatchSubTree;
	TRoot FRoot;
	TShellChangeThread* FThread;
	Classes::TThreadMethod FOnChange;
	void __fastcall SetRoot(const TRoot Value);
	void __fastcall SetWatchSubTree(const bool Value);
	void __fastcall SetFilters(const TNotifyFilters Value);
	void __fastcall SetOnChange(const Classes::TThreadMethod Value);
	
protected:
	void __fastcall Change(void);
	void __fastcall Start(void);
	
public:
	__fastcall virtual TCustomShellChangeNotifier(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomShellChangeNotifier(void);
	__property TNotifyFilters NotifyFilters = {read=FFilters, write=SetFilters, nodefault};
	__property TRoot Root = {read=FRoot, write=SetRoot};
	__property bool WatchSubTree = {read=FWatchSubTree, write=SetWatchSubTree, nodefault};
	__property Classes::TThreadMethod OnChange = {read=FOnChange, write=SetOnChange};
};


class DELPHICLASS TShellChangeNotifier;
class PASCALIMPLEMENTATION TShellChangeNotifier : public TCustomShellChangeNotifier
{
	typedef TCustomShellChangeNotifier inherited;
	
__published:
	__property NotifyFilters;
	__property Root;
	__property WatchSubTree;
	__property OnChange;
public:
	/* TCustomShellChangeNotifier.Create */ inline __fastcall virtual TShellChangeNotifier(Classes::TComponent* AOwner) : TCustomShellChangeNotifier(AOwner) { }
	/* TCustomShellChangeNotifier.Destroy */ inline __fastcall virtual ~TShellChangeNotifier(void) { }
	
};


typedef void __fastcall (__closure *TAddFolderEvent)(System::TObject* Sender, TShellFolder* AFolder, bool &CanAdd);

typedef void __fastcall (__closure *TGetImageIndexEvent)(System::TObject* Sender, int Index, int &ImageIndex);

class DELPHICLASS TCustomShellTreeView;
class DELPHICLASS TCustomShellComboBox;
class DELPHICLASS TCustomShellListView;
class PASCALIMPLEMENTATION TCustomShellTreeView : public Comctrls::TCustomTreeView
{
	typedef Comctrls::TCustomTreeView inherited;
	
public:
	TShellFolder* operator[](int Index) { return Folders[Index]; }
	
private:
	TRoot FRoot;
	TRoot FOldRoot;
	TShellFolder* FRootFolder;
	TShellObjectTypes FObjectTypes;
	int FImages;
	bool FLoadingRoot;
	bool FAutoContext;
	bool FUpdating;
	TCustomShellComboBox* FComboBox;
	TCustomShellListView* FListView;
	bool FAutoRefresh;
	bool FImageListChanging;
	bool FUseShellImages;
	TShellChangeNotifier* FNotifier;
	TAddFolderEvent FOnAddFolder;
	System::UnicodeString FSavePath;
	Comctrls::TTreeNode* FNodeToMonitor;
	Comctrls::TTreeNode* __fastcall FolderExists(Shlobj::PItemIDList FindID, Comctrls::TTreeNode* InNode);
	TShellFolder* __fastcall GetFolder(int Index);
	System::UnicodeString __fastcall GetPath(void);
	void __fastcall SetComboBox(TCustomShellComboBox* Value);
	void __fastcall SetListView(const TCustomShellListView* Value);
	void __fastcall SetPath(const System::UnicodeString Value);
	void __fastcall SetPathFromID(Shlobj::PItemIDList ID);
	void __fastcall SetRoot(const TRoot Value);
	void __fastcall SetUseShellImages(const bool Value);
	void __fastcall SetAutoRefresh(const bool Value);
	
protected:
	DYNAMIC bool __fastcall CanChange(Comctrls::TTreeNode* Node);
	DYNAMIC bool __fastcall CanExpand(Comctrls::TTreeNode* Node);
	void __fastcall CreateRoot(void);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	DYNAMIC void __fastcall DoContextPopup(const Types::TPoint &MousePos, bool &Handled);
	DYNAMIC void __fastcall Edit(const tagTVITEMW &Item);
	virtual void __fastcall GetImageIndex(Comctrls::TTreeNode* Node);
	virtual void __fastcall GetSelectedIndex(Comctrls::TTreeNode* Node);
	void __fastcall InitNode(Comctrls::TTreeNode* NewNode, Shlobj::PItemIDList ID, Comctrls::TTreeNode* ParentNode);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall Delete(Comctrls::TTreeNode* Node);
	Comctrls::TTreeNode* __fastcall NodeFromAbsoluteID(Comctrls::TTreeNode* StartNode, Shlobj::PItemIDList ID);
	Comctrls::TTreeNode* __fastcall NodeFromRelativeID(Comctrls::TTreeNode* ParentNode, Shlobj::PItemIDList ID);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall PopulateNode(Comctrls::TTreeNode* Node);
	void __fastcall RootChanged(void);
	virtual void __fastcall SetObjectTypes(TShellObjectTypes Value);
	HIDESBASE virtual void __fastcall WMDestroy(Messages::TWMNoParams &Message);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	void __fastcall ClearItems(void);
	void __fastcall RefreshEvent(void);
	
public:
	__fastcall virtual TCustomShellTreeView(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomShellTreeView(void);
	HIDESBASE void __fastcall Refresh(Comctrls::TTreeNode* Node);
	TShellFolder* __fastcall SelectedFolder(void);
	__property bool AutoRefresh = {read=FAutoRefresh, write=SetAutoRefresh, nodefault};
	__property TShellFolder* Folders[int Index] = {read=GetFolder/*, default*/};
	__property Items;
	__property System::UnicodeString Path = {read=GetPath, write=SetPath};
	__property bool AutoContextMenus = {read=FAutoContext, write=FAutoContext, default=1};
	__property TShellObjectTypes ObjectTypes = {read=FObjectTypes, write=SetObjectTypes, nodefault};
	__property TRoot Root = {read=FRoot, write=SetRoot};
	__property TCustomShellComboBox* ShellComboBox = {read=FComboBox, write=SetComboBox};
	__property TCustomShellListView* ShellListView = {read=FListView, write=SetListView};
	__property bool UseShellImages = {read=FUseShellImages, write=SetUseShellImages, nodefault};
	__property TAddFolderEvent OnAddFolder = {read=FOnAddFolder, write=FOnAddFolder};
	void __fastcall CommandCompleted(System::UnicodeString Verb, bool Succeeded);
	void __fastcall ExecuteCommand(System::UnicodeString Verb, bool &Handled);
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomShellTreeView(HWND ParentWindow) : Comctrls::TCustomTreeView(ParentWindow) { }
	
private:
	void *__IShellCommandVerb;	/* IShellCommandVerb */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	operator _di_IShellCommandVerb()
	{
		_di_IShellCommandVerb intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IShellCommandVerb*(void) { return (IShellCommandVerb*)&__IShellCommandVerb; }
	#endif
	
};


class DELPHICLASS TShellTreeView;
class PASCALIMPLEMENTATION TShellTreeView : public TCustomShellTreeView
{
	typedef TCustomShellTreeView inherited;
	
__published:
	__property AutoContextMenus = {default=1};
	__property ObjectTypes;
	__property Root;
	__property ShellComboBox;
	__property ShellListView;
	__property UseShellImages;
	__property OnAddFolder;
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoRefresh;
	__property BorderStyle = {default=1};
	__property ChangeDelay = {default=0};
	__property Color = {default=-16777211};
	__property Ctl3D;
	__property Cursor = {default=0};
	__property DragCursor = {default=-12};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property HideSelection = {default=1};
	__property Images;
	__property Indent;
	__property ParentColor = {default=1};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property RightClickSelect = {default=0};
	__property ShowButtons = {default=1};
	__property ShowHint;
	__property ShowLines = {default=1};
	__property ShowRoot = {default=1};
	__property StateImages;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnEnter;
	__property OnExit;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnStartDrag;
	__property OnEndDrag;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnDblClick;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnChanging;
	__property OnChange;
	__property OnExpanding;
	__property OnCollapsing;
	__property OnCollapsed;
	__property OnExpanded;
	__property OnEditing;
	__property OnEdited;
	__property OnGetImageIndex;
	__property OnGetSelectedIndex;
public:
	/* TCustomShellTreeView.Create */ inline __fastcall virtual TShellTreeView(Classes::TComponent* AOwner) : TCustomShellTreeView(AOwner) { }
	/* TCustomShellTreeView.Destroy */ inline __fastcall virtual ~TShellTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TShellTreeView(HWND ParentWindow) : TCustomShellTreeView(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TCustomShellComboBox : public Comctrls::TCustomComboBoxEx
{
	typedef Comctrls::TCustomComboBoxEx inherited;
	
private:
	int FImages;
	int FImageHeight;
	int FImageWidth;
	Imglist::TCustomImageList* FImageList;
	TRoot FOldRoot;
	TRoot FRoot;
	TShellFolder* FRootFolder;
	TCustomShellTreeView* FTreeView;
	TCustomShellListView* FListView;
	TShellObjectTypes FObjectTypes;
	bool FUseShellImages;
	bool FUpdating;
	TGetImageIndexEvent FOnGetImageIndex;
	void __fastcall ClearItems(void);
	TShellFolder* __fastcall GetFolder(int Index);
	System::UnicodeString __fastcall GetPath(void);
	void __fastcall SetPath(const System::UnicodeString Value);
	void __fastcall SetPathFromID(Shlobj::PItemIDList ID);
	void __fastcall SetRoot(const TRoot Value);
	void __fastcall SetTreeView(TCustomShellTreeView* Value);
	void __fastcall SetListView(TCustomShellListView* Value);
	void __fastcall SetUseShellImages(const bool Value);
	int __fastcall GetShellImageIndex(TShellFolder* AFolder);
	
protected:
	void __fastcall AddItems(int Index, TShellFolder* ParentFolder);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall Click(void);
	void __fastcall CreateRoot(void);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	int __fastcall IndexFromID(Shlobj::PItemIDList AbsoluteID);
	virtual void __fastcall Init(void);
	TShellFolder* __fastcall InitItem(TShellFolder* ParentFolder, Shlobj::PItemIDList ID);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall RootChanged(void);
	void __fastcall TreeUpdate(Shlobj::PItemIDList NewPath);
	virtual void __fastcall SetObjectTypes(TShellObjectTypes Value);
	
public:
	__fastcall virtual TCustomShellComboBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomShellComboBox(void);
	__property Items;
	__property System::UnicodeString Path = {read=GetPath, write=SetPath};
	__property TShellFolder* Folders[int Index] = {read=GetFolder};
	__property TRoot Root = {read=FRoot, write=SetRoot};
	__property TShellObjectTypes ObjectTypes = {read=FObjectTypes, write=SetObjectTypes, nodefault};
	__property TCustomShellTreeView* ShellTreeView = {read=FTreeView, write=SetTreeView};
	__property TCustomShellListView* ShellListView = {read=FListView, write=SetListView};
	__property bool UseShellImages = {read=FUseShellImages, write=SetUseShellImages, nodefault};
	__property TGetImageIndexEvent OnGetImageIndex = {read=FOnGetImageIndex, write=FOnGetImageIndex};
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomShellComboBox(HWND ParentWindow) : Comctrls::TCustomComboBoxEx(ParentWindow) { }
	
};


class DELPHICLASS TShellComboBox;
class PASCALIMPLEMENTATION TShellComboBox : public TCustomShellComboBox
{
	typedef TCustomShellComboBox inherited;
	
__published:
	__property Images;
	__property Root;
	__property ShellTreeView;
	__property ShellListView;
	__property UseShellImages;
	__property OnGetImageIndex;
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Color = {default=-16777211};
	__property Constraints;
	__property Ctl3D;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property DropDownCount = {default=8};
	__property Enabled = {default=1};
	__property Font;
	__property ImeMode = {default=3};
	__property ImeName;
	__property MaxLength = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnChange;
	__property OnClick;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDropDown;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TCustomShellComboBox.Create */ inline __fastcall virtual TShellComboBox(Classes::TComponent* AOwner) : TCustomShellComboBox(AOwner) { }
	/* TCustomShellComboBox.Destroy */ inline __fastcall virtual ~TShellComboBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TShellComboBox(HWND ParentWindow) : TCustomShellComboBox(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TCustomShellListView : public Comctrls::TCustomListView
{
	typedef Comctrls::TCustomListView inherited;
	
private:
	TRoot FOldRoot;
	TRoot FRoot;
	TShellFolder* FRootFolder;
	bool FAutoContext;
	bool FAutoRefresh;
	bool FAutoNavigate;
	bool FSorted;
	bool FUpdating;
	TShellObjectTypes FObjectTypes;
	int FLargeImages;
	int FSmallImages;
	TAddFolderEvent FOnAddFolder;
	Classes::TList* FFolders;
	TCustomShellTreeView* FTreeView;
	TCustomShellComboBox* FComboBox;
	TShellChangeNotifier* FNotifier;
	Comctrls::TLVEditingEvent FOnEditing;
	bool FSettingRoot;
	System::UnicodeString FSavePath;
	void __fastcall EnumColumns(void);
	TShellFolder* __fastcall GetFolder(int Index);
	void __fastcall SetAutoRefresh(const bool Value);
	void __fastcall SetSorted(const bool Value);
	void __fastcall SetTreeView(TCustomShellTreeView* Value);
	void __fastcall SetComboBox(TCustomShellComboBox* Value);
	void __fastcall TreeUpdate(Shlobj::PItemIDList NewRoot);
	void __fastcall SetPathFromID(Shlobj::PItemIDList ID);
	void __fastcall SynchPaths(void);
	
protected:
	void __fastcall ClearItems(void);
	void __fastcall CreateRoot(void);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall DoContextPopup(const Types::TPoint &MousePos, bool &Handled);
	void __fastcall EditText(void);
	DYNAMIC void __fastcall Edit(const tagLVITEMW &Item);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual bool __fastcall OwnerDataFetch(Comctrls::TListItem* Item, Comctrls::TItemRequest Request);
	virtual int __fastcall OwnerDataFind(Comctrls::TItemFind Find, const System::UnicodeString FindString, const Types::TPoint &FindPosition, void * FindData, int StartIndex, Comctrls::TSearchDirection Direction, bool Wrap);
	virtual void __fastcall Populate(void);
	void __fastcall RootChanged(void);
	void __fastcall SetObjectTypes(TShellObjectTypes Value);
	void __fastcall SetRoot(const TRoot Value);
	virtual void __fastcall SetViewStyle(Comctrls::TViewStyle Value);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	
public:
	__fastcall virtual TCustomShellListView(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomShellListView(void);
	void __fastcall Back(void);
	HIDESBASE void __fastcall Refresh(void);
	TShellFolder* __fastcall SelectedFolder(void);
	__property TShellFolder* Folders[int Index] = {read=GetFolder};
	__property TShellFolder* RootFolder = {read=FRootFolder};
	__property Items;
	__property Columns;
	__property bool AutoContextMenus = {read=FAutoContext, write=FAutoContext, default=1};
	__property bool AutoRefresh = {read=FAutoRefresh, write=SetAutoRefresh, default=0};
	__property bool AutoNavigate = {read=FAutoNavigate, write=FAutoNavigate, default=1};
	__property TShellObjectTypes ObjectTypes = {read=FObjectTypes, write=SetObjectTypes, nodefault};
	__property TRoot Root = {read=FRoot, write=SetRoot};
	__property TCustomShellTreeView* ShellTreeView = {read=FTreeView, write=SetTreeView};
	__property TCustomShellComboBox* ShellComboBox = {read=FComboBox, write=SetComboBox};
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
	__property TAddFolderEvent OnAddFolder = {read=FOnAddFolder, write=FOnAddFolder};
	__property Comctrls::TLVEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	void __fastcall CommandCompleted(System::UnicodeString Verb, bool Succeeded);
	void __fastcall ExecuteCommand(System::UnicodeString Verb, bool &Handled);
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomShellListView(HWND ParentWindow) : Comctrls::TCustomListView(ParentWindow) { }
	
private:
	void *__IShellCommandVerb;	/* IShellCommandVerb */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	operator _di_IShellCommandVerb()
	{
		_di_IShellCommandVerb intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IShellCommandVerb*(void) { return (IShellCommandVerb*)&__IShellCommandVerb; }
	#endif
	
};


class DELPHICLASS TShellListView;
class PASCALIMPLEMENTATION TShellListView : public TCustomShellListView
{
	typedef TCustomShellListView inherited;
	
__published:
	__property AutoContextMenus = {default=1};
	__property AutoRefresh = {default=0};
	__property AutoNavigate = {default=1};
	__property ObjectTypes;
	__property Root;
	__property ShellTreeView;
	__property ShellComboBox;
	__property Sorted;
	__property OnAddFolder;
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BorderStyle = {default=1};
	__property Color = {default=-16777211};
	__property ColumnClick = {default=1};
	__property OnClick;
	__property OnDblClick;
	__property Ctl3D;
	__property DragMode = {default=0};
	__property ReadOnly = {default=1};
	__property Enabled = {default=1};
	__property Font;
	__property GridLines = {default=0};
	__property HideSelection = {default=1};
	__property HotTrack = {default=0};
	__property IconOptions;
	__property AllocBy = {default=0};
	__property MultiSelect = {default=0};
	__property RowSelect = {default=0};
	__property OnChange;
	__property OnChanging;
	__property OnColumnClick;
	__property OnContextPopup;
	__property OnEnter;
	__property OnExit;
	__property OnInsert;
	__property OnDragDrop;
	__property OnDragOver;
	__property DragCursor = {default=-12};
	__property OnStartDrag;
	__property OnEndDrag;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property ShowHint;
	__property PopupMenu;
	__property ShowColumnHeaders = {default=1};
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property ViewStyle = {default=0};
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnEditing;
public:
	/* TCustomShellListView.Create */ inline __fastcall virtual TShellListView(Classes::TComponent* AOwner) : TCustomShellListView(AOwner) { }
	/* TCustomShellListView.Destroy */ inline __fastcall virtual ~TShellListView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TShellListView(HWND ParentWindow) : TCustomShellListView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall InvokeContextMenu(Controls::TWinControl* Owner, TShellFolder* AFolder, int X, int Y);

}	/* namespace Shellctrls */
using namespace Shellctrls;
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ShellctrlsHPP
