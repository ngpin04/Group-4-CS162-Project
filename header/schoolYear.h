#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "user.h"
#include "course.h"
#include "generalClass.h"
using namespace std;

struct semester
{
    int semesterID = 0; // 1,2,3
    date startDate;
    date endDate;
    bool scorePublished = false; // = not time to view scores yet
    courseList* allCourses = nullptr;
};

struct schoolYear //for example: 2020-2021
{
    int start;
    int end;
    semester *sem1 = nullptr, *sem2 = nullptr, *sem3 = nullptr;
    classList* allClasses = nullptr;
    void input();
};

struct yearList
{
    schoolYear data;
    yearList* next = nullptr;
};  
