//#include "ui.hpp"
#include "frame.hpp"
#include "main.hpp"
#include <wx/wx.h>

class builderApp : public wxApp {
  BFrame* frame;
public:
  virtual bool OnInit() override {
    OnStart();
    frame = new BFrame(nullptr, wxID_ANY, u8"AutoBuilder");
    return frame->Show();
  }
};

wxIMPLEMENT_APP(builderApp);
