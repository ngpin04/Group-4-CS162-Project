#include <iostream>
#include "../header/user.h"
using namespace std;

int main()
{
    user user;
}

void startSem()
{
    int start;
    cout << "Beginning of Semester: " << endl << endl;
    cout << "1. Create a semester" << endl;
    cout << "2. Add course to semester" << endl;
    cout << "3. Upload list of students to course" << endl;
    cout << "4. View list of courses" << endl;
    cout << "5. Update course information" << endl;
    cout << "6. Add a student to course" << endl;
    cout << "7. Remove a student from course" << endl;
    cout << "8. Delete course" << endl << endl;
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
    }
}

void endSem()
{
    int end;
    cout << "End of Semester: " << endl << endl;
    cout << "1. Export list of students from course" << endl;
    cout << "2. Import scoreboard of a course" << endl;
    cout << "3. View scoreboard of a course" << endl;
    cout << "4. Update student's result" << endl;
    cout << "5. View scoreboard of a class" << endl << endl;
    cout << "Your choice: ";
    cin >> end;

    switch (end)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
    }
}

void anyTime()
{
    int r;
    cout << "Possible actions: " << endl << endl;
    cout << "1. View list of classes" << endl;
    cout << "2. View list of students in a class" << endl;
    cout << "3. View list of courses" << endl;
    cout << "4. View list of students in a course" << endl << endl;
    cout << "Your choice: ";
    cin >> r;

    switch (r)
    {
        case 1:
        case 2:
        case 3:
        case 4:
    }
}

void loginAsStaff()
{
    cout << "\033[2J\033[1;1H";
    int a;
    cout << "Possible actions: " << endl << endl;
    cout << "1. Beginning of semester" << endl;
    cout << "2. End of semester" << endl;
    cout << "3. Any time" << endl << endl;
    cout << "Your choice: ";
    cin >> a;

    switch (a)
    {
        case 1: startSem();
        case 2: endSem();
        case 3: anyTime();
    }
}

void loginAsStudent()
{
    cout << "\033[2J\033[1;1H";
    int a;
    cout << "Possible actions: " << endl << endl;
    cout << "1. View list of courses" << endl;
    cout << "2. View scoreboard" << endl;
    cout << "Your choice: ";
    cin >> a;

    switch (a)
    {
        case 1: 
        case 2: 
    }
}

void login()
{
    int a;
        cout << "Welcome to the Course Management System." << endl << endl;
        cout << "1. Academic staff" << endl;
        cout << "2. Student" << endl << endl;
        cout << "Login as: ";
        cin >> a;
        cout << "\033[2J\033[1;1H";

        int b;
        cout << "Options: " << endl << endl;
        cout << "1. View your profile" << endl;
        cout << "2. Change password" << endl;
        cout << "3. Possible actions" << endl;
        cout << "0. Logout" << endl << endl;
        cout << "Your choice: ";
        cin >> b;
        cout << "\033[2J\033[1;1H";

        switch (b)
        {
            case 1:
            case 2:
            {
                user user;
                user.changePassword();
            }
            case 3:
            {
                if (a == 1) loginAsStaff();
                if (a == 2) loginAsStudent();
            }
            case 0:
        }
}
    