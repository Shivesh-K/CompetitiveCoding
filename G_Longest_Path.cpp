#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int n, m;
vector<vector<int>> graph;
vector<int> dp;

int findLongest(int i)
{
    if (dp[i] != -1)
        return dp[i];

    int ans = 0, t;
    for (int t : graph[i])
    {
        t = 1 + findLongest(t);
        if (t > ans)
            ans = t;
    }
    return dp[i] = ans;
}

void compute()
{
    int x, y;
    cin >> n >> m;
    graph = vector<vector<int>>(n);
    dp = vector<int>(n, -1);

    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        graph[x - 1].push_back(y - 1);
    }

    int ans = 0, t;
    for (int i = 0; i < n; ++i)
    {
        t = findLongest(i);
        ans = max(ans, t);
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
    compute();

#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}