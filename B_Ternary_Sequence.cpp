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
    long long x1, x2, y1, y2, z1, z2, ans = 0, temp;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    temp = min(z1, y2);
    ans += (temp << 1);
    z1 -= temp;
    y2 -= temp;

    temp = min(z1, z2);
    z1 -= temp;
    z2 -= temp;

    temp = min(z1, x2);
    z1 -= temp;
    x2 -= temp;

    temp = min(x1, z2);
    x1 -= temp;
    z2 -= temp;

    temp = min(y1, z2);
    ans -= (temp << 1);
    y1 -= temp;
    z2 -= temp;

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