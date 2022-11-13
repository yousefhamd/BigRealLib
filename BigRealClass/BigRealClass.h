#ifndef BIGREAL_H
#define BIGREAL_H


class BigReal {
private:
    BigDecimalInt num;
    int PositionPoint= -1;
    bool checkValid(string input);

public:
    BigReal (double realNumber = 0.0); // default constructor
    BigReal (string realNumber); // string parametrize constructor
    BigReal (BigDecimalInt bigInteger); // BigDecimalInt parameterize constructor
    BigReal (const BigReal& other); // copy constructor
    BigReal (BigReal&& other); // move constructor
    BigReal& operator= (BigReal& other); // assignment operator
    BigReal& operator= (BigReal&& other); // move assignment

};

#endif // BIGREALCLASS_H
