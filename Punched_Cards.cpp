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
    int r, c;
    cin >> r >> c;
    r = 2 * r + 1;
    c = 2 * c + 1;
    vector<string> ans(r, string(c, '.'));

    bool fl1 = true, fl2 = true;
    for (int j = 2; j < c; ++j)
    {
        for (int i = 0; i < r; ++i)
        {
            ans[i][j] = (fl1 ? (fl2 ? '+' : '|') : (fl2 ? '.' : '-'));
            fl2 = !fl2;
        }
        fl1 = !fl1;
    }

    fl1 = true, fl2 = true;
    for (int i = 2; i < r; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            ans[i][j] = (fl1 ? (fl2 ? '+' : '-') : (fl2 ? '|' : '.'));
            fl2 = !fl2;
        }
        fl1 = !fl1;
    }

    for (auto &row : ans)
        cout << row << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ":\n";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}