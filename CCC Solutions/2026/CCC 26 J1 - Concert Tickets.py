a, b, c = [int(input()) for _ in range(3)]
res = 'Y' if b-c >= a else 'N'
ans = str(b-c-a) if res == 'Y' else ''
print(res, ans)