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
vector<int> vis;
set<int> used;

void bfs(queue<int> &q)
{
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        used.insert(t);
        vis[t] = true;
        for (int next : adj[t])
        {
            if (!vis[next])
                q.push(next);
        }
    }
}

void compute()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    vis = vector<int>(n + 1);
    used.clear();

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        bfs(q);
        if (vis[1])
        {
            cout << ans << "\n";
            return;
        }

        for (int t : used)
        {
            if (t - 1 > 0 && !vis[t - 1])
                q.push(t - 1);
            if (t + 1 <= n && !vis[t + 1])
                q.push(t + 1);
        }
        used.clear();
        ++ans;
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