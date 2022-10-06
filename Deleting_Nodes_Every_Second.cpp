#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int n, m;
vector<int> connected;
vector<bool> used;
vector<vector<int>> adj;

void compute()
{
    cin >> n >> m;
    connected = vector<int>(n);
    used = vector<bool>(n);
    adj = vector<vector<int>>(n);

    while (m--)
    {
        int x, y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        connected[x]++;
        connected[y]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (connected[i] <= 1)
            q.push(i), used[i] = true;

    int ans = 0;
    while (!q.empty())
    {
        int l = q.size();
        while (l--)
        {
            int node = q.front();
            q.pop();

            for (int next : adj[node])
            {
                connected[next]--;
                if (connected[next] <= 1 && !used[next])
                {
                    q.push(next);
                    used[next] = true;
                }
            }
        }
        ++ans;
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