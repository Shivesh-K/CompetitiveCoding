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
    long long n, t, b = 1e13;
    bool x = false;
    cin >> n;
    set<long long> d;
    vector<long long> d1, suffix(n);
    for (long long i = 0; i < 2 * n; ++i)
    {
        cin >> t;
        d.insert(t);
    }
    for (auto x : d)
    {
        if (x % 2 != 0)
        {
            cout << "NO\n";
            return;
        }
        d1.push_back(x / 2);
    }
    sort(d1.begin(), d1.end());
    if (d1[n - 1] % n == 0)
    {
        b = d1[n - 1] / n;
    }
    else
    {
        cout << "NO\n";
        return;
    }
    suffix[n - 1] = b;
    for (long long i = n - 2; i >= 0; --i)
    {
        if (((d1[i] - suffix[i + 1]) % (i + 1) != 0) || ((d1[i] - suffix[i + 1]) / (i + 1) >= b))
        {
            cout << "NO\n";
            return;
        }
        b = (d1[i] - suffix[i + 1]) / (i + 1);
        if (b <= 0)
        {
            cout << "NO\n";
            return;
        }
        suffix[i] = b + suffix[i + 1];
    }
    cout << "YES\n";
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