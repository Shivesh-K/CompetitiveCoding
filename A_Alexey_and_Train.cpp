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
    cin >> n;
    vector<int> a(n), b(n), tm(n);
    for (int &x : a)
        cin >> x;
    for (int &y : b)
        cin >> y;
    for (int &z : tm)
        cin >> z;

    int carry = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int t = tm[i] + carry + ceil((a[i] + b[i]) / 2.0);
        if (t > b[i])
        {
            carry += t - b[i];
        }
    }
    cout << (a[n - 1] + tm[n - 1] + carry) << "\n";
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