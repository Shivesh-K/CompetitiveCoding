#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

ll n, k, mod = 1e9 + 7;
vector<int> dp;

ll recur(string &s, ll i)
{
    if (i == n)
    {
        string s1 = s.substr(0, n);
        string s2 = s.substr(n - (s.length() & 1));
        reverse(s1.begin(), s1.end());
        return s1 < s2;
    }

    ll t = s[i] - 'a';
    // ll x = 1, y;
    ll ans = 0;

    if (t > 0)
    {
        // y = n - i - 1;
        // while (y--)
        //     x = (x * k) % mod;
        // x = dp[n - i - 1];
        ans = (ans + (t * dp[n - i - 1]) % mod) % mod;
    }
    ans = (ans + recur(s, i + 1)) % mod;
    return ans;
}

void compute()
{
    ll ans = 0, t = 1;
    string s;
    cin >> n >> k >> s;

    n = (n + 1) / 2;
    for (ll i = 0; i < n; ++i)
    {
        dp.push_back(t);
        t = (t * k) % mod;
    }
    ans = recur(s, 0);

    cout << ans << "\n";
    dp.clear();
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