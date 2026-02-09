n=int(input())
for _ in range(n):
    l=[input() for _ in range(3)]
    y=True
    for i,s in enumerate(l):
        for j,t in enumerate(l):
            if i==j: continue
            m=len(t)
            if m<=len(s) and (s[:m]==t or s[-m:]==t):
                y=False
                break
        if not y: break
    print('Yes' if y else 'No')
