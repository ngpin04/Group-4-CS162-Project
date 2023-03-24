#pragma once
#include <iostream>
#include "../header/generalClass.h"
#include "../header/scoreboard.h"
using namespace std;

struct course
{
    int id;
    string courseName;
    generalClass className;
    string teacherName;
    int credit;
    int maximum = 50;
    string dayOfWeek;
    int session;
    studentList* enrolledStudents;
    scoreList* scoreboard;
};

struct courseList
{
    course data;
    courseList* next;
};

