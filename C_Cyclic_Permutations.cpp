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

long long modFact(long long n, long long p)
{
    if (n >= p)
        return 0;

    long result = 1;
    for (long i = 1; i <= n; i++)
        result = (result * i) % p;

    return result;
}

long long powFact(long long n, long long p, long long m)
{
    long result = 1;
    for (long i = 1; i <= p; i++)
        result = (result * n) % m;

    return result;
}

void compute()
{
    long long n, p, ans;
    cin >> n;
    p = (long long)1000000007;
    ans = modFact(n, p);
    ans = (ans - powFact(2, n - 1, p) + p) % p;
    cout << ans << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    compute();

#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}