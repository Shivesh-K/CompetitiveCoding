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
    ll n, po = 0, ne = 0, ze = 0;
    cin >> n;
    vector<ll> v(n);
    for (ll &t : v)
    {
        cin >> t;
        if (t > 0)
            ++po;
        else if (t < 0)
            ++ne;
        else
            ++ze;
    }

    if (po > 2 || ne > 2)
        cout << "NO\n";
    else
    {
        vector<ll> temp;
        for (int t : v)
            if (t != 0)
                temp.push_back(t);

        int cnt = min(2, ze);
        while (cnt--)
            temp.push_back(0);

        set<ll> se(temp.begin(), temp.end());
        n = temp.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k)
                    if (se.count(temp[i] + temp[j] + temp[k]) == 0)
                    {
                        cout << "NO\n";
                        return;
                    }

        cout << "YES\n";
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