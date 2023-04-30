#include "../header/schoolYear.h"
#include "../header/course.h"
#include "../header/console.h"
#include <string>
using namespace std;

struct mark
{
    string courseName;
    float finalMark;
    mark *nextCourse = nullptr;
};

struct classScores
{
    string id;
    mark *markOfCourses = nullptr;
    classScores *nextStd = nullptr;
};

void returnDefault();
void exportStu(courseList* course);
void importScoreboard(courseList*& course);
void getAllIDs(classScores *scoresOfClass, studentList *studentsOfClass);
void getMarksFromCourses(classScores *scoresOfClass, semester *curSem);
void scoreboardOfClass(yearList *YearList);