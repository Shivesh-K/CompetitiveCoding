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
    int n, ans = INT_MAX;
    cin >> n;
    vector<int> v(n);

    for (int &t : v)
        cin >> t;

    if (n <= 2)
    {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            double d = ((double)v[j] - (double)v[i]) / ((double)j - (double)i);
            int cnt = 0;

            for (int k = 0; k < n; ++k)
            {
                double t = (double)v[i] + (double)(k - i) * d;
                if (v[k] != t)
                    ++cnt;
            }
            ans = min(ans, cnt);
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