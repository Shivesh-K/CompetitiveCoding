#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    long long n, m, mx = 0, ans = 0;
    cin >> n >> m;
    vector<long> a(n);
    for (long long i = 0; i < n; ++i)
    {
        cin >> a[i];
        ans += a[i];
        mx = max(mx, a[i]);
    }
    mx = max(mx, n);
    ans = ans - mx;
    cout << ans << "\n";
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*