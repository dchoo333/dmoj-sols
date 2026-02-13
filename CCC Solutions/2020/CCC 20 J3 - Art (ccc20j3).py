n=int(input())
x=[];y=[]
for _ in range(n):
    a,b=map(int,input().split(','))
    x.append(a);y.append(b)
print(f"{min(x)-1},{min(y)-1}")
print(f"{max(x)+1},{max(y)+1}")