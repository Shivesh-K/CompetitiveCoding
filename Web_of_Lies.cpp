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
    int n, m, t1, t2, q, x;
    cin >> n >> m;
    vector<set<int, greater<int>>> v(n + 1);
    set<int> ans;

    for (int i = 1; i <= n; ++i)
        ans.insert(i);

    while (m--)
    {
        cin >> t1 >> t2;
        v[t1].insert(t2);
        v[t2].insert(t1);
        if (v[t1].size() && *(v[t1].begin()) > t1 && ans.count(t1))
            ans.erase(t1);
        if (v[t2].size() && *(v[t2].begin()) > t2 && ans.count(t2))
            ans.erase(t2);
    }

    cin >> q;
    while (q--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> t1 >> t2;
            v[t1].insert(t2);
            v[t2].insert(t1);
            if (v[t1].size() && *(v[t1].begin()) > t1 && ans.count(t1))
                ans.erase(t1);
            if (v[t2].size() && *(v[t2].begin()) > t2 && ans.count(t2))
                ans.erase(t2);
        }
        else if (x == 2)
        {
            cin >> t1 >> t2;
            v[t1].erase(t2);
            v[t2].erase(t1);
            if (v[t1].empty() || *(v[t1].begin()) < t1)
                ans.insert(t1);
            if (v[t2].empty() || *(v[t2].begin()) < t2)
                ans.insert(t2);
        }
        else
        {
            cout << ans.size() << "\n";
        }
    }
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