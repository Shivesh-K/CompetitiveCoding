#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void swaps(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swapi(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void compute()
{
    int n, ans = 0, i = 0;
    string s;
    deque<int> a;
    cin >> n >> s;
    while (i < n)
    {
        int j = i + 1;
        while (j < n && s[j] == s[i])
            j++;
        a.push_back(j - i);
        i = j;
    }

    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] > 1)
        {
        }
        else
        {
            bool b = false;
            for (int j = i + 1; j < a.size(); ++j)
            {
                if (a[j] > 2)
                {
                    a[j]--;
                    b = !b;
                    break;
                }
            }
            if (!b)
            {
                for (int j = i + 2; j < a.size(); j += 2)
                {
                    if (a[j] == 2)
                    {
                        a[j]--;
                        b = !b;
                        break;
                    }
                }
                if (!b && i + 2 < a.size())
                {
                    a.erase(a.begin() + i + 2);
                    if (i + 2 < a.size())
                    {
                        a[i + 1] += a[i + 2];
                        a.erase(a.begin() + i + 2);
                    }
                }
                else
                {
                    ans++;
                    break;
                }
            }
        }
        ans++;
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