from collections import deque
import sys,re
sys.setrecursionlimit((1<<31)-1)
input=sys.stdin.readline
A=ord('A')
m=[[[]for _ in range(9)]for _ in range(10)]
c=[[-1]*9 for _ in range(10)]
q=deque()

for i in range(10):
    for j,s in enumerate(input().split()):
        if s.isdigit(): c[i][j]=int(s)
        else:
            for x in s.split('+'): m[i][j].append((ord(x[0])-A,int(x[1])-1))
            q.append((i,j))

v=[[0]*9 for _ in range(10)]
def dfs(x,y):
    if c[x][y]!=-1 or v[x][y]: return c[x][y]
    v[x][y]=1
    t=0
    for a,b in m[x][y]:
        r=dfs(a,b)
        if r==-1: t=-1; break
        t+=r
    c[x][y]=t
    return t

for x,y in q: dfs(x,y)

for r in c:
    print(*[str(x) if x!=-1 else '*' for x in r])
