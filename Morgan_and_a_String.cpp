#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<vector<string>> dp;
int n, m;

string recur(int i, int j, string &a, string &b) {
    if(i >= n)
        return b.substr(j);
    if(j >=m)
        return a.substr(i);
    if(dp[i][j].size())
        return dp[i][j];

    string ans;
    if(a[i] < b[j ]){
        ans = recur(i + 1, j, a, b);
        ans += a[i];
    }
    else if(a[i] > b[j]) {
        ans = recur(i, j + 1, a, b);
        ans += b[j];
    }
    else {
        string t1 = recur(i, j + 1, a, b);
        string t2 = recur(i + 1, j, a, b);
        int l = n - i + m - j - 1;
        
    }
}

void compute()
{
    string a, b;
    cin >> a >> b;
    n = a.size();
    m = b.size();
    dp = vector<vector<string>>(n + 1, vector<string>(m + 1));

    string ans = recur(0, 0, a, b);
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