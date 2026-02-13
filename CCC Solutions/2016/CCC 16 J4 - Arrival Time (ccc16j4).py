h, m = map(int, input().split(":"))
t = h * 60 + m
d = 120

while d:
    if 420 <= t < 600 or 900 <= t < 1140:
        t += 2
    else:
        t += 1
    d -= 1

t %= 1440
print(f"{t//60:02d}:{t%60:02d}")
