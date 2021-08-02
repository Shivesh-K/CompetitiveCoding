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
    string s;
    cin >> s;
    int g1, g2, q1, q2;
    bool b = true;
    g1 = g2 = q1 = q2 = 0;

    for (int i = 0; i < 10; ++i)
    {
        if (b)
        {
            if (s[i] == '?')
                ++q1;
            else if (s[i] == '1')
                ++g1;
        }
        else
        {
            if (s[i] == '?')
                ++q2;
            else if (s[i] == '1')
                ++g2;
        }

        if ((g1 + q1 > g2 + (10 - i) / 2) || (g2 + q2 > g1 + (10 - i - 1) / 2))
        {
            cout << (i + 1) << "\n";
            return;
        }

        b = !b;
    }
    cout << "10\n";
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