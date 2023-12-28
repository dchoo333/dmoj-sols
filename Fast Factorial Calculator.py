mod = 2**32
fact = [-1 for i in range(129)]

def factorial(v):
    factv=1
    
    for i in range(2,v+1):
        factv=(factv*i)%mod
    
    return factv
        

for i in range(int(input())):
    n = int(input())
    
    if n >= 128: 
        print(0)
    else: 
        print(factorial(n))
