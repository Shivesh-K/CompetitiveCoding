#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int n, x, p;
    cin >> n >> x >> p;
    x = (n - x) % n;
    // if((x == 0 && (n & 1) && p >= n) || (n % 2 == 0 && n / 2 == x && p >= n) )
    if (x == 0)
    {
        bool fl = false;
        for (int t = 1; t <= min(n, p); ++t)
            if ((t * (t + 1) / 2) % n == 0)
            {
                fl = true;
                break;
            }
        if (fl)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else if ((x * (x - 1) / 2) % n == 0 && p >= x)
    {
        cout << "Yes\n";
    }
    else
    {
        bool fl = false;
        for (int t = 1; t * t <= 2 * x && t <= p; ++t)
            if (t * (t + 1) / 2 == x)
            {
                fl = true;
                break;
            }
        if (fl)
        {
            cout << "Yes\n";
            return;
        }
        else if ((n % 2 == 0) && x == n / 2 && p >= n)
            cout << "Yes\n";
        else
            cout << "No\n";
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