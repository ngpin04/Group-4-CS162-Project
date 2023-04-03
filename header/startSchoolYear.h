#pragma once
#include "schoolYear.h"

void createSchoolYear(yearList*& cur);
void createClasses(schoolYear& year);
void add1Stu(generalClass& c, classList* allClasses);
generalClass findClass(classList* allClasses, string classname);
void inputStu(student& stu);
void addManyStus(generalClass& c, classList* allClasses, string filename);