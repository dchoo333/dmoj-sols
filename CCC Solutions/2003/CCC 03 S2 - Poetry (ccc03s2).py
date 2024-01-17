vowels = set("aeiouAEIOU")

n = int(input())
for _ in range(n):
    lines = [input().lower().split()[-1] for _ in range(4)]
    s = [line[next((r for r in range(len(line)-1, -1, -1) if line[r] in vowels), 0):] for line in lines]
    
    if all(syllable == s[0] for syllable in s):
        print("perfect")
    elif s[0] == s[1] and s[2] == s[3]:
        print("even")
    elif s[0] == s[2] and s[1] == s[3]:
        print("cross")
    elif s[0] == s[3] and s[1] == s[2]:
        print("shell")
    else:
        print("free")