#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "../header/console.h"
#include "../header/course.h"
#include "../header/endSem.h"
using namespace std;

void returnDefault()
{
	cout << "Enter any character to continue: ";
	string tmp;
	cin >> tmp;
	clearScreen();
	cout << " ==================================================================" << endl;
	cout << " Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
	cout << " ==================================================================" << endl;
}

// 19. Export a list of students in a course to a CSV file
void exportStu(courseList *course)
{

	cout << "List of courses in this semester: " << endl;
	string id;

	int index = 1;
	courseList *curCourse = course;
	while (curCourse)
	{
		cout << "\t" << index << ". " << curCourse->data.id << " - " << curCourse->data.className << endl;
		index++;
		curCourse = curCourse->next;
	}
	cout << "Enter the number of the class you want to target: ";
	int choice;
	cin >> choice;
	for (int i = 1; i < choice; i++)
	{
		course = course->next;
	}
	studentList *stu = course->data.enrolledStudents;
	cout << "Enter the file name (including .csv): ";
	string filename;
	cin >> filename;
	ofstream fout(filename);
	if (fout.is_open())
	{
		fout << "No"
			 << ","
			 << "Student ID"
			 << ","
			 << "First name"
			 << ","
			 << "Last name"
			 << ","
			 << "Gender"
			 << ","
			 << "Date of Birth"
			 << ","
			 << "Social ID"
			 << ","
			 << "Midterm Mark"
			 << ","
			 << "Final Mark"
			 << ","
			 << "Other Nark"
			 << ","
			 << "Total Mark" << endl;
		int i = 1;
		while (stu)
		{
			fout << i++ << ","
				 << stu->data.id << ","
				 << stu->data.firstName << ","
				 << stu->data.lastName << ",";
			if (stu->data.isFemale)
				fout << "Female"
					 << ",";
			else
				fout << "Male"
					 << ",";
			fout << stu->data.birth.day << "/" << stu->data.birth.month << "/" << stu->data.birth.year << ","
				 << stu->data.socialID << ",,,," << endl;
			stu = stu->next;
		}
		fout.close();
		cout << "Exported successfully!" << endl;
		returnDefault();
	}
	else
	{
		cout << "Could not create the file" << endl;
		returnDefault();
	}
}

double toDouble(const string &str)
{

	if (str == "" || str == " ")
		return 0.0;
	double result = 0.0;
	double factor = 1.0;
	bool decimal = false;
	for (char c : str)
	{
		if (c == '.')
			decimal = true;
		else if (c >= '0' && c <= '9')
		{
			if (decimal)
			{
				factor *= 0.1;
				result += factor * (c - '0');
			}
			else
				result = 10.0 * result + (c - '0');
		}
	}
	return result;
}

// 20. Import the scoreboard of a course
void importScoreboard(courseList *&course)
{

	cout << " List of courses in this semester: " << endl;
	string id;

	int index = 1;
	courseList *curCourse = course;
	while (curCourse)
	{
		cout << "\t" << index << ". " << curCourse->data.id << " - " << curCourse->data.className << endl;
		index++;
		curCourse = curCourse->next;
	}
	cout << " Enter the number of the class you want to target: ";
	int choice;
	cin >> choice;
	for (int i = 1; i < choice; i++)
	{
		course = course->next;
	}
	scoreList *sc = course->data.scoreboard;
	cout << " Enter the file name (including .csv): ";
	string filename;
	cin >> filename;
	ifstream fin(filename);
	if (fin.is_open())
	{
		string line, word;
		getline(fin, line); // read and discard the first line of the file
		while (getline(fin, line))
		{
			student stu;
			stringstream str(line);
			getline(str, word, ','); // no
			getline(str, word, ',');

			sc->data.id = word;

			getline(str, word, ',');
			stu.firstName = word;
			getline(str, word, ',');
			stu.lastName = word;

			sc->data.fullname = stu.lastName + " " + stu.firstName;

			getline(str, word, ','); // gender
			getline(str, word, ','); // date of birth
			getline(str, word, ','); // social ID

			getline(str, word, ',');
			sc->data.midterm = toDouble(word);
			getline(str, word, ',');
			sc->data.finalMark = toDouble(word);
			getline(str, word, ',');
			sc->data.other = toDouble(word);
			getline(str, word, ',');
			sc->data.total = toDouble(word);
			if (fin.peek() != EOF)
			{
				sc->next = new scoreList;
				sc = sc->next;
			}
			else
				sc->next = nullptr;
		}
		fin.close();
		course->data.resultsReleased = true;
		cout << " Imported successfully!" << endl;
		returnDefault();
	}
	else
	{
		cout << " Could not open the file" << endl;
		returnDefault();
	}
}

