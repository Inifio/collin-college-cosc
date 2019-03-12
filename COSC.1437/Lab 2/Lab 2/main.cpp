//
//  main.cpp
//  Lab 2
//
//  Created by Lawson Zeugin
//  Copyright © 2017 Lawson Zeugin. All rights reserved.
//

#include <iostream>

using namespace std;

class NumDays {
    
private:
    
    int hours;
    float day;
    
public:
    
    NumDays() {
        hours = 0;
        day = 0.0;
    };
    
    NumDays(int h) {
        hours = h;
        day = float(h/8.0);
    };
    
    int getHour() {
        return hours;
    }
    
    float getDay() {
        return day;
    }
    
    NumDays operator +(NumDays obj) {
        int h = getHour() + obj.getHour();
        NumDays temp(h);
        return temp;
    }
    
    NumDays operator -(NumDays obj) {
        int h = getHour() - obj.getHour();
        NumDays temp(h);
        return temp;
    }
    
    
    
    const NumDays& operator++() {
        ++hours;
        day = float(hours/8.0);
        return *this;
    }
    const NumDays& operator--() {
        --hours;
        day = float(hours/8.0);
        return *this;
    }
    
    
    const NumDays operator++(int) {
        NumDays temp(*this);
        ++hours;
        day = float(hours/8.0);
        return temp;
    }
    const NumDays operator--(int) {
        NumDays temp(*this);
        --hours;
        day=float(hours/8.0);
        return temp;
    }
    
};


int main() {
    NumDays objOne(1),objTwo(8),objThree,objFour;
    
    cout << "Defualt obj" << endl;  // DEFUALT OBJ
    
    cout << "objOne: \t\t\t\t\t-> Day:" << objOne.getDay() << "\tHour:" << objOne.getHour() << endl;
    cout << "objTwo: \t\t\t\t\t-> Day:" << objTwo.getDay() << "\t\tHour:" << objTwo.getHour() << endl;
    
    cout << "\nOverloaded obj" << endl; // OVERLOADED OBJ
    
    objThree = objTwo - objOne; // OPERATOR
    cout << "'objThree = objTwo - objOne' \t-> Day:" << objThree.getDay() << "\tHour:" << objThree.getHour() << endl;
    
    objThree = objOne + objTwo;  // OPERATOR
    cout << "'objThree = objOne + objTwo' \t-> Day:" << objThree.getDay() << "\tHour:" << objThree.getHour() << endl;
    
    objFour = objThree++;    // OPERATOR
    cout <<"'objFour = objThree++' \t\t\t-> Day:" <<objFour.getDay() << "\tHour:" << objFour.getHour() << endl;
    
    objFour = ++objThree;    // OPERATOR
    cout << "'objFour = ++objThree' \t\t\t-> Day:" << objFour.getDay() << "\tHour:" << objFour.getHour() << endl;
    
    objFour = objThree--;    // OPERATOR
    cout << "'objFour = objThree--' \t\t\t-> Day:" << objFour.getDay() << "\tHour:" << objFour.getHour() << endl;
    
    objFour = --objThree;    // OPERATOR
    cout << "'objFour = --objThree' \t\t\t-> Day:" << objFour.getDay() << "\tHour:" << objFour.getHour() << endl;
    
};
