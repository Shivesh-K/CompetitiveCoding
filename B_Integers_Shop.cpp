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
    int n;
    long long mn = LLONG_MAX, mx = LLONG_MIN, lCost = LLONG_MAX, rCost = LLONG_MAX, tCost = LLONG_MAX;
    cin >> n;
    vector<long long> l(n), r(n), c(n);
    for (int i = 0; i < n; ++i)
        cin >> l[i] >> r[i] >> c[i];

    for (int s = 1; s <= n; ++s)
    {
        ll newMn, newMx;
        newMn = min(mn, l[s - 1]);
        newMx = max(mx, r[s - 1]);

        if (newMn == l[s - 1])
            lCost = ((newMn < mn) ? c[s - 1] : min(lCost, c[s - 1]));

        if (newMx == r[s - 1])
            rCost = ((newMx > mx) ? c[s - 1] : min(rCost, c[s - 1]));

        if (mx == newMx && mn == newMn)
            tCost = ((newMn == l[s - 1] && newMx == r[s - 1]) ? min(tCost, c[s - 1]) : tCost);
        else
            tCost = ((newMn == l[s - 1] && newMx == r[s - 1]) ? c[s - 1] : lCost + rCost);

        ll ans = min(lCost + rCost, tCost);
        cout << ans << "\n";

        mx = newMx;
        mn = newMn;
        tCost = ans;
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