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
    int n, q, l, r;
    string s;
    cin >> n >> q >> s;
    bool f;
    while (q--)
    {
        cin >> l >> r;
        l--;
        r--;
        f = false;
        for (int i = 0; i < l; ++i)
        {
            if (s[i] == s[l])
            {
                f = true;
                break;
            }
        }
        if (!f)
        {
            for (int j = r + 1; j < n; ++j)
            {
                if (s[j] == s[r])
                {
                    f = true;
                    break;
                }
            }
        }
        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
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