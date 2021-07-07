#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<char>> grid;
int n, m;

void dfs(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '#')
        return;

    grid[i][j] = '#';
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i + 1, j);
    dfs(i, j - 1);
}

void compute()
{
    cin >> n >> m;
    grid = vector<vector<char>>(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    int ans = 0, t;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '.')
            {
                dfs(i, j);
                ++ans;
            }
        }
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