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
        int n, temp;
        bool s[51] = {false};
        cin >> n;
        n <<= 1;
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            if (!s[temp])
            {
                printf("%d ", temp);
                s[temp] = true;
            }
        }
        printf("\n");
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*