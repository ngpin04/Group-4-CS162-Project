#include "../header/addCourse.h"
#include <iostream>

using namespace std;

void addCourse(semester *sem) {
    course newCourse;
    cout << " Please enter course id: ";
    cin >> newCourse.id;
    cout << " Please enter course name: ";
    cin.ignore(100, '\n');
    getline(cin, newCourse.courseName);
    cout << " Please enter class name: ";
    cin >> newCourse.className;
    cout << " Please enter teacher name: ";
    cin.ignore(100, '\n');
    getline(cin, newCourse.teacherName);
    cout << " Please enter the number of credits: ";
    cin >> newCourse.credit;
    cout << " Please enter the maximum number of students (0 to set it to default): ";
    cin >> newCourse.maximum;
    if (newCourse.maximum == 0)
        newCourse.maximum = 50;
    cout << " Please enter the day of week (only the first three capital letters) and the session (from 1 to 4) of this course: ";
    cin >> newCourse.dayOfWeek >> newCourse.session;

    courseList *temp = new courseList;
    temp->data = newCourse;
    temp->next = nullptr;

    courseList *lastCourse = sem->allCourses;
    while (lastCourse->next != nullptr)
        lastCourse = lastCourse->next;
    lastCourse->next = temp;
}   