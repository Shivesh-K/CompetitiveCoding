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
    string s;
    int l, ans;
    pair<int, int> p;
    cin >> s;

    l = s.length();
    if (l == 1 || l == 2)
    {
        cout << "0\n";
        return;
    }

    if (l == 3)
    {
        if (s == "101" || s == "010")
            cout << "1\n";
        else
            cout << "0\n";
        return;
    }

    // c = s[0];
    // for (i = 1; i < l && s[i] == c; ++i)
    // {
    // }
    // for (i = i + 1; i < l; ++i)
    // {
    //     if (s[i] == c)
    //         ans1++;
    // }
    // reverse(s.begin(), s.end());
    // c = s[0];
    // for (i = 1; i < l && s[i] == c; ++i)
    // {
    // }
    // for (i = i + 1; i < l; ++i)
    // {
    //     if (s[i] == c)
    //         ans2++;
    // }
    p.first = p.second = 0;
    for (int i = 0; i < l; ++i)
    {
        s[i] == '0' ? p.first++ : p.second++;
    }
    if (p.first > p.second)
        ans = p.second;
    else
        ans = p.second;

    cout << ans << "\n";

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