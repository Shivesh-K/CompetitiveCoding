//https://codeforces.com/problemset/problem/1353/F
#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
using namespace std;
#define MOD 1000000007LL
#define LL long long
#define ULL unsigned long long
#define LD long double
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define si(n) scanf("%d", &n)
#define sf(n) scanf("%f", &n)
#define sl(n) scanf("%lld", &n)
#define slu(n) scanf("%llu", &n)
#define sd(n) scanf("%lf", &n)
#define ss(n) scanf("%s", n)
#define pnl printf("\n")
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, n) for (int i = (n); i >= 0; i--)
#define DB(x) cout << "\n" \
                   << #x << " = " << (x) << "\n";
#define CL(a, b) memset(a, b, sizeof(a))
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
ULL gcd(ULL a, ULL b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == 1 || b == 1)
        return 1;
    if (a == b)
        return a;
    if (a > b)
        return gcd(b, a % b);
    else
        return gcd(a, b % a);
}
#define SIZE 1000001

void preprocess()
{
} //end prepreprocess

void refresh()
{
} //end refresh

void compute()
{
    long long int n, k, unstableDays, temp, sum = 0;
    bool flag1, flag2;
    vector<long long int> incomes;
    cin >> n;
    unstableDays = (n / 2) + ((n & 1) ? 1 : 0);
    for (long long int i = 0; i < unstableDays; ++i)
    {
        cin >> temp;
        sum += temp;
        incomes.push_back(temp);
    }
    unstableDays = n - unstableDays;
    cin >> temp;
    for (long long int i = 0; i < unstableDays; ++i)
    {
        sum += temp;
        incomes.push_back(temp);
    }

    if (n == 1 && incomes[0] <= 0)
    {
        printf("-1\n");
        return;
    }
    temp = sum;
    k = n;
    for (long long int x = n; x >= 1; --x)
    {
        if (temp > 0)
        {
            break;
        }

        temp -= incomes[x - 1];
        k = x - 1;
    }
    flag2 = false;
    for (; k > 0; --k)
    {
        flag1 = true;
        sum = temp;
        for (long long int i = 0; i <= n - k; ++i)
        {
            if (sum <= 0)
            {
                flag1 = false;
                break;
            }
            if (i + k < n)
            {
                sum -= incomes[i];
                sum += incomes[i + k];
            }
        }
        if (flag1)
        {
            flag2 = true;
            break;
        }
        temp -= incomes[k - 1];
    }

    if (flag2)
        cout << k << "\n";
    else
        cout << "-1\n";

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
    t = 1;
    while (t--)
    {
        compute();
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*