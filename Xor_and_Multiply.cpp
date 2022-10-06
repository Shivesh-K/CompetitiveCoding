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
    ll n, a, b, x = 0;
    cin >> n >> a >> b;

    ll bit = (1 << (n - 1));
    bool fl = true;
    while (bit)
    {
        ll t1 = (a & bit);
        ll t2 = (b & bit);
        if (t1 == t2)
            x |= (t1 == 0 ? bit : 0);
        else if (fl)
            x |= (t1 == 0 ? bit : 0), fl = !fl;
        else
            x |= (t2 == 0 ? bit : 0);
        bit >>= 1;
    }

    cout << x << "\n";
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