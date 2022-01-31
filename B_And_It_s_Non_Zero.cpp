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
    int l, r, ans = INT_MAX, cnt;
    cin >> l >> r;

    for (int bit = 0; bit < 30; ++bit)
    {
        int x = (1 << (1 + bit));
        cnt = 0;

        if (r - l + 1 <= x)
        {
            int c1 = l % x;
            int c2 = r % x;
            cnt = (c2 > c1 ? (min(x / 2, c2 + 1) - c1) : (x / 2 - c1 + c2 + 1));
        }
        else
        {
            int nl = ((l - 1) / x + 1) * x;
            int nr = r / x * x;
            cnt += (nr - nl) / 2;

            if (l < nl)
                cnt += max(0, x / 2 - l % x);

            if (r >= nr)
                cnt += min(x / 2, r % x + 1);
        }

        ans = min(ans, cnt);
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