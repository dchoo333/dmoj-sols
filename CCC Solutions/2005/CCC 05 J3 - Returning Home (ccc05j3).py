directions = []
places = []
count = 0
for i in range(5):
    directions.append(input())
    places.append(input())
    if places[i] == "SCHOOL":
        break
    count += 1

for i in range(count + 1):
    if directions[i] == "R":
        directions[i] = "LEFT"
    if directions[i] == "L":
        directions[i] = "RIGHT"

for i in range(count - 1, -1, -1):
    print("Turn", directions[i + 1], "onto", places[i], "street.")

print("Turn", directions[0], "into your HOME.")