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
    long long n, k, invf, invs;
    cin >> n >> k;
    // if (k == 1)
    // {
    //     cout << "1\n";
    //     return;
    // }
    // else if (k == 2)
    // {
    //     cout << "2 1\n";
    //     return;
    // }
    // invs = (n - k) * (2 * (n - k) - 1);
    // invf =
    vector<int> p(k);
    for (int i = 1; i <= k; ++i)
        p[i - 1] = i;

    if (n > k)
        reverse(p.end() - n + k - 1, p.end());
    for (int i = 0; i < k; ++i)
        cout << p[i] << " ";
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