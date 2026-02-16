#include <iostream>
using namespace std;

int main() {
    char repeat;

    do {
        const int NUM_PRODUCTS = 5;
        const int NUM_SALESPEOPLE = 4;

        double sales[NUM_PRODUCTS][NUM_SALESPEOPLE] = {0};

        int salesperson, product;
        double amount;
        char choice;

        do {
            cout << "\nEnter Salesperson (1-4): ";
            cin >> salesperson;

            cout << "Enter Product (1-5): ";
            cin >> product;

            cout << "Enter Amount: ";
            cin >> amount;

            if (salesperson >= 1 && salesperson <= NUM_SALESPEOPLE &&
                product >= 1 && product <= NUM_PRODUCTS) {
                sales[product - 1][salesperson - 1] += amount;
            } else {
                cout << "Invalid input.\n";
            }

            cout << "Add another record? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        cout << "\n===== MONTHLY SALES SUMMARY =====\n\n";

        cout << "Product ";
        for (int j = 0; j < NUM_SALESPEOPLE; j++)
            cout << "SP" << j + 1 << " ";
        cout << "Total\n";

        double grandTotal = 0;

        for (int i = 0; i < NUM_PRODUCTS; i++) {
            double rowTotal = 0;

            cout << i + 1 << "       ";

            for (int j = 0; j < NUM_SALESPEOPLE; j++) {
                cout << sales[i][j] << " ";
                rowTotal += sales[i][j];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "Total   ";

        for (int j = 0; j < NUM_SALESPEOPLE; j++) {
            double colTotal = 0;

            for (int i = 0; i < NUM_PRODUCTS; i++)
                colTotal += sales[i][j];

            cout << colTotal << " ";
        }

        cout << grandTotal << endl;

        cout << "\nRun the program again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "Program ended.\n";

    return 0;
}
