#include "../header/schoolYear.h"

void schoolYear::input(){
    fi >> this->start;
    fi >> this->end;
    int temp;
    fi >> temp;
    if (temp == 0)
        this->sem1 = nullptr;
    else{
        this->sem1 = new semester;
        this->sem1->semesterID = temp;
        fi >> this->sem1->startDate.day;
        fi >> this->sem1->startDate.month;
        fi >> this->sem1->startDate.year;
        fi >> this->sem1->endDate.day;
        fi >> this->sem1->endDate.month;
        fi >> this->sem1->endDate.year;
        fi >> this->sem1->scorePublished;
    }
    fi >> temp;
    if (temp == 0)
        this->sem2 = nullptr;
    else{
        this->sem2 = new semester;
        this->sem2->semesterID = temp;
        fi >> this->sem2->startDate.day;
        fi >> this->sem2->startDate.month;
        fi >> this->sem2->startDate.year;
        fi >> this->sem2->endDate.day;
        fi >> this->sem2->endDate.month;
        fi >> this->sem2->endDate.year;
        fi >> this->sem2->scorePublished;
    }
    fi >> temp;
    if (temp == 0)
        this->sem3 = nullptr;
    else{
        this->sem3 = new semester;
        this->sem3->semesterID = temp;
        fi >> this->sem3->startDate.day;
        fi >> this->sem3->startDate.month;
        fi >> this->sem3->startDate.year;
        fi >> this->sem3->endDate.day;
        fi >> this->sem3->endDate.month;
        fi >> this->sem3->endDate.year;
        fi >> this->sem3->scorePublished;
    }
    
}