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

void readTime(semester* curSemester, schoolYear* curYear){
    ifstream fi("data/current.txt");
    fi >> curYear->start;
    fi >> curYear->end;
    fi >> curSemester->semesterID;
    fi.close();
}

void saveTime(semester* curSemester, schoolYear* curYear){
    ofstream fo("data/current.txt");
    fo << curYear->start << endl;
    fo << curYear->end << endl;
    fo << curSemester->semesterID << endl;
    fo.close();
}