#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

pair<int, int> calcNext(map<pair<pair<int, int>, char>, pair<int, int>> &m, pair<int, int> curr, char dir)
{
    if (m.find({curr, dir}) == m.end())
    {
        return m[{curr, dir}] = curr;
    }

    if (m[{curr, dir}] == curr)
    {
        return curr;
    }
    else
    {
        return m[{curr, dir}] = calcNext(m, m[{curr, dir}], dir);
    }
}

pair<int, int> moveNext(map<pair<pair<int, int>, char>, pair<int, int>> &m, pair<int, int> curr, char dir)
{
    m[{curr, 'N'}] = calcNext(m, {curr.first - 1, curr.second}, 'N');
    m[{curr, 'S'}] = calcNext(m, {curr.first + 1, curr.second}, 'S');
    m[{curr, 'E'}] = calcNext(m, {curr.first, curr.second + 1}, 'E');
    m[{curr, 'W'}] = calcNext(m, {curr.first, curr.second - 1}, 'W');

    return m[{curr, dir}];
}

void compute(int testCase)
{
    int n, r, c, sr, sc;
    string s;
    cin >> n >> r >> c >> sr >> sc;
    cin >> s;
    map<pair<pair<int, int>, char>, pair<int, int>> m;
    pair<int, int> final = {sr, sc};
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            pair<int, int> x = {i, j};
            m[{x, 'N'}] = x;
            m[{x, 'S'}] = x;
            m[{x, 'E'}] = x;
            m[{x, 'W'}] = x;
        }
    }
    for (char c : s)
    {
        final = moveNext(m, final, c);
    }
    cout << "Case #" << testCase << ": " << final.first << " " << final.second << "\n";
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
    for (int i = 1; i <= t; ++i)
    {
        compute(i);
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}