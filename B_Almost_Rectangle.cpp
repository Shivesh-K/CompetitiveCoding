#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

char grid[400][400];
void compute()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '*')
                ans.push_back({i, j});
        }
    }

    if (ans[0].first == ans[1].first)
    {
        if (ans[0].first - 1 >= 0)
        {
            // ans.push_back({ans[0].first - d, ans[0].second});
            // ans.push_back({ans[1].first - d, ans[1].second});
            grid[ans[0].first - 1][ans[0].second] = '*';
            grid[ans[1].first - 1][ans[1].second] = '*';
        }
        else
        {
            // ans.push_back({ans[0].first + 1, ans[0].second});
            // ans.push_back({ans[1].first + 1, ans[1].second});
            grid[ans[0].first + 1][ans[0].second] = '*';
            grid[ans[1].first + 1][ans[1].second] = '*';
        }
    }
    else if (ans[0].second == ans[1].second)
    {
        if (ans[0].second - 1 >= 0)
        {
            // ans.push_back({ans[0].first, ans[0].second - 1});
            // ans.push_back({ans[1].first, ans[1].second - 1});
            grid[ans[0].first][ans[0].second - 1] = '*';
            grid[ans[1].first][ans[1].second - 1] = '*';
        }
        else
        {
            // ans.push_back({ans[0].first, ans[0].second + 1});
            // ans.push_back({ans[1].first, ans[1].second + 1});
            grid[ans[0].first][ans[0].second + 1] = '*';
            grid[ans[1].first][ans[1].second + 1] = '*';
        }
    }
    else
    {
        grid[ans[0].first][ans[1].second] = '*';
        grid[ans[1].first][ans[0].second] = '*';
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << grid[i][j];
        }
        cout << "\n";
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