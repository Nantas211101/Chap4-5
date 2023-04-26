#pragma once
#include "Constants.hpp"

#include <windows.h>
// #include <commdlg.h>
#include <fstream>
#include <iostream>
#include <optional>
// #include <shlobj.h>
#include <string>
// #include <tchar.h>
#include <tuple>
#include <vector>

namespace GUI {

class FileSelector : private Constants {

  public:
    FileSelector(std::string filter = "Text Files (*.txt)\0*.txt\0",
                 std::string ext = "txt");

    std::optional<std::string> select();

  private:
    std::string filter;
    std::string ext;
};

} // namespace GUI