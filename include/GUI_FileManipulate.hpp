#pragma once
#include "Constants.hpp"

#include <windows.h>
#include <commdlg.h>
#include <shlobj.h>
#include <iostream>
#include <fstream>
#include <string>
#include <tchar.h>
#include <vector>

namespace GUI{

class FileManipulate : private Constants{

    public:
        FileManipulate();

        void externalFileManipulate();
        bool takeInformation(int &n, std::vector<int> &arraySave);

    private:
        std::string textSave;

};

}