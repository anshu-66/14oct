#include <iostream>
using namespace std;

class Vehicle {
protected:
    string vehicleNumber;
    string ownerName;
    int hours;

public:
    Vehicle(string v, string n, int h) {
        vehicleNumber = v;
        ownerName = n;
        hours = h;
    }

    void showDetails() {
        cout << "Vehicle Number: " << vehicleNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Total Hours: " << hours << endl;
    }

    virtual int calculateFee() = 0;

    virtual ~Vehicle() {}
};

class Bike : public Vehicle {
public:
    Bike(string v, string n, int h) : Vehicle(v, n, h) {}

    int calculateFee() override {
        return hours * 20;
    }
};

class Car : public Vehicle {
public:
    Car(string v, string n, int h) : Vehicle(v, n, h) {}

    int calculateFee() override {
        return hours * 50;
    }
};

class Truck : public Vehicle {
public:
    Truck(string v, string n, int h) : Vehicle(v, n, h) {}

    int calculateFee() override {
        return hours * 100;
    }
};

int main() {
    Bike b("BIKE101", "Rahul", 3);
    Car c("CAR101", "Amit", 4);
    Truck t("TRUCK101", "Priya", 2);

    b.showDetails();
    cout << "Parking Fee: " << b.calculateFee() << endl;

    cout << endl;
    c.showDetails();
    cout << "Parking Fee: " << c.calculateFee() << endl;

    cout << endl;
    t.showDetails();
    cout << "Parking Fee: " << t.calculateFee() << endl;
    return 0;
}
