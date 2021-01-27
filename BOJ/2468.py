from collections import deque
from pprint import pprint

n = int(input())

arr = [[0] * (n+1) for _ in range(n+1)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

max_h = 0

for i in range(1, n+1):
    data = list(map(int, input().split()))
    for j in range(1, n+1):
        arr[i][j] = data[j-1]
        max_h = max(max_h, arr[i][j])


def isInside(x, y):
    return 0 < x <= n and 0 < y <= n


def bfs(visited, x, y):
    q = deque([(x, y)])
    visited[x][y] = True

    while q:  # q가 빌때까지
        x, y = q.popleft()

        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if isInside(nx, ny) and not visited[nx][ny] and arr[nx][ny] > h:
                visited[nx][ny] = True
                q.append((nx, ny))


result = 0

for h in range(max_h+1):
    cnt = 0
    visited = [[False] * (n+1) for _ in range(n+1)]

    for i in range(1, n+1):
        for j in range(1, n+1):
            if not visited[i][j] and arr[i][j] > h:
                bfs(visited, i, j)
                cnt += 1

    result = max(result, cnt)

print(result)
