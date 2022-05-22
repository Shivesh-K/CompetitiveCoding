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
    ll n, x, y, total;
    cin >> n >> x >> y;
    total = n * (n + 1) / 2;

    if (total % (x + y) != 0 || total / (x + y) * x > total)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    total = total / (x + y) * x;
    vector<ll> v;
    cout << "POSSIBLE\n";
    for (ll i = n; i >= 0; --i)
    {
        if (i > total)
            break;
        total -= i;
        v.push_back(i);
    }

    if (total)
        v.push_back(total);

    cout << v.size() << "\n";
    for (ll &t : v)
        cout << t << " ";
    cout << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ": ";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}