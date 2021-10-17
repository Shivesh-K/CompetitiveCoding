#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int n, m, cnt = 0;
    cin >> n >> m;

    vector<string> v(n);
    vector<vector<int>> row, col;
    row = col = vector<vector<int>>(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            row[i + 1][j + 1] = row[i + 1][j] + (v[i][j] == '*');
            col[i + 1][j + 1] = col[i][j + 1] + (v[i][j] == '*');
            cnt += (v[i][j] == '*');
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (row[i + 1][m] + col[n][j + 1] - (v[i][j] == '*') == cnt)
            {
                cout << "YES\n"
                     << i + 1 << " " << j + 1 << "\n";
                return;
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