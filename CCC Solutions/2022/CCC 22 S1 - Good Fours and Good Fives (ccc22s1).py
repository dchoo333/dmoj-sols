n = int(input())
print(sum((n-4*x)%5==0for x in range(n//4+1)))