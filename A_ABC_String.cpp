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
    int n;
    char v;
    bool f;
    string s;
    stack<char> st;
    map<char, char> m;
    cin >> s;

    n = s.length();
    if (s[0] == s[n - 1])
    {
        cout << "NO\n";
        return;
    }
    m[s[0]] = '(';
    m[s[n - 1]] = ')';
    if (m.find('A') == m.end())
        v = 'A';
    else if (m.find('B') == m.end())
        v = 'B';
    else
        v = 'C';

    m[v] = '(';
    f = true;
    for (char c : s)
    {
        if (m[c] == '(')
            st.push('(');
        else if (!st.empty() && st.top() == '(')
            st.pop();
        else
        {
            f = false;
            break;
        }
    }
    f = f & st.empty();

    if (!f)
    {
        while (!st.empty())
            st.pop();
        m[v] = ')';
        f = true;
        for (char c : s)
        {
            if (m[c] == '(')
                st.push('(');
            else if (!st.empty() && st.top() == '(')
                st.pop();
            else
            {
                f = false;
                break;
            }
        }
        f = f & st.empty();
    }

    cout << (f ? "YES\n" : "NO\n");
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