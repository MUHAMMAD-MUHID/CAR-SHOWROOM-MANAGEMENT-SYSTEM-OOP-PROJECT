#include <fstream>
#include <iostream>
#include<string>
#include <sstream>
#include "Hatchback.h"
#include "Car.h"
using namespace std;

Hatchback::Hatchback() : Car() {
    cargo_space = 0;
    fuel_type = "n/a";
}
Hatchback::Hatchback(int car_id, string car_make, string car_model, float car_price, int car_seating_capacity, int car_ground_clearance, string is_car_available, int cargo_space, string fuel_type) : Car(car_id, car_make, car_model, car_price, car_seating_capacity, car_ground_clearance, is_car_available) {
    this->cargo_space = cargo_space;
    this->fuel_type = fuel_type;
}
Hatchback::Hatchback(const Hatchback& obj) : Car(obj) {
    this->cargo_space = obj.cargo_space;
    this->fuel_type = obj.fuel_type;
}
Hatchback::~Hatchback() {}
void Hatchback::set_cargo_space(int cargo_space) {
    this->cargo_space = cargo_space;
}
void Hatchback::set_fuel_type(string fuel_type) {
    this->fuel_type = fuel_type;
}
int Hatchback::get_cargo_space()const {
    return cargo_space;
}
string Hatchback::get_fuel_type()const {
    return fuel_type;
}
string Hatchback::toString() {
    return Car::tostring() + "\t" + to_string(cargo_space) + "\t" + fuel_type;
}
void Hatchback::store_to_file() {
    ofstream fout("Hatchback.txt", ios::app);
    if (fout.is_open()) {
        fout << toString() << endl;
        fout.close();
        cout << "\nData Stored To Hatchback File";
    }
    else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}
void Hatchback::view_from_file() {
    ifstream fin("Hatchback.txt");
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
void Hatchback::search() {
    int id;
    cout << "Enter the ID of the Hatchback to search: ";
    cin >> id;

    ifstream fin("Hatchback.txt");
    if (fin.is_open()) {
        bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
        while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> cargo_space >> fuel_type) {
            if (car_id == id) {
                found = true;
                cout << "\nCar ID : " << car_id;
                cout << "\nCar Make : " << car_make;
                cout << "\nCar Model : " << car_model;
                cout << "\nCar Price : " << car_price;
                cout << "\nCar Seating Capacity : " << car_seating_capacity;
                cout << "\nCar Availability : " << availability;
                cout << "\nCar Cargo Space : " << cargo_space;
                cout << "\nCar Fuel Type : " << fuel_type;
            }
            fin.close();
            if (!found) {
                cout << "Hatchback with ID " << id << " not found." << endl;
            }
        }
    }
    else {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}
void Hatchback::update() {
    int id;
    cout << "Enter the ID of the Hatchback to update: ";
    cin >> id;
    ifstream fin("Hatchback.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
        while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> cargo_space >> fuel_type) {
            if (car_id == id) {
                found = true;
                cout << "Enter Car ID: ";
                cin >> car_id;
                cin.ignore();
                cout << "Enter Car Make: ";
                getline(cin, car_make);
                cout << "Enter Car Model: ";
                getline(cin, car_model);
                cout << "Enter Car Price: ";
                cin >> car_price;
                cout << "Enter Car Seating Capacity: ";
                cin >> car_seating_capacity;
                cout << "Enter Car Ground Clearance: ";
                cin >> car_ground_clearance;
                cin.ignore();
                getline(cin, availability);
                cout << "Enter Car Availability(yes/no) : ";
                cin >> availability;
                cout << "Enter Cargo Space : ";
                cin >> cargo_space;
                cout << "Enter Fuel Type : ";
                cin >> fuel_type;
                Hatchback::set_car_id(car_id);
                Hatchback::set_car_make(car_make);
                Hatchback::set_car_model(car_model);
                Hatchback::set_car_price(car_price);
                Hatchback::set_car_seating_capacity(car_seating_capacity);
                Hatchback::set_car_ground_clearance(car_ground_clearance);
                Hatchback::set_car_availability(availability);
                Hatchback::set_cargo_space(cargo_space);
                Hatchback::set_fuel_type(fuel_type);
            }
            fout << Hatchback::toString() << endl;
        }
        fin.close();
        fout.close();
        remove("Hatchback.txt");
        rename("temp.txt", "Hatchback.txt");
        if (!found) {
            cout << "Hatchback with ID " << id << " not found." << endl;
        }
        else {
            cout << "Hatchback updated successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void Hatchback::del() {
    int id;
    cout << "Enter the ID of the Hatchback to delete: ";
    cin >> id;
    ifstream fin("Hatchback.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
        while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> cargo_space >> fuel_type) {
            if (car_id == id) {
                found = true;
            }
            else {
                fout << car_id << "\t" << car_make << "\t" << car_model << "\t" << car_price << "\t" << car_seating_capacity << "\t" << car_ground_clearance << "\t" << availability << "\t" << cargo_space << "\t" << fuel_type << endl;
            }
        }
        fin.close();
        fout.close();
        remove("Hatchback.txt");
        rename("temp.txt", "Hatchback.txt");
        if (!found) {
            cout << "Hatchback with ID " << id << " not found." << endl;
        }
        else {
            cout << "Hatchback with ID " << id << " deleted successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void Hatchback::menu(Hatchback& obj) {
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
ostream& operator<<(ostream& cout, const Hatchback& obj) {
    cout << "Car ID : " << obj.get_car_id() << endl;
    cout << "Car Make : " << obj.get_car_make() << endl;
    cout << "Car Model : " << obj.get_car_model() << endl;
    cout << "Car Price : " << obj.get_car_price() << endl;
    cout << "Car Seating Capacity : " << obj.get_car_seating_capacity() << endl;
    cout << "Car Ground Clearance : " << obj.get_car_ground_clearance() << endl;
    cout << "Car Availability : " << obj.get_car_availability() << endl;
    cout << "Car Cargo Space : " << obj.get_cargo_space() << endl;
    cout << "Car Fuel Type : " << obj.get_fuel_type() << endl;
    return cout;
}
istream& operator>>(istream& cin, Hatchback& obj) {
    int car_id, car_seating_capacity, car_ground_clearance, cargo_space; string car_make, car_model, availability, fuel_type; float car_price;
    cout << "Enter Car ID: ";
    cin >> car_id;
    cin.ignore();
    cout << "Enter Car Make: ";
    getline(cin, car_make);
    cout << "Enter Car Model: ";
    getline(cin, car_model);
    cout << "Enter Car Price: ";
    cin >> car_price;
    cout << "Enter Car Seating Capacity: ";
    cin >> car_seating_capacity;
    cout << "Enter Car Ground Clearance: ";
    cin >> car_ground_clearance;
    cin.ignore();
    cout << "Enter Car Availability : ";
    getline(cin, availability);
    cout << "Enter Offroad Capability: ";
    cin >> cargo_space;
    cout << "Enter Towing Capacity: ";
    cin >> fuel_type;
    obj.set_car_id(car_id);
    obj.set_car_make(car_make);
    obj.set_car_model(car_model);
    obj.set_car_price(car_price);
    obj.set_car_seating_capacity(car_seating_capacity);
    obj.set_car_ground_clearance(car_ground_clearance);
    obj.set_car_availability(availability);
    obj.set_cargo_space(cargo_space);
    obj.set_fuel_type(fuel_type);
    obj.store_to_file();
    return cin;
}