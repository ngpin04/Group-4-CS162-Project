#include <iostream>
using namespace std;

struct date{
    int day;
    int month;
    int year;
};

struct user
{
    int id; //student or staff id
    bool isStaff = false; //default as student
    date birth;
    string username;
    string password = "KHTN123@"; //the dafault password need to be set to ddmmyyyy of the user
    void changePassword();
};
