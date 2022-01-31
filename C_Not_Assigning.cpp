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
vector<bool> vis, weights;
map<vector<int>, int> order;

void dfs(int node, bool prev)
{
    vis[node] = true;
    for (int next : adj[node])
    {
        if (vis[next])
            continue;
        prev = !prev;
        weights[order[{min(node, next), max(node, next)}]] = prev;
        dfs(next, prev);
    }
}

void compute()
{
    int n;
    cin >> n;

    adj = vector<vector<int>>(n + 1);
    order.clear();
    vis = vector<bool>(n + 1);
    weights = vector<bool>(n - 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        order[{min(u, v), max(u, v)}] = i;
    }

    for (auto l : adj)
    {
        if (l.size() > 2)
        {
            cout << "-1\n";
            return;
        }
    }

    dfs(1, true);

    for (bool b : weights)
        cout << (b ? "2 " : "5 ");
    cout << "\n";
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