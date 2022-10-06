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
    int n;
    cin >> n;

    cout << "1\n";

    string left, right;
    for (char ch = 'z'; ch > 'z' - (n - 3); --ch)
        right += ch;

    for (int i = 1; i < n - 1; ++i)
    {
        cout << " ";
        for (auto it = left.rbegin(); it != left.rend(); ++it)
            cout << *it;
        cout << i + 1 << right << " \n";
        left += 'a' + i - 1;
        right.pop_back();
    }

    cout << string(n - 1, ' ') << n << "\n";
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