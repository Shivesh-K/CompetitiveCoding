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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll &t : v)
        cin >> t;

    for (ll bit = 1, x = 1; bit < (1 << 30); bit <<= 1, x += bit)
    {
        vector<int> t;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] & bit)
                t.push_back(i + 1);
        }

        if (t.size() < 2)
            continue;

        cout << "YES\n";

        int last = 1;
        t.back() = n;
        cout << t.size() << "\n";
        for (int &x : t)
        {
            cout << last << " " << x << "\n";
            last = x + 1;
        }

        return;
    }

    cout << "NO\n";
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