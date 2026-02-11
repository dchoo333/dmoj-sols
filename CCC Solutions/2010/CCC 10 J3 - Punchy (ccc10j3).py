a=b=0
o=[]

while 1:
    l=input().split()
    c=l[0]
    if c=='7': break

    if c=='1':
        if l[1]=='A': a=int(l[2])
        else: b=int(l[2])

    elif c=='2':
        o.append(a if l[1]=='A' else b)

    else:
        x = a if l[2]=='A' else b
        if l[1]=='A':
            if c=='3': a+=x
            elif c=='4': a*=x
            elif c=='5': a-=x
            else: a//=x
        else:
            if c=='3': b+=x
            elif c=='4': b*=x
            elif c=='5': b-=x
            else: b//=x

print(*o, sep='\n')
