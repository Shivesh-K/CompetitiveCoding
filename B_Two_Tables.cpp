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
    ll W, H, x1, x2, y1, y2, w, h, ans = LLONG_MAX;
    bool b = false;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

    if (w + x2 - x1 <= W)
        ans = min(ans, min(w - x1, x2 - W + w)), b = true;
    if (h + y2 - y1 <= H)
        ans = min(ans, min(h - y1, y2 - H + h)), b = true;
    if (ans < 0)
        ans = 0;
    if (!b)
        ans = -1;

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