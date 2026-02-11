m=int(input())
t={}
for _ in range(m):
    x,y=input().split()
    t[y]=x

s=input()
i=0
res=[]

while i<len(s):
    j=i+1
    while j<=len(s) and s[i:j] not in t:
        j+=1
    res.append(t[s[i:j]])
    i=j

print(''.join(res))
