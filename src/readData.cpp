#include <iostream>
#include "../header/user.h"
#include "../header/schoolYear.h"
#include "../header/readData.h"

void readData(userList *User, string filename) {
    ifstream fi(filename);
    while (true) {
        int num; fi >> num;
        if (num == -1) 
            break;
        User->data.input(fi);
        User->next = new userList;
        User = User->next;
    }
    fi.close();
}

void printData(userList *pHead){
    while(pHead){
        cout << pHead->data.username << endl;
        pHead = pHead->next;
    }
}
//read the current time into the program before working with user
void readTime(semester*& curSemester, schoolYear* curYear){
    ifstream fi("data/current.txt");
    fi >> curYear->start;
    fi >> curYear->end;
    int temp = 0;
    fi >> temp;
    if (temp == 1)
        curSemester = curYear->sem1;
    else if (temp == 2)
        curSemester = curYear->sem2;
    else
        curSemester = curYear->sem3;
    fi.close();
}
//after user finish working, save the current time to the file
void saveTime(semester* curSemester, schoolYear* curYear){
    ofstream fo("data/current.txt");
    fo << curYear->start << endl;
    fo << curYear->end << endl;
    fo << curSemester->semesterID << endl;
    fo.close();
}