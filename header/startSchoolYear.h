#pragma once
#include "schoolYear.h"

bool isInt(string s);
void checkYear(string& input);
void returnActions();
void createSchoolYear(yearList*& head, schoolYear*& curYear);
schoolYear* findYear(yearList* head, int n);
void createClasses(yearList*& head);
generalClass* findClass(yearList* year, string classname);
void inputStu(student& stu);
void add1Stu(generalClass*& c);
int to_num(const string &str);
void addManyStus(generalClass*& c);
void beforeAddStus(generalClass*& c, yearList*& year, int& tmp);
void updateStuOfYearsAfter(yearList*& year, schoolYear* curYear);