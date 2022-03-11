#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

int n, mx;
vector<set<string>> likes, dislikes;
vector<string> ingredients;
set<string> chosen, ans;

void recur(int idx)
{
    if (idx >= ingredients.size())
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            bool fl = true;

            for (auto like : likes[i])
                if (chosen.find(like) == chosen.end())
                {
                    fl = false;
                    break;
                }
            for (auto dislike : dislikes[i])
                if (chosen.find(dislike) != chosen.end())
                {
                    fl = false;
                    break;
                }

            cnt += fl;
        }

        if (cnt > mx)
            mx = cnt, ans = chosen;

        return;
    }

    recur(idx + 1);
    chosen.insert(ingredients[idx]);
    recur(idx + 1);
    chosen.erase(ingredients[idx]);
}

void compute()
{
    cin >> n;
    likes = vector<set<string>>(n);
    dislikes = vector<set<string>>(n);
    mx = 0;

    set<string> temp;

    for (int i = 0; i < n; ++i)
    {
        int t;
        string s;

        cin >> t;
        while (t--)
        {
            cin >> s;
            likes[i].insert(s);
            temp.insert(s);
        }

        cin >> t;
        while (t--)
        {
            cin >> s;
            dislikes[i].insert(s);
            temp.insert(s);
        }
    }

    ingredients = vector<string>(temp.begin(), temp.end());

    recur(0);

    cout << ans.size() << " ";
    for (auto el : ans)
        cout << el << " ";
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