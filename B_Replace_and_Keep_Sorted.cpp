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
    int n, q, k, l, r, ans;
    cin >> n >> q >> k;
    vector<int> a(n), b(n), c(n);

    for (int &x : a)
        cin >> x;

    b[0] = (n == 1 ? k : (a[1] - 1)) - 1;
    b[n - 1] = k - a[n - 2] - 1;
    for (int i = 1; i < n - 1; ++i)
    {
        b[i] = a[i + 1] - a[i - 1] - 2;
    }

    c[0] = b[0];
    for (int j = 1; j < n; ++j)
    {
        c[j] = b[j] + c[j - 1];
    }

    while (q--)
    {
        cin >> l >> r;
        if (l == r)
        {
            ans = k - 1;
        }
        else
        {
            ans = 0;
            --l, --r;
            ans += a[l + 1] - 2;
            ans += k - a[r - 1] - 1;
            ++l, --r;
            if (l <= r)
                ans += c[r] - c[l - 1];
        }
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