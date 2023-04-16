#include <iostream>
#include "../header/user.h"
#include "../header/startSem.h"
#include "../header/login.h"
#include "../header/console.h"
#include "../header/student.h"
#include "../header/startSchoolYear.h"
#include "../header/studentAction.h"
#include "../header/anyTime.h"
using namespace std;

void checkUserAtLogIn(userList *pHead, user *&curUser)
{
    clearScreen();
    cout << "\t\t\t----------------------------------------------" << endl;
    cout << "\t\t\t|  Welcome to the Course Management System!  |" << endl;
    cout << "\t\t\t----------------------------------------------" << endl
         << endl;
    cout << "\t\t\tType 0 to exit." << endl << endl;
    string curUsername;
    string curPassword;
    userList *cur = pHead;
    do
    {
        cout << "Enter username: ";
        cin >> curUsername;
        if (curUsername == "0"){
            curUser = nullptr;
            return;
        }
        cout << "Enter password: ";
        cin >> curPassword;
        cur = pHead;
        while (cur)
        {
            if (curUsername == cur->data.username && curPassword == cur->data.password)
            {
                cout << "Login successfully!" << endl;
                curUser = &(cur->data);
                return;
            }
            cur = cur->next;
        }
        cout << endl
             << "Account and password are invalid! Please re-enter username and password." << endl; // re-login until login ok
    } while (curUser == nullptr);
}

void startYear(yearList* YearList)
{
    clearScreen();
    cout << "====================================================================" << endl;
    cout << "Logged In >> Main Menu >> Possible Actions >> YEAR-START ACTIONS" << endl;
    cout << "====================================================================" << endl;
    int choice = 100;

    while (choice != 0)
    {
        cout << "Actions at the start of the school year: " << endl
             << endl;
        cout << "\t1. Create a school year" << endl;
        cout << "\t2. Create class for 1st years" << endl;
        cout << "\t3. Add students to 1st-year class" << endl;
        cout << "\t0. Return to Possible Actions"
             << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: 
        {
            createSchoolYear(YearList);
            break;
        }
        case 2: 
        {
            createClasses(YearList);
            break;
        }
        case 3:
        {
            int tmp;
            generalClass* c;
            beforeAddStus(c, YearList->data.allClasses, tmp);
            if (tmp == 1)
            {
                add1Stu(YearList->data.allClasses, c);
            }
            else if (tmp == 2)
            {
                addManyStus(YearList->data.allClasses, c);
            }
            break;
        }
        case 0:
        {
            clearScreen();
            cout << "==============================================================" << endl;
            cout << "Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
            cout << "==============================================================" << endl;
            return;
        }
        }
    }
}

void endSem()
{
    clearScreen();
    cout << "==================================================================" << endl;
    cout << "Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
    cout << "==================================================================" << endl;
    int choice = 100;

    while (choice != 0)
    {
        cout << "Actions at the end of semester: " << endl
             << endl;
        cout << "\t1. Export list of students from course" << endl;
        cout << "\t2. Import scoreboard of a course" << endl;
        cout << "\t3. View scoreboard of a course" << endl;
        cout << "\t4. Update student's result" << endl;
        cout << "\t5. View scoreboard of a class" << endl;
        cout << "\t0. Return to Possible Actions"
             << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 0:
        {
            clearScreen();
            cout << "==============================================================" << endl;
            cout << "Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
            cout << "==============================================================" << endl;
            return;
        }
        }
    }
}

void anyTime(schoolYear* curYear)
{
    clearScreen();
    cout << "==============================================================" << endl;
    cout << "Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
    cout << "==============================================================" << endl;
    int choice = 100;

    while (choice != 0)
    {
        cout << "Actions at any time: " << endl
             << endl;
        cout << "\t1. View list of classes" << endl;
        cout << "\t2. View list of students in a class" << endl;
        cout << "\t3. View list of courses" << endl;
        cout << "\t4. View list of students in a course" << endl;
        cout << "\t0. Return to Possible Actions" << endl
             << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:{
            viewClass(curYear);
            break;
        }
        case 2:
        case 3:
        case 4:
        case 0:
        {
            clearScreen();
            cout << "==============================================================" << endl;
            cout << "Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
            cout << "==============================================================" << endl;
            return;
        }
        }
    }
}

void actionsAsStaff(yearList *YearList, schoolYear* curYear)
{
    clearScreen();
    cout << "==============================================================" << endl;
    cout << "Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
    cout << "==============================================================" << endl;
    int choice = 100;

    while (choice != 0)
    {
        cout << "Possible actions" << endl
             << endl;
        cout << "\t1. At the beginning of the school year" << endl;
        cout << "\t2. At the beginning of semester" << endl;
        cout << "\t3. At the end of semester" << endl;
        cout << "\t4. At any time" << endl;
        cout << "\t0. Return to Main Menu"
             << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            startYear(YearList);
            break;
        }
        case 2:
        {
            startSem(YearList);
            break;
        }
        case 3:
        {
            endSem();
            break;
        }
        case 4:
        {
            anyTime(curYear);
            break;
        }
        case 0:
        {
            clearScreen();
            cout << "==============================================================" << endl;
            cout << "Logged In >> MAIN MENU" << endl;
            cout << "==============================================================" << endl;
            return;
        }
        }
    }
}

void actionsAsStudent(user *&curUser,semester *curSemester)
{
    clearScreen();
    cout << "==============================================================" << endl;
    cout << "Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
    cout << "==============================================================" << endl;
    int choice = 100;

    while (choice != 0)
    {
        cout << "Possible actions: " << endl
             << endl;
        cout << "\t1. View list of courses" << endl;
        cout << "\t2. View scoreboard" << endl;
        cout << "\t0. Return to Main Menu"
             << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            viewCourseInSemesterOfAStudent(curSemester,curUser);
            break;
        }
        case 2:
        {
            printCourseScore(curUser->id,curSemester);
            break;
        }
        case 0:
        {
            clearScreen();
            cout << "==============================================================" << endl;
            cout << "Logged In >> MAIN MENU" << endl;
            cout << "==============================================================" << endl;
            return;
        }
        }
    }
}

void menuAfterLogin(user *&curUser, yearList *YearList,semester *curSemester, schoolYear *curYear)
{
    clearScreen();
    cout << "==============================================================" << endl;
    cout << "Logged In >> MAIN MENU" << endl;
    cout << "==============================================================" << endl;
    int choice = 100;

    while (choice != 0)
    {
        cout << endl
             << "Hi, " << curUser->username << "!" << endl
             << endl;
        cout << "Options: " << endl
             << endl;
        cout << "\t1. View your profile" << endl;
        cout << "\t2. Change password" << endl;
        cout << "\t3. Possible actions" << endl;
        cout << "\t0. Logout" << endl
             << endl;
        cout << "Your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        case 2:
        {
            curUser->changePassword();
            clearScreen();
            cout << "==============================================================" << endl;
            cout << "Logged In >> MAIN MENU" << endl;
            cout << "==============================================================" << endl;
            break;
        }
        case 3:
        {
            if (curUser->isStaff)
                actionsAsStaff(YearList, curYear);
            else
                actionsAsStudent(curUser,curSemester);
            break;
        }
        case 0:
        {
            curUser = nullptr;
            return;
        }
        }
    }
}