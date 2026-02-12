n = int(input())
t = 1

r = {}
s = {}
m = {}

for _ in range(n):
    a, x = input().split()
    x = int(x)
    
    if a == "W":
        t += x - 1
    
    elif a == "R":
        r[x] = r.get(x, 0) + t
        m[x] = m.get(x, 0) + 1
        t += 1
    
    elif a == "S":
        s[x] = s.get(x, 0) + t
        m[x] = m.get(x, 0) + 1
        t += 1

for k in sorted(r):
    w = s[k] - r[k] if m[k] % 2 == 0 else -1
    print(str(k) + " " + str(w))
