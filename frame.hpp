#pragma once
#include "frameBase.hpp"
#include "global.hpp"
#include <unordered_set>
class BFrame : public BuilderFrame {
//wxNotificationMessage* msg;
//wxNotificationMessage* msgIncPath;
public:
		virtual void CordovaPickerOnDirChanged( wxFileDirPickerEvent& event ) override;
		virtual void JavaPickerOnDirChanged( wxFileDirPickerEvent& event ) override;
		virtual void AndroidPickerOnDirChanged( wxFileDirPickerEvent& event ) override;
		virtual void ProjectPickerOnDirChanged( wxFileDirPickerEvent& event ) override;
		virtual void PlatformsBoxOnCheckListBoxToggled( wxCommandEvent& event ) override;
		virtual void BuildButtonOnButtonClick( wxCommandEvent& event ) override;
		virtual void BuildButtonReleaseOnButtonClick( wxCommandEvent& event ) override;
		virtual void KeystorePickerOnFileChanged( wxFileDirPickerEvent& event ) override;
		virtual void KeystorePasswordInputOnText( wxCommandEvent& event ) override;
		virtual void KeystoreAliasInputOnText( wxCommandEvent& event ) override;
		virtual void AndroidTypeToggleOnToggleButton( wxCommandEvent& event ) override;


		BFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 850,423 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
  		static void SendNotificationNoVars (const std::unordered_set<std::string>& list);
  		static void SendNotificationIncPath ();
//		virtual ~BFrame();
};
