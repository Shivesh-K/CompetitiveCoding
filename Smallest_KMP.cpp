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
    string p;
    string ans;
    cin >> s >> p;
    char x = p[0];
    map<char, int> f;
    for (int i = 0; i < s.length(); ++i)
    {
        f[s[i]]++;
    }
    for (int i = 0; i < p.length(); ++i)
    {
        f[p[i]]--;
    }

    for (char i = 'a'; i < x; ++i)
    {
        while (f[i]--)
        {
            ans += i;
        }
    }
    int j = 0;
    for (j = 0; j < p.length() && p[j] == x; ++j)
        ;
    if (j == p.length())
    {
        while (f[x]--)
            ans += x;
        ans += p;
    }
    else
    {
        if (p[j] > x)
        {
            while (f[x]--)
                ans += x;
            ans += p;
        }
        else
        {
            ans += p;
            while (f[x]--)
                ans += x;
        }
    }
    for (char i = x + 1; i <= 'z'; ++i)
    {
        while (f[i]--)
        {
            ans += i;
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