#include "../header/updateCourse.h"

using namespace std;

void updateCourse(courseList *current) {
    cout << "Please enter the course id that you want to update: ";
    string id; cin >> id;
    while (current != nullptr) {
        if (current->data.id == id)
            break;
    }

    if (current == nullptr) {
        cout << "There is no course with your provided id, please try again" << endl;
        return;
    }
    int action;
    cout << "Please choose from the following action: " << endl;
    cout << "\t1. Update course id" << endl;
    cout << "\t2. Update couse name" << endl;
    cout << "\t3. Update class name" << endl;
    cout << "\t4. Update teacher name" << endl;
    cout << "\t5. Update number of credits" << endl;
    cout << "\t6. Update maximum number of students" << endl;
    cout << "\t7. Update day of week and session" << endl;
    
    switch (action) {
        case 0: {
            return;
        }
        case 1: {
            cout << "Please enter course id: ";
            cin >> current->data.id;
        }
        case 2: {
            cout << "Please enter course name: ";
            cin >> current->data.courseName;
        }
        case 3: {
            cout << "Please enter class name: ";
            cin >> current->data.className;
        }
        case 4: {
            cout << "Please enter teacher name: ";
            getline(cin, current->data.teacherName);
        }
        case 5: {
            cout << "Please enter the number of credits: ";
            cin >> current->data.credit;    
        }
        case 6: {
            cout << "Please enter the maximum number of students (0 to set it to default): ";
            cin >> current->data.maximum;
            if (current->data.maximum == 0)
                current->data.maximum = 50;
        }
        case 7: {
            cout << "Please enter the day of week (only the first three capital letters) and the session (from 1 to 4) of this course: ";
            cin >> current->data.dayOfWeek >> current->data.session;
        }
    }

}