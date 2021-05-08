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
    long long n, p1, p2 = LLONG_MAX, idx = -1;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; ++i)
    {
        cin >> v[i];
        if (p2 > v[i])
        {
            p2 = v[i];
            idx = i;
        }
    }

    if (n <= 1)
    {
        cout << "0\n";
        return;
    }

    p1 = 1000000007;
    if (idx > 0)
    {
        cout << n << "\n";
        cout << 1 << " " << (idx + 1) << " " << p2 << " " << p2 << "\n";
        for (long long i = 1; i < n; ++i)
        {
            cout << 1 << " " << (i + 1) << " " << p2 << " " << (i & 1 ? p1 : p2) << "\n";
        }
    }
    else
    {
        cout << (n - 1) << "\n";
        for (long long i = 1; i < n; ++i)
        {
            cout << 1 << " " << (i + 1) << " " << p2 << " " << (i & 1 ? p1 : p2) << "\n";
        }
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