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
    int credit = 4;
    int maximum = 50;
    string dayOfWeek;
    int session = 1;
    bool resultsReleased = false;
    studentList* enrolledStudents = nullptr;
    scoreList* scoreboard = nullptr;
    void input(ifstream& fi);
    void output(ofstream& fo);
};

struct courseList
{
    course data;
    courseList* next = nullptr;
};

