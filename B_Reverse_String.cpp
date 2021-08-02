#include <bits/stdc++.h>
using namespace std;

void compute()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();

    for (int idx = 0; idx < n; ++idx)
    {
        if (s[idx] != t[0])
            continue;

        for (int a = idx, b = 0; a < n && b < m && s[a] == t[b]; ++a, ++b)
        {

            if (a - m + b + 1 >= 0)
            {
                string p = s.substr(a - m + b + 1, m - b - 1);
                reverse(begin(p), end(p));
                string q = t.substr(b + 1);
                if (p == q)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        compute();
    }
}