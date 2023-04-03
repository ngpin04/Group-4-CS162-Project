#pragma once
#include "../header/user.h"
#include "../header/schoolYear.h"
struct student
{
    int number;
    int id;
    string firstName;
    string lastName;
    bool isFemale = false;
    date birth;
    int socialID;
};

struct studentList{
    student data;
    studentList* next;
};

void printCourseScore(int userID, semester *s);

void viewScoreboard(user *curUser, yearList *YearList);

void viewCourseInSemesterOfAStudent(semester *head, user *curUser);