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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, m, x, y, a, b, area, ans;
        cin >> n >> m >> x >> y;

        if (y <= x)
        {
            b = y;
        }
        else
        {
            if (y - x == x)
            {
                b = y - x;
            }
            else
            {
                b = x;
            }
        }

        if (y - b > x)
        {
            a = x;
        }
        else
        {
            a = y - b;
        }

        if (a > b)
        {
            a = a + b - (b = a);
        }

        area = n * m;
        if (area % 2 == 1)
        {
            ans = (a * (area / 2)) + (b * (area - (area / 1)));
        }
        else
        {
            ans = (a + b) * (area / 2);
        }

        cout << ans << "\n";
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*