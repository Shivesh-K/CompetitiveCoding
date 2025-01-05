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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == 0 || c == 0)
    {
        cout << (a == c ? "0" : "1") << "\n";
        return;
    }

    ll g1 = gcd(a, b);
    ll g2 = gcd(c, d);
    a /= g1, b /= g1;
    c /= g2, d /= g2;

    if (a == c && b == d)
        cout << "0\n";
    else if ((a * d) % (c * b) == 0 || (c * b) % (a * d) == 0)
        cout << "1\n";
    else
        cout << "2\n";
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