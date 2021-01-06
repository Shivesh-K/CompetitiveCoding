#include <bits/stdc++.h>
using namespace std;

void compute()
{
    int n, i, j, ta, tb;
    long long ans = 0, mn;
    vector<long long> a, b;
    map<long long, int> fa, fb;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> mn;
        a.push_back(mn);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> mn;
        b.push_back(mn);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    i = j = 0;
    while (i < n && j < n)
    {
        if (a[i] < b[j])
        {
            fa[a[i]]++;
            ++i;
        }
        else if (a[i] > b[j])
        {
            fb[b[j]]++;
            ++j;
        }
        else
        {
            ++i;
            ++j;
        }
    }
    while (i < n)
    {
        fa[a[i]]++;
        ++i;
    }
    while (j < n)
    {
        fb[b[j]]++;
        ++j;
    }

    ta = tb = 0;
    for (i = 0; i < n; ++i)
    {
        if (fa[a[i]] > 0)
        {
            if (fa[a[i]] % 2 == 1)
            {
                cout << "-1\n";
                return;
            }
            else
            {
                fa[a[i]] >>= 1;
                ta += fa[a[i]];
            }
        }
        while (a[i] == a[i + 1])
        {
            ++i;
        }
    }
    for (j = 0; j < n; ++j)
    {
        if (fb[b[j]] > 0)
        {
            if (fb[b[j]] % 2 == 1)
            {
                cout << "-1\n";
                return;
            }
            else
            {
                fb[b[j]] >>= 1;
                tb += fb[b[j]];
            }
        }
        while (b[j] == b[j + 1])
        {
            ++j;
        }
    }
    if (ta != tb)
    {
        cout << "-1\n";
        return;
    }

    i = 0;
    j = n - 1;
    mn = min(a[0], b[0]);
    while (ta)
    {
        while (a[i] == a[i + 1])
        {
            ++i;
        }
        while (b[j] == b[j - 1])
        {
            --j;
        }
        if (fa[a[i]] > 0 && fb[b[j]] > 0)
        {
            ans += min(min(a[i], b[j]), 2 * mn);
            fa[a[i]]--;
            fb[b[j]]--;
            --ta;
        }
        if (fa[a[i]] == 0)
        {
            ++i;
        }
        if (fb[b[j]] == 0)
        {
            --j;
        }
    }

    cout << ans << "\n";
} //end compute

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
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*