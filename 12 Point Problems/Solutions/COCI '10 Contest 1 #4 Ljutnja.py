m,n=map(int,input().split())
a=sorted(int(input()) for _ in range(n))
k=sum(a)-m
t=0
for i in range(n):
 c=n-i
 if a[i]*c<k:
  t+=a[i]*a[i];k-=a[i]
 else:
  q,r=divmod(k,c)
  t+=r*(q+1)**2+(c-r)*q*q
  break
print(t%2**64)