#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

long long firstMissingPositive(vector<long long> arr, long long n)
{
    for (long long i = 0; i < n; i++)
    {
        while (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
            iter_swap(arr.begin() + i, arr.begin() + arr[i] - 1);
    }

    for (long long i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}

void compute()
{
    long long n, k, t, mex, max;
    cin >> n >> k;

    if (k == 0)
    {
        cout << n << "\n";
        return;
    }

    max = 0;
    vector<long long> v(n);
    for (long long &x : v)
    {
        cin >> x;
        max = max >= x ? max : x;
    }
    mex = firstMissingPositive(v, n);

    if (mex > max)
    {
        cout << (n + k) << "\n";
        return;
    }

    t = ceil((mex + max) * 0.5);
    bool b = false;
    for (long long x : v)
        if (x == t)
        {
            b = true;
            break;
        }
    if (!b)
        ++n;

    cout << n << "\n";
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