#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int getP(int node, vector<int> pa)
{
    while (pa[node] != node)
        node = pa[node];
    return node;
}

void compute()
{
    int n, m1, m2, u, v, x, y;
    cin >> n >> m1 >> m2;

    vector<int> p1(n + 1), p2(n + 1);
    for (int i = 1; i <= n; ++i)
        p1[i] = p2[i] = i;

    while (m1--)
    {
        cin >> u >> v;
        x = getP(u, p1), y = getP(v, p1);
        p1[x] = y;
    }

    while (m2--)
    {
        cin >> u >> v;
        x = getP(u, p2), y = getP(v, p2);
        p2[x] = y;
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (getP(i, p1) != getP(j, p1) && getP(i, p2) != getP(j, p2))
            {
                ans.push_back({i, j});
                p1[getP(i, p1)] = getP(j, p1);
                p2[getP(i, p2)] = getP(j, p2);
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto el : ans)
        cout << el.first << " " << el.second << "\n";
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