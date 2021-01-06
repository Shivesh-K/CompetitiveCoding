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
        long long n;
        cin >> n;
        n--;
        if (n & 1)
        {
            n = (n >> 1) + 1;
        }
        else
        {
            n = n >> 1;
        }
        cout << n << "\n";
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*