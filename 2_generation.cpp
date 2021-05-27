#include <iostream>
#include <cmath>
#include <random>
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

int main(int argc, char **argv)
{
    mt19937_64 rnd(clock());
    uint64_t prostoe_chislo;
    int k = 0;
    while (k != 3){
        prostoe_chislo = rnd();
        if (TrialDivision(prostoe_chislo)){
            k+=1;
            cout << "Простое число: " << prostoe_chislo << endl;
        }
    }
    return 0;
}
