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
    int n, t;
    cin >> n;
    vector<set<int>> v(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        while (t)
        {
            if (t <= n)
                v[t].insert(i);
            t >>= 1;
        }
    }

    for (int i = n; i > 0; --i)
    {
        if (v[i].empty())
        {
            cout << "NO\n";
            return;
        }

        int x = *(v[i].begin());

        for (int j = i; j > 0; j >>= 1)
            v[j].erase(x);
    }

    cout << "YES\n";
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