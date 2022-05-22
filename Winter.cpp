#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

map<ll, vector<ll>> adj;
vector<bool> frozen;
queue<ll> qq;

void setFrozen(ll time)
{
    while (qq.size() && time--)
    {
        ll t = qq.size();
        while (t--)
        {
            ll node = qq.front();
            qq.pop();
            for (ll next : adj[node])
            {
                if (!frozen[next])
                {
                    frozen[next] = true;
                    qq.push(next);
                }
            }
        }
    }
}

void compute()
{
    ll n, m, q;
    cin >> n >> m >> q;
    frozen = vector<bool>(n + 1);

    while (m--)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        if (x == 1)
        {
            if (frozen[y])
                continue;
            frozen[y] = true;
            qq.push(y);
        }
        else if (x == 2)
        {
            setFrozen(y);
        }
        else
        {
            cout << (frozen[y] ? "YES\n" : "NO\n");
        }
    }
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    compute();

#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}