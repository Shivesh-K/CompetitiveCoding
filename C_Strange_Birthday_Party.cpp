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
    long long n, m, s = 0;
    cin >> n >> m;
    vector<long long> k(n), c(m);
    // vector<pair<long long, long long>> mins;
    for (long long i = 0; i < n; ++i)
        cin >> k[i];
    for (long long i = 0; i < m; ++i)
    {
        cin >> c[i];
    }
    sort(k.begin(), k.end());
    for (long long &x : k)
        s += c[x - 1];
    for (long long i = n - 1; i >= 0; --i)
    {
        long long t = n - i - 1;
        if (t >= m)
            break;
        if (c[t] < c[k[i] - 1])
        {
            s += (c[t] - c[k[i] - 1]);
        }
    }
    cout << s << "\n";
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