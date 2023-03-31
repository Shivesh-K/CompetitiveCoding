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
    ll q, ch;
    ll a, b, n;
    cin >> q;

    ll mx = LLONG_MAX, mn = 1;

    while (q--)
    {
        cin >> ch;
        if (ch == 1)
        {
            cin >> a >> b >> n;
            ll tmn = (n >= 2 ? a + (n - 2) * (a - b) : 0) + 1;
            ll tmx = a + (n - 1) * (a - b);
            if (mn <= tmx && mx >= tmn)
            {
                mn = max(mn, tmn), mx = min(mx, tmx);
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        else
        {
            cin >> a >> b;
            ll x = (mn <= a ? 1 : ((mn - a + a - b - 1) / (a - b) + 1));
            if (mx <= a + (x - 1) * (a - b))
                cout << x << " ";
            else
                cout << "-1 ";
        }
    }
    cout << "\n";
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