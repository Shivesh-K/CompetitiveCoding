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
    ll n, a, b, cnt = 0, ans, bo, t;
    cin >> n;
    vector<pair<ll, ll>> vp;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        vp.push_back({b, a});
        cnt += a;
    }

    sort(vp.begin(), vp.end(), greater<pair<ll, ll>>());

    bo = ans = 0;
    for (auto &el : vp)
    {
        if (bo >= el.first)
            break;
        t = min(el.first - bo, el.second);
        el.second -= t;
        ans += 2 * t;
        cnt -= t;
        bo += t;
    }
    ans += cnt;
    cout << ans << "\n";
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