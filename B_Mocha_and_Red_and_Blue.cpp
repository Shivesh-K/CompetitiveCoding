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
    int n, l, r;
    string s;
    char ch;
    cin >> n >> s;

    l = 0;
    while (l < n && s[l] == '?')
        ++l;

    if (l == n)
    {
        for (int i = 0; i < n / 2; ++i)
            s[2 * i] = 'R', s[2 * i + 1] = 'B';
        if (n & 1)
            s[n - 1] = 'R';
        cout << s << "\n";
        return;
    }

    ch = s[l];
    for (int i = l; i >= 0; --i)
        s[i] = ch, ch = (ch == 'R' ? 'B' : 'R');

    while (l < n)
    {
        r = l + 1;
        while (r < n && s[r] == '?')
            ++r;
        if (r == n)
            break;
        if (r > l + 1)
        {
            ch = s[l];
            for (int i = l; i < r; ++i)
                s[i] = ch, ch = (ch == 'R' ? 'B' : 'R');
        }

        l = r;
    }

    ch = s[l];
    for (int i = l; i < n; ++i)
        s[i] = ch, ch = (ch == 'R' ? 'B' : 'R');

    cout << s << "\n";
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