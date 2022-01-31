#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> dis;

void dfs(int node, int d)
{
    bool x = true;
    vis[node] = true;

    for (int next : adj[node])
    {
        if (!vis[next])
        {
            x = false;
            dfs(next, d + 1);
        }
    }

    if (x)
        dis.push_back(d);
}

void compute()
{
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    vis = vector<bool>(n + 1);
    dis.clear();

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    sort(dis.begin(), dis.end());

    vector<int> pre(dis.size() + 1);
    for (int i = 0; i < dis.size(); ++i)
        pre[i + 1] = dis[i] + pre[i];

    int prev = 0, curr;
    while (m--)
    {
        cin >> curr;
        auto it = upper_bound(dis.begin(), dis.end(), curr - prev) - dis.begin();
        ans += (ll)(curr - prev) * it - (ll)pre[it];
        prev = curr;
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