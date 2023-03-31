#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &t : a)
        cin >> t;
    for (int &t : b)
        cin >> t;

    bool fl = true;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[n - 1] || b[i] > b[n - 1])
            swap(a[i], b[i]);
        if (a[i] > a[n - 1] || b[i] > b[n - 1])
        {
            fl = false;
            break;
        }
    }

    if (fl)
    {
        cout << "Yes\n";
        return;
    }

    fl = true;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > b[n - 1] || b[i] > a[n - 1])
            swap(a[i], b[i]);
        if (a[i] > b[n - 1] || b[i] > a[n - 1])
        {
            fl = false;
            break;
        }
    }

    if (fl)
        cout << "Yes\n";
    else
        cout << "No\n";
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