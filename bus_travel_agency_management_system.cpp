#include <iostream>
#include <cstring>
using namespace std;

int p = 0;  // Keeps track of the number of buses available

// Base class: Vehicle
class Vehicle {
protected:
    char vehicleNum[10];
    char driver[10];
    char arrival[10];
    char depart[10];
    char from[10];
    char to[10];

public:
    virtual void addDetails() = 0; // Pure virtual function for polymorphism
    virtual void showDetails() = 0; // Pure virtual function for polymorphism
};

// Derived class: Bus
class Bus : public Vehicle {
    char seat[8][4][10]; // Seats in the bus

public:
    void addDetails(); // Adds bus details
    void allotmentOfSeatToPassenger(); // Allots seats to passengers
    void emptySeats(); // Initializes all seats as vacant
    void showAvailableSeats(); // Shows available seats
    void showDetails(); // Shows details of the bus
    void showReservedSeats(); // Shows reserved seats

    Bus() { // Constructor to initialize seats
        emptySeats();
    }
};

Bus bus[25]; // Array of Bus objects

void Bus::addDetails() {
    cout << "Enter bus no: ";
    cin >> vehicleNum;

    cout << "\nEnter Driver's name: ";
    cin >> driver;

    cout << "\nArrival time: ";
    cin >> arrival;

    cout << "\nDeparture: ";
    cin >> depart;

    cout << "\nFrom: \t\t\t";
    cin >> from;

    cout << "\nTo: \t\t\t";
    cin >> to;

    emptySeats(); // Fill all the seats with 'vacant'

    p++; // Number of buses increases
}

void Bus::allotmentOfSeatToPassenger() {
    int seatNumber;
    char busNumber[5];
    cout << "Bus no: ";
    cin >> busNumber;

    int n;
    for (n = 0; n < p; n++) {
        if (strcmp(bus[n].vehicleNum, busNumber) == 0)
            break;
    }

    if (n == p) {
        cout << "Enter correct bus no.\n";
        return;
    }

    cout << "\nSeat Number: ";
    cin >> seatNumber;

    if (seatNumber > 32) {
        cout << "\nThere are only 32 seats available in this bus.";
    } else {
        if (strcmp(bus[n].seat[seatNumber / 4][(seatNumber % 4) - 1], "vacant") == 0) {
            cout << "Enter passenger's name: ";
            cin >> bus[n].seat[seatNumber / 4][(seatNumber % 4) - 1];
        } else {
            cout << "The seat number is already reserved.\n";
        }
    }
}

void Bus::emptySeats() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(seat[i][j], "vacant");
        }
    }
}

void Bus::showAvailableSeats() {
    char busNumber[5];
    cout << "Enter bus no: ";
    cin >> busNumber;

    int n;
    for (n = 0; n < p; n++) {
        if (strcmp(bus[n].vehicleNum, busNumber) == 0)
            break;
    }

    if (n == p) {
        cout << "Enter correct bus no: ";
        return;
    }

    bus[n].showDetails();
    bus[n].showReservedSeats();
}

void Bus::showDetails() {
    cout << "\nBus no: \t" << vehicleNum
         << "\nDriver: \t" << driver
         << "\t\tArrival time: \t" << arrival
         << "\tDeparture time: " << depart
         << "\nFrom: \t\t" << from
         << "\t\tTo: \t\t" << to << "\n";
}

void Bus::showReservedSeats() {
    int s = 0, h = 0;

    for (int i = 0; i < 8; i++) {
        cout << "\n";
        for (int j = 0; j < 4; j++) {
            s++;
            if (strcmp(seat[i][j], "vacant") == 0) {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << seat[i][j];
                h++;
            } else {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << seat[i][j];
            }
        }
    }
    cout << "\n\nThere are " << h << " seats vacant in Bus No: " << vehicleNum;
}

int main() {
    int choice;
    cout << "\t\t\t\t----------Bus Travel Agency Management System--------" << endl << endl;
    while (1) {
        cout << endl;
        cout << "\n\n";

        cout << "\t\t\t1.Add new Bus Details:\n\t\t\t"
             << "2.Reserve your seats:\n\t\t\t"
             << "3.Show the available seats in a bus:\n\t\t\t"
             << "4.Buses Available Now: \n\t\t\t"
             << "5.Exit";
        cout << endl;
    
        cout << "\n\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice) {
        case 1:
            bus[p].addDetails();
            break;

        case 2:
            bus[p].allotmentOfSeatToPassenger();
            break;

        case 3:
            bus[0].showAvailableSeats();
            break;

        case 4:
            for (int i = 0; i < p; i++) {
                bus[i].showDetails();
            }
            break;

        case 5: {
            cout << "Successfully Logged out from the Application. Visit Again!" << endl;
            exit(0);
        }
        }
    }

    return 0;
}