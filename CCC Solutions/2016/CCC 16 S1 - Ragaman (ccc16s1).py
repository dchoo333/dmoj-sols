from string import ascii_lowercase

a = input()
b = input()

ss = b.count("*")

n = 0
for c in ascii_lowercase:
    if a.count(c) > b.count(c):
        n += a.count(c) - b.count(c)

if n <= ss:
    print("A")
else:
    print("N")
