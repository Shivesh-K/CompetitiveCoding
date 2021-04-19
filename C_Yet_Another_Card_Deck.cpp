#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second < b.second;
}

void sort(map<string, int> &M)
{
    vector<pair<string, int>> A;
    for (auto &it : M)
    {
        A.push_back(it);
    }
    sort(A.begin(), A.end(), cmp);
    for (auto &it : A)
    {

        cout << it.first << ' '
             << it.second << endl;
    }
}

void compute()
{
    int n, q, i, t;
    cin >> n >> q;
    map<int, int> m;
    for (i = 1; i <= n; ++i)
    {
        cin >> t;
        if (!m[t])
        {
            m[t] = i;
        }
    }

    while (q--)
    {
        cin >> t;
        int idx = m[t];
        for (auto &e : m)
        {
            if (e.second < idx)
                e.second++;
            else if (e.first == t)
            {
                cout << e.second << " ";
                e.second = 1;
            }
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