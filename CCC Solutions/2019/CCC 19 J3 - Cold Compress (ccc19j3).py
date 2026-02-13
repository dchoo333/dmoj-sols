for _ in range(int(input())):
    s=input()+"`"; out=[]; cnt=0; last=s[0]
    for x in s:
        if x==last: cnt+=1
        else: out+=[str(cnt),last]; cnt=1; last=x
    print(" ".join(out))
