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

    vector<int> a(n), b(n), ac, bc;
    for (int &t : a)
        cin >> t;
    for (int &t : b)
        cin >> t;
    ac = a, bc = b;
    sort(ac.begin(), ac.end());
    sort(bc.begin(), bc.end());

    vector<vector<int>> cnt(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; ++i)
        cnt[ac[i]][bc[i]]++;
    for (int i = 0; i < n; ++i)
        cnt[a[i]][b[i]]--;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (cnt[i][j] != 0)
            {
                cout << "-1\n";
                return;
            }
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == ac[i] && b[i] == bc[i])
            continue;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] == ac[i] && b[j] == bc[i])
            {
                ans.push_back({i + 1, j + 1});
                swap(a[j], a[i]);
                swap(b[j], b[i]);
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto &el : ans)
        cout << el.first << " " << el.second << "\n";
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