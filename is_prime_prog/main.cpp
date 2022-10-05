#include <iostream>
#include <math.h> 
using namespace std;


bool is_prime(int i) {
    int x;
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
    cout << "Tapez un entier :" << endl;

    int i;
    bool f = false;
    string R;
    while (1) {
        cin >> i;

        if (is_prime(i)) R = "True";
        else R = "False";

        cout << i << " is a prime : " << R << endl;
        if (!cin) f = true;
    }

}