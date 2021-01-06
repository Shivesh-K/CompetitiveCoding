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
    long long int n, k, temp, c, ans = 0;
    cin >> n >> k;
    vector<long long int> a;
    vector<long long int> w;
    vector<pair<long long int, long long int>> p;

    for (long long int i = 0; i < n; ++i)
    {
        cin >> temp;
        a.push_back(temp);
    }
    for (long long int i = 0; i < k; ++i)
    {
        cin >> temp;
        w.push_back(temp);
    }
    sort(a.begin(), a.end(), greater<long long int>());
    sort(w.begin(), w.end());
    c = n;

    for (long long int i = 0; i < k; ++i)
    {
        p.push_back(make_pair(a[i], (long long int)0));
    }
    for (long long int i = k - 1; i >= 0; --i)
    {
        if (w[i] > 1)
        {
            p[i].second = a[c - 1];
            c -= w[i] - 1;
        }
        else
        {
            p[i].second = p[i].first;
        }
        ans += p[i].first + p[i].second;
    }
    cout << ans << "\n";
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