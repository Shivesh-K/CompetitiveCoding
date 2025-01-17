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

    vector<string> commands(n);
    for (string &t : commands)
        cin >> t;

    vector<int> src(n);
    map<string, int> cnt;

    for (int i = 0; i < n; ++i)
    {
        if (commands[i][0] != '!')
        {
            src[i] = i;
        }
        else
        {
            int idx = stoi(commands[i].substr(1)) - 1;
            src[i] = src[idx];
        }
        cnt[commands[src[i]]]++;
    }

    return {cnt["cp"], cnt["ls"], cnt["mv"]};
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