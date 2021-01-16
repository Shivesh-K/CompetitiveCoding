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
    int n, k, h1, h2, ans = 0;
    long long s = 0;
    cin >> n >> k;
    vector<int> h(n);
    vector<bool> a(n, true);
    for (int &x : h)
        cin >> x, s += x;

    sort(h.begin(), h.end(), greater<int>());

    int i = 0;
    h1 = h2 = 0;
    for (i = 0; i < n; ++i)
    {
        h1 += h[i];
        if (h1 > k)
        {
            h1 -= h[i];
            break;
        }
        ++ans;
        a[i] = false;
    }
    if (i >= n && h1 < k)
    {
        cout << "-1\n";
        return;
    }

    if (h1 < k)
    {
        for (; i < n; ++i)
        {
            if (h1 + h[i] < k)
            {
                h1 += h[i - 1];
                a[i - 1] = false;
                ++ans;
                break;
            }
        }
        if (i >= n)
        {
            h1 += h[i - 1];
            if (h1 < k)
            {
                cout << "-1\n";
                return;
            }
            a[i - 1] = false;
            ++ans;
        }
    }

    for (i = 1; i < n; ++i)
    {
        if (a[i] && !a[i - 1])
        {
            if (h1 - h[i - 1] + h[i] >= k)
            {
                a[i - 1] = true;
                a[i] = false;
                h1 += (h[i] - h[i - 1]);
            }
        }
    }

    for (i = 0; i < n; ++i)
    {
        if (a[i])
        {
            h2 += h[i];
            a[i] = false;
            ++ans;
            if (h2 >= k)
                break;
        }
    }
    if (h2 < k)
    {
        cout << "-1\n";
        return;
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