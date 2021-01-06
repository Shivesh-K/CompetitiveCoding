#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i, j;
    scanf("%d", &t);
    while (t--)
    {
        long long n, s0, s1, temp, ans, m = 1000000007;
        cin >> n >> s0 >> s1;

        ans = s1;
        if (s0 != 0 && s1 != 0)
        {
            for (long long i = 2; i <= n; ++i)
            {
                temp = s1;
                s1 = (((((s1 * s1) % m) * ((s1 * s0) % m)) % m) * (s0 % m)) % m;
                s0 = temp;
                ans = s1;
            }
        }
        cout << ans << "\n";
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*