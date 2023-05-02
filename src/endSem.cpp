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
    cout << "==================================================================" << endl;
    cout << "Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
    cout << "==================================================================" << endl;
}

// 19. Export a list of students in a course to a CSV file
void exportStu(courseList* course)
{
    cout << "List of courses in this semester: " << endl;
    string id;
    
    int index = 1;
    courseList* curCourse = course;
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
    studentList* stu = course->data.enrolledStudents;
    cout << "Enter the file name (including .csv): ";
    string filename;
    cin >> filename;
    ofstream fout(filename);
    if (fout.is_open())
    {
        fout << "No" << ","
             << "Student ID" << ","
             << "First name" << ","
             << "Last name" << ","
             << "Gender" << ","
             << "Date of Birth" << ","
             << "Social ID" << ","
             << "Midterm Mark" << ","
             << "Final Mark" << ","
             << "Other Nark" << ","
             << "Total Mark" << endl;
        int i = 1;
        while (stu)
        {
            fout << i++ << ","
                 << stu->data.id << ","
                 << stu->data.firstName << ","
                 << stu->data.lastName << ",";
            if (stu->data.isFemale) fout << "Female" << ",";
            else fout << "Male" << ",";
            fout << stu->data.birth.day << "/" << stu->data.birth.month << "/" << stu->data.birth.year << ","
                 << stu->data.socialID << ",,,," << endl;
            stu = stu -> next;
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

// 20. Import the scoreboard of a course
void importScoreboard(courseList*& course)
{
    cout << "Enter the ID of the course that you want to import the scoreboard from: ";
    string id;
    scoreList* sc = nullptr;
    courseList* tmp;
    while (!sc)
    {
        cin >> id;
        tmp = course;
        while (tmp && tmp->data.id != id)
            tmp = tmp -> next;
        if (!tmp) cout << "No such course exists. Please enter another course ID: ";
        else
        {
            sc = tmp -> data.scoreboard;
            break;
        } 
    }
    cout << "Enter the name of the csv file that you want to import: ";
    string filename;
    cin >> filename;
    ifstream fin(filename);
    if (fin.is_open())
    {
        string line;
        getline(fin, line); // read and discard the first line of the file
        while (getline(fin, line))
        {
            stringstream ss(line);
            student stu;
            char comma;
            int num;
            ss >> num >> comma >> stu.id >> comma >> stu.firstName >> comma >> stu.lastName >> comma >> stu.isFemale >> comma
               >> stu.birth.day >> comma >> stu.birth.month >> comma >> stu.birth.year >> comma >> stu.socialID >> comma;
            sc->data.id = stu.id;
            sc->data.fullname = stu.lastName + " " + stu.firstName;
            ss >> sc->data.midterm >> comma
               >> sc->data.finalMark >> comma
               >> sc->data.other >> comma
               >> sc->data.total;
        }
        fin.close();
        cout << "Imported successfully!" << endl;
        returnDefault();
    }
    else
    {
        cout << "Could not open the file" << endl;
        returnDefault();
    }
}

//21. View a scoreboard of a course
void viewScoreboard(semester* curSem) {
    	cout << "List of courses in this semester: " << endl;
	string id;
	
	int index = 1;
	courseList* curCourse = curSem->allCourses;
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
		curSem->allCourses = curSem->allCourses->next;
	}
	scoreList* sc = curSem->allCourses->data.scoreboard;
	cout << "No" << "\t"
		 << "Student ID" << "\t"
		 << "Full name" << "\t"
		 << "Midterm" << "\t"
		 << "Final" << "\t"
		 << "Other" << "\t"
		 << "Total" << endl;
	int i = 1;
    while (sc)
    {
		cout << i++ << "\t"
			 << sc->data.id << "\t"
			 << sc->data.fullname << "\t"
			 << sc->data.midterm << "\t"
			 << sc->data.finalMark << "\t"
			 << sc->data.other << "\t"
			 << sc->data.total << endl;
		sc = sc->next;
	}
	returnDefault();
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
            studentList *enrolledInThisCourse = courseInSem->data.enrolledStudents;
            mark *tmp = nullptr;

            // traverse the list of learners of the course to find the target student
            while (enrolledInThisCourse)
            {
                if (enrolledInThisCourse->data.id == curStudentOnList->id)
                {
                    mark *newMark = new mark;
                    newMark->courseName = courseInSem->data.courseName;
                    newMark->value = courseInSem->data.scoreboard->data.finalMark;
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
        allScores += list->value;
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
                            total += curStudent->data.finalMark * courseInSem->data.credit;
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

    cout << "total: " << total << endl;
    cout << "credits: " << totalCredits << endl;

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
    while (cur1)
    {
        cout << i << ". " << cur2->data.lastName << " " << cur2->data.firstName << endl
             << "\tID: " << cur2->data.id << endl;
        mark *curMark = cur1->markOfCourses;
        while (curMark)
        {
            cout << "\t" << curMark->courseName << ": " << curMark->value << endl;
            if (curMark->nextCourse)
                curMark = curMark->nextCourse;
            else
                break;
        }
        cout << "\tGPA this semester: " << setprecision(2) << fixed << gpaThisSem(cur1) << endl;
        cout << "\tOverall GPA: " << setprecision(2) << fixed << gpaOverall(cur1, YearList) << endl;

        if (cur2->next)
        {
            cur2 = cur2->next;
            i++;
        }
        else
            break;
    }

    return;
}
//the unfinished version
void scoreboardOfClass(yearList *YearList, schoolYear *curYear, semester *curSemester)
{
    // Find the class
    string inputClass;
    bool foundClass = false;

    if (!curYear->allClasses)
	{
		cout << "No class found!" << endl;
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
	cout << "Enter the class whose scoreboard you want to view: ";
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

    int x = 1;
    while (x != 0)
    {
        cout << endl << "Done viewing? Enter 0 to exit: ";
        cin >> x;
        if (!check(cin))
        {
            x = 1;
            continue;
        }
    }

    if (x == 0)
    {
        clearScreen();
            cout << "==================================================================" << endl;
            cout << "Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
            cout << "==================================================================" << endl;
            return;
    }
}
//current working on this version
void scoreboardOfClass2(yearList* YearList, schoolYear* curYear, semester* curSemester) {
    
}
