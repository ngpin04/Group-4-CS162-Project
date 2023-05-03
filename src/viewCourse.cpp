#include "../header/course.h"

void viewCourse(courseList *list) {
    int counter = 0;
    while (list != nullptr) {
        cout << counter << ".\n";
        list = list->next;
        course cur = list->data;
        cout << " Course id: " << cur.id << endl;
        cout << " Course name: " << cur.courseName << endl;
        cout << " Class name: " << cur.className << endl;
        cout << " Teacher name: " << cur.teacherName << endl;
        cout << " Number of credits: " << cur.credit << endl;
        cout << " The maximum number of students in the course " << cur.maximum << endl;
        cout << " The day of week and the session: " << cur.dayOfWeek << " " << cur.session << endl;
        cout << " =================================================================================";
    }

    cout << " Enter any character to go back: ";
    int x; cin >> x;
}