#pragma once
#include "schoolYear.h"
#include "user.h"
#include "iomanip"

void printCourseScore(string userID, semester *s);

void viewScoreboard(user *curUser, semester *curSemester);

void viewCourseInSemesterOfAStudent(semester *head, user *curUser);