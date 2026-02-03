a=[float(input()) for _ in range(int(input()))]
while 1:
    c=int(input())
    if c==77: break
    s=int(input())-1
    if c==99:
        p=int(input())
        x=a[s]
        a[s]=x*p/100
        a.insert(s+1,x*(100-p)/100)
    else:
        a[s]+=a[s+1]
        a.pop(s+1)
print(*[round(x) for x in a])
