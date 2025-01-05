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
    int n, k;
    cin >> n;

    vector<int> rates(n), strategy(n);
    for (int &t : rates)
        cin >> t;
    for (int &t : strategy)
        cin >> t;

    cin >> k;

    vector<int> prefixRates(n + 1, 0);
    for (int i = 0; i < n; ++i)
        prefixRates[i + 1] = prefixRates[i] + rates[i];

    vector<int> prefixStrategy(n + 1, 0);
    for (int i = 0; i < n; ++i)
        prefixStrategy[i + 1] = prefixStrategy[i] + rates[i] * strategy[i];

    int ans = prefixStrategy.back();
    for (int i = 0; i < n - k; ++i)
    {
        int l = prefixStrategy[i];
        int r = prefixStrategy.back() - prefixStrategy[i + k];
        int mu = rates[i + k] - rates[i + k / 2];
        ans = max(ans, l + r + mu);
    }

    cout << ans;
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