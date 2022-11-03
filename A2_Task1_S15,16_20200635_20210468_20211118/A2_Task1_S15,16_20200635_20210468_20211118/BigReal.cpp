#include "BigReal.h"

int BigReal::mk_sm_sz(string& another) {
	int dot_pos = 0;
	bool is_frac = true;
	string num1_int = "", num1_frac = "";
	string num2_int = "", num2_frac = "";
	for (int i = 0; i < big_real.length(); i++) {
		if (big_real[i] != '.' && is_frac)
			num1_frac += big_real[i];
		else if (!is_frac)
			num1_int += big_real[i];
		else
			is_frac = false;
	}

	is_frac = true;
	for (int i = 0; i < another.length(); i++) {
		if (another[i] != '.' && is_frac)
			num2_frac += another[i];
		else if (!is_frac)
			num2_int += another[i];
		else
			is_frac = false;
	}

	if (num1_frac.length() > num2_frac.length())
		num2_frac += string(num1_frac.length() - num2_frac.length(), '0');
	else if (num2_frac.length() > num1_frac.length())
		num1_frac += string(num2_frac.length() - num1_frac.length(), '0');

	if (num1_int.length() > num2_int.length()) {
		num2_int = string(num1_int.length() - num2_int.length(), '0') + num2_int;
		dot_pos = num1_int.length();
	}
	else if (num2_int.length() > num1_int.length()) {
		num1_int = string(num2_int.length() - num1_int.length(), '0') + num1_int;
		dot_pos = num2_int.length();
	}

	big_real = num1_int + num1_frac;
	another = num2_int + num2_frac;
	return dot_pos;
}

BigReal BigReal::operator+ (BigReal& other) {
	BigReal res_real;
	BigDecimalInt res_int;
	int dot_pos = mk_sm_sz(other.big_real);
	big_decimal_int = BigDecimalInt(big_real);
	other.big_decimal_int = BigDecimalInt(other.big_real);
	res_int = big_decimal_int + other.big_decimal_int;
	return *this;
}

BigReal BigReal::operator- (BigReal& other) {
	return *this;
}