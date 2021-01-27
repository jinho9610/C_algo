from collections import deque

f, s, g, u, d = map(int, input().split())

visited = [-1] * 1000001


def bfs(start):
    q = deque([start])
    visited[start] = 0

    while q:
        now = q.popleft()

        if now == g:
            return visited[now]

        for i in range(2):
            if i == 0:
                nxt = now + u
                if nxt <= f and visited[nxt] == -1:
                    q.append(nxt)
                    visited[nxt] = visited[now] + 1
            else:
                nxt = now - d
                if nxt > 0 and visited[nxt] == -1:
                    q.append(nxt)
                    visited[nxt] = visited[now] + 1

    return None


val = bfs(s)

if val == None:
    print('use the stairs')
else:
    print(val)
