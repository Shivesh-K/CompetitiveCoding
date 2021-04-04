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
    int n;
    cin >> n;
    vector<int> q(n), mi(n + 1), ma(n + 1), a1(n + 1), a2(n + 1);
    set<int> s1, s2;
    for (int &t : q)
        cin >> t;

    for (int i = 1; i <= n; ++i)
    {
        mi[i] = i;
        ma[i] = i;
    }

    a1[0] = a2[0] = q[0];
    mi[q[0]] = ma[q[0]] = -1;

    for (int j = 1; j < n; ++j)
    {
        while (q[j] == q[j - 1])
        {
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