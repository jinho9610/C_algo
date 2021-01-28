from collections import deque
import sys

n, m = map(int, input().split())
arr = [[0] * (m+1) for _ in range(n+1)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for i in range(1, n+1):
    data = list(map(int, input().split()))
    for j in range(1, m+1):
        arr[i][j] = data[j-1]


def isInside(x, y):
    return 0 < x <= n and 0 < y <= m


def bfs(a, b):
    q = deque([(a, b)])
    visited[a][b] = True

    while q:
        x, y = q.popleft()

        cnt = 0
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]

            if isInside(nx, ny) and not visited[nx][ny]:
                if arr[nx][ny] > 0:  # 빙산인 경우
                    q.append((nx, ny))
                    visited[nx][ny] = True
                else:  # 바다인 경우
                    cnt += 1

        if arr[x][y] <= cnt:
            arr[x][y] = 0
        else:
            arr[x][y] -= cnt


y = 0
while True:
    isAllMelt = True
    cont = 0
    visited = [[False] * (m + 1) for _ in range(n+1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if arr[i][j] > 0:
                isAllMelt = False
            if arr[i][j] > 0 and not visited[i][j]:
                bfs(i, j)
                cont += 1
                if cont > 1:
                    print(y)
                    sys.exit()

    if isAllMelt == True:
        print(0)
        sys.exit()

    y += 1
