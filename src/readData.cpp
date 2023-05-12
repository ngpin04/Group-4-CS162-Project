#include <iostream>
#include <string>
#include "../header/user.h"
#include "../header/schoolYear.h"
#include "../header/readData.h"

//read the users account: username and password
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
//test function to print the users account
void printData(userList *pHead){
    while(pHead){
        cout << pHead->data.username << endl;
        pHead = pHead->next;
    }
}
//read the current time into the program before working with user
void readTime(semester*& curSemester, schoolYear*& curYear, yearList* YearList, int& index){
    ifstream fi("data/current.txt");
    int temp = 0;
    fi >> temp;
    while (YearList) {
        if (YearList && YearList->data.start == temp) {
			curYear = &(YearList->data);
			break;
		}
		YearList = YearList->next;
    }
    fi >> temp;
    fi >> temp;
    if (temp == 1)
        curSemester = curYear->sem1;
    else if (temp == 2)
        curSemester = curYear->sem2;
    else
        curSemester = curYear->sem3;
    index = temp;
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
//read the school year from the file
void readYearList(yearList* YearList){
    ifstream fi("data/schoolYear.txt");
    while (true){
        int num; fi >> num;
        if (num == -1)
            break;
        YearList->data.input(fi);
        YearList->next = new yearList;
        YearList = YearList->next;
    }
    fi.close();
}

//save the school year to text file
void saveYearList(yearList* YearList){
    ofstream fo("data/schoolYearOutput.txt");
    int index = 1;
    while (YearList){
        if (YearList->data.start==-1)
            break;
        fo << index++ << endl;
        fo << YearList->data.start << " ";
        fo << YearList->data.end << endl;
        if (YearList->data.sem1==nullptr)
            fo << 0 << endl;
        else{
            fo << 1 << " ";
            fo << YearList->data.sem1->startDate.day << " ";
            fo << YearList->data.sem1->startDate.month << " ";
            fo << YearList->data.sem1->startDate.year << " ";
            fo << YearList->data.sem1->endDate.day << " ";
            fo << YearList->data.sem1->endDate.month << " ";
            fo << YearList->data.sem1->endDate.year << " ";
            fo << YearList->data.sem1->scorePublished << endl;
        }
        if (YearList->data.sem2==nullptr)
            fo << 0 << endl;
        else{
            fo << 2 << " ";
            fo << YearList->data.sem2->startDate.day << " ";
            fo << YearList->data.sem2->startDate.month << " ";
            fo << YearList->data.sem2->startDate.year << " ";
            fo << YearList->data.sem2->endDate.day << " ";
            fo << YearList->data.sem2->endDate.month << " ";
            fo << YearList->data.sem2->endDate.year << " ";
            fo << YearList->data.sem2->scorePublished << endl;
        }
        if (YearList->data.sem3==nullptr)
            fo << 0 << endl;
        else{
            fo << 3 << " ";
            fo << YearList->data.sem3->startDate.day << " ";
            fo << YearList->data.sem3->startDate.month << " ";
            fo << YearList->data.sem3->startDate.year << " ";
            fo << YearList->data.sem3->endDate.day << " ";
            fo << YearList->data.sem3->endDate.month << " ";
            fo << YearList->data.sem3->endDate.year << " ";
            fo << YearList->data.sem3->scorePublished << endl;
        }
        YearList = YearList->next;
    }
    fo << -1 << endl;
    fo.close();
}

void readCourseList(courseList*& CourseList, string filename){
    ifstream fi(filename);
    if (!fi){
        CourseList = nullptr;
        return;
    }
    while (true){
        int i;
        fi >> i;
        if (i == -1)
            break;
        courseList* temp = CourseList;
        CourseList = new courseList;
        CourseList->data.input(fi);
        CourseList->next = temp;
    }
    fi.close();
}

void readAllCourse(yearList* YearList){
    string prefix = "data/course";
    while (YearList){
        if (YearList && YearList->data.start == -1)
            return;
        string filename = prefix + to_string(YearList->data.start) + "_01.txt"; 
        readCourseList(YearList->data.sem1->allCourses, filename);
        filename = prefix + to_string(YearList->data.start) + "_02.txt";
        readCourseList(YearList->data.sem2->allCourses, filename);
        filename = prefix + to_string(YearList->data.start) + "_03.txt";
        readCourseList(YearList->data.sem3->allCourses, filename);
        YearList = YearList->next;
    }
}

void readClass(classList*& ClassList, string filename) {
    ifstream fi(filename);
    if (!fi) {
        ClassList = nullptr;
        return;
    }
    while (true) {
        int i;
        fi >> i;
        if (i == -1)
            break;
        classList* temp = ClassList;
        ClassList = new classList;
        fi >> ClassList->data.firstYear;
        fi.ignore(100, '\n');
        getline(fi, ClassList->data.name);
        ClassList->data.input(fi);
        ClassList->next = temp;
    }
    fi.close();
}

void readAllClasses(yearList* YearList) {
    string prefix = "data/class";
    while (YearList) {
        if (YearList && YearList->data.start == -1)
            return;
        string filename = prefix + to_string(YearList->data.start) + ".txt";
        readClass(YearList->data.allClasses, filename);
        YearList = YearList->next;
    }
}