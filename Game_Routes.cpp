#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<ll>> adj;
vector<ll> dp;
ll n, m, mod = 1e9 + 7;

ll dfs(ll idx)
{
    if (idx == n)
        return 1;
    if (dp[idx] != -1)
        return dp[idx];

    ll t = 0;
    for (ll next : adj[idx])
        t = (t + dfs(next)) % mod;
    return dp[idx] = t;
}

void compute()
{
    cin >> n >> m;
    adj = vector<vector<ll>>(n + 1);
    dp = vector<ll>(n + 1, -1);

    ll from, to;
    while (m--)
    {
        cin >> from >> to;
        adj[from].push_back(to);
    }

    cout << (dfs(1)) << "\n";
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