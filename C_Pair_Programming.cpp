#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n), b(m), ans;
    for (int &t : a)
        cin >> t;
    for (int &t : b)
        cin >> t;

    int i = 0, j = 0;
    while (i < n || j < m)
    {
        if (i < n && a[i] <= k)
        {
            ans.push_back(a[i]);
            if (a[i] == 0)
                ++k;
            ++i;
        }
        else if (j < m && b[j] <= k)
        {
            ans.push_back(b[j]);
            if (b[j] == 0)
                ++k;
            ++j;
        }
        else
        {
            cout << "-1\n";
            return;
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