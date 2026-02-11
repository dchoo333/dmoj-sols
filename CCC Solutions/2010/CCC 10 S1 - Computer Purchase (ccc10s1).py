n=int(input())
m=[]

for _ in range(n):
    s=input().split()
    m.append((-(int(s[1])*2+int(s[2])*3+int(s[3])),s[0]))

if m:
    a=sorted(m)
    print(a[0][1])
    if len(a)>1:
        print(a[1][1])
