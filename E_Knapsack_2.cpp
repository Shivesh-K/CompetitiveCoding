#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long int
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<ll>> dp;
vector<ll> weights, values;
ll N, W, maxVal;

ll recur(ll target, ll i)
{
    if (target == 0)
        return 0;
    if (i >= N)
        return 1e12;
    if (dp[target][i] != -1)
        return dp[target][i];

    ll ans = recur(target, i + 1);
    if (values[i] <= target)
        ans = min(ans, weights[i] + recur(target - values[i], i + 1));

    return dp[target][i] = ans;
}

void compute()
{
    cin >> N >> W;
    weights = values = vector<ll>(N);
    maxVal = 0;

    for (long long i = 0; i < N; ++i)
    {
        cin >> weights[i] >> values[i];
        maxVal += values[i];
    }
    dp = vector<vector<ll>>(maxVal + 1, vector<ll>(N, -1));

    ll ans = 0, t;
    for (int val = maxVal; val >= 1; --val)
    {
        t = recur(val, 0);
        if (t <= W)
        {
            ans = val;
            break;
        }
    }

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