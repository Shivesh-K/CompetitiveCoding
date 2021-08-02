#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define ll long long

void solve()
{
    ll N, K, S, ans = 0, T, logarithm = 0, PO;
    cin >> N >> K >> S;

    for (T = K; T > 0; T = T / 2)
    {
        logarithm++;
    }

    vector<ll> vec(N + 1);
    vector<vector<ll>> up(N + 1, vector<ll>(logarithm + 1));
    for (int i = 1; i <= N; ++i)
    {
        cin >> vec[i];
        vec[i] += vec[i - 1];
        auto iter = lower_bound(vec.begin(), vec.begin() + i, vec[i] - S);
        if (iter != vec.end())
        {
            int index = iter - vec.begin();
            up[i][0] = index;
            for (int j = 1; j <= logarithm; ++j)
                up[i][j] = up[up[i][j - 1]][j - 1];

            index = i, PO = 0;
            for (T = K; T > 0; T /= 2)
            {
                if (T & 1)
                    index = up[index][PO];
                ++PO;
            }
            ans = max(ans, i - index);
        }
        else
        {
            for (int j = 0; j <= logarithm; ++j)
            {
                up[i][j] = i;
            }
        }
    }

    cout << ans << endl;
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
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}