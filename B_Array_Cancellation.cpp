#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void swaps(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void compute()
{
    long long n, ans = 0;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (long long i = 0; i < n - 1; ++i)
    {
        if (a[i] > 0)
        {
            long long j = i + 1, t;
            while (a[i] > 0 && j < n)
            {
                if (a[j] < 0)
                {
                    t = min(a[i], -a[j]);
                    a[i] -= t;
                    a[j] += t;
                }
                ++j;
            }
        }
    }
    for (long long i = 0; i < n; ++i)
    {
        if (a[i] > 0)
            ans += a[i];
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