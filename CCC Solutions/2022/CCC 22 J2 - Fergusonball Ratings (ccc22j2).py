n=int(input())
c=0
for _ in range(n):
    a=int(input())
    b=int(input())
    if a*5-b*3>40: c+=1
print(f'{c}+' if c==n else c)
