#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<int> seg;
int total;

void update(int idx, int val)
{
    idx += total / 2;
    seg[idx] = val;
    int l, r;

    while (idx > 0)
    {
        idx = (idx - 1) / 2;
        l = (idx << 1) + 1;
        r = (idx << 1) + 2;
        seg[idx] = min(seg[l], seg[r]);
    }
}

void printMin(int l, int r)
{
    l += total / 2;
    r += total / 2;
    int mn = INT_MAX;
    while (l < r)
    {
        if (l % 2 == 0)
        {
            mn = min(mn, seg[l]);
            ++l;
        }
        if (r % 2 == 1)
        {
            mn = min(mn, seg[r]);
            --r;
        }
        l = (l - 1) / 2;
        r = (r - 1) / 2;
    }
    mn = min(mn, seg[l]);
    cout << mn << "\n";
}

void compute()
{
    int N, Q;
    cin >> N >> Q;

    int t = 1;
    while (t < N)
        t <<= 1;
    total = 2 * t - 1;
    seg = vector<int>(total, INT_MAX);

    for (int i = 0; i < N; ++i)
    {
        cin >> t;
        update(i, t);
    }

    char ch;
    int x, y;
    while (Q--)
    {
        cin >> ch >> x >> y;
        if (ch == 'u')
            update(x - 1, y);
        else
            printMin(x - 1, y - 1);
    }
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    compute();

#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}