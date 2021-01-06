#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>
#define mii map<int, int>
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define tr(container, it) for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define inf (long long)1e18
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define rep(i, n) for (int i = 0; i < n; i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
const int N = 1e9 + 7;

int pow(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = ((res) * (x));
        res %= N;
        y = y >> 1;
        x = ((x) * (x));
    }
    return res;
}
int powm(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int arr[1001][1001];
void solve()
{
    int n, m;
    cin >> n >> m;
    int mn = inf;
    int mx = 0;
    int r = 0;
    int orr = 0;
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> arr[i][j];
            orr = orr | arr[i][j];
            mx = max(mx, arr[i][j]);
            mn = min(mn, arr[i][j]);
            if (arr[i][j] == 0)
                r++;
        }
    }
    if (r == n * m)
    {
        cout << 0 << "\n";
        return;
    }
    if (r > 0)
    {
        cout << 1 << "\n";
        cout << 1 << " " << 1 << " " << n << " " << m << " " << 0 << "\n";
        return;
    }

    int j = 0;
    while (orr > 0)
    {
        if ((orr & 1) == 0)
        {
            if (pow(2, j) <= mx && pow(2, j) >= mn)
            {
                cout << 1 << "\n";
                cout << 1 << " " << 1 << " " << n << " " << m << " " << pow(2, j) << "\n";
                return;
            }
        }
        orr >>= 1;
        j++;
    }

    int temp = floor(log2(double(mn)));
    temp++;
    if (mx >= pow(2, temp))
    {
        cout << 2 << "\n";
        cout << 1 << " " << 1 << " " << n << " " << m << " " << pow(2, temp) << "\n";
        cout << 1 << " " << 1 << " " << n << " " << m << " " << 0 << "\n";
        return;
    }
    cout << -1 << "\n";
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}