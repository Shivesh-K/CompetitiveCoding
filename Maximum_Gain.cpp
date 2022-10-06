#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<ll> setDP(vector<ll> &v, ll k)
{
    ll n = v.size();
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0LL));

    for (ll cnt = 1; cnt <= min(n, k); ++cnt)
    {
        dp[cnt][0] = dp[cnt - 1][0] + v[n - cnt];
        dp[cnt][cnt] = dp[cnt - 1][cnt - 1] + v[cnt - 1];
        for (ll i = 1; i < cnt; ++i)
        {
            dp[cnt][i] = max(dp[cnt - 1][i - 1] + v[i - 1], dp[cnt - 1][i] + v[n - cnt + i]);
        }
    }

    vector<ll> ans(k + 1);
    for (ll cnt = 0; cnt <= k; ++cnt)
        ans[cnt] = *max_element(dp[cnt].begin(), dp[cnt].end());

    return ans;
}

void compute()
{
    ll n, m, k;

    cin >> n;
    vector<ll> a(n);
    for (ll &t : a)
        cin >> t;

    cin >> m;
    vector<ll> b(m);
    for (ll &t : b)
        cin >> t;

    cin >> k;

    auto v1 = setDP(a, k);
    auto v2 = setDP(b, k);

    ll ans = 0;
    for (ll cnt = 0; cnt <= min(n, k); ++cnt)
    {
        ans = max(ans, v1[cnt] + v2[k - cnt]);
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