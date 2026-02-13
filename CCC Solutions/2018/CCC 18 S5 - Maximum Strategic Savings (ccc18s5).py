N,M,P,Q=map(int,input().split())
es=[]
total=0
for _ in range(P):
    a,b,c=map(int,input().split())
    es.append([c,a,b,0])
    total+=c*N
for _ in range(Q):
    a,b,c=map(int,input().split())
    es.append([c,a,b,1])
    total+=c*M

hp=[i for i in range(M+1)]
hsz=[1]*(M+1)
vp=[i for i in range(N+1)]
vsz=[1]*(N+1)

es.sort()
r,c=N,M
res=0

for w,a,b,t in es:
    if t==0:
        xa,xb=a,b
        while hp[xa]!=xa: hp[xa]=hp[hp[xa]]; xa=hp[xa]
        while hp[xb]!=xb: hp[xb]=hp[hp[xb]]; xb=hp[xb]
        if xa!=xb:
            if hsz[xa]>hsz[xb]: hp[xb]=xa; hsz[xa]+=hsz[xb]
            else: hp[xa]=xb; hsz[xb]+=hsz[xa]
            res+=w*r
            c-=1
    else:
        xa,xb=a,b
        while vp[xa]!=xa: vp[xa]=vp[vp[xa]]; xa=vp[xa]
        while vp[xb]!=xb: vp[xb]=vp[vp[xb]]; xb=vp[xb]
        if xa!=xb:
            if vsz[xa]>vsz[xb]: vp[xb]=xa; vsz[xa]+=vsz[xb]
            else: vp[xa]=xb; vsz[xb]+=vsz[xa]
            res+=w*c
            r-=1

print(total-res)
