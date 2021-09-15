#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<int>> valid;
set<int> rem;
int ans, n;

void recur(int x)
{
    if (x > n)
    {
        ++ans;
        return;
    }

    for (int t : valid[x])
    {
        if (rem.count(t))
        {
            rem.erase(t);
            recur(x + 1);
            rem.insert(t);
        }
    }
}

void compute()
{
    ans = 0;
    cin >> n;
    valid = vector<vector<int>>(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        valid[i].push_back(i);
        for (int j = 1; j < i; ++j)
        {
            if (i % j == 0 || j % i == 0)
            {
                valid[i].push_back(j);
                valid[j].push_back(i);
            }
        }
        rem.insert(i);
    }

    recur(1);

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