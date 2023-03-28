#pragma once
#include "schoolYear.h"
#include "user.h"

void checkUserAtLogIn(userList *pHead, user *&curUser);

void endSem();

void anyTime();

void actionsAsStaff();

void actionsAsStudent();

void menuAfterLogin(user *&curUser, yearList *YearList);