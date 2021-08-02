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

    if (n == 1)
    {
        if (v[0])
            cout << "NO\n";
        else
            cout << "YES\n";
        return;
    }

    if (n == 2)
    {
        if (abs(v[0]) == abs(v[1]))
            cout << "YES\n";
        else
            cout << "NO\n";
        return;
    }

    unordered_map<int, int> f;
    for (int t : v)
    {
        f[t]++;
        if (f[t] > 1)
        {
            cout << "YES\n";
            return;
        }
    }

    if (f[0])
    {
        cout << "YES\n";
        return;
    }

    sort(v.begin(), v.end());

    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i)
        pre[i + 1] = pre[i] + v[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            for (int k = 0; k <= j; ++k)
            {
                if (v[i] == pre[j] - pre[k])
                {
                    cout << "YES\n";
                    return;
                }
            }
        }
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