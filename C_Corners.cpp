#include <bits/stdc++.h>
using namespace std;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int mat[500][500];

void compute()
{
    int n, m, cnt = 0, ans = 0;
    cin >> n >> m;

    vector<string> input(n);
    for (auto &t : input)
        cin >> t;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cnt += (mat[i][j] = input[i][j] - '0');

    ans = max(ans, cnt - max(mat[0][0] + mat[1][0] + mat[0][1] + mat[1][1] - 2, 0));
    ans = max(ans, cnt - max(mat[n - 1][m - 1] + mat[n - 1][m - 2] + mat[n - 2][m - 1] + mat[n - 2][m - 2] - 2, 0));
    ans = max(ans, cnt - max(mat[0][m - 1] + mat[0][m - 2] + mat[1][m - 1] + mat[1][m - 2] - 2, 0));
    ans = max(ans, cnt - max(mat[n - 1][0] + mat[n - 2][0] + mat[n - 1][1] + mat[n - 2][1] - 2, 0));

    cout << ans << "\n";
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