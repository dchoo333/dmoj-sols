n = int(input())
a = input().split()
b = input().split()

if n % 2:
    print("bad")
else:
    s = set()
    ok = True
    
    for i in range(n):
        if a[i] == b[i]:
            ok = False
            break
        pair = tuple(sorted((a[i], b[i])))
        s.add(pair)
    
    if ok and len(s) == n // 2:
        print("good")
    else:
        print("bad")
