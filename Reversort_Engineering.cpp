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
    int n, c;
    cin >> n >> c;

    if ((c < n - 1) || (c >= n * (n + 1) / 2))
    {
        cout << " IMPOSSIBLE\n";
        return;
    }
    c -= n - 1;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        v[i] = i + 1;

    for (int i = 0; i < n - 1; ++i)
    {
        if (c <= 0)
            break;

        if (c <= n - i - 1)
        {
            vector<int> p(n + 1);
            for (int j = 0; j < n; ++j)
                p[v[j]] = j;
            int mi = min(p[i + 1], p[n]);
            reverse(v.begin() + mi, v.begin() + mi + c + 1);
            break;
        }
        else
        {
            vector<int> p(n + 1);
            for (int j = 0; j < n; ++j)
                p[v[j]] = j;
            int mi = min(p[i + 1], p[n]);
            int mx = max(p[i + 1], p[n]);
            reverse(v.begin() + mi, v.begin() + mx + 1);
            c -= n - i - 1;
        }
    }
    for (int t : v)
        cout << " " << t;
    cout << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ":";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}