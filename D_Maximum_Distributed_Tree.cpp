#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const ll MOD = 1e9 + 7;

ll n, m, u, v;
vector<vector<ll>> adj;
vector<ll> cnt;

ll setCnt(int node, int parent)
{
    ll ans = 1;
    for (auto next : adj[node])
        if (next != parent)
            ans += setCnt(next, node);

    if (parent)
        cnt.push_back(ans * (n - ans));

    return ans;
}

void compute()
{
    cin >> n;
    adj = vector<vector<ll>>(n + 1);
    cnt.clear();
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> m;
    vector<ll> p;
    while (m--)
    {
        ll t;
        cin >> t;
        p.push_back(t);
    }

    while (p.size() < n - 1)
        p.push_back(1);

    sort(p.begin(), p.end());

    while (p.size() >= n)
    {
        ll t = p[p.size() - 1] * p[p.size() - 2];
        p.pop_back();
        p.pop_back();
        p.push_back(t % MOD);
    }

    setCnt(1, 0);
    sort(cnt.rbegin(), cnt.rend());

    ll ans = 0;
    for (auto el : cnt)
    {
        el %= MOD;
        ans = (ans + (el * p.back()) % MOD) % MOD;
        p.pop_back();
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