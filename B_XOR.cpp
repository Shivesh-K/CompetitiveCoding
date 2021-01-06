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
    long long n, m, a, b, x, ans = 0;
    cin >> n >> m;
    map<long long, long long> ma;

    for (long long i = 0; i < n; ++i)
    {
        cin >> x;
        ma[x]++;
    }
    cin >> a >> b;
    ma[b] += ma[a];
    ma[a] = 0;
    for (auto x : ma)
    {
        if (x.second % 2 == 1)
        {
            ans ^= x.first;
        }
    }
    cout << ans << "\n";
    --m;
    while (m--)
    {
        cin >> a >> b;
        if (ma[a] % 2 == 1)
        {
            ans ^= (a ^ b);
        }
        ma[b] += ma[a];
        ma[a] = 0;

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
    int t = 1;
    while (t--)
    {
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}