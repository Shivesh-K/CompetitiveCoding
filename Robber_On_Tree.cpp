#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int n, r;
vector<vector<int>> adj;
vector<int> coins, dist;

bool setDistances(int node, int parent, int d)
{

    if (node == 1)
    {
        dist[node] = d;
        return true;
    }

    for (int next : adj[node])
    {
        if (next != parent && setDistances(next, node, d + 1))
        {
            dist[node] = d;
            return true;
        }
    }

    return false;
}

int maxCoins(int node, int parent, int d)
{
    int ans = 0;
    for (int next : adj[node])
    {
        if (next != parent)
            ans = max(ans, maxCoins(next, node, d + 1));
    }

    if (d < dist[node])
        ans += coins[node];
    else if (d == dist[node])
        ans += coins[node] / 2;

    return ans;
}

void compute()
{
    cin >> n >> r;
    coins = vector<int>(n + 1);
    dist = vector<int>(n + 1, INT_MAX);
    adj = vector<vector<int>>(n + 1);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    setDistances(r, 0, 0);

    for (int i = 1; i <= n; ++i)
        cin >> coins[i];

    cout << maxCoins(1, 0, 0) << "\n";
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