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
    ll n, i;
    cin >> n;
    vector<ll> arr;
    vector<pair<ll, ll>> arr2;
    for (i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        arr.push_back(temp);
        arr2.push_back({temp, i});
    }
    vector<ll> v1 = arr;
    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());
    for (i = 0; i < n;)
    {
        ll x = arr[i], cnte = 0, cnto = 0;
        while (i < n && x == arr[i])
        {
            if ((arr2[i].second) % 2 == 0)
                cnte++;
            else
                cnto++;

            if (i % 2 == 0)
                --cnte;
            else
                --cnto;

            ++i;
        }
        if (cnte || cnto)
        {
            cout << "NO\n";
            return;
        }
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