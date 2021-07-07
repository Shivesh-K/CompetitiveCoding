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
int n, ans = 0;

int dfs(int node, int parent)
{
    int mx1 = 0, mx2 = 0, t;
    for (int next : adj[node])
    {
        if (next != parent)
        {
            t = dfs(next, node);
            if (t >= mx1)
                mx2 = mx1, mx1 = t;
            else if (t < mx1 && t >= mx2)
                mx2 = t;
        }
    }
    ans = max(ans, 1 + mx1 + mx2);
    return (1 + max(mx1, mx2));
}

void compute()
{
    cin >> n;

    int a, b;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    --ans;
    cout << ans << "\n";
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