import random, math

def dist(p1, p2):
    return math.hypot(p1[0]-p2[0], p1[1]-p2[1])

def circle_from(p1, p2):
    cx = (p1[0] + p2[0])/2
    cy = (p1[1] + p2[1])/2
    r = dist(p1,p2)/2
    return (cx, cy, r)

def circle_from3(p1, p2, p3):
    A = p2[0]-p1[0]
    B = p2[1]-p1[1]
    C = p3[0]-p1[0]
    D = p3[1]-p1[1]
    E = A*(p1[0]+p2[0]) + B*(p1[1]+p2[1])
    F = C*(p1[0]+p3[0]) + D*(p1[1]+p3[1])
    G = 2*(A*(p3[1]-p2[1]) - B*(p3[0]-p2[0]))
    if G == 0:
        pairs = [(p1,p2),(p1,p3),(p2,p3)]
        pmax = max(pairs, key=lambda pair: dist(pair[0],pair[1]))
        return circle_from(pmax[0],pmax[1])
    cx = (D*E - B*F)/G
    cy = (A*F - C*E)/G
    r = dist((cx,cy), p1)
    return (cx, cy, r)

def welzl(P, R):
    if not P or len(R) == 3:
        if len(R) == 0:
            return (0,0,0)
        elif len(R) == 1:
            return (R[0][0], R[0][1], 0)
        elif len(R) == 2:
            return circle_from(R[0], R[1])
        else:
            return circle_from3(R[0], R[1], R[2])
    p = P.pop()
    d = welzl(P, R)
    if dist((d[0], d[1]), p) <= d[2]:
        P.append(p)
        return d
    R.append(p)
    res = welzl(P, R)
    R.pop()
    P.append(p)
    return res

n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]
random.shuffle(points)
c = welzl(points[:], [])

print(f"{2*c[2]:.2f}")
