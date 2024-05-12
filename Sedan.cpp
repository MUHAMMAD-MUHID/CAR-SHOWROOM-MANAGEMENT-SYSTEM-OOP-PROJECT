#include <fstream>
#include <iostream>
#include<string>
#include <sstream>
#include "Sedan.h"
#include "Car.h"
using namespace std;

Sedan::Sedan() : Car() {
    trunk_capacity = 0.0;
    fuel_efficiency = 0.0;
}
Sedan::Sedan(int car_id, string car_make, string car_model, float car_price, int car_seating_capacity, int car_ground_clearance, string is_car_available, float trunk_capacity, float fuel_efficiency) : Car(car_id, car_make, car_model, car_price, car_seating_capacity, car_ground_clearance, is_car_available) {
    this->trunk_capacity = trunk_capacity;
    this->fuel_efficiency = fuel_efficiency;
}
Sedan::Sedan(const Sedan& obj) : Car(obj) {
    this->trunk_capacity = obj.trunk_capacity;
    this->fuel_efficiency = obj.fuel_efficiency;
}
Sedan::~Sedan() {}
void Sedan::set_trunk_capacity(float trunk_capacity) {
    this->trunk_capacity = trunk_capacity;
}
void Sedan::set_fuel_efficiency(float fuel_efficiency) {
    this->fuel_efficiency = fuel_efficiency;
}
float Sedan::get_trunk_capacity()const {
    return trunk_capacity;
}
float Sedan::get_fuel_efficiency()const {
    return fuel_efficiency;
}
string Sedan::toString() {
    return Car::tostring() + "\t" + to_string(trunk_capacity) + "\t" + to_string(fuel_efficiency);
}
void Sedan::store_to_file() {
    ofstream fout("Sedan.txt", ios::app);
    if (fout.is_open()) {
        fout << toString() << endl;
        fout.close();
        cout << "\nData Stored To Sedan File";
    }
    else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}
void Sedan::view_from_file() {
    ifstream fin("Sedan.txt");
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
void Sedan::search() {
    int id;
    cout << "Enter the ID of the Sedan to search: ";
    cin >> id;

    ifstream fin("Sedan.txt");
    if (fin.is_open()) {
        bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
        while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> trunk_capacity >> fuel_efficiency) {
            if (car_id == id) {
                found = true;
                cout << "\nCar ID : " << car_id;
                cout << "\nCar Make : " << car_make;
                cout << "\nCar Model : " << car_model;
                cout << "\nCar Price : " << car_price;
                cout << "\nCar Seating Capacity : " << car_seating_capacity;
                cout << "\nCar Availability : " << availability;
                cout << "\nCar Trunk Capacity : " << trunk_capacity;
                cout << "\nCar Fuel Efficiency : " << fuel_efficiency;
            }
            fin.close();
            if (!found) {
                cout << "Sedan with ID " << id << " not found." << endl;
            }
        }
    }
    else {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}
void Sedan::update() {
    int id;
    cout << "Enter the ID of the Sedan to update: ";
    cin >> id;
    ifstream fin("Sedan.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
        while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> trunk_capacity >> fuel_efficiency) {
            if (car_id == id) {
                found = true;
                cout << "Enter Car ID : ";
                cin >> car_id;
                cin.ignore();
                cout << "Enter Car Make : ";
                getline(cin, car_make);
                cout << "Enter Car Model : ";
                getline(cin, car_model);
                cout << "Enter Car Price : ";
                cin >> car_price;
                cout << "Enter Car Seating Capacity : ";
                cin >> car_seating_capacity;
                cout << "Enter Car Ground Clearance : ";
                cin >> car_ground_clearance;
                cin.ignore();
                getline(cin, availability);
                cout << "Enter Car Availability(yes/no) : ";
                cin >> availability;
                cout << "Enter Trunk Capacity : ";
                cin >> trunk_capacity;
                cout << "Enter Fuel Efficiency : ";
                cin >> fuel_efficiency;
                Sedan::set_car_id(car_id);
                Sedan::set_car_make(car_make);
                Sedan::set_car_model(car_model);
                Sedan::set_car_price(car_price);
                Sedan::set_car_seating_capacity(car_seating_capacity);
                Sedan::set_car_ground_clearance(car_ground_clearance);
                Sedan::set_car_availability(availability);
                Sedan::set_trunk_capacity(trunk_capacity);
                Sedan::set_fuel_efficiency(fuel_efficiency);
            }
            fout << Sedan::toString() << endl;
        }
        fin.close();
        fout.close();
        remove("Sedan.txt");
        rename("temp.txt", "Sedan.txt");
        if (!found) {
            cout << "Sedan with ID " << id << " not found." << endl;
        }
        else {
            cout << "Sedan updated successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void Sedan::del() {
    int id;
    cout << "Enter the ID of the Sedan to delete : ";
    cin >> id;
    ifstream fin("Sedan.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
        while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> trunk_capacity >> fuel_efficiency) {
            if (car_id == id) {
                found = true;
            }
            else {
                fout << car_id << "\t" << car_make << "\t" << car_model << "\t" << car_price << "\t" << car_seating_capacity << "\t" << car_ground_clearance << "\t" << availability << "\t" << trunk_capacity << "\t" << fuel_efficiency << endl;
            }
        }
        fin.close();
        fout.close();
        remove("Sedan.txt");
        rename("temp.txt", "Sedan.txt");
        if (!found) {
            cout << "Sedan with ID " << id << " not found." << endl;
        }
        else {
            cout << "Sedan with ID " << id << " deleted successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void Sedan::menu(Sedan& obj) {
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
ostream& operator<<(ostream& cout, const Sedan& obj) {
    cout << "Car ID : " << obj.get_car_id() << endl;
    cout << "Car Make : " << obj.get_car_make() << endl;
    cout << "Car Model : " << obj.get_car_model() << endl;
    cout << "Car Price : " << obj.get_car_price() << endl;
    cout << "Car Seating Capacity : " << obj.get_car_seating_capacity() << endl;
    cout << "Car Ground Clearance : " << obj.get_car_ground_clearance() << endl;
    cout << "Car Availability : " << obj.get_car_availability() << endl;
    cout << "Car Trunk Capacity : " << obj.get_trunk_capacity() << endl;
    cout << "Car Fuel Efficiency : " << obj.get_fuel_efficiency() << endl;
    return cout;
}
istream& operator>>(istream& cin, Sedan& obj) {
    int car_id, car_seating_capacity, car_ground_clearance, trunk_capacity, fuel_efficiency; string car_make, car_model, availability; float car_price;
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
    cin >> trunk_capacity;
    cout << "Enter Towing Capacity: ";
    cin >> fuel_efficiency;
    obj.set_car_id(car_id);
    obj.set_car_make(car_make);
    obj.set_car_model(car_model);
    obj.set_car_price(car_price);
    obj.set_car_seating_capacity(car_seating_capacity);
    obj.set_car_ground_clearance(car_ground_clearance);
    obj.set_car_availability(availability);
    obj.set_trunk_capacity(trunk_capacity);
    obj.set_fuel_efficiency(fuel_efficiency);
    obj.store_to_file();
    return cin;
}