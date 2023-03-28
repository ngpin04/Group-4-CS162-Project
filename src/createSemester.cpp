#include "../header/createSemester.h"
using namespace std;

semester *createSemester(yearList *current) {
    semester *s = new semester;
    cout << "Please input 2 integers indicates the school year of this semester: \n";
    int start, end; cin >> start >> end;
    while (current != nullptr && current->data.start != start) 
        current = current->next;
    
    if (current == nullptr) {
        cout << "invalid school year, please try again" << endl;
        delete s;
        return nullptr;
    }
    
    cout << "Please input from 1 to 3 indicates the semester" << endl;
    int index; cin >> index;
    if (index == 1)
        current->data.sem1 = s;
    else if (index == 2)
        current->data.sem2 = s;
    else if (index == 3) 
        current->data.sem3 = s;
    else {
        cout << "invalid semester, please try again" << endl;
        delete s;
        return nullptr;
    }
    return s;
}