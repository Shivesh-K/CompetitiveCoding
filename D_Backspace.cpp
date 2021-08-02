#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    int j = 0, i = 0;

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == t[j])
            ++j;
        else
            ++i;
        if (j == m)
            break;
    }
    if (j == m)
        cout << "YES\n";
    else
        cout << "NO\n";
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