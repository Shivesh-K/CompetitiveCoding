#include <bits/stdc++.h>
using namespace std;

void compute()
{
    int n, k, guess = 0, response;
    cin >> n >> k;

    for (int x = 0; x < n; ++x)
    {
        int y = guess ^ x;
        cout << y << "\n";
        cout.flush();
        cin >> response;
        if (response == 1)
            return;
        guess ^= y;
    }
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