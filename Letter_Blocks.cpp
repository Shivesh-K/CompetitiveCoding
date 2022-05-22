#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<int> seq;
vector<string> v;
string sol;

void permute(int idx)
{
    if (idx >= seq.size())
    {
        string ans;
        for (int t : seq)
            ans += v[t];

        vector<bool> vis(26);
        int n = ans.size();

        for (int i = 0; i < n; ++i)
        {
            if (vis[ans[i] - 'A'])
                return;
            int j = i;
            while (j + 1 < n && ans[j + 1] == ans[i])
                ++j;
            i = j;
            vis[ans[i] - 'A'] = true;
        }

        sol = ans;
        return;
    }

    for (int i = idx; i < seq.size(); ++i)
    {
        swap(seq[i], seq[idx]);
        permute(idx + 1);
        swap(seq[i], seq[idx]);
        if (sol.size())
            return;
    }
}

void compute()
{
    int n;
    cin >> n;
    v = vector<string>(n);
    sol.clear();

    for (auto &t : v)
        cin >> t;

    seq = vector<int>(n);
    for (int i = 0; i < n; ++i)
        seq[i] = i;

    permute(0);
    if (sol.empty())
        sol = "IMPOSSIBLE";

    cout << sol << "\n";
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