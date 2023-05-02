#include "../header/createSemester.h"
using namespace std;

semester *createSemester(yearList *current) {
    semester *s = new semester;
    cout << "Please input 2 integers indicating the school year of this semester:";
    int start, end; cin >> start >> end;
    while (current != nullptr && current->data.start != start) 
        current = current->next;
    
    if (current == nullptr) {
        cout << "Invalid school year, please try again." << endl;
        delete s;
        return nullptr;
    }
    
    cout << "Please input a number from 1 to 3 to indicate the semester: ";
    int index; cin >> index;
    if (index == 1)
        current->data.sem1 = s;
    else if (index == 2)
        current->data.sem2 = s;
    else if (index == 3) 
        current->data.sem3 = s;
    else {
        cout << "Invalid semester, please try again." << endl;
        delete s;
        return nullptr;
    }
    return s;
}