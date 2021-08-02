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
    int n, k, i;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &t : a)
        cin >> t;
    for (int &t : b)
        cin >> t;

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    i = k = n - n / 4;
    while (a.size() > k)
        a.pop_back();

    int sumA = accumulate(a.begin(), a.end(), 0);
    int sumB = accumulate(b.begin(), b.begin() + k, 0);
    int ans = 0;

    while (sumA < sumB)
    {
        ++n;
        sumA += 100;
        sumB += ++i <= b.size() ? b[i - 1] : 0;
        if (n % 4 == 0)
        {
            sumA -= a.back();
            a.pop_back();
            // sumB -= --i <= b.size() ? b[i] : 0;
        }
        ++ans;
    }
    cout << ans << "\n";
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