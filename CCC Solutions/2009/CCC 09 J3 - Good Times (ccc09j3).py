import sys

O = int(input())
V, E, W = 0, 0, 0

if O >= 300:
    V, E, W = O - 300, O - 200, O - 100
elif O < 300 and O >= 200:
    V, E, W = 2100 + O, O-200, O-100
elif O < 200 and O >= 100:
    V, E, W = 2100 + O, 2200 + O, O - 100
else:
    V, E, W = 2100 + O, 2200 + O, 2300 + O


T, H, S = O, (O + 100) % 2400, (O // 100 * 100 + 100 + (O % 100 + 30) // 60 * 100 + (O % 100 + 30) % 60) % 2400

print(O, "in Ottawa")
print(V, "in Victoria")
print(E, "in Edmonton")
print(W, "in Winnipeg")
print(T, "in Toronto")
print(H, "in Halifax")
print(S, "in St. John's")

