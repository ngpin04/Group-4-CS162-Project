#include <iostream>
#include "../header/user.h"
#include "../header/readData.h"

void readData(user User[], int &numUser, string filename) {
    ifstream fi(filename);
    while (true) {
        int num; fi >> num;
        if (num == -1) 
            break;
        User[numUser].input(fi);
        ++numUser;
    }
    fi.close();
}