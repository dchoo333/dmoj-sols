r, c = int(input()), int(input())
g = [list(input()) for _ in range(r)]
walls = {(i, j) for i in range(r) for j in range(c) if g[i][j] == 'X'}

m = int(input())
ins = [input().strip() for _ in range(m)]

dirs = {'U':(-1,0),'D':(1,0),'L':(0,-1),'R':(0,1)}
L = {'U':'L','L':'D','D':'R','R':'U'}
R = {'U':'R','R':'D','D':'L','L':'U'}

def build(d):
    x = y = 0
    path = {(0,0)}
    t = b = l = r_ = 0
    for s in ins:
        if s == 'F':
            dx, dy = dirs[d]
            x += dx; y += dy
            path.add((x,y))
            t = min(t,x); b = max(b,x)
            l = min(l,y); r_ = max(r_,y)
        elif s == 'L': d = L[d]
        else: d = R[d]
    return (x,y), path, (t,b,l,r_)

paths = [build(d) for d in "UDLR"]

for i in range(r):
    for j in range(c):
        if g[i][j] == 'X': 
            continue
        for (fx,fy), path, (t,b,l,r_) in paths:
            if i+t < 0 or i+b >= r or j+l < 0 or j+r_ >= c:
                continue
            if any((i+x, j+y) in walls for x,y in path):
                continue
            g[i+fx][j+fy] = '*'

for row in g:
    print(''.join(row))
