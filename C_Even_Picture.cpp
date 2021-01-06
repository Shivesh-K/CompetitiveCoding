#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif

    int n, i;
    cin >> n;
    cout << 3 * n + 4 << "\n";
    cout << "0 0\n";
    for (i = 1; i <= n + 1; ++i)
    {
        cout << i << " " << i << "\n";
        cout << i - 1 << " " << i << "\n";
        cout << i << " " << i - 1 << "\n";
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*