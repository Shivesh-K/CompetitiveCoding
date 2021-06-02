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
    int n, l, r, x, y, ans1 = 0, ans2 = 0, t;
    cin >> n;
    vector<int> v1(n), v2;
    for (int &t : v1)
        cin >> t;
    v2 = v1;

    for (int i = 0; i < n; ++i)
    {
        if (v1[i] != 1)
            continue;

        l = r = i;
        while (r + 1 < n && v1[r + 1] == 1)
            ++r;
        x = l;
        t = y = r;
        --l, ++r;
        while (x <= y)
        {
            while (l >= 0 && v1[l] != 0)
                --l;
            while (r < n && v1[r] != 0)
                ++r;

            if (l >= 0 && r < n)
            {
                if (x - l <= r - y)
                {
                    ans1 += x++ - l;
                    v1[l--] = -1;
                }
                else
                {
                    ans1 += r - y--;
                    v1[r++] = -1;
                }
            }
            else if (l >= 0)
            {
                ans1 += x++ - l;
                v1[l--] = -1;
            }
            else if (r < n)
            {
                ans1 += r - y--;
                v1[r++] = -1;
            }
        }
        i = t;
    }

    for (int i = n - 1; i >= 0; --i)
    {
        if (v2[i] != 1)
            continue;

        l = r = i;
        while (l - 1 >= 0 && v2[l - 1] == 1)
            --l;
        t = x = l;
        y = r;
        --l, ++r;
        while (x <= y)
        {
            while (l >= 0 && v2[l] != 0)
                --l;
            while (r < n && v2[r] != 0)
                ++r;

            if (l >= 0 && r < n)
            {
                if (x - l <= r - y)
                {
                    ans2 += x++ - l;
                    v2[l--] = -1;
                }
                else
                {
                    ans2 += r - y--;
                    v2[r++] = -1;
                }
            }
            else if (l >= 0)
            {
                ans2 += x++ - l;
                v2[l--] = -1;
            }
            else if (r < n)
            {
                ans2 += r - y--;
                v2[r++] = -1;
            }
        }
        i = t;
    }

    cout << (min(ans1, ans2)) << "\n";
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