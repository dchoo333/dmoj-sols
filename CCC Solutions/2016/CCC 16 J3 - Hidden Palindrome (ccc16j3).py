s = input()
n = len(s)
ans = 0

for i in range(n):
    for j in range(i, n):
        sub = s[i:j+1]
        if sub == sub[::-1]:
            ans = max(ans, j - i + 1)

print(ans)
