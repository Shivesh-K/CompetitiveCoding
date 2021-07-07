#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<int>> up;
int n, q, LOG;

void compute()
{
    cin >> n >> q;

    LOG = 0;
    while ((1 << LOG) <= n)
        ++LOG;

    up = vector<vector<int>>(n + 1, vector<int>(LOG + 1, -1));

    int t;
    for (int i = 2; i <= n; ++i)
    {
        cin >> t;
        up[i][0] = t;
    }
    for (int level = 1; level <= LOG; ++level)
    {
        for (int i = 1; i <= n; ++i)
        {
            up[i][level] = (up[i][level - 1] == -1) ? -1 : up[up[i][level - 1]][level - 1];
        }
    }

    int x, k, ans;
    while (q--)
    {
        cin >> x >> k;
        ans = x, t = 0;
        while (t < 32)
        {
            if ((1 << t) & k)
            {
                ans = up[ans][t];
                if (ans == -1)
                    break;
            }
            ++t;
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