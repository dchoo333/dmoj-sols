books = {}
n = int(input())
vis = [1]

for i in range(1,n+1):
    opts = input()
    if opts == "0":
        books[i] = -1
    else:
        p = [int(x) for x in opts.split()]
        books[i] = p[1:]
        for y in p[1:]:
            if y != i:
                vis.append(y)

def func(b):
    cnt = 1
    q = [1]
    while len(q) > 0:
        for _ in range(len(q)):
            node = q[0]
            for y in b[node]:
                if b[y]==-1:
                    return cnt+1
                else:
                    q.append(y)
            q.pop(0)
        cnt += 1

print("Y" if len(set(vis))==n else "N")
print(func(books))
