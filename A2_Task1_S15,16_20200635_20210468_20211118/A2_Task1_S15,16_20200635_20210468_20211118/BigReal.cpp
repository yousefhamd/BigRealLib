#include "BigReal.h"

void BigReal::mk_sm_sz(BigReal& another) {
	string res_num1 = num.getNumber(), res_num2 = another.num.getNumber();

	if (PositionPoint > another.PositionPoint)
		res_num2 += string(PositionPoint - another.PositionPoint, '0');
	else if (another.PositionPoint > PositionPoint)
		res_num1 += string(another.PositionPoint - PositionPoint, '0');

	if (num.sign() == 1)
		res_num1 = '+' + res_num1;
	else
		res_num1 = '-' + res_num1;

	if (another.num.sign() == 1)
		res_num2 = '+' + res_num2;
	else
		res_num2 = '-' + res_num2;

	num = res_num1;
	another.num = res_num2;
}

// CheckValid function
bool BigReal::checkValid(string input)
{
	if (input == ".") return 1;
	int count = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '.')
			count++;
		if (count > 1)
			return 0;
	}
	return 1;
}

//// Default Constructor
//BigReal::BigReal(double realNumber = 0.0) {
//	realNumber = to_string(realNumber);
//	for (int i = 1; i <= realNumber.length(); i++) {
//		if (realNumber[realnumber.length() - i] == '.') {
//			PositionPoint = i - 1;
//			realNumber.erase(realNumber.begin() + (realNumber.length() - i)
//		};
//		break;
//	}
//}

// string parameterize constructor
BigReal::BigReal(string realNumber) {

	if (checkValid(realNumber)) {
		for (int i = 1; i <= realNumber.length(); i++) {
			if (realNumber[realNumber.length() - i] == '.') {
				PositionPoint = i - 1;
				realNumber.erase(realNumber.begin() + (realNumber.length() - i));
				break;
			}
		}
		num = realNumber;
		for (int i = realNumber.length() - PositionPoint; i < realNumber.length(); i++) {
			realPart += realNumber[i];
		}
		for (int i = 0; i < realNumber.length() - PositionPoint; i++) {
			intPart += realNumber[i];
		}
		realNumber.insert(realNumber.end() - PositionPoint, '.');
		bigReal = realNumber;
	}

	else cout << "Invalid" << endl;
}

BigReal::BigReal(BigDecimalInt bigInteger) {
	num = bigInteger;
}

// copy constructor
BigReal::BigReal(const BigReal& other) {
	num = other.num;
	PositionPoint = other.PositionPoint;
}

// Move constructor
BigReal::BigReal(BigReal&& other) {
	num = move(other.num);
	PositionPoint = move(other.PositionPoint);
}

// Assignment Operator
BigReal& BigReal::operator= (BigReal& other) {
	if (this != &other) {
		num = other.num;
		PositionPoint = other.PositionPoint;
	}
	return *this;
}

// move assignment operator
BigReal& BigReal::operator= (BigReal&& other) {
	if (this != &other) {
		num = move(other.num);
		PositionPoint = move(other.PositionPoint);
	}
	return *this;
}

BigReal BigReal::operator+ (BigReal& other) {
	BigDecimalInt res_int;
	mk_sm_sz(other);
	res_int = num + other.num;
	string tmp = "";
	if (res_int.sign() == 1)
		tmp = '+' + res_int.getNumber();
	else
		tmp = '-' + res_int.getNumber();
	tmp.insert(tmp.end() - PositionPoint, '.');
	return BigReal(tmp);
}

BigReal BigReal::operator- (BigReal& other) {
	BigDecimalInt res_int;
	mk_sm_sz(other);
	res_int = num - other.num;
	string tmp = res_int.getNumber();
	tmp.insert(tmp.end() - PositionPoint, '.');
	return BigReal(tmp);
}
/*
 bool BigReal:: operator< (BigReal anotherDec)
{

}

bool BigReal:: operator> (BigReal anotherDec)
{

}
 
bool BigReal:: operator== (BigReal anotherDec)
{

}
*/
char BigReal::Sign() {
	if (num.sign() == 1) {
		return '+';
	}
	else { return '-'; }
}


ostream& operator<<(ostream& out, BigReal& b) {
	out << b.num;
	return out;
}

BigReal BigReal:: operator=(BigReal anotherDec) {

	num = anotherDec.num;
	return *this;
}
