s = input()
print(sum(c != 'M' for c in s[s.count('L'):s.count('L')+s.count('M')]) + sum(c != 'L' for c in s[:s.count('L')]) - min(sum(c == 'L' for c in s[s.count('L'):s.count('L')+s.count('M')]), sum(c == 'M' for c in s[:s.count('L')])))
