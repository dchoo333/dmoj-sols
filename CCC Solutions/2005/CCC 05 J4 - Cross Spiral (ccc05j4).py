w,h,cw,ch,steps=[int(input()) for _ in range(5)]
MAX=32
g=[[True]*MAX for _ in range(MAX)]
x,y=cw+1,1
dir="right"

for i in range(1,cw+1):
    for j in range(1,ch+1): g[i][j]=False
for i in range(w-cw+1,w+1):
    for j in range(1,ch+1): g[i][j]=False
for i in range(1,cw+1):
    for j in range(h-ch+1,h+1): g[i][j]=False
for i in range(w-cw+1,w+1):
    for j in range(h-ch+1,h+1): g[i][j]=False

if 2*cw==w-1: dir="down"

while steps>0:
    pos=0
    if not g[x+1][y]: pos+=1
    if not g[x-1][y]: pos+=1
    if not g[x][y+1]: pos+=1
    if not g[x][y-1]: pos+=1
    if pos==4: break

    g[x][y]=False

    if dir=="right": x+=1
    elif dir=="left": x-=1
    elif dir=="up": y-=1
    elif dir=="down": y+=1
    if dir=="right" and (not g[x+1][y] or x+1>w): dir="down"
    elif dir=="down" and (not g[x][y+1] or y+1>h): dir="left"
    elif dir=="up" and (not g[x][y-1] or y-1<=0): dir="right"
    elif dir=="left" and (not g[x-1][y] or x-1<=0): dir="up"
    elif dir=="down" and not g[x+1][y-1] and g[x+1][y]: dir="right"
    elif dir=="left" and not g[x+1][y+1] and g[x][y+1]: dir="down"
    elif dir=="up" and not g[x-1][y+1] and g[x-1][y]: dir="left"
    elif dir=="right" and not g[x-1][y-1] and g[x][y-1]: dir="up"

    steps-=1

print(x)
print(y)
