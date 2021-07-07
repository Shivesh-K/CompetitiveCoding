#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<pair<long long, long long>>> adj(n + 1);
    vector<long long> dp(n + 1, LLONG_MAX);
    vector<bool> processed(n + 1, false);

    long long from, to, cost;
    while (m--)
    {
        cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
    }

    long long city, mn, next, length;
    priority_queue<pair<long long, long long>> q;
    q.push({0, 1});
    dp[1] = 0;

    while (!q.empty())
    {
        mn = q.top().first;
        city = q.top().second;
        q.pop();

        if (processed[city])
            continue;
        processed[city] = true;

        for (auto flight : adj[city])
        {
            next = flight.first;
            length = flight.second;
            if (dp[next] > length - mn)
            {
                dp[next] = length - mn;
                q.push({-dp[next], next});
            }
        }
    }

    for (long long i = 1; i <= n; ++i)
        cout << dp[i] << " ";
    cout << "\n";
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