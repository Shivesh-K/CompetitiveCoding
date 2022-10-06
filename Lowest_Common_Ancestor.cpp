#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int n, LOG;
vector<vector<int>> adj, up;
vector<int> depth;

void dfs(int node, int parent)
{
    up[node][0] = parent;
    for (int next : adj[node])
    {
        if (next != parent)
        {
            depth[next] = depth[node] + 1;
            dfs(next, node);
        }
    }
}

int parent(int node, int k)
{
    for (int t = LOG; t >= 0; --t)
        if (k & (1 << t))
            node = up[node][t];

    return node;
}

int lca(int a, int b)
{
    if (depth[a] > depth[b])
        swap(a, b);

    b = parent(b, depth[b] - depth[a]);
    if (a == b)
        return a;

    for (int t = LOG; t >= 0; --t)
        if (up[a][t] != up[b][t])
            a = up[a][t], b = up[b][t];

    return up[a][0];
}

void compute()
{
    cin >> n;
    LOG = 1;
    while (n <= (1 << LOG))
        ++LOG;

    adj = vector<vector<int>>(n + 1);
    up = vector<vector<int>>(n + 1, vector<int>(LOG + 1));
    depth = vector<int>(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for (int t = 1; t <= LOG; ++t)
        for (int node = 1; node <= n; ++node)
            up[node][t] = up[up[node][t - 1]][t - 1];

    int q;
    cin >> q;
    while (q--)
    {
        int r, u, v, lcauv;
        cin >> r >> u >> v;
        lcauv = lca(u, v);

        if (lca(r, lcauv) != lcauv)
        {
            cout << lcauv << "\n";
        }
        else
        {
            int lcaru = lca(r, u);
            int lcarv = lca(r, v);
            if (lcaru == lcauv)
                cout << lcarv << "\n";
            else
                cout << lcaru << "\n";
        }
    }
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