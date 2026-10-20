import sys
n=int(input())
if n==1:
    print(0,flush=True);sys.exit()
print(1,1,flush=True)
v=int(input())
a=[1]
for j in range(1,n):
    print(1,j+1,flush=True)
    w=int(input());d=w-v;v=w
    x=a[0];c=(abs(d)-1)//2
    r=x+c+1 if d>0 else x-c
    a=[t+1 if t>=r else t for t in a]
    a.append(r)
    a[0],a[j]=a[j],a[0]
for i in range(n):
    while a[i]!=i+1:
        k=a[i]-1
        print(i+1,k+1,flush=True)
        input()
        a[i],a[k]=a[k],a[i]
print(0,flush=True)