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
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int &t : a)
        cin >> t;
    for (int &t : b)
        cin >> t;

    int d = 0;
    for (int i = 0; i < n; ++i)
        d += a[i] - b[i];

    if (d)
    {
        cout << "-1\n";
        return;
    }

    int i = 0, j = 0;
    vector<pair<int, int>> ans;
    while (i < n && j < n)
    {
        if (a[i] <= b[i])
            ++i;
        else if (a[j] >= b[j])
            ++j;
        else
        {
            ans.push_back({i + 1, j + 1});
            a[i]--;
            a[j]++;
        }
    }

    cout << ans.size() << "\n";
    for (auto el : ans)
        cout << el.first << " " << el.second << "\n";
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