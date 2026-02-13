import math

for _ in range(int(input())):
    a=int(input())*2
    for x in range(3,a,2):
        p=True
        for i in range(2,int(math.sqrt(x))+1):
            if x%i==0: p=False; break
        if not p: continue
        y=a-x
        p=True
        for i in range(2,int(math.sqrt(y))+1):
            if y%i==0: p=False; break
        if p:
            print(x,y)
            break
