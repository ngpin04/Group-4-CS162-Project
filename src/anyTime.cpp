#include "../header/anyTime.h"
#include "../header/console.h"

// 15. View a list of classes.
void viewClass(schoolYear *curYear) 
{
    if (curYear->allClasses == nullptr)
    {
        cout << endl
             << "No class found!" << endl;
        cout << "Enter any character to continue: ";
        string temp;
        cin >> temp;
        clearScreen();
        cout << "==============================================================" << endl;
        cout << "Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
        cout << "==============================================================" << endl;
        return;
    }
    classList *curClass = curYear->allClasses;
    int index = 1;
    while (curClass)
    {
        cout << index << ". " << curClass->data.name << endl;
        index++;
        curClass = curClass->next;
    }
    cout << "Enter any character to continue: ";
    string temp;
    cin >> temp;
    clearScreen();
    cout << "==============================================================" << endl;
    cout << "Logged In >> Main Menu >> Possible Actions >> ANY-TIME ACTIONS" << endl;
    cout << "==============================================================" << endl;
}