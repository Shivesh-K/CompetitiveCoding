#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void swaps(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void compute()
{
    int n;
    string s, a, b;
    cin >> n >> s;

    int zeroes = 0, ones = 0;
    for (char c : s)
        (c == '0') ? ++zeroes : ++ones;

    if (s[0] != '1' || s[n - 1] != '1' || (zeroes & 1))
    {
        cout << "NO\n";
        return;
    }

    int i = 0;
    bool t = true;
    for (char c : s)
    {
        if (c == '1')
        {
            ++i;
            if (i <= ones / 2)
            {
                a += '(';
                b += '(';
            }
            else
            {
                a += ')';
                b += ')';
            }
        }
        else
        {
            if (t)
            {
                a += '(';
                b += ')';
            }
            else
            {
                a += ')';
                b += '(';
            }
            t = !t;
        }
    }
    cout << "YES\n"
         << a << "\n"
         << b << "\n";
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