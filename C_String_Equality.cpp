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
    int n, k;
    string a, b;
    cin >> n >> k >> a >> b;
    map<char, int> fa, fb, x;
    for (char c : a)
        fa[c]++;
    for (char c : b)
        fb[c]++;

    bool f = true;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (fa[c] != fb[c])
        {
            f = false;
        }
        if (fa[c] > fb[c])
        {
            x[c] += fa[c] - fb[c];
            fa[c] = fb[c];
        }
    }
    if (f)
    {
        cout << "Yes\n";
        return;
    }

    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (fa[c] != fb[c])
        {
            if ((fb[c] - fa[c]) % k == 0)
            {
                int di = fb[c] - fa[c];
                for (char m = 'a'; m < c; ++m)
                {
                    while (di > 0 && x[m] >= k)
                    {
                        x[m] -= k;
                        di -= k;
                    }
                }
                if (di > 0)
                {
                    cout << "No\n";
                    return;
                }
            }
            else
            {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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