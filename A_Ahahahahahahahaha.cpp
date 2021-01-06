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
    int n, c = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            ++c;
        }
    }
    if (c <= (n / 2))
    {
        cout << n / 2 << "\n";
        for (int i = 0; i < n / 2; ++i)
        {
            cout << "0 ";
        }
        cout << "\n";
    }
    else
    {
        if ((n / 2) & 1)
        {
            cout << n / 2 + 1 << "\n1 ";
        }
        else
        {
            cout << n / 2 << "\n";
        }
        for (int i = 0; i < n / 2; ++i)
        {
            cout << "1 ";
        }
        cout << "\n";
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