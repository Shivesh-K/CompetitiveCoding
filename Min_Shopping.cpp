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
    int n, m;
    cin >> n >> m;
    vector<int> v(m);

    pair<int, int> mn1, mn2;
    mn1 = mn2 = {0, -1};

    while (n--)
    {
        for (int i = 0; i < m; ++i)
        {
            cin >> v[i];
            if (i != mn1.second)
                v[i] += mn1.first;
            else
                v[i] += mn2.first;
        }

        mn1 = mn2 = {INT_MAX, -1};
        for (int i = 0; i < m; ++i)
        {
            if (v[i] <= mn1.first)
                mn2 = mn1, mn1 = {v[i], i};
            else if (v[i] <= mn2.first)
                mn2 = {v[i], i};
        }
    }

    cout << mn1.first << "\n";
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