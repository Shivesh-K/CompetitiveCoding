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
    long long r, g, b, w, x, o1, o2, o3, o4, t;
    cin >> r >> g >> b >> w;

    x = min(r, min(g, b));
    r -= x;
    g -= x;
    b -= x;
    w += 3 * x;

    o1 = r & 1;
    o2 = g & 1;
    o3 = b & 1;
    o4 = w & 1;

    t = o1 + o2 + o3 + o4;
    if (t == 0 || t == 1)
    {
        cout << "Yes\n";
    }
    else
    {
        if (t == 2)
        {
            cout << "No\n";
        }
        else
        {
            if (x > 0)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
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