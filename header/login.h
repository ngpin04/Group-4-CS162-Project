#pragma once
#include "schoolYear.h"
#include "user.h"

void checkUserAtLogIn(userList *pHead, user *&curUser);

void endSem();

void anyTime(schoolYear* curYear);

void actionsAsStaff(yearList *YearList, schoolYear* curYear);

void actionsAsStudent(user *&curUser,semester *curSemester);

void menuAfterLogin(user *&curUser, yearList *YearList,semester *curSemester, schoolYear *curYear);