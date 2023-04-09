#pragma once
#include "schoolYear.h"

bool isInt(string s);
void startYear(string& input);
void createSchoolYear(yearList*& cur);
schoolYear* findYear(yearList* head, int n);
void createClasses(yearList*& head);
void add1Stu(classList*& allClasses);
generalClass* findClass(classList* allClasses, string classname);
void inputStu(student& stu);
void addManyStus(classList*& allClasses);