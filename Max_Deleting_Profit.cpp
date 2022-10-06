#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int recur(int l, int r, vector<int> &arr)
{
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];

    int prefix = 0, suffix = 0, ans = 0;
    bool fl = true;
    for (int x = l; x <= r; ++x)
    {
        if (arr[x] == arr[l])
        {
            if (fl)
                ++prefix;
            ++suffix;
        }
        else
        {
            fl = false;
            suffix = 0;
        }

        int temp;
        if (prefix == suffix && prefix == x - l + 1)
            temp = prefix * prefix + recur(x + 1, r, arr);
        else
            temp = recur(l + prefix, x - suffix, arr) + (prefix + suffix) * (prefix + suffix) + recur(x + 1, r, arr);

        ans = max(ans, temp);
    }

    return dp[l][r] = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &t : v)
        cin >> t;
    dp = vector<vector<int>>(n, vector<int>(n, -1));
    cout << recur(0, n - 1, v) << "\n";
}