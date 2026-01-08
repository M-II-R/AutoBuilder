#include "ui-interface.hpp"
#include "frame.hpp"
void sendNotificNoVars (const std::unordered_set<std::string>& list) {
  BFrame::SendNotificationNoVars (list);
}
void sendNotificIncPath () {
  BFrame::SendNotificationIncPath();
}
