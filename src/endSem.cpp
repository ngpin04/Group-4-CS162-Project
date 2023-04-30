#include <iostream>
#include <string>
#include <sstream>
#include "../header/endSem.h"

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
    cout << "Enter the ID of the course that you want to export student list from: ";
    string id;
    studentList* stu = nullptr;
    courseList* tmp;
    while (!stu)
    {
        cin >> id;
        tmp = course;
        while (tmp && tmp->data.id != id)
            tmp = tmp -> next;
        if (!tmp) cout << "No such course exists. Please enter another course ID: ";
        else
        {
            stu = tmp -> data.enrolledStudents;
            break;
        } 
    }
    cout << "Enter the name of the csv file that you want to export: ";
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
