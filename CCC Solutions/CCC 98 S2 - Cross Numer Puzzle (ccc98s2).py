print(*[x for x in range(1000,10000) if sum(i for i in range(1,x) if x%i==0)==x])
print(*[x for x in range(100,1001) if x==sum(int(c)**3 for c in str(x))])
