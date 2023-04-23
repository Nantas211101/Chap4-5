#include "../include/GUI_FileManipulate.hpp"
HWND hwnd;
TCHAR szFileName[MAX_PATH];

namespace GUI{

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
            std::cout << line << '\n';
        }
    } else {
        // User cancelled the dialog
    }
 
}

}