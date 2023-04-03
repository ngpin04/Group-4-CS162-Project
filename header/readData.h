#pragma once
#include "../header/user.h"
#include "../header/schoolYear.h"
#include "../header/readData.h"
void readData(userList *User, string filename);

void printData(userList *pHead);

void readTime(semester* curSemester, schoolYear* curYear);

void saveTime(semester* curSemester, schoolYear* curYear);