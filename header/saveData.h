#include <iostream>
#include <string>
#include "../header/user.h"
#include "../header/schoolYear.h"

using namespace std;

void printData(userList *User, string filename);

void saveCourseList(courseList* CourseList, string filename);

void saveAllCourse(yearList* YearList);

void saveClass(classList*& ClassList, string filename);

void saveAllClasses(yearList* YearList);