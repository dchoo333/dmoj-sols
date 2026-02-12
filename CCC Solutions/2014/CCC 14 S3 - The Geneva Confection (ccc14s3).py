t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(input()) for _ in range(n)]
    
    b = []
    need = 1
    i = n - 1
    
    while i >= 0 or b:
        if i >= 0 and a[i] == need:
            need += 1
            i -= 1
        elif b and b[-1] == need:
            need += 1
            b.pop()
        elif i >= 0:
            b.append(a[i])
            i -= 1
        else:
            break
    
    print("Y" if need == n + 1 else "N")
