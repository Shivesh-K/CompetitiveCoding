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
    int n, mx = 0, idx = 0, j;
    cin >> n;
    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (mx < a[i])
        {
            mx = a[i];
            idx = i;
        }
    }
    b[0] = mx;
    c[0] = mx;
    a.erase(a.begin() + idx);

    for (int i = 0; i < n - 1; ++i)
    {
        mx = 0;
        for (j = 0; j < n - 1 - i; ++j)
        {
            if (__gcd(c[i], a[j]) > mx)
            {
                mx = __gcd(c[i], a[j]);
                idx = j;
            }
        }
        b[i + 1] = a[idx];
        c[i + 1] = mx;
        a.erase(a.begin() + idx);
    }

    for (int i = 0; i < n; ++i)
        cout << b[i] << " ";
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