while True:
    a = int(input())
    if a < 0:
        break
    x, y = map(int, input().split())
    c = (y - x) % 10000
    b = 6.59
    b += min(20, max(0, c - 10)) * 0.2373
    b += min(55, max(0, c - 30)) * 0.2271
    b += min(85, max(0, c - 85)) * 0.2178
    b += max(0, c - 170) * 0.2085
    print(f"Account #: {a}\nBill: {b:.2f}")
