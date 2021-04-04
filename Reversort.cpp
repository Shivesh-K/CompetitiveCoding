#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int rsort(vector<int> &v, int l, int r)
{
    int idx = l, mi = v[l], s;
    for (int i = l + 1; i <= r; ++i)
    {
        if (mi > v[i])
        {
            mi = v[i];
            idx = i;
        }
    }
    s = idx - l + 1;
    reverse(v.begin() + r, v.begin() + idx);
    return s;
}

void compute()
{
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int &t : v)
        cin >> t;

    for (int i = 0; i < n - 1; ++i)
    {
        int idx = i, mi = v[i];
        for (int j = i + 1; j <= n - 1; ++j)
        {
            if (mi > v[j])
            {
                mi = v[j];
                idx = j;
            }
        }
        reverse(v.begin() + i, v.begin() + idx + 1);
        ans += idx - i + 1;
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