// 21. View a scoreboard of a course
void viewScoreboard(semester *curSem)
{
	if (curSem->allCourses == nullptr)
	{
		cout << " There is no course in this semester" << endl;
		returnDefault();
	}
	cout << " List of courses in this semester: " << endl;
	int index = 1;
	courseList *curCourse = curSem->allCourses;
	while (curCourse)
	{
		cout << "\t" << index << ". " << curCourse->data.id << " - " << curCourse->data.className << endl;
		index++;
		curCourse = curCourse->next;
	}
	cout << " Enter the number of the class you want to target: ";
	int choice;
	cin >> choice;
	curCourse = curSem->allCourses;
	for (int i = 1; i < choice; i++)
	{
		curCourse = curCourse->next;
	}
	if (curCourse->data.enrolledStudents == nullptr || curCourse->data.scoreboard == nullptr)
	{
		cout << " Either the course has no student or the scoreboard has not been imported yet!" << endl;
		cout << " Enter any character to continue: ";
		string temp;
		cin >> temp;
		clearScreen();
		cout << " ==================================================================" << endl;
		cout << " Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
		cout << " ==================================================================" << endl;
		return;
	}
	scoreList *sc = curCourse->data.scoreboard;
	cout << "\t--------------------------------------------------------------------------------" << endl;
	cout << "\t No |    ID    | Full name\t\t\t|  Mid  | Final | Other | Total " << endl;
	cout << "\t--------------------------------------------------------------------------------" << endl;
	int i = 1;
	while (sc)
	{
		cout << "\t " << setw(2) << i++ << " | " << setw(8) << sc->data.id << " | "
			 << sc->data.fullname;
		for (int i = 0; i < 30 - sc->data.fullname.length(); i++)
			cout << " ";
		cout << " | " << setw(5) << sc->data.midterm << " | "
			 << setw(5) << sc->data.finalMark << " | "
			 << setw(5) << sc->data.other << " | "
			 << setw(5) << sc->data.total << endl;
		sc = sc->next;
	}
	returnDefault();
}

// 22. Update a student's result
void chooseCourse(schoolYear *curYear, semester *curSemester, courseList *&thisCourse)
{
	cout << "*" << endl
		 << "School year: " << curYear->start << "-" << curYear->end << endl
		 << "Semester: " << curSemester->semesterID << endl
		 << "*" << endl
		 << endl;

	cout << "All courses of semester " << curSemester->semesterID
		 << ", year " << curYear->start << "-" << curYear->end << endl;
	cout << "---------------------------------------------------------" << endl
		 << endl;
	courseList *coursesThisSem = curSemester->allCourses;
	thisCourse = coursesThisSem;

	int i = 1;
	while (coursesThisSem)
	{
		cout << i++ << ". " << coursesThisSem->data.id << " | "
			 << coursesThisSem->data.courseName << " | "
			 << coursesThisSem->data.className << endl;
		coursesThisSem = coursesThisSem->next;
	}

	int choice = -1;
	while (choice != 0)
	{
		cout << "Please choose a course by index, or 0 to exit: ";
		cin >> choice;
		if (!check(cin))
		{
			choice = -1;
			continue;
		}
		if (choice >= 1 && choice <= i)
			break;
		if (choice == 0)
		{
			clearScreen();
			cout << " ==================================================================" << endl;
			cout << " Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
			cout << " ==================================================================" << endl;
			return;
		}
	}

	for (int i = 0; i < choice; i++)
	{
		thisCourse = thisCourse->next;
	}

	return;
}

