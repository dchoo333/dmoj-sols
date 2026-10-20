n=int(input())
v=input().split()
c=[0]*(2*n+3)
p=n+1;c[p]=1;l=0;r=0
for x in v:
    if x=='1':l+=c[p];p+=1
    else:p-=1;l-=c[p]
    r+=l;c[p]+=1
print(r)