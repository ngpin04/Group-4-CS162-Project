#include "../header/login.h"
#include "../header/schoolYear.h"
#include "../header/startSchoolYear.h"
#include <fstream>

using namespace std;

void createSchoolYear(yearList*& head)
{
    cout << "Enter the school year: ";
    int start, end;
    cin >> start >> end;
    schoolYear year;
    year.start = start;
    year.end = end;
    yearList* cur = head;
    yearList* tmp = new yearList;
    tmp -> data = year;
    tmp -> next = nullptr;
    if (!cur) //No school years have been added
    {
        head = tmp;
        return;
    }
    while (cur->next && cur->next->data.start<start)
        cur = cur -> next;
    if (cur==head && head->data.start<start) //Only 1 year added and < the one we add
    {
        head -> next = tmp;
    }  
    else if (cur==head && head->data.start>start) //Only 1 year added and > the one we add
    {
        tmp -> next = head;
        head = tmp;
    }
    else if (!cur->next) //All years added < the one we add
    {
        cur -> next = new yearList;
        cur -> next = tmp;
    }
    else //The year we add in the middle of the list
    {
        tmp -> next = cur -> next;
        cur -> next = tmp;
    }
}

void createClasses(schoolYear& year)
{
    cout << "Enter the list of classes, enter 0 to stop: ";
    year.allClasses = new classList;
    classList* curClass;
    curClass = year.allClasses;
    string name;
    cin >> name;
    if (name=="0") year.allClasses = nullptr;
    while(name!="0")
    {
        curClass -> data.name = name;
        cin >> name;
        if (name!="0")
        {
            curClass -> next = new classList;
            curClass = curClass -> next;
        }
        else curClass -> next = nullptr;
    }   
}

void add1Stu(generalClass& c, classList* allClasses)
{
    c.name ="";
    cout << "Which class do you want to add this student into? ";
    string classname;
    cin >> classname;
    c = findClass(allClasses, classname);
    while (c.name=="")
    {
        cout << "No such class exists. Please enter classname again: ";
        cin >> classname;
        c = findClass(allClasses, classname);
    }
    student stu;
    inputStu(stu);
    studentList* curStu = c.studentHead;
    studentList* tmp = new studentList;
    tmp -> data = stu;
    tmp -> next = nullptr;
    if (!curStu) //No students have been added
    {
        c.studentHead = tmp;
        return;
    }
    while (curStu->next && curStu->next->data.id<stu.id)
        curStu = curStu -> next;
    if (curStu==c.studentHead && c.studentHead->data.id<stu.id) //Only 1 student in class and id < the one we add
    {
        c.studentHead -> next = tmp;
    }
    else if (curStu==c.studentHead && c.studentHead->data.id>stu.id) //Only 1 student in class and id > the one we add
    {
        tmp -> next = c.studentHead;
        c.studentHead = tmp;
    }
    else if (!curStu->next) //All students in class have id < the one we add
    {
        curStu -> next = new studentList;
        curStu -> next = tmp;
    }
    else //The student we add have id in the middleof the list
    {
        tmp -> next = curStu -> next;
        curStu -> next = tmp;
    }
}

generalClass findClass(classList* allClasses, string classname)
{
    classList* curClass = allClasses;
    generalClass c;
    while(curClass)
    {
        if (curClass->data.name==classname)
        {
            c = curClass->data;
            return c;
        }
        curClass = curClass -> next;
    }
    if (!curClass) 
    {
        c.name = "";
        return c;
    }     
}

void inputStu(student& stu)
{
    cout << "Enter the student's info" << endl;
    cout << "Order: "; 
    cin >> stu.number;
    cout << "Student ID: ";
    cin >> stu.id;
    cout << "First name: ";
    cin.ignore();
    getline(cin, stu.firstName);
    cout << "Last name: ";
    cin.ignore();
    getline(cin, stu.lastName);
    cout << "Gender (0 for male, 1 for female): ";
    int n;
    cin >> n;
    if (n) stu.isFemale = true;
    else stu.isFemale = false;
    cout << "Date of birth: ";
    cin >> stu.birth.day >> stu.birth.month >> stu.birth.year;
    cout << "Social ID: ";
    cin >> stu.socialID;
}

void addManyStus(generalClass& c, classList* allClasses, string filename)
{
    cout << "Which class do you want to add this student into? ";
    string classname;
    cin >> classname;
    c = findClass(allClasses, classname);
    ifstream fin;
    fin.open(filename);
    if (fin.is_open())
    {
        c.studentHead = new studentList;
        studentList* curStu = c.studentHead;
        while (fin.peek()!=EOF);
        {
            fin.ignore(1000, '\n');
            student stu;
            fin >> stu.number;
            fin >> stu.id;
            fin.ignore();
            getline(fin, stu.firstName,',');
            fin.ignore();
            getline(fin, stu.lastName,',');
            fin >> stu.isFemale;
            fin >> stu.birth.day >> stu.birth.month >> stu.birth.year;
            fin >> stu.socialID;
            curStu -> data = stu;
            curStu -> next = new studentList;
            curStu = curStu -> next;
        }
        curStu -> next = nullptr;
    }
    fin.close();
}