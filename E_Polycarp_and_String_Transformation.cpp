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
    string s;
    cin >> s;
    vector<int> last(26, -1);

    for (int i = 0; i < s.size(); ++i)
        last[s[i] - 'a'] = i;

    vector<pair<int, char>> v;
    for (char ch = 'a'; ch <= 'z'; ++ch)
        if (last[ch - 'a'] >= 0)
            v.push_back({last[ch - 'a'], ch});
    sort(v.begin(), v.end());

    vector<char> rem;
    for (int i = 0; i < v.size(); ++i)
        rem.push_back(v[i].second);

    vector<int> freq(26);
    for (int i = 0; i < s.size(); ++i)
        freq[s[i] - 'a']++;

    int len = 0, cnt = rem.size(), t, idx = s.size(), i, j;
    string s1, s2;

    while (cnt)
    {
        if (freq[rem[cnt - 1] - 'a'] % cnt)
        {
            cout << "-1\n";
            return;
        }
        t = freq[rem[cnt - 1] - 'a'] / cnt;
        len += t;

        i = 0, j = 0;
        s2 = s.substr(idx - len, len);
        while (i < s1.length() && j < s2.length())
        {
            if (s1[i] == s2[j])
                ++i;
            ++j;
        }

        if (i < s1.length())
        {
            cout << "-1\n";
            return;
        }

        s1 = s2;
        idx -= len;
        cnt--;
    }

    cout << s1 << " ";
    for (char c : rem)
        cout << c;
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