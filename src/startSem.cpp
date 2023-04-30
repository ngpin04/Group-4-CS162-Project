#include "../header/startSem.h"
#include "../header/console.h"
#include "../header/createSemester.h"
#include "../header/addCourse.h"
#include "../header/uploadStudentList.h"
#include "../header/viewCourse.h"
#include "../header/updateCourse.h"
#include "../header/removeStudent.h"
#include "../header/deleteCourse.h"
#include "../header/addStudent.h"
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
        cout << "\t4. View list of courses" << endl;
        cout << "\t5. Update course information" << endl;
        cout << "\t6. Add a student to course" << endl;
        cout << "\t7. Remove a student from course" << endl;
        cout << "\t8. Delete a course" << endl;
        cout << "\t0. Return to Possible Actions"
             << endl;
        cout << "Your choice: ";
        cin >> choice;
        if (!(cin >> choice)) {
            cin.clear(); // clears the error flags
            // this line discards all the input waiting in the stream
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 100;
            cout << "invalid input, please try again!" << endl;
            continue;
        }
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
                case 4: viewCourse(newSem->allCourses);
                case 5: updateCourse(newSem->allCourses);
                case 6: addStudent(newSem->allCourses);
                case 7: removeStudent(newSem->allCourses);
                case 8: {
                    deleteCourse(newSem->allCourses);
                    break;
                }
            }
        }
    }
}
