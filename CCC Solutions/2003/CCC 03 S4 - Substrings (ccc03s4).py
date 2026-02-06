for _ in range(int(input())):
    s = input()
    n = len(s)
    sa = sorted(range(n), key=lambda i: s[i:])
    lcp = [0]*n
    rank = [0]*n
    for i,v in enumerate(sa):
        rank[v] = i
    h = 0
    for i in range(n):
        if rank[i]:
            j = sa[rank[i]-1]
            while i+h<n and j+h<n and s[i+h]==s[j+h]:
                h+=1
            lcp[rank[i]] = h
            if h: h-=1
    print(1 + n*(n+1)//2 - sum(lcp))
