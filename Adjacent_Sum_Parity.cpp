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
    vector<int> v(n);
    for (int &t : v)
        cin >> t;

    vector<int> ans(n);

    ans[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        ans[i] = (v[i - 1] - ans[i - 1] + 2) % 2;
    }
    if (v[n - 1] == (ans[n - 1] + ans[0]) % 2)
    {
        cout << "YES\n";
        return;
    }

    ans[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        ans[i] = (v[i - 1] - ans[i - 1] + 2) % 2;
    }
    if (v[n - 1] == (ans[n - 1] + ans[0]) % 2)
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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