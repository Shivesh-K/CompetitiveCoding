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
    bool b = false;
    cin >> n;
    vector<pair<string, int>> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
        if (v[i].first.front() == v[i].first.back())
            b = true;
    }

    if (b)
    {
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        string x = v[i].first;
        reverse(x.begin(), x.end());
        v.push_back({x, -v[i].second});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size() - 1; ++i)
    {
        auto x = v[i].first;
        auto y = v[i + 1].first;

        if (x[0] == y[0] && x[1] == y[1] &&
            abs(v[i].second) != abs(v[i + 1].second) &&
            v[i].second * v[i + 1].second < 0)
        {
            int p = min(v[i].second, v[i + 1].second);
            int q = max(v[i].second, v[i + 1].second);

            if (-p <= q)
                continue;

            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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