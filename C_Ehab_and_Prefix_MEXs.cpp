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
    int n, temp, temp2;
    vector<int> a, b;
    list<int> c;
    a.push_back(0);
    b.push_back(0);
    c.push_front(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> temp;
        if (temp > i)
        {
            cout << "-1\n";
            return;
        }
        a.push_back(temp);
        c.push_front(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        temp = c.back();
        c.pop_back();
        if (temp > a[i])
        {
            b.push_back(temp);
        }
        else if (temp == a[i])
        {
            b.push_back(c.back());
            c.pop_back();
            c.push_back(temp);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
} //end compute

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t = 1;
    while (t--)
    {
        compute();
    } //end while
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
} //end main*