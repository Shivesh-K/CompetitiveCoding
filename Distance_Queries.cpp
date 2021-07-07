#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<int> adj[200001];
int up[200001][20];
int level[200001];
int n, q;

void dfs(int node, int parent)
{
    up[node][0] = parent;
    for (int i = 1; i < 19; ++i)
    {
        up[node][i] = up[up[node][i - 1]][i - 1];
        if (!up[node][i])
            break;
    }
    for (int next : adj[node])
    {
        if (next != parent)
        {
            level[next] = level[node] + 1;
            dfs(next, node);
        }
    }
}

int lift(int n, int d)
{
    for (int i = 19; i >= 0; i--)
    {
        if (d == 0 or n == 0)
            break;

        if (d >= (1 << i))
        {
            d = d - (1 << i);
            n = up[n][i];
        }
    }
    return n;
}

int lca(int a, int b)
{
    if (level[a] > level[b])
    {
        int t = a;
        a = b;
        b = t;
    }

    int d = level[b] - level[a];
    b = lift(b, d);

    if (a == b)
        return a;

    for (int i = 18; i >= 0; --i)
        if (up[a][i] != up[b][i])
            a = up[a][i], b = up[b][i];
    return up[a][0];
}

int query(int a, int b)
{
    return level[a] + level[b] - 2 * level[lca(a, b)];
}

void compute()
{
    cin >> n >> q;

    int a, b, ans;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    while (q--)
    {
        cin >> a >> b;
        ans = query(a, b);
        cout << ans << "\n";
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