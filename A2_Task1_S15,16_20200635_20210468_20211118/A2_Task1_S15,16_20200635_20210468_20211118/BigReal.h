#pragma once
#include "BigDecimalIntClass.h"
using namespace std;

class BigReal
{
	BigDecimalInt big_decimal_int;
	string big_real;
	char sign;
	int mk_sm_sz(string& another);
public:
	BigReal operator+ (BigReal& other);
	BigReal operator- (BigReal& other);
};

