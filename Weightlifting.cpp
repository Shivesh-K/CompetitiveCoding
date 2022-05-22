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
    int e, w;
    cin >> e >> w;
    vector<vector<int>> mat(e, vector<int>(w));
    for (auto &row : mat)
        for (auto &t : row)
            cin >> t;
    mat.push_back(vector<int>(w, 0));

    vector<int> sum(e + 1);
    for (int i = 0; i <= e; ++i)
        sum[i] = accumulate(mat[i].begin(), mat[i].end(), 0);

    ll ans = sum[0];
    for (int i = 1; i <= e; ++i)
    {
        ll cnt = 0;
        for (int j = 0; j < w; ++j)
        {
            if (mat[i - 1][j] == mat[i][j])
            {
                cnt += mat[i][j];
            }
            else
            {
                cnt += min(mat[i - 1][j], mat[i][j]);
                break;
            }
        }
        ans += sum[i - 1] - cnt;
        ans += sum[i] - cnt;
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