from itertools import accumulate
from operator import xor
n=int(input())
b=list(accumulate(map(int,input().split()),xor))
i=1
while i<n and b[i]>=b[i-1]:i+=1
if i==n:print(0)
else:
    r=1;z=o=0
    for j in range(i+1,n):
        x=b[j-1];y=b[j]
        if x==y:continue
        h=1<<((x^y).bit_length()-1)
        if x&h:
            if z&h:r+=1;z=o=0
            else:o|=h
        else:
            if o&h:r+=1;z=o=0
            else:z|=h
    print(r)