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
    int k;
    cin >> k;
    --k;

    int d = 1, cnt = 4;
    while (k >= cnt)
    {
        k -= cnt;
        ++d;
        cnt *= 5;
    }

    bool fl = false;
    cnt /= 4;
    string ans;
    ans += 2 * (k / cnt + 1) + '0';
    while (--d)
    {
        k %= cnt;
        fl = !fl;
        cnt /= 5;
        int x = k / cnt;
        ans += 2 * x + fl + '0';
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