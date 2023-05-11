#include <iostream>
#include <string>
#include "../header/user.h"
#include "../header/schoolYear.h"
#include "../header/readData.h"
#include "../header/saveData.h"

using namespace std;

//save the users account: username and password
void saveData(userList *User, string filename) {
    ofstream fo(filename);
    for (userList *i = User; i->next != nullptr; i = i->next) {
        fo << 1 << " ";
        i->data.output(fo);
    }
    fo << "-1\n";
    fo.close();
}

// save Course List
void saveCourseList(courseList* CourseList, string filename){
    ofstream fo(filename);
    courseList* temp = CourseList;
    while (CourseList != nullptr){
        fo << 1 << "\n";
        CourseList->data.output(fo);
        CourseList = CourseList->next;
    }
    fo.close();
}

// save All Courses
void saveAllCourse(yearList* YearList){
    string prefix = "data/course";
    while (YearList){
        if (YearList && YearList->data.start == -1)
            return;
        string filename = prefix + to_string(YearList->data.start) + "_01.txt"; 
        saveCourseList(YearList->data.sem1->allCourses, filename);
        filename = prefix + to_string(YearList->data.start) + "_02.txt";
        saveCourseList(YearList->data.sem2->allCourses, filename);
        filename = prefix + to_string(YearList->data.start) + "_03.txt";
        saveCourseList(YearList->data.sem3->allCourses, filename);
        YearList = YearList->next;
    }
}

void saveClass(classList*& ClassList, string filename) {
    ofstream fo(filename);
    if (ClassList == nullptr) 
        return;

    classList *cur = ClassList;
    while (true) {
        fo << 1 << "\n";
        fo << cur->data.firstYear << "\n";
        fo << cur->data.name << "\n";
        cur->data.output(fo);
        cur = cur->next;
    }
    fo << -1 << "\n";
    fo.close();
}

void saveAllClasses(yearList* YearList) {
    string prefix = "data/class";
    while (YearList) {
        if (YearList && YearList->data.start == -1)
            return;
        string filename = prefix + to_string(YearList->data.start) + ".txt";
        saveClass(YearList->data.allClasses, filename);
        YearList = YearList->next;
    }
}