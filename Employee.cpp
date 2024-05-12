#include "Employee.h"
#include"Person.h"
#include<iostream>
using namespace std;

// Constructors
Employee::Employee() : Person()
{
    employee_position = "n\a";
    employee_salary = 0.0;
}
Employee::Employee(int person_id, string person_name, string employee_position, float employee_salary) : Person(person_id, person_name)
{
    this->employee_position = employee_position;
    this->employee_salary = employee_salary;
}
Employee::Employee(const Employee& obj) : Person(obj)
{
    this->employee_position = obj.employee_position;
    this->employee_salary = obj.employee_salary;
}

void Employee::set_employee_position(string employee_position) {
    this->employee_position = employee_position;
}
void Employee::set_employee_salary(float employee_salary) {
    this->employee_salary = employee_salary;
}

string Employee::get_employee_position() {
    return employee_position;
}
float Employee::get_employee_salary() {
    return employee_salary;
}

// Member functions
string Employee::tostring() {
    return Person::tostring() + "\t" + employee_position + "\t" + to_string(employee_salary) + "\n";
}
void Employee::promote(string new_position) {
    employee_position = new_position;
}
void Employee::store_to_file(){
    ofstream fout("Employee.txt", ios::app);
    if (fout.is_open()) {
        fout << tostring() << endl;
        fout.close();
        cout << "\nData Stored To Employee  File";
    }
    else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}
void Employee::view_from_file(){
    ifstream fin("Employee.txt");
    if (fin.is_open()) {
        string data;
        while (getline(fin, data)) {
            cout << data << endl;
        }
        fin.close();
    }
    else {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}
void Employee::update() {
    int id;
    cout << "Enter the ID of the Employee to update: ";
    cin >> id;
    ifstream fin("Employee.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false;
        int option, Employee_id;
        string Employee_name;
        while (fin >> Employee_id >> Employee_name >>employee_position>>employee_salary) {
            if (Employee_id == id) {
                found = true;
                cout << "Enter Employee ID: ";
                cin >> Employee_id;
                cin.ignore();
                cout << "Enter Employee Name: ";
                getline(cin, Employee_name);
                cout << "Enter Employee Position: ";
                getline(cin, employee_position);
                cout << "Enter Employee Salary:";
                cin>> employee_salary;
                Employee::set_person_id(Employee_id);
                Employee::set_person_name(Employee_name);
                Employee::set_employee_position(employee_position);
                Employee::set_employee_salary(employee_salary);
            }
            fout << Employee::tostring() << endl;
        }
        fin.close();
        fout.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        if (!found) {
            cout << "Employee with ID " << id << " not found." << endl;
        }
        else {
            cout << "Employee updated successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void Employee::search() {
    int id;
    cout << "Enter the ID of the Employee to search: ";
    cin >> id;
    ifstream fin("Employee.txt");
    if (fin.is_open()) {
        bool found = false;
        int option, Employee_id;
        string Employee_name;
        while (fin >> Employee_id >> Employee_name >> employee_position >> employee_salary) {
            if (Employee_id == id) {
                found = true;
                cout << "\nEmployee ID: " << Employee_id;
                cout << "\nEmployee Name: " << Employee_name;
                cout << "\nEmployee Position: " << employee_position;
                cout << "\nEmployee Salary: " << employee_salary;
            }
            fin.close();
            if (!found) {
                cout << "Employee with ID " << id << " not found." << endl;
            }
        }
    }
    else {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}
void Employee::del() {
    int id;
    cout << "Enter the ID of the Employee to delete: ";
    cin >> id;
    ifstream fin("Employee.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false;
        int option, Employee_id;
        string Employee_name;
        while (fin >> Employee_id >> Employee_name >> employee_position >> employee_salary) {
            if (Employee_id == id) {
                found = true;
            }
            else {
                fout << Employee_id << "\t" << Employee_name << "\t" << employee_position << "\t" << employee_salary << endl;
            }
        }
        fin.close();
        fout.close();
        remove("Employee.txt");
        rename("temp.txt", "Employee.txt");
        if (!found) {
            cout << "Employee with ID " << id << " not found." << endl;
        }
        else {
            cout << "Employee with ID " << id << " deleted successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void Employee::menu(Employee& obj) {
    int choice;
    cout << "\nMenu 1- add 2- view 3- update 4- search 5- delete";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cin >> obj;
        break;
    }
    case 2:
    {
        obj.view_from_file();
        break;
    }
    case 3:
    {
        obj.update();
        break;
    }
    case 4:
    {
        obj.search();
        break;
    }
    case 5:
    {
        obj.del();
        break;
    }
    default:
    {
        cout << "\nInvalid Choice";
        break;
    }
    }
}

// Stream operators
ostream& operator<<(ostream& cout, const Employee& obj) {
    cout << "Employee ID: " << obj.get_person_id();
    cout << "Employee Name: " << obj.get_person_name();
    cout << "Employee Position: " << obj.employee_position;
    cout << "Employee Salary: " << obj.employee_salary;
    return cout;
}
istream& operator>>(istream& cin, Employee& obj) {
    int id;string name;
    cout << "Employee ID: ";
    cin>>id;
    obj.set_person_id(id);
    cin.ignore();
    cout << "Employee Name: ";
    getline(cin, name);
    obj.set_person_name(name);
    cout << "Employee Position: ";
    getline(cin, obj.employee_position);
    cout << "Employee Salary: ";
    cin >> obj.employee_salary;

    obj.set_person_id(id);
    obj.set_person_name(name);
    obj.set_employee_position(obj.employee_position);
    obj.set_employee_salary(obj.employee_salary);
    
    obj.store_to_file();

    return cin;
}