a = int(input())
count = 0

while count < a:
    b = int(input())
    c = int(input())
    d = int(input())

    x = [input() for _ in range(b)]
    y = [input() for _ in range(c)]
    z = [input() for _ in range(d)]

    for j in range(b):
        for k in range(c):
            for s in range(d):
                print(x[j] + " " + y[k] + " " + z[s] + ".")
    
    count += 1
