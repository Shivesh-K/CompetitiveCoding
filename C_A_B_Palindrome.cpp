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
    int a, b, n, ones = 0, zeroes = 0;
    cin >> a >> b;
    string s;
    cin >> s;
    n = s.length();

    for (int i = 0; i < n / 2; ++i)
    {
        if (s[i] == s[n - i - 1])
        {
            if (s[i] == '1')
                b -= 2;
            else if (s[i] == '0')
                a -= 2;
        }
        else
        {
            if (s[i] == '?' || s[n - i - 1] == '?')
            {
                if (s[i] == '1' || s[n - i - 1] == '1')
                {
                    b -= 2;
                    s[i] = s[n - i - 1] = '1';
                }
                else
                {
                    a -= 2;
                    s[i] = s[n - i - 1] = '0';
                }
            }
            else
            {
                cout << "-1\n";
                return;
            }
        }
    }

    for (int i = 0; i < n / 2; ++i)
    {
        if (s[i] == '?')
        {
            if (a >= 2)
            {
                s[i] = s[n - i - 1] = '0';
                a -= 2;
            }
            else if (b >= 2)
            {
                s[i] = s[n - i - 1] = '1';
                b -= 2;
            }
            else
            {
                cout << "-1\n";
                return;
            }
        }
    }

    if (n % 2 == 1)
    {
        if (s[n / 2] == '1')
        {
            --b;
        }
        else if (s[n / 2] == '0')
        {
            --a;
        }
        else
        {
            if (a > 0)
            {
                s[n / 2] = '0';
                a -= 1;
            }
            else if (b > 0)
            {
                s[n / 2] = '1';
                b -= 1;
            }
            else
            {
                cout << "-1\n";
                return;
            }
        }
    }

    if (a == 0 && b == 0)
    {
        cout << s << "\n";
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