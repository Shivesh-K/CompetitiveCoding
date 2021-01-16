#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

string srs(string str)
{
    int letters[26] = {0}, min = 10000, len = 0;
    int lent = str.size();
    len = lent;
    for (int i = 1; i <= lent; i++)
    {
        string temp = "";
        string ans = "";
        if (lent % i == 0)
        {
            for (int j = 0; j < i; j++)
                ans += str[j];
            for (int j = 0; j < (lent / i); j++)
                temp += ans;
            if (str == temp)
            {
                return ans;
            }
        }
    }
    return str;
}

void compute()
{
    int i;
    string s, t;
    cin >> s >> t;
    string srs1 = srs(s);
    string srs2 = srs(t);

    if (srs1 == srs2)
    {
        int l = lcm(s.length(), t.length()) / srs1.length();
        while (l--)
            cout << srs1;
        cout << "\n";
    }
    else
    {
        cout << "-1\n";
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