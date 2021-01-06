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
string last = "";
long long ans = 0;
void compute()
{
    string s;
    long long cur, res, minus, plus, l, index;
    vector<pair<long long, long long>> x;
    cin >> s;

    plus = minus = 0;
    l = s.length();
    cur = 0;
    for (long long i = 0; i < l; ++i)
    {
        s[i] == '+' ? ++plus : ++minus;
        if (minus > plus)
        {
            x.push_back(make_pair(i, minus - plus));
            cur = min(cur, plus - minus);
        }
    }
    res = 0;
    sort(x.begin(), x.end());
    for (long long i = 0; x[i].second != cur; ++i)
    {
        res += x[i].first + 1;
    }
    res += l;
    cout << res << "\n";
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