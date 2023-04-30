#pragma once
#include <iostream>
#include "student.h"

using namespace std;

struct generalClass
{
    int firstYear = -1;
    string name;
    string index = "unused";
    studentList* studentHead = nullptr;
    void input(ifstream& fi);
};

struct classList
{
    generalClass data;
    classList* next = nullptr;
};
