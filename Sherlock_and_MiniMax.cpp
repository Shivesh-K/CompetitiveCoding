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
    int n, p, q, d = 0, l, r;
    cin >> n;
    vector<int> v(n);
    for (int &t : v)
        cin >> t;
    cin >> p >> q;

    sort(v.begin(), v.end());

    l = lower_bound(v.begin(), v.end(), p) - v.begin();
    r = lower_bound(v.begin(), v.end(), q) - v.begin();
    if (r == n || v[r] > q)
        --r;
    if (l > 0)
        --l;

    if (p < v[0])
        d = max(d, v[0] - p);
    if (q > v[n - 1])
        d = max(d, q - v[n - 1]);
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    compute();

#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}