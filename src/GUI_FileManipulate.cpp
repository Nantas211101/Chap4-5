#include "../include/GUI_FileManipulate.hpp"
HWND hwnd;
TCHAR szFileName[MAX_PATH];

namespace GUI {

FileManipulate::FileManipulate(){

};

void FileManipulate::externalFileManipulate() {
    OPENFILENAME ofn;
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = _T("Text Files (*.txt)\0*.txt\0");
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = _T("txt");

    if (GetOpenFileName(&ofn) == TRUE) {
        // User selected a file
        std::ifstream file(ofn.lpstrFile);
        std::string line;
        while (std::getline(file, line)) {
            textSave += line + " ";
        }
    } else {
        // User cancelled the dialog
    }
}

bool FileManipulate::takeInformation(int& n, std::vector<int>& arraySave) {
    for(char c : textSave){
        bool ok = false;
        for(int i = 0; i < Constants::numOfAcceptedChar; ++i)
            if(c == Constants::acceptedChar[i]){
                ok = true;
            }
        if(!ok)
            return false;
    }
    return true;
}

}