#pragma once
#include "frame.hpp"
#include <wx/wx.h>

class builderApp : public wxApp {
  BFrame* frame;
public:
  virtual bool OnInit() override;
};
