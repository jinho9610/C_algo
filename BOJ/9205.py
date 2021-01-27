from pprint import pprint

INF = int(1e9)

T = int(input())

for t in range(1, T+1):
    n = int(input())

    dist = [[INF] * (n + 3) for _ in range(n+3)]

    places = []

    for i in range(1, n + 3):
        x, y = map(int, input().split())
        places.append((x, y))

    for i in range(1, len(places) + 1):
        for j in range(1, len(places) + 1):
            distance = abs(places[i-1][0] - places[j-1][0]) + \
                abs(places[i-1][1]-places[j-1][1])
            if distance <= 1000:
                dist[i][j] = 1

    for k in range(1, n + 3):
        for i in range(1, n + 3):
            for j in range(1, n + 3):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    if dist[1][n + 2] is not INF:
        print('happy')
    else:
        print('sad')
