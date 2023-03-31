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
    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "-1\n";
        return;
    }

    vector<int> ans;
    while (n > 1)
    {
        if (((n + 1) / 2) % 2 == 0)
        {
            n = (n - 1) / 2;
            ans.push_back(2);
        }
        else
        {
            n = (n + 1) / 2;
            ans.push_back(1);
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int t : ans)
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