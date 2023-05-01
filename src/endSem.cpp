#include <iostream>
#include "../header/endSem.h"

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
        studentsOfClass = studentsOfClass->next;
    }

    return;
}

void getMarksFromCourses(classScores *scoresOfClass, semester *curSem)
{
    classScores *curStudentOnList = scoresOfClass;
    while (curStudentOnList->id != "-1")
    {
        courseList *courseInSem = curSem->allCourses;
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
                else
                    enrolledInThisCourse = enrolledInThisCourse->next;
            }
            courseInSem = courseInSem->next;
        }
        curStudentOnList = curStudentOnList->nextStd;
    }

    return;
}

void printClassScoreboard(classScores *scoresOfClass, generalClass thisClass)
{
    clearScreen();
    cout << "==================================================================" << endl;
    cout << "              SCOREBOARD OF CLASS " << thisClass.name << "        " << endl;
    cout << "==================================================================" << endl;
}

void scoreboardOfClass(yearList *YearList)
{
    // Find the school year
    int start;
    bool foundYear = false;
    yearList *thisYear = nullptr;

    while (!foundYear)
    {
        cout << "Enter the starting year of the class, or 0 to exit: ";
        cin >> start;

        if (start == 0)
        {
            clearScreen();
            cout << "==================================================================" << endl;
            cout << "Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
            cout << "==================================================================" << endl;
            return;
        }

        yearList *findTheYear = YearList;
        while (findTheYear)
        {
            if (findTheYear->data.start == start)
            {
                thisYear = findTheYear;
                foundYear = true;
                break;
            }
            else
                findTheYear = findTheYear->next;
        }

        if (!foundYear)
            cout << "Unable to find the year. Please try again." << endl;
    }

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

        classList *classesThisYear = thisYear->data.allClasses;
        while (classesThisYear)
        {
            if (inputClass == classesThisYear->data.name)
            {
                thisClass = classesThisYear->data;
                foundClass = true;
                break;
            }
            else
                classesThisYear = classesThisYear->next;
        }

        if (!foundClass)
            cout << "There's no such class. Please try again." << endl;
    }

    // Get all student IDs of the class
    classScores *scoresOfClass = nullptr;
    studentList *studentsOfClass = thisClass.studentHead;
    getAllIDs(scoresOfClass, studentsOfClass);

    // Find current semsester and get the marks
    semester *s[3] = {thisYear->data.sem1, thisYear->data.sem2, thisYear->data.sem3};

    int curSem;
    bool foundSem = false;

    while (!foundSem)
    {
        cout << "Enter current semester, or 0 to exit: ";
        cin >> curSem;

        if (curSem == 0)
        {
            clearScreen();
            cout << "==================================================================" << endl;
            cout << "Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
            cout << "==================================================================" << endl;
            return;
        }

        if (curSem == 1 || curSem == 2 || curSem == 3)
            foundSem = true;
        else
            cout << "Unable to find the semester. Please try again." << endl;
    }

    getMarksFromCourses(scoresOfClass, s[curSem - 1]);

    // classScores *ptr = scoresOfClass;
    // while (ptr)
    // {
    //     cout << ptr->id << " "
    //          << "Scores: ";
    //     mark *tmp = ptr->markOfCourses;
    //     while (tmp)
    //     {
    //         cout << tmp->finalMark << " ";
    //         tmp = tmp->nextCourse;
    //     }
    //     ptr = ptr->nextStd;
    // }
}
