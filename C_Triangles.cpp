#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int n;
    map<char, vector<pair<int, int>>> m;
    cin >> n;
    vector<vector<char>> grid(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            char c;
            cin >> c;
            grid[i].push_back(c);
            m[c].push_back({i, j});
        }
    }
    for (char c = '0'; c <= '9'; ++c)
    {
        int a = 0;
        for (auto p : m[c])
        {
            for (auto q : m[c])
            {
                if (p != q)
                {
                    int x = abs(p.first - q.first) * (max(p.second, n - p.second - 1));
                    int y = abs(p.second - q.second) * (max(p.first, n - p.first - 1));
                    a = max(a, max(x, y));
                    // cout << a << " ";
                }
            }
        }
        cout << a << " ";
    }
    cout << "\n";
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