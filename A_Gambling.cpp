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
    int n, i, j;
    ll sumA = 0, sumB = 0, t;
    bool turn = true;
    cin >> n;
    priority_queue<pair<int, bool>> pq;

    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        pq.push({t, true});
    }
    for (int j = 0; j < n; ++j)
    {
        cin >> t;
        pq.push({t, false});
    }

    while (!pq.empty())
    {
        ll x = pq.top().first;
        bool y = pq.top().second;
        pq.pop();
        if (turn & y)
            sumA += x;
        else if (!turn && !y)
            sumB += x;
        turn = !turn;
    }

    cout << sumA - sumB << "\n";
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