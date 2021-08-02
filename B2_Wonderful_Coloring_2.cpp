#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

bool comp(vector<int> &v1, vector<int> &v2)
{
    return v1.size() > v2.size();
}

void compute()
{
    int n, k, t;
    cin >> n >> k;
    vector<int> ans(n), pre;
    unordered_map<int, vector<int>> mp;
    unordered_map<int, set<int>> colors;

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        mp[t].push_back(i);
    }

    vector<vector<int>> pos;
    for (auto el : mp)
        pos.push_back(el.second);

    sort(pos.begin(), pos.end(), comp);
    int sz = pos.size(), j = 0, i = 0, c = 0;

    pre = vector<int>(sz);
    for (int i = sz - 2; i >= 0; --i)
        pre[i] = pre[i + 1] + pos[i + 1].size();

    i = 0, j = 0, c = 0;
    while (i < sz)
    {
        if (c == 0 && k - j + pre[i] < k)
            break;
        ans[pos[i][j]] = c + 1;
        c = (c + 1) % k;
        ++j;
        if (j == pos[i].size() || j == k)
            ++i, j = 0;
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