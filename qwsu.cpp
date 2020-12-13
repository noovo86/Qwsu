#include <iostream>
#include <fstream>
#include <cstdlib>
#include <dirent.h>
#include <string>
using namespace std;
int main() {
    const char* path = "./";
    DIR *dp;
    dp = opendir(path);
    if (dp==NULL) exit(1);
    dirent* entry = readdir(dp);
    std::string out;
    while (entry != NULL){
        if (entry != NULL) {
            std::string fname = entry->d_name;
            std::string::size_type pos = fname.find_last_of('.');
            if ( fname.substr(pos + 1) == "pro" ){
                out = "./" + fname;
                std::cout << out << std::endl;
            }
        }
        entry = readdir(dp);
    }
    std::ifstream ifs(out);
    std::string str;
    int hyouka = 0;
    while (getline(ifs, str)) {
        if (str.find("QT += widgets") != std::string::npos) {
            hyouka = 1;
        }        
    }
    if (hyouka == 0){
        ofstream ofs(out, ios::app);
        ofs <<"\nQT += widgets" << endl;
    }
    

    return 0;
}
