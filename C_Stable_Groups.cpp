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
    ll n, k, x, ans = 0;
    cin >> n >> k >> x;
    vector<ll> v(n), cnt;
    for (ll &t : v)
        cin >> t;
    sort(v.begin(), v.end());

    for (ll i = 1; i < n; ++i)
    {
        if (v[i] - v[i - 1] > x)
        {
            cnt.push_back((v[i] - v[i - 1] - 1) / x);
        }
    }

    sort(cnt.begin(), cnt.end(), greater<ll>());
    while (cnt.size())
    {
        if (cnt[cnt.size() - 1] > k)
            break;
        k -= cnt[cnt.size() - 1];
        cnt.pop_back();
    }
    cout << (cnt.size() + 1) << "\n";
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