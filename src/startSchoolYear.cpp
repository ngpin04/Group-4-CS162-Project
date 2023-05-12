#include "../header/login.h"
#include "../header/schoolYear.h"
#include "../header/startSchoolYear.h"
#include "../header/console.h"
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

void returnActions()
{
    cout << "Enter any character to continue: ";
    string tmp;
    cin >> tmp;
    clearScreen();
    cout << " ================================================================" << endl;
    cout << " Logged In >> Main Menu >> Possible Actions >> YEAR-START ACTIONS" << endl;
    cout << " ================================================================" << endl;
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
        returnActions();
        return;
    }
    while (cur)
    {
        if (cur->data.start==start)
        {
            delete tmp;
            cout << "This school year has been created before!" << endl;
            returnActions();
            return;
        }
        cur = cur -> next;
    }
    cur = head;
    while (cur->next && cur->next->data.start<start && cur->next->data.start!=-1)
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
    cout << "Create school year successfully!" << endl;
    returnActions();
}

//2. Create classes for 1st year students
void createClasses(schoolYear*& curYear)
{
    cout << "Enter the list of classes, enter 0 to stop: ";
    if (!curYear->allClasses) curYear->allClasses = new classList; //No classes have been added
    classList* curClass = curYear->allClasses;
    if (curClass->next)
    {
        while (curClass->next) curClass = curClass -> next; //Find the last class in the list
        curClass -> next = new classList;
        curClass = curClass -> next;
    }
    string name;
    cin >> name;
    if (name=="0") 
    {
        if (curYear->allClasses->data.firstYear==-1)
            curYear->allClasses = nullptr;
        cout << "No new classes have been added! Please try again!" << endl;
        returnActions();
        return;
    }
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
    returnActions();
}

void inputStu(student& stu)
{
    cout << "Enter the student's info" << endl;
    cout << "Student ID: ";
    cin >> stu.id;
    cout << "First name: ";
    cin.ignore();
    getline(cin, stu.firstName);
    cout << "Last name: ";
    getline(cin, stu.lastName);
    cout << "Gender (0 for male, 1 for female): ";
    int n;
    cin >> n;
    if (n) stu.isFemale = true;
    else stu.isFemale = false;
    cout << "Date of birth (DD MM YYYY): ";
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
        cout << "Added successfully!" << endl;
        returnActions();
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
    cout << "Added successfully!" << endl;
    returnActions();
}

int to_num(const string &str)
{
    int res = 0;
    for (char c : str)
        res = 10 * res + (c - '0');
    return res;
}

//4. Add 1st year students by csv file
void addManyStus(generalClass*& c)
{
    cout << "Enter the name of the csv file that you want to upload (including .csv): ";
    string filename;
    cin >> filename;
    ifstream fin(filename);
    if (fin.is_open())
    {
        c->studentHead = new studentList;
        studentList* curStu = c->studentHead;
        string line, word;
        getline(fin, line); // read and discard the first line of the file
        while (getline(fin, line))
        {
            student stu;
            stringstream str(line);
            getline(str, word, ',');
            getline(str, word, ',');
            stu.id = word;
            getline(str, word, ',');
            stu.firstName = word;
            getline(str, word, ',');
            stu.lastName = word;
            getline(str, word, ',');
            stu.isFemale = to_num(word);
            getline(str, word, ',');
            stu.birth.day = to_num(word);
            getline(str, word, ',');
            stu.birth.month = to_num(word);
            getline(str, word, ',');
            stu.birth.year = to_num(word);
            getline(str, word, ',');
            stu.socialID = word;
            
            curStu->data = stu;
            if (fin.peek() != EOF)
            {
                curStu->next = new studentList;
                curStu = curStu->next;
            }
            else curStu->next = nullptr;
        }
        fin.close();
        cout << "Added successfully!" << endl;
        returnActions();
    }
    else
    {
        cout << "Could not open the file!" << endl;
        returnActions();
    }
}

void beforeAddStus(generalClass*& c, classList* allClasses, int& tmp)
{
    cout << "List of classess in this year: " << endl;
    int index = 1;
    classList* curClass = allClasses;
    while (curClass)
    {
        cout << "\t" << index++ << ". " << curClass->data.name << endl;
        curClass = curClass->next;
    }
    cout << "Enter the number of the class you want to target: ";
	int choice;
	cin >> choice;
    for (int i=1; i<choice; ++i)
        allClasses = allClasses->next;
    c = &(allClasses->data);
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

//5. Update students from previous years
void updateStuOfYearsAfter(yearList*& year, schoolYear* curYear)
{
    yearList* cur = year;
    while (cur && cur->data.start != curYear->start)
        cur = cur -> next; //Find the current year
    if (cur) //make sure cur != nullptr
    {
        int s = cur->data.start, e = cur->data.end;
        yearList* nextCur = cur;
        int cnt = 1;
        while (cnt<4) //Create 3 other school years
        {
            if (nextCur->next && nextCur->next->data.start!=-1) 
                nextCur = nextCur -> next; //Find the next year
            else 
            {
                yearList* tmp = new yearList;
                tmp -> next = nextCur -> next;
                tmp -> data.start = ++s;
                tmp -> data.end = ++e;
                tmp -> data.allClasses = cur -> data.allClasses;
                nextCur -> next = tmp;
                nextCur = nextCur -> next;
                ++cnt;
                continue;
            }
            classList* newClasses = cur -> data.allClasses;
            while (newClasses->next) newClasses = newClasses -> next;
            newClasses -> next = nextCur -> data.allClasses;
            nextCur -> data.allClasses =  cur -> data.allClasses;
            ++s;
            ++e;
            ++cnt;
        }
    }
}