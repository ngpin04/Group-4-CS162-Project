#include "../header/uploadStudentList.h"
#include <sstream>
#include <fstream>
using namespace std;

int to_number(const string &str) {
    int res = 0;
    for (char c : str)
        res = 10 * res + (c - '0');
    return res;
}

void uploadStudentList(courseList *current) {
    if (current == nullptr) {
        cout << "There is no course yet! Press any key to return" << endl;
        cin.ignore();
        cin.get();
        return;
    }
    
    string filename; 
    cout << " Please enter the name of the csv file that you upload: ";
	cin>> filename;

    cout << "Please choose from the list of courses: " << endl;
    int count = 0;
    cout << count << ". none" << endl;
    for (courseList *i = current; i != nullptr; i = i->next) {
        count++;
        cout << count << ". " << i->data.id << " " << i->data.className << endl;
    }

    cout << "Please enter your choice: ";
    string str;
    cin >> str;
    int res = to_number(str);
    if (res > count || res < 0) {
        cout << "invalid choice! Press any key to return" << endl;
        cin.ignore();
        cin.get();
    }
    if (res == 0) 
        return;   

    res--;
    while (res--)
        current = current->next;

    string line, word;
    studentList *students = new studentList;
    current->data.enrolledStudents = &(*students);
	fstream file ("data/" + filename, ios::in);
	if(file.is_open()) {
        int cur = 1;
		while(getline(file, line)) {
			stringstream str(line);
            if (cur == 1) {
                cur++;
                continue;
            } 
            if (cur > 2) {
                students->next = new studentList;
                students = students->next;
            }

            getline(str, word, ',');
            getline(str, word, ',');
            students->data.id = word;
            cerr << students->data.id << "\n";
            getline(str, word, ',');
            students->data.firstName = word;
            getline(str, word, ',');
            students->data.lastName = word;
            getline(str, word, ',');
            students->data.isFemale = to_number(word);
            getline(str, word, ',');
            students->data.birth.day = to_number(word);
            getline(str, word, ',');
            students->data.birth.month = to_number(word);
            getline(str, word, ',');
            students->data.birth.year = to_number(word);
            getline(str, word, ',');
            students->data.socialID = word;
            cur++;
		}
	}
	else {
		cout << " Could not open the file\n";
    }
}
