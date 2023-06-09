#pragma once
#include "user.h"
#include "schoolYear.h"
#include "readData.h"
void readData(userList *User, string filename);

void printData(userList *pHead);

void readTime(semester*& curSemester, schoolYear*& curYear, yearList* YearList, int& index);

void saveTime(semester* curSemester, schoolYear* curYear);

void readYearList(yearList* YearList);

void saveYearList(yearList* YearList);

void readAllCourse(yearList* YearList);

void readAllClasses(yearList* YearList);