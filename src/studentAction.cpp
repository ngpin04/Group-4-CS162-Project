#include "../header/studentAction.h"
#include "../header/console.h"
#include <iostream>
#include <iomanip>
using namespace std;

// print score of a single semester
// void printCourseScore(string userID, semester *s)
// {
//     courseList *availCourses = s->allCourses;
//     int index = 1;

//     while (availCourses)
//     {
//         studentList *enrolledStd = availCourses->data.enrolledStudents;
//         scoreList *scoreboard = availCourses->data.scoreboard;

//         while (enrolledStd)
//         {
//             bool resultsReleased = availCourses->data.resultsReleased;

//             if (enrolledStd->data.id == userID)
//             {
//                 cout << "| " << left << setw(7) << index << ". "
//                      << " | " << left << setw(10) << availCourses->data.id
//                      << " | " << left << setw(50) << availCourses->data.courseName
//                      << " | " << left << setw(7) << availCourses->data.credit << " | ";

//                 if (!resultsReleased)
//                 {
//                     cout << left << "Results not released." << endl;
//                 }
//                 else
//                 {
//                     cout << left << setw(7) << scoreboard->data.total
//                          << " | " << left << setw(7) << scoreboard->data.midterm
//                          << " | " << left << setw(7) << scoreboard->data.finalMark
//                          << " | " << left << setw(7) << scoreboard->data.other << " |" << endl;
//                 }
//             }

//             enrolledStd = enrolledStd->next;
//             scoreboard = scoreboard->next;
//             index++;
//         }

//         availCourses = availCourses->next;
//     }

//     return;
// }

// 24. View his/her scoreboard (retrieves school year and calls print function)
void viewScoreboard(user *curUser, semester *curSemester)
{
    bool scorePublished = curSemester->scorePublished;

    // if (scorePublished)
    // {
    //     cout << "                                                  SCOREBOARD OF SEMESTER " << curSemester->semesterID << "                                                  " << endl;
    //     cout << "+--------------------------------------------------------------------------------------------------------------------------+" << endl;
    //     cout << "| " << left << setw(7) << "NUMBER"
    //          << " | " << left << setw(10) << "COURSE ID"
    //          << " | " << left << setw(50) << "COURSE NAME"
    //          << " | " << left << setw(7) << "CREDITS"
    //          << " | " << left << setw(7) << "TOTAL"
    //          << " | " << left << setw(7) << "MIDTERM"
    //          << " | " << left << setw(7) << "FINAL"
    //          << " | " << left << setw(7) << "OTHER"
    //          << " |" << endl;
    //     cout << "+--------------------------------------------------------------------------------------------------------------------------+" << endl;

    //     printCourseScore(curUser->id, curSemester);
    //     cout << "+--------------------------------------------------------------------------------------------------------------------------+" << endl
    //          << endl;
    // }

    cout << "\t----------------------------------------------------------------------------------------------------" << endl;
    cout << "\t No |    Course ID    | Course name\t\t\t|  Credits  |  Mid  | Final | Other | Total " << endl;
    cout << "\t----------------------------------------------------------------------------------------------------" << endl;
    int i = 1;
    
    if (scorePublished)
    {
        courseList *availCourses = curSemester->allCourses;

        while (availCourses)
        {
            scoreList *scoreboard = availCourses->data.scoreboard;

            while (scoreboard)
            {
                if (scoreboard->data.id == curUser->id)
                {
                    cout << "\t " << setw(2) << i++ << " | " << setw(8) << availCourses->data.id << " | "
                         << availCourses->data.courseName;
                    for (int i = 0; i < 30 - availCourses->data.courseName.length(); i++)
                        cout << " ";
                    cout << " | " << setw(5) << availCourses->data.credit << " | "
                         << setw(5) << scoreboard->data.midterm << " | "
                         << setw(5) << scoreboard->data.finalMark << " | "
                         << setw(5) << scoreboard->data.other << " | "
                         << setw(5) << scoreboard->data.total << endl;
                    
                    break;
                }

                scoreboard = scoreboard->next;
            }

            availCourses = availCourses->next;
        }
    }
    else 
        cout << endl << "The results of semester " << curSemester->semesterID << " has not been published." << endl;

    string x;
    cout << "Done viewing? Enter any character to exit: ";
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
        cout << " ==============================================================" << endl;
        cout << " Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
        cout << " ==============================================================" << endl;
        return;
    }
    int count = 0;
    cout << "       ------------------------------------------------------------------------------------------------------------------\n";
    cout << "        No |     ID     |                         Name                       | Cre | Capacity | Day | Session | Teacher" << endl;
    cout << "       ------------------------------------------------------------------------------------------------------------------\n";
    while (curCourse)
    {
        studentList *curStudent = curCourse->data.enrolledStudents;
        while (curStudent)
        {
            if (curStudent->data.id == curUser->id)
            {
                count++;
                string fullname = curCourse->data.courseName;
                cout << "\t" << setw(2) << count << " | " << curCourse->data.id;
                if (curCourse->data.id.size() >= 10)
                    ;
                else
                {
                    for (int i = 0; i < (10 - curCourse->data.id.size()); i++)
                        cout << " ";
                }
                cout << " | " << fullname;
                if (fullname.size() >= 50)
                    ;
                else
                {
                    for (int i = 0; i < (50 - fullname.size()); i++)
                        cout << " ";
                }
                cout << " | " << setw(3) << curCourse->data.credit << " | " << setw(8) << curCourse->data.maximum << " | " << curCourse->data.dayOfWeek << " | " << setw(7) << curCourse->data.session << " | " << curCourse->data.teacherName << endl;
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
    cout << " ==============================================================" << endl;
    cout << " Logged In >> Main Menu >> POSSIBLE ACTIONS" << endl;
    cout << " ==============================================================" << endl;
    return;
}
