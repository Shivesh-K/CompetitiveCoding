#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void swaps(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void compute()
{
    long long n, m, l;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    vector<vector<long long>> c;
    vector<pair<long long, long long>> ans;
    for (long long &x : a)
        cin >> x;
    for (long long &y : b)
        cin >> y;

    for (long long i = 0; i < n; ++i)
    {
        for (long long j = 0; j < m; ++j)
        {
            c.push_back({a[i] + b[j], i, j});
        }
    }
    sort(c.begin(), c.end());

    long long x, y, cx, cy;
    cin >> x >> y;
    x--, y--;
    l = n * m;
    cx = c[l - x][0];
    cy = c[l - y][0];
    for (long long i = l - x; i < l; ++i)
    {
        if (c[i][0] > cx)
            ans.push_back({c[i][1], c[i][2]});
    }
    for (long long i = 0; i < l - y; ++i)
    {
        if (c[i][0] < cy)
            ans.push_back({c[i][1], c[i][2]});
    }

    cout << ans.size() << "\n";
    if (ans.size() > 0)
    {
        for (auto t : ans)
        {
            cout << "(" << t.first << "," << t.second << ") ";
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