#include <iostream>

using namespace std;

int main()
{

BigReal n1 ("11.9000000000000000000000000000000001");
BigReal n2 ("2333333333339.1134322222222292");
BigReal n3 = n1 + n2;
cout << n3;
n3 = n3 + BigReal (0.9);
cout << n1 << endl << n2 << endl << n3 << endl;
    return 0;
}
