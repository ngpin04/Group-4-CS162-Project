#pragma once
#include "user.h"

struct student {
    int number;
    string id;
    string firstName;
    string lastName;
    bool isFemale = false;
    date birth;
    string socialID;
};

struct studentList {
    student data;
    studentList* next = nullptr;
};

