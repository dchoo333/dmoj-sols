n=int(input())
a=list(map(int,input().split()))
r=0
b=[]
i=0
while i<n:
    j=i
    while j+1<n and a[j+1]<a[j]:j+=1
    if j>i:r+=1
    b+=a[i:j+1][::-1]
    i=j+1
t=[0]*(n+1)
for k,x in enumerate(b):
    c=0
    y=x
    while y:
        c+=t[y]
        y-=y&-y
    r+=k-c
    y=x
    while y<=n:
        t[y]+=1
        y+=y&-y
print(r)