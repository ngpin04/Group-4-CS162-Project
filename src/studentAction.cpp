#include "../header/studentAction.h"
#include "../header/console.h"
#include <iostream>
#include <iomanip>

using namespace std;

// print score of a single semester
void printCourseScore(string userID, semester *s)
{
    courseList *availCourses = s->allCourses;

    while (availCourses)
    {
        studentList *enrolledStd = availCourses->data.enrolledStudents;
        scoreList *scoreboard = availCourses->data.scoreboard;

        while (enrolledStd)
        {
            bool resultsReleased = availCourses->data.resultsReleased;

            if (enrolledStd->data.id == userID)
            {
                cout << "| " << left << setw(10) << availCourses->data.id
                     << " | " << left << setw(50) << availCourses->data.courseName
                     << " | " << left << setw(10) << availCourses->data.credit;

                if (!resultsReleased)
                {
                    cout << left << "Results not released." << endl;
                }
                else
                {
                    cout << " | " << left << setw(10) << scoreboard->data.total
                         << " | " << left << setw(10) << scoreboard->data.midterm
                         << " | " << left << setw(10) << scoreboard->data.finalMark
                         << " | " << left << setw(10) << scoreboard->data.other << " |" << endl;
                }
            }
            else
            {
                enrolledStd = enrolledStd->next;
                scoreboard = scoreboard->next;
            }
        }
        availCourses = availCourses->next;
    }

    return;
}

// gets school year from ID and retrieves scores of all 3 semesters
void viewScoreboard(user *curUser, yearList *YearList)
{
    string userYear = (curUser->id).substr(0, 2);

    while (YearList)
    {
        string curYear = to_string(YearList->data.start % 100);
        if (userYear == curYear)
        {
            semester *s[3] = {YearList->data.sem1, YearList->data.sem2, YearList->data.sem3};

            for (int i = 0; i < 3; i++)
            {
                bool scorePublished = s[i]->scorePublished;

                if (scorePublished)
                {
                    cout << "                                                      SCOREBOARD OF SEMESTER " << i + 1 << "                                                      " << endl;
                    cout << "+----------------------------------------------------------------------------------------------------------------------------------+" << endl;
                    cout << "| " << left << setw(10) << "COURSE ID"
                         << " | " << left << setw(50) << "COURSE NAME"
                         << " | " << left << setw(10) << "CREDITS"
                         << " | " << left << setw(10) << "TOTAL"
                         << " | " << left << setw(10) << "MIDTERM"
                         << " | " << left << setw(10) << "FINAL"
                         << " | " << left << setw(10) << "OTHER" << " |" << endl;
                    cout << "+----------------------------------------------------------------------------------------------------------------------------------+" << endl;

                    printCourseScore(curUser->id, s[i]);
                    cout << "+----------------------------------------------------------------------------------------------------------------------------------+" << endl << endl;
                }
                else
                    cout << "The results of semester " << i + 1 << " has not been published." << endl;
            }
        }
        else
            YearList = YearList->next;
    }
}

//14. View a list of his/her courses. He/she will study these courses in this semester.
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
