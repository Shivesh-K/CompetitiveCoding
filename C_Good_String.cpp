#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

void compute()
{
    string s;
    cin >> s;

    int n = s.length();
    int ans = 1e6;

    if (n <= 2)
    {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int r = n;
            bool f = false;
            for (int k = 0; k < n; ++k)
            {
                if (!f && s[k] == i + '0')
                {
                    --r;
                    f = !f;
                }
                else if (f && s[k] == j + '0')
                {
                    --r;
                    f = !f;
                }
            }
            if (f && i != j)
            {
                ++r;
            }
            ans = min(ans, r);
        }
    }
    cout << ans << "\n";
}

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
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}