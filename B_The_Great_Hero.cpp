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
    long long A, B, n;
    cin >> A >> B >> n;
    vector<pair<long long, long long>> v(n);
    for (auto &x : v)
        cin >> x.first;
    for (auto &y : v)
        cin >> y.second;

    sort(v.begin(), v.end());

    for (auto &x : v)
    {
        if (B > 0 && x.second > 0)
        {
            long long t, u;
            t = (B / x.first) + (B % x.first != 0);
            u = (x.second / A) + (x.second % A != 0);
            B -= x.first * min(t, u);
            x.second -= A * min(t, u);
        }
        if (x.second <= 0)
        {
            continue;
        }
        if (B <= 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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