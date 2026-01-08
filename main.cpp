#include <string>
#include <iostream>
#include <unordered_set>
#include <filesystem>
#include "main.hpp"
#include "env.hpp"
#include "loc.hpp"
#include "command.hpp"

void OnStart () {
  JAVA_HOME = getEnv("JAVA_HOME");
  ANDROID_HOME = getEnv("ANDROID_HOME");
  InitLoc();
}

void Build(bool release) {
  std::unordered_set<std::string> noVars;
  if (JAVA_HOME.size() == 0) {
    noVars.insert(localize(u8"JAVA_HOME"));
  }
  if (ANDROID_HOME.size() == 0) {
    noVars.insert(localize(u8"ANDROID_HOME"));
  }
  if (CORDOVA.size() == 0) {
    noVars.insert(localize(u8"CORDOVA"));
  }
  if (PROJECT_PATH.size() == 0) {
    noVars.insert(localize(u8"PROJECT_PATH"));
  }
  if (platforms.size() == 0) {
    noVars.insert(localize(u8"PLATFORMS"));
  }
  if (release) {
    if (KEYSTORE_PATH.size() == 0) {
      noVars.insert(localize(u8"KSPATH"));
    }
    if (KEYSTORE_PASSWORD.size() == 0) {
      noVars.insert(localize(u8"KSPASSWORD"));
    }
    if (KEYSTORE_ALIAS.size() == 0) {
      noVars.insert(localize(u8"KSALIAS"));
    }
  }
  if (noVars.size() == 0) {
      std::filesystem::path pth(PROJECT_PATH);
      if (getEnv("JAVA_HOME") != JAVA_HOME) {
      	setEnv("JAVA_HOME", JAVA_HOME);
      }
      std::string PATH_ENV_VAR = getEnv("PATH");
      if(PATH_ENV_VAR.find(JAVA_HOME) == PATH_ENV_VAR.npos) {
	setEnv("PATH", PATH_ENV_VAR + std::string(":") + JAVA_HOME + std::string("/bin"));
      }
      PATH_ENV_VAR.clear();
      if (getEnv("ANDROID_HOME") != ANDROID_HOME) {
	setEnv("ANDROID_HOME", ANDROID_HOME);
      }
      setEnv("ANDROID_SDK_ROOT", ANDROID_HOME);
      if (std::filesystem::exists(pth)) {
        std::filesystem::current_path(pth);
        for (PLATFORMS i : platforms) {
          runCommand(std::string(u8"cordova platform add ") + std::string(i == ANDROID ? u8"android" : u8"ios").c_str());
          runCommand(u8"cordova prepare");
	  if (release) {
	    if (i == ANDROID) {
              runCommand((std::string(u8"cordova build android --release -- --keystore=\"") + KEYSTORE_PATH + std::string("\" --storePassword=") + KEYSTORE_PASSWORD + std::string(" --password=") + KEYSTORE_PASSWORD + std::string(" --alias=") + KEYSTORE_ALIAS + std::string(" --packageType=") + (ANDROID_BUILD_APK ? std::string("apk") : std::string("bundle"))).c_str());
	    }
	    else {
              runCommand(std::string(u8"cordova build ios").c_str());
	    }
	  }
	  else {
            runCommand(std::string(u8"cordova build ") + std::string(i == ANDROID ? u8"android" : u8"ios").c_str());
	  }
        }
      }
      else {
	std::cout << "Incorrect path\n";
        sendNotificIncPath();
      }
  }
  else {
    sendNotificNoVars(noVars);
  }
}
