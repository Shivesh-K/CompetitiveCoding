#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

unordered_map<int, bool> isP;
unordered_map<int, int> pos;

int calc(int sum)
{
    int ans = 0;
    for (int div = 1; div * div < sum; ++div)
    {
        if (sum % div == 0)
        {
            if (isP[div] && isP[sum / div] && pos[div] + pos[sum / div] == sum)
                ++ans;
        }
    }
    return ans;
}

void compute()
{
    ll n, t;
    cin >> n;
    // vector<ll> v(n);
    for (int i = 0; i < n; ++i)
    {
        // cin >> v[i];
        cin >> t;
        isP[t] = true;
        pos[t] = i + 1;
    }

    if (n == 1)
    {
        cout << "0\n";
        return;
    }

    int ans = 0;
    for (int sum = 3; sum <= 2 * n - 1; ++sum)
    {
        ans += calc(sum);
    }
    cout << ans << "\n";
    isP.clear();
    pos.clear();
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