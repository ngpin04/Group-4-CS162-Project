#include "../header/user.h"

void user::changePassword(string newPassword) {
    this->password = newPassword;
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
