#include <iostream>
#include "../header/user.h"
using namespace std;

void checkUserAtLogIn(userList *pHead, user *&curUser)
{
    int a;
    cout << "==============================================" << endl;
    cout << "|| Welcome to the Course Management System! ||" << endl;
    cout << "==============================================" << endl << endl;
    cout << "Logging in..." << endl;
    cout << "Enter username: ";
    string curUsername;
    cin >> curUsername;
    cout << "Enter password: ";
    string curPassword;
    cin >> curPassword;
    while (pHead)
    {
        if (curUsername == pHead->data.username && curPassword == pHead->data.password)
        {
            cout << "Login successfully!";
            curUser = &(pHead->data);
            return;
        }
        pHead = pHead->next;
    }
    do
    {
        cout << "No such account exists! Please re-enter username and password." << endl; //re-login until login ok
        cout << "Enter username: ";
        cin >> curUsername;
        cout << "Enter password: ";
        cin >> curPassword;
        while (pHead)
        {
            if (curUsername == pHead->data.username && curPassword == pHead->data.password)
            {
                cout << "Login successfully!";
                curUser = &(pHead->data);
                return;
            }
            pHead = pHead->next;
        }
    } while (true);
}

void startSem()
{
    cout << "\033[2J\033[1;1H";
    int start;
    cout << "Beginning of Semester: " << endl
         << endl;
    cout << "1. Create a semester" << endl;
    cout << "2. Add course to semester" << endl;
    cout << "3. Upload list of students to course" << endl;
    cout << "4. View list of courses" << endl;
    cout << "5. Update course information" << endl;
    cout << "6. Add a student to course" << endl;
    cout << "7. Remove a student from course" << endl;
    cout << "8. Delete course" << endl
         << endl;
    cout << "Your choice: ";
    cin >> start;

    switch (start)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 0: break;
    }
}

void endSem()
{
    cout << "\033[2J\033[1;1H";
    int end;
    cout << "End of Semester: " << endl
         << endl;
    cout << "1. Export list of students from course" << endl;
    cout << "2. Import scoreboard of a course" << endl;
    cout << "3. View scoreboard of a course" << endl;
    cout << "4. Update student's result" << endl;
    cout << "5. View scoreboard of a class" << endl
         << endl;
    cout << "Your choice: ";
    cin >> end;

    switch (end)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 0: break;
    }
}

void anyTime()
{
    cout << "\033[2J\033[1;1H";
    int r;
    cout << "Possible actions: " << endl
         << endl;
    cout << "1. View list of classes" << endl;
    cout << "2. View list of students in a class" << endl;
    cout << "3. View list of courses" << endl;
    cout << "4. View list of students in a course" << endl
         << endl;
    cout << "Your choice: ";
    cin >> r;

    switch (r)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 0: break;
    }
}

void actionsAsStaff()
{
    cout << "\033[2J\033[1;1H";
    int a;
    cout << "Possible actions" << endl
         << endl;
    cout << "\t1. At the beginning of semester" << endl;
    cout << "\t2. At the End of semester" << endl;
    cout << "\t3. At any time" << endl
         << endl;
    cout << "Your choice: ";
    cin >> a;

    switch (a)
    {
    case 1:
    {
        startSem();
        break;
    }
    case 2:
    {
        endSem();
        break;
    }
    case 3:
    {
        anyTime();
        break;
    }
    }
}

void actionsAsStudent()
{
    cout << "\033[2J\033[1;1H";
    int choice;
    cout << "Possible actions: " << endl
         << endl;
    cout << "\t1. View list of courses" << endl;
    cout << "\t2. View scoreboard" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    case 2:
    case 0: break;
    }
}

void menuAfterLogin(user *&curUser)
{
    cout << "\033[2J\033[1;1H";
    int choice;
    cout << "Options: " << endl
         << endl;
    cout << "\t1. View your profile" << endl;
    cout << "\t2. Change password" << endl;
    cout << "\t3. Possible actions" << endl;
    cout << "\t0. Logout" << endl
         << endl;
    cout << "Your choice: ";
    cin >> choice;
    cout << "\033[2J\033[1;1H";

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
    case 0:{
        curUser = nullptr;
        return;
    }
    }
}