///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "frameBase.hpp"

///////////////////////////////////////////////////////////////////////////

BuilderFrame::BuilderFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );

	m_splitter2 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( BuilderFrame::m_splitter2OnIdle ), NULL, this );

	m_panel1 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* leftPanelSizer;
	leftPanelSizer = new wxBoxSizer( wxVERTICAL );

	TitleText = new wxStaticText( m_panel1, wxID_ANY, _("AutoBuilder"), wxDefaultPosition, wxDefaultSize, 0 );
	TitleText->Wrap( -1 );
	TitleText->SetFont( wxFont( 20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Sans") ) );

	leftPanelSizer->Add( TitleText, 0, wxALIGN_CENTER|wxALL, 5 );

	wxBoxSizer* CordovaSizer;
	CordovaSizer = new wxBoxSizer( wxHORIZONTAL );

	CordovaText = new wxStaticText( m_panel1, wxID_ANY, _("Cordova folder:"), wxDefaultPosition, wxDefaultSize, 0 );
	CordovaText->Wrap( -1 );
	CordovaSizer->Add( CordovaText, 0, wxALIGN_CENTER|wxALL, 5 );

	CordovaPicker = new wxDirPickerCtrl( m_panel1, wxID_ANY, wxT("/"), _("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL );
	CordovaSizer->Add( CordovaPicker, 1, wxALIGN_CENTER|wxALL, 5 );


	leftPanelSizer->Add( CordovaSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* JavaSizer;
	JavaSizer = new wxBoxSizer( wxHORIZONTAL );

	JavaText = new wxStaticText( m_panel1, wxID_ANY, _("Java HOME:"), wxDefaultPosition, wxDefaultSize, 0 );
	JavaText->Wrap( -1 );
	JavaSizer->Add( JavaText, 0, wxALIGN_CENTER|wxALL, 5 );

	JavaPicker = new wxDirPickerCtrl( m_panel1, wxID_ANY, wxT("/"), _("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL );
	JavaSizer->Add( JavaPicker, 1, wxALIGN_CENTER|wxALL, 5 );


	leftPanelSizer->Add( JavaSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* AndroidSizer;
	AndroidSizer = new wxBoxSizer( wxHORIZONTAL );

	AndroidText = new wxStaticText( m_panel1, wxID_ANY, _("Android HOME:"), wxDefaultPosition, wxDefaultSize, 0 );
	AndroidText->Wrap( -1 );
	AndroidSizer->Add( AndroidText, 0, wxALIGN_CENTER|wxALL, 5 );

	AndroidPicker = new wxDirPickerCtrl( m_panel1, wxID_ANY, wxT("/"), _("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL );
	AndroidSizer->Add( AndroidPicker, 1, wxALIGN_CENTER|wxALL, 5 );


	leftPanelSizer->Add( AndroidSizer, 1, wxEXPAND, 5 );


	m_panel1->SetSizer( leftPanelSizer );
	m_panel1->Layout();
	leftPanelSizer->Fit( m_panel1 );
	m_panel2 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* rightPanelSizer;
	rightPanelSizer = new wxBoxSizer( wxVERTICAL );

	rightNotebook = new wxNotebook( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	BuildPanel = new wxPanel( rightNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* BuildSizer;
	BuildSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* ProjectSizer;
	ProjectSizer = new wxBoxSizer( wxHORIZONTAL );

	ProjectPathText = new wxStaticText( BuildPanel, wxID_ANY, _("Project folder:"), wxDefaultPosition, wxDefaultSize, 0 );
	ProjectPathText->Wrap( -1 );
	ProjectSizer->Add( ProjectPathText, 0, wxALIGN_CENTER|wxALL, 5 );

	ProjectPicker = new wxDirPickerCtrl( BuildPanel, wxID_ANY, wxT("/"), _("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_DIR_MUST_EXIST|wxDIRP_USE_TEXTCTRL );
	ProjectSizer->Add( ProjectPicker, 1, wxALIGN_CENTER|wxALL, 5 );


	BuildSizer->Add( ProjectSizer, 1, wxEXPAND, 5 );

	PlatformsText = new wxStaticText( BuildPanel, wxID_ANY, _("Platforms:"), wxDefaultPosition, wxDefaultSize, 0 );
	PlatformsText->Wrap( -1 );
	BuildSizer->Add( PlatformsText, 0, wxALL, 5 );

	wxString PlatformsBoxChoices[] = { _("Android") };
	int PlatformsBoxNChoices = sizeof( PlatformsBoxChoices ) / sizeof( wxString );
	PlatformsBox = new wxCheckListBox( BuildPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, PlatformsBoxNChoices, PlatformsBoxChoices, wxLB_MULTIPLE );
	BuildSizer->Add( PlatformsBox, 0, wxALL|wxEXPAND, 5 );

	IOSText = new wxStaticText( BuildPanel, wxID_ANY, _("IOS is unavailable now."), wxDefaultPosition, wxDefaultSize, 0 );
	IOSText->Wrap( -1 );
	BuildSizer->Add( IOSText, 0, wxALL, 5 );

	wxBoxSizer* KeystoreSizer;
	KeystoreSizer = new wxBoxSizer( wxHORIZONTAL );

	KeystoreText = new wxStaticText( BuildPanel, wxID_ANY, _("Keystore for Android release:"), wxDefaultPosition, wxDefaultSize, 0 );
	KeystoreText->Wrap( -1 );
	KeystoreSizer->Add( KeystoreText, 0, wxALIGN_CENTER|wxALL, 5 );

	KeystorePicker = new wxFilePickerCtrl( BuildPanel, wxID_ANY, wxEmptyString, _("Select a file"), _("Keystore files (*.jks;*.keystore)|*.jks;*.keystore|Other files (*)|*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_USE_TEXTCTRL );
	KeystoreSizer->Add( KeystorePicker, 1, wxALIGN_CENTER|wxALL, 5 );


	BuildSizer->Add( KeystoreSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* KeystorePasswordSizer;
	KeystorePasswordSizer = new wxBoxSizer( wxHORIZONTAL );

	KeystorePaswordText = new wxStaticText( BuildPanel, wxID_ANY, _("Keystore password:"), wxDefaultPosition, wxDefaultSize, 0 );
	KeystorePaswordText->Wrap( -1 );
	KeystorePasswordSizer->Add( KeystorePaswordText, 0, wxALIGN_CENTER|wxALL, 5 );

	KeystorePasswordInput = new wxTextCtrl( BuildPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	KeystorePasswordSizer->Add( KeystorePasswordInput, 1, wxALIGN_CENTER|wxALL, 5 );


	BuildSizer->Add( KeystorePasswordSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* KeystoreAliasSizer;
	KeystoreAliasSizer = new wxBoxSizer( wxHORIZONTAL );

	KeystoreAliasText = new wxStaticText( BuildPanel, wxID_ANY, _("Keystore alias:"), wxDefaultPosition, wxDefaultSize, 0 );
	KeystoreAliasText->Wrap( -1 );
	KeystoreAliasSizer->Add( KeystoreAliasText, 0, wxALIGN_CENTER|wxALL, 5 );

	KeystoreAliasInput = new wxTextCtrl( BuildPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	KeystoreAliasSizer->Add( KeystoreAliasInput, 1, wxALIGN_CENTER|wxALL, 5 );


	BuildSizer->Add( KeystoreAliasSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* AndroidTypeSizer;
	AndroidTypeSizer = new wxBoxSizer( wxHORIZONTAL );

	AndroidTypeText = new wxStaticText( BuildPanel, wxID_ANY, _("Build release APK instead of AAB: "), wxDefaultPosition, wxDefaultSize, 0 );
	AndroidTypeText->Wrap( -1 );
	AndroidTypeSizer->Add( AndroidTypeText, 0, wxALIGN_CENTER|wxALL, 5 );

	AndroidTypeToggle = new wxToggleButton( BuildPanel, wxID_ANY, _("Yes"), wxDefaultPosition, wxDefaultSize, 0 );
	AndroidTypeToggle->SetValue( true );
	AndroidTypeSizer->Add( AndroidTypeToggle, 0, wxALIGN_CENTER|wxALL, 5 );


	BuildSizer->Add( AndroidTypeSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* BuildSizer2;
	BuildSizer2 = new wxBoxSizer( wxHORIZONTAL );


	BuildSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	BuildButton = new wxButton( BuildPanel, wxID_ANY, _("Build Debug"), wxDefaultPosition, wxDefaultSize, 0 );
	BuildSizer2->Add( BuildButton, 0, wxALIGN_CENTER|wxALL, 5 );

	BuildButtonRelease = new wxButton( BuildPanel, wxID_ANY, _("Build Release"), wxDefaultPosition, wxDefaultSize, 0 );
	BuildSizer2->Add( BuildButtonRelease, 0, wxALIGN_CENTER|wxALL, 5 );


	BuildSizer2->Add( 0, 0, 1, wxEXPAND, 5 );


	BuildSizer->Add( BuildSizer2, 1, wxEXPAND, 5 );


	BuildPanel->SetSizer( BuildSizer );
	BuildPanel->Layout();
	BuildSizer->Fit( BuildPanel );
	rightNotebook->AddPage( BuildPanel, _("Build"), true );
	TerminalPanel = new wxPanel( rightNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* TerminalSizer;
	TerminalSizer = new wxBoxSizer( wxVERTICAL );

	TerminalText = new wxStaticText( TerminalPanel, wxID_ANY, _("There is nothing here."), wxDefaultPosition, wxDefaultSize, 0 );
	TerminalText->Wrap( -1 );
	TerminalSizer->Add( TerminalText, 0, wxALL, 5 );


	TerminalPanel->SetSizer( TerminalSizer );
	TerminalPanel->Layout();
	TerminalSizer->Fit( TerminalPanel );
	rightNotebook->AddPage( TerminalPanel, _("Terminal"), false );

	rightPanelSizer->Add( rightNotebook, 1, wxEXPAND, 5 );


	m_panel2->SetSizer( rightPanelSizer );
	m_panel2->Layout();
	rightPanelSizer->Fit( m_panel2 );
	m_splitter2->SplitVertically( m_panel1, m_panel2, 235 );
	MainSizer->Add( m_splitter2, 1, wxEXPAND, 5 );


	this->SetSizer( MainSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	CordovaPicker->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( BuilderFrame::CordovaPickerOnDirChanged ), NULL, this );
	JavaPicker->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( BuilderFrame::JavaPickerOnDirChanged ), NULL, this );
	AndroidPicker->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( BuilderFrame::AndroidPickerOnDirChanged ), NULL, this );
	ProjectPicker->Connect( wxEVT_COMMAND_DIRPICKER_CHANGED, wxFileDirPickerEventHandler( BuilderFrame::ProjectPickerOnDirChanged ), NULL, this );
	PlatformsBox->Connect( wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, wxCommandEventHandler( BuilderFrame::PlatformsBoxOnCheckListBoxToggled ), NULL, this );
	KeystorePicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( BuilderFrame::KeystorePickerOnFileChanged ), NULL, this );
	KeystorePasswordInput->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BuilderFrame::KeystorePasswordInputOnText ), NULL, this );
	KeystoreAliasInput->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BuilderFrame::KeystoreAliasInputOnText ), NULL, this );
	AndroidTypeToggle->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( BuilderFrame::AndroidTypeToggleOnToggleButton ), NULL, this );
	BuildButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BuilderFrame::BuildButtonOnButtonClick ), NULL, this );
	BuildButtonRelease->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BuilderFrame::BuildButtonReleaseOnButtonClick ), NULL, this );
}

BuilderFrame::~BuilderFrame()
{
}
