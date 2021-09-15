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
    int n, cnte = 0, cnto = 0;
    cin >> n;
    vector<ll> v(n);

    for (ll &t : v)
    {
        cin >> t;
        (t & 1) ? ++cnto : ++cnte;
    }

    if (abs(cnte - cnto) > 1)
    {
        cout << "-1\n";
        return;
    }

    if (n & 1)
    {
        bool b = (cnte > cnto);
        int idx = 0, ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (b == ((v[i] & 1) == 0))
            {
                ans += abs(i - idx);
                idx += 2;
            }
        }
        cout << ans << "\n";
    }
    else
    {
        int ans1 = 0, ans2 = 0, idx;

        idx = 0;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] & 1)
                ans1 += abs(i - idx), idx += 2;
        }

        idx = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((v[i] & 1) == 0)
                ans2 += abs(i - idx), idx += 2;
        }

        cout << min(ans1, ans2) << "\n";
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