#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<ll>> adj;
vector<ll> fun, chainFun;
set<ll> roots;
ll n;

ll setChainFun(ll node)
{
    if (chainFun[node] != -1)
        return chainFun[node];

    ll mn = INT_MAX, mnNext = 0;
    for (ll next : adj[node])
    {
        ll t = setChainFun(next);
        if (t < mn)
            mn = t, mnNext = next;
    }

    if (mnNext)
        adj[node] = {mnNext}, roots.erase(mnNext);

    chainFun[node] = mnNext ? max(mn, fun[node]) : fun[node];
    return chainFun[node];
}

void compute()
{
    cin >> n;
    adj = vector<vector<ll>>(n + 1);
    fun = vector<ll>(n + 1);
    chainFun = vector<ll>(n + 1, -1);
    roots.clear();

    for (ll i = 1; i <= n; ++i)
        roots.insert(i);
    for (ll i = 1; i <= n; ++i)
        cin >> fun[i];
    for (ll i = 1; i <= n; ++i)
    {
        ll t;
        cin >> t;
        if (t)
            adj[t].push_back(i);
    }

    for (ll i = 1; i <= n; ++i)
        setChainFun(i);

    ll ans = 0;
    for (ll node : roots)
        ans += chainFun[node];

    cout << ans << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ": ";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}