dirs, pl = [], []
for _ in range(5):
    dirs.append(input()); pl.append(input())
    if pl[-1]=="SCHOOL": break
c=len(dirs)-1
for i in range(c+1):
    dirs[i]="LEFT" if dirs[i]=="R" else "RIGHT" if dirs[i]=="L" else dirs[i]
for i in range(c-1,-1,-1):
    print("Turn", dirs[i+1],"onto",pl[i],"street.")
print("Turn", dirs[0],"into your HOME.")
