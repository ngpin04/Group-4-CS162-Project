#pragma once
#include <string>
#include "../header/user.h"
#include "../header/course.h"
#include "../header/generalClass.h"
using namespace std;

struct schoolYear //for example: 2020-2021
{
    int start;
    int end;
    semester* sem1;
    semester* sem2;
    semester* sem3;
    classList* allClasses;
};

struct semester
{
    date startDate;
    date endDate;
    courseList* allCourses;
};

struct yearList
{
    schoolYear data;
    yearList* next;
};
