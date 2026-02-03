a = 0
b = 0
c = [input().strip() for _ in range(52)]
vals = {"jack": 1, "queen": 2, "king": 3, "ace": 4}

for i in range(52):
    v = vals.get(c[i], 0)
    j = i + 1
    while j <= i + v and j < 52:
        if c[j] in vals:
            break
        j += 1
    if v and j == i + v + 1:
        if i % 2 == 0:
            print("Player A scores " + str(v) + " point(s).")
            a += v
        else:
            print("Player B scores " + str(v) + " point(s).")
            b += v

print("Player A: " + str(a) + " point(s).")
print("Player B: " + str(b) + " point(s).")
