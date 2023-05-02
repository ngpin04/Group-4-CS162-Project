#include <iostream>
#include <iomanip>
#include "../header/console.h"
#include "../header/course.h"
#include "../header/endSem.h"
using namespace std;

// 23. View the scoreboard of a class, including final marks of all courses in the semester,
// GPA in this semester, and the total GPA

void getAllIDs(classScores *scoresOfClass, studentList *studentsOfClass)
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

        if (studentsOfClass)
            studentsOfClass = studentsOfClass->next;
        else
            break;
    }

    return;
}

void getMarksFromCourses(classScores *scoresOfClass, semester *curSemester)
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

                if (enrolledInThisCourse->next)
                    enrolledInThisCourse = enrolledInThisCourse->next;
                else
                    break;
            }

            if (courseInSem->next)
                courseInSem = courseInSem->next;
            else
                break;
        }

        if (curStudentOnList->nextStd)
            curStudentOnList = curStudentOnList->nextStd;
        else
            break;
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

        if (list->nextCourse)
            list = list->nextCourse;
        else
            break;
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

                        if (curStudent->next)
                            curStudent = curStudent->next;
                        else
                            break;
                    }

                    if (courseInSem->next)
                        courseInSem = courseInSem->next;
                    else
                        break;
                }
            }
        }

        if (thisYear->next)
            thisYear = thisYear->next;
        else
            break;
    }

    gpa = total / totalCredits;
    return gpa;
}

void printClassScoreboard(yearList *YearList, classScores *scoresOfClass, generalClass thisClass)
{
    clearScreen();
    cout << "\t\t | SCOREBOARD OF CLASS " << thisClass.name << " | \t\t" << endl;

    classScores *cur1 = scoresOfClass;
    studentList *cur2 = thisClass.studentHead;
    int i = 1;

    if (!cur1)
        cout << "There is no score to display." << endl;
    while (cur1)
    {
        cout << i << ". " << cur2->data.lastName << " " << cur2->data.firstName << endl;
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

void scoreboardOfClass(yearList *YearList, schoolYear *curYear, semester *curSemester)
{
    // Find the class
    string inputClass;
    bool foundClass = false;
    generalClass thisClass;

    while (!foundClass)
    {
        cout << "Enter a class name, 0 to exit: ";
        cin >> inputClass;

        if (inputClass == "0")
        {
            clearScreen();
            cout << "==================================================================" << endl;
            cout << "Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
            cout << "==================================================================" << endl;
            return;
        }

        classList *classesThisYear = curYear->allClasses;
        while (classesThisYear)
        {
            if (inputClass == classesThisYear->data.name)
            {
                thisClass = classesThisYear->data;
                foundClass = true;
                break;
            }
            else
            {
                if (classesThisYear->next)
                    classesThisYear = classesThisYear->next;
                else
                    break;
            }
        }

        if (!foundClass)
            cout << "There's no such class. Please try again." << endl;
    }

    // Get all student IDs of the class
    classScores *scoresOfClass = nullptr;
    studentList *studentsOfClass = thisClass.studentHead;
    getAllIDs(scoresOfClass, studentsOfClass);

    getMarksFromCourses(scoresOfClass, curSemester);
    printClassScoreboard(YearList, scoresOfClass, thisClass);

    int x = 1;
    while (x != 0)
    {
        cout << "Done viewing? Enter 0 to exit: ";
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
