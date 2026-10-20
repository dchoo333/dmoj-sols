d,c,e,p,n=input().split()
d,c,e,p,n=float(d),float(c),float(e),float(p),int(float(n))
s=[(0.0,p)]
for _ in range(n):
 x,y=map(float,input().split())
 if x<=d:s.append((x,y))
s.sort()
s.append((d,0.0))
m=c*e
if any(s[i+1][0]-s[i][0]>m for i in range(len(s)-1)):
 print("No Solution")
else:
 i=0;f=0.0;t=0.0
 while i<len(s)-1:
  k=None;b=None
  for j in range(i+1,len(s)):
   if s[j][0]-s[i][0]>m:break
   if s[j][1]<s[i][1]:k=j;break
   if b is None or s[j][1]<s[b][1]:b=j
  if k is not None:
   g=s[k][0]-s[i][0]
   if f<g:t+=(g-f)/e*s[i][1];f=g
   f-=g;i=k
  else:
   t+=(m-f)/e*s[i][1]
   f=m-(s[b][0]-s[i][0]);i=b
 print("%.2f"%t)