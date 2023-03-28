#include <iostream>
#include "../header/user.h"
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
void checkUserAtLogIn(userList *pHead, user *&curUser)
{
    clearScreen();
    cout << "==============================================" << endl;
    cout << "|| Welcome to the Course Management System! ||" << endl;
    cout << "==============================================" << endl
         << endl;
    cout << "Logging in..." << endl;
    cout << "Enter username: ";
    string curUsername;
    cin >> curUsername;
    cout << "Enter password: ";
    string curPassword;
    cin >> curPassword;
    userList* cur = pHead;
    while (cur)
    {
        if (curUsername == cur->data.username && curPassword == cur->data.password)
        {
            cout << "Login successfully!" << endl << endl;
            curUser = &(cur->data);
            return;
        }
        cur = cur->next;
    }
    cur = pHead;
    do
    {
        cout << endl << "No such account exists! Please re-enter username and password." << endl; // re-login until login ok
        cout << "Enter username: ";
        cin >> curUsername;
        cout << "Enter password: ";
        cin >> curPassword;
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
    } while (curUser == nullptr);
}

void startYear()
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
            case 2:
            case 3:
            {
                int tmp;
                cout << "Add students to 1st-year class: "
                     << endl;
                cout << "Choose class: " << endl
                     << endl;
                cout << "1. Add one-by-one" << endl;
                cout << "2. Import CSV file" << endl
                     << endl;
                cout << "Your choice: ";
                cin >> tmp;
                
                if (tmp == 1)
                {

                }
                else if (tmp == 2)
                {

                }
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

void startSem()
{
    clearScreen();
    cout << "====================================================================" << endl;
    cout << "Logged In >> Main Menu >> Possible Actions >> BEGIN-SEMESTER ACTIONS" << endl;
    cout << "====================================================================" << endl;
    int choice = 100;

    while (choice != 0)
    {
        cout << "Actions at the beginning of semester: " << endl
             << endl;
        cout << "\t1. Create a semester" << endl;
        cout << "\t2. Add course to semester" << endl;
        cout << "\t3. Upload list of students to course" << endl;
        cout << "\t4. View list of courses" << endl;
        cout << "\t5. Update course information" << endl;
        cout << "\t6. Add a student to course" << endl;
        cout << "\t7. Remove a student from course" << endl;
        cout << "\t8. Delete a course" << endl;
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
            case 6:
            case 7:
            case 8:
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

void anyTime()
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
            case 1:
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

void actionsAsStaff()
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
                startYear();
                break;
            }
            case 2:
            {
                startSem();
                break;
            }
            case 3:
            {
                endSem();
                break;
            }
            case 4:
            {
                anyTime();
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

void actionsAsStudent()
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
            case 2:
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

void menuAfterLogin(user *&curUser)
{
    clearScreen();
    cout << "==============================================================" << endl;
    cout << "Logged In >> MAIN MENU" << endl;
    cout << "==============================================================" << endl;
    int choice = 100;

    while (choice != 0)
    {
        cout << endl << "Hi, " << curUser->username << "!" << endl << endl;
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
                break;
            }
            case 3:
            {
                if (curUser->isStaff)
                    actionsAsStaff();
                else
                    actionsAsStudent();
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