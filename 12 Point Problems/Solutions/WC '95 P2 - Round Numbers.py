from math import comb as c
k=int(input())
b=bin(k)[2:]
n=len(b)
t=0
for l in range(2,n):
 t+=sum(c(l-1,j) for j in range((l-2)//2+1))
o,z=1,0
for i in range(1,n):
 if b[i]=='1':
  r=n-1-i
  t+=sum(c(r,j) for j in range((z+1+r-o)//2+1))
  o+=1
 else:z+=1
if z>=o:t+=1
print(f"There are {t} round numbers less than or equal to {k}.")
