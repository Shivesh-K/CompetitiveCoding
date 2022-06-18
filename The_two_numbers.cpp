#include <bits/stdc++.h>
using namespace std;
// #define max(a, b) ((a) > (b) ? (a) : (b))
// #define min(a, b) ((a) < (b) ? (a) : (b))
// #define gcd(a, b) __gcd(a, b)
// #define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

ll gcd(ll a, ll b)
{
    return b == 0LL ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

void compute()
{
    ll n;
    cin >> n;

    if (n == 2)
        cout << "0\n";
    else if (n == 4)
        cout << "2\n";
    else if (n == 6)
        cout << "4\n";
    else
    {
        ll t = n / 2;
        if (n & 1)
            cout << t * (t + 1) - 1 << "\n";
        else
        {
            ll ans = max(0LL, lcm(t - 1, t + 1) - gcd(t - 1, t + 1));
            ans = max(ans, lcm(t - 2, t + 2) - gcd(t - 2, t + 2));
            ans = max(ans, 0LL);
            cout << ans << "\n";
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