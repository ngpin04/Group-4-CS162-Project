#include "../header/login.h"
#include "../header/schoolYear.h"
#include "../header/startSchoolYear.h"
#include <fstream>

using namespace std;

bool isInt(string s)
{
    if (s.empty()) return false;
    for (char c : s)
    {
        if (!isdigit(c)) return false;
    }
    return true;
}

void startYear(string& input)
{
    do
    {
        cin >> input;
        if (!isInt(input)) 
            cout << "School year must be an integer. Please enter again: ";
    } while (!isInt(input));
}

//1. Create a school year
void createSchoolYear(yearList*& head)
{
    cout << "Enter the school year (For example enter 2022 to create the school year 2022-2023): ";
    string input;
    startYear(input);
    int start = stoi(input);
    schoolYear year;
    year.start = start;
    year.end = start+1;
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

schoolYear* findYear(yearList* head, int n)
{
    yearList* curYear = head;
    while (curYear && curYear->data.start!=n)
        curYear = curYear -> next;
    if (!curYear) return nullptr;
    return &curYear->data;
}

//2. Create classes for 1st year students
void createClasses(yearList*& head)
{
    cout << "In which school year do you want to create classes? ";
    string input;
    startYear(input);
    int start = stoi(input);
    schoolYear* year = findYear(head, start);
    while (!year)
    {
        cout << "No such school year exists. Please enter the school year again: ";
        startYear(input);
        start = stoi(input);
        year = findYear(head, start);
    }
    cout << "Enter the list of classes, enter 0 to stop: ";
    year->allClasses = new classList;
    classList* curClass = year->allClasses;
    string name;
    cin >> name;
    if (name=="0") year->allClasses = nullptr;
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

generalClass* findClass(classList* allClasses, string classname)
{
    classList* curClass = allClasses;
    while(curClass)
    {
        if (curClass->data.name==classname)
            return &(curClass->data);
        curClass = curClass -> next;
    }
    return nullptr;  
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

//3. Add 1st year students one by one
void add1Stu(classList*& allClasses, generalClass*& c)
{
    student stu;
    inputStu(stu);
    studentList* curStu = c->studentHead;
    studentList* tmp = new studentList;
    tmp -> data = stu;
    tmp -> next = nullptr;
    if (!curStu) //No students have been added
    {
        c->studentHead = tmp;
        cout << "Added successfully" << endl;
        return;
    }
    while (curStu->next && curStu->next->data.id<stu.id)
        curStu = curStu -> next;
    if (curStu==c->studentHead && c->studentHead->data.id<stu.id) //Only 1 student in class and id < the one we add
    {
        c->studentHead -> next = tmp;
    }
    else if (curStu==c->studentHead && c->studentHead->data.id>stu.id) //Only 1 student in class and id > the one we add
    {
        tmp -> next = c->studentHead;
        c->studentHead = tmp;
    }
    else if (!curStu->next) //All students in class have id < the one we add
    {
        curStu -> next = new studentList;
        curStu -> next = tmp;
    }
    else //The student we add have id in the middle of the list
    {
        tmp -> next = curStu -> next;
        curStu -> next = tmp;
    }
    cout << "Added successfully" << endl;
}

//4. Add 1st year students by csv file
void addManyStus(classList*& allClasses, generalClass*& c)
{
    cout << "Enter the name of the csv file that you want to upload: ";
    string filename;
    cin >> filename;
    ifstream fin;
    fin.open(filename);
    if (fin.is_open())
    {
        c->studentHead = new studentList;
        studentList* curStu = c->studentHead;
        while (fin.peek()!=EOF)
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
        cout << "Added successfully" << endl;
    }
    else 
        cout << "Could not open the file" << endl;
    fin.close();
}

void beforeAddStus(generalClass*& c, classList*& allClasses, int& tmp)
{
    cout << "Which class do you want to add this student into? ";
    string classname;
    cin >> classname;
    c = findClass(allClasses, classname);
    while (!c)
    {
        cout << "No such class exists. Please enter classname again: ";
        cin >> classname;
        c = findClass(allClasses, classname);
    }
    cout << "Add students to 1st-year class: " << endl;
    cout << "How do you want to add students? " << endl
         << endl;
    cout << "1. Add one-by-one" << endl;
    cout << "2. Import CSV file" << endl
         << endl;
    cout << "Your choice: ";
    cin >> tmp;
}