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
    int n, q, l, r;
    ll o, e, ans;
    cin >> n >> q;
    vector<int> v(n), pro(n), pre(n);
    for (int &t : v)
        cin >> t;

    (v[0] & 1) ? pro[0] = 1 : pre[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        pre[i] = pre[i - 1];
        pro[i] = pro[i - 1];
        (v[i] & 1) ? pro[i]++ : pre[i]++;
    }

    while (q--)
    {
        cin >> l >> r;
        --l, --r;
        o = pro[r] - (l ? pro[l - 1] : 0);
        e = pre[r] - (l ? pre[l - 1] : 0);
        ans = 0;
        if (e >= 3)
            ans += e * (e - 1) * (e - 2) / 6;
        if (e >= 1 && o >= 2)
            ans += e * o * (o - 1) / 2;
        cout << ans << "\n";
    }
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