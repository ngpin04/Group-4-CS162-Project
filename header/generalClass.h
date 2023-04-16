#pragma once
#include <iostream>
#include "student.h"

using namespace std;

struct generalClass
{
    int firstYear;
    string name;
    string index;
    studentList* studentHead = nullptr;
};

struct classList
{
    generalClass data;
    classList* next = nullptr;
};
