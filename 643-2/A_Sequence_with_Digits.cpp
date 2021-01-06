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

string lastA, lastA1;
unsigned long long int lastK;
int i = 0;

void preprocess()
{
} //end prepreprocess

void refresh()
{
} //end refresh

void compute()
{
    unsigned long long int k, ans, min, max, add;
    string a1;
    cin >> a1 >> k;
    ans = stoull(a1);

    if (i > 0)
    {

        lastK = k;
        if (a1 == lastA1 && lastK < k)
        {
            k = k - lastK + 1;
            a1 = lastA;
        }
        i++;
    }
    k--;
    lastA1 = a1;
    while (k--)
    {
        min = max = (int)a1[0];
        for (int i = 0; i < a1.length(); ++i)
        {
            if (max < a1[i])
                max = a1[i];
            if (min > a1[i])
                min = a1[i];
        }
        max = max - '0';
        min = min - '0';
        if ((add = max * min) == 0)
            break;
        ans += (unsigned long long int)add;
        lastA = a1 = to_string(ans);
    }
    cout << a1 << "\n";
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