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
    long long n, m, ans = 0;
    cin >> n >> m;
    vector<long long> a(n);
    map<long long, long long> ma;
    for (auto &x : a)
    {
        cin >> x;
        ma[(x % m)]++;
    }
    for (auto &t : ma)
    {
        if (t.second > 0)
        {
            if (t.first == (m - t.first) % m)
            {
                ++ans;
                t.second = 0;
            }
            else
            {
                long long x = (ma.find(m - t.first) == ma.end()) ? 0 : ma[m - t.first];
                ans += 1 + abs(x - t.second);
                if (min(x, t.second) == 0 || abs(x - t.second) >= 1)
                {
                    --ans;
                }
                if (x > 0)
                    ma[m - t.first] = 0;
                t.second = 0;
            }
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