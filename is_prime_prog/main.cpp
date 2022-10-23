#include <iostream>
#include <math.h> 
using namespace std;


bool is_prime(long long i) {
    long long x;
    bool Prem = true;

    if (i == 0 || i == 1) {
        Prem = false;
        return Prem;
    }

    else {
        for (x = 2; x <= sqrt(i); x++)
        {
            if (i % x == 0) {
                Prem = false;
                break;
            }
        }
    }

    return Prem;
}


int main()
{
    long long i;
    bool f = false;
    string R;
    while (cin>>i) {
        if (is_prime(i)) R = "True";
        else R = "False";

        cout << i << " is a prime: " << R << endl;
        if (!cin) f = true;
    }
    return 0;
}
