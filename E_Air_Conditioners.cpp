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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> ac(k);
    vector<ll> ans(n, INT_MAX);

    for (auto &el : ac)
    {
        cin >> el.first;
        el.first--;
    }
    for (auto &el : ac)
    {
        cin >> el.second;
    }

    sort(ac.begin(), ac.end());

    ll pos = 0, temp = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (pos < k && i == ac[pos].first)
        {
            temp = min(temp, ac[pos].second);
            pos++;
        }
        ans[i] = min(ans[i], temp);
        temp++;
    }

    pos = k - 1, temp = INT_MAX;
    for (int i = n - 1; i >= 0; --i)
    {
        if (pos >= 0 && i == ac[pos].first)
        {
            temp = min(temp, ac[pos].second);
            pos--;
        }
        ans[i] = min(ans[i], temp);
        temp++;
    }

    for (ll t : ans)
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