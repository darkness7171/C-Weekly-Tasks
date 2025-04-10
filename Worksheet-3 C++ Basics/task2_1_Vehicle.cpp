#include <iostream>
#include <fstream>
using namespace std;
class Vehicle {
protected:
    string registrationNumber;
    string color;

public:
    Vehicle(const string& regNum, const string& clr) 
        : registrationNumber(regNum), color(clr) {}

    virtual void writeToFile(ofstream& outFile) const {
        outFile << "Vehicle Details:\n";
        outFile << "Registration Number: " << registrationNumber << "\n";
        outFile << "Color: " << color << "\n";
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int numberOfSeats;
public:
    Car(const string& regNum, const string& clr, int seats) 
        : Vehicle(regNum, clr), numberOfSeats(seats) {}

    void writeToFile(ofstream& outFile) const override {
        Vehicle::writeToFile(outFile);
        outFile << "Type: Car\n";
        outFile << "Number of Seats: " << numberOfSeats << "\n\n";
    }
};
class Bike : public Vehicle {
private:
    int engineCapacity;

public:
    Bike(const string& regNum, const string& clr, int capacity) 
        : Vehicle(regNum, clr), engineCapacity(capacity) {}

    void writeToFile(ofstream& outFile) const override {
        Vehicle::writeToFile(outFile);
        outFile << "Type: Bike\n";
        outFile << "Engine Capacity: " << engineCapacity << "cc\n\n";
    }
};
int main() {

    Car myCar("ABC123", "Red", 5);
    Bike myBike("XYZ789", "Black", 150);
    ofstream outFile("vehicles.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!\n";
        return 1;
    }
    myCar.writeToFile(outFile);
    myBike.writeToFile(outFile);
    outFile.close();
    cout << "Vehicle details have been written to vehicles.txt\n";
    return 0;
}