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
    string s;
    cin >> s;
    int size = s.length(), c1, c2;

    c1 = c2 = 0;
    for (int i = 0; i < size; ++i)
    {
        if (s[i] == 'a')
            ++c1;
        else
            break;
    }

    if (c1 == size)
    {
        cout << "NO\n";
        return;
    }

    for (int i = size - 1; i >= 0; --i)
    {
        if (s[i] == 'a')
            ++c2;
        else
            break;
    }

    cout << "YES\n";
    if (c1 <= c2)
        cout << s << "a\n";
    else
        cout << 'a' << s << "\n";
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