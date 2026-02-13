m, s, p = [int(input()) for _ in range(3)]
d=0
i=s
t=0
while t<=m:
    t+=i
    i*=p
    d+=1
print(d-1)