void chooseStudent(schoolYear *curYear, semester *curSemester, courseList *thisCourse, scoreList *&thisStudent)
{
	clearScreen();
	cout << "*" << endl
		 << "School year: " << curYear->start << "-" << curYear->end << endl
		 << "Semester: " << curSemester->semesterID << endl
		 << "Current course: " << thisCourse->data.courseName << endl
		 << "Course ID: " << thisCourse->data.id << endl
		 << "*" << endl
		 << endl;

	cout << "All students of course " << thisCourse->data.id << ", class " << thisCourse->data.className << endl;
	cout << "---------------------------------------------------------" << endl
		 << endl;

	scoreList *allStudents = thisCourse->data.scoreboard;
	thisStudent = allStudents;

	int i = 1;
	while (allStudents)
	{
		cout << i++ << ". " << allStudents->data.id << " | " << allStudents->data.fullname << endl;
		allStudents = allStudents->next;
	}
	int choice = -1;
	while (choice != 0)
	{
		cout << "Please choose a student by index, or 0 to choose another course: ";
		cin >> choice;
		if (!check(cin))
		{
			choice = -1;
			continue;
		}
		if (choice >= 1 && choice <= i)
			break;
		if (choice == 0)
		{
			clearScreen();
			chooseCourse(curYear, curSemester, thisCourse);
			return;
		}
	}

	for (int i = 0; i < choice; i++)
		thisStudent = thisStudent->next;
	
	return;
}

void updateMark(schoolYear *curYear, semester *curSemester, courseList *thisCourse, scoreList *&thisStudent)
{
	clearScreen();
	cout << "*" << endl
		 << "School year: " << curYear->start << "-" << curYear->end << endl
		 << "Semester: " << curSemester->semesterID << endl
		 << "Current course: " << thisCourse->data.courseName << endl
		 << "Course ID: " << thisCourse->data.id << endl
		 << "Current student: " << thisStudent->data.fullname << endl
		 << "Student ID: " << thisStudent->data.id << endl
		 << "*" << endl
		 << endl;

	cout << "Scoreboard of student " << thisStudent->data.id << endl;
	cout << "---------------------------------------------------------" << endl
		 << endl;

	int i = 1;
	cout << i++ << ". Midterm: " << thisStudent->data.midterm << endl
		 << i++ << ". Final: " << thisStudent->data.finalMark << endl
		 << i++ << ". Other: " << thisStudent->data.other << endl
		 << i++ << ". Total: " << thisStudent->data.total << endl;

	int choice = -1;
	while (choice != 0)
	{
		cout << "Please choose a mark to update by index, or 0 to return: ";
		cin >> choice;
		if (!check(cin))
		{
			choice = -1;
			continue;
		}
		if (choice >= 1 && choice <= i)
		{
			double *ptr = nullptr;
			cout << endl << "You've chosen to update this student's ";
			switch (choice)
			{
				case 1:
				{
					cout << "midterm mark." << endl;
					ptr = &thisStudent->data.midterm;
					cout << "Current midterm: " << *ptr << endl;
					break;
				}
				case 2:
				{
					cout << "final mark." << endl;
					ptr = &thisStudent->data.finalMark;
					cout << "Current final: " << *ptr << endl;
					break;
				}
				case 3:
				{
					cout << "other mark." << endl;
					ptr = &thisStudent->data.other;
					cout << "Current other: " << *ptr << endl;
					break;
				}
				case 4:
				{
					cout << "total mark." << endl;
					ptr = &thisStudent->data.total;
					cout << "Current total: " << *ptr << endl;
					break;
				}
			}

			double newMark;
			cout << "Enter the new value: ";
			cin >> newMark;
			*ptr = newMark;
			cout << endl << "Mark updated successfully." << endl << endl;

			string x;
			cout << "Still need to update? (y/n) - ";
			cin >> x;
			if (x == "y")
			{
				cout << "Enter 1-4 to continue updating this student's result" << endl
					 << "Enter 0 to choose another student" << endl;
				cin >> choice;
			}
			if (x == "n")
			{
				clearScreen();
				cout << " ==================================================================" << endl;
				cout << " Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
				cout << " ==================================================================" << endl;
				return;
			}
		}
		if (choice == 0)
		{
			clearScreen();
			chooseStudent(curYear, curSemester, thisCourse, thisStudent);
			return;
		}
	}

	return;
}

