#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<int> pr(n + 1);
    for (int i = 0; i < n; ++i)
    {
        pr[i + 1] = pr[i] + s[i] - 'a' + 1;
    }

    int l, r;
    while (q--)
    {
        cin >> l >> r;
        cout << (pr[r] - pr[l - 1]) << "\n";
    }
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