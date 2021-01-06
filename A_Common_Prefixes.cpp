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

void preprocess()
{
} //end prepreprocess

void refresh()
{
} //end refresh

void compute()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<string> s(n + 1);
    char ch;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    ch = 'a';
    s[0] += 'a';
    for (int i = 0; i < n; ++i)
    {

        for (int j = 0; j < min(s[i].length(), a[i]); ++j)
        {
            s[i + 1] += s[i][j];
        }
        for (int j = s[i].length(); j < a[i]; ++j)
        {
            s[i] += ch;
            s[i + 1] += ch;
        }

        ++ch;
        if (ch > 'z')
        {
            ch = 'a';
        }

        if (s[i + 1].length() == 0)
        {
            s[i + 1] += ((s[i][a[i]] + 1) > 'z' ? 'a' : 'z');
        }
    }

    for (int i = 0; i < n + 1; ++i)
    {
        cout << s[i] << "\n";
    }
} //end compute

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i, j;
    preprocess();
    scanf("%d", &t);
    while (t--)
    {
        compute();
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*