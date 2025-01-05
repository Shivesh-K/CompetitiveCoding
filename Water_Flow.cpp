#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<int>> compute(vector<vector<int>> heights, int r, int c)
{
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> ans(n, vector<int>(m, -1));
    vector<vector<bool>> vis(n, vector<int>(m, false));

    queue<int> bfs;
    bfs.push_back(r * m + c);
    vis[r][c] = true;

    int time = 0;
    while (!bfs.empty())
    {
        int l = bfs.size();
        while (l--)
        {
            int cell = bfs.pop();
            int x = cell / m, y = cell % m;
            ans[x][y] = time;

            if (x - 1 >= 0 && !vis[x - 1][y] && heights[x - 1][y] <= heights[x][y])
                vis[x - 1][y] = true, bfs.push((x - 1) * m + (y));

            if (x + 1 < n && !vis[x + 1][y] && heights[x + 1][y] <= heights[x][y])
                vis[x + 1][y] = true, bfs.push((x + 1) * m + (y));

            if (y - 1 >= 0 && !vis[x][y - 1] && heights[x][y - 1] <= heights[x][y])
                vis[x][y - 1] = true, bfs.push((x)*m + (y - 1));

            if (y + 1 < m && !vis[x][y + 1] && heights[x][y + 1] <= heights[x][y])
                vis[x][y + 1] = true, bfs.push((x)*m + (y + 1));
        }
        ++time;
    }

    return ans;
}

void compute()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> heights(n, vector<int>(m));

    int r, c;
    cin >> r >> c;

    vector<vector<int>> ans = compute(heights, r, c);
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