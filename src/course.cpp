#include "../header/course.h"

void readStudentList(studentList *&StudentList, ifstream &fi)
{
    int i;
    fi >> i;
    if (i == -1)
    {
        StudentList = nullptr;
        return;
    }
    StudentList = new studentList;
    fi >> StudentList->data.id;
    fi.ignore(100, '\n');
    getline(fi, StudentList->data.firstName);
    getline(fi, StudentList->data.lastName);
    fi >> StudentList->data.isFemale;
    fi >> StudentList->data.birth.day;
    fi >> StudentList->data.birth.month;
    fi >> StudentList->data.birth.year;
    fi >> StudentList->data.socialID;
    studentList *cur = StudentList;
    while (true)
    {
        fi >> i;
        if (i == -1)
        {
            cur->next = nullptr;
            break;
        }
        cur->next = new studentList;
        fi >> cur->next->data.id;
        fi.ignore(100, '\n');
        getline(fi,cur->next->data.firstName);
        getline(fi,cur->next->data.lastName);
        fi >> cur->next->data.isFemale;
        fi >> cur->next->data.birth.day;
        fi >> cur->next->data.birth.month;
        fi >> cur->next->data.birth.year;
        fi >> cur->next->data.socialID;
        cur = cur->next;
    }
}

void readScoreList(scoreList *&ScoreList, ifstream &fi)
{
    int i;
    fi >> i;
    if (i == -1)
    {
        ScoreList = nullptr;
        return;
    }
    ScoreList = new scoreList;
    fi >> ScoreList->data.id;
    fi.ignore(100, '\n');
    getline(fi, ScoreList->data.fullname);
    fi >> ScoreList->data.midterm;
    fi >> ScoreList->data.finalMark;
    fi >> ScoreList->data.other;
    fi >> ScoreList->data.total;
    scoreList *cur = ScoreList;
    while (true)
    {
        fi >> i;
        if (i == -1)
        {
            cur->next = nullptr;
            break;
        }
        cur->next = new scoreList;
        fi >> ScoreList->data.id;
        fi.ignore(100, '\n');
        getline(fi, ScoreList->data.fullname);
        fi >> ScoreList->data.midterm;
        fi >> ScoreList->data.finalMark;
        fi >> ScoreList->data.other;
        fi >> ScoreList->data.total;
        scoreList *cur = ScoreList;
        cur = cur->next;
    }
}

// read the course from the file
void course::input(ifstream &fi)
{
    fi >> this->id;
    fi.ignore(100, '\n');
    getline(fi,this->courseName);
    fi >> this->className;
    fi.ignore(100, '\n');
    getline(fi,this->teacherName);
    fi >> this->credit;
    fi >> this->maximum;
    fi >> this->dayOfWeek;
    fi >> this->session;
    fi >> this->resultsReleased;
    int temp = 0;
    fi >> temp;
    if (temp != 0)
    {
        readStudentList(this->enrolledStudents, fi);
    }
    fi >> temp;
    if (temp != 0)
    {
        readScoreList(this->scoreboard, fi);
    }
}