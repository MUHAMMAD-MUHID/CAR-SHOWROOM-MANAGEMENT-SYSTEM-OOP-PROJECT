#include "Car.h"
#include "SUV.h"
#include "Hatchback.h"
#include "Sedan.h"
#include "Person.h"
#include "Employee.h"
#include "Customer.h"
#include "Showroom.h"
#include <iostream>
#include <cstdlib> 
using namespace std;

void displayWelcomeMessage() {
    cout << "\t\t\t\t*****************************************************" << endl;
    cout << "\t\t\t\t*   WELCOME TO THE CAR SHOWROOM MANAGEMENT SYSTEM   *" << endl;
    cout << "\t\t\t\t*****************************************************" << endl;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void main_menu()
{
    char sure = 'y';
    do {
        clearScreen();
        displayWelcomeMessage();
        int choice;
        cout << "Enter Choice:" << endl;
        cout << "1. Car" << endl;
        cout << "2. Employee" << endl;
        cout << "3. Customer" << endl;
        cout << "4. Showroom" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            clearScreen();
            cout << "Choose Car Type:" << endl;
            cout << "1. SUV" << endl;
            cout << "2. Sedan" << endl;
            cout << "3. Hatchback" << endl;
            cout << "4. EXIT" << endl;
            int choice1;
            cin >> choice1;
            clearScreen();
            switch (choice1) {
            case 1: {
                SUV obj;
                obj.menu(obj);
                break;
            }
            case 2: {
                Sedan obj;
                obj.menu(obj);
                break;
            }
            case 3: {
                Hatchback obj;
                obj.menu(obj);
                break;
            }
            case 4: {
                main_menu();
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
                break;
            }
            }
            break;
        }
        case 2: {
            clearScreen();
            Employee obj;
            obj.menu(obj);
            break;
        }
        case 3: {
            clearScreen();
            Customer obj;
            obj.menu(obj);
            break;
        }
        case 4:
        {
            clearScreen();
            Showroom obj;
            obj.menu();
            break;
        }

        case 5: {
            clearScreen();
            cout << "Are you sure you want to exit? (YES(Y) / NO(N)): ";
            cin >> sure;
            break;
        }
        default: {
            cout << "Invalid choice!" << endl;
            break;
        }
        }
    } while (sure == 'N' || sure == 'n');
}

int main() {
    main_menu();
    return 0;
}
