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
    int n, ans = 0;
    cin >> n;
    vector<int> v(n), u;
    string s;
    for (int &t : v)
        cin >> t;
    cin >> s;

    u = v;
    sort(u.begin(), u.end());

    if (v == u)
    {
        cout << "0\n";
    }
    else
    {

        int st, en;
        bool n1 = false, n2 = false, s1 = false, s2 = false, b = true;
        for (st = 0; st < n; ++st)
            if (v[st] != u[st])
                break;
        for (en = n - 1; en >= 0; --en)
            if (v[en] != u[en])
                break;

        if (s.substr(st, en - st + 1) == string(en - st + 1, 'N') || s.substr(st, en - st + 1) == string(en - st + 1, 'S'))
            b = false;

        for (int i = st; i >= 0; --i)
            s[i] == 'N' ? n1 = true : s1 = true;
        for (int i = en; i < n; ++i)
            s[i] == 'N' ? n2 = true : s2 = true;

        if ((n1 && s2) || (n2 && s1))
            cout << "1\n";
        else if (b)
            cout << "2\n";
        else
            cout << "-1\n";
    }
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