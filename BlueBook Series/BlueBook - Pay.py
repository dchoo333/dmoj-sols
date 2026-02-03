N = int(input())
res = []
taxes = {'A':0,'B':10,'C':20,'D':29,'E':35}

for t in range(N):
    if t: input()
    r = float(input())
    h = int(input())
    c = input()
    d = input()
    
    s = h*r if h <= 40 else 40*r + 2*(h-40)*r
    s -= s * taxes[c]/100
    if d == 'y': s -= 10
    res.append(f"{s:.2f}")

print('\n'.join(res))
