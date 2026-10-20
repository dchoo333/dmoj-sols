def func():
    N, X = map(int, input().split())
    
    if N == 1:
        print("0")
        return
    
    M = None
    for m in range(N >> 1, N):
        S = m * (m + 1) >> 1
        tlo = N - m
        thi = m + 1
        nl = tlo - X
        nh = thi - X
        vlo = nl if nl > -S else -S
        vhi = nh if nh < S else S
        if vlo > vhi:
            continue
        if vhi - vlo >= 1 or (S - vlo) & 1 == 0:
            M = m
            break
    
    if M is None or M == 0:
        print("0\n")
        return
    
    tlo = N - M
    thi = M + 1
    
    def can_reach(pos, r):
        """Can we reach [tlo,thi] from pos using {1,...,r}?"""
        if r <= 0:
            return tlo <= pos <= thi
        S_r = r * (r + 1) >> 1
        nl2 = tlo - pos
        nh2 = thi - pos
        vlo2 = nl2 if nl2 > -S_r else -S_r
        vhi2 = nh2 if nh2 < S_r else S_r
        if vlo2 > vhi2:
            return False
        if vhi2 - vlo2 >= 1:
            return True
        return (S_r - vlo2) & 1 == 0
    
    # Check if k=M can be used first from pos=X
    first_ok = (1 <= X + M <= N and can_reach(X + M, M - 1)) or \
               (1 <= X - M <= N and can_reach(X - M, M - 1))
    swap = not first_ok and M >= 2
    
    pos = X
    out = [M]
    
    def dst(k, r):
        nonlocal pos
        np1 = pos + k
        if np1 <= N and can_reach(np1, r):
            out.append(k)
            pos = np1
            return True
        np2 = pos - k
        if np2 >= 1 and can_reach(np2, r):
            out.append(-k)
            pos = np2
            return True
        return False
    
    if not swap:
        for k in range(M, 0, -1):
            dst(k, k - 1)
    else:
        dst(M - 1, M)
        dst(M, M - 2)
        for k in range(M - 2, 0, -1):
            dst(k, k - 1)
    
    print("\n".join(map(str, out)))

func()