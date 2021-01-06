#include <bits/stdc++.h>
using namespace std;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
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
    long int h, c, t, ans = 2;
    double n, t1, t2, t3, min;
    cin >> h >> c >> t;

    if ((h + c) / 2.0 >= t)
    {
        ans = 2;
    }
    else
    {
        n = 1.0 * (t - h) / (h + c - 2.0 * t);
        // cout << n << endl;
        n = ceil(n);
        t1 = abs((1.0 * t) - (1.0 * (n * h + (n - 1) * c) / (2.0 * n - 1)));
        t2 = abs((1.0 * t) - (1.0 * ((n + 1) * h + n * c) / (2.0 * n + 1)));
        t3 = abs((1.0 * t) - (1.0 * ((n + 2) * h + (n + 1) * c) / (2.0 * n + 3)));
        min = min(min(t1, t2), t3);
        // cout << n << " " << t1 << " " << t2 << " " << t3;
        if (min == t1)
        {
            ans = 2 * n - 1;
        }
        else if (min == t2)
        {
            ans = 2 * n + 1;
        }
        else
        {
            ans = 2 * n + 3;
        }
    }

    cout << ans << "\n";
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