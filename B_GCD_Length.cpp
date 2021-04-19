#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

map<int, pair<int, int>> m;

void compute()
{
    int a, b, c;
    cin >> a >> b >> c;

    long long n1, n2;
    n1 = n2 = (c == 1 ? 1 : pow(10, c - 1));
    a -= c - 1;
    b -= c - 1;
    n1 *= m[a].first;
    n2 *= m[b].second;

    cout << n1 << " " << n2 << "\n";
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
    m[1] = {2, 3};
    m[2] = {11, 13};
    m[3] = {101, 103};
    m[4] = {1009, 1013};
    m[5] = {10007, 10009};
    m[6] = {100019, 100043};
    m[7] = {1000003, 1000009};
    m[8] = {10000019, 10000169};
    m[9] = {608888809, 609861011};
    while (t--)
    {
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}