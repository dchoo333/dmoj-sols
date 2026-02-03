def s(n, k, prev_str):
    str = ""
    if n == k:
        for i in range(n):
            str += "1"
        if len(str) == N:
            print(str)
        return str
    elif n == 0:
        return ""
    elif k == 0:
        for i in range(n):
            str += "0"
        if len(str) == N:
            print(str)
        return str
    str = prev_str + "1" + s(n - 1, k - 1, prev_str + "1")
    if len(str) == N:
        print(str)
    str = prev_str + "0" + s(n - 1, k, prev_str + "0")
    if len(str) == N:
        print(str)
    return ""


t = int(input())
for j in range(t):
    N, K = map(int, input().split())
    print("The bit patterns are")
    s(N, K, "")
    if j != t - 1:
        print()
