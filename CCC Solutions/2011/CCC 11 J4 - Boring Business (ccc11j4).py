x,y=-1,-5
visited=[[x,y], [0,-1],[0,-2],[0,-3],[1,-3],[2,-3],[3,-3],[3,-4],[3,-5],[4,-5],[5,-5],[6,-3],[7,-3],[7,-4],[7,-5],[7,-6],[7,-7],[6,-7],[5,-7],[4,-7],[3,-7],[2,-7],[1,-7],[0,-7],[-1,-7],[-1,-6],[-1,-5]]
safe=True

while safe:
    cmd=input().split()
    if cmd==['q','0']: break
    d,dist=cmd[0],int(cmd[1])
    ex,ey=x,y
    for _ in range(dist):
        if d=='l': x-=1
        elif d=='r': x+=1
        elif d=='u': y+=1
        elif d=='d': y-=1
        if [x,y] in visited:
            print(f"{x if d in 'ud' else (ex-dist if d=='l' else ex+dist)} {y if d in 'lr' else (ey+dist if d=='u' else ey-dist)} DANGER")
            safe=False
            break
        visited.append([x,y])
    if safe:
        print(f"{x if d in 'ud' else (ex-dist if d=='l' else ex+dist)} {y if d in 'lr' else (ey+dist if d=='u' else ey-dist)} safe")
