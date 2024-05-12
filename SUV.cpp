#include <fstream>
#include <iostream>
#include<string>
#include <sstream>
#include "SUV.h"
#include "Car.h"
using namespace std;

SUV::SUV() : Car() {
    offroad_capability = 0;
    towing_capacity = 0;
}
SUV::SUV(int car_id, string car_make, string car_model, float car_price, int car_seating_capacity, int car_ground_clearance, string is_car_available, int offroad_capability, int towing_capacity) : Car(car_id, car_make, car_model, car_price, car_seating_capacity, car_ground_clearance, is_car_available) {
    this->offroad_capability = offroad_capability;
    this->towing_capacity = towing_capacity;
}
SUV::SUV(const SUV& obj) : Car(obj) {
    this->offroad_capability = obj.offroad_capability;
    this->towing_capacity = obj.towing_capacity;
}
SUV::~SUV() {}
void SUV::set_offroad_capability(int offroad_capability) {
    this->offroad_capability = offroad_capability;
}
void SUV::set_towing_capacity(int towing_capacity) {
    this->towing_capacity = towing_capacity;
}
int SUV::get_offroad_capability()const {
    return offroad_capability;
}
int SUV::get_towing_capacity()const {
    return towing_capacity;
}
string SUV::toString() {
    return Car::tostring() + "\t" + to_string(offroad_capability) + "\t" + to_string(towing_capacity);
}
void SUV::store_to_file() {
    ofstream fout("SUV.txt", ios::app);
    if (fout.is_open()) {
        fout << toString() << endl;
        fout.close();
        cout << "\nData Stored To SUV File";
    }
    else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}
void SUV::view_from_file() {
    ifstream fin("SUV.txt");
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
void SUV::search() {
    int id;
    cout << "Enter the ID of the SUV to search: ";
    cin >> id;

    ifstream fin("SUV.txt");
    if (fin.is_open()) {
        bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
        while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> offroad_capability >> towing_capacity) {
            if (car_id == id) {
                found = true;
                cout << "\nCar ID: " << car_id;
                cout << "\nCar Make: " << car_make;
                cout << "\nCar Model: " << car_model;
                cout << "\nCar Price: " << car_price;
                cout << "\nCar Seating Capacity: " << car_seating_capacity;
                cout << "\nCar Availability: " << availability;
                cout << "\nCar Off-Road Capability: " << offroad_capability;
                cout << "\nCar Towing Capacity: " << towing_capacity;
            }
            fin.close();
            if (!found) {
                cout << "SUV with ID " << id << " not found." << endl;
            }
        }
    }
    else {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}
void SUV::update() {
    int id;
    cout << "Enter the ID of the SUV to update: ";
    cin >> id;
    ifstream fin("SUV.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
        while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> offroad_capability >> towing_capacity) {
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
                cout << "Enter Offroad Capability: ";
                cin >> offroad_capability;
                cout << "Enter Towing Capacity: ";
                cin >> towing_capacity;
                SUV::set_car_id(car_id);
                SUV::set_car_make(car_make);
                SUV::set_car_model(car_model);
                SUV::set_car_price(car_price);
                SUV::set_car_seating_capacity(car_seating_capacity);
                SUV::set_car_ground_clearance(car_ground_clearance);
                SUV::set_car_availability(availability);
                SUV::set_offroad_capability(offroad_capability);
                SUV::set_towing_capacity(towing_capacity);
            }
            fout << SUV::toString() << endl;
        }
        fin.close();
        fout.close();
        remove("SUV.txt");
        rename("temp.txt", "SUV.txt");
        if (!found) {
            cout << "SUV with ID " << id << " not found." << endl;
        }
        else {
            cout << "SUV updated successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void SUV::del() {
    int id;
    cout << "Enter the ID of the SUV to delete: ";
    cin >> id;
    ifstream fin("SUV.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false; int car_id, car_seating_capacity, car_ground_clearance; string car_make, car_model, availability; float car_price;
        while (fin >> car_id >> car_make >> car_model >> car_price >> car_seating_capacity >> car_ground_clearance >> availability >> offroad_capability >> towing_capacity) {
            if (car_id == id) {
                found = true;
            }
            else {
                fout << car_id << "\t" << car_make << "\t" << car_model << "\t" << car_price << "\t" << car_seating_capacity << "\t" << car_ground_clearance << "\t" << availability << "\t" << offroad_capability << "\t" << towing_capacity << endl;
            }
        }
        fin.close();
        fout.close();
        remove("SUV.txt");
        rename("temp.txt", "SUV.txt");
        if (!found) {
            cout << "SUV with ID " << id << " not found." << endl;
        }
        else {
            cout << "SUV with ID " << id << " deleted successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void SUV::menu(SUV& obj) {
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
ostream& operator<<(ostream& cout, const SUV& obj) {
    cout << "Car ID : " << obj.get_car_id() << endl;
    cout << "Car Make : " << obj.get_car_make() << endl;
    cout << "Car Model : " << obj.get_car_model() << endl;
    cout << "Car Price : " << obj.get_car_price() << endl;
    cout << "Car Seating Capacity : " << obj.get_car_seating_capacity() << endl;
    cout << "Car Ground Clearance : " << obj.get_car_ground_clearance() << endl;
    cout << "Car Availability : " << obj.get_car_availability() << endl;
    cout << "Car Offroad Capability : " << obj.get_offroad_capability() << endl;
    cout << "Car Towing Capacity : " << obj.get_towing_capacity() << endl;
    return cout;
}
istream& operator>>(istream& cin, SUV& obj) {
    int car_id, car_seating_capacity, car_ground_clearance, offroad_capability, towing_capacity; string car_make, car_model, availability; float car_price;
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
    cin >> offroad_capability;
    cout << "Enter Towing Capacity: ";
    cin >> towing_capacity;
    obj.set_car_id(car_id);
    obj.set_car_make(car_make);
    obj.set_car_model(car_model);
    obj.set_car_price(car_price);
    obj.set_car_seating_capacity(car_seating_capacity);
    obj.set_car_ground_clearance(car_ground_clearance);
    obj.set_car_availability(availability);
    obj.set_offroad_capability(offroad_capability);
    obj.set_towing_capacity(towing_capacity);
    obj.store_to_file();
    return cin;
}