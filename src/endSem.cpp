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
        
        if (studentsOfClass)
            studentsOfClass = studentsOfClass->next;
        else break;
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
                else break;
            }

            if (courseInSem->next)
                courseInSem = courseInSem->next;
            else break;
        }

        if (curStudentOnList->nextStd)
            curStudentOnList = curStudentOnList->nextStd;
        else break;
    }

    return;
}

void printClassScoreboard(classScores *scoresOfClass, generalClass thisClass)
{
    clearScreen();
    cout << "==================================================================" << endl;
    cout << "              SCOREBOARD OF CLASS " << thisClass.name << "        " << endl;
    cout << "==================================================================" << endl;

    classScores *cur = scoresOfClass;
    
}

void scoreboardOfClass(schoolYear *curYear, semester *curSemester)
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
                else break;
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
}
