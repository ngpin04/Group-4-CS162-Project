#include "../header/startSem.h"
#include "../header/console.h"
#include "../header/createSemester.h"
#include "../header/addCourse.h"
#include "../header/uploadStudentList.h"
#include <iostream>

using namespace std;

void startSem(yearList *YearList) {
    clearScreen();
    cout << "====================================================================" << endl;
    cout << "Logged In >> Main Menu >> Possible Actions >> BEGIN-SEMESTER ACTIONS" << endl;
    cout << "====================================================================" << endl;
    int choice = 100;

    semester *newSem = nullptr;
    while (choice != 0) {
        cout << "Actions at the beginning of semester: " << endl
             << endl;
        cout << "\t1. Create a semester" << endl;
        cout << "\t2. Add course to semester" << endl;
        cout << "\t3. Upload list of students to course" << endl;
        cout << "\t3. View list of courses" << endl;
        cout << "\t4. Update course information" << endl;
        cout << "\t5. Add a student to course" << endl;
        cout << "\t6. Remove a student from course" << endl;
        cout << "\t7. Delete a course" << endl;
        cout << "\t0. Return to Possible Actions"
             << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 0) {
            clearScreen();
            cout << "==============================================================" << endl;
            cout << "Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
            cout << "==============================================================" << endl;
            return;
        } else if (choice == 1) {
            newSem = createSemester(YearList);
        } else {
            if (newSem == nullptr) {
                cout << "Semester has not been created, please try again." << endl;
            }

            switch (choice) {
                case 2: addCourse(newSem);
                case 3: uploadStudentList(newSem->allCourses);
                case 4:
                case 5:
                case 6:
                case 7:
                case 8: {
                    break;
                }
            }
        }
    }
}
