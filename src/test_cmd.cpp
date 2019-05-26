#include "../header/test_cmd.hpp"
#include <iostream>
using namespace std; 

bool Test_cmd::execute() {
    bool status; 
    struct stat buf; 

    //if a flag is passed in 
    if (argList[1] == "-e" || argList[1] == "-f" || argList[1] == "-d") {
        if (stat(argList[2], &buf) == 0) {
            if (argList[1] == "-f"){
                status = S_ISREG(buf.st_mode); 
            }
            if(argList[1] == "-d") {
                status = S_ISDIR(buf.st_mode); 
            }
            else {
                status = S_ISDIR(buf.st_mode) || S_ISREG(buf.st_mode);
            }

            if (status) {
                cout << "(True)" << endl; 
                return true; 
            }
            else {
                cout << "(False)" << endl; 
                return false; 
            }
        }
        else {
            return false; 
        }
    }
    //if no flag is passed in default to -e
    else {
        if (stat(argList[1], &buf) == 0) {
            status = S_ISDIR(buf.st_mode) || S_ISREG(buf.st_mode);
            
            if (status) {
                cout << "(True)" << endl; 
                return true; 
            }
            else {
                cout << "(False)" << endl; 
                return false; 
            }
        }
        else {
            cout << "(False)" << endl; 
            return false; 
        }
    }
}