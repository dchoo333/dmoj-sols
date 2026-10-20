def ev(e,x):
    t,i=[],0
    while i<len(e):
        c=e[i]
        if c.isdigit():
            j=i
            while j<len(e) and e[j].isdigit(): j+=1
            t.append(int(e[i:j]))
            i=j
        elif c=='x':
            t.append(x)
            i+=1
        else:
            t.append(c)
            i+=1

    p,st=[],[]
    pr={'+':1,'-':1,'*':2}
    for k in t:
        if type(k)==int: p.append(k)
        elif k=='(': st.append(k)
        elif k==')':
            while st and st[-1]!='(': p.append(st.pop())
            st.pop()
        else:
            while st and st[-1]!='(' and st[-1] in pr and pr[st[-1]]>=pr[k]: p.append(st.pop())
            st.append(k)
    while st: p.append(st.pop())

    s=[]
    for k in p:
        if type(k)==int: s.append(k)
        else:
            b,a=s.pop(),s.pop()
            if k=='+': s.append(a+b)
            elif k=='-': s.append(a-b)
            else: s.append(a*b)
    return s[0]

d=input().split()
if len(d)==1: d+=input().split()
e,p,m=d[0],int(d[1]),int(d[2])
b=ev(e,0)%m
a=(ev(e,1)%m-b)%m
for x in range(m):
    if (a*x+b)%m==p:
        print(x)
        break