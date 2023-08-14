#include <iostream>
#include <cmath>
using namespace std;

void masterTheorem(double a, double b, double m, double k)
{
    double logValue = log(a) / log(b);

    string nPowerLog = "n^" + to_string(logValue);

    if (fabs(m - logValue) < 1e-9)
    {
        if (k != 0)
        {
            cout << "Master Theorem - Case 2 -" << endl;
            cout << "T(n) = O(" << nPowerLog << " * (logn)^" << k + 1 << ")" << endl;
        }
        else
        {
            cout << "Master Theorem - Case 2 " << endl;
            cout << "T(n) = O(" << nPowerLog << " * (logn))" << endl;
        }
    }
    else if (logValue > m)
    {
        cout << "Master Theorem - Case 1" << endl;
        cout << "T(n) = O(" << nPowerLog << ")" << endl;
    }
    else
    {
        string func = "n^" + to_string(m);
        if (k != 0)
        {
            if (k == 1)
            {
                func += " * (logn)";
            }
            else
            {
                func += " * (logn)^" + to_string(k);
            }
        }

        cout << "Master Theorem - Case 3 " << endl;
        cout << "T(n) = O(" << func << ")" << endl;
    }
}

int main()
{
    double a, b, k, p;
    cin >> a >> b >> k >> p;
    if (p == -1)
    {
        cout << "Case does not apply." << endl;
        cout << "Invalid input." << endl;
        return 0;
    }
    masterTheorem(a, b, k, p);

    return 0;
}
