#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

bool TrialDivision(int n)
{
    if (n<2)
        return false;
    if (n<4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (int i = 3; i <= sqrt(n); i+=2)
        if (n % i == 0)
            return false;
    return true;
}

int main(int argc, char **argv)
{
    mt19937 rnd(clock());
    int prostoe_chislo;
    int k = 0;
    vector<int> v(1000);
    while (k != 1000){
        prostoe_chislo = rnd();
        if (TrialDivision(prostoe_chislo)){
            v[k] = prostoe_chislo;
            k+=1;
        }
    }
    sort(v.begin(),v.end());
    cout << "Минимальное: " << v[0] << endl;
    cout << "Максимальное: " << v[999] << endl;
    return 0;
}
