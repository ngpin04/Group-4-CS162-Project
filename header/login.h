#pragma once
#include "schoolYear.h"
#include "user.h"

void checkUserAtLogIn(userList *pHead, user *&curUser);

void endSem(yearList* YearList, schoolYear* curYear, semester* curSemester);

void anyTime(schoolYear* curYear, semester* curSem);

void actionsAsStaff(yearList* YearList, schoolYear*& curYear, semester*& curSemester, int& index);

void actionsAsStudent(user*& curUser, semester* curSemester, schoolYear* curYear, int index);

void menuAfterLogin(user*& curUser, yearList* YearList, semester*& curSemester, schoolYear*& curYear, int& index);