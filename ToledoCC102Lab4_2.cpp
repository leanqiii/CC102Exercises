#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    char again;

    int products = 5;
    int salespeople = 4;

    double sales[5][4] = {0};

    do {

        system("cls");

        int sp, pr;
        double amt;
        char choice;

        do {
            cout << "\nEnter salesperson number (1-4): ";
            cin >> sp;

            cout << "Enter product number (1-5): ";
            cin >> pr;

            cout << "Enter sales amount: ";
            cin >> amt;

            if (sp >= 1 && sp <= 4 && pr >= 1 && pr <= 5) {
                sales[pr - 1][sp - 1] += amt;
            }
            else {
                cout << "Invalid input.\n";
            }

            cout << "Do you want to enter another sale? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        cout << "\nSales Summary:\n";

        double grandTotal = 0;

        for (int i = 0; i < products; i++) {

            double rowTotal = 0;
            cout << "Product " << i + 1 << ": ";

            for (int j = 0; j < salespeople; j++) {
                cout << sales[i][j] << " ";
                rowTotal += sales[i][j];
            }

            cout << " | Total = " << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "\nSalesperson Totals:\n";

        for (int j = 0; j < salespeople; j++) {

            double colTotal = 0;

            for (int i = 0; i < products; i++) {
                colTotal += sales[i][j];
            }

            cout << "Salesperson " << j + 1 << ": " << colTotal << endl;
        }

        cout << "\nGrand Total: " << grandTotal << endl;

        cout << "\nRun the program again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
