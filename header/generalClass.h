#pragma once
#include <iostream>
#include "student.h"

using namespace std;

struct generalClass
{
    int firstYear;
    string name;
    string index;
    studentList* studentHead;
};

struct classList
{
    generalClass data;
    classList* next;
};
