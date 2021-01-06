#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, k = 2;
    long int n, x;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int k = 2;; ++k)
        {
            double y = 1.0 * n / (pow(2, k) - 1);
            x = floor(y);
            if (x == y)
                break;
        }
        cout << x << endl;
    }
}