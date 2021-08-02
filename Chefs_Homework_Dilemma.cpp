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
    int n, k, t;
    cin >> n >> k;
    vector<int> v(n);
    priority_queue<pair<int, int>> pq;
    vector<int> upper(n), lower(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        pq.push({v[i], i});
    }

    while (!pq.empty())
    {
        auto p = pq.top();
        int idx = p.second;
        pq.pop();

        int l = idx - (idx > 0 ? upper[idx - 1] : 0);
        int r = idx + (idx < n - 1 ? lower[idx + 1] : 0);

        if (r - l + 1 <= k)
        {
            for (int i = idx; i <= r; ++i)
                upper[i] = i - l + 1;
            for (int j = idx; j >= l; --j)
                lower[j] = r - j + 1;
            v[idx] = 0;
        }
    }

    ll ans = accumulate(v.begin(), v.end(), 0LL);
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