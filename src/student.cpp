#pragma once;
#include <string>
#include <iomanip>
#include "../header/user.h";
#include "../header/schoolYear.h";

void printCourseScore(user *curUser, semester *s)
{
    bool scoreAvailable = false; // check if there is any score to display
    courseList *availCourses = s->allCourses;

    while (availCourses)
    {
        studentList *enrolledStd = availCourses->data.enrolledStudents;
        scoreList *scoreboard = availCourses->data.scoreboard;

        while (enrolledStd)
        {
            if (enrolledStd->data.id == curUser->id)
            {
                if (!scoreAvailable) scoreAvailable = true;

                cout << left << setw(10) << availCourses->data.id
                     << left << setw(15) << availCourses->data.courseName
                     << left << setw(10) << availCourses->data.credit;

                while (scoreboard)
                {
                    if (scoreboard->data.id == curUser->id)
                    {
                        cout << left << setw(10) << scoreboard->data.total
                             << left << setw(10) << scoreboard->data.midterm
                             << left << setw(10) << scoreboard->data.finalMark
                             << left << setw(10) << scoreboard->data.other << endl;
                        break;
                    }
                    else scoreboard = scoreboard->next;
                }
            }
            else enrolledStd = enrolledStd->next;
        }
        availCourses = availCourses->next;
    }

    if (!scoreAvailable) // meaning student is in system but did not participate in any courses
        cout << "There's no score to view." << endl;
    
    return;
}

void viewScoreboard(user *curUser, yearList *YearList)
{
    string userYear = to_string(curUser->id).substr(0, 2);
    string finished = "n";

    while (YearList)
    {
        string curYear = to_string(YearList->data.start % 100);
        if (userYear == curYear)
        {
            while (finished != "y")
            {
                int sem;
                cout << "Select a semester: ";
                cin >> sem;

                semester* s = nullptr;
                if (sem == 1)
                    s = YearList->data.sem1;
                if (sem == 2)
                    s = YearList->data.sem2;
                if (sem == 3)
                    s = YearList->data.sem2;

                bool scorePublished = s->scorePublished;

                if (scorePublished)
                {
                    cout << "SCOREBOARD OF SEMESTER " << sem << ": " << endl;
                    cout << left << setw(10) << "COURSE ID"
                         << left << setw(15) << "COURSE NAME"
                         << left << setw(10) << "CREDITS"
                         << left << setw(10) << "TOTAL"
                         << left << setw(10) << "MIDTERM"
                         << left << setw(10) << "FINAL"
                         << left << setw(10) << "OTHER";
                    cout << "-----------------------------------------------------------------------------------------------" << endl;

                    printCourseScore(curUser, s);
                }
                else
                    cout << "The results of this semester has not been published yet." << endl;
                }
            
                cout << "Finished viewing? (y/n) ";
                cin >> finished;
        }
        else YearList = YearList->next;
    }

    return;
}
