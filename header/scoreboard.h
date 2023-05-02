#pragma once
#include "student.h"

struct score
{
    int number =-1;
    string id = "-1";
    string fullname;
    double total = -1.00;
    double finalMark = -1.00;
    double midterm = -1.00;
    double other = 0.00;
};

struct scoreList{
    score data;
    scoreList* next = nullptr;
};