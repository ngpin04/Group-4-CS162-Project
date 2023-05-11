#include "../header/user.h"
#include "../header/readData.h"
#include "../header/login.h"
#include "../header/schoolYear.h"
#include "../header/saveData.h"

userList *userData = new userList;
yearList *YearList = new yearList;
semester *curSemester = nullptr;
schoolYear *curYear = nullptr;
int curSemIndex = 1;

int main() {
    readData(userData, "data/user.txt");
    readYearList(YearList);
    readAllCourse(YearList);
    readTime(curSemester, curYear, YearList, curSemIndex);
    readAllClasses(YearList);
    user* curUser = nullptr;
    while (true){
        if (curUser == nullptr){
            printData(userData);
            checkUserAtLogIn(userData, curUser);
            if (curUser == nullptr)
                break;
        }
        else{
            menuAfterLogin(curUser, YearList, curSemester, curYear, curSemIndex);
        }
    }
    saveData(userData, "data/user.txt");
    saveYearList(YearList);
    // saveAllCourse(YearList);
    // saveTime(curSemester, curYear);
    // saveAllClasses(YearList);
    return 0;
}