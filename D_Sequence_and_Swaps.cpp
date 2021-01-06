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
    int n, x, ans = 0;
    bool f = true;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (i > 0 && a[i] < a[i - 1])
            f = false;
    }

    if (f)
    {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] > x)
        {
            ans++;
            swapi(&x, &a[i]);
        }
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            cout << "-1\n";
            return;
        }
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