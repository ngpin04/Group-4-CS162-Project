#include "../header/schoolYear.h"
#include "../header/course.h"
#include "../header/console.h"
#include <string>
using namespace std;

struct mark
{
    string courseName;
    double value = -1.00;
    int credits;
    mark *nextCourse = nullptr;
};

struct classScores
{
    string id = "-1";
    mark *markOfCourses = nullptr;
    classScores *nextStd = nullptr;
};

void returnDefault();
void exportStu(courseList* course);
double toDouble(const string& str);
void importScoreboard(courseList*& course);
// function 22
void chooseCourse(schoolYear *curYear, semester *curSemester, courseList *&thisCourse);
void chooseStudent(schoolYear *curYear, semester *curSemester, courseList *thisCourse, scoreList *&thisStudent);
void updateMark(schoolYear *curYear, semester *curSemester, courseList *thisCourse, scoreList *&thisStudent);
void chooseToUpdate(schoolYear *curYear, semester *curSemester);
// function 23
void getAllIDs(classScores *&scoresOfClass, studentList *studentsOfClass);
void getMarksFromCourses(classScores *&scoresOfClass, semester *curSemester);
double gpaThisSem(classScores *curStudent);
double gpaOverall(classScores *scoresOfClass, yearList *YearList);
void printClassScoreboard(yearList *YearList, classScores* scoresOfClass, classList* curClass);
void scoreboardOfClass(yearList *YearList, schoolYear *curYear, semester *curSemester);
// function 24
void viewScoreboard(semester* curSem);