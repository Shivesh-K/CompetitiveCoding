#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

ll fun(vector<ll> v, ll limit)
{
    int cnt = 0;
    for (ll t : v)
        if (t < limit)
            ++cnt;
    return cnt;
}

void compute()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &t : v)
        cin >> t;

    ll l = *min_element(v.begin(), v.end()), r = *max_element(v.begin(), v.end()), ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (fun(v, mid) <= k)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
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