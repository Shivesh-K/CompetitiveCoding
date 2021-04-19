#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    long long n, ans = 0, a, mod = 1000000007;
    cin >> n;
    vector<long long> v(n);
    for (auto &t : v)
    {
        cin >> t;
    }
    a = v[0];
    for (auto &t : v)
    {
        a &= t;
    }
    for (auto &t : v)
    {
        if (t == a)
            ++ans;
    }
    ans = ans * (ans - 1) % mod;
    for (long long i = 1; i <= n - 2; ++i)
    {
        ans = (ans * i) % mod;
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