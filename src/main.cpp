#include "../header/user.h"
#include "../header/readData.h"
const int N = 1e5;

user User[N];

int numUser;

int main() {
    readData(User, numUser, "data/user.txt");
    return 0;
}