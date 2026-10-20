from bisect import bisect_left, bisect_right

for _ in range(int(input())):
    s = input()
    loc = [[] for _ in range(5)]
    m = "bruce"
    for i, ch in enumerate(s):
        if ch in m:
            loc[m.index(ch)].append(i)
    best = float("inf")
    for mid in range(5):
        for center in loc[mid]:
            cs = [[] for _ in range(5)]
            cs[mid].append(center)
            for i in range(5):
                if i == mid: continue
                if loc[i] and loc[i][0] < center:
                    lft = bisect_left(loc[i], center) - 1
                    cs[i].append(loc[i][lft])
                if loc[i] and loc[i][-1] > center:
                    rgt = bisect_right(loc[i], center)
                    cs[i].append(loc[i][rgt])
            r = [[]]
            for c in cs:
                if not c:
                    r = []
                    break
                if len(c) == 1:
                    r = [x + [c[0]] for x in r]
                else:
                    r = [x + [c[0]] for x in r] + [x + [c[1]] for x in r]
            for p in r:
                inv_count = sum(sum(p[j] > p[i] for j in range(i)) for i in range(len(p)))
                c = p[mid]
                left = right = 1
                cost = 0
                for x in p:
                    if x == c: continue
                    if x < c:
                        cost += c - x - left
                        left += 1
                    else:
                        cost += x - c - right
                        right += 1
                best = min(best, inv_count + cost)
    print(best)