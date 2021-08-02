#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<int> func(vector<int> &v1, vector<int> &v2, int idx)
{
    int n = v1.size();
    vector<int> ans(n);
    for (int i = 0; i < n; ++i)
        ans[i] = (v1[i] + v2[(i + idx) % n]) % n;
    return ans;
}

void compute()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), ans(n, INT_MAX);

    for (int &t : a)
    {
        cin >> t;
        t %= n;
    }
    for (int &t : b)
    {
        cin >> t;
        t %= n;
    }

    int mn = INT_MAX;
    for (int t : b)
        if ((a[0] + t) % n < mn)
            mn = (a[0] + t) % n;

    for (int i = 0; i < n; ++i)
    {
        if ((b[i] + a[0]) % n == mn)
        {
            auto t = func(a, b, i);
            if (t < ans)
                ans = t;
        }
    }

    for (int t : ans)
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