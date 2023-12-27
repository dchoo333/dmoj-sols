def mode(data):
    counts = {}
    for number in data:
        if number == -1:
            break
        if number in counts:
            counts[number] += 1
        else:
            counts[number] = 1

    max_count = max(counts.values())

    modes = [number for number, count in counts.items() if count == max_count]
    modes.sort()
    return modes
data = []
while True:
    num = int(input())
    if num == -1:
        break
    data.append(num)

modes = mode(data)

for mode in modes:
    print(mode)
