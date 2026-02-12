m, d = [int(input()) for _ in range(2)]

if m > 2: 
    print("After") 
elif m < 2: 
    print("Before") 
elif d > 18: 
    print("After") 
elif d < 18: 
    print("Before") 
else: 
    print("Special")
