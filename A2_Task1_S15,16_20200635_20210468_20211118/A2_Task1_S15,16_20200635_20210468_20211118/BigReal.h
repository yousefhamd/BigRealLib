#pragma once
#include "BigDecimalIntClass.h"
#include <string>
using namespace std;

class BigReal
{
	BigDecimalInt big_decimal_int;
	void mk_sm_sz(BigReal& another);
	BigDecimalInt num;
	int PositionPoint = -1;
	bool checkValid(string input);

public:
	//BigReal(double realNumber = 0.0); // default constructor
	BigReal(){}
	BigReal(string realNumber); // string parametrize constructor
	BigReal(BigDecimalInt bigInteger); // BigDecimalInt parameterize constructor
	BigReal(const BigReal& other); // copy constructor
	BigReal(BigReal&& other); // move constructor
	BigReal& operator= (BigReal& other); // assignment operator
	BigReal& operator= (BigReal&& other); // move assignment
	BigReal operator+ (BigReal& other);
	BigReal operator- (BigReal& other);
	string getNumber() {
		return num.getNumber();
	}
	int getPointPos() {
		return PositionPoint;
	}
};