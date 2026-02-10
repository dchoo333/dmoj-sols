t, p, pk, tot, cnt = int(input()), int(input()), int(input()), int(input()), 0

for i in range(tot + 1):
    for j in range(tot + 1):
        for k in range(tot + 1):
            if (i * t) + (j * p) + (k * pk) <= tot and i + j + k > 0:
                print(f"{i} Brown Trout, {j} Northern Pike, {k} Yellow Pickerel")
                cnt += 1

print(f"Number of ways to catch fish: {cnt}")
