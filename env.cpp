#include "env.hpp"
#include <iostream>
#include <stdlib.h>
std::string getEnv (const std::string& name) {
  const char* env = std::getenv(name.c_str());
  if (!env) return std::string();
  return std::string(env);
//  return std::getenv(name.c_str());
}
void setEnv (const std::string& name, const std::string& val) {
  #ifdef _WIN32
  _putenv_s(name.c_str(), val.c_str());
  #else
  setenv(name.c_str(), val.c_str(), 1);
  #endif
}
