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
    int n, k, ans = 0, last = -1, i;
    string s;
    cin >> n >> k >> s;
    vector<int> v(n);
    for (i = 0; i < n; ++i)
    {
        if (s[i] == '*')
            last = i;
        v[i] = last;
    }

    for (i = 0; i < n && v[i] == -1; ++i)
        ;
    ans = 1;
    s[i] = 'x';
    do
    {
        last = i;
        i += k;
        if (i >= n)
            break;
        i = v[i];
        if (last == i)
            break;
        s[i] = 'x';
        ans++;
    } while (true);

    for (i = n - 1; i >= 0; --i)
    {
        if (s[i] == 'x')
            break;
        if (s[i] == '*')
        {
            ++ans;
            break;
        }
    }
    cout << ans << "\n";
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