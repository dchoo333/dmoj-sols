trout, pike, pickerel, total, count = int(input()), int(input()), int(input()), int(input()), 0
for i in range(total+1):
    for j in range(total+1):
        for k in range(total+1):
            if (i*trout) + (j*pike) + (k*pickerel) <= total and i+j+k > 0:
                print(f"{i} Brown Trout, {j} Northern Pike, {k} Yellow Pickerel")
                count += 1
print(f"Number of ways to catch fish: {count}")
