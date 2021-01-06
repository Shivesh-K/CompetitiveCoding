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

long long sum(long long n)
{
    long long s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

void compute()
{
    long long n, s, t, t1, n1, ans = 0;
    string temp;
    cin >> n >> s;
    t = sum(n);

    if (t <= s)
    {
        cout << "0\n";
        return;
    }

    int p = 1;
    n1 = n;
    t1 = 10;
    while (t > s)
    {
        temp = to_string(n1);
        if (temp[temp.length() - p] != '0')
        {
            temp[temp.length() - p] = '0';
            n1 = stoll(temp);
            n1 += t1;
            t = sum(n1);
        }
        ++p;
        t1 *= 10;
    }
    ans = n1 - n;
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