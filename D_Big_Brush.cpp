#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int sqx[4] = {0, 0, 1, 1};
int sqy[4] = {0, 1, 1, 0};

bool isValid(int x, int y, vector<vector<int>> &mat)
{
    if (x < 0 || x >= mat.size() - 1 || y < 0 || y >= mat[0].size() - 1)
        return false;

    set<int> se;
    for (int d = 0; d < 4; ++d)
        if (mat[x + sqx[d]][y + sqy[d]])
            se.insert(mat[x + sqx[d]][y + sqy[d]]);

    return se.size() == 1;
}

void compute()
{
    int n, m, cnt = 0;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m)), ans;
    queue<vector<int>> q;

    for (auto &row : mat)
        for (auto &el : row)
            cin >> el;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            if (mat[i][j] == mat[i + 1][j] && mat[i][j] == mat[i][j + 1] && mat[i][j] == mat[i + 1][j + 1])
                q.push({i, j, mat[i][j]});
        }
    }

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        int x = t[0], y = t[1], c = t[2];

        if (!isValid(x, y, mat))
            continue;

        ans.push_back(t);
        for (int d = 0; d < 4; ++d)
            if (mat[x + sqx[d]][y + sqy[d]] != 0)
                mat[x + sqx[d]][y + sqy[d]] = 0, ++cnt;

        for (int d = 0; d < 8; ++d)
        {
            if (isValid(x + dx[d], y + dy[d], mat))
            {
                int co = 0;
                for (int t = 0; t < 4; ++t)
                    co |= mat[x + dx[d] + sqx[t]][y + dy[d] + sqy[t]];

                q.push({x + dx[d], y + dy[d], co});
            }
        }
    }

    if (cnt != n * m)
    {
        cout << "-1\n";
        return;
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto t : ans)
        cout << t[0] + 1 << " " << t[1] + 1 << " " << t[2] << "\n";
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