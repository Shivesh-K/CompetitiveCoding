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
    int n, m, c = 0;
    cin >> n >> m;
    bool v[100][100];
    bool a, b, c, d;
    vector<vector<int>> ans = {};
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> v[i][j];

    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < m; j += 2)
        {
            a = (v[i][j] == 0);
            b = (v[i][j + 1] == 0);
            c = (v[i + 1][j + 1] == 0);
            d = (v[i + 1][j] == 0);

            switch (4 - a + b + c + d)
            {
            case 4:
                c += 4;
                ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});
                ans.push_back({i + 1, j + 1, i + 1, j, i, j});
                ans.push_back({i + 1, j, i, j, i, j + 1});
                break;

            case 3:
                c += 1;

                if (a)
                {
                    ans.push_back({i, j + 1, i + 1, j + 1, i + 1, j});
                }
                else if (b)
                {
                    ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                }
                else if (c)
                {
                    ans.push_back({i, j + 1, i, j, i + 1, j});
                }
                else if (d)
                {
                    ans.push_back({i, j, i, j + 1, i + 1, j + 1});
                }
                break;

            default:
                break;
            }
        }
    }
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