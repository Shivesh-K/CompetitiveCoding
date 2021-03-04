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
    int n, l, r, i;
    cin >> n;
    l = 1, r = n;

    while (l < r)
    {
        if (r - l == 1)
        {
            cout << "? " << l << " " << r << "\n";
            cout.flush();
            cin >> i;
            if (i == l)
                cout << "! " << r << "\n";
            else
                cout << "! " << l << "\n";
            return;
        }

        int t1 = 0, t2 = 0;
        int m = (l + r) >> 1;

        if (m > l)
        {
            cout << "? " << l << " " << m << "\n";
            cout.flush();
            cin >> t1;
        }

        if (m + 1 < r)
        {
            cout << "? " << m + 1 << " " << r << "\n";
            cout.flush();
            cin >> t2;
        }

        cout << "? " << l << " " << r << "\n";
        cout.flush();
        cin >> i;

        if (i <= m)
        {
            if (t1 && t1 == i)
                r = m;
            else
                l = m + 1;
        }
        else
        {
            if (t2 && t2 == i)
                l = m + 1;
            else
                r = m;
        }
    }
    cout << "! " << l << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t = 1;
    while (t--)
    {
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}