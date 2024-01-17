import sys

a = 0
b = 0
num = 0
j = 0
card = [''] * 52
for i in range(52):
    card[i] = input().strip()
for i in range(52):
    num = 0
    if card[i] == "jack":
        num = 1
    if card[i] == "queen":
        num = 2
    if card[i] == "king":
        num = 3
    if card[i] == "ace":
        num = 4
    j = i + 1
    while j <= i + num:
        if j >= 52:
            break
        if card[j] == "jack" or card[j] == "queen" or card[j] == "king" or card[j] == "ace":
            break
        j += 1
    if j == i + num + 1 and num != 0:
        if i % 2 == 0:
            print("Player A scores " + str(num) + " point(s).")
            a += num
        else:
            print("Player B scores " + str(num) + " point(s).")
            b += num
print("Player A: " + str(a) + " point(s).")
print("Player B: " + str(b) + " point(s).")

