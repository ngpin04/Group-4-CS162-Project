#include <iostream>
#include "../header/addStudent.h"

using namespace std;

void addStudent(courseList *courses) {
    if (courses == nullptr) {
        cout << "There is no courses to update! Press any key to return" << endl;
        cin.ignore();
        cin.get();
        return;
    }
    studentList *newStudent = new studentList;
    newStudent->next = nullptr;
    cout << " Please enter the student's id: ";
    cin >> newStudent->data.id;
    cout << " Please enter the student birth (DD MM YYYY): ";
    cin >> newStudent->data.birth.day;
    cin >> newStudent->data.birth.month;
    cin >> newStudent->data.birth.year;
    cout << " Please enter the student's first name: ";
    cin >> newStudent->data.firstName;
    cout << " Please enter the student's last name: ";
    cin.ignore(100, '\n');
    getline(cin, newStudent->data.lastName);
    cout << " Please enter 0 if the student is male and 1 if the student is female: ";
    cin >> newStudent->data.isFemale;
    cout << " Please enter the student's social ID: ";
    cin >> newStudent->data.socialID;
    studentList *lastptr = courses->data.enrolledStudents;
    if (lastptr == nullptr) 
        lastptr = newStudent;
    else {
        while (lastptr->next != nullptr && lastptr->next->data.id < newStudent->data.id)
            lastptr = lastptr->next;
        lastptr->next = newStudent;
    }
}