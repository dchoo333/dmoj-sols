a, b = map(int, input().split())
c, d = map(int, input().split())
e = int(input())
delta = abs(c - a) + abs(d - b)
if delta % 2 == e % 2 and e >= delta:
    print("Y")
else:
    print("N")
