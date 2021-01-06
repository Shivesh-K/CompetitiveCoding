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

void preprocess()
{
} //end prepreprocess

void refresh()
{
} //end refresh

void compute()
{
    vector<pair<long long, long long>> r;
    queue<long long> p;
    long long x, n, m, temp, size, j;
    cin >> n >> x >> m;
    for (long long i = 0; i < m; ++i)
    {
        cin >> temp >> j;
        r.push_back(make_pair(temp, j));
    }
    p.push(x - 1);
    for (j = 0; j < m; ++j)
    {
        size = (long long)p.size();
        if (size == n)
        {
            break;
        }
        while (size--)
        {
            temp = p.front();
            p.pop();
            if (temp >= r[j].first - 1 && temp <= r[j].second - 1)
            {
                for (int q = r[j].first - 1; q <= r[j].second - 1; ++q)
                {
                    p.push(q);
                }
            }
            else
            {
                p.push(temp);
            }
        }
    }

    cout << p.size() << "\n";

} //end compute

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i, j;
    preprocess();
    scanf("%d", &t);
    while (t--)
    {
        compute();
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*