s = input()

p = [s.find(c) for c in "CDHS"] + [len(s)]
a = [list(s[p[i]+1:p[i+1]]) for i in range(4)]

pts = [((3 if not x else 2 if len(x)==1 else 1 if len(x)==2 else 0) + \
           sum(4*(c=='A')+3*(c=='K')+2*(c=='Q')+(c=='J') for c in x)) for x in a]

print("Cards Dealt%20s" % "Points")
print(f"Clubs {' '.join(a[0]):<23} {pts[0]}")
print(f"Diamonds {' '.join(a[1]):<20} {pts[1]}")
print(f"Hearts {' '.join(a[2]):<22} {pts[2]}")
print(f"Spades {' '.join(a[3]):<22} {pts[3]}")
print(f"{'                       Total':<23} {sum(pts)}")
