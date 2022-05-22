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
    ll n;
    cin >> n;
    vector<int> v(n);
    map<int, vector<int>> mp;
    priority_queue<int> pq;
    for (int &t : v)
        cin >> t;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        mp[t].push_back(v[i]);
    }

    double ans = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int t : mp[i])
            pq.push(t);
        if (pq.empty())
            break;
        sum += pq.top();
        pq.pop();
        ans = max(ans, sum / (i + 1));
    }

    cout << fixed << setprecision(6) << ans << "\n";
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