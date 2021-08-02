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
    ll n, m;
    cin >> n >> m;
    map<ll, ll> ans[400];
    vector<string> v(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; ++i)
        cin >> v[i];
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ans[v[i][j]][j]++;
        }
    }
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        bool f = 1;
        for (int j = 0; j < m; ++j)
        {
            f &= ((ans[v[i][j]][j] & 1) == 1);
        }
        if (f == 1)
        {
            cout << v[i] << endl;
            break;
        }
    }
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        v[i] = "";
    }
    cout.flush();
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