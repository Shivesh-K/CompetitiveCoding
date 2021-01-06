#include <bits/stdc++.h>
using namespace std;

void compute()
{
    int n, m, temp, count = 0;
    double min;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        count += a[i];
    }

    min = 1.0 * count / (4.0 * m);
    count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= min)
            ++count;
    }

    if (count >= m)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
} //end compute

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t;
    compute();
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*