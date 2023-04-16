#pragma once
#include <iostream>
#include "scoreboard.h"
#include "student.h"
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
    studentList* enrolledStudents = nullptr;
    scoreList* scoreboard = nullptr;
};

struct courseList
{
    course data;
    courseList* next = nullptr;
};

