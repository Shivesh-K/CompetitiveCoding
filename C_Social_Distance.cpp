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
    int n, k, ans = 0, temp, x, size;
    string s;
    vector<int> ones;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            ones.push_back(i);
        }
    }
    size = ones.size();
    if (size == 0)
    {
        ans = ((n / (k + 1)) + ((n % (k + 1)) > 0 ? 1 : 0));
    }
    else
    {
        x = ones[0];
        while (x > k)
        {
            ans++;
            x -= (k + 1);
        }
        x = ones[0];
        for (int i = 1; i < size; ++i)
        {
            temp = ones[i] - x - 1;
            if (temp > k)
            {
                ans += (temp / (k + 1));
                if ((temp % (k + 1)) != k)
                    ans--;
            }

            x = ones[i];
        }
        x = n - ones[size - 1] - 1;
        while (x > k)
        {
            ans++;
            x -= (k + 1);
        }
    }
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