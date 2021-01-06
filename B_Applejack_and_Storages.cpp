#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void swaps(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void compute()
{
    int n, x, q, temp = 0;
    char s;
    bool ans1, ans2;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    map<int, int> re;

    ans1 = ans2 = false;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        m[a[i]]++;
        if (m[a[i]] >= 2)
        {
            re[a[i]]++;
            m[a[i]] -= 2;
            if (!ans1 && re[a[i]] >= 2)
            {
                re[a[i]] -= 2;
                ans1 = true;
            }
            temp += re[a[i]];
        }
    }

    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> s >> x;
        ans1 = ans2 = false;

        if (s == '+')
        {
            m[x]++;
            if (m[x] >= 2)
            {
                re[x]++;
                m[x] -= 2;
            }
        }
        else
        {
            m[x]--;
            if (m[x] < 0)
            {
                re[x]--;
                m[x] += 2;
                if (re[x] < 0)
                {
                    re[x] += 2;
                    ans1 = false;
                }
            }
        }

        map<int, int> t = re;
        int temp = 0;
        for (auto &i : t)
        {
            if (!ans1 && i.second >= 2)
            {
                ans1 = true;
                i.second -= 2;
            }
            temp += i.second;
        }
        if (temp >= 2)
            ans2 = true;

        if (ans1 && ans2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
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