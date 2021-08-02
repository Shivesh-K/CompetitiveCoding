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
    int n, ans = 0;
    string s1, s2;
    cin >> n >> s1 >> s2;

    for (int i = 0; i < n; ++i)
    {
        if (s2[i] == '0')
            continue;
        if (i > 0 && s1[i - 1] == '1')
            s1[i - 1] = '2', ++ans;
        else if (s1[i] == '0')
            s1[i] = '2', ++ans;
        else if (i < n - 1 && s1[i + 1] == '1')
            s1[i + 1] = '2', ++ans;
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