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
        int n, temp, p, ans = 0;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (a[i] && a[i] != i)
            {
                p = a[i];
                a[i] = 0;
                while (p != i)
                {
                    ++ans;
                    temp = a[p];
                    a[p] = 0;
                    p = temp;
                }
            }
        }
        printf("%d\n", ans);

    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*