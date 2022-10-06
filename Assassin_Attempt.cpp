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
vector<string> grid;
vector<vector<int>> vis;

void compute()
{
    cin >> n >> m;
    grid = vector<string>(n);
    for (string &row : grid)
        cin >> row;

    vis = vector<vector<int>>(n, vector<int>(m, 1));
    pair<int, int> start, destination = {n - 1, m - 1};

    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (grid[i][j] == 'A')
                start = {i, j};
            else if (grid[i][j] == '^' || grid[i][j] == '>' || grid[i][j] == 'v' || grid[i][j] == '<' || grid[i][j] == 'X')
                vis[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int fl = 1;
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '>')
                fl = 0;
            vis[i][j] &= fl;
            if (grid[i][j] == 'X' || grid[i][j] == '<' || grid[i][j] == '^' || grid[i][j] == 'v')
                fl = true;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int fl = 1;
        for (int j = m - 1; j >= 0; --j)
        {
            if (grid[i][j] == '<')
                fl = 0;
            vis[i][j] &= fl;
            if (grid[i][j] == 'X' || grid[i][j] == '>' || grid[i][j] == '^' || grid[i][j] == 'v')
                fl = true;
        }
    }

    for (int j = 0; j < m; ++j)
    {
        int fl = 1;
        for (int i = 0; i < n; ++i)
        {
            if (grid[i][j] == 'v')
                fl = 0;
            vis[i][j] &= fl;
            if (grid[i][j] == 'X' || grid[i][j] == '<' || grid[i][j] == '^' || grid[i][j] == '>')
                fl = true;
        }
    }

    for (int j = 0; j < m; ++j)
    {
        int fl = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            if (grid[i][j] == '^')
                fl = 0;
            vis[i][j] &= fl;
            if (grid[i][j] == 'X' || grid[i][j] == '<' || grid[i][j] == 'v' || grid[i][j] == '>')
                fl = true;
        }
    }

    if (!vis[start.first][start.second])
    {
        cout << "NO\n";
        return;
    }

    int disx[4] = {-1, 0, 1, 0};
    int disy[4] = {0, 1, 0, -1};

    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = 0;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        if (curr == destination)
        {
            cout << "YES\n";
            return;
        }

        for (int t = 0; t < 4; ++t)
        {
            int i = curr.first + disx[t], j = curr.second + disy[t];
            if (i < 0 || i >= n || j < 0 || j >= m || !vis[i][j])
                continue;

            q.push({i, j});
            vis[i][j] = 0;
        }
    }

    cout << "NO\n";
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