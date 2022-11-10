#include "BigReal.h"

int BigReal::mk_sm_sz(string& another) {
	bool is_int = true;
	string num1_int = "", num1_frac = "";
	string num2_int = "", num2_frac = "";
	for (int i = 0; i < big_real.length(); i++) {
		if (big_real[i] != '.' && is_int)
			num1_int += big_real[i];
		else if (!is_int)
			num1_frac += big_real[i];
		else
			is_int = false;
	}

	is_int = true;
	for (int i = 0; i < another.length(); i++) {
		if (another[i] != '.' && is_int)
			num2_frac += another[i];
		else if (!is_int)
			num2_int += another[i];
		else
			is_int = false;
	}

	if (num1_int == "")
		num1_int = "0";

	if (num1_frac == "")
		num1_frac = "0";

	if (num2_int == "")
		num2_int = "0";

	if (num2_frac == "")
		num2_frac = "0";

	if (num1_frac.length() > num2_frac.length())
		num2_frac += string(num1_frac.length() - num2_frac.length(), '0');
	else if (num2_frac.length() > num1_frac.length())
		num1_frac += string(num2_frac.length() - num1_frac.length(), '0');

	big_real = num1_int + num1_frac;
	another = num2_int + num2_frac;

	return num1_frac.length();
}

BigReal BigReal::operator+ (BigReal& other) {
	BigReal res_real;
	BigDecimalInt res_int;
	int dot_pos = mk_sm_sz(other.big_real);
	big_decimal_int = BigDecimalInt(big_real);
	other.big_decimal_int = BigDecimalInt(other.big_real);
	res_int = big_decimal_int + other.big_decimal_int;
	res_int.getNumber().insert(res_int.getNumber().end() - dot_pos, '.');
	big_real.insert(big_real.end() - dot_pos, '.');
	res_real = BigReal(res_int.getNumber());
	return res_real;
}

BigReal BigReal::operator- (BigReal& other) {
	BigReal res_real;
	BigDecimalInt res_int;
	int dot_pos = mk_sm_sz(other.big_real);
	big_decimal_int = BigDecimalInt(big_real);
	other.big_decimal_int = BigDecimalInt(other.big_real);
	res_int = big_decimal_int - other.big_decimal_int;
	res_int.getNumber().insert(res_int.getNumber().end() - dot_pos, '.');
	big_real.insert(big_real.end() - dot_pos, '.');
	res_real = BigReal(res_int.getNumber());
	return res_real;
}