b = [461, 431, 420, 0]
s = [100, 57, 70, 0]
d = [130, 160, 118, 0]
e = [167, 266, 75, 0]

x, y, z, w = [int(input()) for _ in range(4)]

print(
    "Your total Calorie count is " +
    str(b[x-1] + s[y-1] + d[z-1] + e[w-1]) +
    "."
)
