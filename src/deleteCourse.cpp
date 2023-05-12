#include <iostream>
#include "../header/deleteCourse.h"

using namespace std;

void deleteCourse(courseList *&courses) {
    if (courses == nullptr) {
        cout << "There is no courses to update! Press any key to return" << endl;
        cin.ignore();
        cin.get();
        return;
    }
    string id; 
    cout << " Please choose the course that you want to delete: ";
    int count = 0;
    for (courseList *cur = courses; cur != nullptr; cur = cur->next) {
        count++;
        cout << count << ". " << cur->data.id << " " << cur->data.className << "\n";
    }

    int res; cin >> res;
    if (res > count || res <= 0) {
        cout << "Invalid choice! Press any key to go back\n";
        cin.ignore();
        cin.get();
        return;
    }
    
    courseList *pre = nullptr, *cur = courses;
    res--;
    while (res--) {
        pre = cur;
        cur = cur->next;
    }

    if (pre == nullptr){
        courses = cur->next;
    } else {
        pre->next = cur->next;
        cout << " Courses deletion is done!" << endl;
        delete cur;
        return;
    }
    cout << " There is no course with the provided id!" << endl;
}