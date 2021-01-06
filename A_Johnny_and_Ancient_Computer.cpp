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
    long long int a, b, ans, rem;
    int il, ir, jl, jr;
    cin >> a >> b;

    bitset<64> bseta(a), bsetb(b);
    for (il = 63; il >= 0 && bseta[il] != 1; --il)
    {
    }
    for (ir = 0; ir < 64 && bseta[ir] != 1; ++ir)
    {
    }
    for (jl = 63; jl >= 0 && bsetb[jl] != 1; --jl)
    {
    }
    for (jr = 0; jr < 64 && bsetb[jr] != 1; ++jr)
    {
    }

    if (il - ir != jl - jr)
    {
        cout << "-1\n";
        return;
    }
    ans = abs(il - jl);
    for (; il >= ir; --il, --jl)
    {
        if (bseta[il] != bsetb[jl])
        {
            cout << "-1\n";
            return;
        }
    }

    rem = ans;
    ans = rem / 3;
    rem %= 3;
    ans += rem / 2;
    rem %= 2;
    ans += rem;
    cout << ans << "\n";
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