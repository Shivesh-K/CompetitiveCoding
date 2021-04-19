#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (((a) > (b)) ? (a) : (b))
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
    long long n, ans;
    cin >> n;
    vector<long long> v(n);
    for (long long &t : v)
        cin >> t;

    if (n <= 3)
    {
        cout << n << "\n";
        return;
    }

    ans = 3;
    map<long long, vector<pair<long long, long long>>> m;
    long long curr, last;
    long long start = 0, end = 1;

    last = v[1] - v[0];
    for (long long i = 2; i < n; ++i)
    {
        curr = v[i] - v[i - 1];
        if (curr == last)
            end++;
        else
        {
            m[last].push_back({start, end});
            start = i - 1;
            end = i;
            last = curr;
        }
    }
    m[last].push_back({start, end});
    if (end - start + 1 == n)
    {
        cout << n << "\n";
        return;
    }

    for (auto el : m)
    {
        long long diff = el.first;
        auto ve = el.second;
        for (long long i = 1; i < ve.size(); ++i)
        {
            if ((ve[i].first - ve[i - 1].second == 2) && ((v[ve[i - 1].second] + 2 * diff) == v[ve[i].first]))
            {
                ans = max(ans, ve[i].second - ve[i - 1].first + 1);
            }
        }
        for (auto t : ve)
        {
            if ((t.first > 1) && ((v[t.first] - 2 * diff) == v[t.first - 2]))
                ans = max(ans, t.second - t.first + 3);
            else if ((t.second < n - 2) && ((v[t.second] + 2 * diff) == v[t.second + 2]))
                ans = max(ans, t.second - t.first + 3);
            else if ((t.first > 0) || (t.second < n - 1))
                ans = max(ans, t.second - t.first + 2);
        }
    }
    cout << ans << "\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ": ";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}