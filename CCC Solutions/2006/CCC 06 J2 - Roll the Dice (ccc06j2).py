a, b = int(input()), int(input())
count = sum(1 for i in range(a, 0, -1) for j in range(b, 0, -1) if i + j == 10)

print(f"There {'is' if count == 1 else 'are'} {count} {'way' if count == 1 else 'ways'} to get the sum 10.")
