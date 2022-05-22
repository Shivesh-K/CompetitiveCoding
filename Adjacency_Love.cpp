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
    ll n, oddCnt = 0, evenCnt = 0;
    cin >> n;
    vector<ll> evenVector, oddVector;
    for (ll i = 0; i < n; ++i)
    {
        ll t;
        cin >> t;
        if (t & 1)
            oddCnt++, evenVector.push_back(t);
        else
            evenCnt++, oddVector.push_back(t);
    }

    if (oddCnt <= 1)
    {
        cout << "-1\n";
        return;
    }

    if ((oddCnt & 1) == 0)
    {
        for (ll t : evenVector)
            cout << t << " ";
        for (ll t : oddVector)
            cout << t << " ";
        cout << "\n";
    }
    else
    {
        if (!evenCnt)
        {
            cout << "-1\n";
            return;
        }

        for (ll i = 0; i < evenVector.size() - 1; ++i)
            cout << evenVector[i] << " ";
        cout << oddVector[0] << " ";
        cout << evenVector[evenVector.size() - 1] << " ";
        for (ll i = 1; i < oddVector.size(); ++i)
            cout << oddVector[i] << " ";
        cout << "\n";
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