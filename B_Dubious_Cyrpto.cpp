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

void preprocess()
{
} //end prepreprocess

void refresh()
{
} //end refresh

void compute()
{
    long long a, b, c, l, r, m, n, mn = 1e18, temp;
    cin >> l >> r >> m;

    for (a = l; a <= r; ++a)
    {
        if (m / a == 0)
        {
            mn = m - a;
            temp = a;
        }
        else
        {
            if (m % a < a - m % a)
            {
                temp = a;
                n = m / a;
                mn = min(m - (a * n), mn);
            }
            else
            {
                temp = a;
                n = m / a;
                mn = min(m - (a * (n + 1)), mn);
            }
        }
    }

    if (mn >= 0)
    {
        a = temp;
        c = l;
        b = l + mn;
    }
    else
    {
        a = temp;
        b = l;
        c = l - mn;
    }

    cout << a << " " << b << " " << c << "\n";
} //end compute

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i, j;
    preprocess();
    scanf("%d", &t);
    while (t--)
    {
        compute();
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*