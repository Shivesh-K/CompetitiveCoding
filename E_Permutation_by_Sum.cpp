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
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    vector<int> v(n);
    vector<bool> bo(n, false);
    --l, --r;

    int d = r - l + 1;
    if (s > ((n * (n + 1) / 2) - ((n - d) * (n - d + 1) / 2)) || s < d * (d + 1) / 2)
    {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < r - l + 1; ++i)
    {
        v[l + i] = i + 1;
        bo[i] = true;
    }
    s -= d * (d + 1) / 2;

    int i = r;
    int m = n;
    while (s > 0)
    {
        if (v[i] + s <= m)
        {
            bo[v[i] - 1] = false;
            v[i] += s;
            bo[v[i] - 1] = true;
            s = 0;
            break;
        }
        else
        {
            s -= (m - v[i]);
            bo[v[i] - 1] = false;
            v[i] = m;
            bo[v[i] - 1] = true;
            --m;
            --i;
        }
    }

    int idx = 0;
    for (i = 0; i < l; ++i)
    {
        while (bo[idx])
            ++idx;
        v[i] = ++idx;
    }
    for (i = r + 1; i < n; ++i)
    {
        while (bo[idx])
            ++idx;
        v[i] = ++idx;
    }

    for (int t : v)
        cout << t << " ";
    cout << "\n";
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