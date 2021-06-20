import sys
import math

sys.stdin = open("input.txt", 'r')

k, n = map(int, input().split())

arr = []
for _ in range(k):
    arr.append(int(input()))

start, end = 1, max(arr)
ans = 0

while start <= end:
    mid = (start + end) // 2
    
    cnt = 0
    for ar in arr:
        cnt += ar // mid
    
    if cnt >= n:
        start = mid + 1
    else:
        end = mid - 1

print(end)