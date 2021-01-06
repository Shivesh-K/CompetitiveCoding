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
    int n, x, temp, evenCount = 0, oddCount = 0;
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        temp & 1 ? oddCount++ : evenCount++;
    }

    if (oddCount >= 1)
    {
        x--;
        oddCount--;
        if (x <= evenCount)
        {
            cout << "Yes\n";
        }
        else
        {
            if ((x - evenCount) % 2 == 0)
            {
                cout << "Yes\n";
            }
            else
            {
                if (evenCount > 0 && x - evenCount + 1 <= oddCount && (x - evenCount + 1) % 2 == 0)
                {
                    cout << "Yes\n";
                }
                else
                {
                    cout << "No\n";
                }
            }
        }
    }
    else
    {
        cout << "No\n";
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