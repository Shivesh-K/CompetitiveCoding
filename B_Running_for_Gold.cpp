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
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(5));
    map<int, int> f;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> v[i][j];

    int p = 0, cnt;
    for (int i = 1; i < n; ++i)
    {
        cnt = 0;
        for (int j = 0; j < 5; ++j)
            cnt += v[p][j] < v[i][j];
        if (cnt < 5 - cnt)
            p = i;
    }

    for (int i = 0; i < n; ++i)
    {
        if (i == p)
            continue;
        cnt = 0;
        for (int j = 0; j < 5; ++j)
            cnt += v[p][j] < v[i][j];
        if (cnt < 5 - cnt)
        {
            cout << "-1\n";
            return;
        }
    }
    ++p;
    cout << p << "\n";
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