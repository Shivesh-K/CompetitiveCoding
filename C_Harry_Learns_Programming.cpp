#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int pa[1500] = {0};

void preprocess()
{
    int i, d1 = 1, d2 = 0, d3 = 0, d4 = 0, h = 0, m = 1, sum, max;
    pa[0] = 0;
    pa[1] = 1;
    while (h != 24 || m != 0)
    {
        d1 = m % 10;
        d2 = m / 10;
        d3 = h % 10;
        d4 = h / 10;
        i = h * 60 + m + 1;
        sum = (d4 + d3 + d2 + d1);
        max = max(d1, max(d2, max(d3, d4)));
        if (max == sum - max)
        {
            pa[i] = pa[i - 1] + 1;
        }
        else
        {
            pa[i] = pa[i - 1];
        }
        ++m;
        if (m == 60)
        {
            ++h;
            m = 0;
        }
    }
} //end prepreprocess

void refresh()
{
} //end refresh

void compute()
{
    int sh, sm, eh, em;
    int l, r, ans = 0;
    cin >> sh >> sm >> eh >> em;
    l = sh * 60 + sm + 1;
    r = eh * 60 + em + 1;
    ans = pa[r] - pa[l - 1];
    if (l > r)
        ans += pa[1439];

    cout << ans << "\n";
} //end compute

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i, j;
    preprocess();
    scanf("%d", &t);
    while (t--)
    {
        compute();
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*