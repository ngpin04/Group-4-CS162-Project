#include <iostream>
#include "../header/removeStudent.h"

using namespace std;

void removeStudent(courseList *courses) {
    if (courses == nullptr) {
        cout << "There is no courses to update! Press any key to return" << endl;
        cin.ignore();
        cin.get();
        return;
    }
    string id;
    cout << " Please enter the student id: ";
    cin >> id;
    studentList *pre = nullptr;
    for (studentList *cur = courses->data.enrolledStudents; cur != nullptr;) {
        if (cur->data.id == id) {
            if (pre == nullptr) 
                courses->data.enrolledStudents = cur->next;
            else 
                pre->next = cur->next;
            delete cur;
            cout << " The deletion is done" << endl;
            return;
        }
        pre = cur;
        cur = cur->next;
    }
    cout << " There is no students matched the id!";
    cout << endl;
}