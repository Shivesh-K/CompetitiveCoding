#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<int>> adj;
vector<int> groups;
vector<bool> vis;

void dfs(int node)
{
    if (vis[node])
        return;
    vis[node] = true;
    for (int next : adj[node])
        dfs(next);
}

void compute()
{
    int n, m, x, y;
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    vis = vector<bool>(n + 1);

    while (m--)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            groups.push_back(i);
            dfs(i);
        }
    }

    int ans = groups.size() - 1;
    cout << ans << "\n";
    while (ans--)
        cout << groups[ans] << " " << groups[ans + 1] << "\n";
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