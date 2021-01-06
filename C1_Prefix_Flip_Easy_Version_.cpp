#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

vector<int> x;

string swap(string a, int j)
{

    if (j == -1)
    {
        return a;
    }

    string b;
    b = a;
    int k = 0;
    x.push_back(j + 1);
    while (k <= j)
    {
        b[k] = a[j - k] == '1' ? '0' : '1';
        ++k;
    }
    return b;
}

string operate(string a, int i)
{
    int j = i;

    if (a[0] == a[i])
    {
        a = swap(a, i);
        return a;
    }

    while (a[j] == a[i])
    {
        --j;
    }
    a = swap(a, j);
    a = swap(a, i);
    return a;
}

void compute()
{
    int n;
    string a, b;
    cin >> n >> a >> b;

    x.clear();
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] != b[i])
        {
            a = operate(a, i);
            // a = operate(a, i);
        }
    }

    cout << x.size() << " ";
    for (int i = 0; i < x.size(); ++i)
    {
        cout << x[i] << " ";
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
    int t;
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