m, n = int(input()), int(input())
a = [input() for _ in range(n)]
b = [input() for _ in range(n)]

stack = [("", "", 0, [])]
found = False

while stack:
    sa, sb, cnt, res = stack.pop()
    if sa == sb and sa:
        print(cnt)
        print(*res, sep="\n")
        found = True
        break
    if cnt + 1 >= m:
        continue
    for i in range(n-1, -1, -1):
        stack.append((sa + a[i], sb + b[i], cnt + 1, res + [i + 1]))

if not found:
    print("No solution.")
