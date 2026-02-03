M, N = map(int, input().split())
print("\n".join(map(str, [num for num in range(M, N + 1) if num == sum(int(digit) ** 3 for digit in str(num)) and len(str(num)) == 3])))