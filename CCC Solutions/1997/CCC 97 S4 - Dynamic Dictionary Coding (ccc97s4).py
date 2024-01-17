for _ in range(int(input())):
    c, v = 1, {}
    while True:
        line = input().split()
        if not line: print(""); break

        for i in range(len(line)):
            if line[i] in v: line[i] = v[line[i]]
            elif line[i] not in v: v[line[i]] = str(c); c += 1

        print(" ".join(line))