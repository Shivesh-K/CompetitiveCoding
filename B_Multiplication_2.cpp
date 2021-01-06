#include <bits/stdc++.h>
using namespace std;

void compute()
{
    long long a[100010];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    int zero = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            zero++;
    if (zero > 0)
    {
        // a[i] contains 0
        printf("0\n");
        return;
    }
    long long prod = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 1000000000000000000 / prod)
        {
            // This condition is equivalent to prod*a[i] <=10ˆ18
            prod *= a[i];
        }
        else
        {
            printf("-1\n");
            return;
        }
    }
    printf("%lld\n", prod);
} //end compute

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
} //end main*