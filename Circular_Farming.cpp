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
    int ulx, uly, lrx, lry, dx, dy;
    cin >> ulx >> uly >> lrx >> lry;
    cin >> dx >> dy;

    int mxr = INT_MAX;
    mxr = min(mxr, abs(ulx - dx));
    mxr = min(mxr, abs(uly - dy));
    mxr = min(mxr, abs(lrx - dx));
    mxr = min(mxr, abs(lry - dy));

    vector<int> v(mxr + 5);

    int n;
    cin >> n;
    while (n--)
    {
        int x, y, r;
        cin >> x >> y >> r;

        double mn = sqrt((x - dx) * (x - dx) + (y - dy) * (y - dy)) - r;
        int t = max(mn, 0);
        if ((t + r) * (t + r) <= (x - dx) * (x - dx) + (y - dy) * (y - dy))
            ++t;
        if (t <= mxr)
            v[t]++;

        double mx = sqrt((x - dx) * (x - dx) + (y - dy) * (y - dy)) + r;
        t = mx;
        if ((t - r) * (t - r) < (x - dx) * (x - dx) + (y - dy) * (y - dy))
            ++t;
        if (t <= mxr)
            v[t]--;
    }

    for (int i = 0; i < v.size(); ++i)
        v[i] += v[i - 1];

    int ans = 0;
    for (int i = 1; i <= mxr; ++i)
        if (v[i] == 0)
            ++ans;

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
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case " << i << ": ";
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}