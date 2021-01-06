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

void preprocess()
{
} //end prepreprocess

void refresh()
{
} //end refresh

void compute()
{
    int n, temp, x, y, ans;
    vector<int> S;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        S.push_back(temp);
    }
    sort(S.begin(), S.end());
    x = S[0];
    y = S[1];
    bitset<10> bsetx(x);
    bitset<10> bsety(y);
    bitset<10> bsetans;
    for (int i = 0; i < 10; ++i)
    {
        if (bsety[i] == 1)
        {
            bsetans[i] = 1 - bsetx[i];
        }
        else
        {
            bsetans[i] = bsetx[i];
        }
    }
} //end compute

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t, i, j;
    preprocess();
    scanf("%d", &t);
    while (t--)
    {
        compute();
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*