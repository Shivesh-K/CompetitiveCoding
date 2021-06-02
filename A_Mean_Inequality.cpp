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
    vector<int> v(2 * n);
    for (int &t : v)
        cin >> t;
    sort(v.begin(), v.end());

    n <<= 1;
    for (int i = 0; i < n; i += 4)
    {
        if (i + 3 < n)
        {
            iter_swap(v.begin() + i, v.begin() + i + 2);
            iter_swap(v.begin() + i + 1, v.begin() + i + 3);
        }
        else if (i + 1 < n)
        {
            iter_swap(v.begin() + i, v.begin() + i + 1);
        }
    }

    for (int t : v)
        cout << t << " ";
    cout << "\n";
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