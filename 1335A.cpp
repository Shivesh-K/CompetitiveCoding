#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long int n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%ld", &n);
        switch (n)
        {
        case 1:
        case 2:
            printf("0\n");
            break;
        default:
            n = (n >> 1) - ((n & 1) ? 0 : 1);
            printf("%d\n", n);
            break;
        }
    }
}