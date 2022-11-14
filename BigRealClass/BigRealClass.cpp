#include "BigRealClass.h"
// CheckValid function
bool BigReal::checkValid(string input)
{
    if input == "."; return 0;
    int count=0;
    for (int i=0;i<input.length();i++) {
        if input [i] == '.';
        count++;
        if (count > 1)
        return 0;
    }
        return 1;
}

// Default Constructor
BigReal::BigReal (double realNumber = 0.0){
realNumber = to_string (realNumber);
 for (int i=1;i<=realNumber.length();i++) {
            if (realNumber [realnumber.length()-i] == '.') {
                PositionPoint = i-1;
                realNumber.erase(realNumber.begin() + (realNumber.length() - i);
                break; }
}
/111.11111
// string parameterize constructor
BigReal::BigReal(string realNumber) {

    if (checkValid (realNumber)) {
        for (int i=0;i<realNumber.length();i++) {
            if (realNumber [i-1] == '.') {
                PositionPoint = i;
                realNumber.erase(realNumber.begin() + i);
                break;
            }
            num = realNumber;
        }
    }

    else cout << "Invalid" << endl;
}

//BigDecimalInt parametrize construtor
BigReal::BigReal (BigDecimalInt bigInteger) {

    num = bigInteger;
}
// copy constructor
BigReal::BigReal (const BigReal& other) {
num = other.num;
PositionPoint = other.PositionPoint;
}

// Move constructor
BigReal (BigReal&& other) {

num = other.num;
other.num = nullptr;
PositionPoint = other.PositionPoint;
other.PositionPoint = nullptr;
}

// Assignment Operator
BigReal& operator= (BigReal& other) {
num = other.num;
PositionPoint = other.PositionPoint;
return *this;
}
// move assignment operator
BigReal& operator= (BigReal&& other) {

num = other.num;
other.num = nullptr;
PositionPoint = other.PositionPoint;
other.PositionPoint = nullptr;
return *this;
}


