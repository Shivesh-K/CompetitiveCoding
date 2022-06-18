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
    ll l, r;
    cin >> l >> r;

    if (r < 5)
    {
        cout << "-1\n";
        return;
    }

    ll ans[] = {l, l + 1, l + 2, l + 3};
    bool b = false;
    while (!b)
    {
        if (ans[3] > r)
            break;
        if ((ans[0] ^ ans[1] ^ ans[2] ^ ans[3]) == 0)
        {
            b = true;
            break;
        }
        ans[0]++;
        ans[1]++;
        ans[2]++;
        ans[3]++;
    }

    if (!b)
    {
        cout << "-1\n";
        return;
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
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