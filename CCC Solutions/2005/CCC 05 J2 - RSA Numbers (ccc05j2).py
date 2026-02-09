a, b = [int(input()) for _ in range(2)]
c=sum(1 for i in range(a,b+1) if sum(1 for t in range(1,i+1) if i%t==0)==4)
print(f"The number of RSA numbers between {a} and {b} is {c}")
