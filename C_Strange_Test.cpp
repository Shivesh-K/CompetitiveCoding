#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int countInv(int m, int n)
{
    int t = 0, po = 1;
    while (m && n)
    {
        if ((m & 1) && !(n & 1))
            t |= po;
        po <<= 1, m >>= 1, n >>= 1;
    }

    return t;
}

void compute()
{
    int a, b, p, ans = INT_MAX;
    cin >> a >> b;

    p = 1;
    while (p <= b)
        p <<= 1;

    for (int x = a, y = b, cnt = 0; y <= p; ++y, ++cnt)
        ans = min(ans, cnt + countInv(x, y) + 1);

    for (int x = a, y = b, cnt = 0; x <= b; ++x, ++cnt)
        ans = min(ans, cnt + countInv(x, y) + 1);

    ans = min(ans, b - a);

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