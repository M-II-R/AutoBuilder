#include <string>
#include <unordered_set>
#pragma once
// Global variables.
enum PLATFORMS {
  ANDROID,
  IOS
};
extern std::string JAVA_HOME;
extern std::string ANDROID_HOME;
extern std::string CORDOVA;
extern std::string PROJECT_PATH;
extern std::string KEYSTORE_PATH;
extern std::string KEYSTORE_PASSWORD;
extern std::string KEYSTORE_ALIAS;
extern std::unordered_set<PLATFORMS> platforms;
extern bool ANDROID_BUILD_APK;
