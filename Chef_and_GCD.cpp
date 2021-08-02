#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int x, y;
    cin >> x >> y;
    if (x % 2 == 0 && y % 2 == 0)
        cout << "0\n";
    else if (x % 2 == 0 && y % 2 != 0)
    {
        if (gcd(x, y) > 1)
            cout << "0\n";
        else
            cout << "1\n";
    }
    else if (y % 2 == 0 && x % 2 != 0)
    {
        if (gcd(x, y) > 1)
            cout << "0\n";
        else
            cout << "1\n";
    }
    else
    {
        if (gcd(x, y) > 1)
            cout << "0\n";
        else
        {
            int val = x + 1;
            if (gcd(y, val) > 1)
                cout << "1\n";
            else if (gcd(y + 1, x) > 1)
                cout << "1\n";
            else
                cout << "2\n";
        }
    }
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}