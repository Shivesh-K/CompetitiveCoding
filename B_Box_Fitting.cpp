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
    long long n, w, t, c, ans = 0, p, d;
    bool b;
    cin >> n >> w;
    map<long long, long long> m;
    for (long long i = 0; i < n; ++i)
    {
        cin >> t;
        m[t]++;
    }

    b = true;
    while (b)
    {
        p = 1 << 19;
        d = w;
        while (p >= 1)
        {
            if (m[p])
            {
                b = false;
                long long x = min(d / p, m[p]);
                d -= x * p;
                m[p] -= x;
            }
            p >>= 1;
        }
        if (b)
            break;
        b = true;
        ++ans;
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