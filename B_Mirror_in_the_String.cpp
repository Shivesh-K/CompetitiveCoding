#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int optimal(string &s, int idx)
{
    int n = s.length();
    for (int i = 0; i <= idx; ++i)
    {
        int l = idx - i, r = ((idx + i + 1 < n) ? (idx + i + 1) : (n - ((idx + i - 1) - (n - 1))));
        if (s[l] < s[r])
            return l;
        else if (s[r] < s[l])
            return r;
    }

    return -1;
}

void compute()
{
    int n, l = 0;
    string s;
    cin >> n >> s;

    if (n > 1 && s[1] != s[0])
    {
        for (int i = 0; i < n - 1; ++i)
            if (s[i + 1] <= s[i])
                l = i + 1;
            else
                break;
    }

    s = s.substr(0, l + 1);
    s += string(s.rbegin(), s.rend());

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