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
    int n, T = 0, M = 0, idx;
    cin >> n;
    string s;
    cin >> s;
    for (char ch : s)
    {
        ch == 'T' ? ++T : ++M;
    }
    if (T != 2 * M || s[0] != 'T' || s[n - 1] != 'T')
    {
        cout << "NO\n";
        return;
    }

    vector<int> suffix(n + 1);

    suffix[n] = n;
    idx = n;
    for (int i = n - 1; i >= 0; --i)
    {
        // if (s[i] == 'M')
        // {
        //     idx = i;
        // }
        // s[i] == 'M' ? suffix[i] = i : suffix[i + 1];
        suffix[i] = (s[i] == 'M' ? i : suffix[i + 1]);
        // s[i] = idx;
    }
    for (int i = 0, f = 0; f < M; ++i)
    {
        if (s[i] == 'T')
        {
            ++f;
            if (suffix[i] >= n)
            {
                cout << "NO\n";
                return;
            }
            else
            {
                suffix[i] = suffix[suffix[i] + 1];
            }
        }
    }

    suffix[n] = n;
    idx = n;
    for (int i = n - 1; i >= 0; --i)
    {
        // if (s[i] == 'M')
        // {
        //     idx = i;
        // }
        // s[i] == 'M' ? suffix[i] = i : suffix[i + 1];
        suffix[i] = (s[i] == 'T' ? i : suffix[i + 1]);
        // s[i] = idx;
    }
    for (int i = 0, f = 0; f < M; ++i)
    {
        if (s[i] == 'M')
        {
            ++f;
            if (suffix[i] >= n)
            {
                cout << "NO\n";
                return;
            }
            else
            {
                suffix[i] = suffix[suffix[i] + 1];
            }
        }
    }

    cout << "YES\n";
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