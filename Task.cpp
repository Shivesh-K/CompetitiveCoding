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
    int k, a, b, x, y;
    cin >> k;
    vector<vector<int>> v(k);

    for (vector<int> &el : v)
    {
        vector<int> f(4);
        cin >> f[0] >> f[1] >> f[2] >> f[3];
        el = f;
    }

    vector<pair<int, int>> u;

    a = 0, b = k;
    for (auto el : v)
    {
        u.push_back({el[0], 0});
        u.push_back({el[2], 1});
    }
    sort(u.begin(), u.end());
    for (auto el : u)
    {
        if (el.second == 0)
            --b;
        else
            ++a;
        if (a >= b)
        {
            x = el.first;
            break;
        }
    }

    u.clear();
    a = 0, b = k;
    for (auto el : v)
    {
        u.push_back({el[1], 0});
        u.push_back({el[3], 1});
    }
    sort(u.begin(), u.end());
    for (auto el : u)
    {
        if (el.second == 0)
            --b;
        else
            ++a;
        if (a >= b)
        {
            y = el.first;
            break;
        }
    }

    cout << x << " " << y << "\n";
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