#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define inf (long long)1e18
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define gcd(a, b) __gcd(a, b)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const int N = 1e9 + 7;

bool isPrimeNumber(long long n)
{
    bool isPrime = true;

    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

void solve()
{
    long long n, t, u, ans, p, last, curr;
    bool b = false;
    cin >> n;
    t = sqrt(n);
    bool reverse = false;

    while (t > 1 && !isPrimeNumber(t))
        --t;
    // cout << t << " ";
    u = t - 1;
    while (u > 1)
    {
        if (isPrimeNumber(u))
        {
            b = true;
            break;
        }
        --u;
    }
    if (!b)
    {
        u = t + 1;
        while ((u < n) && !isPrimeNumber(u))
            ++u;
    }
    // cout << u << " ";
    last = min(t, u);
    curr = max(t, u);
    while (last * curr <= n)
    {
        ans = last * curr;
        t = curr + 1;
        while (!isPrimeNumber(t))
            ++t;
        last = curr;
        curr = t;
    }
    cout
        << ans << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, k = 1;
    scanf("%d", &t);
    while (k <= t)
    {
        cout << "Case #" << k << ": ";
        solve();
        k++;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}