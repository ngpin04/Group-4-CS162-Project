#pragma once
#include "user.h"
#include "schoolYear.h"
#include "readData.h"
void readData(userList *User, string filename);

void printData(userList *pHead);

void readTime(semester*& curSemester, schoolYear* curYear);

void saveTime(semester* curSemester, schoolYear* curYear);