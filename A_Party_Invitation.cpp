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
        long long n, k;
        bool kp, count = false;
        cin >> n >> k;

        kp = k & 1;
        if (n % 2 == 0 && (((n / 2) & (n / 2) == 0) == kp))
            count = true;

        count ? cout << "Tushar\n" : cout << "Gagan\n";
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*