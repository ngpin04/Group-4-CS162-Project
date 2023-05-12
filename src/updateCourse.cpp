#include "../header/updateCourse.h"

using namespace std;

void updateCourse(courseList *current) {
    if (current == nullptr) {
        cout << "There is no courses to update! Press any key to return" << endl;
        cin.ignore();
        cin.get();
        return;
    }
    cout << "Please choose the course that you want to update: " << "\n";
    int count = 0;
    for (courseList *i = current; i != nullptr; i = i->next) {
        count++;
        cout << count << ". " << i->data.id << " " << i->data.className << "\n";
    }
    
    int choice = 0; 
    cin >> choice;
    if (choice > count || choice <= 0) {
        cout << "your choice is invalid! Press any key to return" << endl;
        cin.ignore();
        cin.get();
        return;
    }

    if (current == nullptr) {
        cout << " There is no course with your provided id, please try again" << endl;
        return;
    }
    
    int action;
    cout << " Please choose from the following action: " << endl;
    cout << "\t1. Update course id" << endl;
    cout << "\t2. Update couse name" << endl;
    cout << "\t3. Update class name" << endl;
    cout << "\t4. Update teacher name" << endl;
    cout << "\t5. Update number of credits" << endl;
    cout << "\t6. Update maximum number of students" << endl;
    cout << "\t7. Update day of week and session" << endl;
    cout << "\t8. Update results released" << endl;
    cout << endl << " Your choice: ";
    cin >> action;
    switch (action) {
        case 0: {
            return;
        }
        case 1: {
            cout << " Please enter course id: ";
            cin >> current->data.id;
            break;
        }
        case 2: {
            cout << " Please enter course name: ";
            cin >> current->data.courseName;
            break;
        }
        case 3: {
            cout << " Please enter class name: ";
            cin >> current->data.className;
            break;
        }
        case 4: {
            cout << " Please enter teacher name: ";
            getline(cin, current->data.teacherName);
            break;
        }
        case 5: {
            cout << " Please enter the number of credits: ";
            cin >> current->data.credit;    
            break;
        }
        case 6: {
            cout << " Please enter the maximum number of students (0 to set it to default): ";
            cin >> current->data.maximum;
            if (current->data.maximum == 0)
                current->data.maximum = 50;
            break;
        }
        case 7: {
            cout << " Please enter the day of week (only the first three capital letters) and the session (from 1 to 4) of this course: ";
            cin >> current->data.dayOfWeek >> current->data.session;
            break;
        }
        case 8: {
			cout << " Please enter the results released (0 for false, 1 for true): ";
			cin >> current->data.resultsReleased;
            break;
		}
    }

}