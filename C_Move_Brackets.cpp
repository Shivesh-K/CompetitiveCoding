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
    int n, a1, a2, l, x;
    string s, s1, s2;
    char c;
    cin >> n >> s;

    s1.assign(s);
    s2.assign(s);

    x = 0;
    a1 = 0;
    for (int i = 0; i < n; ++i)
    {
        s1[i] == '(' ? ++x : --x;
        if (x < 0)
        {
            s1.erase(s1.begin() + i);
            s1.push_back(')');
            ++x;
            ++a1;
            --i;
        }
    }

    x = 0;
    a2 = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        s2[i] == '(' ? ++x : --x;
        if (x > 0)
        {
            s2.erase(s2.begin() + i);
            s2.push_back('(');
            --x;
            ++a2;
        }
    }
    cout << min(a1, a2) << "\n";
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