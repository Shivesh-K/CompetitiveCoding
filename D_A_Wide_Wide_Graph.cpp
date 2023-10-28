#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

#define N 100005
vector<int> adj[N];

int lvl[N];
int dist1[N];
int dist2[N];

void AddEdge(int u, int v)
{
    // Edge from U to V
    adj[u].push_back(v);

    // Edge from V to U
    adj[v].push_back(u);
}

int end1, end2, maxi;

// DFS to find the first
// End Node of diameter
void findFirstEnd(int u, int p)
{
    // Calculating level of nodes
    lvl[u] = 1 + lvl[p];
    if (lvl[u] > maxi)
    {
        maxi = lvl[u];
        end1 = u;
    }

    for (int i = 0; i < adj[u].size(); i++)
    {

        // Go in opposite
        // direction of parent
        if (adj[u][i] != p)
        {
            findFirstEnd(adj[u][i], u);
        }
    }
}

// Function to clear the levels
// of the nodes
void clear(int n)
{
    // set all value of lvl[]
    // to 0 for next dfs
    for (int i = 0; i <= n; i++)
    {
        lvl[i] = 0;
    }

    // Set maximum with 0
    maxi = 0;
    dist1[0] = dist2[0] = -1;
}

// DFS will calculate second
// end of the diameter
void findSecondEnd(int u, int p)
{
    // Calculating level of nodes
    lvl[u] = 1 + lvl[p];
    if (lvl[u] > maxi)
    {
        maxi = lvl[u];

        // Store the node with
        // maximum depth from end1
        end2 = u;
    }

    for (int i = 0; i < adj[u].size(); i++)
    {
        // Go in opposite
        // direction of parent
        if (adj[u][i] != p)
        {
            findSecondEnd(adj[u][i], u);
        }
    }
}

// Function to find the distance
// of the farthest distant node
void findDistancefromFirst(int u, int p)
{
    // Storing distance from
    // end1 to node u
    dist1[u] = 1 + dist1[p];
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (adj[u][i] != p)
        {
            findDistancefromFirst(adj[u][i], u);
        }
    }
}

// Function to find the distance
// of nodes from second end of diameter
void findDistancefromSecond(int u, int p)
{
    // storing distance from end2 to node u
    dist2[u] = 1 + dist2[p];
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (adj[u][i] != p)
        {
            findDistancefromSecond(adj[u][i], u);
        }
    }
}

void compute()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        AddEdge(a, b);
    }

    findFirstEnd(1, 0);
    clear(n);

    findSecondEnd(end1, 0);
    findDistancefromFirst(end1, 0);
    findDistancefromSecond(end2, 0);

    vector<int> distances;

    for (int i = 1; i <= n; i++)
    {
        int x = dist1[i];
        int y = dist2[i];
        if (x >= y)
        {
            distances.push_back(end1);
        }
        else
        {
            distances.push_back(end1);
        }
    }

    sort(distances.begin(), distances.end());

    for (int k = 1; k <= n; ++k)
    {
        int idx = lower_bound(distances.begin(), distances.end(), k) - distances.begin();
        cout << min(idx + (idx < n ? 1 : 0), n) << " ";
    }

    cout << "\n";
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