a = [["a","b","c"],["d","e","f"],["g","h","i"],["j","k","l"],["m","n","o"],["p","q","r","s"],["t","u","v"],["w","x","y","z"]]
r = []

while True:
    s = input()
    if s == "halt":
        break
    p = -1
    t = 0
    for c in s:
        for i in range(8):
            if c in a[i]:
                if p == i:
                    t += 2
                t += a[i].index(c) + 1
                p = i
                break
    r.append(t)

for x in r:
    print(x)
