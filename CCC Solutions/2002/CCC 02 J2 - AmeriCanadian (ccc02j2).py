res = []

while True:
    w = input()
    if w == "quit!":
        break

    if len(w) > 3 and w[-2:] == "or" and w[-3] not in "aeiouy":
        res.append(w[:-2] + "our")
    else:
        res.append(w)

for w in res:
    print(w)
