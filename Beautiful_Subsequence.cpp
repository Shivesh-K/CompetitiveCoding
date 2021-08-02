#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int dp[1001][1001];
int v[1001];
int n, k;

int recur(int idx, int prev, int cnt)
{
    if (idx >= n)
        return 0;
    if (dp[prev + 1][cnt] != -1)
        return dp[prev][cnt];

    int ans = recur(idx + 1, prev, 0);
    if (prev == -1 || (v[idx] != v[prev]) && cnt < k)
        ans = max(ans, 1 + recur(idx + 1, idx, cnt + 1));
    else if (v[idx] == v[prev])
        ans = max(ans, 1 + recur(idx + 1, idx, cnt));

    return dp[prev + 1][cnt] = ans;
}

void compute()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    memset(dp, -1, sizeof(dp));

    int ans = recur(0, -1, 0);
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