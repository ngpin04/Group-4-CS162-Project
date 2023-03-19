#include <iostream>
#include "../header/changePassword.h"

using namespace std;

void changePassword(user u)
{
    string newpass1, newpass2;
    do
    {
        cout << "Enter your new password: ";
        cin >> newpass1;
        if (newpass1==u.password)
            cout << "Sorry, your new password is the same as the old one. \nPlease try again!\n";
    } while (newpass1==u.password);
    do
    {
        cout << "Enter your new password again to confirm: ";
        cin >> newpass2;
        if (newpass2!=newpass1) 
            cout << "Sorry, your new password does not match. \nPlease try again!\n";
    } while (newpass2!=newpass1);
    u.password = newpass1;
}