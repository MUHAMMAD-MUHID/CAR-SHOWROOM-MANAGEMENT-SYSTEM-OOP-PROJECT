#include<iostream>
#include"Person.h"
#include "Customer.h"
#include"Transaction.h"
#include"Insurance.h"
#include"Service.h"
#include<string>
using namespace std;
// Constructors
Customer::Customer() : Person() , Transaction(),Car(),Insurance(),Service()
{
    customer_vehicle_status = "n/a";
    customer_payment_status = "n/a";
    membership = "n/a";

}
Customer::Customer(int person_id, string person_name, string customer_vehicle_status, string customer_payment_status, string membership, int transaction_id, float transaction_amount, int car_id, string car_make, string car_model,int insurance_id,int service_id,string insurance_type,string service_name)
    : Person(person_id, person_name) , Transaction(transaction_id,transaction_amount),Car(car_id,car_make,car_model),Insurance(insurance_id,insurance_type),Service(service_id,service_name){
    this->customer_vehicle_status = customer_vehicle_status;
    this->customer_payment_status = customer_payment_status;;
    this->membership = membership;
}
Customer::Customer(const Customer& obj) : Person(obj) , Transaction(obj) , Car(obj) , Insurance(obj) , Service(obj)
{
    this->customer_vehicle_status = obj.customer_vehicle_status;
    this->customer_payment_status = obj.customer_payment_status;
    this->membership = obj.membership;
}
// Setters
void Customer::set_customer_vehicle_status(string customer_vehicle_status) {
    this->customer_vehicle_status = customer_vehicle_status;
}
void Customer::set_customer_payment_status(string customer_payment_status) {
    this->customer_payment_status = customer_payment_status;
}
void Customer::set_customer_membership(string membership) {
    this->membership = membership;
}
// Getters
string Customer::get_customer_vehicle_status() {
    return customer_vehicle_status;
}
string Customer::get_customer_payment_status() {
    return customer_payment_status;
}
string Customer::get_customer_membership() { return membership; 
}
// Utility functions
string Customer::tostring()  {
    return Person::tostring() + Transaction::tostring_t() +Car::tostring_2() +"\t"+Insurance::tostring()+"\t" +Service::tostring()+"\t" + customer_vehicle_status + "\t" + customer_payment_status + "\t" + membership;
}
void Customer::store_to_file() {
    ofstream fout("Customer.txt", ios::app);
    if (fout.is_open()) {
        fout << tostring() << endl;
        fout.close();
        cout << "\nData Stored To Customer  File";
    }
    else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}
