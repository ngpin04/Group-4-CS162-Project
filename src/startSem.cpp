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

void startSem(yearList *YearList, schoolYear *curYear, semester * &curSem, int &index) {
    clearScreen();
    cout << " ====================================================================" << endl;
    cout << " Logged In >> Main Menu >> Possible Actions >> BEGIN-SEMESTER ACTIONS" << endl;
    cout << " ====================================================================" << endl;
    int choice = 100;

    while (choice != 0) {
        cout << " Actions at the beginning of semester: " << endl
             << endl;
        cout << "\t1. Create a semester" << endl;
        cout << "\t2. Add course to semester" << endl;
        cout << "\t3. Upload list of students to course" << endl;
        cout << "\t4. Update course information" << endl;
        cout << "\t5. Add a student to course" << endl;
        cout << "\t6. Remove a student from course" << endl;
        cout << "\t7. Delete a course" << endl;
        cout << "\t0. Return to Possible Actions" << endl
             << endl;
        cout << " Your choice: ";
        //cin >> choice;
        if (!(cin >> choice)) {
            cin.clear(); // clears the error flags
            // this line discards all the input waiting in the stream
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 100;
            cout << "Invalid input, please try again!" << endl;
            continue;
        }
        if (choice == 0) {
            clearScreen();
            cout << " ==============================================================" << endl;
            cout << " Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
            cout << " ==============================================================" << endl;
            return;
        } else if (choice == 1) {
            delete curSem;
            curSem = new semester;
            curSem->semesterID = index;
            cout << "Please enter the semester start date (DD MM YY): ";
            cin >> curSem->startDate.day;
            cin >> curSem->startDate.month;
            cin >> curSem->startDate.year;
            cout << "Please enter the semester end date (DD MM YY): ";
            cin >> curSem->endDate.day;
            cin >> curSem->endDate.month;
            cin >> curSem->endDate.year;
            assert(curSem->allCourses == nullptr);
            cout << "New semester is created! Press any key to continue" << endl;
            cin.ignore();
            cin.get();
        } else {
            if (curSem == nullptr) {
                cout << " Semester has not been created, please try again." << endl;
                continue;
            }

            switch (choice) {
                case 2: {
                    addCourse(curSem->allCourses);
                    break;
                }
                case 3: {
                    uploadStudentList(curSem->allCourses);
                    break;
                }
                case 4: {
                    updateCourse(curSem->allCourses);
                    break;
                }
                case 5: {
                    addStudent(curSem->allCourses);
                    break;
                }
                case 6: {
                    removeStudent(curSem->allCourses);
                    break;
                }
                case 7: {
                    deleteCourse(curSem->allCourses);
                    break;
                }
            }
        }
    }
}
