#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string record;

class Patient {
private:
    string id;
    string name;
    string age;
    string disease;
    string address;
    string phone;

public:
    void setData();
    void getData();

    void pack();
    void unpack(string rec);

    void insert();
    void display();
    int search(string key);

    void update(string key);
    void deleteP(string key);
};

void Patient::setData() {
    cout << "Enter Patient ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Disease: ";
    cin >> disease;

    cout << "Enter Address: ";
    cin >> address;

    cout << "Enter Phone: ";
    cin >> phone;
}


void Patient::getData() {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Disease: " << disease << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "--------------------------------------\n";
}


void Patient::pack() {
    record = id + "|" + name + "|" + age + "|" + disease + "|" + address + "|" + phone + "#";
}


void Patient::unpack(string rec) {
    record = rec;

    int pos;

    pos = record.find("|");
    id = record.substr(0, pos);
    record.erase(0, pos + 1);

    pos = record.find("|");
    name = record.substr(0, pos);
    record.erase(0, pos + 1);

    pos = record.find("|");
    age = record.substr(0, pos);
    record.erase(0, pos + 1);

    pos = record.find("|");
    disease = record.substr(0, pos);
    record.erase(0, pos + 1);

    pos = record.find("|");
    address = record.substr(0, pos);
    record.erase(0, pos + 1);

    pos = record.find("#");
    phone = record.substr(0, pos);
}


void Patient::insert() {
    fstream file("patients.txt", ios::out | ios::app);

    setData();
    pack();
    file << record << endl;

    file.close();
    cout << "\nPatient inserted successfully.\n";
}


void Patient::display() {
    fstream file("patients.txt", ios::in);

    cout << "\n======= PATIENTS LIST =======\n";
    while (getline(file, record)) {
        unpack(record);
        getData();
    }

    file.close();
}


int Patient::search(string key) {
    fstream file("patients.txt", ios::in);

    int line = 0;
    while (getline(file, record)) {
        line++;
        unpack(record);

        if (id == key) {
            cout << "\nRecord Found at line: " << line << endl;
            getData();
            file.close();
            return line;
        }
    }

    file.close();
    cout << "Record Not Found.\n";
    return -1;
}


void Patient::update(string key) {
    fstream in_file("patients.txt", ios::in);
    fstream out_file("temp.txt", ios::out);

    while (getline(in_file, record)) {
        unpack(record);

        if (id == key) {
            cout << "\nEnter new updated data:\n";
            setData();
        }

        pack();
        out_file << record << endl;
    }

    in_file.close();
    out_file.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    cout << "\nRecord Updated Successfully.\n";
}


void Patient::deleteP(string key) {
    fstream in_file("patients.txt", ios::in);
    fstream out_file("temp.txt", ios::out);

    bool deleted = false;

    while (getline(in_file, record)) {
        unpack(record);

        if (id == key) {
            deleted = true;
            continue; // skip writing
        }

        pack();
        out_file << record << endl;
    }

    in_file.close();
    out_file.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (deleted)
        cout << "\nRecord Deleted Successfully.\n";
    else
        cout << "\nRecord Not Found.\n";
}


int main() {
    Patient p;
    string key;

    int choice;

    do {
        cout << "\n============= MENU =============\n";
        cout << "1. Insert Patient\n";
        cout << "2. Display All\n";
        cout << "3. Search\n";
        cout << "4. Update\n";
        cout << "5. Delete\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            p.insert();
            break;

        case 2:
            p.display();
            break;

        case 3:
            cout << "Enter ID to search: ";
            cin >> key;
            p.search(key);
            break;

        case 4:
            cout << "Enter ID to update: ";
            cin >> key;
            p.update(key);
            break;

        case 5:
            cout << "Enter ID to delete: ";
            cin >> key;
            p.deleteP(key);
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}
