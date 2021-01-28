#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int q, d;
    cin >> q >> d;
    vector<int> a(q);
    for (int &x : a)
        cin >> x;

    for (int x : a)
    {
        if (x < d * 10)
        {
            while (x >= d)
            {
                if (x % d == 0)
                {
                    cout << "YES\n";
                    break;
                }
                x -= 10;
            }
            if (x < d)
                cout << "NO\n";
        }
        else
            cout << "YES\n";
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