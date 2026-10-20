import sys
r=sys.stdin.readline
cc=0
N=int(r())
for k in range(10,0,-1):
    h=(1<<k)-1
    for i in range(h,N):
        for j in range(i,h-1,-h):
            cc+=1
            print("C",j-h+1,j+1)
            sys.stdout.flush()
            ret=int(r())
            if ret==-1: sys.exit(0)
            if ret: break
            cc+=1
            print("S",j-h+1,j+1)
            sys.stdout.flush()
            ret=int(r())
            if ret==-1: sys.exit(0)
            cc+=1
            print("C",j-h+1,j+1)
            sys.stdout.flush()
            ret=int(r())
            if ret==-1: sys.exit(0)
            if not ret: break
print("A")
sys.stdout.flush()