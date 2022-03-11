#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

void compute()
{
    string s, ans;
    cin >> s;

    vector<vector<char>> keypad(10);
    keypad[0] = {' ', '0'};
    keypad[1] = {',', '@'};
    keypad[2] = {'A', 'B', 'C', 'a', 'b', 'c', '2'};
    keypad[3] = {'D', 'E', 'F', 'd', 'e', 'f', '3'};
    keypad[4] = {'G', 'H', 'I', 'g', 'h', 'i', '4'};
    keypad[5] = {'J', 'K', 'L', 'j', 'k', 'l', '5'};
    keypad[6] = {'M', 'N', 'O', 'm', 'n', 'o', '6'};
    keypad[7] = {'P', 'Q', 'R', 'S', 'p', 'q', 'r', 's', '7'};
    keypad[8] = {'T', 'U', 'V', 't', 'u', 'v', '8'};
    keypad[9] = {'W', 'X', 'Y', 'Z', 'w', 'x', 'y', 'z', '9'};

    s += '#';
    char last = '#';
    int f = 1;
    for (char ch : s)
    {
        if (ch == last)
            ++f;
        else
        {
            if (last != '#')
                ans += keypad[last - '0'][f % keypad[last - '0'].size()];
            f = 0;
            last = (ch == '_' ? '#' : ch);
        }
    }

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