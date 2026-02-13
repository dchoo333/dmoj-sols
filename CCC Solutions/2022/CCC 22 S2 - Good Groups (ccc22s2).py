a, b = {}, {}
v = 0 
for _ in range(int(input())):
 f,s = input().split()
 a[f] = a.get(f,[])+[s]
for _ in range(int(input())):
 f,s = input().split()
 b[f] = b.get(f,[])+[s]
for _ in range(int(input())):
 g = input().split()
 for y in g:
  if y in a: v+=sum(i not in g for i in a[y])
  if y in b: v+=sum(i in g for i in b[y])
print(v)
