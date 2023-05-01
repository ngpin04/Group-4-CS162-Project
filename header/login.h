#pragma once
#include "schoolYear.h"
#include "user.h"

void checkUserAtLogIn(userList *pHead, user *&curUser);

void endSem(yearList* YearList);

void anyTime(schoolYear* curYear, semester* curSem);

void actionsAsStaff(yearList *YearList, schoolYear* curYear, semester* curSem);

void actionsAsStudent(user *&curUser,semester *curSemester);

void menuAfterLogin(user *&curUser, yearList *YearList,semester *curSemester, schoolYear *curYear);