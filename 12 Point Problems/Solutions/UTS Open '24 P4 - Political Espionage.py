import sys
sys.setrecursionlimit(10000)
n=int(input())
T={0:0}
def t(s):
 if s not in T:
  a=(s-1)//2
  
  T[s]=2*(t(a)+t(s-1-a))+1
 return T[s]
r=[0]*n
def f(l,s):
 if s:
  a=(s-1)//2
  
  r[l+a]=t(a)+t(s-1-a)+1
  f(l,a);f(l+a+1,s-1-a)
f(0,n)
print(*r)
