#include "../header/user.h"
#include "../header/readData.h"
#include "../header/login.h"
#include "../header/schoolYear.h"

userList *userData = new userList;
yearList *YearList = new yearList;
semester *curSemester = new semester;
schoolYear *curYear = new schoolYear;

int main() {
    readData(userData, "data/user.txt");
    readYearList(YearList);
    readAllCourse(YearList);
    readTime(curSemester, curYear);
    //printData(userData);
    user* curUser = nullptr;
    while (true){
        if (!curUser){
            printData(userData);
            checkUserAtLogIn(userData, curUser);
            if (curUser == nullptr)
                break;
        }
        else{
            menuAfterLogin(curUser, YearList, curSemester, curYear);
        }
    }
    saveYearList(YearList);
    //saveTime(curSemester, curYear); //unfinished
    return 0;
}