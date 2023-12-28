n = int(input())
def sumting(x): return True if x % 4 == 0 else False
print('Yes') if sumting(n) or sumting(n - 3) else print('No')
