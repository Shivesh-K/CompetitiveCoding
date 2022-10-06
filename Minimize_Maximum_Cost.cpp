#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;
int solve(vector<int> a, int n, int mid)
{
    int cnt = 1, j = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] * j <= mid)
        {
            sum += a[i] * j;
            j++;
        }
        else
        {
            cnt++;
            j = 2;
            sum = a[i];
        }
    }

    return cnt;
}
void compute()
{
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    cin >> k;
    int l = *max_element(a.begin(), a.end()), r = 0;
    for (int i = 1; i <= n; i++)
    {
        r += a[i - 1] * i;
    }
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (solve(a, n, mid) > k)
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans;
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