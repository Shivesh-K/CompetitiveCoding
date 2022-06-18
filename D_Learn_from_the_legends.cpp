#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(ll i, ll j, vector<string> &grid, vector<vector<ll>> &dp, vector<vector<int>> vis)
{
    ll cnt = 0, n = grid.size(), m = grid[0].size();

    queue<pair<ll, ll>> q;
    q.push({i, j});
    vis[i][j] = 1;

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d)
        {
            int x = t.first + dx[d];
            int y = t.second + dy[d];
            if (grid[x][y] == '*')
                ++cnt;
            else if (vis[x][y] == 0)
                q.push({x, y}), vis[x][y] = 1;
        }
    }

    q.push({i, j});
    vis[i][j] = 2;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        dp[t.first][t.second] = cnt;

        for (int d = 0; d < 4; ++d)
        {
            int x = t.first + dx[d];
            int y = t.second + dy[d];
            if (grid[x][y] == '.' && vis[x][y] == 1)
                q.push({x, y}), vis[x][y] = 2;
        }
    }
}

void compute()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    vector<vector<ll>> dp(n, vector<ll>(m));
    vector<vector<int>> vis(n, vector<int>(m));
    for (string &row : grid)
        cin >> row;

    while (k--)
    {
        ll r, c;
        cin >> r >> c;
        if (dp[r - 1][c - 1] == 0)
            bfs(r - 1, c - 1, grid, dp, vis);

        cout << dp[r - 1][c - 1] << "\n";
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