#include "../header/user.h"
#include "../header/readData.h"
#include "../header/login.h"
#include "../header/schoolYear.h"

userList *userData = new userList;
yearList *YearList = new yearList;
semester *curSemester = nullptr;
schoolYear *curYear = nullptr;

int main() {
    readData(userData, "data/user.txt");
    readYearList(YearList);
    readAllCourse(YearList);
    readTime(curSemester, curYear, YearList);
    readAllClasses(YearList);
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
    //saveYearList(YearList);
    //saveTime(curSemester, curYear); //unfinished
    return 0;
}