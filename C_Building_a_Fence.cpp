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
    long long n, k;
    cin >> n >> k;
    vector<long long> h(n);
    for (long long &x : h)
        cin >> x;

    long long minL = h[0] + k, maxL = h[0] + k, minR = h[n - 1] + k, maxR = h[n - 1] + k;

    for (long long i = 1; i < ((n + 1) >> 1); ++i)
    {
        if (h[i] > maxL - 1 || h[i] + k < minL - k + 1)
        {
            cout << "NO\n";
            return;
        }
        maxL = min(maxL + k - 1, h[i] + k - 1 + k);
        minL = max(h[i] + k, minL - k + 1);
    }
    for (long long i = n - 1; i >= (n >> 1); --i)
    {
        if (h[i] > maxR - 1 || h[i] + k < minR - k + 1)
        {
            cout << "NO\n";
            return;
        }
        maxR = min(maxR + k - 1, h[i] + k - 1 + k);
        minR = max(h[i] + k, minR - k + 1);
    }

    minL -= k;
    minR -= k;
    if (maxL - minR > 0 && maxR - minL > 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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