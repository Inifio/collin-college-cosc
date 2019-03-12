//
//  main.cpp
//  Lab 5
//
//  Created by Lawson Zeugin on 4/20/17.
//  Copyright © 2017 Lawson Zeugin. All rights reserved.
//

#include<iostream>
#include<string>

using namespace std;

class Ship {    // SHIP CLASS
private:
    string shipName;
    int yearBuilt;
public:
    void setShipName(string str)
        { shipName = str; }
    
    void setYear(int y)
        { yearBuilt = y; }
    
    int getYear()
        { return yearBuilt; }
    
    string getShipName()
        { return shipName; }
    
    Ship(string str="",int y=0) {
        setShipName(str);
        setYear(y);
    }
    
    void print()
        { cout <<"Ship name is " << shipName<< " and it was built in year " << yearBuilt << endl; }
};  // END SHIP CLASS

class CruiseShip: public Ship { // CLASS CRUSIE SHIP DERRIVED FROM CLASS SHIP
private:
    int maxPassengers;
public:
    CruiseShip(string str="",int year=0,int pass=0):Ship(str,year)
        { setPassengers(pass); }
    
    void setPassengers(int pass)
        { maxPassengers = pass; }
    
    int getPassengers()
        { return maxPassengers; }
    
    void print()
        { cout <<"Ship name is " << getShipName()<< " and maximum number of passengers are " << maxPassengers << endl; }
};  // END CLASS CRUSIESHIP

class CargoShip : public Ship { // CLASS CARGOSHIP DERRIVED FROM CLASS SHIP
private:
    int cargoCapacity;
public:
    CargoShip(string str="",int year=0,int pass=0):Ship(str,year)
        { setCapacity(pass); }
    void setCapacity(int pass)
        { cargoCapacity = pass; }
    int getCapacity()
        { return cargoCapacity; }
    void print()
        { cout <<"Ship name is " << getShipName()<< " and its Capacity is " << cargoCapacity << " Tonnes." << endl; }
};  // END CLASS CARGOSHIP


// FUNCTIONS
void getData(string& shipName,int& yearBuilt) {
    cout <<"Enter the Ship's name :";
    cin >> shipName;
    cout << endl;
    cout <<"Enter year in which ship was built (yyyy):";
    cin >> yearBuilt;
    cout << endl;
}
void getDataCruise(string& shipName,int& yearBuilt,int& maxPassengers) {
    getData(shipName,yearBuilt);
    cout << "Enter number of passengers on ship :";
    cin >> maxPassengers;
    cout << endl;
}
void getDataCargo(string& shipName,int& yearBuilt,int& shipCapacity) {
    getData(shipName,yearBuilt);
    cout << "Enter the capacity of ship. :";
    cin >> shipCapacity;
    cout << endl;
}

// MAIN DRIVER FUNCTION
int main() {
    
    // Declaring Variables
    string shipName;
    int yearBuilt;
    int maxPassengers;
    int shipCapacity;
    
    
    //start building Ships now..
    getData(shipName, yearBuilt);
    
    //built object 1
    Ship object1(shipName,yearBuilt);
    object1.print();
    getData(shipName,yearBuilt);
    
    //built object 1
    Ship object2;
    object2.setShipName(shipName);
    object2.setYear(yearBuilt);
    object2.print();
    
    //start building Cruise Ships now..
    getDataCruise(shipName,yearBuilt,maxPassengers);
    
    //built object 1
    CruiseShip cruiseObjectOne(shipName,yearBuilt,maxPassengers);
    cruiseObjectOne.print();
    getDataCruise(shipName,yearBuilt,maxPassengers);
    
    //built object 2
    CruiseShip cruiseObjectTwo;
    cruiseObjectTwo.setShipName(shipName);
    cruiseObjectTwo.setYear(yearBuilt);
    cruiseObjectTwo.setPassengers(maxPassengers);
    cruiseObjectTwo.print();
    
    //start building Cargo Ships now..
    getDataCargo(shipName,yearBuilt,shipCapacity);
    
    //built object 1
    CargoShip cargoObjectOne(shipName,yearBuilt,shipCapacity);
    cargoObjectOne.print();
    getDataCargo(shipName,yearBuilt,shipCapacity);
    
    //built object 2
    CargoShip cargoObjectTwo;
    cargoObjectTwo.setShipName(shipName);
    cargoObjectTwo.setYear(yearBuilt);
    cargoObjectTwo.setCapacity(shipCapacity);
    cargoObjectTwo.print();
    
    //system("pause");
    return 0;
}
