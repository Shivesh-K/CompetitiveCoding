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
    int a, b, x = 0, t = 1, y, ans, cnt;
    cin >> a >> b;
    ans = a;

    for (int i = 0; i < 20; ++i)
    {
        cnt = a / (t << 1) * t;
        y = a % (t << 1);
        if (y > t)
            cnt += y - t;
        if (cnt & 1)
            x |= t;
        t <<= 1;
    }
    if (x != b)
    {
        ++ans;
        ans += ((x ^ b) == a);
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