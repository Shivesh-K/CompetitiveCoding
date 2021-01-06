#include <bits/stdc++.h>
using namespace std;

long recursive(string s, long n, char c)
{
    if (n == 1)
    {
        return s[0] == c ? 0 : 1;
    }

    long countC1, countC2;
    countC1 = countC2 = 0;
    for (long i = 0; i < n / 2; ++i)
    {
        if (s[i] == c)
            ++countC1;
    }
    for (long i = n / 2; i < n; ++i)
    {
        if (s[i] == c)
            ++countC2;
    }
    string s1, s2;
    s1 = s.substr(n / 2, n / 2);
    s2 = s.substr(0, n / 2);
    long n1 = ((n / 2 - countC1) + recursive(s1, n / 2, c + 1));
    long n2 = ((n / 2 - countC2) + recursive(s2, n / 2, c + 1));
    return min(n1, n2);
} //end refresh

void compute()
{
    long n;
    string s;
    cin >> n;
    cin >> s;
    cout << recursive(s, n, 'a') << "\n";
} //end compute

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
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*