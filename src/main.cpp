#include "../header/user.h"
#include "../header/readData.h"
#include "../header/login.h"

userList *userData = new userList;

int main() {
    readData(userData, "data/user.txt");
    printData(userData);
    user* curUser = nullptr;
    while (true){
        if (!curUser)
            checkUserAtLogIn(userData, curUser);
        else{
            menuAfterLogin(curUser);
        }     
    }
    return 0;
}