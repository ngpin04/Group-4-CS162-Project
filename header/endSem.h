#include "../header/schoolYear.h"
#include "../header/course.h"
#include "../header/console.h"
#include <string>
using namespace std;

struct mark
{
    string courseName;
    float value;
    mark *nextCourse = nullptr;
};

struct classScores
{
    string id = "-1";
    mark *markOfCourses = nullptr;
    classScores *nextStd = nullptr;
};

void getAllIDs(classScores *scoresOfClass, studentList *studentsOfClass);
void getMarksFromCourses(classScores *scoresOfClass, semester *curSem);
void printClassScoreboard(classScores* scoresOfClass, studentList* studentsOfClass);
void scoreboardOfClass(yearList *YearList);