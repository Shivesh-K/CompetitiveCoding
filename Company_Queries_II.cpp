#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<int>> up;
vector<int> level;
int n, q, LOG;

void compute()
{
    cin >> n >> q;

    LOG = 0;
    while ((1 << LOG) <= n)
        ++LOG;

    up = vector<vector<int>>(n + 1, vector<int>(LOG + 1, -1));
    level = vector<int>(n + 1, -1);

    int t;
    level[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        cin >> t;
        up[i][0] = t;
        level[i] = level[t] + 1;
    }
    for (t = 1; t <= LOG; ++t)
    {
        for (int i = 1; i <= n; ++i)
        {
            up[i][t] = (up[i][t - 1] == -1) ? -1 : up[up[i][t - 1]][t - 1];
        }
    }

    int a, b, ans, d;
    while (q--)
    {
        cin >> a >> b;
        if (level[a] > level[b])
        {
            t = a;
            a = b;
            b = t;
        }

        d = level[b] - level[a];
        t = 0;
        while (t < 32)
        {
            if ((1 << t) & d)
            {
                b = up[b][t];
                if (b == -1)
                    break;
            }
            ++t;
        }

        if (a == b)
        {
            ans = a;
        }
        else
        {
            for (int i = LOG; i >= 0; --i)
            {
                if (up[a][i] != up[b][i])
                {
                    a = up[a][i];
                    b = up[b][i];
                }
            }
            ans = up[a][0];
        }
        cout << ans << "\n";
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