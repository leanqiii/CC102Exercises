#include <iostream>

using namespace std;

int main () {

    do {
    int quiz, students;
    char choice;

    cout<< "Enter number of students: ";
    cin>> students;

    cout<< "Enter number of quizzes: ";
    cin>> quiz;

    double scores [50][50];

        for (int i = 0; i < students; i++) {
            double sum = 0;

            cout<< "\nStudent " << i + 1 << " scores:\n";

            for (int j = 0; j < quiz; j++) {
                cin>> scores[i][j];
                sum += scores[i][j];
            }
            cout<< "Average: " << sum / quiz << endl;
        }

        cout<< "Do you want to do another? (Y/y): ";
        cin>> choice;

    } while (choice == 'Y' || choice == 'y');

        return 0;
}
