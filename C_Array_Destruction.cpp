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
    int x, nt, m, n;
    cin >> nt;
    nt = nt << 1;
    vector<int> a(nt);
    vector<pair<int, int>> ans;
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    m = 0;
    n = -1;
    while (m < nt)
    {
        if (a[m] > 0)
        {
            x = a[m];
            int t1 = m + 1, t2 = nt - 1;
            if (ans.size() <= (nt / 2 - 1))
            {
                while (a[t1] == 0 || t1 == n)
                    ++t1;
                if (t1 >= nt)
                {
                    ans.push_back({a[m], a[n]});
                    a[m] = 0;
                    a[n] = 0;
                    break;
                }

                while (t1 < t2)
                {
                    if (a[t2] == 0 || t2 == n)
                        --t2;
                    else
                    {
                        int q = a[t1] + a[t2];
                        if (q > x)
                        {
                            cout << "NO\n";
                            return;
                        }
                        else if (q < x)
                            --t2;
                        else
                            break;
                    }
                }
                if (t1 >= t2)
                {
                    cout << "NO\n";
                    return;
                }
            }
            else
            {
                t1 = t2 = nt + 1;
            }
            int j;
            if (n < 0)
            {
                for (j = t1 + 1; j < nt; ++j)
                {
                    if (a[j] && j != t2)
                    {
                        break;
                    }
                }
                if (j >= nt)
                {
                    cout << "NO\n";
                    return;
                }
                n = j;
            }
            ans.push_back({a[n], a[m]});
            a[m] = 0;
            a[n] = 0;
            m = t1;
            n = t2;
        }
    }
    int sum = ans[0].first + ans[0].second;
    cout << "YES\n";
    cout << sum << "\n";
    for (auto z : ans)
        cout << z.first << " " << z.second << "\n";
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