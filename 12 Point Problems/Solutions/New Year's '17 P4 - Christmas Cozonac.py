import sys
r=sys.stdin.buffer.readline
n=int(r())
mp={};nm={}
for _ in range(n):
    t=r().split()
    k=t.index(b'=')
    v=sorted(hash(x) for x in t[1:k-1] if x!=b'+')
    h=hash(t[k+1])
    mp[hash(tuple(v))]=h;nm[h]=t[k+1]
c=int(r());o=[]
for _ in range(c):
    st=[[]]
    for x in r().split():
        if x==b'(':st.append([])
        elif x==b')':
            l=st.pop();l.sort();st[-1].append(mp[hash(tuple(l))])
        elif x!=b'+':st[-1].append(hash(x))
    o.append(nm[st[0][0]])
sys.stdout.write(b"\n".join(o).decode()+"\n")