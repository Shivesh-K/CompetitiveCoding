def solve():
    n = input()
    m = input()
    n = int(n)
    m = int(m)
    dp = [1, 2, 3]

    for i in range(3, n + 1):
        dp.append(dp[i - 1] + dp[i - 2])

    if(m > dp[n]):
        print("Not Possible")
        return

    ans = ''
    l = 0
    while l < n:
        if dp[n - l - 1] >= m:
            ans = ans + 'A'
        else:
            ans = ans + 'B'
            m -= dp[n - l - 1]
        l += 1

    print(ans)

def main():
    t = input()
    t = int(t)

    for _ in range(t):
        solve()
    

if __name__ == '__main__':
    main()