t=input();s=input();f=False
for _ in range(len(s)):
    if s in t: print("yes");f=True;break
    s=s[1:]+s[0]
if not f: print("no")
