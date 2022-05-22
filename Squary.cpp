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
    ll n, k, sum = 0, sqsum = 0;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll &t : v)
    {
        cin >> t;
        sum += t;
        sqsum += t * t;
    }

    if (sum == 0)
    {
        if (sqsum == 0)
            cout << "1\n";
        else
            cout << "IMPOSSIBLE\n";
    }
    else if (sqsum % sum == 0 && (sqsum / sum - sum) % 2 == 0)
    {
        cout << ((sqsum / sum - sum) / 2) << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
    // sqsum + ans * ans = (sum + ans) * (sum + ans)
    // sqsum = sum * sum + 2 * ans * sum
    // ans = ((sqsum / sum) - sum) / 2;
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