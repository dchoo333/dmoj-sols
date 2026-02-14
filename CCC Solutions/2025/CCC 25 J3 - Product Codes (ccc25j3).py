n=int(input())
for _ in range(n):
    s=input()
    r=0
    o=''
    i=0
    while i<len(s):
        if s[i].isupper():
            o+=s[i]
            i+=1
        elif s[i]=='-'or s[i].isdigit():
            si=1
            if s[i]=='-':
                si=-1
                i+=1
            x=0
            while i<len(s) and s[i].isdigit():
                x=x*10+int(s[i])
                i+=1
            r+=si*x
        else:
            i+=1
    print(f"{o}{r}")
