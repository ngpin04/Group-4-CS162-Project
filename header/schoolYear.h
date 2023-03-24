#pragma once
#include <string>
#include "../header/user.h"
using namespace std;

struct schoolYear //for example: 2020-2021
{
    int start;
    int end;
};

struct semester
{
    int index; // 1 or 2 or 3
    schoolYear year;
    date startDate;
    date endDate;
};


