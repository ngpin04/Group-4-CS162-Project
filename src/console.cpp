#include "../header/console.h"

using namespace std;

void clearScreen() {
    #if defined _WIN32
        system("cls");
        //clrscr(); // including header file : conio.h
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
        //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
    #elif defined (__APPLE__)
        system("clear");
    #endif
}

bool check(istream &cur) {
    if (cur.fail()) {
        cur.clear(); // clears the error flags
        // this line discards all the input waiting in the stream
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "invalid input, please try again!" << endl;
        return false;
    }
    return true;
}