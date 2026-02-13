p = int(input())
n = int(input())

d = sorted(map(int, input().split()))
g = sorted(map(int, input().split()), reverse=(p == 2))

print(sum(max(d[i], g[i]) for i in range(n)))
