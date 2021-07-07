#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

string makeStr(int x, int y, vector<string> &grid)
{
    string s;
    while (grid[x][y] != ' ')
    {
        s += grid[x][y];
        if (grid[x][y] == 'U')
            ++x;
        else if (grid[x][y] == 'R')
            --y;
        else if (grid[x][y] == 'D')
            --x;
        else if (grid[x][y] == 'L')
            ++y;
    }
    reverse(s.begin(), s.end());
    return s;
}

void compute()
{
    int n, m, cnt = 1, x, y, l;
    cin >> n >> m;
    vector<string> grid(n, string(m, '#'));
    vector<string> move(n, string(m, ' '));
    queue<pair<int, int>> q;
    pair<int, int> p;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                q.push({i, j});
                grid[i][j] = '#';
            }
        }
    }

    while (!q.empty())
    {
        l = q.size();
        while (l--)
        {
            p = q.front();
            x = p.first;
            y = p.second;
            q.pop();
            // if (grid[x][y] == 'B')
            // {
            // cout << "YES\n";
            // cout << cnt << "\n";
            // cout << (makeStr(x, y, move)) << "\n";
            // return;
            // }
            // grid[x][y] = '#';

            if (x - 1 >= 0 && grid[x - 1][y] != '#')
            {
                move[x - 1][y] = 'U';
                if (grid[x - 1][y] == 'B')
                {
                    cout << "YES\n";
                    cout << cnt << "\n";
                    cout << (makeStr(x - 1, y, move)) << "\n";
                    return;
                }
                q.push({x - 1, y});
                grid[x - 1][y] = '#';
            }
            if (y + 1 < m && grid[x][y + 1] != '#')
            {
                move[x][y + 1] = 'R';
                if (grid[x][y + 1] == 'B')
                {
                    cout << "YES\n";
                    cout << cnt << "\n";
                    cout << (makeStr(x, y + 1, move)) << "\n";
                    return;
                }
                q.push({x, y + 1});
                grid[x][y + 1] = '#';
            }
            if (x + 1 < n && grid[x + 1][y] != '#')
            {
                move[x + 1][y] = 'D';
                if (grid[x + 1][y] == 'B')
                {
                    cout << "YES\n";
                    cout << cnt << "\n";
                    cout << (makeStr(x + 1, y, move)) << "\n";
                    return;
                }
                q.push({x + 1, y});
                grid[x + 1][y] = '#';
            }
            if (y - 1 >= 0 && grid[x][y - 1] != '#')
            {
                move[x][y - 1] = 'L';
                if (grid[x][y - 1] == 'B')
                {
                    cout << "YES\n";
                    cout << cnt << "\n";
                    cout << (makeStr(x, y - 1, move)) << "\n";
                    return;
                }
                q.push({x, y - 1});
                grid[x][y - 1] = '#';
            }
        }
        ++cnt;
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
    compute();

#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}