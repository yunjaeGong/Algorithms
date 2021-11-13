import sys
t = int(sys.stdin.readline().strip())

for _ in range(t):
    data = []
    no = []
    n = int(sys.stdin.readline().strip())

    for _ in range(2):
        data.append(list(map(int, sys.stdin.readline().strip().split())))

    dp = [data[0][0], data[1][0], 0]
    tmp = [0] * 3
    for j in range(1, n):
        tmp[0] = max(tmp[2], dp[1]) + data[0][j]  # data[i][j] 쓰는 경우
        tmp[1] = max(tmp[2], dp[0]) + data[1][j]
        tmp[2] = max(dp[0], dp[1])  # data[i][j] 쓰지 않는 경우
        dp[0] = tmp[0]
        dp[1] = tmp[1]

    print(max(dp[0], dp[1], tmp[2]))
