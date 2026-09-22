n, l, q = [int(input()) for _ in range(3)]
lated = [0] * (n+2)
for _ in range(l):
    P, S = map(int, input().split())
    left = max(1, P-S)
    right = min(n, P+S)
    lated[left] += 1
    lated[right+1] -= 1
    
for i in range(1, n+1):
    lated[i] += lated[i-1]
for _ in range(q):
    spot = int(input())
    print('Y' if lated[spot] > 0 else 'N')