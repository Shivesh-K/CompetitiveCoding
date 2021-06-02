#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int n;
vector<int> a, b, c;

void compute()
{
    cin >> n;
    a = b = c = vector<int>(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];

    for (int i = n - 2; i >= 0; --i)
    {
        a[i] = a[i] + max(b[i + 1], c[i + 1]);
        b[i] = b[i] + max(c[i + 1], a[i + 1]);
        c[i] = c[i] + max(a[i + 1], b[i + 1]);
    }

    int ans = max(a[0], max(b[0], c[0]));
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