#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct student {
    int studentID;
    string name;
    string course;
    float gpa;
};

string getStanding(float gpa) {
    if (gpa >= 90) return "Excellent";
    else if (gpa >= 80) return "Very Good";
    else if (gpa >= 70) return "Good";
    else if (gpa >= 60) return "Passing";
    else return "Failed";
}

void input(student s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << endl;

        bool unique;
        do {
            unique = true;
            cout << "Enter Student ID: ";
            cin >> s[i].studentID;

            for (int j = 0; j < i; j++) {
                if (s[i].studentID == s[j].studentID) {
                    cout << "ID already exists! Enter another.\n";
                    unique = false;
                    break;
                }
            }
        } while (!unique);

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, s[i].name);

        cout << "Enter Course: ";
        getline(cin, s[i].course);

        cout << "Enter GPA (0-100): ";
        cin >> s[i].gpa;
    }
}

void display(student s[], int n) {
    cout << "\n\nStudent Records:\n";
    cout << left << setw(12) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Course"
         << setw(10) << "GPA"
         << setw(15) << "Standing" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(12) << s[i].studentID
             << setw(20) << s[i].name
             << setw(15) << s[i].course
             << setw(10) << s[i].gpa
             << setw(15) << getStanding(s[i].gpa) << endl;
    }
}

int main() {
    char again;

    do {
        int n;
        cout << "Enter number of students: ";
        cin >> n;

        student s[n];

        input(s, n);
        display(s, n);

        cout << "\nRun again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}