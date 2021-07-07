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
    ll n, x, t, ans, u;
    cin >> n >> x >> t;
    if (t < x)
        cout << "0\n";
    else if (t == x)
        cout << n - 1 << "\n";
    else
    {
        u = t / x;
        if (n <= u)
        {
            cout << (n * (n - 1) / 2) << "\n";
        }
        else
        {
            n = n - u;
            ans = n * u + (u * (u - 1) / 2);
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