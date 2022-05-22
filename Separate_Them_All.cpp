#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<set<ll>> adj, adjc;
vector<ll> vis, visc;

ll dfs(ll s, ll parent)
{
    vis[s] = 1;
    ll sum = 0;
    ll l = adj[s].size();

    for (auto x : adj[s])
    {
        if (vis[x] == 0)
        {
            vis[x] = 1;
            sum += dfs(x, s);

            if (adj[x].size() == 1)
            {
                sum += l-- * adj[x].size();
                adj[x].erase(s);
            }
        }
    }
    adj[s].clear();
    if (l == 1)
        adj[s].insert(parent);
    return sum;
}
void compute()
{
    ll n, m, q;
    cin >> n >> q;
    ll i;
    vis = vector<ll>(n + 1);
    adj = vector<set<ll>>(n + 1);
    for (i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    adjc = adj;
    visc = vis;
    cout << dfs(1, 0) << "\n";

    while (q--)
    {
        adj = adjc;
        vis = visc;

        ll u, v, a, b;
        cin >> u >> v >> a >> b;

        adj[u].erase(v);
        adj[v].erase(u);
        adj[a].insert(b);
        adj[b].insert(a);

        cout << dfs(1, 0) << "\n";
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