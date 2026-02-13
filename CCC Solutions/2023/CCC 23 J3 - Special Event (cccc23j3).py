n = int(input())
a = [input() for _ in range(n)]
c = [sum(p[i]=='Y' for p in a) for i in range(5)]
print(','.join(str(i+1) for i,v in enumerate(c) if v==max(c)))
