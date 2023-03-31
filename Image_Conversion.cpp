#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

ll solve(int n, vector<int> &A, vector<int> &B, int k)
{
    vector<int> idx(n + 1);
    for (int i = 0; i < n; ++i)
        idx[A[i]] = i;

    int r = 0;
    for (int i = n - 1; i > 0; --i)
    {
        int t = idx[B[i]];
        t = (t - r) % (i + 1);
        r += (t + 1) % (i + 1);
    }

    return 1LL * k * r;
}

ll minimumCost(int n, vector<int> A, vector<int> B, vector<int> C, int k1, int k2)
{
    ll ans = 0;
    ans += solve(n, A, B, k1);

    reverse(B.begin(), B.end());
    reverse(C.begin(), C.end());
    ans += solve(n, B, C, k2);

    return ans;
}

void compute()
{
    int n;
    cin >> n;

    vector<int> A(n), B(n), C(n);
    int k1, k2;

    for (int &t : A)
        cin >> t;
    for (int &t : B)
        cin >> t;
    for (int &t : C)
        cin >> t;
    cin >> k1 >> k2;

    cout << minimumCost(n, A, B, C, k1, k2) << "\n";
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