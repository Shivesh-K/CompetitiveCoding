#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

ll n, m, k;
vector<vector<pair<ll, ll>>> adj;
vector<ll> P, Q;

void compute()
{
    cin >> n >> m >> k;
    adj = vector<vector<pair<ll, ll>>>(n);
    P = Q = vector<ll>(n);

    vector<ll> A(m), B(m), W(m);
    for (ll &t : A)
        cin >> t;
    for (ll &t : B)
        cin >> t;
    for (ll &t : W)
        cin >> t;

    for (int i = 0; i < m; ++i)
    {
        adj[A[i]].push_back({B[i], W[i]});
        adj[B[i]].push_back({A[i], W[i]});
    }

    for (ll &t : P)
        cin >> t;
    for (ll &t : Q)
        cin >> t;

    vector<vector<ll>> dp(n, vector<ll>(k + 1, INT_MAX));
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    pq.push({P[0], Q[0], 0});

    while (!pq.empty())
    {
        auto el = pq.top();
        pq.pop();
        if (el[0] > k || el[1] >= dp[el[2]][el[0]])
            continue;

        dp[el[2]][el[0]] = el[1];

        if (el[0] + P[el[2]] <= k)
            pq.push({el[0] + P[el[2]], el[1] + Q[el[2]], el[2]});

        for (auto next : adj[el[2]])
        {
            if (el[0] + next.second + P[next.first] <= k)
                pq.push({el[0] + next.second + P[next.first], el[1] + Q[next.first], next.first});
        }
    }

    ll ans = INT_MAX;
    for (int i = 0; i < n; ++i)
        ans = min(ans, dp[i][k]);

    if (ans == INT_MAX)
        ans = -1;

    cout << ans << "\n";
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