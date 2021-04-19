#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

string addOne(string s)
{
    int carry = 1;
    for (int i = s.length() - 1; i >= 0; --i)
    {
        int d = s[i] - '0';
        d += carry;
        s[i] = char(d % 10 + '0');
        carry = d > 9;
    }
    if (carry)
        s.insert(s.begin(), '1');

    return s;
}

// bool compareStr(string s1, string s2) {

// }

void compute()
{
    long long n, ans = 0;
    cin >> n;
    vector<string> x(n);
    for (auto &t : x)
    {
        cin >> t;
    }

    for (long long i = 1; i < n; ++i)
    {
        if ((x[i].length() < x[i - 1].length()) || (x[i].length() == x[i - 1].length() && x[i] <= x[i - 1]))
        {
            long long b = 0;
            for (long long j = 0; j < x[i].length(); ++j)
            {
                if (x[i][j] < x[i - 1][j])
                {
                    b = -1;
                    break;
                }
                else if (x[i][j] > x[i - 1][j])
                {
                    b = 1;
                    break;
                }
            }
            long long d = x[i - 1].length() - x[i].length();
            if (b == 0)
            {
                if (d > 0)
                {
                    string t = x[i - 1].substr(x[i].length());
                    string t1 = addOne(t);

                    ans += d;
                    if (t1.length() > t.length())
                    {
                        ++d;
                        ++ans;
                        while (d--)
                            x[i] += '0';
                    }
                    else
                    {
                        x[i] += t1;
                    }
                }
                else
                {
                    x[i] += '0';
                    ans += 1;
                }
            }
            else if (b == 1)
            {
                ans += d;
                while (d--)
                    x[i] += '0';
            }
            else
            {
                ++d;
                ans += d;
                while (d--)
                    x[i] += '0';
            }
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
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ": ";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}