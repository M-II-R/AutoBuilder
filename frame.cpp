#include "frame.hpp"
#include "loc.hpp"
#include "main.hpp"
#include <wx/msgdlg.h>
#include <wx/string.h>
BFrame::BFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : BuilderFrame(parent, id, title, pos, size, style) {
  JavaPicker->SetPath(JAVA_HOME);
  AndroidPicker->SetPath(ANDROID_HOME);
}

void BFrame::CordovaPickerOnDirChanged (wxFileDirPickerEvent& event) {
  CORDOVA = event.GetPath();
}
void BFrame::JavaPickerOnDirChanged (wxFileDirPickerEvent& event) {
  JAVA_HOME = event.GetPath();
}
void BFrame::AndroidPickerOnDirChanged (wxFileDirPickerEvent& event) {
  ANDROID_HOME = event.GetPath();
}
void BFrame::ProjectPickerOnDirChanged (wxFileDirPickerEvent& event) {
  PROJECT_PATH = event.GetPath();
}
void BFrame::BuildButtonOnButtonClick( wxCommandEvent& event ) {
  Build(false);
}
void BFrame::BuildButtonReleaseOnButtonClick( wxCommandEvent& event ) {
  Build(true);
}
void BFrame::KeystorePickerOnFileChanged( wxFileDirPickerEvent& event ) {
  KEYSTORE_PATH=event.GetPath();
}
void BFrame::KeystorePasswordInputOnText( wxCommandEvent& event ) {
  KEYSTORE_PASSWORD = event.GetString().ToStdString();
}
void BFrame::KeystoreAliasInputOnText( wxCommandEvent& event ) {
  KEYSTORE_ALIAS = event.GetString().ToStdString();
}
void BFrame::AndroidTypeToggleOnToggleButton( wxCommandEvent& event ) {
  ANDROID_BUILD_APK = event.IsChecked();
}
void BFrame::PlatformsBoxOnCheckListBoxToggled( wxCommandEvent& event ) {
  event.Skip();
  platforms.clear();
  if(PlatformsBox->IsChecked(0)) { // Android
    platforms.insert(ANDROID);
  }
}
void BFrame::SendNotificationNoVars (const std::unordered_set<std::string>& list) {
  std::string ndtext = localize(u8"NO_DATA_TEXT");
  for (const auto& i : list) {
    ndtext += i;
    ndtext += std::string(u8", ");
  }
  if (ndtext.substr(ndtext.size() - 2, 2) == std::string(u8", ")) {
    ndtext.erase(ndtext.size() - 2, 2);
  }
//  wxNotificationMessage notification(localize(u8"NO_DATA"), ndtext);
  wxMessageBox(wxString(ndtext.c_str(), wxConvUTF8), wxString(localize(u8"NO_DATA").c_str(), wxConvUTF8), wxICON_ERROR);
/*  wxNotificationMessage* notification = new wxNotificationMessage("No data", ndtext);
  notification->SetFlags(wxICON_INFORMATION);
  notification->Show(); 
  notification->Close();
  delete notification;*/
}
void BFrame::SendNotificationIncPath () {
  wxMessageBox(wxString(localize(u8"INC_PATH").c_str(), wxConvUTF8), wxString(localize(u8"INCORRECT_PATH").c_str(), wxConvUTF8), wxICON_ERROR);
  /*wxNotificationMessage* notification = new wxNotificationMessage(localize(u8"INCORRECT_PATH"), localize(u8"INC_PATH"));
  notification->SetFlags(wxICON_INFORMATION);
  notification->Show();
  notification->Close();
  delete notification;*/
}
/*
BFrame::~BFrame() {
  msg->Close();
  msgIncPath->Close();
}*/
