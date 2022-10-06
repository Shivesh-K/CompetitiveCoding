#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<int> a, b, bIdx;

bool cmp(int i1, int i2)
{
    return b[i1] < b[i2];
}

void compute()
{
    int n, m, k;
    cin >> n >> m >> k;

    a = vector<int>(n);
    b = bIdx = vector<int>(m);
    for (int &t : a)
        cin >> t;
    for (int &t : b)
        cin >> t;

    for (int i = 0; i < m; ++i)
        bIdx[i] = i;

    sort(a.begin(), a.end());
    sort(bIdx.begin(), bIdx.end(), cmp);

    map<int, int> f;
    for (int i = n - 1; i >= 0; --i)
        f[a[i]]++;

    for (auto &el : f)
    {
        if (el.second > k)
        {
            f[el.first - 1] += el.second - k;
            el.second = k;
        }
    }

    if (f[-1] > 0)
    {
        cout << "-1\n";
        return;
    }

    int market = 0;
    vector<int> ans;
    for (int day = 0; market < m;)
    {
        while (market < m && b[bIdx[market]] < day)
            ++market;
        if (market >= m)
            break;
        if (f[day] < k)
        {
            ++f[day];
            ans.push_back(bIdx[market] + 1);
            ++market;
        }

        if (f[day] == k)
            ++day;
    }

    cout << ans.size() << "\n";
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
    compute();
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}