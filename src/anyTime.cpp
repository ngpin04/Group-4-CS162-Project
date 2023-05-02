#include "../header/anyTime.h"
#include "../header/console.h"
#include <iomanip>

// 15. View a list of classes.
void viewClass(schoolYear* curYear)
{
	if (curYear->allClasses == nullptr)
	{
		cout << endl
			<< "No class found!" << endl;
		cout << "Enter any character to continue: ";
		string temp;
		cin >> temp;
		clearScreen();
		cout << "==============================================================" << endl;
		cout << "Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
		cout << "==============================================================" << endl;
		return;
	}
	classList* curClass = curYear->allClasses;
	int index = 1;
	while (curClass)
	{
		cout << index << ". " << curClass->data.name << endl;
		index++;
		curClass = curClass->next;
	}
	cout << "Enter any character to continue: ";
	string temp;
	cin >> temp;
	clearScreen();
	cout << "==============================================================" << endl;
	cout << "Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
	cout << "==============================================================" << endl;
}

//16. View a list of students of a class.
void viewStudent(schoolYear* curYear)
{
	if (curYear->allClasses == nullptr)
	{
		cout << endl
			<< "No class found!" << endl;
		cout << "Enter any character to continue: ";
		string temp;
		cin >> temp;
		clearScreen();
		cout << "==============================================================" << endl;
		cout << "Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
		cout << "==============================================================" << endl;
		return;
	}
	classList* curClass = curYear->allClasses;
	int index = 1;
	while (curClass)
	{
		cout << "\t" << index << ". " << curClass->data.name << endl;
		index++;
		curClass = curClass->next;
	}
	cout << "Enter the class you want to view: ";
	int choice;
	cin >> choice;

	curClass = curYear->allClasses;
	for (int i = 1; i < choice; i++)
	{
		curClass = curClass->next;
	}
	if (curClass->data.studentHead == nullptr)
	{
		cout << endl
			<< "No student found!" << endl;
		cout << "Enter any character to continue: ";
		string temp;
		cin >> temp;
		clearScreen();
		cout << "==============================================================" << endl;
		cout << "Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
		cout << "==============================================================" << endl;
		return;
	}

	studentList* curStudent = curClass->data.studentHead;
	index = 1;
	cout << "\t       ------------------------------------------------------------------------------------\n";
	cout << "\t        No |    ID    |             Fullname           |  Sex   |    Birth   |   SocialID" << endl;
	cout << "\t       ------------------------------------------------------------------------------------\n";
	while (curStudent)
	{
		string fullname = curStudent->data.lastName + " " + curStudent->data.firstName;
		cout << "\t\t" << setw(2) << index << " | " << curStudent->data.id << " | " << fullname;
		if (fullname.size() >= 30)
			cout << fullname;
		else {
			for (int i = 0; i < (30 - fullname.size()); i++)
				cout << " ";
		}
		cout << " | ";
		if (curStudent->data.isFemale)
			cout << "Female";
		else
			cout << " Male ";
		cout << " | " << setw(2) << curStudent->data.birth.day << '/' << setw(2) << curStudent->data.birth.month << '/' << setw(2) << curStudent->data.birth.year << " | " << curStudent->data.socialID << endl;
		
		index++;
		curStudent = curStudent->next;
	}
	cout << endl << "Enter any character to continue: ";
	string temp;
	cin >> temp;
	clearScreen();
	cout << "==============================================================" << endl;
	cout << "Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
	cout << "==============================================================" << endl;
}

//17. View a list of courses of a semester.
void viewCourse(semester* curSemester)
{
	if (curSemester->allCourses == nullptr)
	{
		cout << endl
			<< "No course found!" << endl;
		cout << "Enter any character to continue: ";
		string temp;
		cin >> temp;
		clearScreen();
		cout << "==============================================================" << endl;
		cout << "Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
		cout << "==============================================================" << endl;
		return;
	}
	courseList* curCourse = curSemester->allCourses;
	int index = 1;
	while (curCourse)
	{
		cout << index << ". " << curCourse->data.courseName << endl;
		index++;
		curCourse = curCourse->next;
	}
	cout << "Enter any character to continue: ";
	string temp;
	cin >> temp;
	clearScreen();
	cout << "==============================================================" << endl;
	cout << "Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
	cout << "==============================================================" << endl;
}

//