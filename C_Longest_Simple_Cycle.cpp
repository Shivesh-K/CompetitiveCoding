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
    long long n, ans;
    cin >> n;
    vector<long long> a(n), b(n), c(n);
    for (auto &x : c)
        cin >> x;
    for (auto &y : a)
        cin >> y;
    for (auto &z : b)
        cin >> z;

    long long m = abs(a[1] - b[1]) + 2;
    ans = m + c[1] - 1;
    for (long long i = 2; i < n; ++i)
    {

        if (a[i] == b[i])
            m = 2;
        else if (m + c[i - 1] - 1 - abs(a[i] - b[i]) < abs(a[i] - b[i]))
            m = abs(a[i] - b[i]) + 2;
        else
            m += c[i - 1] - 1 - abs(a[i] - b[i]) + 2;
        ans = max(ans, m + c[i] - 1);
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