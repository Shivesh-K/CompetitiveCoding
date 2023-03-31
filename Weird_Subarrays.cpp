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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &t : v)
        cin >> t;

    ll ans = 0;
    int l = 0, r = 0, t = -1, mx;
    while (true)
    {
        while (r + 1 < n && v[r + 1] <= v[r])
            ++r;
        mx = INT_MIN;
        int ti = r;
        while (r + 1 < n && v[r + 1] >= v[r])
        {
            ++r;
            if (v[r] > mx)
                mx = v[r], ti = r;
        }

        long long s1 = r - l + 1;
        long long s2 = t - l + 1;
        ans += (s1 * (s1 + 1) / 2) - (s2 * (s2 + 1) / 2);

        l = ti;
        t = r;

        if (r == n - 1)
            break;
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