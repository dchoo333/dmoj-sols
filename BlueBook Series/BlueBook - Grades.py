def g(p):
    if 80 <= p <= 100: return "A"
    if 70 <= p <= 79: return "B"
    if 60 <= p <= 69: return "C"
    if 50 <= p <= 59: return "D"
    if 0 <= p <= 49: return "F"
    return "X"

for _ in range(int(input())):
    print(g(int(input())))
