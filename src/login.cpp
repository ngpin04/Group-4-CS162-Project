#include <iostream>
#include "../header/user.h"
#include "../header/startSem.h"
#include "../header/login.h"
#include "../header/console.h"
#include "../header/student.h"
#include "../header/startSchoolYear.h"
#include "../header/studentAction.h"
#include "../header/anyTime.h"
#include "../header/endSem.h"
using namespace std;

void checkUserAtLogIn(userList* pHead, user*& curUser)
{
	clearScreen();
	cout << "\t\t\t----------------------------------------------" << endl;
	cout << "\t\t\t|  Welcome to the Course Management System!  |" << endl;
	cout << "\t\t\t----------------------------------------------" << endl
		<< endl;
	cout << "\t\t\tEnter 0 for username to save & exit\n\t\t\tLogging in..." << endl << endl;
	string curUsername;
	string curPassword;
	userList* cur = pHead;
	do
	{
		cout << "\tEnter username: "; cout.flush();
		cin >> curUsername;
		if (curUsername == "0") {
			curUser = nullptr;
			return;
		}
		cout << "\tEnter password: "; cout.flush();
		cin >> curPassword;
		cur = pHead;
		while (cur)
		{
			if (curUsername == cur->data.username && curPassword == cur->data.password)
			{
				cout << "Login successfully!" << endl;
				curUser = &(cur->data);
				return;
			}
			cur = cur->next;
		}
		cout << endl
			<< "\tEither wrong username or password!\n\tPlease re-enter username and password." << endl;
	} while (curUser == nullptr);
}

void startYear(yearList* YearList, schoolYear*& curYear)
{
	clearScreen();
	cout << " ================================================================" << endl;
	cout << " Logged In >> Main Menu >> Possible Actions >> YEAR-START ACTIONS" << endl;
	cout << " ================================================================" << endl;
	int choice = 100;

	while (choice != 0)
	{
		cout << " Actions at the start of the school year: " << endl
			<< endl;
		cout << "\t1. Create a school year" << endl;
		cout << "\t2. Create class for 1st years" << endl;
		cout << "\t3. Add students to 1st-year class" << endl;
		cout << "\t0. Return to Possible Actions"
			<< endl << endl;
		cout << " Your choice: ";
		cin >> choice;
		if (!check(cin)) {
			choice = 100;
			continue;
		}
		switch (choice)
		{
		case 1:
		{
			createSchoolYear(YearList, curYear);
			break;
		}
		case 2:
		{
			createClasses(YearList);
			break;
		}
		case 3:
		{
			int tmp;
			generalClass* c;
			beforeAddStus(c, YearList, tmp);
			if (tmp == 1)
			{
				add1Stu(c);
			}
			else if (tmp == 2)
			{
				addManyStus(c);
			}
			updateStuOfYearsAfter(YearList, curYear);
			break;
		}
		case 0:
		{
			clearScreen();
			cout << " ==============================================================" << endl;
			cout << " Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
			cout << " ==============================================================" << endl;
			return;
		}
		default: {
			cout << "invalid choice, please try again\n";
			break;
		}
		}
	}
}

