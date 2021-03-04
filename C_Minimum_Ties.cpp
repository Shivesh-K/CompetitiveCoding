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
    int n, d;
    cin >> n;
    map<pair<int, int>, char> m;

    d = (n - 1) / 2;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= i + d; ++j)
        {
            m[{i, (j - 1) % n + 1}] = '1';
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (m[{i, j}] == '1')
                cout << "1 ";
            else if (m[{j, i}] == '1')
                cout << "-1 ";
            else
                cout << "0 ";
        }
    }
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