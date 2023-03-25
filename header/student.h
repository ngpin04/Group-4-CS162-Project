#pragma once
#include "../header/user.h"
struct student
{
    int number;
    int id;
    string firstName;
    string lastName;
    bool isFemale = false;
    date birth;
    int socialID;
};

struct studentList{
    student data;
    studentList* next;
};