void changeYearSem(yearList* YearList, schoolYear*& curYear, semester*& curSemester) {
	if (!YearList) {
		cout << " No school year found\n";
		return;
	}
	schoolYear* tmp = curYear;
	yearList* cur = YearList;
	int index = 1;
	while (cur) {
		if (cur->data.start == -1 || cur->data.end == -1)
			break;
		cout << "\t" << index << ". " << cur->data.start << " - " << cur->data.end << endl;
		index++;
		cur = cur->next;
	}
	cout << " Target your new year: ";
	int choice;
	cin >> choice;
	for (int i = 1; i < choice; i++) {
		YearList = YearList->next;
	}
	curYear = &(YearList->data);
	cout << " Change year successfully!\n";
	index = 0;
	if (curYear->sem1)
		cout << "\t" << "Semester 1 can be targeted" << endl;
	if (curYear->sem2)
		cout << "\t" << "Semester 2 can be targeted" << endl;
	if (curYear->sem3)
		cout << "\t" << "Semester 3 can be targeted" << endl;
	if (curYear->sem1 == nullptr && curYear->sem2 == nullptr && curYear->sem3 == nullptr) {
		cout << " No semester found. Year and semester will stay the same.\n";
		curYear = tmp;
		return;
		clearScreen();
		cout << " ==============================================================" << endl;
		cout << " Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
		cout << " ==============================================================" << endl;
	}
	cout << " Target your new semester: ";
	cin >> choice;
	if (choice == 1)
		curSemester = curYear->sem1;
	else if (choice == 2)
		curSemester = curYear->sem2;
	else if (choice == 3)
		curSemester = curYear->sem3;
	else {
		cout << " Invalid choice! Current semester will stay the same.\n";
		return;
	}
	cout << " Change semester successfully!\n";
	clearScreen();
	cout << " ==============================================================" << endl;
	cout << " Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
	cout << " ==============================================================" << endl;
}

void endSem(yearList* YearList, schoolYear* curYear, semester* curSemester)
{
	clearScreen();
	cout << " ==================================================================" << endl;
	cout << " Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
	cout << " ==================================================================" << endl;
	int choice = 100;

	while (choice != 0)
	{
		cout << " Actions at the end of semester: " << endl
			<< endl;
		cout << "\t1. Export list of students from course" << endl;
		cout << "\t2. Import scoreboard of a course" << endl;
		cout << "\t3. View scoreboard of a course" << endl;
		cout << "\t4. Update student's result" << endl;
		cout << "\t5. View scoreboard of a class" << endl;
		cout << "\t0. Return to Possible Actions"
			<< endl << endl;
		cout << " Your choice: ";
		cin >> choice;
		if (!check(cin)) {
			choice = 100;
			continue;
		}
		switch (choice)
		{
		case 1:
		{
			exportStu(curSemester->allCourses);
			break;
		}
		case 2:
		{
			importScoreboard(curSemester->allCourses);
			break;
		}
		case 3:
		{
			viewScoreboard(curSemester);
			break;
		}
		case 4:
		case 5:
		{
			scoreboardOfClass(YearList, curYear, curSemester);
			break;
		}
		case 0:
		{
			clearScreen();
			cout << " ==============================================================" << endl;
			cout << " Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
			cout << " ==============================================================" << endl;
			return;
		}
		}
	}
}

void anyTime(schoolYear* curYear, semester* curSem)
{
	clearScreen();
	cout << " ==============================================================" << endl;
	cout << " Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
	cout << " ==============================================================" << endl;
	int choice = 100;

	while (choice != 0)
	{
		cout << " Actions at any time: " << endl
			<< endl;
		cout << "\t1. View list of classes" << endl;
		cout << "\t2. View list of students in a class" << endl;
		cout << "\t3. View list of courses" << endl;
		cout << "\t4. View list of students in a course" << endl;
		cout << "\t0. Return to Possible Actions" << endl
			<< endl;
		cout << " Your choice: ";
		cin >> choice;
		if (!check(cin)) {
			choice = 100;
			continue;
		}
		switch (choice)
		{
		case 1: {
			viewClass(curYear);
			break;
		}
		case 2: {
			viewStudent(curYear);
			break;
		}
		case 3: {
			viewCourse(curSem);
			break;
		}
		case 4: {
			viewStudentOfACourse(curSem);
			break;
		}
		case 0:
		{
			clearScreen();
			cout << " ==============================================================" << endl;
			cout << " Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
			cout << " ==============================================================" << endl;
			return;
		}
		}
	}
}

