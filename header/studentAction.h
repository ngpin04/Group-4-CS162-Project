#pragma once
#include "schoolYear.h"
#include "user.h"

void printCourseScore(int userID, semester *s);

void viewScoreboard(user *curUser, yearList *YearList);

void viewCourseInSemesterOfAStudent(semester *head, user *curUser);