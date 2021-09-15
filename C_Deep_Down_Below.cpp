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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> cave;

    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        cave = vector<int>(k);
        for (int &t : cave)
            cin >> t;

        for (int j = k - 1; j >= 0; --j)
        {
            --v[i].first;
            v[i].first = max(v[i].first, cave[j] + 1);
        }
        v[i].second = k;
    }

    sort(v.begin(), v.end());

    int ans = 0, curr = 0;
    for (auto &el : v)
    {
        if (el.first > curr)
            ans += el.first - curr;
        curr = max(curr, el.first) + el.second;
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