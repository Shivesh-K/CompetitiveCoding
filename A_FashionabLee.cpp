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
    long long int n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        n % 4 == 0 ? cout << "YES\n" : cout << "NO\n";
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*