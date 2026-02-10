c = ""
t = 10**9

while True:
    city, temp = input().split()
    temp = int(temp)

    if temp < t:
        t = temp
        c = city

    if city == "Waterloo":
        break

print(c)
