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
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    set<pair<int, int>> se;

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        se.insert({v[i], i});
    }

    int l1 = 0, l2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] == l1 && v[i] == l2)
            ans += 0;
        else if (v[i] == l1 && v[i] != l2)
            l2 = v[i], ++ans;
        else if (v[i] != l1 && v[i] == l2)
            l1 = v[i], ++ans;
        else
        {
            int d1 = n, d2 = n;

            auto it1 = se.upper_bound({l1, i});
            if (it1 != se.end() && it1->first == l1 && it1->second > i)
                d1 = it1->second;

            auto it2 = se.upper_bound({l2, i});
            if (it2 != se.end() && it2->first == l2 && it2->second > i)
                d2 = it2->second;

            (d1 <= d2) ? (l1 = v[i]) : (l2 = v[i]);
            ++ans;
        }
    }

    cout << ans << "\n";
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