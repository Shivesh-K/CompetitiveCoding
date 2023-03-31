#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int n, m;
vector<int> a, anc, cnt;
vector<vector<int>> adj;

int getAnc(int node)
{
    if (anc[node] == node)
        return node;
    return anc[node] = getAnc(anc[node]);
}

int mergeNodes(int x, int y)
{
    x = getAnc(x), y = getAnc(y);
    anc[y] = x;
    cnt[x] = cnt[y] + cnt[x];
    // cout << cnt[x] << " ";
}

void func(int node)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int next : adj[node])
        pq.push({a[next], next});
    while (!pq.empty())
    {
        auto el = pq.top();
        pq.pop();
        if (cnt[getAnc(node)] >= el.first && getAnc(el.second) != getAnc(node))
        {
            mergeNodes(node, el.second);
            for (int next : adj[el.second])
                pq.push({a[next], next});
        }
    }
}

void compute()
{
    cin >> n >> m;

    a.resize(n);
    anc.resize(n);
    cnt.resize(n);
    for (int &t : a)
        cin >> t;

    for (int i = 0; i < n; ++i)
        anc[i] = i, cnt[i] = 1;

    adj = vector<vector<int>>(n);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0 && cnt[getAnc(i)] <= 1)
            func(i);
    }

    if (cnt[getAnc(0)] == n)
        cout << "YES\n";
    else
        cout << "NO\n";
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