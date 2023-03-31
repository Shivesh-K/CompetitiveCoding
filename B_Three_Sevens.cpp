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
    int m;
    cin >> m;

    vector<vector<int>> v(m);
    vector<int> cnt(50005);
    for (int i = 0; i < m; ++i)
    {
        vector<int> se;
        int n;
        cin >> n;
        while (n--)
        {
            int t;
            cin >> t;
            se.push_back(t);
            cnt[t]++;
        }
        v[i] = se;
    }

    vector<int> winners(m, -1);
    for (int i = 0; i < m; ++i)
    {
        for (int t : v[i])
        {
            if (cnt[t] <= 1)
            {
                winners[i] = t;
                break;
            }
        }
        for (int t : v[i])
            cnt[t]--;

        if (winners[i] == -1)
        {
            cout << "-1\n";
            return;
        }
    }
    for (int t : winners)
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