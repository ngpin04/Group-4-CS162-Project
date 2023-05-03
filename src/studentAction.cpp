#include "../header/studentAction.h"
#include "../header/console.h"
#include <iostream>
#include <iomanip>
using namespace std;

// print score of a single semester
void printCourseScore(string userID, semester *s)
{
    courseList *availCourses = s->allCourses;
    int index = 1;

    while (availCourses)
    {
        studentList *enrolledStd = availCourses->data.enrolledStudents;
        scoreList *scoreboard = availCourses->data.scoreboard;

        while (enrolledStd)
        {
            bool resultsReleased = availCourses->data.resultsReleased;

            if (enrolledStd->data.id == userID)
            {
                cout << "| " << left << setw(7) << index << ". "
                     << " | " << left << setw(10) << availCourses->data.id
                     << " | " << left << setw(50) << availCourses->data.courseName
                     << " | " << left << setw(7) << availCourses->data.credit << " | ";

                if (!resultsReleased)
                {
                    cout << left << "Results not released." << endl;
                }
                else
                {
                    cout << left << setw(7) << scoreboard->data.total
                         << " | " << left << setw(7) << scoreboard->data.midterm
                         << " | " << left << setw(7) << scoreboard->data.finalMark
                         << " | " << left << setw(7) << scoreboard->data.other << " |" << endl;
                }
            }

            enrolledStd = enrolledStd->next;
            scoreboard = scoreboard->next;
            index++;
        }

        availCourses = availCourses->next;
    }

    return;
}

// 24. View his/her scoreboard (retrieves school year and calls print function)
void viewScoreboard(user *curUser, yearList *YearList)
{
    string userYear = (curUser->id).substr(0, 2);

    while (YearList)
    {
        string curYear = to_string(YearList->data.start % 100);
        if (userYear == curYear)
        {
            semester *s[3] = {YearList->data.sem1, YearList->data.sem2, YearList->data.sem3};

            int curSem;
            cout << "Enter current semester: ";
            cin >> curSem;

            while (curSem != 1 && curSem != 2 && curSem != 3)
            {
                cout << "Invalid semester. Please try again: ";
                cin >> curSem;
            }

            bool scorePublished = s[curSem - 1]->scorePublished;

            if (scorePublished)
            {
                cout << "                                                  SCOREBOARD OF SEMESTER " << curSem << "                                                  " << endl;
                cout << "+--------------------------------------------------------------------------------------------------------------------------+" << endl;
                cout << "| " << left << setw(7) << "NUMBER"
                     << " | " << left << setw(10) << "COURSE ID"
                     << " | " << left << setw(50) << "COURSE NAME"
                     << " | " << left << setw(7) << "CREDITS"
                     << " | " << left << setw(7) << "TOTAL"
                     << " | " << left << setw(7) << "MIDTERM"
                     << " | " << left << setw(7) << "FINAL"
                     << " | " << left << setw(7) << "OTHER"
                     << " |" << endl;
                cout << "+--------------------------------------------------------------------------------------------------------------------------+" << endl;

                printCourseScore(curUser->id, s[curSem - 1]);
                cout << "+--------------------------------------------------------------------------------------------------------------------------+" << endl
                     << endl;
            }

            else
                cout << "The results of semester " << curSem << " has not been published." << endl;
        }

        else
            YearList = YearList->next;
    }

    string x;
    cout << "Done viewing? Enter any character to exit: " << endl;
    cin >> x;
    clearScreen();
    cout << "==============================================================" << endl;
    cout << "Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
    cout << "==============================================================" << endl;
    return;
}

// 14. View a list of his/her courses. He/she will study these courses in this semester.
void viewCourseInSemesterOfAStudent(semester *curSemester, user *curUser)
{
    courseList *curCourse = curSemester->allCourses;
    if (curCourse == nullptr)
    {
        cout << "There is no course in this semester." << endl;
        cout << "Enter any character to continue: ";
        string count;
        cin >> count;
        clearScreen();
        cout << "==============================================================" << endl;
        cout << "Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
        cout << "==============================================================" << endl;
        return;
    }
    int count = 0;
    while (curCourse)
    {
        studentList *curStudent = curCourse->data.enrolledStudents;
        while (curStudent)
        {
            if (curStudent->data.id == curUser->id)
            {
                count++;
                cout << count << ". " << curCourse->data.id
                     << " - " << curCourse->data.courseName << endl;
                break;
            }
            curStudent = curStudent->next;
        }
        curCourse = curCourse->next;
    }
    cout << "Enter any character to continue: ";
    string temp;
    cin >> temp;
    clearScreen();
    cout << "==============================================================" << endl;
    cout << "Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
    cout << "==============================================================" << endl;
    return;
}
