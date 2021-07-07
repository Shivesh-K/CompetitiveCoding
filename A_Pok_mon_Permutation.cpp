#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    int n;
    string s;
    cin >> s;
    n = s.length();
    vector<int> f(26);
    for (char ch : s)
        f[ch - 'a']++;

    int result = f[0];
    for (int i = 1; i < 26; i++)
    {
        result = gcd(f[i], result);

        if (result == 1)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    string ans;
    s = "";
    int i = 0;
    for (int &t : f)
    {
        t /= result;
        s += string(t, char(i + 'a'));
        ++i;
    }
    while (ans.length() < n)
        ans += s;
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