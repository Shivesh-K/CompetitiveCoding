#include <bits/stdc++.h>
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define fo(i, x, y) for (__typeof(x) i = x; i < y; ++i)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
vector<long long> v, ans;
long long k;
void rec(long long sum, long long pro, long long i)
{
    if (i == k)
    {
        if (pro == sum)
        {
            ans.pb(pro);
            return;
        }
        return;
    }
    rec(sum + v[i], pro, i + 1);
    rec(sum, pro * v[i], i + 1);
}
int main()
{
    fast;
    ll tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t)
    {
        ll m;
        cin >> m;
        vector<ll> p(m + 1), n(m + 1);
        for (long long i = 0; i < m; ++i)
            cin >>
                p[i] >> n[i];
        v.clear();
        ans.clear();
        for (long long i = 0; i < m; ++i)
        {
            while (n[i]--)
                v.pb(p[i]);
        }
        k = v.size();

        rec(0, 1, 0);

        ll final = 0;
        for (long long i = 0; i < ans.size(); ++i)
            final = MAX(final, ans[i]);
        cout << "Case #" << t << ": " << final << "\n";
    }
}
