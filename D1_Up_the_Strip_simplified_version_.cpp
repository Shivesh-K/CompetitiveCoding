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
    ll n, m, sum = 1, t;
    cin >> n >> m;

    vector<int> v(n + 1);
    v[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        t = sum;

        for (int j = 2; j * j < i; ++j)
            t = (t + v[i / j]) % m;

        for (int k = 1; k * k <= i; ++k)
            t = (t + (v[k] * (ll)((i / k) - (i / (k + 1)))) % m) % m;

        v[i] = t;
        sum = (sum + t) % m;
    }

    cout << v[n] << "\n";
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