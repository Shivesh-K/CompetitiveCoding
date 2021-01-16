#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int isHill(vector<long long> a, long long i)
{
    return (a[i] > a[i - 1] && a[i] > a[i + 1]);
}

int isValley(vector<long long> a, long long i)
{
    return (a[i] < a[i - 1] && a[i] < a[i + 1]);
}

void compute()
{
    long long n, h, v, ans = 0;
    cin >> n;
    vector<long long> a(n);
    vector<int> s(n);
    for (long long i = 0; i < n; ++i)
        cin >> a[i];

    if (n == 1 || n == 2 || n == 3)
    {
        cout << "0\n";
        return;
    }

    h = v = 0;
    for (long long i = 1; i < n - 1; ++i)
    {
        if (isHill(a, i))
            s[i] = 2, ++h;
        else if (isValley(a, i))
            s[i] = 1, ++v;
    }

    ans = h + v;
    for (long long i = 1; i < n - 1; ++i)
    {
        long long t = a[i], c, f;
        long long ta, t1, t2;
        ta = t1 = t2 = h + v;

        c = ((isHill(a, i - 1) || isValley(a, i - 1)) + (isHill(a, i) || isValley(a, i)) + (isHill(a, i + 1) || isValley(a, i + 1)));

        a[i] = a[i - 1];
        f = ((isHill(a, i - 1) || isValley(a, i - 1)) + (isHill(a, i) || isValley(a, i)) + (isHill(a, i + 1) || isValley(a, i + 1)));

        t1 = min(ta, ta - c + f);

        a[i] = a[i + 1];
        f = ((isHill(a, i - 1) || isValley(a, i - 1)) + (isHill(a, i) || isValley(a, i)) + (isHill(a, i + 1) || isValley(a, i + 1)));

        t2 = min(ta, ta - c + f);

        ans = min(t1, t2);
        a[i] = t;
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