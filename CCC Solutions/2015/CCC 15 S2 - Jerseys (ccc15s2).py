j = int(input())
a = int(input())
ss = [0] + [input().strip() for _ in range(j)]
cnt = 0
for _ in range(a):
    s, num = input().split()
    num = int(num)
    if ss[num] <= s:
        cnt += 1
        ss[num] = 'Z'
print(cnt)
