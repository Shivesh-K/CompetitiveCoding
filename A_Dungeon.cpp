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
    vector<long long> t(3);
    cin >> t[0] >> t[1] >> t[2];
    sort(t.begin(), t.end());
    long long s = (t[2] - t[0]) + (t[1] - t[0]);
    if (s % 3 == 0)
    {
        if (s % 6 == 0)
        {
            if (((t[0] - (s / 6)) >= 0) && ((t[0] - (s / 6)) % 3 == 0))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            if (((t[0] - (s / 6) - 2) >= 0) && ((t[0] - (s / 6) - 2) % 3 == 0))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    else
    {
        cout << "NO\n";
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