a,b,c,d=map(int,input().split())

w1=a+c
h1=max(b,d)
p1=2*(w1+h1)

w2=max(a,c)
h2=b+d
p2=2*(w2+h2)

print(min(p1,p2))
