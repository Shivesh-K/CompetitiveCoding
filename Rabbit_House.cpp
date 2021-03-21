#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int v[300][300];
int row, col;

struct Data
{
    int h, x, y;
    Data(int he, int xc, int yc) : h(he), x(xc), y(yc) {}
};

bool operator<(const Data &d1, const Data &d2)
{
    return d1.h < d2.h;
}

void updateNeighbours(pair<int, int> m, long long &ans, priority_queue<Data> &pq)
{
    pair<int, int> l = {m.first, m.second - 1};
    pair<int, int> r = {m.first, m.second + 1};
    pair<int, int> u = {m.first - 1, m.second};
    pair<int, int> d = {m.first + 1, m.second};

    if (l.second >= 0 && v[l.first][l.second] < v[m.first][m.second] - 1)
    {
        ans += v[m.first][m.second] - 1 - v[l.first][l.second];
        v[l.first][l.second] = v[m.first][m.second] - 1;
        Data newData(v[l.first][l.second], l.first, l.second);
        pq.push(newData);
    }
    if (r.second < col && v[r.first][r.second] < v[m.first][m.second] - 1)
    {
        ans += v[m.first][m.second] - 1 - v[r.first][r.second];
        v[r.first][r.second] = v[m.first][m.second] - 1;
        Data newData(v[r.first][r.second], r.first, r.second);
        pq.push(newData);
    }
    if (u.first >= 0 && v[u.first][u.second] < v[m.first][m.second] - 1)
    {
        ans += v[m.first][m.second] - 1 - v[u.first][u.second];
        v[u.first][u.second] = v[m.first][m.second] - 1;
        Data newData(v[u.first][u.second], u.first, u.second);
        pq.push(newData);
    }
    if (d.first < row && v[d.first][d.second] < v[m.first][m.second] - 1)
    {
        ans += v[m.first][m.second] - 1 - v[d.first][d.second];
        v[d.first][d.second] = v[m.first][m.second] - 1;
        Data newData(v[d.first][d.second], d.first, d.second);
        pq.push(newData);
    }
}

void compute()
{
    long long ans = 0;
    int x = 0;
    cin >> row >> col;
    priority_queue<Data> pq;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cin >> x;
            v[i][j] = x;
            Data newData(x, i, j);
            pq.push(newData);
        }
    }
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        if (temp.h == v[temp.x][temp.y])
        {
            updateNeighbours({temp.x, temp.y}, ans, pq);
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
    int t, i = 1;
    scanf("%d", &t);
    while (i <= t)
    {
        cout << "Case #" << i << ": ";
        compute();
        ++i;
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}