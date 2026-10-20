import sys
from math import gcd, isqrt, log10, floor

def lcm(a, b):
    return a // gcd(a, b) * b

def out(num, den, D):
    if num == 0 or D == 0:
        print(-1); return
    
    P = num * num * D 
    
    import math
    Tf = math.sqrt(float(P)) / float(den)
    if Tf <= 0:
        print(-1); return
    
    log10_T = math.log10(Tf)
    exp = int(floor(log10_T))
    
    shift = 5 - exp
    
    if shift >= 0:
        P2 = P * (10 ** (2 * shift))
        sq = isqrt(P2)
        result = sq // den
    else:
        new_den = den * (10 ** (-shift))
        sq = isqrt(P)
        result = sq // new_den
    
    s = str(result)
    if len(s) < 6:
        result *= 10 ** (6 - len(s))
        s = str(result)
    if len(s) > 6:
        s = s[:6]
    
    print(s)

def func():
    W, H =  map(int, input().split())
    w, h =  map(int, input().split())
    x0, y0 = map(int, input().split())
    dx, dy = map(int, input().split())
    
    A = W - w
    B = H - h
    adx, ady = abs(dx), abs(dy)
    D = dx*dx + dy*dy
    
    if adx == 0 and ady == 0:
        print(-1); return
    
    if adx == 0:
        if B == 0: print(-1); return
        out(2*B, 1, 1)
        return
    
    if ady == 0:
        if A == 0: print(-1); return
        out(2*A, 1, 1)
        return
    
    if A == 0 and B == 0:
        print(-1); return
    
    if A == 0:
        g = gcd(2*B, ady)
        out((2*B)//g, ady//g, D)
        return
    
    if B == 0:
        g = gcd(2*A, adx)
        out((2*A)//g, adx//g, D)
        return

    g1 = gcd(2*A, adx)
    p1, q1 = (2*A)//g1, adx//g1
    g2 = gcd(2*B, ady)
    p2, q2 = (2*B)//g2, ady//g2 
    L_num = lcm(p1, p2)
    L_den = gcd(q1, q2)
    g = gcd(L_num, L_den)
    L_num //= g; L_den //= g
    
    out(L_num, L_den, D)

func()