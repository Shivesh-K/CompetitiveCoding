#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
const ll MOD = 1e9 + 7;

ll inverse(ll a, ll m = MOD)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

string nextNum(string &curr)
{
    string ans = curr;
    int i;
    for (i = 9; i >= 0; --i)
    {
        if (ans[i] == '0')
            break;
        else if (ans[i] == '3')
        {
            ans[i] = '8';
            while (++i < ans.length())
                ans[i] = '3';
            return ans;
        }
    }

    for (int j = i; j < 10; ++j)
        ans[j] = '3';
    return ans;
}

void compute()
{
    ll a1, a2, b1, b2, k;
    cin >> a1 >> a2 >> b1 >> b2 >> k;

    string succ = "0000000003", prev = "0000000000";
    queue<string> q;
    for (int i = 0; i < k - 1; ++i)
    {
        q.push(succ);
        succ = nextNum(succ);
    }

    ll num = 0, den = (a2 - a1 + 1) * (b2 - b1 + 1);

    ll cnt = 1022 - k + 1;
    while (cnt--)
    {
        q.push(succ);
        succ = nextNum(succ);

        while (q.size() > k)
        {
            prev = q.front();
            q.pop();
        }

        ll l = max(a1, stoll(prev) + 1);
        ll r = min(b2, stoll(succ) - 1);
        num += max(min(a2, stoll(q.front())) - l + 1, 0LL) * max(r - max(b1, stoll(q.back())) + 1, 0LL);

        l = max(b1, stoll(prev) + 1);
        r = min(a2, stoll(succ) - 1);
        num += max(min(b2, stoll(q.front())) - l + 1, 0LL) * max(r - max(a1, stoll(q.back())) + 1, 0LL);
    }

    num %= MOD;
    den %= MOD;
    ll ans = (num * inverse(den)) % MOD;

    cout << ans << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    compute();
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}