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
    int n;
    cin >> n;
    vector<int> v(n);
    bool b1 = true;

    for (int &t : v)
        cin >> t;

    for (int i = 0; i < n; ++i)
    {
        if (v[i] != i + 1)
        {
            b1 = false;
            break;
        }
    }

    if (b1)
        cout << "0\n";
    else
    {
        if (v[0] == 1 || v[n - 1] == n)
            cout << "1\n";
        else
        {
            if (v[0] == n && v[n - 1] == 1)
                cout << "3\n";
            else
                cout << "2\n";
        }
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