#pragma once
#include "schoolYear.h"
#include "user.h"
#include "iomanip"

void printCourseScore(int userID, semester *s);

void viewScoreboard(user *curUser, yearList *YearList);

void viewCourseInSemesterOfAStudent(semester *head, user *curUser);