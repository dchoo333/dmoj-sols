n = int(input())
for _ in range(n):
    x = input()
    print(' '.join('****' if len(w) == 4 else w for w in x.split()))
