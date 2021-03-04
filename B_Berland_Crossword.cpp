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
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;

    for (int i = 0; i < 16; ++i)
    {
        int tu = u, tr = r, td = d, tl = l;
        if (i & 1)
            --tu, --tl;
        if (i & 2)
            --tu, --tr;
        if (i & 4)
            --tr, --td;
        if (i & 8)
            --td, --tl;

        if (tu >= 0 && tr >= 0 && td >= 0 && tl >= 0 && tu <= n - 2 && tr <= n - 2 && td <= n - 2 && tl <= n - 2)
        {
            cout << "YES\n";
            return;
        }
    }
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