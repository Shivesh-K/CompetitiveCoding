#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void findQ(string s, int &i, int &j)
{
    int l = j + 1, r, n = s.length();
    if (l >= n)
    {
        i = j = l;
        return;
    }
    while (l < n && s[l] != '?')
        ++l;
    i = j = l;
    if (l >= n)
        return;
    while (j + 1 < n && s[j + 1] == '?')
        ++j;
}

int calcCost(string s, int x, int y)
{
    int ans = 0, l = s.length();
    for (int i = 0; i < l - 1; ++i)
    {
        ans += (s[i] == 'C' && s[i + 1] == 'J') * x + (s[i] == 'J' && s[i + 1] == 'C') * y;
    }
    return ans;
}

void compute()
{
    int x, y, n, i, j, ans = 0;
    string s;
    char ch;
    cin >> x >> y >> s;
    n = s.length();
    i = j = -1;

    bool b = (x < y);

    findQ(s, i, j);
    while (i < n)
    {
        // cout << i << " " << j << " ";
        if (i == 0 && j == n - 1)
        {
            cout << "0\n";
            return;
        }
        else if (i <= 0)
            ch = s[j + 1];
        else if (j >= n - 1)
            ch = s[i - 1];
        else if (s[i - 1] == s[j + 1])
            ch = s[j + 1];
        else
            ch = 'J';
        fill(s.begin() + i, s.begin() + j + 1, ch);
        findQ(s, i, j);
    }
    ans = calcCost(s, x, y);
    cout << ans << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ": ";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}