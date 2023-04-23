#pragma once
#include <windows.h>
#include <commdlg.h>
#include <shlobj.h>
#include <iostream>
#include <fstream>
#include <string>
#include <tchar.h>
#include <vector>

namespace GUI{

class FileManipulate{

    public:
        FileManipulate();

        void externalFileManipulate();

    private:
        std::vector<std::string> textSave;

};

}