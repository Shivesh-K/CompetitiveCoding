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
    int a, b, k, ans = 0, t;
    cin >> a >> b >> k;
    vector<pair<int, int>> p(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> t;
        p[i].first = t;
    }
    for (int j = 0; j < k; ++j)
    {
        cin >> t;
        p[j].second = t;
    }
    sort(p.begin(), p.end());

    for (int i = 0; i < k - 1; ++i)
    {
        for (int j = i + 1; j < k; ++j)
        {
            if (p[i].first != p[j].first && p[i].second != p[j].second)
                ++ans;
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