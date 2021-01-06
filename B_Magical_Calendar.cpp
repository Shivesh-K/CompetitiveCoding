#include <bits/stdc++.h>
using namespace std;

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
        long long n, r, ans = 0;
        cin >> n >> r;

        if (r >= n)
        {
            ans += 1;
            r = n - 1;
        }
        ans += (r * (r + 1) >> 1);

        cout << ans << "\n";
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*