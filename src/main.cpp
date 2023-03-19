#include "../header/user.h"
#include "../header/readData.h"
const int N = 1e5;

userList *User = new userList;

int main() {
    readData(User, "data/user.txt");
    return 0;
}