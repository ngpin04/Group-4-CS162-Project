#include "../header/user.h"
#include "../header/readData.h"
#include "../header/login.h"
#include "../header/schoolYear.h"

userList *userData = new userList;
yearList *YearList = new yearList;

int main() {
    readData(userData, "data/user.txt");
    printData(userData);
    user* curUser = nullptr;
    while (true){
        if (!curUser){
            printData(userData);
            checkUserAtLogIn(userData, curUser);
        }
        else{
            menuAfterLogin(curUser, YearList);
        }
    }
    return 0;
}