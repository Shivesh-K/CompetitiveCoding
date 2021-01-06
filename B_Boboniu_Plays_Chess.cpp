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
    int n, m, sx, sy, ex, ey;
    bool dir = true;
    cin >> n >> m >> sx >> sy;

    cout << sx << " " << sy << "\n";
    cout << sx << " 1\n";
    cout << "1 1\n";

    auto p1 = make_pair(sx, sy);
    auto p2 = make_pair(sx, 1);

    sx = sy = 1;
    ey = m;
    ex = m & 1 ? n : 1;
    while (!(sx == ex && sy == ey))
    {
        if ((sx == n && dir) || (sx == 1 && !dir))
        {
            sy++;
            dir = !dir;
        }
        else
        {
            sx += (dir ? 1 : -1);
        }
        if (make_pair(sx, sy) == p1 || make_pair(sx, sy) == p2)
        {
            continue;
        }
        else
        {
            cout << sx << " " << sy << "\n";
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
    compute();
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}