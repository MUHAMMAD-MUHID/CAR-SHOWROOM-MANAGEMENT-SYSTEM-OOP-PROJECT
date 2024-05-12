#ifndef SHOWROOM_H
#define SHOWROOM_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Showroom {
private:
	int id;string name, location;
public:
	Showroom() {
		id = 0;
		name = "n/a";
		location = "n/a";
	}
	Showroom(int s_id, string s_name, string s_location) {
		id = s_id;
		name = s_name;
		location = s_location;
	}
	Showroom(Showroom& obj) {
		this->id = obj.id;
		this->name = obj.name;
		this->location = obj.location;
	}
	void setid(int s_id) {
		id = s_id;
	}
	void setname(string name) {
		this->name = name;
	}
	void setlocation(string location) {
		this->location = location;
	}
	int getid() {
		return id;
	}
	string getname() {
		return name;
	}
	string getlocation() {
		return location;
	}
	string toString() {
		return to_string(id) + "\t" + name + "\t" + location;
	}
	void store_to_file() {
		ofstream fout;
		fout.open("Showroom.txt", ios::app);
		if (fout.is_open()) {
			fout << toString() << endl;
			fout.close();
			cout << "\nData Stored To Showroom File";
		}
		else {
			cerr << "Error: Unable to open file for writing." << endl;
		}
	}
	void view_from_file() {
		ifstream fin;
		fin.open("Showroom.txt");
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
	void search() {
		int id;
		cout << "Enter the ID of the Showroom to search: ";
		cin >> id;

		ifstream fin;
		fin.open("Showroom.txt");
		if (fin.is_open()) {
			bool found = false;
			while (fin >> id >> name >> location) {
				if (id == id) {
					found = true;
					cout << "\nShowroom ID : " << id;
					cout << "\nShowroom Name : " << name;
					cout << "\nShowroom  Location : " << location;
				}
				fin.close();
				if (!found) {
					cout << "Showroom with ID " << id << " not found." << endl;
				}
			}
		}
		else {
			cerr << "Error: Unable to open file for reading." << endl;
		}
	}
	void update() {
		int id;
		cout << "Enter the ID of the Showroom to update: ";
		cin >> id;
		ifstream fin;
		fin.open("Showroom.txt");
		ofstream fout;
		fout.open("temp.txt");
		if (fin.is_open() && fout.is_open()) {
			bool found = false;
			while (fin >> id >> name >> location) {
				if (id == id) {
					found = true;
					cout << "Enter Showroom ID : : ";
					cin >> id;
					cout << "Enter Showroom Name : ";
					cin >> name;
					cout << "Enter Showroom Location : ";
					cin >> location;
					setname(name);
					setid(id);
					setlocation(location);
				}
				fout << toString() << endl;
			}
			fin.close();
			fout.close();
			remove("Showroom.txt");
			rename("temp.txt", "Showroom.txt");
			if (!found) {
				cout << "Showroom with ID " << id << " not found." << endl;
			}
			else {
				cout << "Showroom updated successfully." << endl;
			}
		}
		else {
			cerr << "Error: Unable to open file for reading or writing." << endl;
		}
	}
	void del() {
		int id;
		cout << "Enter the ID of the Showroom to delete: ";
		cin >> id;
		ifstream fin;
		fin.open("Showroom.txt");
		ofstream fout;
		fout.open("temp.txt");
		if (fin.is_open() && fout.is_open()) {
			bool found = false;
			while (fin >> id >> name >> location) {
				if (id == id) {
					found = true;
				}
				else {
					fout << id << "\t" << name << "\t" << location << "\n";
				}
			}
			fin.close();
			fout.close();
			remove("Showroom.txt");
			rename("temp.txt", "Showroom.txt");
			if (!found) {
				cout << "Showroom with ID " << id << " not found." << endl;
			}
			else {
				cout << "Showroom with ID " << id << " deleted successfully." << endl;
			}
		}
		else {
			cerr << "Error: Unable to open file for reading or writing." << endl;
		}
	}
	void menu() {
		int choice;
		cout << "\nMenu 1- add 2- view 3- update 4- search 5- delete";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Enter Showroom ID: ";
			cin >> id;
			cin.ignore();
			cout << "Enter Showroom Name : ";
			getline(cin, name);
			cout << "Enter Showroom location : ";
			getline(cin, location);
			setid(id);
			setname(name);
			setlocation(location);
			store_to_file();
			break;
		}
		case 2:
		{
			view_from_file();
			break;
		}
		case 3:
		{
			update();
			break;
		}
		case 4:
		{
			search();
			break;
		}
		case 5:
		{
			del();
			break;
		}
		default:
		{
			cout << "\nInvalid Choice";
			break;
		}
		}
	}
};
#endif // !SHOWROOM_H
