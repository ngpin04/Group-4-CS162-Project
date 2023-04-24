#include "../header/login.h"
#include "../header/schoolYear.h"
#include "../header/startSchoolYear.h"
#include <fstream>
#include <sstream>

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

void checkYear(string& input)
{
    do
    {
        cin >> input;
        if (!isInt(input)) 
            cout << "School year must be an integer. Please enter again: ";
    } while (!isInt(input));
}

//1. Create a school year
void createSchoolYear(yearList*& head, schoolYear*& curYear)
{
    cout << "Enter the school year (For example enter 2022 to create the school year 2022-2023): ";
    string input;
    checkYear(input);
    int start = stoi(input);
    schoolYear year;
    year.start = start;
    year.end = start+1;
    yearList* cur = head;
    yearList* tmp = new yearList;
    tmp -> data = year;
    tmp -> next = nullptr;
    curYear = &(tmp -> data);
    if (!cur) //No school years have been added
    {
        head = tmp;
        cout << "Created school year successfully!" << endl;
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
    else if (cur==head && head->data.start==start) //We added that year before
    {
        delete tmp;
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
    cout << "Create school year successfully!" << endl;
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
    checkYear(input);
    int start = stoi(input);
    schoolYear* year = findYear(head, start);
    while (!year)
    {
        cout << "No such school year exists. Please enter the school year again: ";
        checkYear(input);
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
    cout << "Created classes successfully!" << endl;   
}

generalClass* findClass(yearList* year, string classname)
{
    classList* curClass = year -> data.allClasses;
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
void add1Stu(generalClass*& c)
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
void addManyStus(generalClass*& c)
{
    cout << "Enter the name of the csv file that you want to upload: ";
    string filename;
    cin >> filename;
    ifstream fin(filename);
    if (fin.is_open())
    {
        c->studentHead = new studentList;
        studentList* curStu = c->studentHead;
        string line;
        getline(fin, line); // read and discard the first line of the file
        while (getline(fin, line))
        {
            stringstream ss(line);
            student stu;
            char comma;
            ss >> stu.number >> comma >> stu.id >> comma >> stu.firstName >> comma >> stu.lastName >> comma >> stu.isFemale >> comma
               >> stu.birth.day >> comma >> stu.birth.month >> comma >> stu.birth.year >> comma >> stu.socialID;
            curStu->data = stu;
            curStu->next = new studentList;
            curStu = curStu->next;
        }
        curStu->next = nullptr;
        fin.close();
        cout << "Added successfully" << endl;
    }
    else 
        cout << "Could not open the file" << endl;
}

void beforeAddStus(generalClass*& c, yearList*& year, int& tmp)
{
    cout << "In which school year do you want to add student(s) into? ";
    int y;
    yearList* tmpYear;
    do
    {
        tmpYear = year;
        cin >> y;
        while (tmpYear && tmpYear->data.start != y)
            tmpYear = tmpYear -> next;
        if (!tmpYear) cout << "No such school year exists. Please enter the school year again: ";
    } while (!tmpYear);
    cout << "Which class do you want to add student(s) into? ";
    string classname;
    cin >> classname;
    c = findClass(tmpYear, classname);
    while (!c)
    {
        cout << "No such class exists. Please enter classname again: ";
        cin >> classname;
        c = findClass(tmpYear, classname);
    }
    cout << "Add students to 1st-year class: " << endl;
    cout << "How do you want to add students? " << endl
         << endl;
    cout << "1. Add one-by-one" << endl;
    cout << "2. Import CSV file" << endl
         << endl;
    cout << "Your choice: ";
    cin >> tmp;
    while (!(tmp==1 || tmp ==2))
    {
        cout << "Please choose from the two options: ";
        cin >> tmp;
    }
}

void updateStuOfYearsAfter(yearList*& year, schoolYear* curYear)
{
    yearList* cur = year;
    while (cur && cur->data.start != curYear->start)
        cur = cur -> next; //Find the current year
    int s = cur->data.start, e = cur->data.end;
    yearList* tmp = year;
    while (tmp && tmp->data.start != curYear->start)
            tmp = tmp -> next;
    int cnt = 1;
    while (cnt<4) //Create 3 other school years
    {
        tmp = tmp -> next; //Find the next year
        if (tmp)
        {
            tmp -> data.allClasses = cur -> data.allClasses;
            ++s;
            ++e;
        }
        else
        {
            tmp = new yearList;
            tmp -> next = nullptr;
            tmp -> data.start = ++s;
            tmp -> data.end = ++e;
            tmp -> data.allClasses = cur -> data.allClasses;
        }
        ++cnt;
    }
}