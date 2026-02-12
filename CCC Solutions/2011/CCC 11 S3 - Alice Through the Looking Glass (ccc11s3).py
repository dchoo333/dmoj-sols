for _ in range(int(input())):
    m,x,y=map(int,input().split())
    while True:
        s=5**(m-1)
        cx,cy=x//s,y//s
        if (cy==0 and cx in [1,2,3]) or (cx==2 and cy==1):
            print("crystal")
            break
        if cx in [0,4] or cy in [3,4] or (cx==1 and cy==2) or (cx==3 and cy==2):
            print("empty")
            break
        if (cx in [1,3] and cy==1) or (cx==2 and cy==2):
            if m==1:
                print("empty")
                break
            x%=s
            y%=s
            m-=1
