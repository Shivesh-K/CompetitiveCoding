#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int n, m;
vector<vector<int>> adj;
vector<bool> vis;

int recur(int node, int parent)
{
    int cnt = 0;
    for (int next : adj[node])
        if (next != parent)
            ++cnt;

    if (cnt == 0)
        return 1;
    if (cnt > 2)
        return 0;

    int ans = 1;
    for (int next : adj[node])
        if (next != parent)
            ans *= recur(next, node);
    ans <<= 1;

    return ans;
}

void compute()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    vis = vector<bool>(n + 1);

    int u, v;
    while (m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << (3 * recur(1, 0)) << "\n";
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