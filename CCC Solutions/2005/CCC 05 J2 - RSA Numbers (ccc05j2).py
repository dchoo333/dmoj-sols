def rsa(n):
    f = 0
    for t in range(1, n+1):
        if n % t == 0:
            f += 1
    if f == 4:
        return True
    return False
a = int(input())
b = int(input())
count = 0
for i in range(a, b+1):
    if rsa(i):
        count += 1
print("The number of RSA numbers between " + str(a) + " and " + str(b) + " is " + str(count))
