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
    string s;
    cin >> n >> s;

    if (s.front() == '0' || s.back() == '0' || s[1] == '0')
    {
        cout << "No\n";
        return;
    }

    vector<int> ans;
    unordered_set<int> se;
    int left = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == '0')
        {
            ans.push_back(i);
            se.insert(i);
        }
        else
        {
            for (int j = left; j < i; ++j)
            {
                if (se.count(j) == 0)
                    ans.push_back(j);
                se.insert(j);
            }
            left = i;
        }
    }

    cout << "Yes\n";
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