#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void f(vector<int> &v, int idx)
{
    if (v[idx] > v[idx + 1])
        iter_swap(v.begin() + idx, v.begin() + idx + 1);
}

void compute()
{
    int n, ans;
    cin >> n;
    vector<int> v(n), u;
    for (int &t : v)
        cin >> t;
    u = v;
    sort(u.begin(), u.end());

    if (v == u)
    {
        cout << "0\n";
        return;
    }

    for (ans = 1; ans <= n; ++ans)
    {
        if (ans & 1)
            for (int j = 0; j < n - 2; j += 2)
                f(v, j);
        else
            for (int j = 1; j < n - 1; j += 2)
                f(v, j);

        if (v == u)
            break;
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