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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n), f(k);

    for (ll &t : v)
    {
        cin >> t;
        f[t % k]++;
        t /= k;
    }

    ll ans = accumulate(v.begin(), v.end(), 0LL);
    for (ll i = 1, j = k - 1; j >= i;)
    {
        if (i + j < k)
        {
            ++i;
        }
        else if (i == j)
        {
            ans += f[i] / 2;
            break;
        }
        else
        {
            ll t = min(f[i], f[j]);
            ans += t;
            f[i] -= t;
            f[j] -= t;
            if (f[i] == 0)
                ++i;
            if (f[j] == 0)
                --j;
        }
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