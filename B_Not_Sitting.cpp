#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

bool valid(int x, int y, int n, int m)
{
    return (x > 0 && x <= n && y > 0 && y <= m);
}

void compute()
{
    int n, m;
    cin >> n >> m;

    vector<int> ans;
    int cx[4] = {0, 0, n - 1, n - 1};
    int cy[4] = {0, m - 1, m - 1, 0};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int t = 0;
            for (int d = 0; d < 4; ++d)
                t = max(t, abs(i - cx[d]) + abs(j - cy[d]));
            ans.push_back(t);
        }
    }

    sort(ans.begin(), ans.end());

    for (int x : ans)
        cout << x << " ";
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