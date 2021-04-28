
def arr_changer():
    global arr
    arr = [5, 5, 5, 5, 5, 5]
    arr[3] = 2
    print(arr)


if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5]
    arr_changer()
    print(arr)
