n = int(input())
s = input().strip()

p = [0] * n
for i in range(1, n):
    k = p[i - 1]
    while k and s[i] != s[k]: k = p[k - 1]
    if s[i] == s[k]: k += 1
    p[i] = k

c = [0] * (n + 1)
for v in p: c[v] += 1
for l in range(n, 0, -1): c[p[l - 1]] += c[l]
for l in range(1, n + 1): c[l] += 1

r = 0
l = n
while l:
    r += c[l]
    l = p[l - 1]
print(r)