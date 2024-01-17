key, line = input().strip(), ''.join(c for c in input().strip() if c.isalpha())
ans = ''.join(chr(((ord(line[i]) - 65 + ord(key[i % len(key)]) - 65) % 26) + 65) for i in range(len(line)))
print(ans)