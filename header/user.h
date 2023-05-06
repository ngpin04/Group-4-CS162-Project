#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct date{
    int day = -1;
    int month = -1;
    int year = -1;
};

struct user
{
    string id; //student or staff id
    bool isStaff = false; //default as student
    date birth;
    string username;
    string password = "KHTN123@"; //the dafault password need to be set to ddmmyyyy of the user
    void changePassword();
    void input(ifstream &fi);
    void output(ofstream &fo);
};

struct userList {
    userList *next = nullptr;
    user data;
    userList();
    userList(user data);
    userList(userList *next, user data);
};