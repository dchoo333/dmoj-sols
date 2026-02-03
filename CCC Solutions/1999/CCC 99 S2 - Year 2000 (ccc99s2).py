import re

n = int(input())
mos = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]

for _ in range(n):
    s = input()
    ma = list(re.finditer(r"\w+/\w+/\w+", s))
    for m in reversed(ma):
        t = m.group().split("/")
        r = m.group()
        if len(t) == 3 and len(t[0]) == 2 and len(t[1]) == 2 and len(t[2]) == 2:
            try:
                if 1 <= int(t[0]) <= 31 and 1 <= int(t[1]) <= 12:
                    y = int(t[2])
                    t[2] = "19" + t[2] if y >= 25 else "20" + t[2]
                    r = t[0] + "/" + t[1] + "/" + t[2]
            except:
                pass
        s = s[:m.start()] + r + s[m.end():]

    ma = list(re.finditer(r"\w+[.]\w+[.]\w+", s))
    for m in reversed(ma):
        t = m.group().split(".")
        r = m.group()
        if len(t) == 3 and len(t[0]) == 2 and len(t[1]) == 2 and len(t[2]) == 2:
            try:
                if 1 <= int(t[2]) <= 31 and 1 <= int(t[1]) <= 12:
                    y = int(t[0])
                    t[0] = "19" + t[0] if y >= 25 else "20" + t[0]
                    r = t[0] + "." + t[1] + "." + t[2]
            except:
                pass
        s = s[:m.start()] + r + s[m.end():]

    ma = list(re.finditer(r"\w+\s\w+,\s\w+", s))
    for m in reversed(ma):
        t = re.split(r"\s|,\s", m.group())
        r = m.group()
        if len(t) == 3 and t[0] in mos and len(t[1]) == 2 and len(t[2]) == 2:
            try:
                if 1 <= int(t[1]) <= 31:
                    y = int(t[2])
                    t[2] = "19" + t[2] if y >= 25 else "20" + t[2]
                    r = t[0] + " " + t[1] + ", " + t[2]
            except:
                pass
        s = s[:m.start()] + r + s[m.end():]

    print(s)