void chooseToUpdate(schoolYear *curYear, semester *curSemester)
{
	courseList *thisCourse = nullptr;
	chooseCourse(curYear, curSemester, thisCourse);

	scoreList *thisStudent = nullptr;
	chooseStudent(curYear, curSemester, thisCourse, thisStudent);

	updateMark(curYear, curSemester, thisCourse, thisStudent);
	return;
}

// 23. View the scoreboard of a class, including final marks of all courses in the semester,
// GPA in this semester, and the total GPA

void getAllIDs(classScores *&scoresOfClass, studentList *studentsOfClass)
{
	classScores *cur = nullptr;

	while (studentsOfClass)
	{
		classScores *newStd = new classScores;
		newStd->id = studentsOfClass->data.id;
		if (!scoresOfClass)
		{
			scoresOfClass = newStd;
			cur = scoresOfClass;
		}
		else
		{
			cur->nextStd = newStd;
			cur = cur->nextStd;
		}

		studentsOfClass = studentsOfClass->next;
	}

	return;
}

void getMarksFromCourses(classScores *&scoresOfClass, semester *curSemester)
{

	classScores *curStudentOnList = scoresOfClass;

	while (curStudentOnList)
	{
		courseList *courseInSem = curSemester->allCourses;

		// traverse the list of courses in this semester
		while (courseInSem)
		{
			scoreList *enrolledInThisCourse = courseInSem->data.scoreboard;
			mark *tmp = nullptr;

			// traverse the list of learners of the course to find the target student
			while (enrolledInThisCourse)
			{
				if (enrolledInThisCourse->data.id == curStudentOnList->id)
				{
					mark *newMark = new mark;
					newMark->courseName = courseInSem->data.courseName;
					newMark->value = enrolledInThisCourse->data.total;
					newMark->credits = courseInSem->data.credit;

					// Array of marks (of this student) is empty
					if (!curStudentOnList->markOfCourses)
					{
						curStudentOnList->markOfCourses = newMark;
						tmp = curStudentOnList->markOfCourses;
					}
					else
					{
						tmp->nextCourse = newMark;
						tmp = tmp->nextCourse;
					}

					break;
				}

				enrolledInThisCourse = enrolledInThisCourse->next;
			}

			courseInSem = courseInSem->next;
		}

		curStudentOnList = curStudentOnList->nextStd;
	}

	return;
}

double gpaThisSem(classScores *curStudent)
{
	double allScores = 0.00;
	int totalCredits = 0;
	double gpa = 0.00;

	mark *list = curStudent->markOfCourses;
	while (list)
	{
		allScores += list->value * list->credits;
		totalCredits += list->credits;
		list = list->nextCourse;
	}

	gpa = allScores / totalCredits;
	return gpa;
}

