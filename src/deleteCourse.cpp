#include <iostream>
#include "../header/deleteCourse.h"

using namespace std;

void deleteCourse(courseList *courses) {
    string id; 
    cout << "Please enter the course id that you want to delete: ";
    cin >> id;
    courseList *pre = nullptr;
    for (courseList *cur = courses; cur != nullptr; cur = cur->next) {
        if (cur->data.id == id) {
            if (pre == nullptr)
                courses = cur->next;
            else 
                pre->next = cur->next;
            cout << "Courses deletion is done!" << endl;
            delete cur;
            return;
        }
        pre = cur;
    }
    cout << "There is no course with the provided id!" << endl;
}