///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/filepicker.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/checklst.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/notebook.h>
#include <wx/splitter.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class BuilderFrame
///////////////////////////////////////////////////////////////////////////////
class BuilderFrame : public wxFrame
{
	private:

	protected:
		wxSplitterWindow* m_splitter2;
		wxPanel* m_panel1;
		wxStaticText* TitleText;
		wxStaticText* CordovaText;
		wxDirPickerCtrl* CordovaPicker;
		wxStaticText* JavaText;
		wxDirPickerCtrl* JavaPicker;
		wxStaticText* AndroidText;
		wxDirPickerCtrl* AndroidPicker;
		wxPanel* m_panel2;
		wxNotebook* rightNotebook;
		wxPanel* BuildPanel;
		wxStaticText* ProjectPathText;
		wxDirPickerCtrl* ProjectPicker;
		wxStaticText* PlatformsText;
		wxCheckListBox* PlatformsBox;
		wxStaticText* IOSText;
		wxStaticText* KeystoreText;
		wxFilePickerCtrl* KeystorePicker;
		wxStaticText* KeystorePaswordText;
		wxTextCtrl* KeystorePasswordInput;
		wxStaticText* KeystoreAliasText;
		wxTextCtrl* KeystoreAliasInput;
		wxStaticText* AndroidTypeText;
		wxToggleButton* AndroidTypeToggle;
		wxButton* BuildButton;
		wxButton* BuildButtonRelease;
		wxPanel* TerminalPanel;
		wxStaticText* TerminalText;

		// Virtual event handlers, override them in your derived class
		virtual void CordovaPickerOnDirChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void JavaPickerOnDirChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void AndroidPickerOnDirChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void ProjectPickerOnDirChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void PlatformsBoxOnCheckListBoxToggled( wxCommandEvent& event ) { event.Skip(); }
		virtual void KeystorePickerOnFileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void KeystorePasswordInputOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void KeystoreAliasInputOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void AndroidTypeToggleOnToggleButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void BuildButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void BuildButtonReleaseOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		BuilderFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 920,521 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BuilderFrame();

		void m_splitter2OnIdle( wxIdleEvent& )
		{
			m_splitter2->SetSashPosition( 235 );
			m_splitter2->Disconnect( wxEVT_IDLE, wxIdleEventHandler( BuilderFrame::m_splitter2OnIdle ), NULL, this );
		}

};


