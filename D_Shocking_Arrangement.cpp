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
    vector<ll> v(n);
    for (ll &t : v)
        cin >> t;
    sort(v.begin(), v.end());

    if (v.back() == 0LL)
    {
        cout << "No\n";
        return;
    }

    vector<int> ans;
    ll diff = (ll)v.back() - (ll)v.front();
    bool fl;
    int l = 0, r = n - 1;
    ll sum = 0;

    if (abs(v[0]) <= abs(v[n - 1]))
    {
        ans.push_back(v[0]);
        fl = true;
        l = 1;
        sum = abs(v[0]);
    }
    else
    {
        ans.push_back(v[n - 1]);
        fl = false;
        r = n - 2;
        sum = abs(v[n - 1]);
    }

    while (l <= r)
    {
        ll x = ((fl ^ (v[l] < 0)) ? abs(v[l]) : sum + abs(v[l]));
        ll y = ((fl ^ (v[r] < 0)) ? abs(v[r]) : sum + abs(v[r]));
        if (x < y)
        {
            fl = (v[l] < 0);
            sum = x;
            ans.push_back(v[l]);
            ++l;
        }
        else if (y < x)
        {
            fl = (v[r] < 0);
            sum = y;
            ans.push_back(v[r]);
            --r;
        }
        else
        {
            if ((fl ^ (v[l] < 0)) == 0)
            {
                fl = (v[l] < 0);
                sum = x;
                ans.push_back(v[l]);
                ++l;
            }
            else
            {

                fl = (v[r] < 0);
                sum = y;
                ans.push_back(v[r]);
                --r;
            }
        }
    }

    cout << "Yes\n";
    for (int t : ans)
        cout << t << " ";
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