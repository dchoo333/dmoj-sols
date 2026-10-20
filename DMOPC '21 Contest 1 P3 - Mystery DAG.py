import sys
n,m=map(int,input().split())
e=[tuple(map(int,input().split())) for _ in range(m)]
got=[set() for _ in range(10)]
for b in range(10):
    A=[x for x in range(1,n+1) if not x>>b&1];B=[x for x in range(1,n+1) if x>>b&1]
    if not A or not B:continue
    print("?",len(A),len(B));print(*A);print(*B);sys.stdout.flush()
    r=list(map(int,input().split()))
    if r and r[0]==-1:sys.exit()
    got[b]=set(r[1:])
s=[]
for i,(u,v) in enumerate(e,1):
    b=((u^v)&-(u^v)).bit_length()-1
    t=u if (i in got[b])==(not u>>b&1) else v
    h=u+v-t
    s.append('1' if t>h else '0')
print("!","".join(s));sys.stdout.flush()
