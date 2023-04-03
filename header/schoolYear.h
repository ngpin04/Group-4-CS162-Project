#pragma once
#include <string>
#include "../header/user.h"
#include "../header/course.h"
#include "../header/generalClass.h"
using namespace std;

struct semester
{
    int semesterID = 0; // 1,2,3
    date startDate;
    date endDate;
    bool scorePublished = false; // = not time to view scores yet
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
