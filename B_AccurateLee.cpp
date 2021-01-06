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
    int n, index;
    string s;
    bool x = false;
    cin >> n >> s;

    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == '1' && s[i + 1] == '0')
        {
            x = true;
            while (s[i + 2] == '0')
            {
                s.erase(s.begin() + i + 2);
            }
            while (s[i - 1] == '1')
            {
                s.erase(s.begin() + i - 1);
                --i;
            }
        }
    }
    for (index = 0; index < n; ++index)
    {
        if (s[index] == '1' && s[index + 1] == '0')
            break;
    }
    while (s[index] == '1' && s[index + 1] == '0')
    {
        s.erase(s.begin() + index);
        s.erase(s.begin() + index);
    }
    if (x)
        s.insert(index, 1, '0');
    cout << s << "\n";
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