double gpaOverall(classScores *scoresOfClass, yearList *YearList)
{

	yearList *thisYear = YearList;
	string currentID = scoresOfClass->id;
	double total = 0.00;
	int totalCredits = 0;
	double gpa = 0.00;

	// each year
	while (thisYear)
	{
		semester *s[3] = {thisYear->data.sem1, thisYear->data.sem2, thisYear->data.sem3};

		for (int i = 0; i < 3; i++)
		{
			// each semester
			if (s[i])
			{
				courseList *courseInSem = s[i]->allCourses;

				// all courses in 1 semester
				while (courseInSem)
				{
					scoreList *curStudent = courseInSem->data.scoreboard;

					// find the student in each course
					while (curStudent)
					{
						if (curStudent->data.id == currentID)
						{
							total += curStudent->data.total * courseInSem->data.credit;
							totalCredits += courseInSem->data.credit;
							break;
						}

						curStudent = curStudent->next;
					}

					courseInSem = courseInSem->next;
				}
			}
		}

		thisYear = thisYear->next;
	}

	gpa = total / totalCredits;
	return gpa;
}

void printClassScoreboard(yearList *YearList, classScores *scoresOfClass, classList *curClass)
{

	clearScreen();
	cout << "\t\t | SCOREBOARD OF CLASS " << curClass->data.name << " | \t\t" << endl;

	classScores *cur1 = scoresOfClass;
	studentList *cur2 = curClass->data.studentHead;
	int i = 1;

	if (!cur1)
		cout << "There is no score to display." << endl;

	while (cur1 && cur2)
	{
		cout << i << ". " << cur2->data.lastName << " " << cur2->data.firstName << endl
			 << "\tID: " << cur2->data.id << endl;
		mark *curMark = cur1->markOfCourses;
		while (curMark)
		{
			cout << "\t" << curMark->courseName << ": " << setprecision(2) << fixed << curMark->value << endl;
			curMark = curMark->nextCourse;
		}
		cout << "\tGPA this semester: " << setprecision(2) << fixed << gpaThisSem(cur1) << endl;
		cout << "\tOverall GPA: " << setprecision(2) << fixed << gpaOverall(cur1, YearList) << endl;
		cout << "------------------------------------------------------------------------------------------" << endl;

		cur1 = cur1->nextStd;
		cur2 = cur2->next;
		i++;
	}

	return;
}

void scoreboardOfClass(yearList *YearList, schoolYear *curYear, semester *curSemester)
{
	// Find the class
	string inputClass;
	bool foundClass = false;

	if (!curYear->allClasses)
	{
		cout << " No class found!" << endl;
		cout << " Enter any character to continue: ";
		string temp;
		cin >> temp;
		clearScreen();
		cout << " ==============================================================" << endl;
		cout << " Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
		cout << " ==============================================================" << endl;
		return;
	}

	classList *curClass = curYear->allClasses;
	int index = 1;
	while (curClass)
	{
		cout << "\t" << index << ". " << curClass->data.name << endl;
		index++;
		curClass = curClass->next;
	}
	cout << " Enter the class whose scoreboard you want to view: ";
	int choice;
	cin >> choice;

	curClass = curYear->allClasses;
	for (int i = 1; i < choice; i++)
	{
		curClass = curClass->next;
	}

	// Get all student IDs of the class
	classScores *scoresOfClass = nullptr;
	studentList *studentsOfClass = curClass->data.studentHead;
	getAllIDs(scoresOfClass, studentsOfClass);

	getMarksFromCourses(scoresOfClass, curSemester);
	printClassScoreboard(YearList, scoresOfClass, curClass);

	string x;
	cout << "Done viewing? Enter any character to exit: ";
	cin >> x;

	clearScreen();
	cout << "==================================================================" << endl;
	cout << "Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
	cout << "==================================================================" << endl;
	return;
}
// // current working on this version
// void scoreboardOfClass2(yearList *YearList, schoolYear *curYear, semester *curSemester)
// {
// 	if (!curYear->allClasses)
// 	{
// 		cout << "No class found in this current year!" << endl;
// 		cout << "Enter any character to continue: ";
// 		string temp;
// 		cin >> temp;
// 		clearScreen();
// 		cout << "==============================================================" << endl;
// 		cout << "Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
// 		cout << "==============================================================" << endl;
// 		return;
// 	}
// }
