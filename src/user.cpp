#include "../header/user.h"

void user::changePassword() 
{
    string curpass, newpass1, newpass2;
    do 
    {
        cout << "Enter your current password: ";
        cin >> curpass;
        if (curpass!=password)
            cout << "\nSorry, this is not your current password. \nPlease try again!\n";
    } while (curpass!=password);
    do
    {
        cout << "Enter your new password: ";
        cin >> newpass1;
        if (newpass1==password)
            cout << "\nSorry, your new password is the same as the old one. \nPlease try again!\n";
    } while (newpass1==password);
    do
    {
        cout << "Enter your new password again to confirm: ";
        cin >> newpass2;
        if (newpass2!=newpass1) 
            cout << "\nSorry, you did not enter the same new password. \nPlease try again!\n";
    } while (newpass2!=newpass1);
    password = newpass1;
}

void user::input(ifstream &fi) {
    fi >> this->id;
    fi >> this->isStaff;
    fi >> this->birth.day;
    fi >> this->birth.month;
    fi >> this->birth.year;
    fi >> this->username;
    fi >> this->password;
}

void user::output(ofstream &fo) {
    fo << this->id << " ";
    fo << this->isStaff << " ";
    fo << this->birth.day << " ";
    fo << this->birth.month << " ";
    fo << this->birth.year << " ";
    fo << this->username << " ";
    fo << this->password << " ";
    fo << "\n";
}

userList::userList() {
    this->next = nullptr;
};

userList::userList(user userData) {
    this->next = nullptr;
    this->data = userData;
};

userList::userList(userList *ptr, user userData) {
    this->next = ptr;
    this->data = userData;
};
