#include "loc.hpp"
#include <filesystem>
#include <fstream>
#include <unordered_map>
#if not defined(_MSC_VER)
#include <unistd.h>
#endif
std::unordered_map<std::string, std::string> loc;
std::filesystem::path abs_exe_directory()
{
    #if defined(_MSC_VER)
        wchar_t path[FILENAME_MAX] = { 0 };
        GetModuleFileNameW(nullptr, path, FILENAME_MAX);
        return std::filesystem::path(path).parent_path().string();
    #else
        char path[FILENAME_MAX];
        ssize_t count = readlink("/proc/self/exe", path, FILENAME_MAX);
        return std::filesystem::path(std::string(path, (count > 0) ? count: 0)).parent_path().string();
    #endif
}
void removeSpaces (std::string& str) {
    while (str[0] == ' ' || str[0] == '	') {
      str.erase(0, 1);
    }
    while (str.size() > 0 && (str[str.size() - 1] == ' ' || str[str.size() - 1] == '	')) {
      str.erase(str.size() - 1, 1);
    }
}
void readLocfile (std::ifstream& file) {
  std::string line;
  while (std::getline(file, line, '=')) {
    std::string line2;
    std::getline(file, line2);
    removeSpaces(line);
    removeSpaces(line2);
    loc.insert({line, line2});
  }
}

void InitLoc () {
  std::filesystem::path dir = abs_exe_directory();
  std::filesystem::path locfile = dir / u8"builder-locfile.txt";
  std::ifstream locf (locfile);
  if (locf.is_open()) {
    readLocfile(locf);
    locf.close();
  }
}
std::string localize (const std::string& word) {
  if (loc.find(word) != loc.end()) {
    return loc[word];
  }
  else return word;
}
