#include <bits/stdc++.h>
using namespace std;
#define max(v, b) ((a) > (b) ? (a) : (b))
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
    int mn = INT_MAX;
    for (int &t : v)
    {
        cin >> t;
        mn = min(mn, t);
    }

    int cnt = 0;
    bool b = true;
    for (int t : v)
    {
        if (t == mn)
        {
            cnt++;
        }
        else
        {
            int x = t - mn;
            if (t % x != mn)
            {
                b = false;
                break;
            }
        }
    }

    if (b)
        cout << (n - cnt) << "\n";
    else
        cout << n << "\n";
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