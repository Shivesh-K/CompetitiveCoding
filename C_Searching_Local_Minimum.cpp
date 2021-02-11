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
    int n, m, l, r;
    cin >> n;
    vector<int> a(n + 2, 0);
    a[0] = a[n + 1] = INT32_MAX;
    l = 1, r = n;
    while (l < r)
    {
        m = (l + r) / 2;
        if (m - 1 > 0)
        {
            cout << "? " << m - 1 << "\n";
            cout.flush();
            cin >> a[m - 1];
        }
        if (m + 1 < n + 1)
        {
            cout << "? " << m + 1 << "\n";
            cout.flush();
            cin >> a[m + 1];
        }
        cout << "? " << m << "\n";
        cout.flush();
        cin >> a[m];

        a[m] < a[m + 1] ? r = m : l = m + 1;
    }
    cout << "! " << l << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t = 1;
    while (t--)
    {
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}