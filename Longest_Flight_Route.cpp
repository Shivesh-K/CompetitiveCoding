#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> dist(n + 1);
    vector<bool> vis(n + 1), path(n + 1);

    int from, to;
    while (m--)
    {
        cin >> from >> to;
        adj[from].push_back(to);
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    vis[1] = true;

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        if (vis[p.second])
            continue;

        vis[p.second] = true;
        for (int next : adj[p.first])
        {
            if (dist[next] < dist[p.second] + 1)
            {
                dist[next] = dist[p.second] + 1;
                pq.push({dist[next], next});
                path[next] = p.second;
            }
        }
    }

    if (!vis[n])
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> ans;
    while (n != 1)
    {
        ans.push_back(n);
        n = path[n];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());

    cout << (ans.size()) << "\n";
    for (int city : ans)
        cout << city << " ";
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