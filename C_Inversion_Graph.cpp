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
    int n, ans = 0;
    cin >> n;
    vector<int> p(n);
    unordered_map<int, int> mp;
    for (int &t : p)
        cin >> t;

    for (int i = 0; i < n; ++i)
    {
        mp[i + 1]++;
        mp[p[i]]--;

        if (!mp[i + 1])
            mp.erase(i + 1);
        if (!mp[p[i]])
            mp.erase(p[i]);

        if (mp.empty())
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