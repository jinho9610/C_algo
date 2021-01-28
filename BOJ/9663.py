n = int(input())

cols = [0] * (n + 1)

result = 0


def promising(x):
    for i in range(1, x):
        # 같은 열에 있거나 대각선에 있다면
        if cols[i] == cols[x] or abs(cols[i]-cols[x]) == abs(i-x):
            return False

    return True


def chess(x):
    global result
    if(promising(x)):
        if(x == n):
            result += 1
        else:
            for i in range(1, n+1):
                cols[x + 1] = i
                chess(x + 1)


chess(0)

print(result)
