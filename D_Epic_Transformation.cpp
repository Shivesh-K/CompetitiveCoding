#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void swaps(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void compute()
{
    priority_queue<pair<int, int>> q;
    int n;
    cin >> n;
    map<int, int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[x]++;
    }
    for (auto t : v)
    {
        q.push({t.second, t.first});
    }
    int ans = n;
    while (q.size() >= 2)
    {
        auto t1 = q.top();
        q.pop();
        auto t2 = q.top();
        q.pop();
        t1.first--;
        t2.first--;
        ans -= 2;
        if (t1.first)
        {
            q.push({t1.first, t1.second});
        }
        if (t2.first)
        {
            q.push({t2.first, t2.second});
        }
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