#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

bool isDigit(string &s)
{
    for (auto &ch : s)
        if (ch >= '0' && ch <= '9')
            return true;
    return false;
}

bool isSpecial(string &s)
{
    for (auto &ch : s)
    {
        if (ch == '*' || ch == '@' || ch == '&' || ch == '#')
            return true;
    }
    return false;
}

bool isUpper(string &s)
{
    for (auto &ch : s)
        if (ch >= 'A' && ch <= 'Z')
            return true;
    return false;
}

bool isLower(string &s)
{
    for (auto &ch : s)
        if (ch >= 'a' && ch <= 'z')
            return true;
    return false;
}

void compute()
{
    int n;
    string s;
    cin >> n >> s;

    if (!isDigit(s))
        s += '1';
    if (!isLower(s))
        s += 'a';
    if (!isUpper(s))
        s += 'A';
    if (!isSpecial(s))
        s += '@';
    s += string(max(s.length(), 7) - s.length(), '1');
    cout << s << "\n";
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