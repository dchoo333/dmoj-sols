s=input()
h=s.count('H')%2
v=s.count('V')%2

g=[['1','2'],['3','4']]

if h: g=g[::-1]
if v: g=[r[::-1] for r in g]

print(*g[0])
print(*g[1])
