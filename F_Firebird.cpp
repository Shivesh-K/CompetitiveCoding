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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (int &t : v)
        cin >> t;

    for (int i = n - 1; i >= 0; --i)
    {
        if (v[i] == -1)
            continue;

        int j = i - 1, age = v[i] - 1;
        while (j >= 0 && age >= 0)
            v[j--] = age--;
        i = j + 1;
    }

    for (int i = 0; i < n; ++i)
    {
        if (v[i] == -1)
            continue;

        int j = i + 1, age = v[i] + 1;
        while (j < n && age < k)
            v[j++] = age++;
        i = j - 1;
    }

    int cnt = 0, ans = 0;
    v.push_back(k - 1);
    for (int i = 0; i <= n; ++i)
    {
        if (v[i] == -1)
            ++cnt;
        else
        {
            ans += (i == n ? (cnt + k - 1) / k : cnt / k);
            cnt = 0;
            if (v[i] == 0)
                ++ans;
        }
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
    compute();
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}