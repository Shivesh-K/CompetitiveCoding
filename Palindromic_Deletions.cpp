#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
// #define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<int> v;
int sum = 0, cnt = 0;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll power(ll x, unsigned ll y, unsigned ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}

ll modInverse(ll a, ll m)
{
    ll g = gcd(a, m);
    return power(a, m - 2, m);
}

bool isPalindrome(string &s)
{
    int n = s.length();
    int i = 0, j = n - 1;
    while (i < n)
    {
        if (s[i] == 0)
            ++i;
        else if (s[j] == 0)
            --j;
        else if (s[i] != s[j])
            return false;
        else
            ++i, --j;
    }
    return true;
}

void calc(string s)
{
    for (int &t : v)
    {
        s[t] = 0;
        sum += isPalindrome(s);
    }
}

void permute(string &s, int idx)
{
    if (idx >= v.size())
    {
        ++cnt;
        string t(s);
        calc(t);
    }

    for (int i = idx; i < v.size(); ++i)
    {
        swap(v[i], v[idx]);
        permute(s, idx + 1);
        swap(v[i], v[idx]);
    }
}

void compute()
{
    int n;
    string s;
    cin >> n >> s;

    sum = 0, cnt = 0;
    v = vector<int>(n);
    for (int i = 0; i < n; ++i)
        v[i] = i;

    permute(s, 0);
    int div = gcd(sum, cnt);
    sum /= div;
    cnt /= div;

    ll MOD = 1e9 + 7;
    ll ans = (sum * modInverse(cnt, MOD)) % MOD;
    cout << ans << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ": ";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}