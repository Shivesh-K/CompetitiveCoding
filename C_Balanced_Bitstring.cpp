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
    long long n, k;
    string s, t;
    bool flag = true;
    char x, y;
    cin >> n >> k >> s;

    if (k == 2)
    {
        long long i = 0;
        while (s[i] == '?')
            ++i;
        if (((i & 1) == 0) && s[i] == '0')
        {
            x = '0';
            y = '1';
        }
        else if (((i & 1) == 0) && s[i] == '1')
        {
            x = '1';
            y = '0';
        }
        else if ((i & 1) && s[i] == '0')
        {
            x = '1';
            y = '0';
        }
        else if ((i & 1) && s[i] == '1')
        {
            x = '0';
            y = '1';
        }
        cout << x << " " << y;
        for (long long i = 0; i < n; i += 2)
        {
            if (((s[i] != x) && (s[i] != '?')) || ((i < n - 1) && ((s[i + 1] != y) && (s[i + 1] != '?'))))
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
        {
            cout << "NO\n";
        }
        return;
    }

    for (long long i = 0; i < n; i += 2)
    {

        if (i == n - 1 && s[i] != s[0])
        {
            flag = false;
            break;
        }
        if (!(((s[i] == '0' || s[i] == '?') && (s[i + 1] == '1' || s[i + 1] == '?')) ||
              ((s[i] == '1' || s[i] == '?') && (s[i + 1] == '0' || s[i + 1] == '?'))))
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES\n";
    else
    {
        cout << "NO\n";
    }
    return;
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