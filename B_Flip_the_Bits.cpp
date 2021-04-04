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
    int n, x, y, last;
    string a, b;
    cin >> n >> a >> b;
    vector<int> v(n);

    x = y = 0;
    last = -1;
    for (int i = 0; i < n; ++i)
    {
        x += (a[i] == '0');
        y += (a[i] == '1');
        if (x == y)
            last = i;
        v[i] = last;
    }

    bool bo = true;
    for (int i = n - 1; i >= 0; --i)
    {
        if ((bo && a[i] != b[i]) || (!bo && a[i] == b[i]))
        {
            if (v[i] < i)
            {
                cout << "NO\n";
                return;
            }
            else
            {
                // x -= (b[i] == '0');
                // y -= (b[i] == '0');
                bo = !bo;
            }
        }
    }
    cout << "YES\n";
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