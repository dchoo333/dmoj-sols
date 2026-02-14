s = input().strip()
c = int(input())
v = []
t = 0
i = 0
while i < len(s):
    ch = s[i]
    if ch.isalpha():
        j = i + 1
        n = 0
        while j < len(s) and s[j].isdigit():
            n = n * 10 + int(s[j])
            j += 1
        v.append((ch, n))
        t += n
        i = j
    else:
        i += 1

c %= t
for ch, n in v:
    if c < n:
        print(ch)
        break
    else:
        c -= n

