#pragma once
#include "schoolYear.h"

bool isInt(string s);
void startYear(string& input);
void createSchoolYear(yearList*& head, schoolYear*& curYear);
schoolYear* findYear(yearList* head, int n);
void createClasses(yearList*& head);
generalClass* findClass(classList* allClasses, string classname);
void inputStu(student& stu);
void add1Stu(generalClass*& c);
void addManyStus(generalClass*& c);
void beforeAddStus(generalClass*& c, classList*& allClasses, int& tmp);