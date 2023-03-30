#pragma once
#include <string>
#include "../header/user.h"
#include "../header/course.h"
#include "../header/generalClass.h"
using namespace std;

struct semester
{
    date startDate;
    date endDate;
    bool scorePublished = false; // only true when scoreboard of all courses have been updated
    courseList* allCourses;
};

struct schoolYear //for example: 2020-2021
{
    int start;
    int end;
    semester *sem1, *sem2, *sem3;
    classList* allClasses;
};

struct yearList
{
    schoolYear data;
    yearList* next;
};  
