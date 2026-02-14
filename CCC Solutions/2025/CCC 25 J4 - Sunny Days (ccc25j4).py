n=int(input())
a=[input() for _ in range(n)]
l=0
p=0
m=0

for r in range(n):
    if a[r]=='P':
        p+=1
    while p>1:
        if a[l]=='P':
            p-=1
        l+=1
    m=max(m,r-l+1)

if p==0:
    print(n-1)
else:
    print(m)