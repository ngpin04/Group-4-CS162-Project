#pragma once
#include <iostream>
#include "../header/scoreboard.h"
using namespace std;

struct course
{
    string id;
    string courseName;
    string className;
    string teacherName;
    int credit;
    int maximum = 50;
    string dayOfWeek;
    int session;
    bool resultsReleased;
    studentList* enrolledStudents;
    scoreList* scoreboard;
};

struct courseList
{
    course data;
    courseList* next;
};

