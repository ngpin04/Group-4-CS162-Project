#include "../header/generalClass.h"

void generalClass::input(ifstream& fi) {
    int i;
    fi >> i;
    if (i == -1)
    {
        this->studentHead = nullptr;
        return;
    }
    this->studentHead = new studentList;
    fi >> this->studentHead->data.id;
    fi.ignore(100, '\n');
    getline(fi, this->studentHead->data.firstName);
    getline(fi, this->studentHead->data.lastName);
    fi >> this->studentHead->data.isFemale;
    fi >> this->studentHead->data.birth.day;
    fi >> this->studentHead->data.birth.month;
    fi >> this->studentHead->data.birth.year;
    fi >> this->studentHead->data.socialID;
    studentList* cur = this->studentHead;
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
        getline(fi, cur->next->data.firstName);
        getline(fi, cur->next->data.lastName);
        fi >> cur->next->data.isFemale;
        fi >> cur->next->data.birth.day;
        fi >> cur->next->data.birth.month;
        fi >> cur->next->data.birth.year;
        fi >> cur->next->data.socialID;
        cur = cur->next;
    }
}