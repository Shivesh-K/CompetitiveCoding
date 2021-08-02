#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll rem = 998244353;

int GDBEx(ll A, ll B, ll *X, ll *Y)
{
    if (A == 0)
    {
        *X = 0, *Y = 1;
        return B;
    }

    ll x1, y1;
    ll gcd = GDBEx(B % A, A, &x1, &y1);

    *X = y1 - (B / A) * x1;
    *Y = x1;

    return gcd;
}

ll modInverse(ll B, ll mo)
{
    ll x, y;
    ll g = GDBEx(B, mo, &x, &y);
    if (g != 1)
        return -1;
    return (x % mo + mo) % mo;
}

ll modDivide(ll A, ll B, ll mo)
{
    A = A % mo;
    ll inv = modInverse(B, mo);
    ll c = (inv * A) % mo;
    return c;
}

ll fact(ll n)
{
    ll res = 1;
    for (ll i = 1; i <= n; i++)
        res = (res * i) % rem;

    return res;
}

void compute()
{
    int n;
    string str;
    cin >> n >> str;

    ll ones = 0, zeroes = 0;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == '0')
            ++zeroes;
        else if (str[i] == '1' && i + 1 < n && str[i + 1] == '1')
            ones++, ++i;
    }
    ll a = fact(ones + zeroes);
    ll b = fact(ones);
    ll c = fact(zeroes);

    ll ans = modDivide(a, (b * c) % rem, rem);
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