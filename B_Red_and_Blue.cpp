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
    int n, m, sum = 0;
    cin >> n;
    vector<int> r(n);
    for (int x : r)
        cin >> x;
    cin >> m;
    vector<int> b(m);
    for (int y : b)
        cin >> y;

    int i = 0, j = 0;
    while (i < r.size() && j < b.size())
    {
        if (r[i] >= 0 || b[j] >= 0)
        {
            if (r[i] >= b[j])
            {
                sum += r[i++];
            }
            else
            {
                sum += b[j++];
            }
        }
        else
        {
            int t1 = sum, t2 = sum;
            int x = i, y = j;
            while (x < r.size())
            {
                t1 += r[x++];
                if (r[x - 1] > 0)
                    break;
            }
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