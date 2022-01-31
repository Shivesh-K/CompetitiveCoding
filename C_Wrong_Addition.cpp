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
    string a, b, s;
    cin >> a >> s;

    reverse(a.begin(), a.end());
    reverse(s.begin(), s.end());

    int i = 0, j = 0;

    while (i < a.length())
    {
        if (j >= s.length())
        {
            cout << "-1\n";
            return;
        }

        int d = (s[j] - a[i] + 10) % 10;
        if (((a[i] - '0' + d) / 10 > 0))
        {
            if (((j + 1 >= s.length()) || (s[j + 1] - '0' != (a[i] - '0' + d) / 10)))
            {
                cout << "-1\n";
                return;
            }
            else
                ++j;
        }

        b += d + '0';
        ++i, ++j;
    }

    b += s.substr(j);
    while (b.back() == '0')
        b.pop_back();
    reverse(b.begin(), b.end());

    cout << b << "\n";
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