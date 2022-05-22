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
    vector<vector<int>> colors(3, vector<int>(4));
    vector<int> mn(4, 1e7);
    int total = 1e6;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> colors[i][j];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            mn[j] = min(mn[j], colors[i][j]);

    if (accumulate(mn.begin(), mn.end(), 0) < total)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            int t = min(mn[i], total);
            total -= t;
            cout << t << " ";
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
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ": ";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}