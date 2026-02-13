n = int(input())
v = sorted(int(input()) for _ in range(n))

mn = float('inf')
for i in range(1, n-1):
    d = (v[i+1] - v[i-1])/2
    if d < mn:
        mn = d

print(f"{mn:.1f}")
