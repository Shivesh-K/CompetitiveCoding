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
    int n, m, x = 0, l, r;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<pair<int, int>> t(n + 2, {0, 0});
    vector<int> v(n + 2, 0);
    t[0] = {0, 0};
    v[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        s[i] == '+' ? x++ : x--;
        v[i] = x;
        pair<int, int> p;
        p.first = x > t[i - 1].first ? x : t[i - 1].first;
        p.second = x < t[i - 1].second ? x : t[i - 1].second;
        t[i] = p;
    }
    t[n + 1] = t[n];
    v[n + 1] = v[n];

    for (int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        int d;
        if (r >= n)
        {
            d = v[r + 1] - v[l - 1];
        }
        else
        {
            d = v[r + 1] - v[l - 1] + (s[r + 1] == '+' ? -1 : 1);
        }
        int nt = min(t[l - 1].first, t[n + 1].first - d);
        int nb = max(t[l - 1].second, t[n + 1].second - d);
        cout << nt - nb + 1 << "\n";
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