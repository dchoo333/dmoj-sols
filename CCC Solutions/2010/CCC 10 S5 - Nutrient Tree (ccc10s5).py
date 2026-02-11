r={'v':0,'l':None,'r':None,'m':[]}
s=input()
if '(' not in s:
    r['v']=int(s)
else:
    s=s[1:-1]
    st=[r]
    i=0
    while i<len(s):
        while i<len(s) and s[i]==' ': i+=1
        start=i
        if i>=len(s): break
        if s[start] not in '()':
            while i+1<len(s) and s[i+1] not in '( )': i+=1
        p=st[-1]
        if s[start]!=')':
            if p['l'] is None:
                p['l']={'v':-1,'l':None,'r':None,'m':[]}
                st.append(p['l'])
            else:
                p['r']={'v':-1,'l':None,'r':None,'m':[]}
                st.append(p['r'])
            if s[start]!='(':
                st[-1]['v']=int(s[start:i+1])
                st.pop()
        else:
            st.pop()
        i+=1

if r['v']!=0:
    X=int(input())
    print(r['v']+X)
else:
    X=int(input())+1
    lvl=[]
    q=[r]
    while q:
        sz=len(q)
        lvl.insert(0,q[:sz])
        q=q[sz:]
        for x in lvl[0]:
            if x['l']: q.append(x['l'])
            if x['r']: q.append(x['r'])
    for i in range(len(lvl)):
        for j in range(len(lvl[i])):
            n=lvl[i][j]
            if n['l'] is None and n['r'] is None:
                n['m']=list(range(n['v'],n['v']+X))
            else:
                lT,rT=[1]*X,[1]*X
                nv,ef,ca=0,1,0
                while ca<X:
                    f=ef**2
                    val=n['l']['m'][nv]
                    if val<=f:
                        nv+=1
                        lT[ca]=val
                    else:
                        ef+=1
                        lT[ca]=f
                    ca+=1
                nv,ef,ca=0,1,0
                while ca<X:
                    f=ef**2
                    val=n['r']['m'][nv]
                    if val<=f:
                        nv+=1
                        rT[ca]=val
                    else:
                        ef+=1
                        rT[ca]=f
                    ca+=1
                n['m']=[0]*X
                p1,p2=0,X-1
                for k in range(X):
                    a,b=0,k
                    maxv=0
                    while a<=k and b>=0:
                        maxv=max(maxv,lT[a]+rT[b])
                        a+=1
                        b-=1
                    n['m'][k]=maxv
    print(max(r['m']))