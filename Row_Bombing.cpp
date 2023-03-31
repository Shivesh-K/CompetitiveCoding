#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

bool comp(vector<int> &v1, vector<int> &v2)
{
    if (v1[0] != v2[0])
        return v1[0] > v2[0];
    else if (v1[1] != v2[1])
        return v1[1] < v2[1];
    else
        return v1[2] < v2[2];
}

void compute()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (string &row : v)
        cin >> row;

    vector<int> dist(n * m, INT_MAX);
    priority_queue<vector<int>, vector<vector<int>>, function<bool(vector<int> &, vector<int> &)>> pq(comp);
    pq.push({0, 0, -1});
    dist[0] = 0;

    while (!pq.empty())
    {
        auto el = pq.top();
        pq.pop();

        int cost = el[0];
        int i = el[1] / m, j = el[1] % m;
        int ls = el[2];

        if (i == n - 1 && j == m - 1)
            break;

        if (cost > dist[el[1]])
            continue;

        if (i + 1 < n)
        {
            if (v[i + 1][j] == '.')
            {
                if (cost < dist[m * (i + 1) + j])
                {
                    pq.push({cost, m * (i + 1) + j, ls});
                    dist[m * (i + 1) + j] = cost;
                }
            }
            else
            {
                if (cost + 1 < dist[m * (i + 1) + j])
                {
                    pq.push({cost + 1, m * (i + 1) + j, i + 1});
                    dist[m * (i + 1) + j] = cost + 1;
                }
            }
        }

        if (i - 1 >= 0 && ls < i)
        {
            if (v[i - 1][j] == '.')
            {
                if (cost < dist[m * (i - 1) + j])
                {
                    pq.push({cost, m * (i - 1) + j, ls});
                    dist[m * (i - 1) + j] = cost;
                }
            }
            else if (ls < i - 1)
            {
                if (cost + 1 < dist[m * (i - 1) + j])
                {
                    pq.push({cost + 1, m * (i - 1) + j, i - 1});
                    dist[m * (i - 1) + j] = cost + 1;
                }
            }
            else
            {
                if (cost < dist[m * (i - 1) + j])
                {
                    pq.push({cost, m * (i - 1) + j, ls});
                    dist[m * (i - 1) + j] = cost;
                }
            }
        }

        if (j + 1 < m)
        {
            if (v[i][j + 1] == '.')
            {
                if (cost < dist[m * i + j + 1])
                {
                    pq.push({cost, m * i + j + 1, ls});
                    dist[m * i + j + 1] = cost;
                }
            }
            else if (ls < i)
            {
                if (cost + 1 < dist[m * i + j + 1])
                {
                    pq.push({cost + 1, m * i + j + 1, i});
                    dist[m * i + j + 1] = cost + 1;
                }
            }
            else
            {
                if (cost < dist[m * i + j + 1])
                {
                    pq.push({cost, m * i + j + 1, ls});
                    dist[m * i + j + 1] = cost;
                }
            }
        }

        if (j - 1 >= 0)
        {
            if (v[i][j - 1] == '.')
            {
                if (cost < dist[m * i + j - 1])
                {
                    pq.push({cost, m * i + j - 1, ls});
                    dist[m * i + j - 1] = cost;
                }
            }
            else if (ls < i)
            {
                if (cost + 1 < dist[m * i + j - 1])
                {
                    pq.push({cost + 1, m * i + j - 1, i});
                    dist[m * i + j - 1] = cost + 1;
                }
            }
            else
            {
                if (cost < dist[m * i + j - 1])
                {
                    pq.push({cost, m * i + j - 1, ls});
                    dist[m * i + j - 1] = cost;
                }
            }
        }
    }

    cout << dist[n * m - 1] << "\n";
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