void actionsAsStaff(yearList* YearList, schoolYear*& curYear, semester*& curSemester)
{
	clearScreen();
	cout << " ==============================================================" << endl;
	cout << " Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
	cout << " ==============================================================" << endl;
	int choice = 100;

	while (choice != 0)
	{
		cout << " Current year: " << curYear->start << " - " << curYear->end << endl;
		cout << " Current semester: " << curSemester->semesterID << " - start from " << curSemester->startDate.month << "/" << curSemester->startDate.year << endl;
		cout << " Possible actions" << endl
			<< endl;
		cout << "\t1. At the beginning of the school year" << endl;
		cout << "\t2. At the beginning of semester" << endl;
		cout << "\t3. At the end of semester" << endl;
		cout << "\t4. At any time" << endl;
		cout << "\t5. Change current school year and semester" << endl;
		cout << "\t0. Return to Main Menu" << endl
			<< endl;
		cout << " Your choice: ";
		cin >> choice;
		if (!check(cin)) {
			choice = 100;
			continue;
		}
		switch (choice)
		{
		case 1:
		{
			startYear(YearList, curYear);
			break;
		}
		case 2:
		{
			startSem(YearList);
			break;
		}
		case 3:
		{
			endSem(YearList, curYear, curSemester);
			break;
		}
		case 4:
		{
			anyTime(curYear, curSemester);
			break;
		}
		case 5:
		{
			changeYearSem(YearList, curYear, curSemester);
			break;
		}
		case 0:
		{
			clearScreen();
			cout << " ==============================================================" << endl;
			cout << " Logged In >> MAIN MENU" << endl;
			cout << " ==============================================================" << endl;
			return;
		}
		}
	}
}

void actionsAsStudent(user*& curUser, semester* curSemester, schoolYear* curYear)
{
	clearScreen();
	cout << " ==============================================================" << endl;
	cout << " Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
	cout << " ==============================================================" << endl;
	int choice = 100;

	while (choice != 0)
	{
		cout << " Current year: " << curYear->start << " - " << curYear->end << endl;
		cout << " Current semester: " << curSemester->semesterID << " - start from " << curSemester->startDate.month <<"/"<<curSemester->startDate.year << endl;
		cout << " Possible actions: " << endl
			<< endl;
		cout << "\t1. View list of courses" << endl;
		cout << "\t2. View scoreboard" << endl;
		cout << "\t0. Return to Main Menu"
			<< endl << endl;
		cout << " Your choice: ";
		cin >> choice;
		if (!check(cin)) {
			choice = 100;
			continue;
		}
		switch (choice)
		{
		case 1:
		{
			viewCourseInSemesterOfAStudent(curSemester, curUser);
			break;
		}
		case 2:
		{
			printCourseScore(curUser->id, curSemester);
			break;
		}
		case 0:
		{
			clearScreen();
			cout << " ==============================================================" << endl;
			cout << " Logged In >> MAIN MENU" << endl;
			cout << " ==============================================================" << endl;
			return;
		}
		}
	}
}

void menuAfterLogin(user*& curUser, yearList* YearList, semester*& curSemester, schoolYear*& curYear)
{
	clearScreen();
	cout << " ==============================================================" << endl;
	cout << " Logged In >> MAIN MENU" << endl;
	cout << " ==============================================================" << endl;
	int choice = 100;

	while (choice != 0)
	{
		cout << endl
			<< " Hi, " << curUser->username << "!"
			<< endl;
		cout << " Options: " << endl
			<< endl;
		cout << "\t1. View your profile" << endl;
		cout << "\t2. Change password" << endl;
		cout << "\t3. Possible actions" << endl;
		cout << "\t0. Logout" << endl
			<< endl;
		cout << " Your choice: ";
		cin >> choice;
		if (!check(cin)) {
			choice = 100;
			continue;
		}
		switch (choice)
		{
		case 1:
		case 2:
		{
			curUser->changePassword();
			clearScreen();
			cout << " ==============================================================" << endl;
			cout << " Logged In >> MAIN MENU" << endl;
			cout << " ==============================================================" << endl;
			break;
		}
		case 3:
		{
			if (curUser->isStaff)
				actionsAsStaff(YearList, curYear, curSemester);
			else
				actionsAsStudent(curUser, curSemester, curYear);
			break;
		}
		case 0:
		{
			curUser = nullptr;
			return;
		}
		}
	}
}