#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

bool possible(int a, int b, int c, int k)
{
    return ((b - k) * (b - k) - 4 * a * c) < 0;
}

void compute()
{
    ll n, m;
    cin >> n >> m;

    vector<double> v;
    bool ze = false;
    while (n--)
    {

        double t;
        cin >> t;
        if ((ll)t == 0)
            ze = true;
        else
            v.push_back(t);
    }

    sort(v.begin(), v.end());

    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (-c >= 0)
        {
            cout << "NO\n";
            continue;
        }
        else if (ze && b * b < 4 * a * c)
        {
            cout << "YES\n"
                 << 0 << "\n";
            continue;
        }

        double l = sqrt(4 * a * c) + 1.0 * b;
        double r = -sqrt(4 * a * c) + 1.0 * b;

        ll lidx = upper_bound(v.begin(), v.end(), r) - v.begin();
        ll ridx = lower_bound(v.begin(), v.end(), l) - v.begin() - 1;

        if (lidx <= ridx)
            cout << "YES\n"
                 << (ll)v[lidx] << "\n";
        else
            cout << "NO\n";
    }
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