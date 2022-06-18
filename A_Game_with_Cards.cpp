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
    int n, m;

    cin >> n;
    vector<int> a(n);
    for (int &t : a)
        cin >> t;

    cin >> m;
    vector<int> b(m);
    for (int &t : b)
        cin >> t;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int mx1 = a.back();
    int mx2 = b.back();

    if (mx1 > mx2)
        cout << "Alice\nAlice\n";
    else if (mx1 < mx2)
        cout << "Bob\nBob\n";
    else
        cout << "Alice\nBob\n";
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