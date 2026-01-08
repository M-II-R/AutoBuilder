#include "command.hpp"
#include <iostream>
void runCommand (const std::string& comm) {
  std::cout << "Command: " << comm << "\n";
  system(comm.c_str());
}