void Customer::view_from_file() {
    ifstream fin("Customer.txt");
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
void Customer::search() {
    int id;
    cout << "Enter the ID of the Customer to search: ";
    cin >> id;
    ifstream fin("Customer.txt");
    if (fin.is_open()) {
        bool found = false;
        int customer_id, transaction_id, car_id,insurance_id,service_id;float transaction_amount;
        string customer_name, car_make, car_model,insurance_type,service_name;
        while (fin >> customer_id >> customer_name >> transaction_id >> transaction_amount >> car_id >> car_make >> car_model >>insurance_id>>insurance_type>>service_id>>service_name>> customer_vehicle_status >> customer_payment_status>>membership) {
            if (customer_id == id) {
                found = true;
                cout << "\nCustomer ID: " << customer_id;
                cout << "\nCustomer Name: " << customer_name;
                cout << "\nCustomer Transaction ID: " << transaction_id;
                cout << "\nCustomer Transaction Amount: " << transaction_amount;
                cout << "\nCustomer Car ID: " << car_id;
                cout << "\nCustomer Car Make: " << car_make;
                cout << "\nCustomer Car Model: " << car_model;
                cout << "\nCustomer Insurance ID: " << insurance_id;
                cout << "\nCustomer Insurance Type: " << insurance_type;
                cout << "\nCustomer Service ID: " << service_id;
                cout << "\nCustomer Service Name: " << service_name;
                cout << "\nCustomer Vehicle Staus: " << customer_vehicle_status;
                cout << "\nCustomer Payment Status: " << customer_payment_status;
                cout << "\nCustomer Membership Status: " << membership;
            }
            fin.close();
            if (!found) {
                cout << "Customer with ID " << id << " not found." << endl;
            }
        }
    }
    else {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}
void Customer::update() {
    int id;
    cout << "Enter the ID of the Customer to update: ";
    cin >> id;
    ifstream fin("Customer.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false;
        int  customer_id ,transaction_id,car_id, insurance_id, service_id;float transaction_amount;
        string customer_name, car_make, car_model, insurance_type, service_name;
        while (fin >> customer_id >> customer_name >> transaction_id >> transaction_amount >> car_id >> car_make >> car_model >>insurance_id >> insurance_type >> service_id >> service_name>> customer_vehicle_status >> customer_payment_status>>membership) {
            if (customer_id == id) {
                found = true;
                cout << "Enter Customer ID: ";
                cin >> customer_id;
                cin.ignore();
                cout << "Enter Customer Name: ";
                getline(cin, customer_name);
                cout << "\nEnter Customer Transaction ID: ";cin >> transaction_id;
                cout << "\nEnter Customer Transaction Amount: ";cin >> transaction_amount;
                cout << "\nEnter Car ID: ";cin >> car_id;
                cout << "\nEnter Car Make: ";cin >> car_make;
                cout << "\nEnter Car Model: ";cin >> car_model;
                cout << "\nEnter Insurance ID: ";cin >> insurance_id;cin.ignore();
                cout << "\nEnter Insurance Type: ";getline(cin ,insurance_type);
                cout << "\nEnter Service ID: ";cin >> service_id;cin.ignore();
                cout << "\nEnter Serice Name: ";getline(cin, service_name);
                cout << "Enter Customer Vehicle Status: ";
                getline(cin, customer_vehicle_status);
                cout << "Enter Customer Payment Status: ";
                getline(cin, customer_payment_status);
                cout << "\nEnter Customer Membership: ";cin >> membership;
                fout << customer_id << "\t" << customer_name << "\t" << transaction_id << "\t" << transaction_amount << "\t" << car_id << "\t" << car_make << "\t" << car_model<< "\t" << insurance_id << "\t" << insurance_type << "\t" << service_id << "\t" << service_name << "\t" << customer_vehicle_status << "\t" << customer_payment_status << "\t" << membership << endl;
            }
        }
        fin.close();
        fout.close();
        remove("Customer.txt");
        rename("temp.txt", "Customer.txt");
        if (!found) {
            cout << "Customer with ID " << id << " not found." << endl;
        }
        else {
            cout << "Customer updated successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void Customer::del() {
    int id;
    cout << "Enter the ID of the Customer to delete: ";
    cin >> id;
    ifstream fin("Customer.txt");
    ofstream fout("temp.txt");
    if (fin.is_open() && fout.is_open()) {
        bool found = false;
        int customer_id, transaction_id,car_id,insurance_id, service_id;float transaction_amount;
        string customer_name, car_make, car_model,insurance_type, service_name;
        while (fin >> customer_id >> customer_name >> transaction_id >> transaction_amount >> car_id >> car_make >> car_model >>insurance_id >> insurance_type >> service_id >> service_name >> customer_vehicle_status >> customer_payment_status>>membership){
            if (customer_id == id) {
                found = true;
            }
            else {
                fout << customer_id << "\t" << customer_name << "\t" << transaction_id << "\t" << transaction_amount <<"\t"<<car_id<<"\t"<<car_make<<"\t"<<car_model<< "\t" << insurance_id << "\t" << insurance_type << "\t" << service_id << "\t" << service_name <<"\t" << customer_vehicle_status << "\t" << customer_payment_status <<"\t"<<membership << endl;
            }
        }
        fin.close();
        fout.close();
        remove("Customer.txt");
        rename("temp.txt", "Customer.txt");
        if (!found) {
            cout << "Customer with ID " << id << " not found." << endl;
        }
        else {
            cout << "Customer with ID " << id << " deleted successfully." << endl;
        }
    }
    else {
        cerr << "Error: Unable to open file for reading or writing." << endl;
    }
}
void Customer::menu(Customer& obj) {
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
void Customer::customer_membership(string new_membership)
{
  membership = new_membership;
}
ostream& operator<<(ostream& cout, const Customer& obj) {
    cout << "Customer ID: "<<obj.get_person_id();
    cout << "Customer Name: "<<obj.get_person_name();
    cout << "Customer Membership: " << obj.membership;
    cout << "Customer Transaction ID " << obj.get_transaction_id();
    cout << "Customer Transaction Amount " << obj.get_transaction_amount();
    cout << "Customer Car ID " << obj.get_car_id();
    cout << "Customer Car Make " << obj.get_car_make();
    cout << "Customer Car Model " << obj.get_car_model();
    cout << "\nCustomer Insurance ID: " << obj.get_Insurance_id();
    cout << "\nCustomer Insurance Type: " << obj.get_Insurance_type();
    cout << "\nCustomer Service ID: " << obj.get_service_id();
    cout << "\nCustomer Service Name: " << obj.get_service_name();
    cout << "Customer Vehicle Status: " << obj.customer_vehicle_status;
    cout << "Customer Payment Status "<<obj.customer_payment_status;
    return cout;
}
istream& operator>>(istream& cin, Customer& obj) {
    int option;
    cout << "\nWe have an offer for you \n1-) Free Service 1-year \n2-)  Free Insurance 1-year \nEnter the details for what you want:";
    cin >> option;
    int id, t_id, car_id, insurance_id, service_id;string name, car_model, car_make, insurance_type, service_name;float t_amount;
    cout << "Customer ID: ";cin >> id;
    obj.set_person_id(id);
    cin.ignore();
    cout << "Customer Name: ";
    getline(cin, name);
    obj.set_person_name(name);
    cout << "Customer Membership: ";
    getline(cin, obj.membership);
    cout << "Customer Transaction ID:";
    cin >> t_id;
    cout << "Customer Transaction Amount:";
    cin >> t_amount;
    cout << "Customer Car ID ";cin >> car_id;cin.ignore();
    cout << "Customer Car Make ";getline(cin, car_make);
    cout << "Customer Car Model "; getline(cin, car_model);
    cout << "Customer Vehicle Status: ";
    getline(cin, obj.customer_vehicle_status);
    cout << "Customer Payment Status: ";
    getline(cin, obj.customer_payment_status);
    cout << "Enter Insurance Type : ";
    getline(cin, insurance_type);
    cout << "Enter Insurance ID :";
    cin >> insurance_id;
    cin.ignore();
    cout << "Enter Service Name :";getline(cin, service_name);
    cout << "Enter Service Id :";cin >> service_id;
    obj.set_service_id(service_id);
    obj.set_service_name(service_name);
    obj.set_person_id(id);
    obj.set_person_name(name);
    obj.set_transaction_id(t_id);
    obj.set_transaction_amount(t_amount);
    obj.set_car_id(car_id);
    obj.set_car_make(car_make);
    obj.set_car_model(car_model);
    obj.set_Insurance_id(insurance_id);
    obj.set_Insurance_type(insurance_type);
    obj.set_service_id(service_id);
    obj.set_service_name(service_name);
    obj.set_customer_vehicle_status(obj.customer_vehicle_status);
    obj.set_customer_payment_status(obj.customer_payment_status);
    obj.set_customer_membership(obj.membership);
    obj.store_to_file();
    return cin;
}