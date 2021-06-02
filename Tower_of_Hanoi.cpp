#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void recur(int n, int start, int end)
{
    if (n == 1)
    {
        cout << start << " " << end << "\n";
        return;
    }
    int mid = 6 - start - end;
    recur(n - 1, start, mid);
    cout << start << " " << end << "\n";
    recur(n - 1, mid, end);
}

void compute()
{
    int n;
    cin >> n;
    cout << ((1 << n) - 1) << "\n";
    recur(n, 1, 3);
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