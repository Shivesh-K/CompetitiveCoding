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
    ll n, p = 1, ans = INT_MAX;
    string s, t;
    cin >> n;
    s = to_string(n);

    for (p = 1; p <= 1e18; p <<= 1)
    {
        t = to_string(p);
        int i = 0, j = 0;
        while (i < s.length() && j < t.length())
        {
            if (s[i] == t[j])
                ++j;
            ++i;
        }
        ans = min(ans, (ll)(s.length() + t.length() - 2 * j));
    }

    cout << ans << "\n";
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