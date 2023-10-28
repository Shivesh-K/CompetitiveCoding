// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

string ans;

bool operate(vector<int> nums)
{
    if (nums.size() == 1)
    {
        cout << ans << " " << nums[0] << "\n";
        return (nums[0] == 10);
    }

    int n = nums.size() - 1;
    vector<int> x(n);
    string temp = ans;
    for (int i = 0; i < n - 1; ++i)
        x[i] = nums[i];

    x[n - 1] = nums[n - 1] + nums[n];
    ans = ans + to_string(nums[n - 1]) + '+';
    if (operate(x))
        return true;
    ans = temp;

    x[n - 1] = nums[n] - nums[n - 1];
    ans = ans + to_string(nums[n - 1]) + '-';
    if (operate(x))
        return true;
    ans = temp;

    x[n - 1] = nums[n - 1] * nums[n];
    ans = ans + to_string(nums[n - 1]) + '*';
    if (operate(x))
        return true;
    ans = temp;

    if (nums[n - 1] != 0 && nums[n] % nums[n - 1] == 0)
    {
        x[n - 1] = nums[n] / nums[n - 1];
        ans = ans + to_string(nums[n - 1]) + '/';
        if (operate(x))
            return true;
        ans = temp;
    }

    return false;
}

void solve()
{
    vector<int> nums(4);

    for (int &t : nums)
        cin >> t;

    do
    {
        ans = to_string(nums[3]);
        if (operate(nums))
        {
            cout << "Solution found\n";
            break;
        }
    } while (next_permutation(nums.begin(), nums.end()));
}

int main()
{
    solve();
    return 0;
}