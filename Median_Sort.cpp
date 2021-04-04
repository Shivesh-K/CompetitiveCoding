#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int t, n, q;

void insertNew(vector<int> &v, int l, int r, int i)
{
    int ans;

    cout << v[l] << " " << v[r - 1] << " " << i << "\n";
    cout.flush();
    cin >> ans;

    if (ans == v[l])
    {
        v.insert(v.begin() + l, i);
    }
    else if (ans == v[r - 1])
    {
        v.insert(v.begin() + r, i);
    }
    else
    {
        if (r - l == 2)
        {
            v.insert(v.begin() + l + 1, i);
        }
        else if (r - l == 3)
        {
            cout << v[l] << " " << v[l + 1] << " " << i;
            cout.flush();
            cin >> ans;
            if (ans == v[l])
                v.insert(v.begin() + l, i);
            else if (ans == v[l + 1])
                v.insert(v.begin() + l + 2, i);
            else
                v.insert(v.begin(), l + 1, i);
        }
        else
            insertNew(v, l + 1, r - 1, i);
    }
}

void compute()
{
    vector<int> v;
    int ans;

    cout << "1 2 3\n";
    cout.flush();
    cin >> ans;
    switch (ans)
    {
    case 1:
        v = {2, 1, 3};
        break;
    case 2:
        v = {1, 2, 3};
        break;
    case 3:
        v = {1, 3, 2};
        break;
    default:
        break;
    }

    for (int i = 4; i <= n; ++i)
    {
        insertNew(v, 0, v.size(), i);
    }

    for (int t : v)
        cout << t << " ";
    cout << "\n";
    cout.flush();
    cin >> ans;
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    cin >> t >> n >> q;
    while (t--)
    {
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}