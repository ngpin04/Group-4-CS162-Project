#pragma once
#include "../header/student.h"

struct score
{
    int number;
    int id;
    string fullname;
    double total;
    double finalMark;
    double midterm;
    double other;
};

struct scoreList{
    score data;
    scoreList* next;
};
