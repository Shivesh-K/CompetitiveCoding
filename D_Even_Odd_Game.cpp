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
    long long n, sa = 0, sb = 0, lo, le, x;
    cin >> n;
    vector<long long> a(n), odd, even;
    for (long long i = 0; i < n; ++i)
    {
        cin >> x;
        x % 2 == 0 ? even.push_back(x) : odd.push_back(x);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    lo = odd.size();
    le = even.size();

    bool isAlice = true;
    while (lo > 0 && le > 0)
    {
        if (isAlice)
        {
            if (even[le - 1] < odd[lo - 1])
            {
                lo--;
            }
            else
            {
                sa += even[--le];
            }
        }
        else
        {
            if (odd[lo - 1] < even[le - 1])
            {
                le--;
            }
            else
            {
                sb += odd[--lo];
            }
        }
        isAlice = !isAlice;
    }
    while (lo > 0)
    {
        isAlice ? lo-- : sb += odd[--lo];
        isAlice = !isAlice;
    }
    while (le > 0)
    {
        !isAlice ? le-- : sa += even[--le];
        isAlice = !isAlice;
    }

    if (sa == sb)
        cout << "Tie\n";
    else if (sa > sb)
        cout << "Alice\n";
    else
        cout << "Bob\n";
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