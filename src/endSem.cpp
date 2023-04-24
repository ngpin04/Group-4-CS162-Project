#include <iostream>
#include "../header/endSem.h"

// 23. View the scoreboard of a class, including final marks of all courses in the semester,
// GPA in this semester, and the total GPA

void getAllIDs(classScores *scoresOfClass, studentList *studentsOfClass)
{
    classScores *tmpStudent = nullptr;

    while (studentsOfClass)
    {
        classScores *newStd = new classScores;
        newStd->id = studentsOfClass->data.id;
        if (!scoresOfClass)
        {
            scoresOfClass = newStd;
            tmpStudent = scoresOfClass;
        }
        else
        {
            tmpStudent->nextStd = newStd;
            tmpStudent = tmpStudent->nextStd;
        }
        studentsOfClass = studentsOfClass->next;
    }

    return;
}

void getMarksFromCourses(classScores *scoresOfClass, semester *curSem)
{
    classScores *thisStudent = scoresOfClass;
    while (thisStudent)
    {
        courseList *theseCourses = curSem->allCourses;
        while (theseCourses)
        {
            studentList *enrolled = theseCourses->data.enrolledStudents;
            mark *tmpMark = nullptr;
            while (enrolled)
            {
                if (enrolled->data.id == thisStudent->id)
                {
                    mark *newMark = new mark;
                    newMark->courseName = theseCourses->data.courseName;
                    newMark->finalMark = theseCourses->data.scoreboard->data.finalMark;

                    if (!thisStudent->markOfCourses)
                    {
                        thisStudent->markOfCourses = newMark;
                        tmpMark = thisStudent->markOfCourses;
                    }
                    else
                    {
                        tmpMark->nextCourse = newMark;
                        tmpMark = tmpMark->nextCourse;
                    }

                    break;
                }
                else
                    enrolled = enrolled->next;
            }
            theseCourses = theseCourses->next;
        }
        thisStudent = thisStudent->nextStd;
    }

    return;
}

void scoreboardOfClass(yearList *YearList)
{
    // Find the class
    string inputClass;
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

    bool found = false;
    generalClass thisClass;

    classList *classes = YearList->data.allClasses;
    while (classes)
    {
        if (inputClass == classes->data.name)
        {
            thisClass = classes->data;
            found = true;
            break;
        }
        else
            classes = classes->next;
    }

    if (!found)
    {
        cout << "There is no such class. Please try again or 0 to exit: ";
        cin >> inputClass;

        if (inputClass == "0")
        {
            clearScreen();
            cout << "==================================================================" << endl;
            cout << "Logged In >> Main Menu >> Possible Actions >> END-SEMESTER ACTIONS" << endl;
            cout << "==================================================================" << endl;
            return;
        }
    }

    // Get all student IDs of the class
    classScores *scoresOfClass = nullptr;
    studentList *studentsOfClass = thisClass.studentHead;
    getAllIDs(scoresOfClass, studentsOfClass);

    // Find current year -> current semester and get the marks
    int thisYear = thisClass.firstYear;
    while (YearList)
    {
        if (thisYear == YearList->data.start)
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

            getMarksFromCourses(scoresOfClass, s[curSem - 1]);

            classScores* ptr = scoresOfClass;
            while (ptr)
            {
                cout << ptr->id << " " << "Scores: ";
                mark* tmp = ptr->markOfCourses;
                while (tmp)
                {
                    cout << tmp->finalMark << " ";
                    tmp = tmp->nextCourse;
                }    
                ptr = ptr->nextStd;
            }
        }
        else
            YearList = YearList->next;
    }
}
