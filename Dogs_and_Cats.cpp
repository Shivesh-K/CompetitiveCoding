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
    long long n, d, c, m;
    string s;
    cin >> n >> d >> c >> m >> s;

    vector<int> dogs;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'D')
            dogs.push_back(i);

    if (dogs.empty())
    {
        cout << "YES\n";
        return;
    }

    if (d < dogs.size())
    {
        cout << "NO\n";
        return;
    }

    int prev = -1;
    for (int i = 0; i < dogs.size(); ++i)
    {
        if (c < dogs[i] - prev - 1)
        {
            cout << "NO\n";
            return;
        }
        c -= dogs[i] - prev - 1;
        --d;
        c += m;
        prev = dogs[i];
    }

    cout << "YES\n";
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