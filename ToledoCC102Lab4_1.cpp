#include <iostream>
using namespace std;

int main() {
    int students, quizzes;
    float scores[50][50];
    char choice;

    do {
        cout << "\n===== Quiz Average Calculator =====\n";

        cout << "Number of students: ";
        cin >> students;

        cout << "Number of quizzes: ";
        cin >> quizzes;

        for (int i = 0; i < students; i++) {
            float total = 0;

            cout << "\nEnter scores for Student #" << (i + 1) << endl;

            for (int j = 0; j < quizzes; j++) {
                cout << "Quiz " << (j + 1) << ": ";
                cin >> scores[i][j];
                total += scores[i][j];
            }

            float average = total / quizzes;
            cout << "Student #" << (i + 1) << " Average: " << average << endl;
        }

        cout << "Run program again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
