n=int(input())
for _ in range(n):
    s=input()
    m=True
    while m:
        m=False
        for i,c in enumerate(s):
            if c=='X':
                s=s[:i]+'x'+s[i+1:]
                m=True
                if s[i-2]==')':
                    b=1
                    for k in range(i-3,-1,-1):
                        if s[k]==')':b+=1
                        if s[k]=='(':b-=1
                        if b==0:
                            s=s[:k]+'('+s[k:]
                            break
                else:
                    for k in range(i-2,-1,-1):
                        if s[k]==' ':
                            s=s[:k+1]+'('+s[k+1:]
                            break
                    else:
                        s='('+s
                if i+3<len(s) and s[i+3]=='(':
                    b=1
                    for k in range(i+4,len(s)):
                        if s[k]=='(':b+=1
                        if s[k]==')':b-=1
                        if b==0:
                            s=s[:k+1]+')'+s[k+1:]
                            break
                else:
                    for k in range(i+3,len(s)):
                        if s[k]==' ':
                            s=s[:k]+')'+s[k:]
                            break
                    else:
                        s+=')'
                break
    a=True
    while a:
        a=False
        for i,c in enumerate(s):
            if c in '+-':
                a=True
                s=s[:i]+('=' if c=='+' else '_')+s[i+1:]
                if s[i-2]==')':
                    b=1
                    for k in range(i-3,-1,-1):
                        if s[k]==')':b+=1
                        if s[k]=='(':b-=1
                        if b==0:
                            s=s[:k]+'('+s[k:]
                            break
                else:
                    for k in range(i-2,-1,-1):
                        if s[k]==' ':
                            s=s[:k+1]+'('+s[k+1:]
                            break
                    else:
                        s='('+s
                if i+3<len(s) and s[i+3]=='(':
                    b=1
                    for k in range(i+4,len(s)):
                        if s[k]=='(':b+=1
                        if s[k]==')':b-=1
                        if b==0:
                            s=s[:k+1]+')'+s[k+1:]
                            break
                else:
                    for k in range(i+3,len(s)):
                        if s[k]==' ':
                            s=s[:k]+')'+s[k:]
                            break
                    else:
                        s+=')'
                break
    s=s.replace('=','+').replace('_','-').replace('x','X')
    print(s[1:-1],end='\n\n' if _!=n-1 else '\n')
