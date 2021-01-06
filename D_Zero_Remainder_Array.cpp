#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)

long long k;

bool compareInterval(long long i1, long long i2)
{
    return (i1 % k > i2 % k);
}

void compute()
{
    long long n, temp, x;
    vector<long long> a;
    cin >> n >> k;
    for (long long i = 0; i < n; ++i)
    {
        cin >> temp;
        a.push_back(temp);
    }

    x = 0;
    sort(a.begin(), a.end(), compareInterval);
    for (long long i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    for (long long i = 0; i < n; ++i)
    {
        temp = k - a[i] % k;
        if (x == temp)
        {
            x++;
        }
        else
        {
            if (x > temp)
            {
                x += temp + k - x;
            }
            else
            {
                x += temp - x;
            }
        }
    }
    cout << x << "\n";
} //end compute

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i, j;
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