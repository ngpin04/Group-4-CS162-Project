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
    string filename; 
    cout << "Please enter the name of the csv file that you upload: ";
	cin>> filename;

	string line, word;
    studentList *students = current->data.enrolledStudents;
    students = new studentList;

    while (current->next != nullptr)    
        current = current->next;
    
	fstream file (filename, ios::in);
	if(file.is_open()) {
        bool firstline = true;
		while(getline(file, line)) {
			stringstream str(line);
            if (!firstline) {
                students->next = new studentList;
                students = students->next;
            }

            getline(str, word, ',');
            getline(str, word, '.');
            students->data.id = to_number(word);
            getline(str, word, '.');
            students->data.firstName = word;
            getline(str, word, '.');
            students->data.lastName = word;
            getline(str, word, '.');
            students->data.isFemale = to_number(word);
            getline(str, word, '.');
            students->data.birth.day = to_number(word);
            getline(str, word, '.');
            students->data.birth.month = to_number(word);
            getline(str, word, '.');
            students->data.birth.month = to_number(word);
            getline(str, word, '.');
            students->data.socialID = word;
		}
	}
	else {
		cout<<"Could not open the file\n";
    }
}
