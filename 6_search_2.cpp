#include <iostream>
#include <cmath>
using namespace std;

bool TrialDivision(uint64_t n)
{
    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (uint64_t i = 3; i <= (uint64_t) sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}

bool SearchBit(uint64_t n)
{
    int k = 0;
    while(n) {
        k += (n & 1);
        n >>= 1;
        if (k > 3)
            return false;
    }
    if (k==3) {
        return true;
    }
    return false;
}
int main ()
{
    uint64_t n;
    for (n = 0x80000001; n <= 0xFFFFFFFF; n++) {
        if (TrialDivision(n) and SearchBit(n)) {
            cout << dec << "Десятичное: " << n << " Шестнадцатеричное: " << hex << n << endl;
        }
    }
    return 0;
}
