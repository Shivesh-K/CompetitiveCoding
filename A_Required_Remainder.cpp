#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    long int t;
    scanf("%ld", &t);
    while (t--)
    {
        long long x, y, n, temp, k;
        scanf("%lld %lld %lld", &x, &y, &n);
        temp = n % x;

        if (y == temp)
        {
            k = n;
        }
        else
        {
            k = n - temp + y;
            k -= y > temp ? x : 0;
        }

        cout << k << "\n";
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*